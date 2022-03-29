#include <array>
#include <iostream>
#include <glm/glm.hpp>

#include <glm/gtx/string_cast.hpp>

#include <stb_image.h>

#include <GL/glew.h>

#include <glm/ext.hpp>

#include <GLFW/glfw3.h>

const int width = 800;
const int height = 600;


int main() {

	glfwInit();

	// referencia para a janela
	GLFWwindow* window = glfwCreateWindow(width, height, "BlueMarble", nullptr, nullptr);

	glfwMakeContextCurrent(window); // torna a janela criada como o contexto corrente

	glewInit();// inicializa a glew

	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;
		
	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	// std::cout << "OpenGL Version: " << GLGetString() << std::endl;

	std::cout << "OpenGL Vendor: " << GLMajorVersion << "." << GLMinorVersion << std::endl;

	// Usar o glGetString() para obter informa��es sobre o driver que estamos usando
	std::cout << "OpenGL Vendor   : " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "OpenGL Renderer : " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL Version  : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version    : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	// define um tri�ngilo em coordenadas normalizadas
	std::array<glm::vec3, 3> Triangle = {
		glm::vec3{ 0.0f, 0.5f, 0.0f},
		glm::vec3{ -0.5f, -0.5f, 0.0f},
		glm::vec3{ 0.5f, -0.5f, 0.0f}
	};

	//Model view Projection
	glm::mat4 Model = glm::identity<glm::mat4>();

	//View (Camera)
	glm::vec3 Eye{ 0.0f, 0.0f, 10.0f }; // posicao 
	glm::vec3 Center{ 0.0f, 0.0f, 0.0f }; // dire��o
	glm::vec3 Up{ 1.0f, 1.0f, 0.0f }; // orienta��o

	//define a camera
	glm::mat4 View = glm::lookAt(Eye, Center, Up);

	//Projection
	//angulo de vis�o 45�
	constexpr float FoV = glm::radians(45.0f);
	//raz�o de aspecto
	const float AspectRatio = width / height;
	const float Near = 0.001f; //proximo de 0
	//distancia do plano longe da camera
	const float Far = 1000.0f; // isso � 1
	glm::mat4 Projection = glm::perspective(FoV, AspectRatio, Near, Far);

	glm::mat4 ModelViewProjection = Projection * View * Model;

	// aplicar a ModelViewProjection nos vertices do tri�ngulo
	for (glm::vec3& Vertex : Triangle) {
		// precisamos transformar o vec3 em v4
		glm::vec4 ProjectedVertex = ModelViewProjection * glm::vec4{ Vertex,1.0f };
		//transformando o ProjectedVertex em coordenadas normalizadas entre 0 e 1
		//dividir x,y,z por w garante que as coordenadas estejam entre 0 e 1
		ProjectedVertex /= ProjectedVertex.w;
		//colocamos a altera��o no Vertex
		Vertex = ProjectedVertex;
	}

	// vamos copiar os v�rtices do triangulo para a mem�ria da GPU
	GLuint VertexBuffer;

	// gerar o identificador
	glGenBuffers(1, &VertexBuffer);

	// ativa glBufferVertex para receber a c�pia
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);


	// copia os dados para a mem�ria de v�deo
	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);

	// Define a cor de fundo
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);// define o estado com a cor vermelha (novo estado)

	// enquanto a janela n�o for fechada
	while (!glfwWindowShouldClose(window)) {

		// glClear limpa o frame buffer
		// GL_COLOR_BUFFER_BIT informa para limpar o buffer de cor para colorir com a cor corrente
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		// informa ao OpenGL que VertexBuffer ser� o ativo no momento
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		// informa ao OpenGL onde, dentro do vertex buffer, os v�rtices est�o
		// array � cont�guoa em mem�ria, basta dizer quantos v�rtices ser�o utilizados
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		// finalmente dispara o OpenGL e desenha triangulo no vertex buffer
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// reverte o estado criado
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glDisableVertexAttribArray(0);


		// processar todos os eventos da fila de eventos do GLFW (teclado, mouse, gamepad)
		glfwPollEvents();

		// envia o conte�do do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(window);
	}

	// desaloca 
	glDeleteBuffers(1, &VertexBuffer);

	glfwTerminate(); // encerra a janela

	return 0;
}