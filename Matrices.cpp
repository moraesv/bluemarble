#include <iostream>
#include <iomanip>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

// recebe o endere�o de mem�ria de mat4

void PrintMatrix(const glm::mat4& M) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout
				<< std::setw(10) // espacamento de 10 pts
				<< std::setprecision(4) // precisao 4
				<< std::fixed // fixando o valor
				<< M[j][i] << " "; // mostra valor
		}
		std::cout << std::endl;
	}

}

void TranslationMatrix() {
	// pula linha
	std::cout << std::endl;
	// mostra mensagem
	std::cout << "Translation Matrix" << std::endl;
	// cria uma matriz identidade 4x4 - I 
	glm::mat4 I = glm::identity<glm::mat4>();
	// cria o vetor de transla��o
	glm::vec3 T(10, 10, 10);
	// matriz de transla��o
	glm::mat4 Translation = glm::translate(I, T);
	// imprime
	PrintMatrix(Translation);
	//	std::cout << glm::to_string(M) << std::endl;

		// cria um vetor de posi��o
	glm::vec4 Position(10, 10, 10, 1); // posi��o
	// cria um vetor de dire��o
	glm::vec4 Direction(10, 10, 10, 0); // dire��o
	// aplica a transla��o no vetor de posi��o
	Position = Translation * Position;
	// aplica a transla��o no vetor de dire��o
	// aplicar transla��o no vetor de dire��o 
	// n�o tem efeito
	Direction = Translation * Direction;

	std::cout << glm::to_string(Position) << std::endl;
	// vetor n�o foi alterado com a transla��o
	std::cout << glm::to_string(Direction) << std::endl;

}

void ScaleMatrix() {
	// pula linha
	std::cout << std::endl;
	// mensagem
	std::cout << "Scale Matrix" << std::endl;
	// cria a matriz 4x4 identidade - I
	glm::mat4 I = glm::identity<glm::mat4>();
	// cria o vetor de escala
	// qtde que vamos escalar (dobrar em x, y e z)
	glm::vec3 ScaleAmount(2, 2, 2);
	// cria a matriz de escala
	glm::mat4 Scale = glm::scale(I, ScaleAmount);
	// imprime
	PrintMatrix(Scale);
	// cria o vetor de posi��o
	glm::vec4 Position(100, 100, 0, 1);
	// cria o vetor de dire��o
	glm::vec4 Direction(100, 100, 0, 0);

	// escala o vetor de posi��o
	Position = Scale * Position;
	// escala o vetor de dire��o
	Direction = Scale * Direction; // tem magnitude
	// imprime
	std::cout << glm::to_string(Position) << std::endl;
	// o vetor de dire��o tamb�m sofre altera��o de 
	// escala
	std::cout << glm::to_string(Direction) << std::endl;
}

void RotationMatrix() {
	// pula linha
	std::cout << std::endl;
	// mensagem
	std::cout << "Rotation Matrix" << std::endl;
	// matriz identidade
	glm::mat4 I = glm::identity<glm::mat4>();
	// �ngulo de rota��o
	// 1.57 radianos
	constexpr float Angle = glm::radians(90.0f); // graus para radianos
	glm::vec3 Axis{ 0,0,1 }; // eixo de rota��o z
	// cria a matriz de rota��o
	glm::mat4 Rotation = glm::rotate(I, Angle, Axis);

	// cria o vetor de posi��o
	glm::vec4 Position{ 100, 0, 0, 1 };
	glm::vec4 Direction{ 100, 0, 0, 0 };

	// rota��o
	Position = Rotation * Position;
	Direction = Rotation * Direction;

	// a rota��o altera a posi��o
	std::cout << glm::to_string(Position) << std::endl;
	// a rota��o altera a dire��o
	std::cout << glm::to_string(Direction) << std::endl;
}

void ComposedMatrices() {
	// pula linha
	std::cout << std::endl;
	// mensagem
	std::cout << "Composed Matrix" << std::endl;
	// matriz identidade
	glm::mat4 I = glm::identity<glm::mat4>();
	// matriz transla��o
	glm::vec3 T{ 0, 10, 0 };//desloca 10 em y
	glm::mat4 TranslationMatrix = glm::translate(I,T);
	std::cout << "Translation Matrix" << std::endl;
	PrintMatrix(TranslationMatrix);
	//matriz de rota��o
	//converte angulos em radianos - 0,79 radianos
	constexpr float Angle = glm::radians(45.0f); //angulo de rota��o de 45 graus
	glm::vec3 Axis{ 0, 0, 1 }; //eixo de rota��o
	glm::mat4 RotationMatrix = glm::rotate(I, Angle, Axis);
	std::cout << "Rotation Matrix" << std::endl;
	PrintMatrix(RotationMatrix);
	//matriz de escala
	glm::vec3 ScaleAmount(2, 2, 0);
	glm::mat4 ScaleMatrix = glm::scale(I, ScaleAmount);//dobra largura dobra altura
	std::cout << "Scale Matrix" << std::endl;
	PrintMatrix(ScaleMatrix);
	// cria um vetpr de posi��o
	glm::vec4 Position(1,1,0,1);
	// cria um vetor de dire��o
	glm::vec4 Direction(1, 1, 0, 0);

	// primeiro escala, segundo rotaciona e depois translada
	// multiplicacao de matrizes n�o � comutativa, a ordem importa
	glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;	//vai fazer da direita pra esquerda
	std::cout << "Model Matrix" << std::endl;
	PrintMatrix(ModelMatrix);


	//aplicando a composi��o no vetor de posi��o

	Position = ModelMatrix * Position;
	std::cout << glm::to_string(Position) << std::endl;
	Direction = ModelMatrix * Direction;
	std::cout << glm::to_string(Direction) << std::endl;

}

void ModelViewProjection() {
	std::cout << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Model, View and Projection" << std::endl;
	std::cout << "==========================" << std::endl;

	// Model � a matriz formada pelas transforma��es de 
	// Escala, Rota��o e Transla��o!
	glm::mat4 Model = glm::identity<glm::mat4>();

	// View - onde est� a c�mera para ver o modelo
	glm::vec3 Eye{ 0.0f, 0.0f, 10.0f };// posi��o
	glm::vec3 Center{ 0.0f, 0.0f, 0.0 };//dire��o
	// 0 , -1, 0 vendo de cabe�a para baixo
	glm::vec3 Up{ 0.0f, 1.0f, 0.0f };//orienta��o
	glm::mat4 View = glm::lookAt(Eye, Center, Up);

	std::cout << "View: " << std::endl;
	PrintMatrix(View);

	//angulo de vis�o 45�
	constexpr float FoV = glm::radians(45.0f);
	//raz�o de aspecto
	const float AspectRatio = 800.0f / 600.0f;
	//distancia do plano perto da camera
	const float Near = 0.001f; //proximo de 0
	//distancia do plano longe da camera
	const float Far = 1000.0f; // isso � 1
	glm::mat4 Projection = glm::perspective(FoV, AspectRatio, Near, Far);

	std::cout << "Projection: " << std::endl;
	PrintMatrix(Projection);

	glm::mat4 ModelViewProjection = Projection * View * Model;

	std::cout << "ModelViewProjection: " << std::endl;
	PrintMatrix(ModelViewProjection);

	glm::vec4 Position{ 0, 0, 0, 1 };
	Position = ModelViewProjection * Position;
	std::cout << glm::to_string(Position) << std::endl;
}

int main() {
	std::cout << "Ol� matrizes" << std::endl;
	//TranslationMatrix();
	//ScaleMatrix();
	//RotationMatrix();
	//ComposedMatrices();
	ModelViewProjection();
}