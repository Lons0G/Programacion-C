#include <stdio.h>

int main(){

  // Cargar el archivo
  FILE *fptr = fopen("archivo.txt", "w");

  // Si el archvio es nulo
  if (fptr == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  char buffer[100];
  while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
    printf("%s", buffer);
  }

  fclose(fptr);

  return 0;
}
