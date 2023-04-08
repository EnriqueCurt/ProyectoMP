#include <stdio.h>
#include "struct_ficheros.h"
#include "Cargar_ficheros.h"
#include "Cargar_ficheros.c"
int main(){
  usuario* usuarios = (usuario*)malloc(sizeof(usuario));
  vehiculo* vehiculos =(vehiculo*)malloc(sizeof(vehiculo));
  viaje* viajes = (viaje*)malloc(sizeof(viaje));
  paso* pasos =( paso*)malloc(sizeof(paso));
    int num_usuarios = 0;
    int num_vehiculos = 0;
    int num_viajes = 0;
    int num_pasos = 0;
    cargar_ficheros(&usuarios,&num_usuarios,&vehiculos,&num_vehiculos,&viajes,&num_viajes,&pasos,&num_pasos);

    printf("Se cargaron %d usuarios desde el archivo\n", num_usuarios);
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

    printf("Se cargaron %d vehiculos desde el archivo\n", num_vehiculos);
    for (int j = 0; j < num_vehiculos; j++) {
        printf("Id usuario %s Matricula=%s, plazas=%d , descripcion=%s \n",
               vehiculos[j].idusuario,
               vehiculos[j].matricula,
               vehiculos[j].plazas,
               vehiculos[j].descript);
    }

    printf("Se cargaron %d viajes desde el archivo\n", num_vehiculos);
    for (int j = 0; j < num_vehiculos; j++) {
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

    printf("Se cargaron %d pasos desde el archivo\n", num_pasos);
    for (int j = 0; j < num_vehiculos; j++) {
        printf("Id viaje=%s,Poblacion=%s \n",
               pasos[j].idviaje,
               pasos[j].poblados);
    }

return 0;
}
