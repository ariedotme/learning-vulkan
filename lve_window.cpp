#include "lve_window.hpp"
#include <stdexcept>

namespace lve {

LveWindow::LveWindow(int width, int height, std::string name)
    : width(width), height(height), windowName(name) {
  initWindow();
}

void LveWindow::initWindow() {
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
  }

  // set GLFW to not create an OpenGL context
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window =
      glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

LveWindow::~LveWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}
} // namespace lve
