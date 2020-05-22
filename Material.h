#pragma once
#include <string>
class Material
{
public:
	//constructores

	Material();
	Material(int id, std::string titu);

	// metodos de acceso y modificacion 
	
	void setTitulo(std::string titu);
	void setIdMaterial(int idmat);
	std::string getTitulo();
	int getIdMaterial();
	
	//metodos  abstractos
	
	virtual void muestraDatos() = 0;
	virtual int cantidadDiasPrestamo() = 0;

protected:

	//atributos

	std::string titulo;
	int idMaterial;

};

