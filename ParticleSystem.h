#ifndef EDITOR_SCENE_H
#define EDITOR_SCENE_H

#include <glad/glad.h> 

#include "LogConsole.h"

#include "ParticleSystem.h"
#include "Shader.h"
#include "ShadersList.h"

namespace ParticleSystemEditor
{
	class ParticleSystem 
	{
	public:
		void Render();
	};
}
#endif