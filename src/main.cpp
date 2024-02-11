#include <iostream>
#include "main.h"
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include "callbacks.h"
#include <GLFW/glfw3.h>

int main()
{

    /*
        Setting OpenGL configuration
    */

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                 // enabling OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // enabling OpenGL Core version
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // only enabled on MacOS
    #endif
    /*
        Setting GLFW Windo
    */

    GLFWwindow *window = glfwCreateWindow(900, 600, "Tetris", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << '\n';
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /*
        Setting up GLAD
    */

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << '\n';
        return -1;
    }

    glViewport(0, 0, 900, 600);                                        // setting the OpenGL window size
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // setting change window size callback

    /*
         Main loop
    */

    while (!glfwWindowShouldClose(window))
    {
        processInput(window); // Check for key pressing
        
        /*
            Rendering
        */

       glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // setting color as state
       glClear(GL_COLOR_BUFFER_BIT); // using state to set color

        
        glfwSwapBuffers(window); // function that render pixels
        glfwPollEvents();        // function that check events and call callbacks
    }

    /*
        Clear everything
    */

    glfwTerminate();
    return 0;
}