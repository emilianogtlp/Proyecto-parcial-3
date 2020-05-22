#include "Software.h"

Software::Software():Material()
{
	Version = 0;
	SO = 0;
}

Software::Software(int id, std::string titu, int ver, int so):Material(id,titu)
{
	Version = ver;
	SO = so;
}

void Software::setVersion(int ver)
{
	Version = ver;
}

void Software::setOS(int os)
{
	SO = os;
}

int Software::getVersion()
{
	return Version;
}

int Software::getOS()
{
	return SO;
}

void Software::muestraDatos()
{
	std::cout << "Software " << "ID: " << idMaterial << " | Titulo: " << titulo << " | SO: " << SO << " | Version: " << Version << std::endl;
}

int Software::cantidadDiasPrestamo()
{
	return 1;
}
