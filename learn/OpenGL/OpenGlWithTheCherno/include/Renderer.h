//
// Created by yaojie on 2023/4/17.
//

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); \
    x;                            \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char *function, const char *file, int line);
