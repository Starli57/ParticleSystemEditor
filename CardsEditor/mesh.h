
#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include "triangle.h"

namespace Graphics
{
	struct mesh
	{
	public:
		std::vector<triangle> triangles;
	};
}
#endif