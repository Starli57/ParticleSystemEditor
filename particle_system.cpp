
#include "particle_system.h"
#include "shader.h"
#include "shaders_list.h"

namespace ParticleSystemEditor
{

	void ParticleSystem::Render() 
	{
		Graphics::Shader *defaultShader = new Graphics::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());

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

		defaultShader->Use();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		delete defaultShader;
	}
}