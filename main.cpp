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

	glfwMakeContextCurrent(window); // torna a janela criada como o contexto corrente
	glewInit();// inicializa a glew

	GLint GLMajorVersion;
	GLint GLMinorVersion;
	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	std::cout << "OpenGL Version: " << GLGetString() << std::endl;

	std::cout << "OpenGL Vendor: " << GLMajorVersion << "." << GLMinorVersion << std::endl;

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);// define o estado com a cor vermelha (novo estado)

	// enquanto a janela não for fechada
	while (!glfwWindowShouldClose(window)) {

		// glClear limpa o frame buffer
		// GL_COLOR_BUFFER_BIT informa para limpar o buffer de cor para colorir com a cor corrente
		glClear(GL_COLOR_BUFFER_BIT);
		// processar todos os eventos da fila de eventos do GLFW (teclado, mouse, gamepad)
		glfwPollEvents();

		// envia o conteúdo do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(window);
	}


	glfwTerminate(); // encerra a janela

	glewInit();

	return 0;
}