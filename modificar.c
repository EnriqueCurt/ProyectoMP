#include <stdio.h>
#include <stdlib.h>
#include "struct_ficheros.h"

void u_modificar_viaje(viaje** viajes,int idviaje){
    char opcion;
    int opcion2;
    printf("¿desea cambiar el estado del viaje?\n");
    scanf("%c",&opcion);
    if(opcion=='s')
    {
        printf("elija una se las siguientes opciones:\n1:Abierto \n 2:Cerrado \n 3:Iniciado \n 4:Finalizado \n 5:Anulado");
        scanf("%i",&opcion2);
        switch (opcion2)
        {
        case 1 :
            strcat((*viajes)[idviaje].estado,"Abierto");
            puts("El estado del viaje ahora es Abierto");
            break;

        case 2 :
            strcat((*viajes)[idviaje].estado,"Cerrado");
            puts("El estado del viaje ahora es Cerrado");
            break;

        case 3 :
            strcat((*viajes)[idviaje].estado,"Iniciado");
            puts("El estado del viaje ahora es Iniciado");
            break;

        case 4 :
            strcat((*viajes)[idviaje].estado,"Finalizado");
            puts("El estado del viaje ahora es Finalizado");
            break;


        case 5 :
            strcat((*viajes)[idviaje].estado,"Anulado");
            puts("El estado del viaje ahora es Anulado");
            break;

       default :
            puts("Has escrito un estado que no esta en la lista asegurese de que esta bien escrito");
            break;
        }
    }
}
void u_modificar_usuario(usuario** usuarios,int i){
    int c;
modificador:
    printf("¿Que desea modificar?\n1.Nombre\n2.Localidad\n3.Nombre de cuenta\n4.Contrasena\n");
    fflush(stdin);
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        printf("Introduzca su nombre:\n");
        fflush(stdin);
        scanf("%20s",(*usuarios)[i].nombre);
        printf("Guardado con exito.\n");
        break;
    case 2:
        printf("Introduzca su localidad:\n");
        fflush(stdin);
        scanf("%20s",(*usuarios)[i].localidad);
        printf("Guardado con exito.\n");
        break;
    case 3:
        printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
        fflush(stdin);
        scanf("%5s",(*usuarios)[i].cuenta);
        for(i=0; i<=5; i++)
        {
            if((*usuarios)[i].cuenta[i]=='-')
            {
                printf("No se pueden introducir guiones.\n");
                printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
                fflush(stdin);
                scanf("%5s",(*usuarios)[i].cuenta);

            }
        }
        printf("Guardado con exito.\n");
        break;
    case 4:
        printf("Introduzca su contraseña(maximo de 8 caracteres, sin guiones):\n");
        fflush(stdin);
        scanf("%8s",(*usuarios)[i].contra);
        for(i=0; i<=9; i++)
        {
            if((*usuarios)[i].cuenta[i]=='-')
            {
                printf("No se pueden introducir guiones.\n");
                printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
                fflush(stdin);
                scanf("%5s",(*usuarios)[i].contra);
            }
        }
        printf("Guardado con exito.\n");
        break;
    default:
        goto modificador;
        break;
    }
Opcion:
    {
        printf("Desea modificar algo mas?\n1.Si\n2.No\n");
        fflush(stdin);
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            goto modificador;
            break;
        case 2:
            break;
        default:
            goto Opcion;
            break;
        }
    }
}
void u_crear_vehiculo(vehiculo** vehiculos,int i,int* num_vehiculos){
    char buffer[30];
    *vehiculos = (vehiculo *)realloc(*vehiculos,(*num_vehiculos+1) * sizeof(vehiculo ));
    sprintf(buffer, "%04d",i+1);
    strncat((*vehiculos)[*num_vehiculos].idusuario,buffer,5);
    printf("%s\n",(*vehiculos)[*num_vehiculos].idusuario);

    do{
    printf("Introduzca matricula(Debe de ser de 7 caracteres)\n");
    fflush(stdin);
    scanf("%7s",(*vehiculos)[*num_vehiculos].matricula);
    if(strlen((*vehiculos)[*num_vehiculos].matricula)!= 7){
        printf("Tamaño incorrecto\n");
        }
    }while(strlen((*vehiculos)[*num_vehiculos].matricula)!= 7);

    printf("Introduzca numero de plazas\n");
    fflush(stdin);
    scanf("%d",&(*vehiculos)[*num_vehiculos].plazas);
    printf("Introduzca una breve descripcion(maximo 50 caracteres)\n");
    fflush(stdin);
    scanf("%50s",(*vehiculos)[*num_vehiculos].descript);

    *num_vehiculos=*num_vehiculos+1;
}
