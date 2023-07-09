#pragma once

namespace Rendering
{
	struct Vertex
	{
	public:
		float position[3];

		Vertex SetPosition(float x, float y, float z) 
		{
			position[0] = x;
			position[1] = y;
			position[2] = z;
			return *this;
		}
	};
}