/*
 * utn.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Isaac
 */

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myGets(char* cadena,int longitud)
{
    int retorno=-1;
    char bufferString[256];//arreglar

    if(cadena!=NULL&&longitud>0)
    {
        fflush(stdin);
       if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)//el fgets no elimina el \n, lo toma como un caracter
       {
           if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')//si la posicion final menos 1 es \n
           {
               bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';//pisar con \0
           }
           //si no es \n cargarlo
           if(strnlen(bufferString,sizeof(bufferString))<=longitud)
           {
               strncpy(cadena,bufferString,longitud);
               retorno=0;

           }
       }
    }

    return retorno;
}



int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(pResultado!=NULL)
    {
        if(myGets(bufferString,sizeof(bufferString))==0&&esNumerica(bufferString,sizeof(bufferString)))
        {
            retorno=0;
            *pResultado=atof(bufferString);

        }
    }
    return retorno;
}

int esNumerica(char* cadena,int limite)
{
    int retorno=1;//verdadero

    for(int i=0;i<limite&&cadena[i] !='\0' ;i++)
    {
        if(i==0 && cadena[i]=='+'&&cadena[i]=='-')//acepta signos solo en la primera posicion &&--||
        {
            continue;
        }
        if(cadena[i]>'9' || cadena[i]<'0')
        {
            retorno=0;//falso
            break;
        }

    }

    return retorno;
}

int getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float min,float max,int reintentos)
{
    int retorno=-1;
    float bufferFloat;
    do
    {
        printf("%s",mensaje);
        if( getFloat(&bufferFloat)==0&&bufferFloat>=min&&bufferFloat<=max)
        {
            retorno=0;//exito
            *pResultado=bufferFloat;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }while(reintentos>=0);


    return retorno;
}

//--



int getNumero(int* pResultado,char* mensaje,char* mensajeError,int min,int max,int reintentos)
{
    int retorno=-1;
    int bufferInt;
    do
    {
        printf("%s",mensaje);
        if( getInt(&bufferInt)==0&&bufferInt>=min&&bufferInt<=max)
        {
            retorno=0;
            *pResultado=bufferInt;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }while(reintentos>=0);


    return retorno;
}


int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(pResultado!=NULL)
    {
        if(myGets(bufferString,sizeof(bufferString))==0&& esNumerica(bufferString,sizeof(bufferString)))
        {
            retorno=0;
            *pResultado=atoi(bufferString);

        }
    }
    return retorno;
}



int esString(char* cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != ' ')
			{
				if( (cadena[i] < 'A' || cadena[i] > 'Z') &&
					(cadena[i] < 'a' || cadena[i] > 'z') )
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

int getString(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

	if(pResultado != NULL)
	{
		if(	myGets(buffer,sizeof(buffer)) == 0 &&
			esString(buffer, sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud )
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}

    return retorno;
}

int getCadenaLetras(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	int i = 0;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getString(bufferString, sizeof(bufferString)) == 0 &&
		   strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			i++;
			bufferString[0] = toupper(bufferString[0]);
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}

		printf("%s",mensajeError);
	}

	return retorno;
}

