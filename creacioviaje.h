#ifndef _CREACIOVIAJE_H_
#define _CREACIOVIAJE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void creacioviaje(viaje** viajes,int* num_viajes,vehiculo** vehiculos,int* num_vehiculos,paso** pasos,int* num_pasos);
void u_entrar_viaje(viaje** viajes,int* num_viajes,paso** pasos,int* num_pasos);

#endif
