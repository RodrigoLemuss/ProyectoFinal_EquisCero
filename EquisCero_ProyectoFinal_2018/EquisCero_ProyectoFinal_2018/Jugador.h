#pragma once
#include <opencv2/opencv.hpp>
#include "TableroOpencv.h"
#include <string.h>
using namespace cv;
using namespace std;

Tablero colores;


class Jugador
{
public:
	int idJugador;
	string nombreJugador;

	//void registrarJugadores(Mat ventana_jugadores, Jugador *);
};

//void Jugador::registrarJugadores(Mat ventana_jugadores, Jugador *p) {
//	bool cuadrotexto = true;
//	int contador;
//	while (true) {
//		Rect rectangulo1(145, 30, 200, 30);
//		rectangle(ventana_jugadores, rectangulo1, colores.rojo);
//		putText(ventana_jugadores, "Jugador 1: ", Point(50, 50), CV_FONT_HERSHEY_SIMPLEX, 0.4, colores.blanco);
//
//		Rect rectangulo2(145, 130, 200, 30);
//		rectangle(ventana_jugadores, rectangulo2, colores.azul);
//		putText(ventana_jugadores, "Jugador 2: ", Point(50, 150), CV_FONT_HERSHEY_SIMPLEX, 0.4, colores.blanco);
//
//		Rect rectangulo3(70, 250, 250, 50);
//		rectangle(ventana_jugadores, rectangulo3, Scalar(0, 0, 255));
//		putText(ventana_jugadores, "Jugar!", Point(175, 280), CV_FONT_HERSHEY_SIMPLEX, 0.4, blanco);
//
//		imshow("Jugadores", ventana_jugadores);
//
//		char tecla = waitKey(10);
//
//		if (tecla == 27) break;
//
//		if (cuadrotexto == true) {
//			contador = 0;
//			if (tecla >= 'a' && tecla <= 'z' && contador < 10) {
//				nickname1 += tecla;
//				contador++;
//				putText(ventana_jugadores, nickname1, Point(150, 50), CV_FONT_HERSHEY_SIMPLEX, 0.4, blanco);
//			}
//		}
//		else {
//			contador = 0;
//			if (tecla >= 'a' && tecla <= 'z' && contador < 10) {
//				nickname2 += tecla;
//				contador++;
//				putText(ventana_jugadores, nickname2, Point(150, 150), CV_FONT_HERSHEY_SIMPLEX, 0.4, blanco);
//			}
//		}
//	}
//}