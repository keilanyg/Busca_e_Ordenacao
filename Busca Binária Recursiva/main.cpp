#include <ctime>
#include <iostream>
using namespace std;

int buscaBinariaRecursiva(int *vetor, int chave, int inicio, int fim) {
  if (inicio <= fim) {
    int meio = (inicio + fim) / 2;
    if (chave == vetor[meio]) {
      return meio;
    } else if (chave < vetor[meio]) {
      return buscaBinariaRecursiva(vetor, chave, inicio, meio - 1);
    } else {
      return buscaBinariaRecursiva(vetor, chave, meio + 1, fim);
    }
  }
  return -1;
}

int main() {
  int tam = 10000;
  int vetor[tam], aux;
  int chave, resultado;

  clock_t start_time = clock();

  srand(time(nullptr)); 
  for (int i = 0; i < tam; i++) {
    vetor[i] = rand() % 30000;
  }

  // Ordenação do vetor
  for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  }

  cout << "Vetor ordenado:" << endl;
  for (int i = 0; i < tam; i++) {
    cout << vetor[i] << "|";
  }
  cout << endl;
  cout << "Insira a chave para indicar seu índice: ";
  cin >> chave;

  resultado = buscaBinariaRecursiva(vetor, chave, 0, tam - 1);

  if (resultado != -1) {
    cout << "\nChave encontrada no índice: " << resultado << endl;
  } else {
    cout << "\nChave não encontrada no vetor." << endl;
  }

  clock_t end_time = clock();
  double elapsed_time =
      static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
  cout << "Tempo decorrido: " << elapsed_time << " segundos" << endl;

  return 0;
}
