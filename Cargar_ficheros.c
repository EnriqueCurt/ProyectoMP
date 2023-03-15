#include "struct_ficheros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void cargar_usuarios_desde_archivo(const char* archivo, usuario* usuarios, int* num_usuarios) {
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%s %s %s %d %s %s",
               usuarios[i].idusuario,
               usuarios[i].nombre,
               usuarios[i].localidad,
               &(usuarios[i].administrador),
               usuarios[i].cuenta,
               usuarios[i].contra);
        i++;
    }
    *num_usuarios = i;

    fclose(fp);
}
