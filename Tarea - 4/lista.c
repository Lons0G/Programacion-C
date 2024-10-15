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

NODO *split(NODO *head) {
  NODO *fast = head;
  NODO *slow = head;

  while (fast != NULL && fast->der != NULL && fast->der->der != NULL) {
    fast = fast->der->der;
    slow = slow->der;
  }

  NODO *temp = slow->der;
  slow->der = NULL;
  if (temp != NULL) {
    temp->izq = NULL;
  }
  return temp;
}

NODO *merge(NODO *first, NODO *second) {

  if (first == NULL)
    return second;
  if (second == NULL)
    return first;

  if (first->peso < second->peso) {

    first->der = merge(first->der, second);
    if (first->der != NULL) {
      first->der->izq = first;
    }
    first->izq = NULL;
    return first;
  } else {

    second->der = merge(first, second->der);
    if (second->der != NULL) {
      second->der->izq = second;
    }
    second->izq = NULL;
    return second;
  }
}

NODO *MergeSort(NODO *head) {

  if (head == NULL || head->der == NULL) {
    return head;
  }

  NODO *second = split(head);

  head = MergeSort(head);
  second = MergeSort(second);

  return merge(head, second);
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

  // insertar elementos
  for (i = 0; i < 20; i++) {
    T = crear_nodo();
    T->peso = 20 - i;
    insert_node(T, actual);
    actual = T;
  }
  // Numero demasiado grande para imprimir los 20 elementos
  fin->peso = 100000000;

  int peso_delete = delete_node(ini, 15);
  printf("\nEl elemento eliminado es: %d\n", peso_delete);

  printf("\n");
  imprimir_lista(ini);
  printf("\n");

  ini = MergeSort(ini);

  printf("\nImprime la lista despues de ordenacion\n");
  imprimir_lista(ini);

  printf("\nEliminar la lista\n");
  delete_list(&ini);

  printf("\nImpresion de la lista depues de la eliminacion\n");
  imprimir_lista(ini);

  return 0;
}
