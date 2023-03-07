#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int aux;          // Troca de posições
    int cont = start; // Começa na esquerda, em 0
    // Percorrer da esquerda a direita
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < arr[start])
        {
            cont++; // Incrementar o cont, para saber o número de troca que vai ser feita
            aux = arr[i];
            arr[i] = arr[cont]; // Cont manipula a posição a ser trocada
            arr[cont] = aux;
        }
    }
    // Trocar a posição inicial com a ultima posição que foi trocada
    aux = arr[start];
    arr[start] = arr[cont];
    arr[cont] = aux;
    return cont; // Retorna o cont para o pos
}
void quick(int arr[], int start, int end)
{
    int pos; // Posição que parou de ordenar na esquerda e direita
    if (start < end)
    {
        pos = partition(arr, start, end); // Particionar o vetor
        // Reoderna o vetor
        quick(arr, start, pos - 1);
        quick(arr, pos + 1, end);
    }
}
int main()
{

    int tam = 10;
    int arr[tam];

    // Gerador de números aleatorios
    srand((0));
    for (int i = 0; i < tam; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Vetor inicial: ";
    for (int i = 0; i < tam; i++)
    {
        cout << arr[i] << "| ";
    }
    // Chamada de função
    quick(arr, 0, tam);
    cout << endl;

    cout << "Vetor final";
    for (int i = 0; i < tam; i++)
    {
        cout << "| " << arr[i];
    }
}