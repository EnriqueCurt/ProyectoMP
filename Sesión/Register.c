//Este m�dulo se encargar� de registrar a los nuevos usuarios (Esto es simplemente un primer modelo muy susceptible a cambios. Este modelo usa datos los cuales todav�a pueden no haber sido creados)

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b;
    return 0;
}
void opciones(int a,int b) //El usuario elijir� si iniciar sesi�n (pulsando el n�mero 1) o registrarse (pulsando el 2).
{
    printf("1.Iniciar sesion\n2.Registrarse\n");
    do
    {
        scanf("%d",a);
    }while(a==!1||a==!2);
    if(a==1)
    {
        printf("Introduzca su usuario:\n");
        scanf("%c",&b);
        if(b==usuario.cuenta)
        {

        }
    }
    if(a==0)
    {

    }
}
