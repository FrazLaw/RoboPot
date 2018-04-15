#include "GUI.h"

GUI::GUI()
{
}


GUI::~GUI()
{
}
 //Checks to see if command file is readable
bool GUI::Check_Cmd(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	return file.good();
}
//Reads command file and returns pot destination
char GUI::Read_Cmd(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	file.get(cmd);
	return cmd;
}
//Writes to file to inform GUI of present location
void GUI::Send(const std::string& filename, const std::string& message)
{
	std::ifstream file;
	file.open(filename.c_str());
}
