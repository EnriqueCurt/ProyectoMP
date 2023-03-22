#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definición de constantes
#define MAX_USERS 100
#define MAX_LONG_USERS 50
#define MAX_LONG_PASSW 50

//Definición de estructuras
typedef struct{
    char usuario[MAX_LONG_USERS];
    char contraseña[MAX_LONG_PASSW];
    int perfil;
}Usuario
//Definicion de funciones
int leerUsuarios(Usuario usuarios[]);
int verificarUsuario(usuario, contrasena, usuarios, numUsuarios);

int main (){
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
            printf("¿Desea registrarse? (s/n): ");
            char opcion;
            scanf(" %c", &opcion);
            if (opcion == 's' || opcion == 'S') {
                // TODO: Registrar al usuario en el archivo Usuarios.txt
                printf("Registrado correctamente como usuario normal\n");
                perfil = 1;
            }
        }
    } while (perfil == -1); 

    if (perfil == 0) {
        printf("Bienvenido, administrador %s\n", usuario);
        // TODO: Implementar funcionalidad para administradores
        
        printf("¿Que deseas hacer?");
        char ch;
        ch = getchar() 
        switch(c){
                  case '1': puts("Acceder al perfil");
                   break;
                   case '2' :puts("Acceder al vehiculos");
                    break;
                    case '3' :puts("Acceder al viajes");
                     break;
        }
    
        scanf("%c",&ch);
        if(opcion == 1){
                  printf("Que deseas hacer en el perfil");
                  char = c1
                  ch = getchar()
                  switch(c1){
                             case '1': //Dar de alta o baja al usuario
                             break;
                             case '2' : //Hacer una modificación
                             break;
                             case '3' : //Hacer un listado de usuarios
                             break;
                             }
                  }
        if(opcion == 2){
                  printf("Que deseas hacer en el vehiulos");
                  char = c2
                  ch = getchar()
                  switch(c2){
                             case '1': //Dar de alta o baja el vehiculo
                             break;
                             case '2' //Hacer una modificación
                             break;
                             case '3' //Hacer un listado de vehiculos
                             break;
                             }
                  }
        if(opcion == 3){
                  printf("Que deseas hacer en el viajes");
                  (c2){
                             case '1': //Publicar un viaje
                             break;
                             case '2' //Modificar un viaje
                             break;
                             case '3' //Eliminar un viaje
                             break;
                             case '4' :puts("Listar todos los viajes");
                             break;
                             }
                  }
        
    } else {
        printf("Bienvenido, usuario %s\n", usuario); 
        printf("Que quieres hacer?");
        // TODO: Implementar funcionalidad para usuarios normales
         printf("Donde quieres acceder?");
        char opcion;
        scanf("%c",&opcion);
        if(opcion == 1){
                  printf("Estas en el perfil");
                  printf("Deseas modificar algun dato");
                  }
        if(opcion == 2){
                  printf("Estas en vehiculos");
                  
                  }
        if(opcion == 3){
                  printf("Estas en viajes");   
                  }
    }

    return 0;
}
