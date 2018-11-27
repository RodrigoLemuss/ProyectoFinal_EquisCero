#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

class Tarjeta
{
public:
	int numeroTarjeta();

};


int Tarjeta::numeroTarjeta() {
	srand(5);
	return (1 + rand() % 13);
}
