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

		const int squads = maxParticles;

		vao = vbo = ibo = 0;

		vertexes = new Rendering::Vertex[squads * 4];
		indices = new uint32_t[squads * 6];

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

		shader = new Rendering::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());
		shader->Use();
	}

	ParticlesRenderer::~ParticlesRenderer()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);

		delete shader;
		delete[] indices;
		delete[] vertexes;
	}

	void ParticlesRenderer::Render()
	{
		const int squads = maxParticles;

		for (int i = 0; i < squads; i++)
		{
			Particle* particle = particles->at(i);
			glm::vec3 position = particle->GetPosition();

			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, position);
			model = glm::rotate(model, particle->GetRotation(), settings->rotationVector);
			model = glm::scale(model, Math::Lerp(settings->startScale, settings->endScale, particle->GetLifetimeAspect()));

			glm::vec4 color = Math::Lerp(settings->startColor, settings->endColor, particle->GetLifetimeAspect());

			float distance = abs(position.z);
			if (distance < settings->nearHideDistance)
			{
				float nearT = Math::InverseLerp<float>(settings->nearHideDistanceMin, settings->nearHideDistance, distance);
				color.a = Math::Lerp<float>(0, color.a, nearT);
			}

			if (distance > settings->farHideDistance)
			{
				float farT = Math::InverseLerp<float>(settings->farHideDistance, settings->farHideDistanceMax, distance);
				color.a = Math::Lerp<float>(color.a, 0, farT);
			}

			for (int j = 0; j < 4; j++) 
			{
				vertexes[i * 4 + j].model = model;
				vertexes[i * 4 + j].color = color;
			}
		}

		vao = vbo = ibo = 0;
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ibo);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, squads * 4 * sizeof(Vertex), vertexes, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, squads * 6 * sizeof(uint32_t), indices, GL_STATIC_DRAW);

		//data layout
		//1st -> index
		//2nd -> number of components (coordinates, like x y z w)
		//5th -> stride[bytes]: offset between vertexes (if 1 vertex has 3 elements - offset must be 3 * sizeof(type)) 
		//6th -> offset[bytes] to the initial element (if vertex has position and colors and you need to take colors)
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, color)));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, model));

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, model) + 1 * sizeof(glm::vec4)));

		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, model) + 2 * sizeof(glm::vec4)));

		glEnableVertexAttribArray(5);
		glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(offsetof(Vertex, model) + 3 * sizeof(glm::vec4)));


		float screenAspect = screen->GetScreenAspect();

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(90.0f), screenAspect, 0.1f, 1000.0f);

		glm::mat4 view = glm::mat4(1.0f);
		shader->setMat4("projection", projection);
		shader->setMat4("view", view);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, squads * 6, GL_UNSIGNED_INT, 0);

		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
	}
}