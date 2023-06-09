//
// Created by yaojie on 2023/4/17.
//

#include "Renderer.h"
#include <GL/glew.h>
#include <fmt/core.h>

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


void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
