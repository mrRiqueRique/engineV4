#include "GLFW/glfw3.h"
#include "IO/Window.hpp"
#include <Core/Core.hpp>

Core::Core(){
    if(!glfwInit()){
        throw std::runtime_error("Failed to initialize glfw");
    }

    windowParams wParams = {
        .fullscreen = GLFW_FALSE,
        .width = 1080,
        .height = 720,
        .hasHeader = false
    };

    window = new Window(wParams);
    std::cout<<"created window successfully"<<std::endl;
}

Core::~Core(){
    delete window;
}

int Core::onStart(){
    return 1;
}

int Core::onLoop(){
    if(glfwGetKey(window->getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS){
        window->close();
        shouldEnd = true;
    }
    
    window->poll();
    window->clear();
    window->update();

    return 1;
}