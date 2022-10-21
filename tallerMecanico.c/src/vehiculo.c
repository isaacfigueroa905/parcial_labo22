/*
 * vehiculo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Isaac
 */
#include "vehiculo.h"
#include <stdio.h>
#define OCUPADO 1
#define LIBRE 0
#define LEN_CHARS 15


void VEI_hardcodeoTipo(eTipo listadoTipo[])
{

    eTipo aux[3]= {{1,"SEDAN 3PTAS",OCUPADO},{2,"SEDAN 5PTAS",OCUPADO},{3,"CAMIONETA",OCUPADO}};

     for(int i=0;i<3;i++)
    {
        listadoTipo[i]=aux[i];
    }

}


void VEI_mostrarUnTipo(eTipo tipo)
{
	printf("\n%d-%s\n",tipo.idTipo,tipo.descripcion);
}


int VEI_mostrarListaTipo(eTipo listaTipo[],int tam)
{
	int retorno=-1;

	if(listaTipo!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(listaTipo[i].isEmpty==OCUPADO)
			{
				VEI_mostrarUnTipo(listaTipo[i]);
				retorno=0;
			}

		}
	}
	return retorno;
}


void VEI_inicializarArray(eVehiculo listado [], int tam )
{
    int i;

    for(i=0;i<tam;i++)
    {
        listado[i].isEmpty=LIBRE;
    }

}


int VEI_buscarIndiceLibre(eVehiculo listado[], int tam)
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
eVehiculo VEI_ingresarVehiculo(eTipo tipo[],int tamTipo)
{
    eVehiculo ingreso;

    getCadenaLetras("\ningrese descripcion vehiculo\n","\nescriba decripcion valida\n",10,LEN_CHARS,ingreso.descripcion);
    getNumero(&ingreso.modelo,"\ningrese modelo (anio fabricacion): ","\n modelo invalido! ",1980,2023,50);
    getCadenaLetras("\ningrese color vehiculo\n","\nescriba color valido\n",10,LEN_CHARS,ingreso.color);
    VEI_mostrarListaTipo(tipo,tamTipo);
    getNumero(&ingreso.tipoId.idTipo,"\ningrese tipo de vehiculo","\nopcion incorrecta! ",1,3,50);

    ingreso.isEmpty=OCUPADO;

    return ingreso;
}


int VEI_altaVehiculo(eVehiculo listaVehiculo[],int tam,eTipo tipo[],int tamTipo)
{
	int retorno=-1;
	int posicionLibre;
	eVehiculo vehiculo;

	if(listaVehiculo!=NULL&& tam>0)
	{
		posicionLibre=VEI_buscarIndiceLibre(listaVehiculo,tam);
		vehiculo= VEI_ingresarVehiculo(tipo,tamTipo);
		if(posicionLibre!=-1)
		{
			listaVehiculo[posicionLibre]=vehiculo;
			listaVehiculo[posicionLibre].idVehiculo=posicionLibre+1000;

			retorno=0;
		}
	}


	return retorno;
}


void VEI_mostrarUno(eVehiculo vehiculo,eTipo listaTipo[] ,int tamTipo)
{
   int id;
   eTipo aux;
   id=vehiculo.tipoId.idTipo;


   aux=VEI_buscarUnTipoPorId(listaTipo,tamTipo,id);

	printf("\n%d-%s-%d-%s-%s\n",vehiculo.idVehiculo,vehiculo.descripcion,vehiculo.modelo,vehiculo.color,aux.descripcion);
	printf("\n--------------------------------------------------\n");
}

int VEI_mostrarLista(eVehiculo listaVehiculo[] ,int tam,eTipo listaTipo[],int tamTipo)
{
	int retorno=-1;

	if(listaVehiculo!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(listaVehiculo[i].isEmpty==OCUPADO)
			{
				VEI_mostrarUno(listaVehiculo[i],listaTipo,tamTipo);
				retorno=0;
			}

		}
	}
	return retorno;
}

