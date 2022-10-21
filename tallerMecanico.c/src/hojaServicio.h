/*
 * hojaServicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Isaac
 */

#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_
#define LEN_CHARS 20

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;



typedef struct
{
    int idHoja;
    int vehiculoId;
    char descripcion[LEN_CHARS];
    float precioServicio;
    eFecha fecha;
    int isEmpty;
}eHojaServicio;




void HOJA_inicializarArray(eHojaServicio listado [], int tam );
int HOJA_buscarIndiceLibre(eHojaServicio listado[], int tam);
eHojaServicio HOJA_ingresarHojaServicio();
int HOJA_altaHojaServicio(eHojaServicio listaHojaServicio[],int tamHoja);
int HOJA_buscarPosicionPorId(eHojaServicio listaHojaServicio[],int tamHoja,int id);

eHojaServicio HOJA_buscarUnHojaServicioPorId(eHojaServicio listaHojaServicio[],int tamHoja,int id);

void HOJA_mostrarUno(eHojaServicio hojaServicio);

int HOJA_mostrarLista(eHojaServicio listaHojaServicio[],int tamHoja);










#endif /* HOJASERVICIO_H_ */
