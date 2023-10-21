//esto lo ha realizado jose luis ramirez tocino
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h> // libreria de control del tiempo pagina donde he sacado la documentacion https://www.techiedelight.com/es/print-current-date-and-time-in-c/
#include "struct_ficheros.h"
void creacioviaje(viaje** viajes,int* num_viajes,vehiculo** vehiculos,int* num_vehiculos,paso** pasos,int* num_pasos){
int x=0;
int coincide=0;
int hora;
int minuto;
int dia;
int mes;
int ano;
int idviaje;
char buffer[30];
time_t now;
int a;
char aux_matricula[8];                             //Para los pasos

time(&now);
struct tm *local = localtime(&now);

hora = local->tm_hour;         // obtener horas desde la medianoche (0-23)
minuto = local->tm_min;        // obtener minutos pasados después de la hora (0-59)

dia = local->tm_mday;            // obtener el día del mes (1 a 31)
mes = local->tm_mon + 1;      // obtener el mes del año (0 a 11)
ano = local->tm_year + 1900;   // obtener el año desde 1900

*viajes = (viaje *)realloc(*viajes,(*num_viajes+1) * sizeof(viaje ));

idviaje=*num_viajes;
sprintf(buffer, "%06d",idviaje+1);
strcat((*viajes)[idviaje].idviaje,buffer); // establece el idviaje
do{
        printf("Introduzca matricula del coche que desees utilizar en el viaje(Debe de ser de 7 caracteres)\n");
        fflush(stdin);
        scanf("%s",aux_matricula);
        if(strlen(aux_matricula)!= 7){
            printf("\nTamano incorrecto\n\n");
            }
        if(strlen(aux_matricula) == 7){
            for (x = 0; (x < *num_vehiculos) && (coincide==0); x++) {
                if (strncmp((*vehiculos)[x].matricula, aux_matricula,7) == 0) {
                coincide = 1;
                printf("\nVehiculo selecionado corretamente\n\n");
                x--;
                    }
                }
            }
        if(x == *num_vehiculos){
            printf("\nMatricula incorrecta\n\n");
        }
        }while(strlen(aux_matricula)!= 7 || coincide==0);

strcat((*viajes)[idviaje].matricula,aux_matricula); // establece la matricula

(*viajes)[idviaje].plazas=(*vehiculos)[1].plazas; // establece el numero de plazas disponibles segun el vehiculo selecionado

printf("pulse 1 para ida, pulse 2 para vuelta\n"); // pide que el usuario indique si el viaje es de ida o vuelta
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].idavuelta);

strcat((*viajes)[idviaje].estado,"abierto"); // estabece por defecto el viaje como abierto
printf("introduzca ano\n"); //pide la fecha que el viaje !! hay que controlar que la fecha no sea del pasado!!
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].fecha.ano);

printf("introduzca mes\n");
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].fecha.mes);

printf("introduzca dia\n");
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].fecha.dia);

	   while((*viajes)[idviaje].fecha.ano<ano){ // controlador año
	   printf("ano no posible\n");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].fecha.ano);
	   }

	   if((*viajes)[idviaje].fecha.ano==ano){
            while((*viajes)[idviaje].fecha.mes<mes || (*viajes)[idviaje].fecha.mes>12 ){ // controlador mes
            printf("mes no posible\n");
            fflush(stdin);
            scanf("%i",&(*viajes)[idviaje].fecha.mes);
            }
        }

        if((*viajes)[idviaje].fecha.ano==ano && (*viajes)[idviaje].fecha.mes==mes ){
            while(((*viajes)[idviaje].fecha.dia<dia) ||
                   ((*viajes)[idviaje].fecha.mes==2 && (*viajes)[idviaje].fecha.dia>29 && (*viajes)[idviaje].fecha.ano % 4 == 0) ||
                   ((*viajes)[idviaje].fecha.mes==2 && (*viajes)[idviaje].fecha.dia>28 && (*viajes)[idviaje].fecha.ano % 4 != 0 )
                  || ((*viajes)[idviaje].fecha.dia>32) ){ // controlador dia
            printf("dia no posible\n");
            fflush(stdin);
            scanf("%i",&(*viajes)[idviaje].fecha.dia);
            }
	   }

