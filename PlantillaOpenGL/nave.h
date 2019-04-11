#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include "GL/glew.h"
#include <time.h>


class Nave : public Modelo {
public:
	Nave();
	enum Direccion {Izquierda, Derecha};
	vec3 coordenadas;
	float angulo = 0.0f;
	float velocidadAngular = 0.4f;
	float xNave = 0.0f;
	float yNave = 0.0f;
	float aceleracion = 0.09f;
	float velocidadNormal = 1.18f;
	float desaceleracion = 0.05f;




	double tiempoAnterior = 0.0f;
	double tiempoActual = 0.0f;
	double tiempoDiferencial = 0.0f;

	void rotar(Direccion direccion);
	void avanzar();
	void actualizarMatrizTransformacion();
	void naveTiempoDiferencial();
	void naveRegreso();
};