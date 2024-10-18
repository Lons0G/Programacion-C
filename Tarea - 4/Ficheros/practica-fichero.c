#include <stdio.h>
#include <stdlib.h>

int main(){

  int random = rand() % 100;

  printf("%d", random);

  // Cargar el archivo
  FILE *fptr = fopen("practica.bin", "wb");

  // Si el archvio es nulo
  if (fptr == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  // Escribir datos binarios en el archivo
  fwrite(&random, sizeof(int), 1, fptr);  // Escribir un entero
  
  fclose(fptr);

  // Lectura del archivo binario
  FILE *archivo_bin = fopen("practica.bin", "rb");
  FILE *archivo_txt = fopen("practica.txt", "w");


  // Si el archvio es nulo
  if (archivo_bin == NULL || archivo_txt == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  int num_txt = 0;
  fread(&num_txt, sizeof(int), 1, archivo_bin);  // Leer un entero
  printf("numero extraido del archivo bin %d", num_txt);
  fprintf(archivo_txt, "%i", num_txt);  

  fclose(archivo_bin);
  fclose(archivo_txt);


  //Lectura del archivo txt
  FILE *archivo_txt_lectura = fopen("practica.txt", "r");

  // Si el archvio es nulo
  if (archivo_txt_lectura == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }
  
  char buffer_txt[100];
  while (fgets(buffer_txt, sizeof(buffer_txt), archivo_txt_lectura) != NULL) {
    printf("%s", buffer_txt);
  }
  return 0;
}
