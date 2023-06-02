
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Graphics
{
	class Shader 
	{
	public:
		unsigned int id;

		Shader(const char* vertexPath, const char* fragmentPath, char* shaderlog);

		void Use();
		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;

	};
}
#endif