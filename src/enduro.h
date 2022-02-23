/*
 * enduro.h
 *
 *  Created on: 23 feb. 2022
 *      Author: Lucas
 */

#ifndef ENDURO_H_
#define ENDURO_H_

typedef struct
{
	int idCuatri;
	char nombreDueno[100];
	char categoria[50];
	int tiempo;
	float promedio;
}sEnduro;

sEnduro* new_Enduro();
sEnduro* new_EnduroParametros(char* idCuatri, char* nombreDueno, char* categoria, char* tiempo, char* promedio);
//Setters y getters
int enduro_setId(sEnduro* this, int id);
int enduro_getId(sEnduro* this, int* id);
int enduro_setNombre(sEnduro* this, char* nombre);
int enduro_getNombre(sEnduro* this, char* nombre);
int enduro_setCategoria(sEnduro* this, char* categoria);
int enduro_getCategoria(sEnduro* this, char* categoria);
int enduro_setTiempo(sEnduro* this, int tiempo);
int enduro_getTiempo(sEnduro* this, int* tiempo);
int enduro_setPromedio(sEnduro* this, float promedio);
int enduro_getPromedio(sEnduro* this, float* promedio);
// -------------------------------------------------------- //
void enduro_listar(sEnduro* this);
int enduro_calcularPromedio(void* enduro);
int enduro_filtrarCategoriaMX1(void* enduro);
int enduro_filtrarCategoriaMX2(void* enduro);
int enduro_filtrarCategoriaSUPER_ATV(void* enduro);
int enduro_ordenarPromedio(void* promedioUno, void* promedioDos);

#endif /* ENDURO_H_ */
