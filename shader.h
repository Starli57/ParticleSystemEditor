
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "logger.h"
#include "di.h"

namespace Graphics
{
	class Shader 
	{
	public:
		unsigned int id;

		Shader(const char* vertexPath, const char* fragmentPath);

		void Use();
		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;

	};
}
#endif