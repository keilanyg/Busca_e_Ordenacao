#include <iostream>
using namespace std;

int buscaLinear(int *vetor, int chave, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == chave)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int tam = 100;
    int vetor[tam], aux;
    int chave, resultado;

    srand(time(NULL));

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

    cout << "Insira a chave para indicar seu indice: ";
    cin >> chave;

    cout << "\nBusca linear: " << buscaLinear(vetor, chave, tam);
}