#include<stdio.h>
#include"registro.h"

void alta()
{
    //Copiar y pegar el módulo de registro pero cambiándole algunas cosas (enunciados sobre todo) para que se adapte mejor a esta función.
    //También hay que dar la opción de poder dar de alta a alguien que esté dado de baja
}

void baja()
{
    printf("Introduzca el nombre del usuario al que quiera dar de baja\n");
    scanf("%5s",cuenta);
    //Haré un bucle el cual compruebe en la base de datos si existe algún usuario con dicho nombre.
    //Si se da el caso, se le preguntará al admin si está seguro de que quiere dar de baja a dicho usuario.
    //Para dar de baja, se le cambiará al usuario el número registrado en su apartado "administrador"(lo de que si es usuario normal o administrador) por un 2.
}

void modificar()
{
    printf("Introduzca el nombre del usuario el cual quiera modificar\n");
    scanf("%5s",cuenta);
    //Haré un bucle el cual compruebe en la base de datos si existe algún usuario con dicho nombre.
    //Si se da el caso, se le preguntará al admin si está seguro de que quiere modificar a dicho usuario, permitiéndole después poder modificar cualquier aspecto de la cuenta.

}
void listar()
{

}
