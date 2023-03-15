#include<stdio.h>
#include "struct_ficheros.h"
#include "Cargar_ficheros.h"
#include <stdlib.h>
#include <string.h>

int cargar_datos_desde_archivo(usuario* u1) {

    FILE* archivo;
    char linea[100];

    archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    while (fgets(linea, 100, archivo)) {
        sscanf(linea,"%s %s %s %i %s %s",u1->idusuario, u1->nombre, u1->localidad, &u1->administrador, u1->cuenta, u1->contra);
         printf("ID: %s Nombre: %s Localidad: %s Admin: %i Cuenta: %s Contrasena: %s ", u1->idusuario,u1->nombre, u1->localidad, u1->administrador, u1->cuenta, u1->contra);
    }

    fclose(archivo);
    }
