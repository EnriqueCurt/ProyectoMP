#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char opcion;
    int perfil;

    printf("Si eres admnistrador pulse 0 usuario pulse cualquier numero ");
    scanf("%d",&perfil);
     system("cls");

    if(perfil == 0){
    do {
        printf("\n--- Menu de administrador ---\n");
        printf("1. Gestionar usuarios\n");
        printf("2. Gestionar vehículos\n");
        printf("3. Gestionar viajes\n");
        printf("4. Salir\n");
        printf("\nElija una opción: ");
        fflush(stdin);
        scanf("%c", &opcion);
         system("cls");

        switch(opcion) {
            case '1':
                // Llamar a función para gestionar usuarios
                printf("1. Dar alta o baja\n");
                printf("2. Modificar el usuario\n");
                printf("3. Listar usuarios\n");
                 system("cls");
                break;
            case '2':
                // Llamar a función para gestionar vehículos
                printf("1. Dar alta o baja el vehiculo\n");
                printf("2. Modificar el vehiculo\n");
                printf("3. Listar  vehiculos\n");
                 system("cls");
                break;
            case '3':
                // Llamar a función para gestionar viajes
                printf("1. Publicar viajes\n");
                printf("2. Modificar viajes\n");
                printf("3. Borrar viajes\n");
                printf("4. Listar viajes\n");
                 system("cls");
                break;
            case '4':
                printf("\nSaliendo del menu de administrador...\n");
                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo.\n");


        }
    } while(opcion != '4');
    }
    else {
        do {
        printf("\n--- Menu de usuario ---\n");
        printf("1. Gestionar perfil\n");
        printf("2. Gestionar vehiculos\n");
        printf("3. Gestionar viajes\n");
        printf("4. Salir\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
         system("cls");

        switch(opcion) {
            case '1':
                // Llamar a función para gestionar perfil
                printf("1. Modificar el usuario\n");
                 system("cls");
                break;
            case '2':
                // Llamar a función para gestionar vehículos
                printf("1. Dar de alta un nuevo vehiculo\n");
                printf("2. Modificar el vehiculo\n");
                printf("3. Eliminar el vehiculo\n");
                 system("cls");
                break;
            case '3':
                // Llamar a función para gestionar viajes
                printf("1. Publicar viajes\n");
                printf("2. Incorporarse a un viaje\n");
                printf("3. Visualizar el viaje\n");
                printf("4. Modificar el usuarios\n");
                 system("cls");
                break;
            case '4':
                printf("\nSaliendo del menu usuario...\n");

                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo.\n");

            }
        } while(opcion != '4');
    }

    system("pause");
    return 0;

}


