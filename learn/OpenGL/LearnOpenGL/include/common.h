//
// Created by yaojie on 2023/4/29.
//

#ifndef COMMNO_H
#define COMMNO_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace yj {
    glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp) {
        auto zaxis = glm::normalize(position - target);
        auto xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
        auto yaxis = glm::normalize(glm::cross(zaxis, xaxis));

        glm::mat4 translation = glm::translate(glm::mat4{1.0f}, -position);

        glm::mat4 rotation = glm::mat4(1.0f);

        rotation[0][0] = xaxis.x;
        rotation[1][0] = xaxis.y;
        rotation[2][0] = xaxis.z;

        rotation[0][1] = yaxis.x;
        rotation[1][1] = yaxis.y;
        rotation[2][1] = yaxis.z;

        rotation[0][2] = zaxis.x;
        rotation[1][2] = zaxis.y;
        rotation[2][2] = zaxis.z;

        return rotation * translation;
    }
}

#endif
