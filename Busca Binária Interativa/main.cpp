#include <iostream>
using namespace std;

int buscaBinariaInterativa(int *vetor, int chave, int fim)
{
    int inicio = 0;
    int meio = (inicio + fim) / 2;

    while (inicio <= fim)
    {
        if (chave == vetor[meio])
            return meio;
        else
        {
            if (chave < vetor[meio])
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
        meio = (inicio + fim) / 2;
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

    cout << "\nBusca Interativa: " << buscaBinariaInterativa(vetor, chave, tam) << endl;
}