#pragma once
#include <iostream>
using namespace std;
class Fecha
{
public:

	// constructores
	
	Fecha();
	Fecha(int d, int m, int a);

	// metodos de accesos y modificacion
	
	void setFecha(int d, int m, int a);
	int getDia();
	int getMes();
	int getAnio();

	// sobrecarga de operadores

	Fecha operator+(int f1);
	bool operator>=(Fecha f1);
	bool operator<=(Fecha f1);
	bool operator>(Fecha f1);
	bool operator<(Fecha f1);
	bool operator==(Fecha f1);
	friend ostream &operator<<(ostream &os, Fecha f1);
	friend istream &operator>>(istream& os, Fecha& f1);

private:
	int dd, mm, aa;
};

