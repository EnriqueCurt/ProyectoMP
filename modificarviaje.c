#include <stdio.h>
#include <stdlib.h>
#include "struct_ficheros.h"

void u_modificar_viaje(viaje** viajes,i){
	char opcion;
	int opcion2;
	printf("¿desea cambiar el estado del viaje?\n");
	scanf("$c",&opcion);
	if($opcion=="si"){
		printf("elija una se las siguientes opciones:\n Abierto \n Cerrado \n Iniciado \n Finalizado \n Anulado");
	scanf("$i",&opcion2);
		switch (opcion2){
			case 'Abierto' :
				strcat((*viajes)[idviaje].estado,"Abierto");
				puts("El estado del viaje ahora es Abierto");
				break;

			case 'Cerrado' :
				strcat((*viajes)[idviaje].estado,"Cerrado");
				puts("El estado del viaje ahora es Cerrado");
				break;

			case 'Iniciado' :
				strcat((*viajes)[idviaje].estado,"Iniciado");
				puts("El estado del viaje ahora es Iniciado");
				break;

			case 'Finalizado' :
				strcat((*viajes)[idviaje].estado,"Finalizado");
				puts("El estado del viaje ahora es Finalizado");
				break;


			case 'Anulado' :
				strcat((*viajes)[idviaje].estado,"Anulado");
				puts("El estado del viaje ahora es Anulado");
				break;

			case default :
				puts("Has escrito un estado que no esta en la lista asegurese de que esta bien escrito");
				break;
		}
	}
}
void u_modificar_usuario(usuario** usuarios,int* num_usuarios){
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
