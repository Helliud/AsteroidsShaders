#include "stdafx.h"
#include "Nave.h"


Nave::Nave() {
	angulo = 0.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	//Establecer el valor como una matriz identidad
	transformaciones = mat4(1.0f);

	Vertice v1 = {
		vec4(0.0f,0.1f,0.0f,1.0f),
		vec4(1.0f,0.0f,0.0f,1.0f)
	};

	Vertice v2 = {
		vec4(-0.1f,-0.1f,0.0f,1.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	Vertice v3 = {
		vec4(0.1f,-0.1f,0.0f,1.0f),
		vec4(1.0f,0.8f,0.0f,1.0f)
	};

	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

}

void Nave::naveTiempoDiferencial() {

	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;

}

void Nave::rotar(Direccion direccion) {

	float rotacion = velocidadAngular;

	if (direccion == Direccion::Derecha) {
		rotacion = -rotacion * tiempoDiferencial;
		if (rotacion > 360) {
			rotacion -= 360;
		}
	}

	if (direccion == Direccion::Izquierda) {
		rotacion = +rotacion * tiempoDiferencial;
		if (rotacion > 0) {
			rotacion += 360;
		}
	}
	angulo += rotacion;

	actualizarMatrizTransformacion();
}

void Nave::naveRegreso() {

	if (coordenadas.x > 1.2f) {
		coordenadas.x -= 2.2;
	}

	else if (coordenadas.x < -1.2f) {
		coordenadas.x += 2.2;
	}

	if (coordenadas.y > 1.2) {
		coordenadas.y += -2.2;
	}

	else if (coordenadas.y < -1.2) {
		coordenadas.y += 2.2;
	}
}

void Nave::avanzar() {

	if (velocidad < velocidadMaxima) {
		velocidad += aceleracion * tiempoDiferencial;
	}

	float anguloDesfasado = angulo + 90.0f;


	vec3 traslacion = vec3(
		cos(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //X
		sin(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //Y
		0.0f
	);
	coordenadas += traslacion;
	actualizarMatrizTransformacion();
}

void Nave::actualizarMatrizTransformacion() {
	//Partir siempre de una matriz identidad
	transformaciones = mat4(1.0f);
	
	//Aplicar transformaciones
	transformaciones = translate(transformaciones, coordenadas);
	transformaciones = rotate(transformaciones, angulo * 3.14159f / 180.0f, vec3(0.0f, 0.0f, 1.0f));
}


void Nave::desaceleracionNave() {

	velocidad -= aceleracion * tiempoDiferencial;
	if (velocidad < 0) {
		velocidad = 0.0f;
	}

	float anguloDesfasado = angulo + 90.0f;

	vec3 traslacion = vec3(
		cos(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //x
		sin(anguloDesfasado * 3.14159 / 180.0f) * velocidad, //y
		0.0f //z
	);

	coordenadas += traslacion;

	actualizarMatrizTransformacion();


}

