#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<regex>
#include "gui.hpp"

using namespace std;

class myApp : public App
{
  public:
  void Startup(void);
  void Update(void);
  ImGuiInputTextFlags flags = 0;
  string input_text = "";
};
