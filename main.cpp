#include <iostream>
#include <glm/glm.hpp>

#include <glm/gtx/string_cast.hpp>

#include <stb_image.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>


int main() {

	glm::vec3 V(1, 2, 3);

	// definindo a saída padrão
	std::cout << "Boa noite, já sabemos C++" << std::endl;
	std::cout << glm::to_string(V) << std::endl;

	glfwInit();

	glewInit();

	return 0;
}