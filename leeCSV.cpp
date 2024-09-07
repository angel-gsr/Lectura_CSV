#include <cstdio>

int main() {
    FILE *archivo;
    char palabra[100];

    // Abre el archivo en modo lectura
    archivo = fopen("archivo.csv", "r");

    if (archivo != NULL) {
        // Lee palabras del archivo e impr�melas
        while (fscanf(archivo, "%[^,\n]", palabra) == 1) {
            printf("Palabra: %s\n", palabra);
            fgetc(archivo); // Consume la coma o el car�cter de nueva l�nea
        }

        // Cierra el archivo
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo 'archivo.csv'\n");
    }

    return 0;
}

