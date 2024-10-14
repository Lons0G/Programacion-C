#include <stdio.h>

int main() {
  unsigned long long valor = 123456789012345ULL;
  unsigned long long desplazamiento = 32;

  unsigned long long corr_izq = valor << desplazamiento;
  unsigned long long valor_izq = valor >> (sizeof(long long) - desplazamiento);

  unsigned long long corr_der = valor >> desplazamiento;
  unsigned long long valor_der = valor << (sizeof(long long) - desplazamiento);

  unsigned long long des_izq = corr_izq | valor_izq;
  unsigned long long des_der = corr_der | valor_der;

  printf("\nCorrimiento circular a la izquierda\n");
  printf("\n %llx \n", corr_izq);
  printf("\n %llx \n", valor_izq);
  printf("\n %llx \n", des_izq);

  printf("\nCorrimiento circular a la derecha\n");
  printf("\n %llx \n", corr_der);
  printf("\n %llx \n", valor_der);
  printf("\n %llx \n", des_der);
  return 0;
}
