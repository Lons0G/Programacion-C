#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicarMatrices(int filasA, int columnasA, int filasB, int columnasB,
                         int matrizA[filasA][columnasA],
                         int matrizB[filasB][columnasB],
                         int resultado[filasA][columnasB]) {

  if (columnasA != filasB) {
    printf("No se pueden multiplicar las matrices. El número de columnas de la "
           "primera matriz debe ser igual al número de filas de la segunda "
           "matriz.\n");
    return;
  }

  for (int i = 0; i < filasA; i++) {
    for (int j = 0; j < columnasB; j++) {
      resultado[i][j] = 0;
      for (int k = 0; k < columnasA; k++) {
        resultado[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }
}

int main() {

  int filasA = 100;
  int columnasA = 500;
  int filasB = 500;
  int columnasB = 100;

  // Verifica si las matrices se pueden multiplicar antes de declararlas
  if (columnasA != filasB) {
    printf("No se pueden multiplicar las matrices. El número de columnas de la "
           "primera matriz debe ser igual al número de filas de la segunda "
           "matriz.\n");
    return 1;
  }

  int matrizA[filasA][columnasA], matrizB[filasB][columnasB],
      resultado[filasA][columnasB];

  srand(time(NULL));
  for (int i = 0; i < filasA; i++) {
    for (int j = 0; j < columnasA; j++) {
      matrizA[i][j] = rand() % 10;
    }
  }

  for (int i = 0; i < filasB; i++) {
    for (int j = 0; j < columnasB; j++) {
      matrizB[i][j] = rand() % 10;
    }
  }

  clock_t inicio = clock();
  multiplicarMatrices(filasA, columnasA, filasB, columnasB, matrizA, matrizB,
                      resultado);

  clock_t fin = clock();

  float tiempo_total = (((float)fin - (float)inicio) / CLOCKS_PER_SEC) * 1000;
  printf("Tiempo de ejecución: %f segundos\n", tiempo_total);

  return 0;
}
