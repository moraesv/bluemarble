#include <iostream>
#include <glm/glm.hpp>

#include <glm/gtx/string_cast.hpp>

#include <stb_image.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

const int width = 800;
const int height = 600;


int main() {

	glm::vec3 V(1, 2, 3);

	// definindo a saída padrão
	std::cout << "Boa noite, já sabemos C++" << std::endl;
	std::cout << glm::to_string(V) << std::endl;

	glfwInit();

	// referencia para a janela
	GLFWwindow* window = glfwCreateWindow(width, height, "BlueMarble", nullptr, nullptr);

	// enquanto a janela não for fechada
	while (!glfwWindowShouldClose(window)) {
		// processar todos os eventos da fila de eventos do GLFW (teclado, mouse, gamepad)
		glfwPollEvents();

		// envia o conteúdo do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(window);
	}


	glfwTerminate(); // encerra a janela

	glewInit();

	return 0;
}