printf("introduzca hora de salida\n"); //pide la hora de salida !! hay que controlar que la hora no haya pasado
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horasalida.horas);
while((*viajes)[idviaje].horasalida.horas>23){
       printf("hora no posible");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horasalida.horas);
}
    if((*viajes)[idviaje].fecha.ano==ano && (*viajes)[idviaje].fecha.mes==mes && (*viajes)[idviaje].fecha.dia==dia){
	   while((*viajes)[idviaje].horasalida.horas<hora ){ // controlador hora salida
	   printf("hora no posible");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horasalida.horas);
	   }
	}

printf("introduzca minuto de salida\n");
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horasalida.minutos);
while((*viajes)[idviaje].horasalida.minutos>60){
       printf("minuto no posible");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horasalida.minutos);
}
    if((*viajes)[idviaje].horasalida.horas==hora && (*viajes)[idviaje].fecha.ano==ano && (*viajes)[idviaje].fecha.mes==mes && (*viajes)[idviaje].fecha.dia==dia){
            while((*viajes)[idviaje].horasalida.minutos<=minuto){ //controlador minuto salida
            printf("minuto no posible\n");
            fflush(stdin);
            scanf("%i",&(*viajes)[idviaje].horasalida.minutos);
            }
    }

printf("introduzca hora de llegada\n"); // pide la hora de llegada !! hay que controlar que sea mayor que la de salida
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horallegada.horas);
       while((*viajes)[idviaje].horallegada.horas>23){
       printf("hora no posible");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horallegada.horas);
        }
	   while((*viajes)[idviaje].horallegada.horas<(*viajes)[idviaje].horasalida.horas){ // controlador hora llegada
	   printf("hora no posible\n");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horallegada.horas);
	   }

printf("introduzca minuto de llegada\n");
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horallegada.minutos);
       while((*viajes)[idviaje].horallegada.minutos>60){
       printf("minuto no posible");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horallegada.minutos);
        }
	   while((*viajes)[idviaje].horallegada.minutos<=(*viajes)[idviaje].horasalida.minutos && (*viajes)[idviaje].horallegada.horas<(*viajes)[idviaje].horasalida.horas){ // controlador minuto llegada
	   printf("minuto no posible\n");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horallegada.minutos);
	   }

printf("introduce precio del viaje\n"); // pide el precio del viaje
fflush(stdin);
scanf("%f",&(*viajes)[idviaje].precio);

*pasos = (paso *)realloc(*pasos,(*num_pasos+1) * sizeof(paso ));
memset((*pasos)[*num_pasos].idviaje, 0, sizeof((*pasos)[*num_pasos].idviaje));
strcpy((*pasos)[*num_pasos].idviaje,(*viajes)[idviaje].idviaje);
memset((*pasos)[*num_pasos].poblados, 0, sizeof((*pasos)[*num_pasos].poblados));
printf("Introduzca la poblacion por la que pasas:\n");
scanf("%20s",(*pasos)[*num_pasos].poblados);
*num_pasos=*num_pasos+1;

