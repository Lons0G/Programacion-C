#include <iostream>

class Arreglo {
private:
  int *arr;
  int size;

public:
  Arreglo(int s) : size(s) {
    arr = new int[size];
    for (int i = 0; i < size; ++i) {
      arr[i] = 0;
    }
  }

  ~Arreglo() { delete[] arr; }
  // Método para print el contenido del arreglo
  void print() const {
    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  // Sobrecarga del operador ++
  Arreglo &operator++() {
    for (int i = 0; i < size; ++i) {
      arr[i] += 1;
    }
    return *this;
  }

  // Sobrecarga del operador --
  Arreglo &operator--() {
    for (int i = 0; i < size; ++i) {
      arr[i] -= 1;
    }
    return *this;
  }

  // Sobrecarga del operador *=
  Arreglo &operator*=(int n) {
    for (int i = 0; i < size; i++) {
      arr[i] *= n;
    }
    return *this;
  }

  // Sobrecarga del operador +=
  Arreglo &operator+=(Arreglo &arr_2) {
    if (this->size != arr_2.size) {
      std::cout << "los arreglos no son de la misma longuitud" << '\n';
      return *this;
    }
    for (int i = 0; i < size; i++) {
      arr[i] += arr_2.arr[i];
    }
    return *this;
  }

  // Sobrecarga del operador +=
  Arreglo &operator+=(int n) {
    for (int i = 0; i < size; i++) {
      arr[i] += n;
    }
    return *this;
  }

  // Sobrecarga del operador -=
  Arreglo &operator-=(Arreglo &arr_2) {
    if (this->size != arr_2.size) {
      std::cout << "los arreglos no son de la misma longuitud" << '\n';
      return *this;
    }
    for (int i = 0; i < size; i++) {
      arr[i] -= arr_2.arr[i];
    }
    return *this;
  }

  // Sobrecarga del operador -=
  Arreglo &operator-=(int n) {
    for (int i = 0; i < size; i++) {
      arr[i] -= n;
    }
    return *this;
  }

  // Sobrecarga del operador /=
  Arreglo &operator/=(int n) {
    for (int i = 0; i < size; i++) {
      arr[i] /= n;
    }
    return *this;
  }

  // Sobrecarga del operador /=
  Arreglo &operator/=(Arreglo &arr_2) {
    if (this->size != arr_2.size) {
      std::cout << "los arreglos no son de la misma longuitud" << '\n';
      return *this;
    }
    for (int i = 0; i < size; i++) {
      arr[i] /= arr_2.arr[i];
    }
    return *this;
  }
};

int main() {
  std::cout << "Creacion del arreglo con 10 elementos" << '\n';
  Arreglo arr(10);
  arr.print();

  // Suma en 1
  std::cout << "Sumatoria del arreglo en 1" << '\n';
  ++arr;
  ++arr;
  arr.print();

  // Resta en 1
  std::cout << "Resta del arreglo en 1" << '\n';
  --arr;
  arr.print();

  // Multiplicacion de cada elemento
  std::cout << "Multplicacion del arreglo por 5" << '\n';
  arr *= 5;
  arr.print();

  // Suma de una cantidad n a cada elemento
  std::cout << "Suma de una cantidad n del arreglo" << '\n';
  arr += 6;
  arr.print();

  // Sumatoria de dos arreglos
  std::cout << "Suma de dos arreglos" << '\n';
  Arreglo arr_2(10);
  ++arr_2;
  arr += arr_2;
  arr.print();

  // Resta de una cantidad n a cada elemento
  std::cout << "Resta de una cantidad n del arreglo" << '\n';
  arr -= 2;
  arr.print();

  // Resta de dos arreglos
  std::cout << "Resta de dos arreglo" << '\n';
  arr -= arr_2;
  arr.print();

  // Resta de una cantidad n a cada elemento
  std::cout << "Division de una cantidad n del arreglo" << '\n';
  arr /= 3;
  arr.print();

  // Resta de dos arreglos
  std::cout << "Division de dos arreglo" << '\n';
  arr /= arr_2;
  arr.print();

  return 0;
}
