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

void insert_node(HEAP *heap, NODO *nodo) {
  if (heap->size < heap->capacity) {
    heap->lista[heap->size] = *nodo;
    heapify_bt(heap, heap->size);
    heap->size++;
  }
}

void heapify_bt(HEAP *heap, int i) {
  int padre = (i - 1) / 2;
  NODO temp;
  if (heap->lista[padre].frecuencia > heap->lista[i].frecuencia) {
    temp = heap->lista[padre];
    heap->lista[padre] = heap->lista[i];
    heap->lista[i] = temp;
    heapify_bt(heap, padre);
  }
}

void heapify_tb(HEAP *heap, int i) {
  int left = i * 2 + 1;
  int right = i * 2 + 2;
  int min;
  NODO temp;
  printf("inicio de funcion\n");
  if (left >= heap->size || left <= 0) {
    left = -1;
  }
  if (right >= heap->size || right <= 0) {
    left = -1;
  }
  printf("se ejecuta condiciones left y right\n");
  if (left != -1 && heap->lista[left].frecuencia < heap->lista[i].frecuencia) {
    min = left;
    printf("ejecuto if left\n");
  } else {
    min = i;
  }
  if (right != -1 &&
      heap->lista[right].frecuencia < heap->lista[i].frecuencia) {
    printf("ejecuto if right\n");
    min = right;
  }
  printf("ejecto hasta aqui\n");
  if (min != i) {
    temp = heap->lista[min];
    printf(" temp = heap min ");
    heap->lista[min] = heap->lista[i];
    printf(" heap min = heap i ");
    heap->lista[i] = temp;
    printf("heap i = temp\n");
    heapify_tb(heap, min);
  }
}

NODO Pop(HEAP *heap) {
  NODO pop;
  pop.caracter = '!';
  pop.frecuencia = -1;

  if (heap->size == 0) {
    printf("\nLista vacia\n");
    return pop;
  }

  pop = heap->lista[0];
  printf("se asigna nodo 0 al pop\n");
  heap->lista[0] = heap->lista[heap->size - 1];
  printf("se asigna nodo 1 al 0\n");
  heap->size -= 1;
  printf("size de heap: %d\n", heap->size);
  heapify_tb(heap, 0);
  printf("se ejcuto todo\n");
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

// Funcion para crear nodos con sus frecuencias
void Nodes_freq(HEAP *heap, int *frec) {
  for (int i = 0; i < 26; i++) {
    if (frec[i] != 0) {
      if (i == 25) {
        NODO *T = crear_nodo(frec[25], 32);
        insert_node(heap, T);
      } else {
        NODO *T = crear_nodo(frec[i], i + 65);
        insert_node(heap, T);
      }
    }
  }
}

void print_minheap(HEAP *heap) {
  for (int i = 0; i < heap->size; i++) {
    printf("Nodo %d: frecuencia: %d, caracter %c\n", i,
           heap->lista[i].frecuencia, heap->lista[i].caracter);
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

  char ruta[] = "texto.txt";
  char *path = ruta;

  frecuencias(path, p_array);

  printf("Obtencion de la frecuencias de los caracteres\n");
  for (int i = 0; i < 26; i++) {
    printf(" %d ", freq[i]);
  }

  printf("\nCreando el Min Heap\n");
  HEAP *heap = Crear_heap(26);
  Nodes_freq(heap, p_array);

  print_minheap(heap);

  for (int i = 0; i < heap->size; i++) {
    NODO T = Pop(heap);
    printf("Pop Nodo: frecuencia = %d, caracter = %c", T.frecuencia,
           T.caracter);
  }

  printf("\n");
  return 0;
}
