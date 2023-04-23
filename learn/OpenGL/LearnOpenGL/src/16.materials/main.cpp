#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "camera.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <fmt/core.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void mouse_callback(GLFWwindow *window, double xpos, double ypos);

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
bool movable = true;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

glm::vec3 lightPos(std::sqrt(8.0f) * std::cos(0.0f), 1.0f,
                   std::sqrt(8.0f) * std::sin(0.0f));

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Light", nullptr, nullptr);
    if (window == nullptr) {
        fmt::print("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fmt::print("Failed to initialize GLAD\n");
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    Shader lightingShader("./shader/16.materials/1.colors.vert",
                          "./shader/16.materials/1.colors.frag");
    Shader lightCubeShader("./shader/16.materials/1.light_cube.vert",
                           "./shader/16.materials/1.light_cube.frag");

    float vertices[] = {
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

            -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f
    };

    glm::vec3 cubePositions[] = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glfwSwapInterval(1);
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    bool light_rotation = false;
    bool light_change = false;

    ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);

    ImVec4 material_ambient = ImVec4(1.0f, 0.5f, 0.31f, 1.0f);
    ImVec4 material_diffuse = ImVec4(1.0f, 0.5f, 0.31f, 1.0f);
    ImVec4 material_specular = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
    float material_shininess = 32.0f;

    ImVec4 light_ambient = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
    ImVec4 light_diffuse = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
    ImVec4 light_specular = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightColor = {1.0f, 1.0f, 1.0f};

    float t3 = 0;
    float x = 0.0f;
    float y = 0.0f;

    while (!glfwWindowShouldClose(window)) {

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = std::abs(currentFrame - lastFrame);
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        lightingShader.use();

        lightingShader.setFloat("viewPos", camera.Position.x, camera.Position.y, camera.Position.z);

        lightingShader.setFloat("material.ambient", material_ambient.x, material_ambient.y, material_ambient.z);
        lightingShader.setFloat("material.diffuse", material_diffuse.x, material_diffuse.y, material_diffuse.z);
        lightingShader.setFloat("material.specular", material_specular.x, material_specular.y, material_specular.z);
        lightingShader.setFloat("material.shininess", material_shininess);

        lightingShader.setFloat("light.position", lightPos.x, lightPos.y, lightPos.z);
        lightingShader.setFloat("light.specular", light_specular.x, light_specular.y, light_specular.z);

        if (light_change) {
            lightColor.x = sin(glfwGetTime() * 2.0f);
            lightColor.y = sin(glfwGetTime() * 0.7f);
            lightColor.z = sin(glfwGetTime() * 1.3f);
            light_diffuse = ImVec4{lightColor.x * glm::vec3(0.5f).x, lightColor.y * glm::vec3(0.5f).y,
                                   lightColor.z * glm::vec3(0.5f).z, 1.0f};
            light_ambient = ImVec4{light_diffuse.x * glm::vec3(0.2f).x, light_diffuse.y * glm::vec3(0.2f).y,
                                   light_diffuse.z * glm::vec3(0.2f).z, 1.0f};
        }
        lightingShader.setFloat("light.ambient", light_ambient.x, light_ambient.y, light_ambient.z);
        lightingShader.setFloat("light.diffuse", light_diffuse.x, light_diffuse.y, light_diffuse.z);

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float) SCR_WIDTH / (float) SCR_HEIGHT, 0.1f,
                                                100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        lightingShader.setMatrix4("projection", projection);
        lightingShader.setMatrix4("view", view);

//        glm::mat4 model = glm::mat4(1.0f);
//        lightingShader.setMatrix4("model", model);
        glBindVertexArray(cubeVAO);
        for (unsigned int i = 0; i < 10; i++) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            // float angle = 20.0f * i;
            model = glm::rotate(model, (float) glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
            lightingShader.setMatrix4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        lightCubeShader.use();
        lightCubeShader.setMatrix4("projection", projection);
        lightCubeShader.setMatrix4("view", view);

        if (light_rotation) {
            x += currentFrame - t3;
            y += currentFrame - t3;
            lightPos = glm::vec3{std::sqrt(8.0f) * std::cos(x), 1.0f,
                                 std::sqrt(8.0f) * std::sin(y)};
        }

        t3 = currentFrame;

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lightCubeShader.setMatrix4("model", model);

        glBindVertexArray(lightCubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        if (!movable) {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            {
                ImGui::Begin("Light Test");

                ImGui::ColorEdit3("clear color", (float *) &clear_color);

                ImGui::DragFloat3("Material ambient", (float *) &material_ambient, 0.001f, 0.0f, 1.0f);
                ImGui::DragFloat3("Material diffuse", (float *) &material_diffuse, 0.001f, 0.0f, 1.0);
                ImGui::DragFloat3("Material specular", (float *) &material_specular, 0.001f, 0.0f, 1.0);
                ImGui::DragFloat("Material shininess", (float *) &material_shininess, 1, 0, 200);

                ImGui::DragFloat3("Light ambient", (float *) &light_ambient, 0.001f, 0.0f, 1.0);
                ImGui::DragFloat3("Light diffuse", (float *) &light_diffuse, 0.001f, 0.0f, 1.0);
                ImGui::DragFloat3("Light specular", (float *) &light_specular, 0.001f, 0.0f, 1.0);

                ImGui::Checkbox("Light  rotation", &light_rotation);
                ImGui::Checkbox("Light Change", &light_change);
                ImGui::End();
            }
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &VBO);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}

float t1 = 0.0f;

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
        auto t2 = static_cast<float>(glfwGetTime());
        deltaTime = std::abs(t2 - t1);
        if (deltaTime > 0.1) {
            if (!movable) {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            } else {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
            movable = !movable;
            t1 = t2;
        }
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn) {
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    if (movable) {
        camera.ProcessMouseMovement(xoffset, yoffset);
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
