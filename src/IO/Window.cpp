#include "GLFW/glfw3.h"
#include <IO/Window.hpp>


Window::Window(const windowParams &params)
{
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    
    if(params.fullscreen){
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        width = mode->width;
        height = mode->height;
        self = glfwCreateWindow(width, height, params.windowName, monitor, NULL);
    } else{
        if(!params.hasHeader)
            glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        
        width = params.width;
        height = params.height;
        self = glfwCreateWindow(width, height, params.windowName, NULL, NULL);
    }
    
    if(!self)
        throw std::runtime_error("Falha ao inicializar janela");
    
    setClearColor(params.clearColor);
    setCloseButton(params.closeButton);
}

Window::~Window()
{
    glfwDestroyWindow(self);
}

void Window::turnFullScreen()
{
    
}

void Window::turnWindowed(int width, int height)
{
    
}

void Window::turnWindowed()
{
    
}

void Window::resizeTo(int newWidth, int newHeight)
{
    glfwSetWindowSize(self, newWidth, newHeight);
    width = newWidth;
    height = newHeight; 
}

void Window::switchHeader()
{
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
}

void Window::setCloseButton(unsigned int newButton)
{
    closeButton = newButton;
    // Trocar CallBack;
}

void Window::setClearColor(color newColor)
{
    glClearColor(newColor.r, newColor.g, newColor.b, newColor.a);
}