int VEI_buscarPosicionPorId(eVehiculo listaVehiculo[],int tamVEI,int id)
{
   int index=-1;

   if(listaVehiculo!=NULL&&tamVEI>0)
	{
		for(int i=0;i<tamVEI;i++)
		{
			if(listaVehiculo[i].isEmpty==OCUPADO&&listaVehiculo[i].idVehiculo==id)
			{

			   index=i;
				break;
			}
		}
	}
	return index;


}

eVehiculo VEI_buscarUnVehiculoPorId(eVehiculo listaVehiculo[],int tamVei,int id)
{
	eVehiculo aux;

	if(listaVehiculo!=NULL&&tamVei>0)
	{
		for(int i=0;i<tamVei;i++)
		{
			if(listaVehiculo[i].isEmpty==OCUPADO&&listaVehiculo[i].idVehiculo==id)
			{
				aux=listaVehiculo[i];
				break;
			}
		}
	}



	return aux;
}


eTipo VEI_buscarUnTipoPorId(eTipo listaTipo[],int tamTipo,int id)
{
	eTipo aux;

	if(listaTipo!=NULL&&tamTipo>0)
	{
		for(int i=0;i<tamTipo;i++)
		{
			if(listaTipo[i].isEmpty==OCUPADO&&listaTipo[i].idTipo==id)
			{
				aux=listaTipo[i];
				break;
			}
		}
	}



	return aux;
}


int VEI_modificarVehiculo(eVehiculo listaVehiculo[],int tamVei,int id,eTipo listaTipo[],int tamTipo)
{
   int index;
  // eVehiculo aux;
   int retorno=-1;
   int opcion;


   printf("\n::::::::::::::::MENU MODIFICACION::::::::::::::::\n");
   VEI_mostrarLista(listaVehiculo,tamVei,listaTipo,tamTipo);

   getNumero(&id,"\npor favor ingrese el id del Vehiculo que desea modificar :","\n error !!! ",1000,8000,50);
   index=VEI_buscarPosicionPorId(listaVehiculo,tamVei,id);
   if(index!=-1)
   {
      VEI_mostrarUno(listaVehiculo[index],listaTipo,tamTipo);
      getNumero(&opcion,"\n1.modificar descripcion\n2.modificar precio\n3.cancelar\nelija una opcion: ","\nopcion no valida reintente: ",1,3,50);
      switch(opcion)
      {
         case 1:
            getCadenaLetras("\ningrese nueva descripcion\n","\nescriba una descripcion valida\n",10,LEN_CHARS,listaVehiculo[index].descripcion);
            retorno=1;

         break;
         case 2:
           // getNumeroFloat(&listaVehiculo[index].precioServicio,"\ningrese nueva cantidad de pasajeros: ","\nerror ingrese una cantidad permitida ",1,TAM,50);
            retorno=2;
            printf("\n se modifico cantidad de pasajeros! ");
         break;
         case 3:

         break;

      }
   }
   else
   {

      printf("\vno se encontro Vehiculo!!!");
   }



   return retorno;

}



int VEI_eliminarVehiculo(eVehiculo listaVehiculo[],int tamVei,int id,eTipo listaTipo[],int tamTipo)
{
   int index;

   int retorno=-1;
   int opcion;


   printf("\n::::::::::::::::MENU ELIMINAR::::::::::::::::\n");
   VEI_mostrarLista(listaVehiculo,tamVei,listaTipo,tamTipo);

   getNumero(&id,"\npor favor ingrese el id del vehiculo que desea eliminar :","\n error !!! ",1000,8000,50);
   index=VIA_buscarPosicionPorId(listaVehiculo,tamVei,id);
   if(index!=-1)
   {
      VIA_mostrarUno(listaVehiculo[index],listaTipo,tamTipo);
      getNumero(&opcion,"\nEsta a punto de eliminar este vehiculo... desea continuar ?\n\t1.confirmar \n2.cancelar\nelija una opcion: ","\nopcion no valida reintente: ",1,3,50);
      switch(opcion)
      {
         case 1:
            listaVehiculo[index].isEmpty=LIBRE;//ELIMINAR
            retorno=1;

         break;
         case 2:
            retorno=2;
         break;

      }
   }
   else
   {

      printf("\vno se encontro vehiculo!!!");
   }



   return retorno;

}



















