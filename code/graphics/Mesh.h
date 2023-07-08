#pragma once

#include <iostream>
#include <vector>
#include "triangle.h"

namespace Graphics
{
	struct mesh
	{
	public:
		std::vector<Triangle> triangles;
	};
}