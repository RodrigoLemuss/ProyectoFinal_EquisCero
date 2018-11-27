#pragma once
#include <opencv2/opencv.hpp>
#include "Tarjetas.h"
#include <iostream>
using namespace std;
using namespace cv;



class Casilla
{

	bool casilla_ocupada = false;
	//Conocer que jugador esta usando esta casilla
	bool rojo = false, verde = false, amarillo = false, azul = false;
	//Valores para facilitar el movimiento de las fichas
	int coor_x, coor_y, num_casilla, puntos_ficha;
	//Punteros para recorrer el tablero
	Casilla *Sig;
	Casilla *Ant;

	friend class ListaCasillas;
};

class ListaCasillas
{
	Casilla *Primero, *Ultimo;
public:
	void Inicializa();
	bool vacia();
	int tamano();
	void mostrar();
	void insertarInicio();
	void insertarFinal(int);
	void asignarCoordenadas();
	void avanzarCasilla();
	//void insertarPosicion(int posicion);
};


void ListaCasillas::Inicializa() {
	Primero = NULL;
	Ultimo = NULL;
}


bool ListaCasillas::vacia() {
	if (Primero == NULL and Ultimo == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ListaCasillas::tamano() {
	int cont=0;
	Casilla *aux;
	aux = Ultimo;

	while (aux != NULL)
	{	
		cont++;
		aux = aux->Ant;
	}
	return cont;
}

void ListaCasillas::insertarInicio() {
	Casilla *temp = new Casilla();
	/*
	_Asignar valores
	*/
	temp->Sig = NULL;
	temp->Ant = NULL;

	if (vacia())
	{
		Primero = temp;
		Ultimo = temp;
	}
	else {
		temp->Sig = Primero;
		Primero->Ant = temp;
		Primero = temp;
	}
}

void ListaCasillas::insertarFinal(int num_casillas) {
	

	for (int i = 0; i < num_casillas; i++)
	{
		Casilla *temp = new Casilla();
		/*
		_Asignar valores
		*/
		temp->num_casilla= i+1;
		temp->Sig = NULL;
		temp->Ant = NULL;
		if (vacia())
		{
			Primero = temp;
			Ultimo = temp;
		}
		else {
			temp->Ant = Ultimo;
			Ultimo->Sig = temp;
			Ultimo = temp;
		}
	}
}
//
//void ListaCasillas::insertarPosicion(int po) {
//	Casilla *temp = new Casilla();
//	/*
//	_Asignar valores
//	*/
//	temp->Sig = NULL;
//	temp->Ant = NULL;
//	if (vacia())
//	{
//		Primero = temp;
//		Ultimo = temp;
//	}
//	else {
//		if (po==1)
//		{
//			insertarInicio();
//		}
//		else if (po == (tamano()+1)) {
//			//insertarFinal();
//		}
//		else if (po>1 and po <(tamano()+1)) {
//			Casilla *aux;
//			aux = Primero;
//			for (int i = 1; i < po; i++)
//			{
//				aux = aux->Sig;
//			}
//			aux->Ant->Sig = temp;
//			temp->Sig = aux;
//			temp->Ant = aux->Ant;
//			aux->Ant = temp;
//		}
//		else {
//			cout << "Posicion no encnontrada";
//		}
//	}
//}

void ListaCasillas::mostrar() {

	Casilla *aux;
	aux = Primero;

	while (aux!=NULL)
	{
		/*
		MOstrar datos
		*/
		cout << "numero de casilla >" << aux->num_casilla<<"  -  X("<<aux->coor_x<<","<<aux->coor_y<<")\n";
		aux = aux->Sig;
	}

}

void ListaCasillas::asignarCoordenadas() {
	Casilla *aux;
	aux = Primero;
	int cont = 1,contb=1,contc=1,contd=1;
	for (int i = 1; i <= 60; i++)
	{
		if (i<=16)
		{
			aux->coor_x = 30 * cont++;
			aux->coor_y = 30;
			aux = aux->Sig;
		}
		else if (i > 16 and i <= 31) {
			
			aux->coor_x = 480;
			aux->coor_y = 30*(contb++ +1);
			aux = aux->Sig;
		}
		else if (i>31 and i <=46) {
			
			aux->coor_x = 30 * (contc++ + 1);
			aux->coor_y = 480;
			aux = aux->Sig;
		}
		else if (i > 46 and i <= 60) {
		
			aux->coor_x = 30;
			aux->coor_y = 30 * (contd++ + 1);
			aux = aux->Sig;
		}
	}
	
}
 
void ListaCasillas::avanzarCasilla() {
	Tarjeta tarjetaObj;


}