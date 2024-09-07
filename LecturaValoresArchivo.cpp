#include <stdio.h>
int main() 
{
	char caracter;
	int num;
	FILE *archivo;
	archivo = fopen("valores.txt", "r");
	if (archivo == NULL) 
	{	
		perror("Error al abrir el archivo");
		return 1;
	}
	while(feof(archivo)==0)
	{
		fscanf(archivo, "%d", &num );
		printf("%d\n",num);
	}
	// Cierra el archivo después de usarlo
	fclose(archivo);
	return 0;
}
