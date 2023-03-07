#include <iostream>
using namespace std;

int main()
{

    int tam = 10;
    int vetor[tam], aux;

    srand((0));

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 100;
    }
    cout << "Vetor gerado aleatoriamente! " << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << "| ";
    }

    for (int i = 0; i < tam; i++)
    { // Recomeça
        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[i] > vetor[j])
            { // Verifica se precisa trocar
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    cout << "\nVetor ordenado: " << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << "| ";
    }
}