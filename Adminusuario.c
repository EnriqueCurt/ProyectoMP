#include<stdio.h>
#include"registro.h"

void alta()
{
    //Copiar y pegar el m�dulo de registro pero cambi�ndole algunas cosas (enunciados sobre todo) para que se adapte mejor a esta funci�n.
    //Tambi�n hay que dar la opci�n de poder dar de alta a alguien que est� dado de baja
}

void baja()
{
    printf("Introduzca el nombre del usuario al que quiera dar de baja\n");
    scanf("%5s",cuenta);
    //Har� un bucle el cual compruebe en la base de datos si existe alg�n usuario con dicho nombre.
    //Si se da el caso, se le preguntar� al admin si est� seguro de que quiere dar de baja a dicho usuario.
    //Para dar de baja, se le cambiar� al usuario el n�mero registrado en su apartado "administrador"(lo de que si es usuario normal o administrador) por un 2.
}

void modificar()
{
    printf("Introduzca el nombre del usuario el cual quiera modificar\n");
    scanf("%5s",cuenta);
    //Har� un bucle el cual compruebe en la base de datos si existe alg�n usuario con dicho nombre.
    //Si se da el caso, se le preguntar� al admin si est� seguro de que quiere modificar a dicho usuario, permiti�ndole despu�s poder modificar cualquier aspecto de la cuenta.

}
void listar()
{

}
