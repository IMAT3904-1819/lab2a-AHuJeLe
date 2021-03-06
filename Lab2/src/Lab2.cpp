// Lab2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <glad/glad.h>
#include "glfw3.h"
#include <iostream>


int main(int argc, char* argv[])
{
	/*
	std::cout << "Hello World" << std::endl;

	system("pause");
    return 0;
	*/

	// Initializing a window and letting the GLFW know that should target OpenGL version 4.3
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Creating window
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpeningAWindow", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Making new window as our current context, and then trying to initialise GLAD function ptrs
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	// We do this until we recieve a message to close the program
	while (!glfwWindowShouldClose(window))
	{
		// Make the screen greeen
		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swapping buffers such as draw to screen
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	glfwTerminate();
	return 0;

}

