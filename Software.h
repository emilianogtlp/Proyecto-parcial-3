#pragma once
#include "Material.h"
#include <iostream>
class Software:public Material
{
public:
	//constructores
	Software();
	Software(int id, std::string titu, int ver, int so);

	//metodos de acceso y modificacion

	void setVersion(int ver);
	void setOS(int os);
	int getVersion();
	int getOS();

	// metodos abstractos heredados de Material.h
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int Version, SO;
};

