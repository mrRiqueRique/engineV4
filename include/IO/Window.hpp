#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

struct color{
    float r, g, b;
    float a = 1.0f;
};

struct windowParams{
    bool fullscreen = true;
    int width;
    int height;
    const char *windowName = "Window";
    bool hasHeader = true;
    unsigned int closeButton = GLFW_KEY_ESCAPE;
    color clearColor = color(0.0f, 0.0f, 0.0f);
};

class Window{
    public:
        Window(const windowParams &params);
        ~Window();

        void turnFullScreen();
        void turnWindowed(int width, int height);
        void turnWindowed();
        
        void resizeTo(int width, int height);
        int getWidth(){ return width; }
        int getHeight(){ return height; }

        void switchHeader();

        void setCloseButton(unsigned int newButton);
        void setClearColor(color newColor);

        void close() { glfwSetWindowShouldClose(self, GLFW_TRUE); }
        void update() { glfwSwapBuffers(self); }
        void poll() { glfwPollEvents(); }
        void clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
        bool shouldClose() { return glfwWindowShouldClose(self); }

        GLFWwindow *getHandle(){ return self; }

    private:
        GLFWwindow *self = nullptr;
        int width, height;
        unsigned int closeButton;
        bool fullscreen;
};