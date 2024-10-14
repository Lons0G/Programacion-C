#include <stdio.h>
#include <stdlib.h>

void corrimiento_circular(unsigned int hexadecimal, unsigned int desplazamiento,
                          unsigned int *corr_izq, unsigned int *corr_der) {

  // Corrimiento circular a la izquierda
  unsigned int temp_izq = hexadecimal << desplazamiento;
  printf("\n Resultado de temp_izq: %x \n", temp_izq);
  unsigned int recuperacion_izq = hexadecimal >> (32 - desplazamiento);
  printf("\n Resultado de recuperacion_izq: %x \n", recuperacion_izq);

  *corr_izq = temp_izq | recuperacion_izq;

  // Corrimiento circular a la derecha
  unsigned int temp_der = hexadecimal >> desplazamiento;
  printf("\n Resultado de temp_der: %x \n", temp_der);
  unsigned int recuperacion_der = hexadecimal << (32 - desplazamiento);
  printf("\n Resultado de recuperacion_der: %x \n", recuperacion_der);
  *corr_der = temp_der | recuperacion_der;
}

int main() {
  unsigned int hexadecimal, cant_desp;
  unsigned int resultado_izq, resultado_der;

  // Solicitar entradas al usuario
  printf("Ingrese el número en hexadecimal (sin el prefijo 0x): ");
  scanf("%x", &hexadecimal);
  printf("Ingrese el número de bits a desplazar: ");
  scanf("%u", &cant_desp);

  // Validar que el desplazamiento esté en el rango correcto
  if (cant_desp > 31) {
    fprintf(stderr,
            "Error: El número de bits a desplazar debe estar entre 0 y 31.\n");
    return EXIT_FAILURE;
  }

  // Llamar a la función de corrimiento circular
  corrimiento_circular(hexadecimal, cant_desp, &resultado_izq, &resultado_der);

  // Mostrar los resultados
  printf("Resultados:\n");
  printf("Número original: %x\n", hexadecimal);
  printf("Resultado del corrimiento circular a la izquierda: %x\n",
         resultado_izq);
  printf("Resultado del corrimiento circular a la derecha: %x\n",
         resultado_der);

  return EXIT_SUCCESS;
}
