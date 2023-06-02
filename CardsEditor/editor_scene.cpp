
#include "editor_scene.h"
#include "shader.h"

namespace CardsEditor
{

	void EditorScene::Render() 
	{
		static char shaderLog[100];
		Graphics::Shader *defaultShader = new Graphics::Shader("default.vert", "default.frag", shaderLog);

		float vertexes[] = 
		{
		//   positions
		//   x   y   z
			-1, -1,  0,
			 0,  1,  0,
			 1, -1,  0
		};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// render the triangle
		defaultShader->Use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		delete defaultShader;
	}
}