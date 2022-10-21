/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "vehiculo.h"
#include "hojaServicio.h"
#include "utn.h"
#define TAM 100
#define TAM_SER 100
#define TAM_TIPO 3

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	int evaluar;
	eVehiculo listado[TAM];
	//eHojaServicio listaServicio[TAM_SER];
	eTipo listadoTipo[TAM_TIPO];
	int id;

VEI_hardcodeoTipo(listadoTipo);
	do
	    {

	         getNumero(&opcion,"\n\t\tMENU PRINCIPAL\n\t______________________________________\n\tElija una opcion:\n\t1.ALTA VEHICULO \n\t2.MODIFICAR VEHICULO\n\t3.BAJA VIAJE \n\t4.LISTAR  VEHICULO\n\t5.LISTAR TIPOS\n\t6.ALTA VAUCHER\n\t7.LISTAR HOJAS DE SERVICIO\n\t8.INFORMES\n\t0.SALIR\n\n",
	         	        "error, elija una opcion correcta!!!",0,8,10);

	        switch(opcion)
	        {
	            case 1:
	                printf("ALTA VEHICULO...\n");
	                evaluar=VEI_altaVehiculo(listado,TAM,listadoTipo,TAM_TIPO);
	                if(evaluar!=-1)
	                {
	                    printf("vehiculo cargado con exito::\n");
	                }
	                else
	                {
	                    printf("ocurrio un error..\n");
	                }
	            break;
	            case 2:
	                printf("MODIFICAR VEHICULO...\n");

	            break;
	            case 3:
	                printf("BAJA VEHICULO...\n");
	                evaluar=VEI_eliminarVehiculo(listado,TAM,id,listadoTipo,TAM_TIPO);

	                if(evaluar==1)
	                {
	                   printf("\nviaje eliminado...\n");
	                }
	                if(evaluar==2)
	                {
	                   printf("\ncancelado!!!\n");

	                }
	                else
	                {
	                   printf("\nno existe el id ingresado \n");
	                }
	            break;
	            case 4:
	                printf("LISTAR VEHICULO\n");

	            break;
	            case 5:
	                printf("LISTAR TIPOS\n");

	                VEI_mostrarListaTipo(listadoTipo,TAM_TIPO);
	            break;
	            case 6:
	                printf("ALTA HOJAS SERVICIOS\n");


	            break;
	            case 7:
	                printf("LITAR HOJAS DE SERVICIOS\n");

	            break;
	            case 8:
	                printf("INFORMES\n");

	            break;
	            case 9:
	                printf("SALIR.. \n");

	            break;


	        }

	    }while(opcion!=0);



	return EXIT_SUCCESS;
}
