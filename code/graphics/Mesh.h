#pragma once

#include <iostream>
#include <vector>
#include "triangle.h"

namespace Graphics
{
	struct Mesh
	{
	public:
		std::vector<Triangle> triangles;
	};
}