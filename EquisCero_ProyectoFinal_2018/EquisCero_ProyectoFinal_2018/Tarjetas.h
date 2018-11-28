#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

class Tarjeta
{
public:
	int numeroTarjeta(int);

};


int Tarjeta::numeroTarjeta(int semilla) {
	srand(semilla);
	return (1 + rand() % 13);
}
