#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  struct nodo *izq;
  struct nodo *der;
  int peso;
} NODO;

typedef struct nodo_c {
  NODO *tNode;
  struct nodo_c *sig;
} NODO_C;

typedef struct cola {
  NODO_C *ini;
  NODO_C *fin;
} COLA;

NODO *crear_nodo(int valor) {
  NODO *T;
  T = (NODO *)malloc(sizeof(NODO));
  T->der = NULL;
  T->izq = NULL;
  T->peso = valor;
  return T;
}

NODO_C *crear_nodo_c(NODO *tNode) {
  NODO_C *qNode = (NODO_C *)malloc(sizeof(NODO_C));
  qNode->tNode = tNode;
  qNode->sig = NULL;
  return qNode;
}

COLA *crear_cola() {
  COLA *q = (COLA *)malloc(sizeof(COLA));
  q->ini = q->fin = NULL;
  return q;
}

void enqueue(COLA *q, NODO *tNode) {
  NODO_C *qNode = crear_nodo_c(tNode);

  if (q->fin == NULL) {
    q->ini = q->fin = qNode;
  } else {
    q->fin->sig = qNode;
    q->fin = qNode;
  }
}

NODO *dequeue(COLA *q) {
  if (q->ini == NULL)
    return NULL;
  NODO *tNode = q->ini->tNode;
  NODO_C *temp = q->ini;
  q->ini = q->ini->sig;
  if (q->ini == NULL)
    q->fin = NULL;
  free(temp);
  return tNode;
}

void insertar(NODO *raiz, int valor) {
  NODO *padre = raiz;

  NODO *anterior;
  while (padre != NULL) {
    if (padre->peso > valor) {
      anterior = padre;
      padre = padre->izq;
    } else {
      anterior = padre;
      padre = padre->der;
    }
  }
  if (anterior->peso > valor) {
    anterior->izq = crear_nodo(valor);
  } else {
    anterior->der = crear_nodo(valor);
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

void Pre_order(NODO *raiz) {
  if (raiz == NULL) {
    return;
  }
  printf("%d ", raiz->peso);
  Pre_order(raiz->izq);
  Pre_order(raiz->der);
}

void In_order(NODO *raiz) {
  if (raiz == NULL) {
    return;
  }
  In_order(raiz->izq);
  printf("%d ", raiz->peso);
  In_order(raiz->der);
}

void Post_order(NODO *raiz) {
  if (raiz == NULL) {
    return;
  }
  Post_order(raiz->izq);
  Post_order(raiz->der);
  printf("%d ", raiz->peso);
}

void Ancho(NODO *raiz) {
  if (raiz == NULL)
    return;

  COLA *q = crear_cola();

  enqueue(q, raiz);

  while (q->ini != NULL) {
    NODO *curr = dequeue(q);
    printf("%d ", curr->peso);
    if (curr->izq != NULL)
      enqueue(q, curr->izq);
    if (curr->der != NULL)
      enqueue(q, curr->der);
  }
}
int main() {
  NODO *raiz = crear_nodo(10);

  printf("\nInsertando los elementos \n");
  insertar(raiz, 8);
  insertar(raiz, 14);
  insertar(raiz, 7);
  insertar(raiz, 17);
  insertar(raiz, 12);
  insertar(raiz, 15);
  printf("\nImprimiento la lista\n");
  Pre_order(raiz);

  printf("\nEliminando el elemento 7\n");
  eliminar(raiz, 3);
  Pre_order(raiz);
  printf("\nEliminando el elemento 6\n");
  eliminar(raiz, 6);

  printf("\nImpresion del arbol\n");
  printf("\nPre order\n");
  Pre_order(raiz);
  printf("\n");

  printf("\nIn order\n");
  In_order(raiz);
  printf("\n");

  printf("\nPost order\n");
  Post_order(raiz);
  printf("\n");

  printf("\nImpresion por anchura\n");
  Ancho(raiz);

  return 0;
}
