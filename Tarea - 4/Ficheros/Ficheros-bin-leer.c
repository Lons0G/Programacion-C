#include <stdio.h>

int main() {
    // Abrir archivo en modo binario para lectura
    FILE *archivo = fopen("archivo.bin", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Variables para almacenar los datos leídos
    int numero;
    float pi;
    char mensaje[11];  // Longitud suficiente para "Hola Mundo" + '\0'

    // Leer los datos binarios del archivo
    fread(&numero, sizeof(int), 1, archivo);  // Leer un entero
    fread(&pi, sizeof(float), 1, archivo);    // Leer un flotante
    fread(mensaje, sizeof(mensaje), 1, archivo);  // Leer la cadena de texto

    // Mostrar los datos leídos
    printf("Numero: %d\n", numero);
    printf("Pi: %f\n", pi);
    printf("Mensaje: %s\n", mensaje);

  // Cerrar el archivo
    fclose(archivo);
    return 0;
}
