#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int Iguales(std::vector<int> dados, int valor) {
  int sum = 0;
  for (int dado : dados) {
    if (dado == valor) {
      sum += dado;
    }
  }
  return sum;
}

int Suerte(std::vector<int> dados) {
  int sum = 0;
  for (int dado : dados) {
    sum += dado;
  }
  return sum;
}

bool Tipo(std::vector<int> dados, int valor) {
  bool valido = false;

  int frecuencia[6] = {0};
  for (int dado : dados) {
    frecuencia[dado - 1]++;
  }
  for (int i = 0; i < 6; i++) {
    if (frecuencia[i] == valor) {
      valido = true;
    }
  }
  return valido;
}

bool Secuencia(std::vector<int> dados, int secuencia) {
  std::sort(dados.begin(), dados.end());

  bool valido = false;
  int sec = dados[0];
  for (int i = 1; i < dados.size(); ++i) {
    if (dados[i] == sec + 1) {
      sec++;
    }
  }
  if (sec >= 4 && secuencia == 0) {
    valido = true;
  } else if (sec >= 5 && secuencia == 1) {
    valido = true;
  }
  return valido;
}

bool FULL_HOUSE(std::vector<int> dados) {
  bool valido = false;
  int tres = 0;
  int dos = 0;
  int frecuencia[6] = {0};

  for (int dado : dados) {
    frecuencia[dado - 1]++;
  }
  for (int i = 0; i < 6; i++) {
    if (frecuencia[i] == 3) {
      tres = 1;
    }
    if (frecuencia[i] == 2) {
      dos = 1;
    }
    if (tres && dos) {
      valido = true;
    }
  }
  return valido;
}

int simulacion() {

  std::ofstream archivo("simulaciones.txt", std::ios::app);

  std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  std::vector<int> dados(5);
  std::vector<int> puntaje(13);

  while (!numeros.empty()) {

    int indiceAleatorio = rand() % numeros.size();
    int seleccion_categoria = numeros[indiceAleatorio];

    // std::cout << "Categoria seleccionada: " << seleccion_categoria <<
    // std::endl;

    numeros.erase(numeros.begin() + indiceAleatorio);

    for (int i = 0; i < dados.size(); ++i) {
      dados[i] = rand() % 6 + 1;
    }

    // std::cout << "Valores del los dados: " << std::endl;
    // for (int i = 0; i < dados.size(); ++i) {
    //   std::cout << dados[i] << " ";
    // }
    // std::cout << "\n";

    switch (seleccion_categoria) {
    case 1:
      // std::cout << "Categoria UNOS" << std::endl;

      archivo << "Dados 1: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }

      puntaje[0] = Iguales(dados, 1);
      archivo << "\n";
      break;
    case 2:
      // archivo << "Categoria DOS" << std::endl;

      archivo << "Dados 1: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }

      puntaje[1] = Iguales(dados, 2);
      archivo << "\n";
      break;
    case 3:
      // archivo << "Categoria TRES" << std::endl;

      archivo << "Dados 2: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      puntaje[2] = Iguales(dados, 3);
      archivo << "\n";
      break;
    case 4:
      // archivo << "Categoria CUATROS" << std::endl;
      archivo << "Dados 3: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      puntaje[3] = Iguales(dados, 4);
      archivo << "\n";
      break;
    case 5:
      // archivo << "Categoria CINCOS" << std::endl;
      archivo << "Dados 4: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      puntaje[4] = Iguales(dados, 5);
      archivo << "\n";
      break;
    case 6:
      // archivo << "Categoria SEISES" << std::endl;
      archivo << "Dados 5: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      puntaje[5] = Iguales(dados, 6);
      archivo << "\n";
      break;
    case 7:
      // archivo << "Categoria SUERTE" << std::endl;
      archivo << "Dados 6: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      puntaje[6] = Suerte(dados);
      archivo << "\n";
      break;
    case 8:
      // archivo << "Categoria TRES DE UN TIPO" << std::endl;
      archivo << "Dados 7: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      if (Tipo(dados, 3)) {
        puntaje[7] = Suerte(dados);
      }
      archivo << "\n";
      break;
    case 9:
      // archivo << "Categoria CUATRO DE UN TIPO" << std::endl;
      archivo << "Dados 8: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      if (Tipo(dados, 4)) {
        puntaje[8] = Suerte(dados);
      }
      archivo << "\n";
      break;
    case 10:
      // archivo << "Categoria CINCO DE UN TIPO" << std::endl;
      archivo << "Dados 9: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      if (Tipo(dados, 5)) {
        puntaje[9] = Suerte(dados);
      }
      archivo << "\n";
      break;
    case 11:
      //  archivo << "Categoria SECUENCIA CORTA" << std::endl;
      archivo << "Dados 10: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      if (Secuencia(dados, 0)) {
        puntaje[10] = 25;
      }
      archivo << "\n";
      break;
    case 12:
      //  archivo << "Categoria SECUENCIA LARGA" << std::endl;
      archivo << "Dados 11: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      if (Secuencia(dados, 1)) {
        puntaje[11] = 35;
      }
      archivo << "\n";
      break;
    case 13:
      // std::cout << "Categoria FULL HOUSE" << std::endl;
      archivo << "Dados 12: " << " ";
      for (int i = 0; i < dados.size(); ++i) {
        archivo << dados[i] << " ";
      }
      archivo << "\n";
      if (FULL_HOUSE(dados)) {
        puntaje[12] = 40;
      }
      break;
    }
  }
  int total = 0;
  int suma = 0;
  int bono = 0;

  // Sumar los 6 primeros elementos
  for (int i = 0; i < 6; ++i) {
    suma += puntaje[i];
  }

  if (suma >= 63) {
    bono = 35;
  }

  // std::cout << "Puntajes de las categorias" << std::endl;
  for (int i = 0; i < puntaje.size(); ++i) {
    archivo << puntaje[i] << " ";
  }

  for (int i = 0; i < 13; ++i) {
    total += puntaje[i];
  }
  total += bono;
  archivo << bono << " " << total << std::endl;

  archivo.close();
  return total;
}

int main() {
  int i = 0;
  int resultados[1000] = {0};
  int tam = sizeof(resultados) / sizeof(resultados[0]);
  srand(time(0));
  while (i < 1000) {
    resultados[i] = simulacion();

    i++;
  }

  int count[1000] = {0};
  int maxFreq = 0;
  int mostFrequent = 0;

  for (int num : resultados) {
    count[num]++;
    maxFreq = std::max(maxFreq, count[num]);
  }

  for (int i = 0; i < 1000; i++) {
    if (count[i] == maxFreq) {
      mostFrequent = i;
      break;
    }
  }

  int minimo = *std::min_element(resultados, resultados + tam);
  int maximo = *std::max_element(resultados, resultados + tam);

  // Imprimir resultados
  std::cout << "Puntaje minimo: " << minimo << std::endl;
  std::cout << "Puntaje maximo: " << maximo << std::endl;
  std::cout << "Puntaje mas comun: " << mostFrequent << std::endl;
  return 0;
}
