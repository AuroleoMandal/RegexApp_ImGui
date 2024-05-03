#include"main.hpp"
#include "imgui.h"


//Returns the contents of a file in a string
string readFileToString(string& input_filename)
{
  ifstream file(input_filename, ios::binary);
  //Opens raw file

  if(!file.is_open())
  {
    cerr << "Cannot open file, please check name and permissions";
    exit(1);
  }
  string contents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
  //Gotta learn iterators

  file.close();
  return contents;
}

int main(int argc, char** argv)
{

  if(argc != 2)
  {
    cerr << "Invalid arguments";
    return 1;
  }

  string input_filename = argv[1]; 
  string input_filecontents = readFileToString(input_filename);

  myApp app;

  app.input_text = input_filecontents;
  cout << input_filename << " "; 
  app.flags = ImGuiInputTextFlags_AllowTabInput;
  app.Run();

  return 0;
}

