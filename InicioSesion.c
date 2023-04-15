//Este módulo se encargará de iniciar sesión (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todavía pueden no haber sido creados)
//Por Juan Edriss Bueno Smidi
#include <stdio.h>
#include <string.h>
#include "InicioSesion.h"
#include "Registro.h"

void iniciosesion(usuario **usuarios, int* n){
    int i,no_existe,registrar;
    no_existe=1;
    char cuenta[6],contra[9];
    while(no_existe==1){
        printf("Nombre de cuenta:\n");
        fflush(stdin);
        scanf("%6s",cuenta);
        printf("Contrasena:\n");
        fflush(stdin);
        scanf("%9s",contra);

        for(i=0; (no_existe==1) && i<(*n) ;i++){
            if((strcmp((*usuarios)[i].cuenta,cuenta)&& strcmp((*usuarios)[i].contra,contra))==0){
                no_existe=0;
            }
        }
        if(no_existe==1){
        do{
            printf("Usuario o Contrasena incorrecta\nPulse 1 para volver a intentarlo\nPulse 2 para registrarse\n");
            fflush(stdin);
            scanf("%d",&no_existe);
        }while(no_existe!=1 && no_existe!=2);
        }
    }
    if(no_existe==2){
        registro(usuarios,n);
    }
    if((*usuarios)[i].administrador==0){
                    //menunormal;                                         //Se le redirigirá al menú de usuario normal
        }
    if((*usuarios)[i].administrador==1){
                    //menuadministrador;                                  //Se le redirigirá al menú de administrador
        }
    if((*usuarios)[i].administrador==2){
        printf("Usted esta baneado del programa");
        exit(0);
        }
}
