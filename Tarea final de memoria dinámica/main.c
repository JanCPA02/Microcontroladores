#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *args[]) {
    char *input_string;
    FILE *archivo;
    long int x = strlen(args[2:10]);
    int y = strlen(args[1]);

    char nombre_archivo[y+1];
    strcpy(nombre_archivo, args[1]);

    printf("La longitud de la cadena es es %ld\n", x);
    printf("El nombre del dato es %s\n", nombre_archivo);

    input_string = (char *)malloc((x+1) * sizeof(char));
    if (input_string == NULL) {
        printf("Error: No se pudo asignar memoria.");
        return 1;
    }
    strcpy(input_string,args[2]);

    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo.");
        return 1;
    }
    fprintf(archivo, "%s", input_string);
    fclose(archivo);
    free(input_string);

    return 0;
}
