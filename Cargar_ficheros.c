#include "struct_ficheros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void cargar_usuarios_desde_archivo(const char* archivo, usuario** usuarios, int* num_usuarios) {
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
    linecount++;
    *usuarios = (usuario *)realloc(*usuarios,linecount * sizeof(usuario ));
    fseek(fp, 0, SEEK_SET);

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]-%[^-]-%d-%[^-]-%[^-]",
               (*usuarios)[i].idusuario,
               (*usuarios)[i].nombre,
               (*usuarios)[i].localidad,
               &(*usuarios)[i].administrador,
               (*usuarios)[i].cuenta,
               (*usuarios)[i].contra);
        i++;
    }
    *num_usuarios = linecount;

    fclose(fp);
}


void cargar_vehiculos_desde_archivo(const char* archivo, vehiculo** vehiculos, int* num_vehiculos) {
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
    linecount++;
    *vehiculos = (vehiculo *)realloc(*vehiculos,linecount * sizeof(vehiculo ));
    fseek(fp, 0, SEEK_SET);

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]-%d-%[^-]",
                (*vehiculos)[i].idusuario,
                (*vehiculos)[i].matricula,
                &(*vehiculos)[i].plazas,
                (*vehiculos)[i].descript);
        i++;
    }
    *num_vehiculos = linecount;

    fclose(fp);
}


void cargar_viajes_desde_archivo(const char* archivo, viaje** viajes, int* num_viajes) {
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
    linecount++;
    *viajes = (viaje *)realloc(*viajes,linecount * sizeof(viaje ));
    fseek(fp, 0, SEEK_SET);

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]-%d/%d/%d-%d:%d-%d:%d-%d-%d-%f-%[^-]",
                (*viajes)[i].idviaje,
                (*viajes)[i].matricula,
                &(*viajes)[i].fecha.dia,
                &(*viajes)[i].fecha.mes,
                &(*viajes)[i].fecha.ano,
                &(*viajes)[i].horasalida.horas,
                &(*viajes)[i].horasalida.minutos,
                &(*viajes)[i].horallegada.horas,
                &(*viajes)[i].horallegada.minutos,
                &(*viajes)[i].idavuelta,
                &(*viajes)[i].plazas,
                &(*viajes)[i].precio,
                (*viajes)[i].estado);
        i++;
    }
    *num_viajes = linecount;

    fclose(fp);
}

void cargar_pasos_desde_archivo(const char* archivo, paso** pasos, int* num_pasos) {
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
    linecount++;
    *pasos = (paso *)realloc(*pasos,linecount * sizeof(paso ));
    fseek(fp, 0, SEEK_SET);

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        sscanf(line, "%[^-]-%[^-]",
                (*pasos)[i].idviaje,
                (*pasos)[i].poblados);
        i++;
    }
    *num_pasos = linecount;

    fclose(fp);
}

void cargar_ficheros(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos){
    cargar_usuarios_desde_archivo("usuarios.txt",usuarios, num_usuarios);
    cargar_vehiculos_desde_archivo("vehiculos.txt",vehiculos, num_vehiculos);
    cargar_viajes_desde_archivo("viajes.txt",viajes,num_viajes);
    cargar_pasos_desde_archivo("pasos.txt",pasos,num_pasos);
}
