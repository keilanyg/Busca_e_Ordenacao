#include <iostream>
#include <ctime>

using namespace std;

int main(){
    
    int tam = 10000;
    int vetor[tam], aux;

    // Captura o tempo de início
    clock_t start_time = clock();
    srand((0));
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 2000;
    }
    cout << "Vetor gerado aleatoriamente! " << endl;
    for (int i = 0; i < tam; i++){
        cout << vetor[i] << "| ";
    }

    for (int i = 0; i < tam; i++){ // Recomeça
        for (int j = i + 1; j < tam; j++){
            if (vetor[i] > vetor[j])
            { // Verifica se precisa trocar
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    cout << "\nVetor ordenado: " << endl;
    for (int i = 0; i < tam; i++){
        cout << vetor[i] << "| ";
    }
    // Captura o tempo de fim
    clock_t end_time = clock();

    // Calcule o tempo decorrido em segundos
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Imprime o tempo decorrido em segundos
    cout << "\nTempo decorrido: " << elapsed_time << " segundos" << endl;

}