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
  // Leer del archivo
  int tamano = 28;

  int ascii_original[28];

  // Inicializar el arreglo con los valores ASCII de 'a' a 'z'
  for (int i = 0; i < 28; ++i) {
    if (i == 0) {
      ascii_original[i] = 32;
    } else if (i == 27) {
      ascii_original[i] = 32;
    } else {
      ascii_original[i] = 96 + i;
    }
  }
  FILE *archivo = fopen("mensaje_cifrado.txt", "r");
  if (archivo == NULL) {
    printf("Error al abrir el archivo.\n");
    return 1;
  }

  int alfabeto[tamano];
  for (int i = 0; i < tamano; i++) {
    if (fscanf(archivo, "%d", &alfabeto[i]) != 1) {
      printf("Error al leer el archivo.\n");
      return 1;
    }
  }

  // Opteniendo el alfabeto
  for (int i = 0; i < tamano; i++) {
    printf("%d ", alfabeto[i]);
  }
  printf("\n");

  printf("Leyendo el archivo de texto codificado\n");
  char bufferc;
  int indice = 0;
  while ((bufferc = fgetc(archivo)) != EOF) {
    // Condiciones por si encuentra una ñ asignarle su valor en ascii
    if (bufferc != -16) {
      if (bufferc == -92) {
        indice = buscarIndice(alfabeto, 164);
      } else {
        indice = buscarIndice(alfabeto, bufferc);
      }
      printf("%c", ascii_original[indice]);
    }
  }

  fclose(archivo);

  return 0;
}
