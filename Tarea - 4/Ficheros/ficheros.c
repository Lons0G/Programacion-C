#include <stdio.h>

int main() {
  
  // Cargar el archivo
  FILE *fptr = fopen("archivo.txt", "w");

  // Si el archvio es nulo
  if (fptr == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }
  
  // Escribir en el archivo
  fprintf(fptr, "Hola, mundo en un archivo!\n");
  char cadena[] = "A'adi desde una variable";

  fprintf(fptr, "%s", cadena);

  int numero = 10;
  fprintf(fptr, "%i", numero);

  //Cerrar el archivo
  fclose(fptr);
  printf("Archivo escrito con exito");

  return 0;
}
