#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float diff;
  const int row_A = 100;
  const int col_A = 1000;
  const int col_B = 500;
  const int num_trails = 10;

  float A[row_A][col_A];
  float B[col_A][col_B];
  float C[row_A][col_B];
  float scratchpad[8];
  clock_t t1, t2;

  for (int i = 0; i < row_A; i++) {
    for (int j = 0; j < col_A; j++) {
      A[i][j] = (float)(rand() % 1000) / 800.0f;
    }
  }
  for (int i = 0; i < col_A; i++) {
    for (int j = 0; j < col_B; j++) {
      B[i][j] = (float)(rand() % 1000) / 800.0f;
    }
  }

  __m256 ymm0, ymm1, ymm2;

  t1 = clock();
  const int col_A_reduced = col_A - col_A % 8;
  for (int r = 0; r < num_trails; r++) {
    for (int i = 0; i < row_A; i++) {
      for (int j = 0; j < col_B; j++) {
        float res = 0;
        for (int k = 0; k < col_A_reduced; k += 8) {
          // Cargar 8 elementos de A y B usando AVX
          ymm0 = _mm256_loadu_ps(&A[i][k]);
          ymm1 = _mm256_loadu_ps(&B[k][j]);

          // Multiplicar los valores cargados
          ymm2 = _mm256_mul_ps(ymm0, ymm1);

          // Almacenar el resultado en un scratchpad
          _mm256_storeu_ps(scratchpad, ymm2);

          // Sumar los valores del scratchpad
          for (int x = 0; x < 8; x++) {
            res += scratchpad[x];
          }
        }
        // Procesar los elementos restantes de forma escalar
        for (int k = col_A_reduced; k < col_A; k++) {
          res += A[i][k] * B[k][j];
        }
        C[i][j] = res;
      }
    }
  }
  t2 = clock();
  diff = (((float)t2 - (float)t1) / CLOCKS_PER_SEC) * 1000;
  printf("Tiempo de ejecucion con intrinsics AVX: %f ms\n", diff);

  printf("Primeros elementos de la matriz C:\n");
  for (int i = 0; i < row_A; i++) {
    for (int j = 0; j < col_B; j++) {
      printf("%f ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
