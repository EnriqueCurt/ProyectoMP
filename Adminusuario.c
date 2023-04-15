#include<stdio.h>
#include<stdlib.h>
#include "Cargar_ficheros.h"
#include "Adminusuario.h"

void alta(usuario** usuarios,int* num_usuarios)
{
    int idusuario,i,j;
    char buffer[30],nombre[20];
    *usuarios = (usuario *)realloc(*usuarios,(*num_usuarios+1) * sizeof(usuario));
    idusuario= *num_usuarios;                  //Calcula el id del nuevo usuario
    printf("Registarse:\n");
    sprintf(buffer, "%04d",(idusuario+1));
    strcat((*usuarios)[idusuario].idusuario,buffer);

    printf("Su id sera: %d\n",idusuario+1);

    printf("Introduzca su nombre:\n");
    fflush(stdin);
    scanf("%20s",nombre[20]);
    for(j=0;j=*num_usuarios;j++)
    {
        if(strcmp(nombre[20],(*usuarios)[j].nombre)==0)
        {
            if((*usuarios)[j].administrador==2)
            {
                printf("Esta persona esta dada de baja. Si desea darla de alta como usuario pulse 0. Si desea darla de alta como administrador pulse 1. Si desea que siga dada de baja pulse 2.\n");
                scanf("%d",&(*usuarios)[j].administrador);
                switch((*usuarios)[j].administrador)
                {
                case 0:
                    printf("La persona ha sido dada de alta como usuario.\n");
                    break;
                case 1:
                    printf("La persona ha sido dada de alta como administrador.\n");
                    break;
                case 2:
                    printf("La persona sigue estando dada de baja.\n");
                    break;
                }
                exit(0);
            }
            else
            {
                printf("El usuario ya esta dado de alta.\n");
                exit(0);
            }
        }
    }

    printf("Introduzca su localidad:\n");
    fflush(stdin);
    scanf("%20s",(*usuarios)[idusuario].localidad);

    do{
        printf("Pulse 1 si desea ser administrador, si no pulse 0:\n");
        fflush(stdin);
        scanf("%d",&(*usuarios)[idusuario].administrador);
    }while(((*usuarios)[idusuario].administrador != 0) && ((*usuarios)[idusuario].administrador != 1));

    printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
    fflush(stdin);
    scanf("%5s",(*usuarios)[idusuario].cuenta);
    for(i=0;i<=5;i++){
        if((*usuarios)[idusuario].cuenta[i]=='-')
        {
            printf("No se pueden introducir guiones.\n");
            printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
            fflush(stdin);
            scanf("%5s",(*usuarios)[idusuario].cuenta);

        }
    }
    printf("Introduzca su contraseña(maximo de 8 caracteres, sin guiones):\n");
    fflush(stdin);
    scanf("%8s",(*usuarios)[idusuario].contra);
    for(i=0;i<=9;i++){
        if((*usuarios)[idusuario].cuenta[i]=='-')
        {
            printf("No se pueden introducir guiones.\n");
            printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
            fflush(stdin);
            scanf("%5s",(*usuarios)[idusuario].contra);

        }
    }

    *num_usuarios=*num_usuarios+1;
}

void baja(usuario** usuarios,int* num_usuarios)
{
    int i;
    char nombre[20];
    printf("Introduzca el nombre del usuario al que quiera dar de baja\n");
    fflush(stdin);
    scanf("%20s",nombre);
    for(i=0;i=*num_usuarios;i++)
    {
        if(strcmp(nombre,(*usuarios)[i].nombre)==0)
        {
            (*usuarios)[i].administrador=2;
            printf("El usuario ha sido dado de baja.\n");
            exit(0);
        }
    }
    printf("Dicho usuario no existe");
}

void modificar(usuario** usuarios,int* num_usuarios)
{
    int i,c;
    char nombre[20];
    printf("Introduzca el nombre del usuario el cual quiera modificar\n");
    fflush(stdin);
    scanf("%20s",nombre);
    for(i=0;i=*num_usuarios;i++)
    {
        if(strcmp(nombre,(*usuarios)[i].nombre)==0)
        {
            modificador:
                {
                    printf("¿Que desea modificar?\n1.Nombre\n2.Localidad\n3.Administrador\n4.Nombre de cuenta\n5.Contrasena\n");
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
                        do{
                            printf("Pulse 1 si desea ser administrador, si no pulse 0:\n");
                            fflush(stdin);
                            scanf("%d",&(*usuarios)[i].administrador);
                        }while(((*usuarios)[i].administrador != 0) && ((*usuarios)[i].administrador != 1));
                        printf("Guardado con exito.\n");
                    case 4:
                        printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
                        fflush(stdin);
                        scanf("%5s",(*usuarios)[i].cuenta);
                        for(i=0;i<=5;i++){
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
                    case 5:
                        printf("Introduzca su contraseña(maximo de 8 caracteres, sin guiones):\n");
                        fflush(stdin);
                        scanf("%8s",(*usuarios)[i].contra);
                        for(i=0;i<=9;i++){
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
                            printf("¿Desea modificar algo mas?\n1.Si\n2.No");
                            scanf("%d",c);
                            switch(c)
                            {
                            case 1:
                                goto modificador;
                                break;
                            case 2:
                                exit(0);
                                break;
                            default:
                                goto Opcion;
                                break;
                            }
                        }
                }
        }
    }
    printf("Dicho usuario no existe.\n");
}
