#include <iostream>

#define GLM_SWIZZLE

// inclui as bibliotecas da GLM
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors() {
	// vetor com 2 coordenadas - x,y (2D)
	glm::vec2 Ponto0{ 10.0f, 10.0f };

	// vetor com 3 coordenadas - x,y,z (3D)
	glm::vec3 Ponto1{ 10.0f, 0.0f, 0.0f };

	// vetor com 4 coordenadas 4D
	glm::vec4 Ponto2{ 10.0f, 10.0f, 0.0f, 0.0f };

	//vetor com 2 coordenadas inteiras
	glm::ivec2 Ponto3{ 3, 4 };

	// vetor com 3 coordenadas booleanas
	glm::bvec3 Ponto4{ false, true, false };

	//vetor com 2 coordenadas decimais - maior precisão
	glm::dvec2 Ponto5{ 10.0, 10.0 };

	// construir pontos a partir de outros pontos
	glm::vec3 Ponto6{ Ponto0, 1.0f };
	glm::vec3 Ponto7{ Ponto2 };

	// mostra os vetores na forma de strings
	std::cout << std::endl; // pula linha
	std::cout <<"Ponto 0 " << glm::to_string(Ponto0) << std::endl;
	std::cout << "Ponto 1 " << glm::to_string(Ponto1) << std::endl;
	std::cout << "Ponto 2 " << glm::to_string(Ponto2) << std::endl;
	std::cout << "Ponto 3 " << glm::to_string(Ponto3) << std::endl;
	std::cout << "Ponto 4 " << glm::to_string(Ponto4) << std::endl;
	std::cout << "Ponto 5 " << glm::to_string(Ponto5) << std::endl;
	std::cout << "Ponto 6 " << glm::to_string(Ponto6) << std::endl;
	std::cout << "Ponto 7 " << glm::to_string(Ponto7) << std::endl;
}

void Components() {
	glm::vec3 Ponto{ 1, 2, 3 };

	//mostra os vetores na forma de strings
	std::cout << std::endl; // pula linha
	std::cout << "X: " << Ponto.x << " Y: " << Ponto.y << " Z: " << Ponto.z << std::endl;
	std::cout << "R: " << Ponto.r << " G: " << Ponto.g << " B: " << Ponto.b << std::endl;
	std::cout << "0: " << Ponto[0] << " 1: " << Ponto[1] << " 2: " << Ponto[2] << std::endl;
}

void Swizzle() {
	glm::vec4 P1{ 1,2,3,4 };
	glm::vec3 P2 = P1.xxx; // {1,1,1}
	glm::vec3 P3 = P1.xyx; // {1,2,1}
	glm::vec4 P4 = P1.xyzw; // {1,2,3,4}
	glm::vec4 P5 = P1.xzzw; // {1,3,3,4}

	std::cout << std::endl; // pula linha
	std::cout << "P1 " << glm::to_string(P1) << std::endl;
	std::cout << "P2 " << glm::to_string(P2) << std::endl;
	std::cout << "P3 " << glm::to_string(P3) << std::endl;
	std::cout << "P4 " << glm::to_string(P4) << std::endl;
	std::cout << "P5 " << glm::to_string(P5) << std::endl;
}

void Operations() {
	glm::vec3 P0{ 10.0f, 10.0f,0.0f };
	glm::vec3 P1{ 10.0f, 10.0f,10.0f };

	glm::uvec3 PR;


	std::cout << std::endl; // pula linha

	//soma
	PR = P0 + P1;
	std::cout << "PR - soma " << glm::to_string(PR) << std::endl;

	//subtracao
	PR = P0 - P1;
	std::cout << "PR - subtracao " << glm::to_string(PR) << std::endl;

	//escala
	PR = P0 * 5.0f;
	std::cout << "PR - escala multiplicacao " << glm::to_string(PR) << std::endl;
	PR = P0 / 5.0f;
	std::cout << "PR - escala divisao " << glm::to_string(PR) << std::endl;

	//multiplicacao
	PR = P0 * P1;
	std::cout << "PR - multiplicacao " << glm::to_string(PR) << std::endl;

	//divisao
	PR = P0 / P1;
	std::cout << "PR - divisao " << glm::to_string(PR) << std::endl;

	// comprimento
	float L = glm::length(P0); // sqrt(x^2 + y^2 + z^2)
	std::cout << "Comprimento do vetor " << L << std::endl;
	std::cout << "Qtde coordenadas do vetor " << P0.length() << std::endl;

	// normalizar - retorna vetor de tamanho 1
	glm::vec3 Norm = glm::normalize(P0);

	// produto escalar (Dot Product) - cosseno do ângulo entre os vetores
	float Dot = glm::dot(P0, P1);

	// produto vetorial - cross product - area definida pelo paralelograma
	glm::vec3 Cross = glm::cross(P0, P1);

	// distância entre dois pontos
	float Distance = glm::distance(P0, P1);

	// vetor de refração - vetor de incidência e vetor normal
	glm::vec3 Refract = glm::refract(P0, Norm, 1.0f);

	// vetor de reflexão - vetor de incidência e vetor normal
	glm::vec3 Reflect = glm::reflect(P0, Norm);
}

int main() {
	Constructors(); // vai criar os vetores
	Components(); // analisar e explorar os vetores como componentes
	Swizzle(); // criarmos um novo ponto a partir de outros existentes
	Operations();
	return 0;
}
