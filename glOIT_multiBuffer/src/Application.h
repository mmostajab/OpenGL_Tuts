#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "helper.h"

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


// STD
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "Camera.h"

#define MAX_FRAMEBUFFER_WIDTH   2048
#define MAX_FRAMEBUFFER_HEIGHT  2048

#define NUM_FRAME_BUFFERS       4

struct PlyObjVertex
{
  glm::vec3 pos;
  glm::vec3 normal;
};

class Application {
public:
    Application();

    void init(const unsigned int& width, const unsigned int& height);
    void init();
    void run();
    void shutdown();

    ~Application();

private:
    void create();
    void update(float time, float elapsedTime);
    void draw();

    void compileShaders();

    void prepare_framebuffer();
    void prepare_Order_Independent_Transparency();
    void draw_framebuffer(const int& idx);
    void draw_Order_Independent_Transparency(const int& idx);
    void combine_Lists_Order_Independent_Transparency();
    void apply_transparency();

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

private:
    static GLFWwindow* m_window;
    glm::mat4 m_projmat, m_viewmat, m_worldmat, m_inv_viewmat;
    static unsigned int m_width, m_height;
    GLuint m_coord_system_program;
    GLuint m_transformation_buffer, m_lighting_buffer, m_general_buffer;
   
	  // scene objects
	  static Camera m_camera;

    // Rendering buffer
    static int  rendering_state;
    static int  render_fbo_idx;
    GLuint      combine_program;
    GLuint      ssao_program;
    GLuint      render_fbo[NUM_FRAME_BUFFERS];
    GLuint      fbo_textures[NUM_FRAME_BUFFERS][3];
    GLuint      quad_vao;

    // Order Independence Transparency
    static int  comp_shaders;
    static float transparency_value;
    GLuint resolve_order_independence_program;
    GLuint combine_order_independence_lists_program;
    GLuint blend_order_independence_buffers_program;
    size_t total_pixels;
    GLuint head_pointer_texture[NUM_FRAME_BUFFERS];
    GLuint head_pointer_clear_buffer;
    GLuint linked_list_buffer[NUM_FRAME_BUFFERS], linked_list_texture[NUM_FRAME_BUFFERS];
    GLuint atomic_counter_buffer[NUM_FRAME_BUFFERS];
    GLuint render_opaque_fbo;
    GLuint fbo_opaque_texture;

    // Ply buffers
    GLuint ply_program;
    std::vector<PlyObjVertex> vertices[NUM_FRAME_BUFFERS];
    std::vector<unsigned int> indices[NUM_FRAME_BUFFERS];
    GLuint                    vertices_buffer[NUM_FRAME_BUFFERS], indices_buffer[NUM_FRAME_BUFFERS];

    // Main renderer
    GLuint      main_render_fbo;
    GLuint      main_fbo_textures[3];
    GLuint      main_head_pointer_texture;
    GLuint      main_linked_list_buffer, main_linked_list_texture;
    GLuint      main_atomic_counter_buffer;

    std::vector<PlyObjVertex> vertices2;
    std::vector<unsigned int> indices2;
    GLuint vertices_buffer2,  indices_buffer2;
    void drawPly(const int& idx);
    void drawPly2();
};

#endif