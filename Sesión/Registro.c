//Este módulo se encargará de registrar a los nuevos usuarios (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todavía pueden no haber sido creados)
//Por Juan Edriss Bueno Smidi


#include<stdio.h>
#include<string.h>
#include<Cargar_ficheros.h>
#include<Registro.h>

void registro(usuario* usuarios,int* num_usuarios)
{

    printf("Registarse:\n");

    (*usuarios)[*num_usuarios].id=*num_usuarios+1;

    printf("Su id sera: %d\n",*num_usuarios+1);

    printf("Introduzca su nombre:\n");
    scanf("%20s",(*usuarios)[*num_usuarios+1].nombre);

    printf("Introduzca su localidad:\n");
    scanf("%20s",(*usuarios)[*num_usuarios+1].localidad);

    printf("Pulse 1 si desea ser administrador, si no pulse 0:\n");
    scanf("%d",(*usuarios)[*num_usuarios+1].administrador);

    printf("Introduzca su nombre de cuenta (maximo de 5 caracteres):\n");
    scanf("%5s",(*usuarios)[*num_usuarios+1].cuenta);

    printf("Escriba su contraseña (maximo de 8 caracteres):\n");
    scanf("%8s",(*usuarios)[*num_usuarios+1].contra);

    (*num_usuarios)++;
}
