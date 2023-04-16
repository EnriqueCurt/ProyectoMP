#include "struct_ficheros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void volcar_datos_usuarios_archivo(const char* archivo, usuario* usuarios, int* num_usuarios){
FILE* fp = fopen(archivo, "w");
char buffer[20];
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    for(i=0;i<*num_usuarios;i++){
            strcpy(line, usuarios[i].idusuario);
            strcat(line, "-");
            strcat(line, usuarios[i].nombre);
            strcat(line, "-");
            strcat(line, usuarios[i].localidad);
            strcat(line, "-");
            sprintf(buffer, "%d",usuarios[i].administrador);
            strcat(line,buffer);
            strcat(line, "-");
            strcat(line, usuarios[i].cuenta);
            strcat(line, "-");
            strcat(line, usuarios[i].contra);
            if(line[strlen(line)-1] == '\n'){
                line[strlen(line)-1] = '\0';
            }
             if(i < *num_usuarios-1){
                fprintf(fp, "%s\n", line);
            }
            if(i == (*num_usuarios)-1){
                line[strlen(line)] = '\0' ;
                fprintf(fp, "%s", line);
            }
        }
        fclose(fp);
    }

void volcar_datos_vehiculos_archivo(const char* archivo, vehiculo* vehiculos, int* num_vehiculos){
    FILE* fp = fopen(archivo, "w");
    char buffer[20];
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    for(i=0;i<*num_vehiculos;i++){
            strcpy(line, vehiculos[i].idusuario);
            strcat(line, "-");
            strcat(line, vehiculos[i].matricula);
            strcat(line, "-");
            sprintf(buffer, "%d",vehiculos[i].plazas);
            strcat(line,buffer);
            strcat(line, "-");
            strcat(line, vehiculos[i].descript);
            if(line[strlen(line)-1] == '\n'){
                line[strlen(line)-1] = '\0';
            }
             if(i<*num_vehiculos-1){
                fprintf(fp, "%s\n", line);
            }
            if(i==*num_vehiculos-1){
                line[strlen(line)] = '\0' ;
                fprintf(fp, "%s", line);
            }
        }
        fclose(fp);
}
void volcar_datos_viajes_archivo(const char* archivo, viaje* viajes, int* num_viajes){
    FILE* fp = fopen(archivo, "w");
    char buffer[20];
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    for(i=0;i<*num_viajes;i++){
            strcpy(line, viajes[i].idviaje);
            strcat(line, "-");
            strcat(line, viajes[i].matricula);
            strcat(line, "-");
            sprintf(buffer, "%02d",viajes[i].fecha.dia);
            strcat(line,buffer);
            strcat(line, "/");
            sprintf(buffer, "%02d",viajes[i].fecha.mes);
            strcat(line,buffer);
            strcat(line,"/");
            sprintf(buffer,"%d",viajes[i].fecha.ano);
            strcat(line,buffer);
            strcat(line,"-");
            sprintf(buffer,"%02d",viajes[i].horasalida.horas);
            strcat(line,buffer);
            strcat(line,":");
            sprintf(buffer,"%02d",viajes[i].horasalida.minutos);
            strcat(line,buffer);
            strcat(line,"-");
            sprintf(buffer,"%02d",viajes[i].horallegada.horas);
            strcat(line,buffer);
            strcat(line,":");
            sprintf(buffer,"%02d",viajes[i].horallegada.minutos);
            strcat(line,buffer);
            strcat(line,"-");
            sprintf(buffer,"%d",viajes[i].idavuelta);
            strcat(line,buffer);
            strcat(line,"-");
            sprintf(buffer,"%d",viajes[i].plazas);
            strcat(line,buffer);
            strcat(line,"-");
            sprintf(buffer,"%.2f",viajes[i].precio);
            strcat(line,buffer);
            strcat(line,"-");
            strcat(line,viajes[i].estado);
            if(line[strlen(line)-1] == '\n'){
                line[strlen(line)-1] = '\0';
            }
             if(i<*num_viajes-1){
                fprintf(fp, "%s\n", line);
            }
            if(i==*num_viajes-1){
                line[strlen(line)] = '\0' ;
                fprintf(fp, "%s", line);
            }
        }
        fclose(fp);
}

void volcar_datos_pasos_archivo(const char* archivo, paso* pasos, int* num_pasos){
FILE* fp = fopen(archivo, "w");
char buffer[20];
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    for(i=0;i < *num_pasos;i++){
            strcpy(line, pasos[i].idviaje);
            strcat(line, "-");
            strcat(line, pasos[i].poblados);
            if(line[strlen(line)-1] == '\n'){
                line[strlen(line)-1] = '\0';
            }
             if(i < *num_pasos-1){
                fprintf(fp, "%s\n", line);
            }
            if(i == *num_pasos-1){
                line[strlen(line)] = '\0' ;
                fprintf(fp, "%s", line);
            }
        }
        fclose(fp);
    }
void volcar_ficheros(usuario* usuarios, int* num_usuarios,vehiculo* vehiculos, int* num_vehiculos,viaje* viajes, int* num_viajes,paso* pasos, int* num_pasos){
volcar_datos_usuarios_archivo("usuarios.txt",usuarios,num_usuarios);
volcar_datos_vehiculos_archivo("vehiculos.txt",vehiculos,num_vehiculos);
volcar_datos_viajes_archivo("viajes.txt",viajes,num_viajes);
volcar_datos_pasos_archivo("pasos.txt",pasos,num_pasos);
printf("\nVolcado realizado exitosamente\n");
}
