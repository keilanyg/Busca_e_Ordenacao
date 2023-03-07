#include <iostream>
using namespace std;

int buscaBinariaRecursiva(int *vetor, int chave, int inicio, int fim)
{
    int meio;
    if (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (chave == vetor[meio])
        {
            return meio;
        }
        else
        {
            if (chave < vetor[meio])
            {
                return buscaBinariaRecursiva(vetor, chave, inicio, meio - 1);
            }
            else
                return buscaBinariaRecursiva(vetor, chave, meio + 1, fim);
        }
    }
    return -1;
}

int main()
{

    int tam = 100;
    int vetor[tam], aux;
    int chave, resultado;

    srand((0));

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 1000;
    }
    for (int i = 0; i < tam; i++)
    { // Prende
        for (int j = i + 1; j < tam; j++)
        { // Obriga o J a percorrer o resto
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    cout << "Vetor ordenado " << endl;

    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << endl;
    }
    cout << endl;

    cout << "Insira a chave para indicar seu indice: " << endl;
    cin >> chave;

    cout << "\nBusca Recursiva: " << buscaBinariaRecursiva(vetor, chave, 0, tam) << endl;
}