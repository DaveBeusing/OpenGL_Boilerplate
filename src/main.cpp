/**
 * OpenGL Boilerplate
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void FramebufferSizeCallback( GLFWwindow* window, int width, int height ){
	std::cout << "width: " << width << " height: " << height << std::endl;
	glViewport( 0, 0, width, height );
}

void KeyEventCallback( GLFWwindow* window, int key, int scancode, int action, int mods ){
	if( key == GLFW_KEY_E && action == GLFW_PRESS ){
		std::cout << "You pressed the e key!" << std::endl;
	}
}

const int windowWidth = 1280;
const int windowHeight = 720;
const char* windowTitle = "GLFW GLAD OpenGL Boilerplate";

int main(){
	if( !glfwInit() ){
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	glfwWindowHint( GLFW_SAMPLES, 4 );//4x MSAA (Multisample anti-aliasing)
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	GLFWwindow* window = glfwCreateWindow( windowWidth, windowHeight, windowTitle, nullptr, nullptr );
	if( window == nullptr ){
		std::cout << "Failed to open GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent( window );
	if( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) ){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//Register Callbacks -> glfwPollEvents
	glfwSetKeyCallback( window, KeyEventCallback);
	glfwSetFramebufferSizeCallback( window, FramebufferSizeCallback );
	glViewport( 0, 0, windowWidth, windowHeight );
	while( !glfwWindowShouldClose( window ) ){
		//Clear the screen
		glClearColor( 250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );
		glfwSwapBuffers( window );
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}