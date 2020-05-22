#include "Disco.h"

Disco::Disco():Material()
{
	duracion = 0;
	Genero = "Genero default";
}

Disco::Disco(int id, std::string titu, int dur, std::string gen):Material(id,titu)
{
	duracion = dur;
	Genero = gen;
}

void Disco::setDuracion(int dur)
{
	duracion = dur;
}

void Disco::setGenero(std::string gen)
{
	Genero = gen;
}

int Disco::getDuracion()
{
	return duracion;
}

std::string Disco::getGenero()
{
	return Genero;
}

void Disco::muestraDatos()
{
	std::cout << "ID: " << idMaterial << " | Titulo: " << titulo << " | Duracion: " << duracion << " | Genero: " << Genero << std::endl;
}

int Disco::cantidadDiasPrestamo()
{
	return 2;
}
