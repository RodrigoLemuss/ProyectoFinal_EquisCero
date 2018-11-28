// EquisCero_ProyectoFinal_2018.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Tarjetas.h"
#include "Tablero.h"
#include "TableroOpencv.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Tablero dibujarTablero;
Mat ventana(30 * 18, 30 * 18, CV_8UC3, dibujarTablero.fondo);



int main() {
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
		dibujarTablero.dibujarCasilla(Point(30 * 3, 30 + 30 * i), dibujarTablero.rojo, ventana);
		dibujarTablero.dibujarCasilla(Point(30 * 14, 300 + 30 * i), dibujarTablero.amarillo, ventana);
		dibujarTablero.dibujarCasilla(Point(30 + 30 * i, 30 * 14), dibujarTablero.verde, ventana);
		dibujarTablero.dibujarCasilla(Point(300 + 30 * i, 30 * 3), dibujarTablero.azul, ventana);
	}

	//Centro
	dibujarTablero.dibujarCentro(ventana);
	ListaCasillas lista;
	Tarjeta tarjetas;
	lista.Inicializa();
	lista.insertarFinal(60);
	lista.asignarCoordenadas();
	lista.mostrar();
	int cont = 0;
	do {
		lista.avanzarCasilla(1, tarjetas.numeroTarjeta(cont), 3, ventana);
	} while (cont++ <=10);
	
	imshow("Tablero", ventana);
	
	

	
	waitKey(0);

	
	return 0;
}

