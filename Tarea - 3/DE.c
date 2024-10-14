#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ind {
  float x[3];
  float fitness;
} individuo;

// generador pseudo-aleatorio
float RAND_REAL(float Rmax, float Rmin) {
  float n, test;
  test = rand();
  if (rand() % 2 == 0)
    n = ((float)test / RAND_MAX) * Rmax;
  else
    n = ((float)test / RAND_MAX) * Rmin;
  return n;
}

// función objetivo
float f(float x[3]) { return x[0] * x[0] + x[1] * x[1] + x[2] * x[2]; }

void print_poblacion(individuo *poblacion, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("\n %d x1: %f x2: %f x3: %f  fitness: %f\n", i, poblacion[i].x[0],
           poblacion[i].x[1], poblacion[i].x[2], poblacion[i].fitness);
  }
}

// Funcion de mutacion, crossover y seleccion
void Mutacion(individuo *p, int n_individuos, int parametros, float F) {
  int a_i;
  int b_i;
  int c_i;

  individuo hijos[n_individuos];

  // Mutacion para cada individuo de la poblacion
  for (int i = 0; i < n_individuos; i++) {
    int random = 0;
    int CR = 1;

    // Seleccionando aleatoriamente el individuo a
    do {
      random = rand() % 100;
      a_i = random;
    } while (a_i == i);

    // Seleccionando aleatoriamente el individuo b
    do {
      random = rand() % 100;
      b_i = random;
    } while (b_i == i || b_i == a_i);

    // Seleccionando aleatoriamente el individuo c
    do {
      random = rand() % 100;
      c_i = random;
    } while (c_i == i || c_i == a_i || c_i == b_i);

    for (int j = 0; j < parametros; j++) {
      // Selecciona aleatoriamente si mutar el parametro con una probabilidad
      // del 10%
      if (CR == rand() % 10) {
        printf("\nEntro en el crossover en el individuo %d\n", i);
        hijos[i].x[j] = p[a_i].x[j] + F * (p[b_i].x[j] - p[c_i].x[j]);
        while (hijos[i].x[j] < -5.12 || hijos[i].x[j] > 5.12) {
          if (hijos[i].x[j] < -5.12) {
            hijos[i].x[j] += RAND_REAL(1.0, 0.0);
          }
          if (hijos[i].x[j] > 5.12) {
            hijos[i].x[j] -= RAND_REAL(1.0, 0.0);
          }
        }
      } else {
        hijos[i].x[j] = p[i].x[j];
      }
    }
    // Seleccion
    hijos[i].fitness = f(hijos[i].x);
    if (hijos[i].fitness < p[i].fitness) {
      printf("\n Se intercambio de padre %d a hijo %d\n", i, i);
      p[i] = hijos[i];
    }
  }
}

int main() {
  int cantidad_p = 25;
  individuo poblacion[cantidad_p];
  int i;
  float F = 0.5;
  srand(time(NULL));

  for (i = 0; i < cantidad_p; i++) {
    poblacion[i].x[0] = RAND_REAL(5.2, -5.2);
    poblacion[i].x[1] = RAND_REAL(5.2, -5.2);
    poblacion[i].x[2] = RAND_REAL(5.2, -5.2);
    poblacion[i].fitness = f(poblacion[i].x);
  }

  printf("\nPrimera Generacion\n");
  print_poblacion(poblacion, cantidad_p);
  Mutacion(poblacion, cantidad_p, 3, F);
  printf("\nSegunda Generacion\n");
  print_poblacion(poblacion, cantidad_p);

  return 0;
}
