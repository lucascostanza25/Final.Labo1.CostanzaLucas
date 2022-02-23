#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

float utn_getFlotante(float* pResultadoFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int longitud, int reintentos);

int es_String(char* cadena, int longitud);

int get_String(char* pResultado, int longitud);

int myGets(char* pCadena, int longitud);

#endif /* UTN_H_ */
