// ImGui - standalone example application for GLFW + OpenGL 3, using programmable pipeline
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan graphics context creation, etc.)
// (GL3W is a helper library to access OpenGL functions since there is no standard header to access modern OpenGL functions easily. Alternatives are GLEW, Glad, etc.)

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include <stdio.h>
// This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include "GLES3/gl3.h"
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}




// int main(int, char**)
// {

//     // Setup window
//     glfwSetErrorCallback(glfw_error_callback);
//     if (!glfwInit())
//         return 1;
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
// #if __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif
    
//     GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui GLFW+OpenGL3 example", NULL, NULL); //第三个参数是用来传输显示器的参数的 不写返回默认普通window
//     glfwMakeContextCurrent(window);
//     glfwSwapInterval(1); // Enable vsync
//     //gl3Init();
//     glfwInit();
//     // Setup ImGui binding
//     ImGui::CreateContext();
//     ImGuiIO& io = ImGui::GetIO(); (void)io;
//     //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
//     //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls
//     ImGui_ImplGlfwGL3_Init(window, true);

//     // Setup style
//     // ImGui::StyleColorsDark();
//     //ImGui::StyleColorsClassic();
//     ImGui::StyleColorsLight();
//     // Load Fonts
//     // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them. 
//     // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple. 
//     // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
//     // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
//     // - Read 'misc/fonts/README.txt' for more instructions and details.
//     // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
//     //io.Fonts->AddFontDefault();
//     // io.Fonts->AddFontFromFileTTF("./misc/fonts/Roboto-Medium.ttf", 16.0f);
//     io.Fonts->AddFontFromFileTTF("./misc/fonts/Cousine-Regular.ttf", 15.0f);
//     // io.Fonts->AddFontFromFileTTF("./misc/fonts/Consolas.ttf", 14.0f);
//     // io.Fonts->AddFontFromFileTTF("./misc/fonts/DroidSans.ttf", 16.0f);
//     // io.Fonts->AddFontFromFileTTF("./misc/fonts/Roboto-Medium.ttf", 10.0f);
//     //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
//     //IM_ASSERT(font != NULL);

//     bool show_demo_window = true;
//     bool show_another_window = false;
//     ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

//     // Main loop
//     while (!glfwWindowShouldClose(window))
//     {
//         // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
//         // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
//         // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
//         // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
//         glfwPollEvents();
//         ImGui_ImplGlfwGL3_NewFrame();

//         // 1. Show a simple window.
//         // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
//         {
//             static float f = 0.0f;
//             static int counter = 0;
//             ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
//             ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
//             ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

//             ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
//             ImGui::Checkbox("Another Window", &show_another_window);

//             if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
//                 counter++;
//             ImGui::SameLine();
//             ImGui::Text("counter = %d", counter);

//             ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//         }

//         // 2. Show another simple window. In most cases you will use an explicit Begin/End pair to name your windows.
//         if (show_another_window)
//         {
//             ImGui::Begin("Another Window", &show_another_window);
//             ImGui::Text("Hello from another window!");
//             if (ImGui::Button("Close Me"))
//                 show_another_window = false;
//             ImGui::End(); 
//         }

//         // 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
//         if (show_demo_window)
//         {
//             ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
//             ImGui::ShowDemoWindow(&show_demo_window);
//         }

//         // Rendering
//         int display_w, display_h;
//         glfwGetFramebufferSize(window, &display_w, &display_h);
//         glViewport(0, 0, display_w, display_h);
//         glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
//         glClear(GL_COLOR_BUFFER_BIT);
//         ImGui::Render();
//         ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
//         glfwSwapBuffers(window);
//     }

//     // Cleanup
//     ImGui_ImplGlfwGL3_Shutdown();
//     ImGui::DestroyContext();

//     glfwDestroyWindow(window);
//     glfwTerminate();

//     return 0;
// }
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>
static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f }
};

static const char* vertex_shader_text =
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";
static const char* fragment_shader_text =
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    // gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);
    // NOTE: OpenGL error checks have been omitted for brevity
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetAttribLocation(program, "vPos");
    vcol_location = glGetAttribLocation(program, "vCol");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(float) * 5, (void*) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(float) * 5, (void*) (sizeof(float) * 2));
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        mat4x4 m, p, mvp;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        mat4x4_identity(m);
        mat4x4_rotate_Z(m, m, (float) glfwGetTime());
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);
        glUseProgram(program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
}