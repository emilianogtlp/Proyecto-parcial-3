#pragma once
#include "Fecha.h"
#include "Material.h"
class Reserva
{
public:
	Reserva();
	Reserva(int idC, int idM, Fecha fechar);
	Fecha calculaFechaFinReserva(int m1);
private:
	int idCliente;
	int idMaterial;
	Fecha fechaReservacion;
};

