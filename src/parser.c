/*
 * parser.c
 *
 *  Created on: 23 feb. 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "enduro.h"
#include "LinkedList.h"
#include "UTN.h"
#include "parser.h"

int parser_dataFromText(FILE* pFile, LinkedList* enduroList)
{
	int retorno=-1;
	char bufferDatos[5][1028];
	int cantidadDatos;
	sEnduro* auxEnduro;

	if(pFile!=NULL && enduroList!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
		while(!feof(pFile))
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
			if(cantidadDatos==5)
			{
				auxEnduro=new_EnduroParametros(bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
				if(auxEnduro!=NULL)
				{
					ll_add(enduroList, auxEnduro);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}
