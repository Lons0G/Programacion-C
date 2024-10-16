#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  struct nodo *izq;
  struct nodo *der;
  int peso;
} NODO;

NODO *crear_nodo(int valor) {
  NODO *T;
  T = (NODO *)malloc(sizeof(NODO));
  T->der = NULL;
  T->izq = NULL;
  T->peso = valor;
  return T;
}

void insertar(NODO *raiz, int valor) {
  NODO *padre = raiz;
  if (padre->peso > valor) {
    while (padre->izq != NULL) {
      padre = padre->izq;
    }
    padre->izq = crear_nodo(valor);
  } else {
    while (padre->der != NULL) {
      padre = padre->der;
    }
    padre->der = crear_nodo(valor);
  }
}
void eliminar(NODO *raiz, int valor) {
  NODO *padre = raiz;
  NODO *anterior = raiz;
  int encontrado = 0;
  if (raiz == NULL) {
    return;
  }
  while (padre->izq != NULL || padre->der != NULL) {

    if (padre->peso == valor) {
      printf("\nSe elimino el elemento: %d\n", padre->peso);
      anterior->izq = NULL;
      anterior->der = NULL;
      free(padre);
      encontrado = 1;
      break;
    } else if (padre->peso < valor) {
      if (padre->der == NULL) {
        break;
      }
      anterior = padre;
      padre = padre->der;
    } else {
      if (padre->izq == NULL) {
        break;
      }
      anterior = padre;
      padre = padre->izq;
    }
  }
  if (!encontrado) {
    printf("\nNo se encontro el elemento\n");
  }
}
void imprimir(NODO *raiz) {
  if (raiz == NULL) {
    return;
  }
  printf("%d ", raiz->peso);
  imprimir(raiz->izq);
  imprimir(raiz->der);
}

int main() {
  NODO *raiz = crear_nodo(10);

  insertar(raiz, 8);
  insertar(raiz, 11);
  insertar(raiz, 7);
  insertar(raiz, 3);
  insertar(raiz, 9);

  eliminar(raiz, 7);
  imprimir(raiz);
  eliminar(raiz, 6);
  imprimir(raiz);

  return 0;
}
