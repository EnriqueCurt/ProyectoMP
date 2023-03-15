#include <stdio.h>
#include "struct_ficheros.h"
#include "Cargar_ficheros.h"
#include "Cargar_ficheros.c"
int main(){
  usuario usuarios[100];
    int num_usuarios = 0;

    cargar_usuarios_desde_archivo("usuarios.txt", usuarios, &num_usuarios);

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



return 0;}
