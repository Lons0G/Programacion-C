#include <iostream>

class Nodo {
public:
  int data;
  Nodo *hijos[10];
  int numHijos;

  Nodo(int valor) : data(valor), numHijos(0) {
    for (int i = 0; i < 10; ++i) {
      hijos[i] = nullptr;
    }
  }

  void agregarHijo(Nodo *nuevoHijo) {
    if (numHijos < 10) {
      hijos[numHijos] = nuevoHijo;
      numHijos++;
    } else {
      std::cerr << "Error: El nodo ya tiene el máximo número de hijos."
                << std::endl;
    }
  }
};

class Arbol {
public:
  Nodo *raiz;

  Arbol(int valorRaiz) { raiz = new Nodo(valorRaiz); }

  // Función para insertar un nuevo nodo como hijo de un nodo existente
  void insertar(Nodo *nodoPadre, int valorHijo) {
    if (nodoPadre == nullptr) {
      std::cerr << "Error: Nodo padre no existe." << std::endl;
      return;
    }

    Nodo *nuevoHijo = new Nodo(valorHijo);
    nodoPadre->agregarHijo(nuevoHijo);
    std::cout << "Se inserto un nuevo nodo hijo " << nuevoHijo->data
              << " en el nodo padre " << nodoPadre->data << std::endl;
  }

  // Otras funciones útiles:
  // - Recorrido en preorden, inorden, postorden
  // - Calcular la altura del árbol
  // - Contar el número de nodos
  // - Eliminar un nodo
};
int main() {
  // Crear un árbol con raíz 1
  Arbol arbol(1);

  // Insertar hijos de la raíz
  arbol.insertar(arbol.raiz, 2);
  arbol.insertar(arbol.raiz, 3);

  // Insertar hijos del nodo con valor 2
  Nodo *nodo2 = arbol.raiz->hijos[0];
  arbol.insertar(nodo2, 4);
  arbol.insertar(nodo2, 5);

  // Imprimir el árbol (por ejemplo, en preorden)
  // ... (implementar la función de recorrido en preorden)

  return 0;
}
