#include "SceneContext.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

void glfw_error_callback(int error, const char* description)
{
    MLogger->Log("GLFW Error description: " + std::string(description));
}

SceneContext::SceneContext()
{
    glfwSetErrorCallback(glfw_error_callback);
    glfwInit();

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

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);
    gladLoadGL();
}

SceneContext::~SceneContext()
{
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
}

void SceneContext::Prepare()
{
    ImVec4 clear_color = ImVec4(0.075f, 0.15f, 0.2f, 1.00f);
    int display_w, display_h;
    glfwGetFramebufferSize(GetWindow(), &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void SceneContext::Finalize()
{
    glfwSwapBuffers(GetWindow());
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