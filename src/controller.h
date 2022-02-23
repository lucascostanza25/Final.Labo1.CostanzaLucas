/*
 * controller.h
 *
 *  Created on: 23 feb. 2022
 *      Author: Lucas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_loadDataFromText(char* path, LinkedList* enduroList);

int controller_listarData(LinkedList* enduroList);

int controller_filtarCategoria(LinkedList* enduroList, LinkedList* enduroListFiltrada);

int controller_saveDataAsText(char* path, LinkedList* enduroList);

int controller_listarCategoriaMX1(LinkedList* enduroList, LinkedList* enduroListFiltrada);

int controller_listarCategoriaMX2(LinkedList* enduroList, LinkedList* enduroListFiltrada);

int controller_listarCategoriaSUPER_ATV(LinkedList* enduroList, LinkedList* enduroListFiltrada);

int controller_ordenarPromedio(LinkedList* enduroList);

#endif /* CONTROLLER_H_ */
