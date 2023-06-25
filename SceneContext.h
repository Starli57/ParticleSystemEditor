#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h> 
#include <string>

#include "IContext.h"
#include "Di.h"
#include "Logger.h"

class SceneContext : public IContext
{
public:

	// Inherited via IContext
	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void BeforeRender() override;
	virtual void Render() override;
	virtual void AfterRender() override;
	virtual void BeforeUpdate() override;
	virtual void AfterUpdate() override;

	GLFWwindow* GetWindow();
	std::string GetGlslVersion();

private:

	GLFWwindow* _window;
};

