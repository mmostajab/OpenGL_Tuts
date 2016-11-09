#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "helper.h"

//#include <Windows.h>

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
#include <complex>
#include <time.h>
#include <fstream>
#include <iostream>

#include "Camera.h"
#include "ArcSegment.h"
#include "ArcTriangle.h"
#include "ArcQuad.h"
#include "AntTweakBarGUI.h"
#include "Evaluator.h"

using namespace ArcRep;

extern float                 mult;

#define MAX_FRAMEBUFFER_WIDTH 2048
#define MAX_FRAMEBUFFER_HEIGHT 2048

static clock_t               last_change_clock = clock();

class Application {
public:
    Application();

	void init(const unsigned int& width, const unsigned int& height, HGLRC mainWindowContext);
	void init(const unsigned int& width, const unsigned int& height);
  void init();
  void run();
	void run_onestep();
  void shutdown();

  ~Application();

// private:
public:
    void create();
    void update(float time, float elapsedTime);
    void draw(bool doUpdateGLBuffers);

    void compileShaders();

    void prepare_framebuffer();

    void setupOpenGLSpecs();

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

    static bool wireframe;

//private:
public:
    static GLFWwindow*  m_window;
    glm::mat4           m_projmat, m_viewmat, m_worldmat, m_inv_viewmat, m_mvp_mat;
    static unsigned int m_width, m_height;
    static AntTweakBarGUI      m_gui;
    
    GLuint              m_transformation_buffer, m_lighting_buffer, m_general_buffer;
   
    // shaders
    GLuint m_simple_program;
    GLuint m_coord_system_program;
    GLuint m_background_program;

	// scene objects
	static Camera m_camera;

    // Rendering buffer
    static int  rendering_state;
    GLuint      render_fbo;
    GLuint      fbo_textures[3];
    GLuint      quad_vao;

    Evaluator<int64_t, float> trianglesPerSecondEvaluator;
    Evaluator<int64_t, float> memUsagePerTriangleEvaluator;
    Evaluator<int64_t, float> renderTimePerTriangleEvaluator;
    Evaluator<int64_t, float> drawTimePerTriangleEvaluator;
    Evaluator<int64_t, float> uploadTimePerTriangleEvaluator;
    Evaluator<float, float>   pipelinePerTrianglesEvaluator;
    Evaluator<float, int64_t> trianglesPerZoomFactorEvaluator;
    

	std::vector<ArcSegment>  arcSegments;
  std::vector<ArcTriangle> arcTriangles;
  std::vector<ArcQuad>     arcQuads;

  std::streambuf* m_orig_cout_buf;
  std::ofstream m_logFile;

  const glm::vec3 green_color, red_color;

  // Measurments
  int    nTriangles;
  float  memUsage;


  // Buffer comibination
  enum {
    TRIANGLE_FAN_BUFFER_ID                  = 0,
    TRIANGLE_STRIP_BUFFER_ID                = 1,
    NUMBER_OF_REQUIRED_COMBINATION_BUFFERS  = 2,
  };


  // Update the arc primitives every frame
  void enableUpdateEveryFrame();
  void disableUpdateEveryFrame();
  bool updateEveryFrame;

  // Separate / Combined GL Buffers
  void disableSeparateGLBuffers();
  void enableSeparateGLBuffers();
  bool combineArcPrimitiveBuffers;
  std::array<std::vector<Vertex>, NUMBER_OF_REQUIRED_COMBINATION_BUFFERS>                     primitiveVertices;
  std::array<std::vector<DrawArraysIndirectCommand>, NUMBER_OF_REQUIRED_COMBINATION_BUFFERS>  indirectDrawCmds;
  std::array<GLuint, NUMBER_OF_REQUIRED_COMBINATION_BUFFERS>                                  allArcPrimitiveTrianglesBuffer;
  std::array<GLuint, NUMBER_OF_REQUIRED_COMBINATION_BUFFERS>                                  allArcPrimitiveTrianglesIndirectDrawBuffer;
  std::array<size_t, NUMBER_OF_REQUIRED_COMBINATION_BUFFERS>                                  allArcPrimitivesBufferSizeNumVertices;
  std::array<size_t, NUMBER_OF_REQUIRED_COMBINATION_BUFFERS>                                  allArcPrimitivesBufferSizeNumCmds;
  
  void updateAllArcPrimitivesSingleBuffer();
};

#endif