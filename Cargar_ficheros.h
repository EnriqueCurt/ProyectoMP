#ifndef _CARGAR_FICHEROS_H_
#define _CARGAR_FICHEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void cargar_usuarios_desde_archivo(const char* archivo, usuario** usuarios, int* num_usuarios);

void cargar_vehiculos_desde_archivo(const char* archivo, vehiculo** vehiculos, int* num_vehiculos);
void cargar_viajes_desde_archivo(const char* archivo, viaje** viajes, int* num_viajes);
void cargar_pasos_desde_archivo(const char* archivo, paso** pasos, int* num_pasos);
void cargar_ficheros(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos);
#endif
