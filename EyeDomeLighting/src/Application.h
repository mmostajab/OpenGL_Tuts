#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "helper.h"

#include <Windows.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#include <gl/glew.h>
//#include <../src/glew.c>
#include <GLFW/glfw3.h>
#include <GLFW\glfw3native.h>
#include <glm/glm.hpp>


// STD
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "Camera.h"

#define MAX_FRAMEBUFFER_WIDTH 2048
#define MAX_FRAMEBUFFER_HEIGHT 2048

#include <glm/glm.hpp>
struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
};

class Application {
public:
    Application();

	void init(const unsigned int& width, const unsigned int& height, HGLRC mainWindowContext);
	void init(const unsigned int& width, const unsigned int& height);
    void init();
    void run();
    void shutdown();

    ~Application();

// private:
public:
    void create();
    void update(float time, float elapsedTime);
    void draw();

    void compileShaders();

  GLuint simple_program;

private:
    static void EventMouseButton(GLFWwindow* window, int button, int action, int mods);
    static void EventMousePos(GLFWwindow* window, double xpos, double ypos);
    static void EventMouseWheel(GLFWwindow* window, double xoffset, double yoffset);
    static void EventKey(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void EventChar(GLFWwindow* window, int codepoint);

    // Callback function called by GLFW when window size changes
    static void WindowSizeCB(GLFWwindow* window, int width, int height);
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static bool m_controlKeyHold;
    static bool m_altKeyHold;
    static bool m_w_pressed, m_s_pressed, m_a_pressed, m_d_pressed, m_q_pressed, m_e_pressed;
    static bool m_mouse_left_drag, m_mouse_middle_drag, m_mouse_right_drag;

//private:
public:
    static GLFWwindow* m_window;
    glm::mat4 m_projmat, m_viewmat, m_worldmat, m_inv_viewmat;
    static unsigned int m_width, m_height;
    GLuint m_coord_system_program;
    GLuint m_transformation_buffer, m_lighting_buffer;
   
	// scene objects
	static Camera m_camera;

	void createFrameBuffer();
	void loadfile(std::string filename, std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
	void createMeshBuffer();
	void drawMesh();
	GLuint m_frameBuffer;
	GLuint m_fbo_textures[3];

	GLuint m_meshRenderProgram;
	GLuint m_meshIndicesBuffer;
	GLuint m_meshVerticesBuffer;
	unsigned int m_meshTriangleCount;

	GLuint m_eyeDomeLightingProgram;
	GLuint m_quadBuffer;
};

#endif