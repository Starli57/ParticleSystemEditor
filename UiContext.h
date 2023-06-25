#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "IContext.h"

class UiContext : public IContext
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

	ImGuiIO* GetImguiIo();

private:
	ImGuiIO* _io;
};

