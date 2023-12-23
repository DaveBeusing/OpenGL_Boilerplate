/**
 * OpenGL Boilerplate
 * Window.h
 * Copyright (c) 2023 Dave Beusing
 * MIT License - https://opensource.org/license/mit/
 */
#pragma once


#include <iostream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Window {

	private:
		GLFWwindow *m_Window;
		const char *m_Title;
		int m_Width;
		int m_Height;
		float m_FPS;
		bool m_VSync;
		bool m_isInitialized;
		bool m_isFullscreen;
		bool m_isMaximized;
		bool m_isWireframe;
		int m_GLErrorCode;
		static void FramebufferSizeCallback( GLFWwindow *window, int width, int height );

	public:
		Window( int width, int height, const char *title );
		~Window();
		GLFWwindow *getWindow() const;
		void getOpenGLVersionInfo();
		double getFPS();
		glm::ivec2 getResolution();
		void setVSync( bool on );
		void setTitle( const char* title );
		void setSize( int width, int height );
		void ErrorHandler();
		bool isRunning();
		bool isFullscreen();
		bool isMaximized();
		bool isWireframe();
};