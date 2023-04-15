#include<stdio.h>
#include<Register.h>

int main()
{
    int a,b;
    return 0;
}
void opciones(int a,int b) //El usuario elijirá si iniciar sesión (pulsando el número 1) o registrarse (pulsando el 2).
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
