# C++ OpenGL GLFW GLAD VSCode Boilerplate

This repo contains Boilerplate code I use as starting point to create OpenGL C++ projects.<br>
It contains GLFW, GLAD, GLM, stb and make use of VSCode and windows-gcc-x64.



#### Dependancies
[GLAD OpenGL 3.3 Core](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D3.3&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=compatibility&loader=on)<br>
[GLFW 3.3.8 Win64 Binaries](https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN64.zip)<br>
[stb single-file public domain libraries for C/C++](https://github.com/nothings/stb)<br>
[OpenGL Mathematics (GLM)](https://github.com/g-truc/glm)<br>


#### GLAD/GLFW implementation details
>Be sure to include GLAD before GLFW. The include file for GLAD includes the required OpenGL headers behind the scenes (like GL/gl.h) so be sure to include GLAD before other header files that require OpenGL (like GLFW).<br><br>
#include <glad/glad.h><br>
#include <GLFW/glfw3.h>


#### STB implementation details
>Define STB_IMAGE_IMPLEMENTATION before you include stb_image.h to create the implementation.<br><br>
 #define STB_IMAGE_IMPLEMENTATION<br>
 #include <stb/stb_image.h><br>


#### Project Structure
```
ProjectRoot
	/.vscode
	/bin
	/include
		/vendor
			/glad
				/glad.c
				/glad.h
			/GLFW
				/glfw3.h
				/glfw3native.h
			/glm
			/KHR
				/khrplatform.h
			/stb
				/stb_image_write.h
				/stb_image.h
	/lib
		/glfw3dll.lib
	/resources
	/src
		/main.cpp
```