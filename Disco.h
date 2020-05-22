#pragma once
#include "Material.h"
#include <iostream>
class Disco : public Material
{
public:
	
	//Constructores
	Disco();
	Disco(int id, std::string titu, int dur, std::string gen);

	//metodos de acceso

	void setDuracion(int dur);
	void setGenero(std::string gen);
	int getDuracion();
	std::string getGenero();

	// metodos abstractos heredados de Material.h
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int duracion;
	std::string Genero;

};

