#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras
typedef struct {
  int x;
  int y;
} Puntos;

typedef struct {
  float perimetro;
  float area;
  int puntos;
  Puntos *p;

} Figura;

// Funciones
float perimetro(Figura fig);
float area(Figura fig);
int guardar_archivo(Figura fig);
Figura cargar_archivo(char ruta[]);
void imprimir_figura(Figura figura);

// Poligonos
void Triangulo();
void Cuadrado();
void Pentagono();
void Hexagono();

int main() {
  int opcion = 0;
  printf("Selecciona un poligono\n");
  printf("\nTriangulo: 1\n");
  printf("\nCuadrado:  2\n");
  printf("\nPentagono: 3\n");
  printf("\nHexagono:  4\n");
  scanf("%d", &opcion);

  while (opcion > 4 || opcion < 0) {
    printf("Seleccione una opcion valida");
    scanf("%d", &opcion);
  }

  switch (opcion) {
  case 1:
    Triangulo();
    Figura triangulo;
    triangulo = cargar_archivo("figura.csv");
    imprimir_figura(triangulo);
    break;
  case 2:
    Cuadrado();
    Figura cuadrado;
    cuadrado = cargar_archivo("figura.csv");
    imprimir_figura(cuadrado);
    break;
  case 3:
    Pentagono();
    Figura pentagono;
    pentagono = cargar_archivo("figura.csv");
    imprimir_figura(pentagono);
    break;
  case 4:
    Hexagono();
    Figura hexagono;
    hexagono = cargar_archivo("figura.csv");
    imprimir_figura(hexagono);
    break;
  }

  return 0;
}

float perimetro(Figura fig) {
  int i = 1;
  float perimetro = 0.0f;
  float p = 0.0f;
  while (i < fig.puntos) {
    perimetro += sqrt(pow((fig.p[i].x - fig.p[i - 1].x), 2) +
                      pow((fig.p[i].y - fig.p[i - 1].y), 2));
    i++;
  }

  perimetro += sqrt(pow((fig.p[0].x - fig.p[fig.puntos - 1].x), 2) +
                    pow((fig.p[0].y - fig.p[fig.puntos - 1].y), 2));

  return perimetro;
}

float area(Figura fig) {
  float area = 0;
  int j = fig.puntos - 1;
  for (int i = 0; i < fig.puntos; i++) {
    area += (fig.p[j].x + fig.p[i].x) * (fig.p[j].y - fig.p[i].y);
    j = i;
  }

  return abs(area / 2.0);
}

int guardar_archivo(Figura fig) {
  FILE *archivo;
  archivo = fopen("figura.csv", "w");

  if (archivo == NULL) {
    printf("Error al cargar el archivo");
    return 1;
  }

  fprintf(archivo, "%f,%f,%d", fig.perimetro, fig.area, fig.puntos);

  for (int i = 0; i < fig.puntos; i++) {
    fprintf(archivo, ",%d,%d", fig.p[i].x, fig.p[i].y);
  }

  fclose(archivo);
  return 0;
}

Figura cargar_archivo(char ruta[]) {
  FILE *archivo;
  archivo = fopen(ruta, "r");

  if (archivo == NULL) {
    printf("Error al cargar el archivo");
  }

  Figura fig;

  float perimetro = 0;
  float area = 0;
  int puntos = 0;
  Puntos *p;

  char buffer[100];
  char *dato;
  while (fgets(buffer, 100, archivo) != NULL) {
    dato = strtok(buffer, ",");
    perimetro = atof(dato);
    fig.perimetro = perimetro;
    dato = strtok(NULL, ",");
    area = atof(dato);
    fig.area = area;
    dato = strtok(NULL, ",");
    puntos = atoi(dato);
    fig.puntos = puntos;

    fig.p = (Puntos *)malloc(puntos * sizeof(int *));

    for (int i = 0; i < fig.puntos; i++) {
      dato = strtok(NULL, ",");
      fig.p[i].x = atoi(dato);
      dato = strtok(NULL, ",");
      fig.p[i].y = atoi(dato);
    }
  }

  fclose(archivo);

  return fig;
}

