#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Nave : public Modelo {
public:
	Nave();
	enum Direccion {Izquierda, Derecha};
	vec3 coordenadas;
	float angulo;
	float velocidadAngular = 5.0f;
	float velocidadNormal = 0.01f;

	void rotar(Direccion direccion);
	void avanzar();
	void actualizarMatrizTransformacion();
};