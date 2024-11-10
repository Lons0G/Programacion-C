#include <stdio.h>
#include <stdlib.h>

int buscarIndice(int arreglo[28], int valor) {
  for (int i = 0; i < 28; i++) {
    if (arreglo[i] == valor) {
      return i;
    }
  }
  return 0;
}

int main() {
  // Tamaño del arreglo
  int tamano = 5;
  int numeros[5];
  for (int i = 0; i < tamano; i++) {
    numeros[i] = i + 1; // Puedes ajustar los valores según tus necesidades
  }

  // Escribir en el archivo
  FILE *archivo = fopen("mis_numeros.txt", "w");
  if (archivo == NULL) {
    printf("Error al abrir el archivo.\n");
    return 1;
  }
  for (int i = 0; i < tamano; i++) {
    fprintf(archivo, "%d\n", numeros[i]);
  }
  fclose(archivo);

  return 0;
}
