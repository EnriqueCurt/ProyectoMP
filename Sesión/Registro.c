//Este módulo se encargará de registrar a los nuevos usuarios (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todavía pueden no haber sido creados)
//Por Juan Edriss Bueno Smidi


#include<stdio.h>
#include<string.h>
#include<Cargar_ficheros.h>
#include<Registro.h>

void registro(usuario* usuarios,int* num_usuarios)
{

    printf("Registarse:\n");

    (*usuarios)[*num_usuarios+1].id=*num_usuarios+1;                                                            //Calcula el id del nuevo usuario

    printf("Su id sera: %d\n",*num_usuarios+1);

    printf("Introduzca su nombre:\n");                                                                          //Registro del nombre real del nuevo usuario
    scanf("%20s",(*usuarios)[*num_usuarios+1].nombre);

    printf("Introduzca su localidad:\n");                                                                       //Registro de la localidad del nuevo usuario
    scanf("%20s",(*usuarios)[*num_usuarios+1].localidad);

    do                                                                                                          //Elección entre ser o no ser administrador
    {
        printf("Pulse 1 si desea ser administrador, si no pulse 0:\n");
        scanf("%d",(*usuarios)[*num_usuarios+1].administrador);
    }while((*usuarios)[*num_usuarios+1].administrador!=0&&(*usuarios)[*num_usuarios+1].administrador!=1)        //Solo admitirá 0 (para ser un usuario normal) o 1(para ser administrador)

    printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
    scanf("%5s",(*usuarios)[*num_usuarios+1].cuenta);
    for(i=0;i=5;i++)                                                                                            //Comprueba que no haya guiones
    {
        if((*usuarios)[*num_usuarios+1].cuenta[i]="-")
        {
            printf("No se pueden introducir guiones.\n");
            printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
            scanf("%5s",(*usuarios)[*num_usuarios+1].cuenta);
            i=-1;                                                                                               //Reinicia el bucle
        }
    }

    printf("Escriba su contraseña (maximo de 8 caracteres, sin guiones):\n");
    scanf("%8s",(*usuarios)[*num_usuarios+1].contra);
    for(i=0;i=5;i++)                                                                                            //Comprueba que no haya guiones
    {
        if((*usuarios)[*num_usuarios+1].cuenta[i]="-")
        {
            printf("No se pueden introducir guiones.\n");
            printf("Escriba su contraseña (maximo de 8 caracteres, sin guiones):\n");
            scanf("%8s",(*usuarios)[*num_usuarios+1].contra);
            i=-1;                                                                                               //Reinicia el bucle
        }
    }

    (*num_usuarios)++;                                                                                          //Actualiza el número de usuarios registrados
}
