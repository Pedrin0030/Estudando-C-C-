#include <stdlib.h>
#include <iostream>
#include <string>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[]){
    int i;
    cout << "\n";

    for(i = 0; i < TAM; i++){
        cout << " |" << vetor[i] << "| ";
    }
}

void shell_sort(int vetor[TAM]){
    int i, j, atual;
    int h = 1;

    //De quantos em quantos será o pulo entre análises
    while (h < TAM){
        h = 3*h+1;
    }

    while(h > 1){

        //Reduz a distância entre as análises
        h = h / 3;

        for(i = h; i < TAM; i++){

            //Elemento atual em análise
            atual = vetor[i];

            //Elemento anterior ao analisado
            j = i - h;

            //Analisando membros anterior
            while( (j >=0) && (atual < vetor[j])){

                //Posiciona os elementos uma posição para frente
                vetor[j + h] = vetor[j];

                //Faz o j andar para trás
                j = j - h;
            }

            //Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
            vetor[j + h] = atual;

            imprimeVetor(vetor);
        }
    }
}

int main(){

    int vetor[TAM] = {9,10,3,4,6,7,5,1,8,2};

    shell_sort(vetor);

    imprimeVetor(vetor);
}
