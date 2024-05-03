#include "main.hpp"
#include "imgui.h"

void myApp::Startup(void)
{
}

void myApp::Update(void)
{
  ImGui::Begin("Input text");                          // Create a window called "Input text" and append into it.
  ImGui::TextWrapped("%s", &input_text[0]);
  ImGui::End();

  ImGui::Begin("Matches");
  ImGui::Text("The matchs are:");
  ImGui::End();
}
