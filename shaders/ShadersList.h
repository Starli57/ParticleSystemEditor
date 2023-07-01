#pragma once

#include <iostream>
#include <string>

class ShadersList
{
public:
	static const char* GetDefaultVertexPath() { return "shaders/default.vert"; }
	static const char* GetDefaultFragmentPath() { return "shaders/default.frag"; }
};