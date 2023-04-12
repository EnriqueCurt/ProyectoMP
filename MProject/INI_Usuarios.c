#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definición de constantes
#define MAX_USERS 100
#define MAX_LONG_USER 50
#define MAX_LONG_PASSW 50

//Definición de estructuras
typedef struct{
    char usuarios[MAX_USERS];
    char usuario[MAX_LONG_USER];
    char contrasena[MAX_LONG_PASSW];
    int perfil;
}Usuario;


   int main() {

    Usuario usuarios[MAX_USERS];
    int numUsuarios;
    char usuario[MAX_LONG_USER];
    char contrasena[MAX_LONG_PASSW];
    int perfil;

    numUsuarios = leerUsuarios(usuarios);
    if (numUsuarios == -1) {
        printf("Error al abrir el archivo Usuarios.txt\n");
        return 1;
    }

    printf("Bienvenido a ESI-SHARE\n");
    do {
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contraseña: ");
        scanf("%s", contrasena);

        perfil = verificarUsuario(usuario, contrasena, usuarios, numUsuarios);
        if (perfil == -1) {
            printf("Usuario o contraseña incorrectos\n");
            printf("Si desea registrarse teclee (R/r): ");
            printf("Si desea volver intentarlo teclee (I/i): ");

            char opcion;
            scanf(" %c", &opcion);
            if (opcion == 'r' || opcion == 'R') {
                // TODO: Registrar al usuario en el archivo Usuarios.txt
                printf("Registrado correctamente como usuario normal\n");
                perfil = 1;

            if(opcion == 'i' ||opcion == 'I')


            }
            }
        }
    } while (perfil == -1);

    if (perfil == 0) {
        printf("Bienvenido, administrador %s\n", usuario);
        // TODO: Implementar funcionalidad para administradores

    } else {
        printf("Bienvenido, usuario %s\n", usuario);
        // TODO: Implementar funcionalidad para administradores




    }
    system("pause");
    return 0;

}




