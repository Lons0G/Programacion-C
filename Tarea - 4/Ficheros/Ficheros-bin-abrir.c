#include <stdio.h>

int main() {
    // Abrir archivo en modo binario para escritura
    FILE *archivo = fopen("archivo.bin", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Datos a escribir
    int numero = 65536;
    float pi = 3.14159;
    char mensaje[] = "Hola Mundo";

    // Escribir datos binarios en el archivo
    fwrite(&numero, sizeof(int), 1, archivo);  // Escribir un entero
    fwrite(&pi, sizeof(float), 1, archivo);    // Escribir un flotante
    fwrite(mensaje, sizeof(mensaje), 1, archivo);  // Escribir cadena de texto

    // Cerrar el archivo
    fclose(archivo);
    return 0;
}
