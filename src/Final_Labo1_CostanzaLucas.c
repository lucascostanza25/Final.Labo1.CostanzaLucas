/*
 ============================================================================
 Name        : Final_Labo1_CostanzaLucas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "parser.h"
#include "enduro.h"
#include "LinkedList.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* enduroList=ll_newLinkedList();
	LinkedList* enduroListFiltrada=ll_newLinkedList();
	int menu;
	int flagMenu=0;

	do
	{
		utn_getNumero(&menu, "-- FINAL LABO 1 --\n"
				"\n1.Cargar archivo enduro\n"
				"2.Imprimir lista\n"
				"3.Asignar promedio\n"
				"4.Filtrar por tipo\n"
				"5.Mostrar posiciones\n"
				"6.Guardar posiciones\n"
				"0.Salir\n"
				"\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 6, 4);
		system("cls");
		switch(menu)
		{
			case 1:
				if(controller_loadDataFromText("../enduro.csv", enduroList)!=-1)
				{
					printf("Archivo cargado con exito!\n");
					flagMenu=1;
				}
				else
				{
					printf("No se pudo cargar el archivo\n");
				}
				system("pause");
			break;

			case 2:
				if(flagMenu==1)
				{
					if(controller_listarData(enduroList)!=-1)
					{
						printf("Data enduro en el sistema!\n");
					}
					else
					{
						printf("No se pudo mostar la data\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 3:
				if(flagMenu==1)
				{
					if(ll_map(enduroList, enduro_calcularPromedio)!=-1)
					{
						printf("Promedio calculado exitosamenet!\n");
					}
					else
					{
						printf("No se pudo calcular el promedio\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 4:
				if(flagMenu==1)
				{
					if(controller_filtarCategoria(enduroList, enduroListFiltrada)!=-1)
					{
						printf("Categoria filtrada exitosamente!\n");
					}
					else
					{
						printf("No se pudo filtrar la categoria\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 5:
				if(flagMenu==1)
				{
					if(controller_listarCategoriaMX1(enduroList, enduroListFiltrada)!=-1 && controller_listarCategoriaMX2(enduroList, enduroListFiltrada)!=-1 &&
							controller_listarCategoriaSUPER_ATV(enduroList, enduroListFiltrada)!=-1)
					{

					}
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 6:
				if(flagMenu==1)
				{
					if(controller_ordenarCategoria(enduroList)!=-1)
					{
						printf("Data ordenada\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 0:
				utn_getNumero(&menu, "-- SALIR --\n\nSeguro que desea salir?\n0.Si\n1.No\n\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 1, 2);
			break;
		}
		system("cls");
	}while(menu!=0);
	return EXIT_SUCCESS;
}
