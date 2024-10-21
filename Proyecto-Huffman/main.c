#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
// 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90

// Creacion de las estructuras
typedef struct nodo {
  struct nodo *left;
  struct nodo *right;
  int frecuencia;
  char caracter;

} NODO;

//
typedef struct heap {
  int size;
  int capacity;
  NODO *lista;
} HEAP;

// Metodos

// Creacion de los nodos
NODO *crear_nodo(int frecuencia, char caracter) {

  NODO *T = (NODO *)malloc(sizeof(NODO));

  T->left = NULL;
  T->right = NULL;
  T->frecuencia = frecuencia;
  T->caracter = caracter;

  return T;
}

HEAP *Crear_heap(int capacity) {
  HEAP *heap = (HEAP *)malloc(capacity * sizeof(HEAP));

  heap->size = 0;
  heap->capacity = capacity;

  heap->lista = (NODO *)malloc(capacity * sizeof(NODO));

  return heap;
}

void heapify_bt(HEAP *heap, int i) {
  int padre = (i - 1) / 2;
  NODO *temp;
  if (heap->lista[padre].frecuencia > heap->lista[i].frecuencia) {
    *temp = heap->lista[padre];
    heap->lista[padre] = heap->lista[i];
    heap->lista[i] = *temp;
    heapify_bt(heap, padre);
  }
}

void heapify_tb(HEAP *heap, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int min;
  NODO *temp;
  int aux = 1;

  if (left >= heap->size || right >= heap->size) {
    left = -1;
    right = -1;
  }

  if (left != -1 && heap->lista[left].frecuencia < heap->lista[i].frecuencia) {
    min = left;
  } else {
    min = i;
  }
  if (right != -1 &&
      heap->lista[right].frecuencia < heap->lista[i].frecuencia) {
    min = right;
  }

  if (min != i) {
    *temp = heap->lista[min];
    heap->lista[min] = heap->lista[i];
    heap->lista[i] = *temp;

    heapify_tb(heap, min);
  }
}

NODO *Pop(HEAP *heap) {
  NODO *pop;
  if (heap->size == 0) {
    printf("\nLista vacia\n");
    return NULL;
  }

  *pop = heap->lista[0];
  heap->lista[0] = heap->lista[heap->size - 1];
  heap->size -= 1;
  heapify_tb(heap, 0);

  return pop;
}

// Funcion para contar la frecuencia de los caracteres
void frecuencias(char *path, int *frec) {
  FILE *archivo = fopen(path, "r");

  if (archivo == NULL) {
    printf("\nError al abrir el archivo\n");
    return;
  }

  char c;
  while ((c = fgetc(archivo)) != EOF) {
    if (isspace(c)) {
      frec[25]++;
    } else {
      frec[c - 65]++;
    }
  }
}

int main() {

  NODO *hoja;
  hoja = (NODO *)malloc(sizeof(NODO));

  hoja->left = NULL;
  hoja->right = NULL;
  hoja->frecuencia = 4;
  hoja->caracter = 65;

  int freq[26] = {0};
  int *p_array = freq;

  char ruta[] = "p.txt";
  char *path = ruta;

  frecuencias(path, p_array);

  for (int i = 0; i < 26; i++) {
    printf(" %d ", freq[i]);
  }

  return 0;
}
