#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarUsuarios(){
for (int i = 0; i < num_usuarios; i++) {
        printf("Usuario %d: id=%s, nombre=%s, localidad=%s, admin=%d, cuenta=%s, contra=%s\n",
               i+1,
               usuarios[i].idusuario,
               usuarios[i].nombre,
               usuarios[i].localidad,
               usuarios[i].administrador,
               usuarios[i].cuenta,
               usuarios[i].contra);
}

void listarVehiculos (){
    for (int j = 0; j < num_vehiculos; j++) {
        printf("Id usuario %s Matricula=%s, plazas=%d , descripcion=%s \n",
               vehiculos[j].idusuario,
               vehiculos[j].matricula,
               vehiculos[j].plazas,
               vehiculos[j].descript);
}

void listarViajes
