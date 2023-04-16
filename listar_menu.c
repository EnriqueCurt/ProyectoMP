#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarUsuarios(usuario **usuarios,int num_usuarios){
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

void listarVehiculos(vehiculo **vehiculos,int num_vehiculos){
    for (int j = 0; j < num_vehiculos; j++) {
        printf("Id usuario %s Matricula=%s, plazas=%d , descripcion=%s \n",
               vehiculos[j].idusuario,
               vehiculos[j].matricula,
               vehiculos[j].plazas,
               vehiculos[j].descript);
}

void listarViajes (viaje **viajes,int num_viajes){
 printf("");
    for (int j = 0; j < num_viajes; j++) {
        printf("Id viaje=%s, Matricula=%s,fecha=%02d/%02d/%d , hora salida=%02d:%02d, hora llegada=%02d:%02d, ida o vuelta=%d, plazas=%d, precio=%.2f$, estado=%s \n",
               viajes[j].idviaje,
               viajes[j].matricula,
               viajes[j].fecha.dia,
               viajes[j].fecha.mes,
               viajes[j].fecha.ano,
               viajes[j].horasalida.horas,
               viajes[j].horasalida.minutos,
               viajes[j].horallegada.horas,
               viajes[j].horallegada.minutos,
               viajes[j].idavuelta,
               viajes[j].plazas,
               viajes[j].precio,
               viajes[j].estado);
    }
}
