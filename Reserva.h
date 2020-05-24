#pragma once
#include "Fecha.h"
#include "Material.h"
class Reserva
{
public:
	// constructores
	Reserva();
	Reserva(int idC, int idM, Fecha fechar);
	// metodos NO SOLICITADO
	void setReserva(int idc, int idm, Fecha fechar);
	// metodos modificacion y acceso
	void setIdcliente(int id);
	void setIdmaterial(int idm);
	void setFecha(Fecha f1);
	int getIdcliente();
	int getIdmaterial();
	Fecha getFecha();
	//metodos avanzados
	Fecha calculaFechaFinReserva(int m1);
private:
	int idCliente;
	int idMaterial;
	Fecha fechaReservacion;
};

