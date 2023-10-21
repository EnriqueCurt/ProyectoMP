#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_ficheros.h"

void u_modificar_viaje(viaje** viajes,int* num_viajes,int i,vehiculo** vehiculos,int* num_vehiculos)
{
    int opcion;
    int opcion2;
    int idviaje=0;
    int c;          //Auxiliar para el menu
    int j;          //Auxiliar para enumerar coches
    int coincide=0;   //Auxiliar para saber si existe el coche en el veector
    int x;    //Auxiliar para saber la posicion del coche en el vector
    int d=0;   //Auxiliar para saber cantidad de coches que tienes
    char buffer[30];
    char aux_matricula[8];

    sprintf(buffer, "%04d",i+1);
    for (j = 0; j < *num_vehiculos; j++)
    {
        if(strncmp((*vehiculos)[j].idusuario,buffer,5)==0)
        {
            printf("Matricula=%s, plazas=%d , descripcion=%s \n\n",
                   (*vehiculos)[j].matricula,
                   (*vehiculos)[j].plazas,
                   (*vehiculos)[j].descript);
            d++;

        }
    }
    printf("\nUsted tiene %d coche/s registrado/s\n\n",d);
    if(d==0)
    {
        printf("No puede modificar ya que usted no tiene ningun coche registrado\n\n");
        system("pause");
        system("cls");
        return;
    }
    do
    {
        printf("Introduzca matricula del coche que desees su viaje modificar(Debe de ser de 7 caracteres)\n\n");
        fflush(stdin);
        scanf("%s",aux_matricula);
        if(strlen(aux_matricula)!= 7)
        {
            printf("\nTamano incorrecto\n\n");
        }
        if(strlen(aux_matricula) == 7)
        {
            for (x = 0; (x < *num_viajes) || (coincide==0); x++)
            {
                if (strncmp((*viajes)[x].matricula, aux_matricula,7) == 0)
                {
                    printf("\nId viaje=%s, Matricula=%s,fecha=%02d/%02d/%d , hora salida=%02d:%02d, hora llegada=%02d:%02d, ida o vuelta=%d, plazas=%d, precio=%.2f$, estado=%s \n\n",
                           (*viajes)[j].idviaje,
                           (*viajes)[j].matricula,
                           (*viajes)[j].fecha.dia,
                           (*viajes)[j].fecha.mes,
                           (*viajes)[j].fecha.ano,
                           (*viajes)[j].horasalida.horas,
                           (*viajes)[j].horasalida.minutos,
                           (*viajes)[j].horallegada.horas,
                           (*viajes)[j].horallegada.minutos,
                           (*viajes)[j].idavuelta,
                           (*viajes)[j].plazas,
                           (*viajes)[j].precio,
                           (*viajes)[j].estado);
                    coincide = 1;
                }
            }
        }
    }
    while(strlen(aux_matricula)!= 7 || coincide==0);

    printf("Introduce el id del viaje que desees modificar\n");
    scanf("%d",&idviaje);
    idviaje=idviaje-1;

    printf("Desea cambiar el estado del viaje?\n\nPulse 1 para si, 2 para no\n");
    scanf("%d",&opcion);
    if(opcion==1)
    {
        printf("elija una se las siguientes opciones:\n1:Abierto \n2:Cerrado \n3:Iniciado \n4:Finalizado \n5:Anulado\n\n");
        scanf("%i",&opcion2);
        switch (opcion2)
        {
        case 1 :
            memset((*viajes)[idviaje].estado, 0, sizeof((*viajes)[idviaje].estado));
            strcat((*viajes)[idviaje].estado,"Abierto");
            puts("El estado del viaje ahora es Abierto\n");
            break;

        case 2 :
            memset((*viajes)[idviaje].estado, 0, sizeof((*viajes)[idviaje].estado));
            strcat((*viajes)[idviaje].estado,"Cerrado");
            puts("El estado del viaje ahora es Cerrado\n");
            break;

        case 3 :
            memset((*viajes)[idviaje].estado, 0, sizeof((*viajes)[idviaje].estado));
            strcat((*viajes)[idviaje].estado,"Iniciado");
            puts("El estado del viaje ahora es Iniciado\n");
            break;

        case 4 :
            memset((*viajes)[idviaje].estado, 0, sizeof((*viajes)[idviaje].estado));
            strcat((*viajes)[idviaje].estado,"Finalizado");
            puts("El estado del viaje ahora es Finalizado\n");
            break;


        case 5 :
            memset((*viajes)[idviaje].estado, 0, sizeof((*viajes)[idviaje].estado));
            strcat((*viajes)[idviaje].estado,"Anulado");
            puts("El estado del viaje ahora es Anulado\n");
            break;

        default :
            puts("Has escrito un estado que no esta en la lista asegurese de que esta bien escrito\n\n");
            break;
        }
    }
    system("pause");
}
void u_modificar_usuario(usuario** usuarios,int i)
{
    int c;
modificador:
    printf("¿Que desea modificar?\n1.Nombre\n2.Localidad\n3.Nombre de cuenta\n4.Contrasena\n");
    fflush(stdin);
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        printf("Introduzca su nombre:\n");
        fflush(stdin);
        scanf("%20s",(*usuarios)[i].nombre);
        printf("Guardado con exito.\n");
        break;
    case 2:
        printf("Introduzca su localidad:\n");
        fflush(stdin);
        scanf("%20s",(*usuarios)[i].localidad);
        printf("Guardado con exito.\n");
        break;
    case 3:
        printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
        fflush(stdin);
        scanf("%5s",(*usuarios)[i].cuenta);
        for(i=0; i<=5; i++)
        {
            if((*usuarios)[i].cuenta[i]=='-')
            {
                printf("No se pueden introducir guiones.\n");
                printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
                fflush(stdin);
                scanf("%5s",(*usuarios)[i].cuenta);

            }
        }
        printf("Guardado con exito.\n");
        break;
    case 4:
        printf("Introduzca su contraseña(maximo de 8 caracteres, sin guiones):\n");
        fflush(stdin);
        scanf("%8s",(*usuarios)[i].contra);
        for(i=0; i<=9; i++)
        {
            if((*usuarios)[i].cuenta[i]=='-')
            {
                printf("No se pueden introducir guiones.\n");
                printf("Introduzca su nombre de cuenta (maximo de 5 caracteres, sin guiones):\n");
                fflush(stdin);
                scanf("%5s",(*usuarios)[i].contra);
            }
        }
        printf("Guardado con exito.\n");
        break;
    default:
        goto modificador;
        break;
    }
