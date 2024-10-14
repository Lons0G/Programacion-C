#include <stdio.h>
#include <stdlib.h>

void PrintMatriz(int **A, int n, int m) {
  int i = 0;
  int j = 0;

  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j < m; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

void FillMatriz(int **A, int n, int m) {
  int i = 0;
  int j = 0;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      A[i][j] = rand() % 3;
    }
  }
}

void SumaMatriz(int **A, int **B, int n, int m, int q, int p) {
  if (n == m && q == p && n == q) {
    int **C;
    C = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
      C[i] = (int *)malloc(p * sizeof(int *));
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        C[i][j] = A[i][j] + B[i][j];
      }
    }
    printf("\nImprimiendo suma de matrices\n");
    PrintMatriz(C, n, q);
  } else {
    printf("\nError, no se puede realizar la sumatoria\n");
  }
}

void RestaMatriz(int **A, int **B, int n, int m, int q, int p) {
  if (n == m && q == p && n == q) {
    int **C;
    C = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
      C[i] = (int *)malloc(p * sizeof(int *));
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        C[i][j] = A[i][j] - B[i][j];
      }
    }
    printf("\nImprimiendo resta de matrices\n");
    PrintMatriz(C, n, q);
  } else {
    printf("\nError, no se puede realizar la resta\n");
  }
}

void Producto_E_Matriz(int **A, int n, int m, int escalar) {
  int **C;
  C = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    C[i] = (int *)malloc(m * sizeof(int *));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      C[i][j] = A[i][j] * escalar;
    }
  }

  printf("\nImprimiendo producto escalar de matrices\n");
  PrintMatriz(C, n, m);
}

void MultiplicacionMatriz(int **A, int **B, int n, int m, int q, int p) {
  if (m == q) {
    int **C;
    C = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
      C[i] = (int *)malloc(p * sizeof(int *));
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < p; j++) {
        C[i][j] = 0;
        for (int k = 0; k < m; k++) {
          C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
        }
      }
    }

    printf("\nImprimiendo multiplicacion de matrices\n");
    PrintMatriz(C, n, q);

  } else {
    printf("\nError, no se puede realizar la multiplicacion\n");
  }
}

int main() {
  int **A;
  int n = 4;
  int m = 4;

  srand(4);

  A = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    A[i] = (int *)malloc(m * sizeof(int *));
  }

  int **B;
  int p = 4;
  int q = 4;

  srand(8);

  B = (int **)malloc(p * sizeof(int *));

  for (int i = 0; i < p; i++) {
    B[i] = (int *)malloc(q * sizeof(int *));
  }

  printf("\nMatriz A\n");
  FillMatriz(A, n, m);
  PrintMatriz(A, n, m);

  printf("\nMatriz B\n");
  FillMatriz(B, p, q);
  PrintMatriz(B, p, q);

  SumaMatriz(A, B, n, m, q, p);

  RestaMatriz(A, B, n, m, q, p);

  Producto_E_Matriz(A, n, m, 2);

  MultiplicacionMatriz(A, B, n, m, p, q);

  free(A);
  free(B);

  return 0;
}
