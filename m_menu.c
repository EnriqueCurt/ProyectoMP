#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void menuInicio(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos){
    char opcion;
    printf("-------------------------------------------\n\nBienvenidos a ESI-Share\n\n-------------------------------------------\n\n");
    do{
    printf("\n--- Menu de inicio ---\n");
    printf("1. Login\n");
    printf("2. Registrarte\n");
    printf("3. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    switch(opcion){
            case '1':
                system("cls");
                iniciosesion(usuarios,num_usuarios,vehiculos,num_vehiculos,viajes,num_viajes,pasos,num_pasos);
                break;
            case '2':
                system("cls");
                registro(usuarios,num_usuarios);
                break;
            case '3':
                printf("\nSaliendo del menu de inicio...\n");
                system("cls");
                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo.\n\n");

            }
        }while(opcion != '3');
}
void menuUsuario(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos){

    char opcion ,selec;

       do {
        printf("--- Menu de usuario ---\n");
        printf("1. Gestionar perfil\n");
        printf("2. Gestionar vehiculos\n");
        printf("3. Gestionar viajes\n");
        printf("4. Salir\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);


        switch(opcion) {
            case '1':
                //Imprime datos del usuario
                printf("1. Modificar el usuario\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &selec);
                if(selec == '1');
                //Llamar la función de modificar el usuario
                system("cls");



                break;
            case '2':
                // Llamar a función para gestionar vehículos
                printf("1. Dar de alta un nuevo vehiculo\n");
                printf("2. Modificar el vehiculo\n");
                printf("3. Eliminar el vehiculo\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &selec);

                 switch(selec) {
                     case '1':
                        //Llamar la función para dar alta o baja el vehiculo
                        break;
                     case '2':
                        //Llamar la función para modificar el vehiculo
                        break;
                     case '3':
                         //Llamar la función para eliminar el vehiculo
                         break;
                 }system("cls");


                break;
            case '3':
                // Llamar a función para gestionar viajes
                printf("1. Publicar viajes\n");
                printf("2. Incorporarse en un viaje\n");
                printf("3. Mostrar el viaje\n");
                printf("4. Modificar el viaje\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &selec);

                 switch(selec) {
                     case '1':
                        //Llamar la función para publicar viaje
                        break;
                     case '2':
                        //Llamar la función para incorporar en un viaje
                        break;
                     case '3':
                         //Llamar la función para mostrar el viaje
                         break;
                     case '4':
                         //Llamar la función para modificar el viaje
                         break;
                 }system("cls");


                break;
            case '4':
                printf("\nSaliendo del menu usuario...\n");
                system("pause");
                system("cls");

                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo.\n");

            }
        } while(opcion != '4');

}

void menuAdmin(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos){

    char opcion, selec;

    do {
        printf("--- Menu de administrador ---\n");
        printf("1. Gestionar usuarios\n");
        printf("2. Gestionar vehiculos\n");
        printf("3. Gestionar viajes\n");
        printf("4. Salir\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
         system("cls");

        switch(opcion) {
            case '1':
                // Imprime por pantalla las función para gestionar usuarios
                printf("1. Dar alta o baja usuarios\n");
                printf("2. Modificar el usuario\n");
                printf("3. Listar usuarios\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &selec);

                 switch(selec) {
                     case '1':
                        //Llamar la función para dar alta o baja al usuario
                        break;
                     case '2':
                        //Llamar la función para modificar el usuario
                        break;
                     case '3':
                         //Llamar la función para listar usuarios

                         break;
                 }system("cls");


                break;
            case '2':
                // Imprime por pantalla las función para gestionar vehículos
                printf("1. Dar alta o baja el vehiculo\n");
                printf("2. Modificar el vehiculo\n");
                printf("3. Listar  vehiculos\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &selec);

                 switch(selec) {
                     case '1':
                        //Llamar la función para dar alta o baja al vehiculo
                        break;
                     case '2':
                        //Llamar la función para modificar el vehiculo
                        break;
                     case '3':
                         //Llamar la función para listar vehiculo

                         break;
                 }system("cls");

                break;
            case '3':
               // Imprime por pantalla las función para gestionar  viajes
                printf("1. Publicar viaje\n");
                printf("2. Modificar viaje\n");
                printf("3. Borrar viaje\n");
                printf("4. Listar viajes\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &selec);

                 switch(selec) {
                     case '1':
                        //Llamar la función para publicar viaje
                        break;
                     case '2':
                        //Llamar la función para modificar viaje
                        break;
                     case '3':
                         //Llamar la función para borrar viaje
                         break;
                     case '4':
                         //Llamar la función para listar viajes

                         break;
                 }system("cls");

                break;
            case '4':
                printf("\nSaliendo del menu de administrador...\n\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo.\n");


        }
    } while(opcion != '4');
}
