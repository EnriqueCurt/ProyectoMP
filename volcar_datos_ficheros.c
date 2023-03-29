#include "struct_ficheros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void volcar_datos_usuarios_archivo(const char* archivo, usuario* usuarios, int* num_usuarios){
FILE* fp = fopen(archivo, "w");
    if (!fp) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        exit(1);
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    for(i=0;i<u;i++){
            strcpy(line, usuario[i].idusuario);
            strcat(line, "-");
            strcat(line, usuario[i].nombre);
            strcat(line, "-");
            strcat(line, usuario[i].localidad);
            strcat(line, "-");
            strcat(line, usuario[i].administrador);
            strcat(line, "-");
            strcat(line, usuario[i].cuenta);
            strcat(line, "-");
            strcat(line, usuario[i].contra);
            if(i <*num_usuarios) {  // no agregar '\n' al final del archivo
                strcat(line, "\n");
            }
            printf("%s",line);
            fprintf(fu, "%s", line);
        }
    }
    fclose(fu);
    }




}