Opcion:
    {
        printf("Desea modificar algo mas?\n1.Si\n2.No\n");
        fflush(stdin);
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            goto modificador;
            break;
        case 2:
            break;
        default:
            goto Opcion;
            break;
        }
    }
}
void u_crear_vehiculo(vehiculo** vehiculos,int i,int* num_vehiculos)
{
    char buffer[30];

    sprintf(buffer, "%04d",i+1);
    *vehiculos = (vehiculo *)realloc(*vehiculos,(*num_vehiculos+1) * sizeof(vehiculo ));
    sprintf(buffer, "%04d",i+1);
    memset((*vehiculos)[*num_vehiculos].idusuario, 0, sizeof((*vehiculos)[*num_vehiculos].idusuario));
    strncat((*vehiculos)[*num_vehiculos].idusuario,buffer,5);

    do
    {
        printf("Introduzca matricula(Debe de ser de 7 caracteres)\n");
        fflush(stdin);
        scanf("%7s",(*vehiculos)[*num_vehiculos].matricula);
        if(strlen((*vehiculos)[*num_vehiculos].matricula)!= 7)
        {
            printf("Tamaño incorrecto\n");
        }
    }
    while(strlen((*vehiculos)[*num_vehiculos].matricula)!= 7);

    printf("Introduzca numero de plazas\n");
    fflush(stdin);
    scanf("%d",&(*vehiculos)[*num_vehiculos].plazas);
    printf("Introduzca una breve descripcion(maximo 50 caracteres)\n");
    fflush(stdin);
    scanf("%50s",(*vehiculos)[*num_vehiculos].descript);

    *num_vehiculos=*num_vehiculos+1;
}
void u_modificar_vehiculo(vehiculo** vehiculos,int i,int *num_vehiculos)
{
    int c;          //Auxiliar para el menu
    int j;          //Auxiliar para enumerar coches
    int coincide=0;   //Auxiliar para saber si existe el coche en el veector
    int x;    //Auxiliar para saber la posicion del coche en el vector
    int d=0;   //Auxiliar para saber cantidad de coches que tienes
    char buffer[30];
    char aux_matricula[8];

    sprintf(buffer, "%04d",i+1);
    for (j = 0; j < *num_vehiculos; j++)
    {
        if(strncmp((*vehiculos)[j].idusuario,buffer,5)==0)
        {
            printf("Matricula=%s, plazas=%d , descripcion=%s \n",
                   (*vehiculos)[j].matricula,
                   (*vehiculos)[j].plazas,
                   (*vehiculos)[j].descript);
            d++;

        }
    }
    printf("\nUsted tiene %d coche/s registrado/s\n\n",d);
    if(d==0)
    {
        printf("No puede modificar ya que usted no tiene ningun coche registrado\n\n");
        system("pause");
        system("cls");
        return;
    }
    do
    {
        printf("Introduzca matricula del coche que desees modificar(Debe de ser de 7 caracteres)\n");
        fflush(stdin);
        scanf("%s",aux_matricula);
        if(strlen(aux_matricula)!= 7)
        {
            printf("\nTamano incorrecto\n\n");
        }
        if(strlen(aux_matricula) == 7)
        {
            for (x = 0; (x < *num_vehiculos) && (coincide==0); x++)
            {
                if (strncmp((*vehiculos)[x].matricula, aux_matricula,7) == 0)
                {
                    coincide = 1;
                    printf("\nVehiculo selecionado corretamente\n\n");
                    x--;
                }
            }
        }
        if(x == *num_vehiculos)
        {
            printf("\nMatricula incorrecta\n\n");
        }
    }
    while(strlen(aux_matricula)!= 7 || coincide==0);
modificador:
    printf("Que desea modificar?\n1.Matricula\n2.Plazas\n3.Descripcion\n");
    fflush(stdin);
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        do
        {
            printf("Introduzca matricula(Debe de ser de 7 caracteres)\n");
            fflush(stdin);
            scanf("%7s",(*vehiculos)[x].matricula);
            if(strlen((*vehiculos)[x].matricula)!= 7)
            {
                printf("Tamaño incorrecto\n");
            }
        }
        while(strlen((*vehiculos)[x].matricula)!= 7);
        break;
    case 2:
        printf("Introduzca numero de plazas:\n");
        fflush(stdin);
        scanf("%d",&(*vehiculos)[x].plazas);
        printf("%d\n",(*vehiculos)[x].plazas);
        printf("Guardado con exito.\n");
        break;
    case 3:
        printf("Introduzca una breve descripcion(maximo 50 caracteres)\n");
        fflush(stdin);
        scanf("%50s",(*vehiculos)[x].descript);
        printf("Guardado con exito.\n");
        break;
    default:
        goto modificador;
        break;
    }
