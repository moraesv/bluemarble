#include <iostream>
#include <glm/glm.hpp>

#include <glm/gtx/string_cast.hpp>

int main() {

	glm::vec3 V(1, 2, 3);

	// definindo a sa�da padr�o
	std::cout << "Boa noite, j� sabemos C++" << std::endl;
	std::cout << glm::to_string(V) << std::endl;
	return 0;
}