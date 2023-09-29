#include <ctime>
#include <iostream>

using namespace std;

int buscaLinear(int *vetor, int chave, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == chave) {
      return i;
    }
  }
  return -1;
}

int main() {
  int tam = 10000;
  int vetor[tam], aux;
  int chave, resultado;

  clock_t start_time = clock();
  srand(time(NULL));
  for (int i = 0; i < tam; i++) {
    vetor[i] = rand() % 30000;
  }
  for (int i = 0; i < tam; i++) {       // Prende
    for (int j = i + 1; j < tam; j++) { // Obriga o J a percorrer o resto
      if (vetor[i] > vetor[j]) {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  cout << "Vetor ordenado " << endl;

  for (int i = 0; i < tam; i++) {
    cout << vetor[i] << "|";
  }
  cout << endl;
  cout << "Insira a chave para indicar seu indice: ";
  cin >> chave;

  resultado = buscaLinear(vetor, chave, tam);

   if (resultado != -1) {
    cout << "\nChave encontrada no índice: " << resultado << endl;
  } else {
    cout << "\nChave não encontrada no vetor." << endl;
  }
  
  clock_t end_time = clock();
  double elapsed_time =
      static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
  cout << "\nTempo decorrido: " << elapsed_time << " segundos" << endl;
}