void imprimir_figura(Figura figura) {
  printf("\n --Impresion de la estructura Figura--\n ");
  printf("\n perimetro: %f \n", figura.perimetro);
  printf("\n area: %f \n", figura.area);
  for (int i = 0; i < figura.puntos; i++) {
    printf("\n p%d : (%d, %d) \n", i, figura.p[i].x, figura.p[i].y);
  }
}

void Triangulo() {
  int puntos = 3;

  Figura triangulo;

  triangulo.p = (Puntos *)malloc(puntos * sizeof(int *));
  triangulo.puntos = puntos;
  Puntos p1 = {1, 3};
  Puntos p2 = {-1, 1};
  Puntos p3 = {2, 1};

  triangulo.p[0] = p1;
  triangulo.p[1] = p2;
  triangulo.p[2] = p3;

  triangulo.perimetro = perimetro(triangulo);
  triangulo.area = area(triangulo);

  imprimir_figura(triangulo);

  if (guardar_archivo(triangulo) == 0) {
    printf("\n El archivo se guardo correctamente \n");
  } else {
    printf("Error al guardar el archivo");
  }
}

void Cuadrado() {
  int puntos = 4;

  Figura cuadrado;

  cuadrado.p = (Puntos *)malloc(puntos * sizeof(int *));
  cuadrado.puntos = puntos;
  Puntos p1 = {2, 4};
  Puntos p2 = {-1, 4};
  Puntos p3 = {1, -1};
  Puntos p4 = {2, 1};

  cuadrado.p[0] = p1;
  cuadrado.p[1] = p2;
  cuadrado.p[2] = p3;
  cuadrado.p[3] = p4;

  cuadrado.perimetro = perimetro(cuadrado);
  cuadrado.area = area(cuadrado);

  imprimir_figura(cuadrado);

  if (guardar_archivo(cuadrado) == 0) {
    printf("\n El archivo se guardo correctamente \n");
  } else {
    printf("Error al guardar el archivo");
  }
}

void Pentagono() {
  int puntos = 5;

  Figura pentagono;

  pentagono.p = (Puntos *)malloc(puntos * sizeof(int *));
  pentagono.puntos = puntos;
  Puntos p1 = {2, 5};
  Puntos p2 = {-2, 3};
  Puntos p3 = {-1, -3};
  Puntos p4 = {4, -3};
  Puntos p5 = {5, 2};

  pentagono.p[0] = p1;
  pentagono.p[1] = p2;
  pentagono.p[2] = p3;
  pentagono.p[3] = p4;
  pentagono.p[4] = p5;

  pentagono.perimetro = perimetro(pentagono);
  pentagono.area = area(pentagono);

  imprimir_figura(pentagono);

  if (guardar_archivo(pentagono) == 0) {
    printf("\n El archivo se guardo correctamente \n");
  } else {
    printf("Error al guardar el archivo");
  }
}

void Hexagono() {
  int puntos = 6;

  Figura hexagono;

  hexagono.p = (Puntos *)malloc(puntos * sizeof(int *));
  hexagono.puntos = puntos;
  Puntos p1 = {-2, 3};
  Puntos p2 = {-1, 1};
  Puntos p3 = {2, 1};
  Puntos p4 = {2, 5};
  Puntos p5 = {1, 5};
  Puntos p6 = {3, 3};

  hexagono.p[0] = p1;
  hexagono.p[1] = p2;
  hexagono.p[2] = p3;
  hexagono.p[3] = p4;
  hexagono.p[4] = p5;

  hexagono.perimetro = perimetro(hexagono);
  hexagono.area = area(hexagono);

  imprimir_figura(hexagono);

  if (guardar_archivo(hexagono) == 0) {
    printf("\n El archivo se guardo correctamente \n");
  } else {
    printf("Error al guardar el archivo");
  }
}
