//Este módulo se encargará de registrar a los nuevos usuarios (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todavía pueden no haber sido creados)
//Por Juan Edriss Bueno Smidi
#include<stdio.h>
#include<string.h>
#include "Cargar_ficheros.h"
#include "Registro.h"

void registro(usuario** usuarios,int* num_usuarios){
    int idusuario,i;
    char buffer[30];
    *usuarios = (usuario *)realloc(*usuarios,(*num_usuarios+1) * sizeof(usuario));
    idusuario= *num_usuarios;                  //Calcula el id del nuevo usuario
    printf("-------Registarse-------\n");
    sprintf(buffer, "%04d",(idusuario+1));
    strcat((*usuarios)[idusuario].idusuario,buffer);

    printf("\nSu id sera: %d\n",idusuario+1);

    printf("\nIntroduzca su nombre:\n");
    fflush(stdin);                                                                       //Registro del nombre real del nuevo usuario
    scanf("%20s",(*usuarios)[idusuario].nombre);

    printf("\nIntroduzca su localidad:\n");
    fflush(stdin);                                                                      //Registro de la localidad del nuevo usuario
    scanf("%20s",(*usuarios)[idusuario].localidad);

    do{                                                                                                       //Elección entre ser o no ser administrador
        printf("\nPulse 1 si desea ser administrador, si no pulse 0:\n");
        fflush(stdin);
        scanf("%d",&(*usuarios)[idusuario].administrador);
    }while(((*usuarios)[idusuario].administrador != 0) && ((*usuarios)[idusuario].administrador != 1));        //Solo admitirá 0 (para ser un usuario normal) o 1(para ser administrador)

    printf("\nIntroduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
    fflush(stdin);
    scanf("%5s",(*usuarios)[idusuario].cuenta);
    for(i=0;i<=5;i++){                                                                                            //Comprueba que no haya guiones
        if((*usuarios)[idusuario].cuenta[i]=='-')
        {
            printf("No se pueden introducir guiones.\n");
            printf("\nIntroduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
            fflush(stdin);
            scanf("%5s",(*usuarios)[idusuario].cuenta);

        }
    }
    printf("\nIntroduzca su contrasena(maximo de 8 caracteres, sin guiones):\n");
    fflush(stdin);
    scanf("%8s",(*usuarios)[idusuario].contra);
    for(i=0;i<=9;i++){                                                                                            //Comprueba que no haya guiones
        if((*usuarios)[idusuario].cuenta[i]=='-')
        {
            printf("No se pueden introducir guiones.\n");
            printf("\nIntroduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
            fflush(stdin);
            scanf("%5s",(*usuarios)[idusuario].contra);
        }
    }

    *num_usuarios=idusuario+1;
    printf("\nRegistro realizado correctamente\n");
    system("pause");
    system("cls");
}
