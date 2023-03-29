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
        sscanf(line, "%[^-]-%[^-]-%[^-]-%d-%[^-]-%[^-]-",
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

void cargar_vehiculos_desde_archivo(const char* archivo, vehiculo* vehiculos, int* num_vehiculos) {
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]-%d-%[^-]",
               vehiculos[i].idusuario,
               vehiculos[i].matricula,
               &(vehiculos[i].plazas),
               vehiculos[i].descript);
        i++;
    }
    *num_vehiculos = i;

    fclose(fp);
}

void cargar_viajes_desde_archivo(const char* archivo, viaje* viajes, int* num_viajes) {
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%d-%d-%f-%[^-]",
               viajes[i].idviaje,
               viajes[i].matricula,
               viajes[i].fecha,
               viajes[i].horasalida,
               viajes[i].horallegada,
               &(viajes[i].idavuelta),
               &(viajes[i].plazas),
               &(viajes[i].precio),
               viajes[i].estado)
               ;
        i++;
    }
    *num_viajes = i;

    fclose(fp);
}
