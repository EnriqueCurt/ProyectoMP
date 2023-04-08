#ifndef _STRUCT_FICHEROS_H_
#define _STRUCT_FICHEROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
    }calendario;

//Estructura para vehiculos.txt -> Almacena inforomación de los vehiculos del sistema.

typedef struct{
    char idusuario[5];
    char matricula[8];
    int plazas;
    char descript[50];
}vehiculo;

//Estructura para usuarios.txt -> Almacena información de los usuarios del sistema.

typedef struct{
    char idusuario[5];
    char nombre[20];        //nombre real de la persona
    char localidad[20];
    int administrador;  // 1 si es admin, 0 si no lo es
    char cuenta[5];     //  nombre de la cuenta
    char contra[8];     // la contraseña
}usuario;

typedef struct{
    int horas;
    int minutos;
    }horario;

//Estructura para viajes.txt -> Almacena información de los viajes.

typedef struct{
    char idviaje[7];
    char matricula[8];
    calendario fecha;         // "dd/mm/yyyy"
    horario horasalida;     // hh:mm
    horario horallegada;    // hh:mm
    int idavuelta;      // decimos 0 si es ida, 1 si es vuelta
    int plazas;
    float precio;
    char estado[11];    // estado del viaje
}viaje;

//Estructura para pasos.txt -> almancena info de plasos del viaje.

typedef struct{
    char idviaje[7];
    char poblados[20];
}paso;

#endif

