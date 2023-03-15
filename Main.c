#include <stdio.h>
#include "struct_ficheros.h"
#include "Cargar_ficheros.h"
#include "Cargar_ficheros.c"
int main(){
    usuario u1;
    int resultado;

    resultado = cargar_datos_desde_archivo(&u1);
    if (resultado != 0) {
        printf("Error al cargar los datos desde el archivo\n");
        return 1;
    }



return 0;}
