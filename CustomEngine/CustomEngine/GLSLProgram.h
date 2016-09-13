#pragma once

#include <string>
#include <GL\glew.h>
#include <fstream>

#include "Errors.h"

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string& vertexShaderFilePath,const std::string& fragmentShaderFilePath);
	void linkShaders();
	void addAttribute(const std::string& attributeName);
	void use();
	void unuse();

private:
	GLuint _programID;
	GLuint _fragmentShaderID;
	GLuint _vertexShaderID;
	int _numAttributes;

	void compileShader(const std::string&filePath, GLuint id);

};

