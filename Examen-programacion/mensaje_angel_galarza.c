#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirAlfabeto(int arr[]) {
  printf("Alfabeto a partir de los valores ASCII:\n");
  for (int i = 0; i < 28; ++i) {
    printf("%d=%c \n", arr[i], arr[i]);
  }
}

void alfabeto_shuffle(int arr[]) {
  // Semilla para generar numeros pesudoaleatorios
  srand(time(NULL));

  // Revuelve los elementos menos el elemento 0 (' ')
  for (int i = 1; i < 28; ++i) {
    int j = rand() % (28 - i) + 1;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

int buscarIndice(int arreglo[28], int valor) {
  for (int i = 0; i < 28; i++) {
    if (arreglo[i] == valor) {
      return i;
    }
  }
  return 0;
}

int main() {
  // Arreglo para almacenar los valores ASCII del alfabeto (minúsculas)
  int ascii_original[28];
  int ascii_alfabeto[28];

  // Inicializar el arreglo con los valores ASCII de 'a' a 'z'
  for (int i = 0; i < 28; ++i) {
    if (i == 0) {
      ascii_original[i] = 32;
      ascii_alfabeto[i] = 32;
    } else if (i == 27) {
      ascii_original[i] = 32;
      ascii_alfabeto[i] = 164;
    } else {
      ascii_original[i] = 96 + i;
      ascii_alfabeto[i] = 96 + i;
    }
  }

  imprimirAlfabeto(ascii_alfabeto);

  printf("Despues del shuffle\n");
  // Revolviendo el alfabeto
  alfabeto_shuffle(ascii_alfabeto);
  imprimirAlfabeto(ascii_alfabeto);

  // Abriendo el archivo txt
  char filename[] = "mensaje_sin_cifrar.txt";
  char file_codec[] = "mensaje_cifrado.txt";
  FILE *archivo = fopen(filename, "r");
  FILE *archivo_codificado = fopen(file_codec, "w");

  if (archivo == NULL || archivo_codificado == NULL) {
    printf("Error al abrir uno de los archivo\n");
  }

  printf("ascii original\n");
  imprimirAlfabeto(ascii_original);

  printf("Leyendo el archivo de texto original\n");
  int pass = 0;
  char buffer;
  while ((buffer = fgetc(archivo)) != EOF) {
    // Condiciones porque se encuentra una ñ y no lo puede leer correctamente
    if (buffer < 0 && pass == 0) {
      pass = 1;
    } else if (buffer < 0 && pass == 1) {
      printf("%c = %c -- %c\n", 164, ascii_alfabeto[27], ascii_original[27]);
      fputc(ascii_alfabeto[27], archivo_codificado);
    } else if (buffer != 32) {
      printf("%c = %c -- %c\n", buffer, ascii_alfabeto[buffer - 96],
             ascii_original[buffer - 96]);
      fputc(ascii_alfabeto[buffer - 96], archivo_codificado);
    } else {
      fputc(ascii_alfabeto[0], archivo_codificado);
      printf("%c = %c -- %c\n", buffer, ascii_alfabeto[0], ascii_original[0]);
    }
  }
  fclose(archivo);
  fclose(archivo_codificado);

  printf("Leyendo el archivo de texto codificado\n");
  FILE *archivo_codificado_c = fopen(file_codec, "r");
  char bufferc;
  int indice = 0;
  while ((bufferc = fgetc(archivo_codificado_c)) != EOF) {
    // Condiciones por si encuentra una ñ asignarle su valor en ascii
    if (bufferc != -16) {
      if (bufferc == -92) {
        indice = buscarIndice(ascii_alfabeto, 164);
      } else {
        indice = buscarIndice(ascii_alfabeto, bufferc);
      }
      printf("%c", ascii_original[indice]);
    }
  }

  fclose(archivo_codificado);
  return 0;
}
