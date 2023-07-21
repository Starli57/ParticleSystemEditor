#include "ParticlesRenderer.h"

namespace ParticleSystemEditor
{
	#define timer  Utilities::DI::Get<Time>()
	#define rand   Utilities::DI::Get<Random>()
	#define screen Utilities::DI::Get<ScreenSettings>()

	using namespace Rendering;

	ParticlesRenderer::ParticlesRenderer(ParticleSettings* settings, std::vector<Particle*>* particles)
	{
		this->settings = settings;
		this->particles = particles;

		vao = vbo = ibo = 0;

		shader = new Rendering::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());
		shader->Use();
	}

	ParticlesRenderer::~ParticlesRenderer()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);

		delete shader;
	}

	void ParticlesRenderer::Render()
	{

		const int squads = 10;

		Rendering::Vertex vertexes[squads * 4];
		uint32_t indices[squads * 6];

		for (int i = 0; i < squads; i++)
		{
			int vi = i * 4;
			vertexes[vi].position = glm::vec3(-0.5f, -0.5f, 0);
			vertexes[vi + 1].position = glm::vec3(-0.5f, 0.5f, 0);
			vertexes[vi + 2].position = glm::vec3(0.5f, 0.5f, 0);
			vertexes[vi + 3].position = glm::vec3(0.5f, -0.5f, 0);

			int ii = i * 6;
			indices[ii] = vi;
			indices[ii + 1] = vi + 1;
			indices[ii + 2] = vi + 2;
			indices[ii + 3] = vi + 2;
			indices[ii + 4] = vi + 3;
			indices[ii + 5] = vi;
		}

		glm::mat4 models[squads];
		for (int i = 0; i < squads; i++)
		{
			Particle* particle = particles->at(i);

			models[i] = glm::mat4(1.0f);
			models[i] = glm::translate(models[i], particle->GetPosition());
			models[i] = glm::rotate(models[i], particle->GetRotation(), settings->rotationVector);
			models[i] = glm::scale(models[i], Math::Lerp(settings->startScale, settings->endScale, particle->GetLifetimeAspect()));
		}

		for (int i = 0; i < squads; i++)
		{
			vertexes[i * 4].model = models[i];
			vertexes[i * 4 + 1].model = models[i];
			vertexes[i * 4 + 2].model = models[i];
			vertexes[i * 4 + 3].model = models[i];
		}

		vao = vbo = ibo = 0;
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ibo);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//data layout
		//1st -> index
		//2nd -> number of components (coordinates, like x y z w)
		//5th -> stride[bytes]: offset between vertexes (if 1 vertex has 3 elements - offset must be 3 * sizeof(type)) 
		//6th -> offset[bytes] to the initial element (if vertex has position and colors and you need to take colors)
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, model));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, model) + 1 * sizeof(glm::vec4)));

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, model) + 2 * sizeof(glm::vec4)));

		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, model) + 3 * sizeof(glm::vec4)));


		float screenAspect = screen->GetScreenAspect();

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(90.0f), screenAspect, 0.1f, 1000.0f);

		glm::mat4 view = glm::mat4(1.0f);
		shader->setMat4("projection", projection);
		shader->setMat4("view", view);


		for (int i = 0; i < particles->size(); i++) 
		{
			Particle* particle = particles->at(i);

			glm::vec4 color = Math::Lerp(settings->startColor, settings->endColor, particle->GetLifetimeAspect());

			shader->setVec4("inColor", color);
		}

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, squads * 6, GL_UNSIGNED_INT, 0);

		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);

		//for (Particle* particle : *particles)
		//{
		//	particle->Render();
		//}
	}
}