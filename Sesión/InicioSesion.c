//Este m�dulo se encargar� de iniciar sesi�n (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todav�a pueden no haber sido creados)
//Por Juan Edriss Bueno Smidi

#include<stdio.h>
#include<string.h>
#include<Cargar_ficheros.h>
#include<struct_ficheros.h>
#include<InicioSesion>

void iniciosesion(usuario *usuarios, int n)
{
    int i,existe;
    char cuenta[5],contra[8];
    printf("Nombre de cuenta:\n");
    scanf("%5s",cuenta);
    printf("Contrase�a:\n");
    scanf("%8s",contra);
    for(i=0;i<n;i++)
    {
        if(strcmp(usuarios[i].cuenta,cuenta)==0)
        {
            existe=1;                                                   //Si existe es igual a 1 implica que existe un usuario con dicho nombre
            if(strcmp(usuarios[i].contra,contra)==0)
            {
                if(strcmp(usuarios[i].administrador,"0")==0)
                {
                    menunormal;                                         //Se le redirigir� al men� de usuario normal
                }
                if(strcmp(usuarios[i].administrador,"1")==0)
                {
                    menuadministrador;                                  //Se le redirigir� al men� de administrador
                }
            }
            else
            {
                printf("La contrase�a es incorrecta\n");
                iniciosesion(usuarios,n);
            }
        }
        else                                                            //Si existe es igual a 0, implica que no existe ningun usuario con ese nombre
        {
            printf("No existe ningun usuario con ese perfil.\n");
        }
    }
}
