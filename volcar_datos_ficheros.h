#ifndef _VOLCAR_DATOS_FICHEROS_H_
#define _VOLCAR_DATOS_FICHEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void volcar_datos_usuarios_archivo(const char* archivo, usuario** usuarios, int* num_usuarios);
void volcar_datos_vehiculos_archivo(const char* archivo, vehiculo** vehiculos, int* num_vehiculos);
void volcar_datos_viajes_archivo(const char* archivo, viaje** viajes, int* num_viajes);
void volcar_datos_pasos_archivo(const char* archivo, paso** pasos, int* num_pasos);
void volcar_ficheros(usuario* usuarios, int* num_usuarios,vehiculo* vehiculos, int* num_vehiculos,viaje* viajes, int* num_viajes,paso* pasos, int* num_pasos);
#endif
