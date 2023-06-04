#pragma once

#include <iostream>
#include <string>

class ShadersList
{
public:
	static const char* GetDefaultVertexPath() { return "default.vert"; }
	static const char* GetDefaultFragmentPath() { return "default.frag"; }
};