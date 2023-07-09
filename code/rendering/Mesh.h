#pragma once

#include <iostream>
#include <vector>
#include "triangle.h"

namespace Rendering
{
	struct Mesh
	{
	public:
		std::vector<Triangle> triangles;
	};
}