#pragma once

#include <glm/vec3.hpp>

namespace Rendering
{
	struct Vertex
	{
	public:
		glm::vec3 position;
		glm::mat4 model;
	};
}