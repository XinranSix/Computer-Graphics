//
// Created by yaojie on 2023/4/17.
//
#pragma once

#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray {
private:
    unsigned int m_RendererID;
public:
    VertexArray();

    ~VertexArray();

    void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);

    void Bind() const;

    void Unbind() const;
};
