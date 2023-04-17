//Este módulo se encargará de iniciar sesión (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todavía pueden no haber sido creados)
//Por Juan Edriss Bueno Smidi
#include <stdio.h>
#include <string.h>
#include "InicioSesion.h"
#include "Registro.h"
#include "m_menu.h"

void iniciosesion(usuario** usuarios, int* num_usuarios,vehiculo** vehiculos, int* num_vehiculos,viaje** viajes, int* num_viajes,paso** pasos, int* num_pasos){
    int i,no_existe,registrar;
    i=0;
    no_existe=1;
    char cuenta[6],contra[9];
    while(no_existe==1){
        printf("Nombre de cuenta:\n");
        fflush(stdin);
        scanf("%5s",cuenta);
        printf("Contrasena:\n");
        fflush(stdin);
        scanf("%8s",contra);
        for(i=0; (no_existe==1) && (i < (*num_usuarios)) ;i++){
            if((strncmp((*usuarios)[i].cuenta,cuenta,5)== 0) && (strncmp((*usuarios)[i].contra,contra,8)==0)){
                no_existe=0;
                printf("\nLogin correcto\n\n");
                system("pause");
                system("cls");
                break;
            }
        }
        if(no_existe==1){
        do{
            printf("\nUsuario o Contrasena incorrecta\n\nPulse 1 para volver a intentarlo\nPulse 2 para registrarse\n\n");
            fflush(stdin);
            scanf("%d",&no_existe);
        }while(no_existe!=1 && no_existe!=2);
        }
    }
    if(no_existe==2){
        system("cls");
        registro(usuarios,num_usuarios);
    }
    if((*usuarios)[i].administrador==0){
        menuUsuario(usuarios,num_usuarios,vehiculos,num_vehiculos,viajes,num_viajes,pasos,num_pasos,i);                                         //Se le redirigirá al menú de usuario normal
        }
    if((*usuarios)[i].administrador==1){
        menuAdmin(usuarios,num_usuarios,vehiculos,num_vehiculos,viajes,num_viajes,pasos,num_pasos);                                   //Se le redirigirá al menú de administrador
        }
    if((*usuarios)[i].administrador==2){
        printf("\nUsted esta baneado del programa\n\n");
        system("pause");
        system("cls");

        }
}
