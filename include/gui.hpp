#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h> 

class App
{
  public:

  GLFWwindow* window; 
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  App();
  ~App();

  void Run(void)
  {
    Startup();

    while(!glfwWindowShouldClose(window))
    {
      glfwPollEvents();

      // Start the Dear ImGui frame
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      Update(); 

      // Rendering
      ImGui::Render();
      int display_w, display_h;
      glfwGetFramebufferSize(window, &display_w, &display_h);
      glViewport(0, 0, display_w, display_h);
      glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
      glClear(GL_COLOR_BUFFER_BIT);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

      glfwSwapBuffers(window);
    }
  }
  virtual void Startup() = 0;
  virtual void Update() = 0;

  private:
};
