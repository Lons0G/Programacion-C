#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void insert_node(NODO *new, NODO *izq) {
  new->der = izq->der;
  izq->der->izq = new;
  izq->der = new;
  new->izq = izq;
}
int delete_node(NODO *ini, int val) {
  NODO *I;
  for (I = ini->der; I->der != NULL; I = I->der) {
    if (I->peso == val) {
      printf("\nEl nodo anterior es %p con su valor %d\n", &I->izq,
             I->izq->peso);
      printf("\nEl nodo despues es %p con su valor %d\n", &I->der,
             I->der->peso);
      printf("\nEncontro el valor en el nodo %p\n", &I);

      I->izq->der = I->der;
      I->der->izq = I->izq;

      free(I);
      return val;
    }
  }
  return NULL;
}

void delete_list(NODO **ini) {
  NODO *I;

  while (*ini != NULL) {

    I = *ini;
    *ini = I->der;
    free(I);
  }
}

NODO *split(NODO *ini) {
  NODO *fast = ini;
  NODO *slow = ini;
  while (fast != NULL && fast->der != NULL) {
    fast = fast->der->der;
    if (fast != NULL) {
      slow = slow->der;
    }
  }

  NODO *temp = slow->der;
  slow->der = NULL;
  return temp;
}

NODO *merge(NODO *first, NODO *second) {

  NODO *tmp = NULL;

  if (first == NULL) {
    return second;
  }
  if (second == NULL) {
    return first;
  }

  if (first->peso < second->peso) {
    tmp = merge(first->der, second);
    first->der = tmp;
    tmp->izq = first;
    return first;
  } else {
    tmp = merge(first, second->der);
    second->der = tmp;
    tmp->izq = second;
    return second;
  }
}

NODO *mergesort(NODO *ini) {
  if (ini == NULL || ini->der == NULL) {
    return ini;
  }

  NODO *second = split(ini);

  ini = mergesort(ini);
  second = mergesort(second);

  return merge(ini, second);
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

int main() {
  NODO *ini, *fin, *T, *actual;
  int i;

  crear_lista(&ini, &fin);
  actual = ini;

  printf("\nImprime lista vacia\n");
  imprimir_lista(ini);
  printf("\n");

  for (i = 0; i < 20; i++) {
    T = crear_nodo();
    T->peso = 20 - i;
    insert_node(T, actual);
    actual = T;
  }
  printf("\n ini: %d\n", ini->peso);
  printf("\n ini->der: %d\n", ini->der->peso);
  printf("\n ini->der->der: %d\n", ini->der->der->peso);

  printf("\n");
  imprimir_lista(ini);
  printf("\n");

  // delete_list(&ini);
  // int val = delete_node(ini, 17);

  ini = mergesort(ini);

  printf("\nImprime la lista despues de ordenacion\n");
  // printf("\n Lista despues de la eliminacion del nodo %d\n", val);
  imprimir_lista(ini);
  printf("\n ini: %p\n", &ini);
  printf("\n ini->der: %d\n", ini->peso);
  printf("\n fin: %p\n", &fin);
  // printf("\n");
  return 0;
}
