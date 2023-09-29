#include <iostream>
#include <cstdlib> // Incluir a biblioteca para srand e rand
#include <ctime>   // Incluir a biblioteca para time

using namespace std;

int partition(int arr[], int esquerda, int direita){
    int aux;
    int cont = esquerda;
    for (int i = esquerda + 1; i <= direita; i++){
        if (arr[i] < arr[esquerda]){
            cont++;
            aux = arr[i];
            arr[i] = arr[cont];
            arr[cont] = aux;
        }
    }
    aux = arr[esquerda];
    arr[esquerda] = arr[cont];
    arr[cont] = aux;
    return cont;
}

void quick(int arr[], int esquerda, int direita){
    int pos;
    if (esquerda < direita){
        pos = partition(arr, esquerda, direita);
        quick(arr, esquerda, pos - 1);
        quick(arr, pos + 1, direita);
    }
}

int main(){
    int tam = 10000;
    int arr[tam];
    // Captura o tempo de início
    clock_t start_time = clock();

    // Inicializar o gerador de números aleatórios com o tempo atual
    srand(time(0));
    for (int i = 0; i < tam; i++){
        arr[i] = rand() % 2000;
    }

    cout << "Vetor inicial:" << endl;
    for (int i = 0; i < tam; i++){
        cout << arr[i] << "| ";
    }

    quick(arr, 0, tam - 1); // Corrigir a chamada da função quick

    cout << endl;
    cout << "Vetor final:" << endl;
    for (int i = 0; i < tam; i++){
        cout << "| " << arr[i];
    }
    // Captura o tempo de fim
    clock_t end_time = clock();
    // Calcule o tempo decorrido em segundos
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    // Imprime o tempo decorrido em segundos
    cout << "\nTempo decorrido: " << elapsed_time << " segundos" << endl;

    return 0;
}
