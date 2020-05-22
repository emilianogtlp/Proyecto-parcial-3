#pragma once
#include "Material.h"
#include <iostream>
class Libro : public Material
{
public:
	//constructores

	Libro();
	Libro(int id, std::string titu, int num, std::string au);

	//metodos de acceso y modificacion

	void setNumPag(int num);
	void setAutor(std::string au);
	int getNumPag();
	std::string getAutor();

	// metodos abstractos heredados de Material.h
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int numPag;
	std::string Autor;
};

