
#include "Particle.h"


namespace ParticleSystemEditor
{
	Particle::Particle() : Particle(glm::vec3(0, 0, 0)) {}

	Particle::Particle(const glm::vec3 startPosition) 
	{
		shader = new Graphics::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());
		position = new glm::vec3(startPosition);
	}

	Particle::~Particle() 
	{
		delete position;
		delete shader;
	}

	void Particle::Render() 
	{
		float vertexes[] =
		{
			//   positions
			//   x      y      z
				-0.5f, -0.5f,  0,
				-0.5f,  0.5f,  0,
				 0.5f,  0.5f,  0,
				 0.5f, -0.5f,  0
		};

		uint32_t indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		unsigned int VAO, VBO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		shader->Use();

		// create transformations
		glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		glm::mat4 projection = glm::mat4(1.0f);

		float widthHeightAspect = 1;
		projection = glm::perspective(glm::radians(90.0f), widthHeightAspect, 0.1f, 1000.0f);
		view = glm::translate(view, *position);
		view = glm::rotate(view, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

		// pass transformation matrices to the shader
		shader->setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		shader->setMat4("view", view);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0, 0, 0));
		float angle = 10;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		shader->setMat4("model", model);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

}