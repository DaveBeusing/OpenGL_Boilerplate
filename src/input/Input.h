/**
 * Input.h 
 * Copyright (c) 2023 Dave Beusing 
 * MIT License - https://opensource.org/license/mit/
 */

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window/Window.h"

class Input {

	private:
		static GLFWwindow *m_window;
		static void KeyEventCallback( GLFWwindow* m_window, int key, int scancode, int action, int mods ){

			// Escape = close Window
			if( glfwGetKey( m_window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ){
				glfwSetWindowShouldClose( m_window, true );
			}

			// Key f = Fullscreen
			if( glfwGetKey( m_window, GLFW_KEY_F ) == GLFW_PRESS ){
				if( glfwGetWindowAttrib( m_window, GLFW_MAXIMIZED) ){
					//if is maximized then restore
					glfwRestoreWindow( m_window );
				}
				else {
					glfwMaximizeWindow( m_window );
				}
			}

			// Key 1 = Wireframe
			if( glfwGetKey( m_window, GLFW_KEY_1 ) == GLFW_PRESS ){
				glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
				
			}

			// Key 2 = Normal view
			if( glfwGetKey( m_window, GLFW_KEY_2 ) == GLFW_PRESS ){
				glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
			}
		};

	public:
		Input( GLFWwindow *_window ){
			GLFWwindow *m_window = _window;
			glfwSetKeyCallback( m_window, KeyEventCallback );
		};
		~Input(){};

};