Opcion:
    {
        printf("Desea modificar algo mas?\n1.Si\n2.No\n");
        fflush(stdin);
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            goto modificador;
            break;
        case 2:
            break;
        default:
            goto Opcion;
            break;
        }
    }
}
void u_borrar_vehiculo(vehiculo** vehiculos,int i, int* num_vehiculos)
{
    int c;          //Auxiliar para el menu
    int j;          //Auxiliar para enumerar coches
    int coincide=0;   //Auxiliar para saber si existe el coche en el veector
    int x;    //Auxiliar para saber la posicion del coche en el vector
    int d=0;   //Auxiliar para saber cantidad de coches que tienes
    char buffer[30];
    char aux_matricula[8];

    sprintf(buffer, "%04d",i+1);
    for (j = 0; j < *num_vehiculos; j++)
    {
        if(strncmp((*vehiculos)[j].idusuario,buffer,5)==0)
        {
            printf("Matricula=%s, plazas=%d , descripcion=%s \n",
                   (*vehiculos)[j].matricula,
                   (*vehiculos)[j].plazas,
                   (*vehiculos)[j].descript);
            d++;

        }
    }
    printf("\nUsted tiene %d coche/s registrado/s\n\n",d);
    if(d==0)
    {
        printf("No puede modificar ya que usted no tiene ningun coche registrado\n\n");
        system("pause");
        system("cls");
        return;
    }
    do
    {
        printf("Introduzca matricula del coche que desees borrar(Debe de ser de 7 caracteres)\n");
        fflush(stdin);
        scanf("%s",aux_matricula);
        if(strlen(aux_matricula)!= 7)
        {
            printf("\nTamano incorrecto\n\n");
        }
        if(strlen(aux_matricula) == 7)
        {
            for (x = 0; (x < *num_vehiculos) && (coincide==0); x++)
            {
                if (strncmp((*vehiculos)[x].matricula, aux_matricula,7) == 0)
                {
                    coincide = 1;
                    printf("\nVehiculo selecionado corretamente\n\n");
                    x--;
                }
            }
        }
        if(x == *num_vehiculos)
        {
            printf("\nMatricula incorrecta\n\n");
        }
    }
    while(strlen(aux_matricula)!= 7 || coincide==0);

    while(x < (*num_vehiculos -1))
    {
        memset((*vehiculos)[x].idusuario, 0, sizeof((*vehiculos)[x].idusuario));
        strcat((*vehiculos)[x].idusuario,(*vehiculos)[x+1].idusuario);
        memset((*vehiculos)[x].matricula, 0, sizeof((*vehiculos)[x].matricula));
        strcat((*vehiculos)[x].matricula,(*vehiculos)[x+1].matricula);
        (*vehiculos)[x].plazas = (*vehiculos)[x+1].plazas;
        memset((*vehiculos)[x].descript, 0, sizeof((*vehiculos)[x].descript));
        strcat((*vehiculos)[x].descript,(*vehiculos)[x+1].descript);
        x++;
    }
    *num_vehiculos=*num_vehiculos-1;
    *vehiculos = (vehiculo *)realloc(*vehiculos,(*num_vehiculos) * sizeof(vehiculo ));
    printf("Borrado exitosamente\n");
    system("pause");
}
void admin_registro_baja(usuario** usuarios,int* num_usuarios)
{
    int opcion=0;
    int id=0;
    char buffer[30];
    do
    {
        printf("Pulse 1 para dar de alta, 2 para dar de baja\n");
        scanf("%d",&opcion);
    }
    while((opcion<1) && (opcion>2));
    if(opcion==1)
    {
        registro(usuarios,num_usuarios);
    }
    else
    {
        do
        {
            printf("Introduzca el id de el usuario a banear\n");
            scanf("%d",&id);
        }
        while(id>*num_usuarios && id<1);
        id=id-1;
        (*usuarios)[id].administrador=2;
        printf("\nUsuario %s baneado del sistema\n",(*usuarios)[id].cuenta);
    }
    system("pause");
}
void admin_modificar_usuarios(usuario** usuarios,int* num_usuarios)
{
    int i;
    do
    {
        printf("Introduzca el id de usuario a modificar\n");
        fflush(stdin);
        scanf("%d",&i);
    }
    while((i<1) && (i>*num_usuarios));
    i=i-1;
    u_modificar_usuario(usuarios,i);
    system("pause");
}
void admin_registro_baja_vehiculo(vehiculo** vehiculos, int* num_vehiculos,int* num_usuarios)
{
    int x=0;
    int i=0;
    do
    {
        printf("Pulse 1 para dar de alta,pulse 2 para dar de baja\n");
        fflush(stdin);
        scanf("%d",&x);
    }
    while((x<1) && (x>2));
    if(x==1)
    {
        do
        {
            printf("Introduzca el id del usuario\n");
            fflush(stdin);
            scanf("%d",&i);
        }
        while((i<1)&& (i>*num_usuarios));
        i=i-1;
        u_crear_vehiculo(vehiculos,i,num_vehiculos);
    }
    else
    {
        do
        {
            printf("Introduzca el id del usuario\n");
            fflush(stdin);
            scanf("%d",&i);
        }
        while((i<1)&& (i>*num_vehiculos));
        i=i-1;
        u_borrar_vehiculo(vehiculos,i,num_vehiculos);
    }
    system("pause");
}
void admin_modificar_vehiculo(vehiculo** vehiculos,int *num_vehiculos,int* num_usuarios)
{
    int i;
    do
    {
        printf("Introduzca el id de usuario a modificar su vehiculo\n");
        fflush(stdin);
        scanf("%d",&i);
    }
    while((i<1)&& (i>*num_usuarios));
    i=i-1;
    u_modificar_vehiculo(vehiculos,i,num_vehiculos);
    system("pause");
}
void admin_modificar_viaje(viaje** viajes,int* num_viajes,vehiculo** vehiculos,int* num_vehiculos,int *num_usuarios)
{
    int i;
    do
    {
        printf("Introduzca el id de usuario a modificar su viaje\n");
        fflush(stdin);
        scanf("%d",&i);
    }
    while((i<1)&& (i>*num_usuarios));
    i=i-1;
    u_modificar_viaje(viajes,num_viajes,i,vehiculos,num_vehiculos);
    system("pause");
}
void admin_borrar_viaje(viaje** viajes,int* num_viajes)
{
    int i;
    do
    {
        printf("Introduzca el id del viaje que desea borrar\n");
        fflush(stdin);
        scanf("%d",&i);
    }
    while((i<1) || (i>*num_viajes));
    i=i-1;
    memset((*viajes)[i].estado, 0, sizeof((*viajes)[i].estado));
    strcat((*viajes)[i].estado,"Finalizado");
    puts("El estado del viaje ahora es Finalizado\n");
    system("pause");
}
