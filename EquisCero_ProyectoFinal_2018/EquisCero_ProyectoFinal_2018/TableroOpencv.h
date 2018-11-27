#pragma once
#include <opencv2/opencv.hpp>
#include "Tarjetas.h"
#include <iostream>
using namespace std;
using namespace cv;


class Tablero
{
public:
	
	Scalar negro = Scalar(0, 0, 0);
	Scalar blanco = Scalar(255, 255, 255);
	Scalar fondo = Scalar(50, 150, 50);
	Scalar azul = Scalar(255, 0, 0);
	Scalar verde = Scalar(0, 255, 0);
	Scalar rojo = Scalar(0, 0, 255);
	Scalar amarillo = Scalar(0, 255, 255);
	
	
	void dibujarCasilla(Point esquinaSupizq, Scalar color, Mat v);
	void dibujarCirculo(Point centro, Scalar color, Mat v);
	void DrawRotatedRectangle(Point, Size, double, Scalar, Mat);
	void dibujarCentro(Mat v);


};


void Tablero::dibujarCasilla(Point esquinaSupizq, Scalar color, Mat v) {
	rectangle(v, Rect(esquinaSupizq.x, esquinaSupizq.y, 30, 30), color, CV_FILLED);
	rectangle(v, Rect(esquinaSupizq.x, esquinaSupizq.y, 30, 30), negro, 2);
}
void Tablero::dibujarCirculo(Point centro, Scalar color, Mat v) {
	circle(v, centro, 30 * 1.5, color, CV_FILLED);
	circle(v, centro, 30 * 1.5, negro, 2);
}

void Tablero::dibujarCentro(Mat v) {
	//Cuadros de colores
	rectangle(v, Rect(v.rows / 2 - 30 * 2, v.cols / 2 - 30 * 2, 30 * 2, 30 * 2), rojo, CV_FILLED);
	rectangle(v, Rect(v.rows / 2, v.cols / 2 - 30 * 2, 30 * 2, 30 * 2), azul, CV_FILLED);
	rectangle(v, Rect(v.rows / 2 - 30 * 2, v.cols / 2, 30 * 2, 30 * 2), verde, CV_FILLED);
	rectangle(v, Rect(v.rows / 2, v.cols / 2, 30 * 2, 30 * 2), amarillo, CV_FILLED);
	rectangle(v, Rect(v.rows / 2 - 30 * 2, v.cols / 2 - 30 * 2, 30 * 4, 30 * 4), negro, 2);

	//Rombo central (cuadrado girado 45 grados)
	DrawRotatedRectangle(Point(v.rows / 2, v.cols / 2), Size(30 * 3.5, 30 * 3.5), 45, negro,v);
	DrawRotatedRectangle(Point(v.rows / 2, v.cols / 2), Size(30 * 3.5 - 4, 30 * 3.5 - 4), 45, fondo,v);
}

void  Tablero::DrawRotatedRectangle(Point centerPoint, Size rectangleSize, double rotationDegrees, Scalar color, Mat v) {
	// Create the rotated rectangle
	RotatedRect rotatedRectangle(centerPoint, rectangleSize, rotationDegrees);
	// We take the edges that OpenCV calculated for us
	Point2f vertices2f[4];
	rotatedRectangle.points(vertices2f);
	// Convert them so we can use them in a fillConvexPoly
	Point vertices[4];
	for (int i = 0; i < 4; ++i) vertices[i] = vertices2f[i];
	// Now we can fill the rotated rectangle with our specified color
	fillConvexPoly(v, vertices, 4, color);
}
