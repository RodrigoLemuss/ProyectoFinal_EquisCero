// EquisCero_ProyectoFinal_2018.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Tarjetas.h"
#include "Tablero.h"
#include "TableroOpencv.h"
#include "Jugador.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Tablero dibujarTablero;
Mat ventana(30 * 18, 30 * 18, CV_8UC3, dibujarTablero.fondo);

ListaCasillas lista; //lista doblemente enlazada
Tarjeta tarjetas; //la usamos para obtener valores aleatorios
Jugador jugadores[4]; //para saber el numero de jugador y sus datos
int turno = 0;
void cargarTableroSinFichas() {
	

	//Puntos de llegada
	dibujarTablero.dibujarCirculo(Point(30 * 3.5, 30 * 8.5 - 3), dibujarTablero.rojo, ventana);
	dibujarTablero.dibujarCirculo(Point(30 * 14.5, 30 * 9.5 + 3), dibujarTablero.amarillo, ventana);
	dibujarTablero.dibujarCirculo(Point(30 * 8.5 - 3, 30 * 14.5), dibujarTablero.verde, ventana);
	dibujarTablero.dibujarCirculo(Point(30 * 9.5 + 3, 30 * 3.5), dibujarTablero.azul, ventana);

	//Puntos de partida
	dibujarTablero.dibujarCirculo(Point(30 * 5.5, 30 * 3.5 - 3), dibujarTablero.rojo, ventana);
	dibujarTablero.dibujarCirculo(Point(30 * 12.5, 30 * 14.5 + 3), dibujarTablero.amarillo, ventana);
	dibujarTablero.dibujarCirculo(Point(30 * 3.5 - 3, 30 * 12.5), dibujarTablero.verde, ventana);
	dibujarTablero.dibujarCirculo(Point(30 * 14.5 + 3, 30 * 5.5), dibujarTablero.azul, ventana);

	//Casillas blancas (contorno)
	for (int i = 0; i < 16; i++) {
		//Fila arriba
		dibujarTablero.dibujarCasilla(Point(30 + 30 * i, 30), dibujarTablero.blanco, ventana);
		//Fila abajo
		dibujarTablero.dibujarCasilla(Point(30 + 30 * i, 16 * 30), dibujarTablero.blanco, ventana);
		//Columna izquierda
		dibujarTablero.dibujarCasilla(Point(30, 30 + 30 * i), dibujarTablero.blanco, ventana);
		//Columna derecha
		dibujarTablero.dibujarCasilla(Point(16 * 30, 30 + 30 * i), dibujarTablero.blanco, ventana);
	}

	//Casillas de colores
	for (int i = 1; i <= 5; i++) {
		dibujarTablero.dibujarCasilla(Point(30 * 3, 30 + 30 * i), dibujarTablero.blanco, ventana);
		dibujarTablero.dibujarCasilla(Point(30 * 14, 300 + 30 * i), dibujarTablero.blanco, ventana);
		dibujarTablero.dibujarCasilla(Point(30 + 30 * i, 30 * 14), dibujarTablero.blanco, ventana);
		dibujarTablero.dibujarCasilla(Point(300 + 30 * i, 30 * 3), dibujarTablero.blanco, ventana);
	}

	//Centro
	dibujarTablero.dibujarCentro(ventana);
	
	
}

void onMouse(int event, int x, int y, int, void*) {
	if (event == CV_EVENT_LBUTTONUP) {
			turno++;

	if (jugadores[turno].idJugador = 1)
	{
		cout << "turno";
		lista.avanzarCasilla(1, tarjetas.numeroTarjeta(turno), jugadores[turno].idJugador, ventana, 5);
		turno++;
	}

	turno = 0;
	}
}

void cargarTablero() {

	namedWindow("ji");
	setMouseCallback("ji", onMouse);


	cargarTableroSinFichas();
	while (true)
	{
		imshow("ji", ventana);
		if ((waitKey(1) & 0XFF) == 27) break;
	}
}
int main() {

	for (int i = 0; i <4 ; i++)
	{
		jugadores[i].setIdjugador(i + 1);
		jugadores[i].setNombreJugador(i);
		
	}
	
	lista.Inicializa();
	lista.insertarFinal(60);
	lista.asignarCoordenadas();
	lista.mostrar();
	

		
	cargarTablero();
	
	//
	

	
	return 0;
}

