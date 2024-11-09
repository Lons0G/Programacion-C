#include <cstdio>
#include <iostream>

// Creacion de la clase
class Nodo {
public:
  int valor;
  Nodo *izq;
  Nodo *der;

  Nodo(int valor) {
    std::cout << "Creando un nodo con el valor " << valor << std::endl;
    this->valor = valor;
    this->izq = nullptr;
    this->der = nullptr;
  }
  Nodo(int valor, Nodo *izquierdo) {
    std::cout << "Creando un nodo con el valor " << valor
              << " y asignando un nodo a la izquierda" << std::endl;
    this->valor = valor;
    this->izq = izquierdo;
    this->der = nullptr;
  }
  ~Nodo() {
    std::cout << "Destruyendo un nodo con el valor " << valor
              << " y volviendo null izquierdo y derecho" << std::endl;
    this->izq = nullptr;
    this->der = nullptr;
  }
};

class Lista {
public:
  Nodo *cabeza;
  Nodo *cola;
  Lista() {
    std::cout << "Creando una lista vacia\n" << std::endl;
    this->cabeza = nullptr;
    this->cola = nullptr;
  }
  ~Lista() {
    Nodo *actual = cabeza;
    while (actual != nullptr) {
      Nodo *der = actual->der;
      delete actual;
      actual = der;
    }
  }

  void InsertarValor(int valor) {
    if (cabeza == nullptr) {
      std::cout << "Insertando el primer nodo a la lista\n" << std::endl;
      Nodo *nodo = new Nodo(valor);
      cabeza = nodo;
      cola = nodo;
    } else {
      std::cout << "Insertando un nodo a la lista\n" << std::endl;
      Nodo *nodo = new Nodo(valor, cola);
      cola->der = nodo;
      cola = nodo;
    }
  }

  void InsertarNodoInicio(Nodo *nodo) {
    if (cabeza == nullptr) {
      std::cout << "Insertando el primer nodo a la lista\n" << std::endl;
      cabeza = nodo;
      cola = nodo;
    } else {
      std::cout << "Insertando un nodo al inicio de la lista\n" << std::endl;
      nodo->der = cabeza;
      cabeza->izq = nodo;
      cabeza = nodo;
    }
  }

  void InsertarNodoFinal(Nodo *nodo) {
    if (cabeza == nullptr) {
      std::cout << "Insertando el primer nodo a la lista\n" << std::endl;
      cabeza = nodo;
      cola = nodo;
    } else {
      std::cout << "Insertando un nodo al final de la lista\n" << std::endl;
      cola->der = nodo;
      nodo->izq = cola;
      cola = nodo;
    }
  }

  void InsertarNodoPosicion(Nodo *nodo, int posicion) {
    if (posicion <= 1) {
      std::cout << "Se insertara al inicio el nuevo nodo con valor "
                << nodo->valor << std::endl;
      InsertarNodoInicio(nodo);
      return;
    }

    Nodo *actual = cabeza;
    while (actual != nullptr && 0 < posicion) {
      actual = actual->der;
      posicion--;
    }

    if (actual == nullptr) {
      std::cout << "Posición fuera de rango. Se Insertara al final de la lista "
                   "el nodo con valor "
                << nodo->valor << std::endl;
    }

    // Enlazar los nodos
    nodo->der = actual;
    nodo->izq = actual->izq;
    actual->izq->der = nodo;
    actual->izq = nodo;
  }
  void EliminarNodo(Nodo *nodo) {
    std::cout << "Destruyendo el nodo con el valor " << nodo->valor
              << std::endl;
    if (nodo == cabeza) {
      cabeza = cabeza->der;
      if (cabeza != nullptr) {
        cabeza->izq = nullptr;
      } else {
        cola = nullptr;
      }
    }

    else if (nodo == cola) {
      cola = cola->izq;
      if (cola != nullptr) {
        cabeza->der = nullptr;
      } else {
        cabeza = nullptr;
      }
    } else {
      nodo->izq->der = nodo->der;
      nodo->der->izq = nodo->izq;
    }

    delete nodo;
  }

  void Ordenamiento() {
    std::cout << "Ordenando la lista" << std::endl;
    Nodo *actual = cabeza->der;
    while (actual != nullptr) {
      int temp = actual->valor;
      Nodo *anterior = actual->izq;

      while (anterior != nullptr && temp < anterior->valor) {
        actual->valor = anterior->valor;
        actual = anterior;
        anterior = anterior->izq;
      }

      actual->valor = temp;
      actual = actual->der;
    }
  }

  static void RecorrerAdelante(Nodo *nodo) {
    if (nodo == nullptr) {
      std::cout << "\n";
      return;
    }
    std::cout << nodo->valor << " ";
    RecorrerAdelante(nodo->der);
  }

  void RecorrerAtras() {
    Nodo *actual = this->cola;
    while (actual != nullptr) {
      std::cout << actual->valor << " \n" << std::endl;
      actual = actual->izq;
    }
  }

  // Sobrecarga del operador + para concatenar listas
  Lista operator+(const Lista &otraLista) const {
    Lista nuevaLista;

    // Copiar los elementos de la lista actual a la nueva lista
    Nodo *actual = cabeza;
    while (actual != nullptr) {
      nuevaLista.InsertarNodoFinal(actual); // Pasamos el nodo directamente
      actual = actual->der;
    }

    // Copiar los elementos de la otra lista a la nueva lista
    actual = otraLista.cabeza;
    while (actual != nullptr) {
      nuevaLista.InsertarNodoFinal(actual);
      actual = actual->der;
    }

    return nuevaLista;
  }

  friend std::ostream &operator<<(std::ostream &os, const Lista &lista) {
    RecorrerAdelante(lista.cabeza);
    return os;
  }
};

int main() {
  Lista list;
  Nodo *nodo1 = new Nodo(2);
  Nodo *nodo2 = new Nodo(3);
  Nodo *nodo3 = new Nodo(15);
  Nodo *nodo4 = new Nodo(5);
  Nodo *nodo5 = new Nodo(1);

  list.InsertarNodoFinal(nodo1);
  list.InsertarNodoFinal(nodo2);
  list.InsertarNodoFinal(nodo3);
  list.InsertarNodoFinal(nodo4);
  list.InsertarNodoFinal(nodo5);
  std::cout << list << std::endl;

  list.EliminarNodo(nodo2);
  std::cout << list << std::endl;

  Nodo *nodo6 = new Nodo(17);
  list.InsertarNodoInicio(nodo6);
  Nodo *nodo7 = new Nodo(10);
  list.InsertarNodoPosicion(nodo7, 4);
  std::cout << list << std::endl;

  list.Ordenamiento();
  std::cout << list << std::endl;

  Lista lista2;
  Nodo *nodo8 = new Nodo(9);
  Nodo *nodo9 = new Nodo(33);
  Nodo *nodo10 = new Nodo(25);
  Nodo *nodo11 = new Nodo(14);
  Nodo *nodo12 = new Nodo(3);

  lista2.InsertarNodoFinal(nodo8);
  lista2.InsertarNodoFinal(nodo9);
  lista2.InsertarNodoFinal(nodo10);
  lista2.InsertarNodoFinal(nodo11);
  lista2.InsertarNodoFinal(nodo12);

  std::cout << lista2 << std::endl;

  std::cout << "Concatenando dos listas" << std::endl;
  Lista lista3 = list + lista2;

  std::cout << "Ordenando la nueva lista" << std::endl;
  lista3.Ordenamiento();
  std::cout << lista3 << std::endl;

  return 0;
}
