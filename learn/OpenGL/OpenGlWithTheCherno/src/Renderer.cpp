//
// Created by yaojie on 2023/4/17.
//


#include "Renderer.h"

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char *function, const char *file, int line) {

    while (GLenum error = glGetError()) {
        fmt::print("[OpenGL Error] ({}): {} {} {}\n", error, function, file, line);
        return false;
    }
    return true;
}