#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void menuInicio(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos)
{
    char opcion;
    printf("-------------------------------------------\n\nBienvenidos a ESI-Share\n\n-------------------------------------------\n\n");
    do
    {
        printf("--- Menu de inicio ---\n");
        printf("1. Login\n");
        printf("2. Registrarte\n");
        printf("3. Salir\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
        switch(opcion)
        {
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
            system("pause");
            system("cls");
            break;
        default:
            printf("\nOpcion invalida, vuelva a intentarlo.\n\n");

        }
    }
    while(opcion != '3');
}
void menuUsuario(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos,int i)
{

    char opcion,selec;

    do
    {
        printf("--- Menu de usuario ---\n");
        printf("1. Gestionar perfil\n");
        printf("2. Gestionar vehiculos\n");
        printf("3. Gestionar viajes\n");
        printf("4. Salir\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);


        switch(opcion)
        {
        case '1':
            system("cls");
            printf("Usuario %d: id=%s, nombre=%s, localidad=%s, admin=%d, cuenta=%s, contra=%s\n\n",
                   i+1,
                   (*usuarios)[i].idusuario,
                   (*usuarios)[i].nombre,
                   (*usuarios)[i].localidad,
                   (*usuarios)[i].administrador,
                   (*usuarios)[i].cuenta,
                   (*usuarios)[i].contra);
            printf("1. Modificar el usuario\n");
            printf("\nElija una opcion: ");
            fflush(stdin);
            scanf("%c", &selec);
            if(selec == '1');
            u_modificar_usuario(usuarios,i);
            system("cls");



            break;
        case '2':
            // Llamar a funci�n para gestionar veh�culos
            printf("1. Dar de alta un nuevo vehiculo\n");
            printf("2. Modificar el vehiculo\n");
            printf("3. Eliminar el vehiculo\n");
            printf("\nElija una opcion: ");
            fflush(stdin);
            scanf("%c", &selec);

            switch(selec)
            {
            case '1':
                system("cls");
                u_crear_vehiculo(vehiculos,i,num_vehiculos);
                break;
            case '2':
                system("cls");
                u_modificar_vehiculo(vehiculos,i,num_vehiculos);
                break;
            case '3':
                system("cls");
                u_borrar_vehiculo(vehiculos,i,num_vehiculos);
                break;
            }
            system("cls");


            break;
        case '3':
            // Llamar a funci�n para gestionar viajes
            printf("1. Publicar viajes\n");
            printf("2. Incorporarse en un viaje\n");
            printf("3. Modificar el viaje\n");
            printf("\nElija una opcion: ");
            fflush(stdin);
            scanf("%c", &selec);

            switch(selec)
            {
            case '1':
                system("cls");
                creacioviaje(viajes,num_viajes,vehiculos,num_vehiculos,pasos,num_pasos);
                break;
            case '2':
                system("cls");
                u_entrar_viaje(viajes,num_viajes,pasos,num_pasos);
                break;
            case '3':
                system("cls");
                u_modificar_viaje(viajes,num_viajes,i,vehiculos,num_vehiculos);
                break;
            }
            system("cls");


            break;
        case '4':
            printf("\nSaliendo del menu usuario...\n");
            system("pause");
            system("cls");

            break;
        default:
            printf("\nOpcion invalida, vuelva a intentarlo.\n");

        }
    }
    while(opcion != '4');

}
void menuAdmin(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos)
{

    char opcion, selec;

    do
    {
        printf("--- Menu de administrador ---\n");
        printf("1. Gestionar usuarios\n");
        printf("2. Gestionar vehiculos\n");
        printf("3. Gestionar viajes\n");
        printf("4. Salir\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
        system("cls");

        switch(opcion)
        {
        case '1':
            // Imprime por pantalla las funci�n para gestionar usuarios
            printf("1. Dar alta o baja usuarios\n");
            printf("2. Modificar el usuario\n");
            printf("3. Listar usuarios\n");
            printf("\nElija una opcion: ");
            fflush(stdin);
            scanf("%c", &selec);

            switch(selec)
            {
            case '1':
                system("cls");
                admin_registro_baja(usuarios,num_usuarios);
                break;
            case '2':
                system("cls");
                admin_modificar_usuarios(usuarios,num_usuarios);
                break;
            case '3':
                system("cls");
                listarUsuarios(usuarios,num_usuarios);
                break;
            }
            system("cls");


            break;
        case '2':
            // Imprime por pantalla las funci�n para gestionar veh�culos
            printf("1. Dar alta o baja el vehiculo\n");
            printf("2. Modificar el vehiculo\n");
            printf("3. Listar  vehiculos\n");
            printf("\nElija una opcion: ");
            fflush(stdin);
            scanf("%c", &selec);

            switch(selec)
            {
            case '1':
                system("cls");
                admin_registro_baja_vehiculo(vehiculos,num_vehiculos,num_usuarios);
                break;
            case '2':
                system("cls");
                admin_modificar_vehiculo(vehiculos,num_vehiculos,num_usuarios);
                break;
            case '3':
                system("cls");
                listarVehiculos(vehiculos,num_vehiculos);
                break;
            }
            system("cls");

            break;
        case '3':
            // Imprime por pantalla las funci�n para gestionar  viajes
            printf("1. Publicar viaje\n");
            printf("2. Modificar viaje\n");
            printf("3. Borrar viaje\n");
            printf("4. Listar viajes\n");
            printf("\nElija una opcion: ");
            fflush(stdin);
            scanf("%c", &selec);

            switch(selec)
            {
            case '1':
                system("cls");
                creacioviaje(viajes,num_viajes,vehiculos,num_vehiculos,pasos,num_pasos);
                break;
            case '2':
                system("cls");
                admin_modificar_viaje(viajes,num_viajes,vehiculos,num_vehiculos,num_usuarios);
                break;
            case '3':
                system("cls");
                admin_borrar_viaje(viajes, num_viajes);
                break;
            case '4':
                system("cls");
                listarViajes(viajes,num_viajes);
                break;
            }
            system("cls");

            break;
        case '4':
            printf("\nSaliendo del menu de administrador...\n\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("\nOpcion invalida, vuelva a intentarlo.\n");


        }
    }
    while(opcion != '4');
}
