/*
 * controller.c
 *
 *  Created on: 23 feb. 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "enduro.h"
#include "LinkedList.h"
#include "UTN.h"
#include "controller.h"

int controller_loadDataFromText(char* path, LinkedList* enduroList)
{
	int retorno=-1;
	FILE* pFileLectura=fopen(path, "r");

	if(path!=NULL && enduroList!=NULL)
	{
		if(pFileLectura!=NULL)
		{
			parser_dataFromText(pFileLectura, enduroList);
			retorno=0;
		}
		fclose(pFileLectura);
	}

	return retorno;
}

int controller_listarData(LinkedList* enduroList)
{
	int retorno=-1;
	sEnduro* auxEnduro;
	int i;

	if(enduroList!=NULL)
	{
		printf("%-5s | %-20s | %-10s | %-5s | %s\n", "ID", "NOMBRE", "CATEGORIA", "TIEMPO", "PROMEDIO (Segundos)");
		for(i=0; i<ll_len(enduroList); i++)
		{
			auxEnduro=ll_get(enduroList, i);
			enduro_listar(auxEnduro);
		}
		retorno=0;
	}

	return retorno;
}

int controller_saveDataAsText(char* path, LinkedList* enduroList)
{
	int retorno=-1;
	FILE* pFile=fopen(path, "w");
	sEnduro* enduroGuardado;
	int i;

	if(path!=NULL && enduroList!=NULL)
	{
		fprintf(pFile, "id_cuatri,nombre,categoria,tiempo,promedio\n");
		for(i=0; i<ll_len(enduroList); i++)
		{
			enduroGuardado=ll_get(enduroList, i);
			fprintf(pFile, "%d,%s,%s,%d,%.2f\n", enduroGuardado->idCuatri, enduroGuardado->nombreDueno, enduroGuardado->categoria,
					enduroGuardado->tiempo, enduroGuardado->promedio);
		}
		fclose(pFile);
		retorno=0;
	}

	return retorno;
}

int controller_filtarCategoria(LinkedList* enduroList, LinkedList* enduroListFiltrada)
{
	int retorno=-1;
	int i;
	int categoriaSeleccionada;

	if(enduroList!=NULL && enduroListFiltrada!=NULL)
	{
		utn_getNumero(&categoriaSeleccionada, "-- FILTRAR --\n"
					"\nSeleccione una categoria:\n"
					"1.MX1\n"
					"2.MX2\n"
					"3.SUPER_ATV\n"
					"\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 1, 3, 4);
		for(i=0; i<ll_len(enduroList); i++)
		{
			switch(categoriaSeleccionada)
			{
				case 1:
					enduroListFiltrada=ll_filter(enduroList, enduro_filtrarCategoriaMX1);
					controller_saveDataAsText("../enduroFiltrado.csv", enduroListFiltrada);
				break;

				case 2:
					enduroListFiltrada=ll_filter(enduroList, enduro_filtrarCategoriaMX2);
					controller_saveDataAsText("../enduroFiltrado.csv", enduroListFiltrada);
				break;

				case 3:
					enduroListFiltrada=ll_filter(enduroList, enduro_filtrarCategoriaSUPER_ATV);
					controller_saveDataAsText("../enduroFiltrado.csv", enduroListFiltrada);
				break;
			}
		}
		retorno=0;
	}

	return retorno;
}

int controller_ordenarPromedio(LinkedList* enduroList)
{
	int retorno=-1;

	if(enduroList!=NULL)
	{
		ll_sort(enduroList, enduro_ordenarPromedio, 0);
		retorno=0;
	}

	return retorno;
}

int controller_listarCategoriaMX1(LinkedList* enduroList, LinkedList* enduroListFiltrada)
{
	int retorno=-1;
	int i;

	if(enduroList!=NULL && enduroListFiltrada!=NULL)
	{
		for(i=0; i<ll_len(enduroList); i++)
		{
			enduroListFiltrada=ll_filter(enduroList, enduro_filtrarCategoriaMX1);
		}

		if(enduroListFiltrada!=NULL)
		{
			printf("\n -- Categoria MX1\n");
			controller_ordenarPromedio(enduroListFiltrada);
			controller_listarData(enduroListFiltrada);
			retorno=0;
		}
	}

	return retorno;
}

int controller_listarCategoriaMX2(LinkedList* enduroList, LinkedList* enduroListFiltrada)
{
	int retorno=-1;
	int i;

	if(enduroList!=NULL && enduroListFiltrada!=NULL)
	{
		for(i=0; i<ll_len(enduroList); i++)
		{
			enduroListFiltrada=ll_filter(enduroList, enduro_filtrarCategoriaMX2);
		}

		if(enduroListFiltrada!=NULL)
		{
			printf("\n -- Categoria MX2\n");
			controller_ordenarPromedio(enduroListFiltrada);
			controller_listarData(enduroListFiltrada);
			retorno=0;
		}
	}

	return retorno;
}

int controller_listarCategoriaSUPER_ATV(LinkedList* enduroList, LinkedList* enduroListFiltrada)
{
	int retorno=-1;
	int i;

	if(enduroList!=NULL && enduroListFiltrada!=NULL)
	{
		for(i=0; i<ll_len(enduroList); i++)
		{
			enduroListFiltrada=ll_filter(enduroList, enduro_filtrarCategoriaSUPER_ATV);
		}

		if(enduroListFiltrada!=NULL)
		{
			printf("\n -- Categoria SUPER_ATV\n");
			controller_ordenarPromedio(enduroListFiltrada);
			controller_listarData(enduroListFiltrada);
			retorno=0;
		}
	}

	return retorno;
}

