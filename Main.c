#include <stdio.h>
#include "struct_ficheros.h"
#include "Cargar_ficheros.h"
#include "Cargar_ficheros.c"
int main(){
  usuario usuarios[100];
  vehiculo vehiculos[100];
  viaje viajes[100];
    int num_usuarios = 0;
    int num_vehiculos = 0;
    int num_viajes = 0;


    cargar_usuarios_desde_archivo("usuarios.txt", usuarios, &num_usuarios);
    cargar_vehiculos_desde_archivo("vehiculos.txt", vehiculos, &num_vehiculos);
    cargar_viajes_desde_archivo("viajes.txt", viajes,&num_viajes);

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
        printf("Id viaje=%s, Matricula=%s,fecha=%s , hora salida=%s, hora llegada=%s, ida o vuelta=%d, plazas=%d, precio=%.2f, estado=%s \n",
               viajes[j].idviaje,
               viajes[j].matricula,
               viajes[j].fecha,
               viajes[j].horasalida,
               viajes[j].horallegada,
               viajes[j].idavuelta,
               viajes[j].plazas,
               viajes[j].precio,
               viajes[j].estado);
    }

return 0;
}
