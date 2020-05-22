#pragma once
#include "Material.h"
#include <iostream>
class Software:public Material
{
public:
	//constructores
	Software();
	Software(int id, std::string titu, int ver, std::string so);

	//metodos de acceso y modificacion

	void setVersion(int ver);
	void setOS(std::string os);
	int getVersion();
	std::string getOS();

	// metodos abstractos heredados de Material.h
	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int Version;
	std::string	SO;
};

