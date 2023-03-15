#ifndef _STRUCT_FICHEROS_H_
#define _STRUCT_FICHEROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura para vehiculos.txt -> Almacena inforomación de los vehiculos del sistema.

typedef struct{
    char idusuario[4];
    char matricula[8];
    int plazas;
    char descript[50];
}vehiculo;

//Estructura para usuarios.txt -> Almacena información de los usuarios del sistema.

typedef struct{
    int idusuario[4];
    char nombre[20];        //nombre real de la persona
    char localidad[20];
    int administrador;  // 1 si es admin, 0 si no lo es
    char cuenta[5];     //  nombre de la cuenta
    char contra[8];     // la contraseña
}usuario;

//Estructura para viajes.txt -> Almacena información de los viajes.

typedef struct{
    char idviaje[6];
    char matricula[8];
    char fecha[11];         // "dd/mm/yyyy"
    char horasalida[6];     // hh:mm
    char horallegada[6];    // hh:mm
    int idavuelta;      // decimos 0 si es ida, 1 si es vuelta
    int plazas;
    float precio;
    char estado[11];    // estado del viaje
}viajes;

//Estructura para pasos.txt -> almancena info de plasos del viaje.

typedef struct{
    int idviaje[7];
    char poblados[20];
}pasos;

#endif
