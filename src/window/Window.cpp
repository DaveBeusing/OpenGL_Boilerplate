/**
 * OpenGL Boilerplate
 * Window.cpp
 * Copyright (c) 2023 Dave Beusing
 * MIT License - https://opensource.org/license/mit/
 */

#include "window/Window.h"

Window::Window( int width, int height, const char *title ){

	int m_Width = width;//1280;
	int m_Height = height;//720;
	bool m_isFullscreen = false;
	bool m_isMaximized = false;
	bool m_isWireframe = false;
	bool m_VSync = true;
	const char *m_Title = title;// "OpenGL Window";

	if( !glfwInit() ){
		std::cout << "Failed to initialize GLFW" << std::endl;
		exit(-1);
	}

	glfwWindowHint( GLFW_SAMPLES, 4 );//4x MSAA (Multisample anti-aliasing)
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	if( !monitor ){
		std::cout << "Failed to get primary monitor" << std::endl;
		exit(-1);
	}

	const GLFWvidmode* videomode = glfwGetVideoMode( monitor );
	if( !videomode ){
		std::cout << "Failed to get video mode of primary monitor." << std::endl;
		exit(-1);
	}

	std::cout << "Monitor size: " << videomode->width << "x" << videomode->height << std::endl;

	//minimum 300x200
	m_Width = glm::clamp( videomode->width / 2, 300, INT_MAX );
	m_Height = glm::clamp( videomode->height / 2, 200, INT_MAX );

	std::cout << "WxH: " << m_Width << "x" << m_Height << std::endl;
	std::cout << "WindowTitle: " << m_Title << std::endl;

	m_Window = glfwCreateWindow( m_Width, m_Height, m_Title, nullptr, nullptr );
	if( m_Window == nullptr ){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent( m_Window );

	//callbacks
	glfwSetFramebufferSizeCallback( m_Window, FramebufferSizeCallback );

	if( !gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) ){
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}

	glViewport( 0, 0, m_Width, m_Height );

	std::cout << "isVSync: " << m_VSync << std::endl;

	if( m_VSync ){
		glfwSwapInterval(1);
	}
	else {
		glfwSwapInterval(0);
	}

	// set aspect ration avoid stretching if window is resized
	glfwSetWindowAspectRatio( m_Window, 16, 9 );

	// Set color of screen (red, green, blue, alpha)
	glClearColor( 0.55f, 0.55f, 0.55f, 1.0f );

	//clean buffers and assign new color
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	//enable depth testing, OpenGL can figure which shape is in front
	glEnable( GL_DEPTH_TEST );

	// swap to new colored buffer
	glfwSwapBuffers( m_Window );

	// we are done initializing
	m_isInitialized = true;
	std::cout << "Window::isInitialized::true" << std::endl;
	getOpenGLVersionInfo();
}


GLFWwindow *Window::getWindow() const {
	return m_Window;
}


Window::~Window(){
	if( m_Window != nullptr ){
		glfwDestroyWindow( m_Window );
	}
	if( m_isInitialized ){
		glfwTerminate();
	}
	std::cout << "Window::~Window" << std::endl;
}


void Window::getOpenGLVersionInfo(){
	std::cout << "Version: " << glGetString( GL_VERSION ) << std::endl;
	std::cout << "Vendor: " << glGetString( GL_VENDOR ) << std::endl;
	std::cout << "Renderer: " << glGetString( GL_RENDERER ) << std::endl;
	std::cout << "Vendor: " << glGetString( GL_SHADING_LANGUAGE_VERSION ) << std::endl;
}


double Window::getFPS(){
	static double previousSeconds = glfwGetTime();
	static int frameCount;
	double currentSeconds = glfwGetTime();
	double elapsedSeconds = currentSeconds - previousSeconds;
	if( elapsedSeconds > 0.25 ){
		previousSeconds = currentSeconds;
		double m_FPS = (double) frameCount / elapsedSeconds;
		frameCount = 1;
		return m_FPS;
	}
	frameCount++;
	return m_FPS;
}


glm::ivec2 Window::getResolution(){
	return glm::ivec2( m_Width, m_Height );
}


void Window::setVSync( bool on ){
	if( on ){
		m_VSync = true;
		glfwSwapInterval(1);
	}
	else {
		m_VSync = false;
		glfwSwapInterval(0);
	}
}


void Window::setTitle( const char* title ){
	glfwSetWindowTitle( m_Window, title );
}


void Window::setSize( int width, int height ){
	glfwSetWindowSize( m_Window, width, height );
}


void Window::FramebufferSizeCallback( GLFWwindow *window, int width, int height ){
	std::cout << "FramebufferSizeCallback Width: " << width << " Height: " << height << std::endl;
	glViewport( 0, 0, width, height );
}


bool Window::isRunning(){
	return ( !glfwWindowShouldClose( m_Window ) );
}


bool Window::isFullscreen(){
	return m_isFullscreen;
}


bool Window::isMaximized(){
	return m_isMaximized;
}


bool Window::isWireframe(){
	return m_isWireframe;
}


void Window::ErrorHandler(){
	m_GLErrorCode = glGetError();
	if( m_GLErrorCode != 0 ){
		switch( m_GLErrorCode ){
			case 1280:
				std::cout << "GL_INVALID_ENUM. Enumeration parameter is not legal." << std::endl;
				break;
			case 1281:
				std::cout << "GL_INVALID_VALUE. Value parameter is not legal." << std::endl;
				break;
			case 1282:
				std::cout << "GL_INVALID_OPERATION. State for a command is not legal for its given parameters." << std::endl;
				break;
			case 1283:
				std::cout << "GL_STACK_OVERFLOW. Command would cause a stack overflow." << std::endl;
				break;
			case 1284:
				std::cout << "GL_STACK_UNDERFLOW. Command would cause a stack underflow." << std::endl;
				break;
			case 1285:
				std::cout << "GL_OUT_OF_MEMORY. Not enough memory left to execute command." << std::endl;
				break;
			case 1286:
				std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION. Command is not allowed on the current incomplete framebuffer." << std::endl;
				break;
			default:
				std::cout << "Unknown OpenGL error." << std::endl;
				break;	
		}
	}
}