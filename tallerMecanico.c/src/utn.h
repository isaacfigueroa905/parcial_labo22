/*
 * utn.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Isaac
 */

#ifndef UTN_H_
#define UTN_H_


//--utn
int getCadenaLetras(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado);
int getString(char* pResultado, int longitud);
int esString(char* cadena, int longitud);
/// @brief getNumero:pide el ingreso de un numero entero.
///
/// @param int*:puntero que contiene el numero ingresado.
/// @param char*:mensaje que pide al usuario el ingreso a relizar.
/// @param char*:mensaje de error.
/// @param int:n°minimo que se puede ingresar.
/// @param int:n°maximo que se puede ingresar.
/// @param int:establece la cantidad de reintentos.
/// @return int:0 si sale todo bien; -1 si sale mal.
int getNumero(int*,char*,char*,int,int,int);

/// @brief getInt:pide un texto al usuario,lo almacena como cadena,valida y convierte al texto como entero.
///
/// @param int*:texto validado como numerico y convertido a numero entero.
/// @return retorna 0 si se pudo validar;-1 si no se pudo.
int getInt(int*);

/// @brief myGets:lee stdin hasta que encuentre un salto de linea o hasta haber copiado en cadena un maximo de longitud -1 de caracteres.
///
/// @param char*: puntero al espacio de memoria donde se copiara la cadena obtenida.
/// @param int:establece el largo de la cadena.
/// @return retorna 0 si se obtine la cadena; -1 si no.
int myGets(char*,int);

/// @brief getInt:pide un texto al usuario,lo almacena como cadena,valida y convierte al texto como flotante.
///
/// @param float*:texto validado como numerico y convertido a numero flotante
/// @return retorna 0 si se pudo validar;-1 si no se pudo.
int getFloat(float*);

/// @brief esNumerica:verifica que una cadena sea numerica.
///
/// @param char*:cadena ingresada.
/// @param int: establece el limite maximo de la cadena a verificar.
/// @return
int esNumerica(char*,int);

/// @brief
///
/// @param getNumeroFlotante:pide el ingreso de un numero flotante.
/// @param float*:puntero que contiene el numero ingresado.
/// @param char*:mensaje que pide al usuario el ingreso a relizar.
/// @param char*:mensaje de error.
/// @param float:n°minimo que se puede ingresar.
/// @param float:n°maximo que se puede ingresar.
/// @param int:establece la cantidad de reintentos.
/// @return int:0 si sale todo bien; -1 si sale mal.
int getNumeroFlotante(float*,char*,char*,float,float,int);
//--


#endif /* UTN_H_ */
