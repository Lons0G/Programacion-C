#include <iostream>

class Nodo {
public:
  int valor;
  Nodo **hijos;
  int numHijos;
  int capacidad;

  Nodo(int val, int capacidad) : valor(val), capacidad(capacidad), numHijos(0) {
    hijos = new Nodo *[capacidad];
  }

  ~Nodo() {
    std::cout << "Eliminando los hijos del nodo " << this->valor << std::endl;
    delete[] hijos;
  }

  // Metodo para agregar un hijo
  bool agregarHijo(Nodo *hijo) {
    if (numHijos < capacidad) {
      hijos[numHijos++] = hijo;
      return true;
    }
    std::cout << "Supero la capacidad de agregar mas hijos" << std::endl;
    return false;
  }

  bool InsertarHijos() {
    for (int i = 0; i < 3; ++i) {
      int valor = 1 + rand() % 15;
      Nodo *nuevoHijo = new Nodo(valor, capacidad);
      if (!agregarHijo(nuevoHijo)) {
        // Si no se pudo agregar un hijo, se eliminan los hijos ya agregados
        for (int j = 0; j < i; ++j) {
          delete hijos[j];
        }
        return false;
      }
    }
    return true;
  }
};

class Arbol {
public:
  Nodo *raiz;
  int capacidadHijos;

  Arbol(int valorRaiz, int capacidadHijos) {
    raiz = new Nodo(valorRaiz, capacidadHijos);
    this->capacidadHijos = capacidadHijos;
  }

  // Destructor
  ~Arbol() {
    std::cout << "Eliminado arbol" << std::endl;
    eliminarNodo(raiz);
  }

  // Metodo ecursivo para eliminar nodos
  void eliminarNodo(Nodo *nodo) {
    if (nodo) {
      for (int i = 0; i < nodo->numHijos; i++) {
        eliminarNodo(nodo->hijos[i]);
      }
      delete nodo;
    }
  }

  // Metodo para agregar tres hijos a un nodo
  void InsertarNodos(Nodo *nodo) {
    if (nodo) {
      nodo->InsertarHijos();
    } else {
      std::cout << "Nodo no encontrado." << std::endl;
    }
  }

  // Metodo recursivo para imprimir el arbol
  void imprimirArbol(Nodo *nodo, int nivel = 0) {
    if (nodo) {
      for (int i = 0; i < nivel; i++) {
        std::cout << "  ";
      }
      std::cout << nodo->valor << std::endl;
      for (int i = 0; i < nodo->numHijos; i++) {
        imprimirArbol(nodo->hijos[i], nivel + 1);
      }
    }
  }

  void imprimir() { imprimirArbol(raiz); }
};

int main() {

  srand(time(0));
  // Crear un árbol
  Arbol arbol(1, 3);

  arbol.InsertarNodos(arbol.raiz);
  arbol.InsertarNodos(arbol.raiz->hijos[0]);
  arbol.InsertarNodos(arbol.raiz->hijos[1]);
  arbol.InsertarNodos(arbol.raiz->hijos[2]);

  // Se imprime el arbol
  arbol.imprimir();

  return 0;
}
