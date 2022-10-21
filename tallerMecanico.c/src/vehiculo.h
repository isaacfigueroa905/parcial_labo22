/*
 * vehiculo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Isaac
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_
#define TAMCHARS 30
typedef struct
{
	int idTipo;
	char descripcion[TAMCHARS];
	int isEmpty;

}eTipo;

typedef struct
{
	int idVehiculo;
	char descripcion [TAMCHARS];
	int modelo;
	char color[TAMCHARS];
	int isEmpty;
	eTipo tipoId;

}eVehiculo;



void VEI_hardcodeoTipo(eTipo listadoTipo[]);
void VEI_mostrarUnTipo(eTipo tipo);
int VEI_mostrarListaTipo(eTipo listaTipo[],int tam);
void VEI_inicializarArray(eVehiculo listado [], int tam );
int VEI_buscarIndiceLibre(eVehiculo listado[], int tam);
eVehiculo VEI_ingresarVehiculo(eTipo tipo[],int tamTipo);
int VEI_altaVehiculo(eVehiculo listaVehiculo[],int tam,eTipo tipo[],int tamTipo);
void VEI_mostrarUno(eVehiculo vehiculo,eTipo listaTipo[] ,int tamTipo);
int VEI_mostrarLista(eVehiculo listaVehiculo[] ,int tam,eTipo listaTipo[],int tamTipo);
int VEI_buscarPosicionPorId(eVehiculo listaVehiculo[],int tamVEI,int id);

eVehiculo VEI_buscarUnVehiculoPorId(eVehiculo listaVehiculo[],int tamVei,int id);

eTipo VEI_buscarUnTipoPorId(eTipo listaTipo[],int tamTipo,int id);
int VEI_eliminarVehiculo(eVehiculo listaVehiculo[],int tamVei,int id,eTipo listaTipo[],int tamTipo);












#endif /* VEHICULO_H_ */
