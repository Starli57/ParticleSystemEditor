#include "SceneContext.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

void glfw_error_callback(int error, const char* description)
{
    MLogger->Log("GLFW Error description: " + std::string(description));
}

void SceneContext::Initialize()
{
    glfwSetErrorCallback(glfw_error_callback);
    int initialized = glfwInit();

    if (!initialized)
    {
        return;
    }

#if defined(__APPLE__)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    _window = glfwCreateWindow(800, 800, "Cards editor", nullptr, nullptr);
    if (_window == nullptr)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);
    gladLoadGL();
}

void SceneContext::Finalize()
{
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
}

void SceneContext::Update()
{
}

void SceneContext::BeforeRender()
{
}

void SceneContext::Render()
{
}

void SceneContext::AfterRender()
{
}

void SceneContext::BeforeUpdate()
{
}

void SceneContext::AfterUpdate()
{
}

GLFWwindow* SceneContext::GetWindow()
{
    return _window;
}

std::string SceneContext::GetGlslVersion()
{
#if defined(__APPLE__)
    // GL 3.2 + GLSL 150
    return "#version 150";
#endif

    // GL 3.0 + GLSL 130
    return "#version 130";
}