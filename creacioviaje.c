//esto lo ha realizado jose luis ramirez tocino
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // libreria de control del tiempo pagina donde he sacado la documentacion https://www.techiedelight.com/es/print-current-date-and-time-in-c/
#include "struct_ficheros.h"
void creacioviaje(viaje** viajes,int* num_viajes,vehiculo** vehiculos){

int hora;
int minuto;
int dia;
int mes;
int ano;
int idviaje;
char buffer[30];
time_t now;

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
strcat((*viajes)[idviaje].matricula,(*vehiculos)[0].matricula);

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
            while((*viajes)[idviaje].fecha.mes<mes){ // controlador mes
            printf("mes no posible\n");
            fflush(stdin);
            scanf("%i",&(*viajes)[idviaje].fecha.mes);
            }
        }

        if((*viajes)[idviaje].fecha.ano==ano && (*viajes)[idviaje].fecha.mes==mes ){
            while((*viajes)[idviaje].fecha.dia<dia){ // controlador dia
            printf("dia no posible\n");
            fflush(stdin);
            scanf("%i",&(*viajes)[idviaje].fecha.dia);
            }
	   }

printf("introduzca hora de salida\n"); //pide la hora de salida !! hay que controlar que la hora no haya pasado
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horasalida.horas);
	   while((*viajes)[idviaje].horasalida.horas>hora){ // controlador hora salida
	   printf("hora no posible");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horasalida.horas);
	   }

printf("introduzca minuto de salida\n");
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horasalida.minutos);
    if((*viajes)[idviaje].horasalida.horas!=hora){
            while((*viajes)[idviaje].horasalida.minutos>minuto){ //controlador minuto salida
            printf("minuto no posible\n");
            fflush(stdin);
            scanf("%i",&(*viajes)[idviaje].horasalida.minutos);
            }
    }

printf("introduzca hora de llegada\n"); // pide la hora de llegada !! hay que controlar que sea mayor que la de salida
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horallegada.horas);
	   while((*viajes)[idviaje].horallegada.horas!=(*viajes)[idviaje].horasalida.horas){ // controlador hora salida
	   printf("hora no posible\n");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horallegada.horas);
	   }

printf("introduzca minuto de llegada\n");
fflush(stdin);
scanf("%i",&(*viajes)[idviaje].horallegada.minutos);
	   while((*viajes)[idviaje].horallegada.minutos==(*viajes)[idviaje].horasalida.minutos){ // controlador hora salida
	   printf("minuto no posible\n");
	   fflush(stdin);
	   scanf("%i",&(*viajes)[idviaje].horallegada.minutos);
	   }


printf("introduce precio total del viaje\n"); // pide el precio total del viaje
fflush(stdin);
scanf("%f",&(*viajes)[idviaje].precio);

   printf("\nSe cargaron %d viajes desde el archivo\n", *num_viajes+1);
    for (int j = 0; j < *num_viajes+1; j++) {
        printf("Id viaje=%s, Matricula=%s,fecha=%02d/%02d/%d , hora salida=%02d:%02d, hora llegada=%02d:%02d, ida o vuelta=%d, plazas=%d, precio=%.2f$, estado=%s \n",
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
    }
    *num_viajes=*num_viajes+1;
}
