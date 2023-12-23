/**
 * OpenGL Boilerplate
 * 
 * Advanced
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window/Window.h"
#include "input/Input.h"

int main(){

	Window window = Window( 1280, 720, "OpenGL Window" );
	Input input = Input( window.getWindow() );

	while( window.isRunning() ){

		window.ErrorHandler();

		//Clear the screen
		glClearColor( 255.0f, 255.0f, 255.0f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		glfwSwapBuffers( window.getWindow() );
		glfwPollEvents();
	}
	return 0;
}