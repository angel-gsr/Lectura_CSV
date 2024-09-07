#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxColumn 4000  
#define filas 50 
#define longMax 25000

int main() 
{
    FILE *archivo_entrada = fopen("emails.csv", "r");
    if (!archivo_entrada) 
	{
        perror("Error al abrir el archivo CSV");
        return 1;
    }

    char buffer[longMax];
    char *palabras[maxColumn];
    int veces[maxColumn] = {0};
    int IDterm = 266; //terminacion de mi ID

    if (fgets(buffer, sizeof(buffer), archivo_entrada)) 
	{
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna <= maxColumn) 
		{
            palabras[columna] = strdup(token); 
            token = strtok(NULL, ",");
            columna++;
        }
    }

    for (int fila_actual = 1; fila_actual < IDterm-1 && fgets(buffer, sizeof(buffer), archivo_entrada); ++fila_actual) {
        
    }

    for (int fila_actual = 0; fila_actual < filas && fgets(buffer, sizeof(buffer), archivo_entrada); fila_actual++) 
	{
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < maxColumn) 
		{
            veces[columna] += atoi(token);  
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(archivo_entrada);

    FILE *archivo_salida = fopen("181266.txt", "w");
    if (!archivo_salida) 
	{
        perror("Error al abrir el archivo de salida");
        for (int i = 0; i < maxColumn; i++) 
		{
            free(palabras[i]);
        }
        return 1;
    }

    for (int i = 1; i < maxColumn && palabras[i] != NULL; i++) 
	{
        fprintf(archivo_salida, "%s, %d\n", palabras[i], veces[i]);
        free(palabras[i]); 
    }

    fclose(archivo_salida);
    printf("Los conteos de palabras han sido escritos en 181266.txt\n");

    return 0;
}
