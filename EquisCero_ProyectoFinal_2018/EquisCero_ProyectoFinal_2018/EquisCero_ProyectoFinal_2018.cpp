// EquisCero_ProyectoFinal_2018.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Scalar negro = Scalar(0, 0, 0);
Scalar blanco = Scalar(255, 255, 255);
Scalar fondo = Scalar(50, 150, 50);
Scalar azul = Scalar(255, 0, 0);
Scalar verde = Scalar(0, 255, 0);
Scalar rojo = Scalar(0, 0, 255);
Scalar amarillo = Scalar(0, 255, 255);
Mat ventana(30 * 18, 30 * 18, CV_8UC3, fondo);

void dibujarCasilla(Point esquinaSupizq, Scalar color) {
	rectangle(ventana, Rect(esquinaSupizq.x, esquinaSupizq.y, 30, 30), color, CV_FILLED);
	rectangle(ventana, Rect(esquinaSupizq.x, esquinaSupizq.y, 30, 30), negro, 2);
}
void dibujarCirculo(Point centro, Scalar color) {
	circle(ventana, centro, 30 * 1.5, color, CV_FILLED);
	circle(ventana, centro, 30 * 1.5, negro, 2);
}
void DrawRotatedRectangle(Point, Size, double, Scalar);
void dibujarCentro() {
	//Cuadros de colores
	rectangle(ventana, Rect(ventana.rows / 2 - 30 * 2, ventana.cols / 2 - 30 * 2, 30 * 2, 30 * 2), rojo, CV_FILLED);
	rectangle(ventana, Rect(ventana.rows / 2, ventana.cols / 2 - 30 * 2, 30 * 2, 30 * 2), azul, CV_FILLED);
	rectangle(ventana, Rect(ventana.rows / 2 - 30 * 2, ventana.cols / 2, 30 * 2, 30 * 2), verde, CV_FILLED);
	rectangle(ventana, Rect(ventana.rows / 2, ventana.cols / 2, 30 * 2, 30 * 2), amarillo, CV_FILLED);
	rectangle(ventana, Rect(ventana.rows / 2 - 30 * 2, ventana.cols / 2 - 30 * 2, 30 * 4, 30 * 4), negro, 2);

	//Rombo central (cuadrado girado 45 grados)
	DrawRotatedRectangle(Point(ventana.rows / 2, ventana.cols / 2), Size(30 * 3.5, 30 * 3.5), 45, negro);
	DrawRotatedRectangle(Point(ventana.rows / 2, ventana.cols / 2), Size(30 * 3.5 - 4, 30 * 3.5 - 4), 45, fondo);
}

int main() {
	//Puntos de llegada
	dibujarCirculo(Point(30 * 3.5, 30 * 8.5 - 3), rojo);
	dibujarCirculo(Point(30 * 14.5, 30 * 9.5 + 3), amarillo);
	dibujarCirculo(Point(30 * 8.5 - 3, 30 * 14.5), verde);
	dibujarCirculo(Point(30 * 9.5 + 3, 30 * 3.5), azul);

	//Puntos de partida
	dibujarCirculo(Point(30 * 5.5, 30 * 3.5 - 3), rojo);
	dibujarCirculo(Point(30 * 12.5, 30 * 14.5 + 3), amarillo);
	dibujarCirculo(Point(30 * 3.5 - 3, 30 * 12.5), verde);
	dibujarCirculo(Point(30 * 14.5 + 3, 30 * 5.5), azul);

	//Casillas blancas (contorno)
	for (int i = 0; i < 16; i++) {
		//Fila arriba
		dibujarCasilla(Point(30 + 30 * i, 30), blanco);
		//Fila abajo
		dibujarCasilla(Point(30 + 30 * i, 16 * 30), blanco);
		//Columna izquierda
		dibujarCasilla(Point(30, 30 + 30 * i), blanco);
		//Columna derecha
		dibujarCasilla(Point(16 * 30, 30 + 30 * i), blanco);
	}

	//Casillas de colores
	for (int i = 1; i <= 5; i++) {
		dibujarCasilla(Point(30 * 3, 30 + 30 * i), rojo);
		dibujarCasilla(Point(30 * 14, 300 + 30 * i), amarillo);
		dibujarCasilla(Point(30 + 30 * i, 30 * 14), verde);
		dibujarCasilla(Point(300 + 30 * i, 30 * 3), azul);
	}

	//Centro
	dibujarCentro();

	imshow("Tablero", ventana);
	waitKey(0);

	return 0;
}

void DrawRotatedRectangle(Point centerPoint, Size rectangleSize, double rotationDegrees, Scalar color) {
	// Create the rotated rectangle
	RotatedRect rotatedRectangle(centerPoint, rectangleSize, rotationDegrees);
	// We take the edges that OpenCV calculated for us
	Point2f vertices2f[4];
	rotatedRectangle.points(vertices2f);
	// Convert them so we can use them in a fillConvexPoly
	Point vertices[4];
	for (int i = 0; i < 4; ++i) vertices[i] = vertices2f[i];
	// Now we can fill the rotated rectangle with our specified color
	cv::fillConvexPoly(ventana, vertices, 4, color);
}
