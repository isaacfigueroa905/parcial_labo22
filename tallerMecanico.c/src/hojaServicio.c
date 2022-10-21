/*
 * hojaServicio.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Isaac
 */

#include "utn.h"
#include "hojaServicio.h"
#include <stdio.h>
#define LEN_CHARS 20
#define OCUPADO 1
#define LIBRE 0



eFecha pedirYValidarFecha(void)
{
     eFecha aux;


     getNumero(&aux.dia,"\ningrese dia: ","\ndia invalido",1,31,50);
     getNumero( &aux.mes,"\ningrese mes: ","\nmes invalido",1,12,50);
     getNumero(&aux.anio,"\ningrese anio: ","\nanio invalido",2020,2030,50);

     while(aux.mes==2&&aux.dia>28)
     {

         printf("\nfecha invalida... por favor verifique\n");
         getNumero(&aux.dia,"\ningrese dia: ","\ndia invalido",1,31,50);
         getNumero( &aux.mes,"\ningrese mes: ","\nmes invalido",1,12,50);
         getNumero(&aux.anio,"\ningrese anio: ","\nanio invalido",2020,2030,50);


     }
    /* while(aux.dia>30&&aux.mes== 4||aux.mes==6||aux.mes==9||aux.mes==11)
     {
         printf("\nfecha invalida... por favor verifique\n");
         getNumero(&aux.dia,"\ningrese dia: ","\ndia invalido",1,31,50);
         getNumero( &aux.mes,"\ningrese mes: ","\nmes invalido",1,12,50);
         getNumero(&aux.anio,"\ningrese anio: ","\nanio invalido",2020,2030,50);

     }*/

     return aux;


}


void HOJA_inicializarArray(eHojaServicio listado [], int tam )
{
    int i;

    for(i=0;i<tam;i++)
    {
        listado[i].isEmpty=LIBRE;
    }

}


int HOJA_buscarIndiceLibre(eHojaServicio listado[], int tam)
{
    int i;
    int index= -1;

    for(i=0;i<tam;i++)
    {
        if(listado[i].isEmpty==LIBRE)
        {
            index=i;
            break;
        }

    }
    return index;
}

eHojaServicio HOJA_ingresarHojaServicio()
{
    eHojaServicio ingreso;
    eFecha fecha;

    getCadenaLetras("\ningrese descripcion del HojaServicio: \n","\nescriba una descripcion valida\n",10,LEN_CHARS,ingreso.descripcion);
    getNumeroFlotante(&ingreso.precioServicio,"\ningrese precio del servicio: ","\nprecio erroneo, verifique! ",1.0,99999.9,50);
    fecha=pedirYValidarFecha();
    ingreso.fecha=fecha;

    ingreso.isEmpty=OCUPADO;

    return ingreso;
}

int HOJA_altaHojaServicio(eHojaServicio listaHojaServicio[],int tamHoja)
{
	int retorno=-1;
	int posicionLibre;
	eHojaServicio hojaServicio;

	if(listaHojaServicio!=NULL&& tamHoja>0)
	{
		posicionLibre=HOJA_buscarIndiceLibre(listaHojaServicio,tamHoja);
		hojaServicio= HOJA_ingresarHojaServicio();

		if(posicionLibre!=-1)
		{
			listaHojaServicio[posicionLibre]=hojaServicio;
			listaHojaServicio[posicionLibre].idHoja=posicionLibre+20000;

			retorno=0;
		}
	}


	return retorno;
}



int HOJA_buscarPosicionPorId(eHojaServicio listaHojaServicio[],int tamHoja,int id)
{
   int index=-1;

   if(listaHojaServicio!=NULL&&tamHoja>0)
	{
		for(int i=0;i<tamHoja;i++)
		{
			if(listaHojaServicio[i].isEmpty==OCUPADO&&listaHojaServicio[i].idHoja==id)
			{

			   index=i;
				break;
			}
		}
	}
	return index;


}

eHojaServicio HOJA_buscarUnHojaServicioPorId(eHojaServicio listaHojaServicio[],int tamHoja,int id)
{
	eHojaServicio aux;

	if(listaHojaServicio!=NULL&&tamHoja>0)
	{
		for(int i=0;i<tamHoja;i++)
		{
			if(listaHojaServicio[i].isEmpty==OCUPADO&&listaHojaServicio[i].idHoja==id)
			{
				aux=listaHojaServicio[i];
				break;
			}
		}
	}



	return aux;
}

void HOJA_mostrarUno(eHojaServicio hojaServicio)
{


	printf("\n|%d|%-s|%-f|%d/%d/%d|\n", hojaServicio.idHoja, hojaServicio.descripcion, hojaServicio.precioServicio, hojaServicio.fecha.dia,hojaServicio.fecha.mes,hojaServicio.fecha.anio);
	printf("\n--------------------------------------------------\n");
}

int HOJA_mostrarLista(eHojaServicio listaHojaServicio[],int tamHoja)
{
	int retorno=-1;

	if(listaHojaServicio!=NULL&&tamHoja>0)
	{
		for(int i=0;i<tamHoja;i++)
		{
			if(listaHojaServicio[i].isEmpty==OCUPADO)
			{
				HOJA_mostrarUno(listaHojaServicio[i]);
				retorno=0;
			}

		}
	}
	return retorno;
}



