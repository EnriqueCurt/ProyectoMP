#ifndef _CREACIOVIAJE_H_
#define _CREACIOVIAJE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void u_modificar_viaje(viaje** viajes,int* num_viajes,int i,vehiculo** vehiculos,int* num_vehiculos);
void u_modificar_usuario(usuario** usuarios,int i);
void u_crear_vehiculo(vehiculo** vehiculos,int i,int* num_vehiculos);
void u_modificar_vehiculo(vehiculo** vehiculos,int i, int* num_vehiculos);
void u_borrar_vehiculo(vehiculo** vehiculos,int i, int* num_vehiculos);
void admin_registro_baja(usuario** usuarios,int* num_usuarios);
void admin_modificar_usuarios(usuario** usuarios,int* num_usuarios);
void admin_registro_baja_vehiculo(vehiculo** vehiculos, int* num_vehiculos,int* num_usuarios);
void admin_modificar_vehiculo(vehiculo** vehiculos,int *num_vehiculos,int* num_usuarios);
void admin_modificar_viaje(viaje** viajes,int* num_viajes,vehiculo** vehiculos,int* num_vehiculos,int* num_usuarios);
void admin_borrar_viaje(viaje** viajes,int* num_viajes);

#endif
