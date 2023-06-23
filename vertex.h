#pragma once

namespace Graphics
{
	struct vertex
	{
	public:
		float position[3];

		vertex SetPosition(float x, float y, float z) 
		{
			position[0] = x;
			position[1] = y;
			position[2] = z;
			return *this;
		}
	};
}