Pasos:
    {
        printf("¿Desea introducir mas poblaciones por las que va a pasar?\n1.Si\n2.No\n");              //Para los pasos
        fflush(stdin);
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            *pasos = (paso *)realloc(*pasos,(*num_pasos+1) * sizeof(paso ));
            memset((*pasos)[*num_pasos].idviaje, 0, sizeof((*pasos)[*num_pasos].idviaje));
            strcpy((*pasos)[*num_pasos].idviaje,(*viajes)[idviaje].idviaje);
            memset((*pasos)[*num_pasos].poblados, 0, sizeof((*pasos)[*num_pasos].poblados));
            printf("Introduzca la poblacion por la que pasas:\n");
            scanf("%20s",(*pasos)[*num_pasos].poblados);
            *num_pasos=*num_pasos+1;
            goto Pasos;
            break;
        case 2:
            break;
        default:
            goto Pasos;
        }
    }
    *num_viajes=*num_viajes+1;
}
void u_entrar_viaje(viaje** viajes,int* num_viajes,paso** pasos,int* num_pasos){
char aux_paso[20];
char aux_matricula[8];
int x=0; //auxiliar para buscar en el vector pasos
int j=0; //auxiliar para buscar en viajes
int b=0; //auxiliar para ecoger en el menu
int y=0;
int coincide=0;
do{
        printf("Introduce a que lugar deseas ir(20 caracteres maximo)\n");
        fflush(stdin);
        scanf("%s",aux_paso);
        if(strlen(aux_matricula) > 20){
            printf("\nTamano incorrecto\n\n");
            }

        if(strlen(aux_paso) <= 20){
            for (x = 0; (x < *num_pasos) || (coincide==0); x++) {
                if (strncmp((*pasos)[x].poblados, aux_paso,strlen(aux_paso)) == 0 ) {
                    for (j = 0; (j < *num_viajes) || (coincide==0); j++){
                        if(((strcmp((*viajes)[j].estado,"abierto")==0) || strcmp((*viajes)[j].estado,"iniciado")==0) && (strcmp((*pasos)[x].idviaje,(*viajes)[j].idviaje)==0)){
                            coincide = 1;
                            printf("Matricula=%s,fecha=%02d/%02d/%d , hora salida=%02d:%02d, hora llegada=%02d:%02d,plazas=%d, precio=%.2f$\n",
                                    (*viajes)[j].matricula,
                                    (*viajes)[j].fecha.dia,
                                    (*viajes)[j].fecha.mes,
                                    (*viajes)[j].fecha.ano,
                                    (*viajes)[j].horasalida.horas,
                                    (*viajes)[j].horasalida.minutos,
                                    (*viajes)[j].horallegada.horas,
                                    (*viajes)[j].horallegada.minutos,
                                    (*viajes)[j].plazas,
                                    (*viajes)[j].precio);
                                    coincide = 1;
                                    }
                        }
                    }
                }
            }
        if(coincide==0){
            printf("\nNo existen viajes que vayan a donde deseas\n\n");
            printf("Pulse 1 para volver a buscar, 2 para salir\n");
            scanf("%d",&b);
            if(b==2){
                return;
            }
            }
        }while(strlen(aux_paso )> 20 || coincide==0);
        coincide=0;
    do{
        printf("\nIntroduzca matricula del coche que desees ir en el viaje(Debe de ser de 7 caracteres)\n");
        fflush(stdin);
        scanf("%s",aux_matricula);
        if(strlen(aux_matricula)!= 7){
            printf("\nTamano incorrecto\n\n");
            }
        if(strlen(aux_matricula) == 7){
            for (y= 0; (y< *num_viajes) && (coincide==0); y++) {
                if (strncmp((*viajes)[y].matricula, aux_matricula,7) == 0) {
                coincide = 1;
                printf("\nVehiculo selecionado corretamente\n\n");
                y--;
                    }
                }
            }
        if(x == *num_viajes){
            printf("\nMatricula incorrecta\n\n");
            }
        }while(strlen(aux_matricula)!= 7 || coincide==0);
printf("\nViaje escogido correctamente, debe pagar %.2f $ al conductor\n\n",(*viajes)[y].precio);
(*viajes)[y].plazas=(*viajes)[y].plazas -1;

if((*viajes)[y].plazas==0){
    memset((*viajes)[y].estado, 0, sizeof((*viajes)[y].estado));
    strcat((*viajes)[y].estado,"cerrado");
    }
    system("pause");
}
