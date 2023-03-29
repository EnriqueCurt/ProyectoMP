#include "struct_ficheros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void cargar_usuarios_desde_archivo(const char* archivo, usuario* usuarios, int* num_usuarios) {
    char ch;
    int linecount = 0;
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linecount++;
        }
    }
    usuarios=(usuario*)malloc(linecount * sizeof(usuario));

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
    *num_usuarios = linecount;

    fclose(fp);
}

void cargar_vehiculos_desde_archivo(const char* archivo, vehiculo* vehiculos, int* num_vehiculos) {
    char ch;
    int linecount = 0;
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linecount++;
        }
    }
    vehiculos=(vehiculo*)malloc(linecount * sizeof(vehiculo));
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
    *num_vehiculos = linecount;

    fclose(fp);
}

void cargar_viajes_desde_archivo(const char* archivo, viaje* viajes, int* num_viajes) {
    char ch;
    int linecount = 0;
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linecount++;
        }
    }
    viajes=(viaje*)malloc(linecount * sizeof(viaje));

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
    *num_viajes = linecount;

    fclose(fp);
}
void cargar_pasos_desde_archivo(const char* archivo, paso* pasos, int* num_pasos) {
    char ch;
    int linecount = 0;
    FILE* fp = fopen(archivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linecount++;
        }
    }
    pasos=(paso*)malloc(linecount * sizeof(paso));

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]",
               pasos[i].idviaje,
               pasos[i].poblados);
               ;
        i++;
    }
    *num_pasos = linecount;

    fclose(fp);
}
void cargar_ficheros(usuario* usuarios, int* num_usuarios,vehiculo* vehiculos, int* num_vehiculos,viaje* viajes, int* num_viajes,paso* pasos, int* num_pasos){
    cargar_usuarios_desde_archivo("usuarios.txt", usuarios, num_usuarios);
    cargar_vehiculos_desde_archivo("vehiculos.txt", vehiculos, num_vehiculos);
    cargar_viajes_desde_archivo("viajes.txt", viajes,num_viajes);
    cargar_pasos_desde_archivo("pasos.txt", pasos,num_pasos);
}
