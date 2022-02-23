/*
 * enduro.c
 *
 *  Created on: 23 feb. 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "UTN.h"
#include "enduro.h"

sEnduro* new_Enduro()
{
	sEnduro* this=NULL;
	this=(sEnduro*)malloc(sizeof(sEnduro));

	return this;
}

sEnduro* new_EnduroParametros(char* idCuatri, char* nombreDueno, char* categoria, char* tiempo, char* promedio)
{
	sEnduro* auxEnduro=new_Enduro();

	if(idCuatri!=NULL && nombreDueno!=NULL && categoria!=NULL && tiempo!=NULL && promedio!=NULL)
	{
		auxEnduro->idCuatri=atoi(idCuatri);
		strcpy(auxEnduro->nombreDueno, nombreDueno);
		strcpy(auxEnduro->categoria, categoria);
		auxEnduro->tiempo=atoi(tiempo);
		auxEnduro->promedio=atof(promedio);
	}

	return auxEnduro;
}

int enduro_setId(sEnduro* this, int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->idCuatri=id;
		retorno=0;
	}

	return retorno;
}

int enduro_getId(sEnduro* this, int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->idCuatri;
		retorno=0;
	}

	return retorno;
}

int enduro_setNombre(sEnduro* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->nombreDueno, nombre);
		retorno=0;
	}

	return retorno;
}

int enduro_getNombre(sEnduro* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(nombre, this->nombreDueno);
		retorno=0;
	}

	return retorno;
}

int enduro_setCategoria(sEnduro* this, char* categoria)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->categoria, categoria);
		retorno=0;
	}

	return retorno;
}

int enduro_getCategoria(sEnduro* this, char* categoria)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(categoria, this->categoria);
		retorno=0;
	}

	return retorno;
}

int enduro_setTiempo(sEnduro* this, int tiempo)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->tiempo=tiempo;
		retorno=0;
	}

	return retorno;
}

int enduro_getTiempo(sEnduro* this, int* tiempo)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*tiempo=this->tiempo;
		retorno=0;
	}

	return retorno;
}

int enduro_setPromedio(sEnduro* this, float promedio)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->promedio=promedio;
		retorno=0;
	}

	return retorno;
}

int enduro_getPromedio(sEnduro* this, float* promedio)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*promedio=this->promedio;
		retorno=0;
	}

	return retorno;
}

void enduro_listar(sEnduro* this)
{
	int auxId;
	char auxNombre[100];
	char auxCategoria[50];
	int auxTiempo;
	float auxPromedio;

	if(this!=NULL)
	{
		enduro_getId(this, &auxId);
		enduro_getNombre(this, auxNombre);
		enduro_getCategoria(this, auxCategoria);
		enduro_getTiempo(this, &auxTiempo);
		enduro_getPromedio(this, &auxPromedio);

		printf("%-8d%-23s%-13s%-8d%.2f\n", auxId, auxNombre, auxCategoria, auxTiempo, auxPromedio);
	}
}

int enduro_calcularPromedio(void* enduro)
{
	int retorno;
	int auxTiempo;

	if(enduro!=NULL)
	{
		enduro_getTiempo(enduro, &auxTiempo);
		if(auxTiempo<15)
		{
			enduro_setPromedio(enduro, 6);
		}
		if(auxTiempo>15 && auxTiempo<=20)
		{
			enduro_setPromedio(enduro, 8);
		}
		if(auxTiempo>20)
		{
			enduro_setPromedio(enduro, 10);
		}
		retorno=0;
	}

	return retorno;
}

int enduro_filtrarCategoriaMX1(void* enduro)
{
	int retorno=-1;
	char auxCategoria[50];

	if(enduro!=NULL)
	{
		enduro_getCategoria(enduro, auxCategoria);
		if(strcmp(auxCategoria, "MX1")==0)
		{
			retorno=0;
		}
	}

	return retorno;
}

int enduro_filtrarCategoriaMX2(void* enduro)
{
	int retorno=-1;
	char auxCategoria[50];

	if(enduro!=NULL)
	{
		enduro_getCategoria(enduro, auxCategoria);
		if(strcmp(auxCategoria, "MX2")==0)
		{
			retorno=0;
		}
	}

	return retorno;
}

int enduro_filtrarCategoriaSUPER_ATV(void* enduro)
{
	int retorno=-1;
	char auxCategoria[50];

	if(enduro!=NULL)
	{
		enduro_getCategoria(enduro, auxCategoria);
		if(strcmp(auxCategoria, "SUPER_ATV")==0)
		{
			retorno=0;
		}
	}

	return retorno;
}

int enduro_ordenarPromedio(void* promedioUno, void* promedioDos)
{
	float auxPromedioUno;
	float auxPromedioDos;
	int retorno=-1;

	if(promedioUno!=NULL && promedioDos!=NULL)
	{
		enduro_getPromedio(promedioUno, &auxPromedioUno);
		enduro_getPromedio(promedioDos, &auxPromedioDos);

		if(auxPromedioUno>auxPromedioDos)
		{
			retorno=0;
		}
	}

	return retorno;
}
