#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  struct nodo *izq;
  struct nodo *der;
  int peso;
} NODO;

NODO *crear_nodo() {
  NODO *T;
  T = (NODO *)malloc(sizeof(NODO));
  T->der = NULL;
  T->izq = NULL;
  T->peso = 0;
  return T;
}

void crear_lista(NODO **ini, NODO **fin) {
  *ini = crear_nodo();
  *fin = crear_nodo();
  (*ini)->der = *fin;
  (*fin)->izq = *ini;
}

void push(NODO *ini, int valor) {
  NODO *I, *P;
  P = crear_nodo();
  P->peso = valor;
  I = ini->der;

  while (I->der != NULL) {
    I = I->der;
  }

  I->izq->der = P;
  P->der = I;
  I->izq = P;
}

int pop(NODO **fin) {
  NODO *I;
  I = *fin;
  *fin = I->izq;
  int valor = I->peso;
  free(I);
  return valor;
}

void imprimir_lista(NODO *ini) {
  NODO *I;
  if (ini == NULL) {
    printf("\nLa lista esta vacia\n");
    return;
  }
  for (I = ini->der; I->der != NULL; I = I->der)
    printf(" %d ", I->peso);
}

int isempty(NODO *ini, NODO *fin) {
  if (ini->der == fin) {
    return 1;
  }
  return 0;
}

int main() {
  NODO *ini, *fin, *T;
  int i;

  crear_lista(&ini, &fin);

  printf("\nValor del pop: %p\n", fin);
  if (isempty(ini, fin)) {
    printf("\nLa pila esta vacia\n");
  }

  // insertar elementos
  for (i = 0; i < 20; i++) {
    push(ini, i + 1);
  }
  imprimir_lista(ini);

  int valor = pop(&fin);
  printf("\nValor del pop %d: %p\n", valor, fin);
  printf("\nImpresion de la lista despues del pop\n");
  imprimir_lista(ini);

  if (isempty(ini, fin)) {
    printf("\nLa pila esta vacia\n");
  } else {
    printf("\nLa pila no esta vacia\n");
  }
  return 0;
}
