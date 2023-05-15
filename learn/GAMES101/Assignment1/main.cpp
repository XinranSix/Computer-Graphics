#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    rotation_angle = rotation_angle / 180.0f * MY_PI;
    float sin_value = std::sin(rotation_angle);
    float cos_value = std::cos(rotation_angle);

    Eigen::Matrix4f rotation_matrix;

    rotation_matrix <<
        cos_value, -sin_value, 0, 0,
        sin_value, cos_value, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    model = rotation_matrix * model;

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    float t = std::abs(zNear) * std::tan(eye_fov / 180.0f * MY_PI / 2);
    float b = -t;
    float r = t * aspect_ratio;
    float l = -r;

   /* Eigen::Matrix4f persp_to_ortho, T, S;

    persp_to_ortho <<
        zNear, 0, 0, 0,
        0, zNear, 0, 0,
        0, 0, zNear + zFar, -zNear * zFar,
        0, 0, 1, 0;

    T <<
        1, 0, 0, -(l + r) / 2,
        0, 1, 0, -(t + b) / 2,
        0, 0, 1, -(zNear + zFar) / 2,
        0, 0, 0, 1;

    S <<
        2 / (r - l), 0, 0, 0,
        0, 2 / (t - b), 0, 0,
        0, 0, 2 / (zNear - zFar), 0,
        0, 0, 0, 1;

    projection = S * T * persp_to_ortho * projection;*/


    Eigen::Matrix4f m1;

    m1 <<
        zNear / r, 0, 0, 0,
        0, zNear / r, 0, 0,
        0, 0, -(zFar + zNear) / (zFar - zNear), -(2 * zNear * zFar) / (zFar - zNear),
        0, 0, -1, 0;

    projection = m1 * projection;

    return projection;
}

Eigen::Matrix4f get_rotation(Vector3f axis, float angle) {
    Eigen::Matrix3f rotation = Eigen::Matrix3f::Identity();

    angle = angle / 180 * MY_PI;

    float cos_angle = std::cos(angle);
    float sin_angle = std::sin(angle);

    Eigen::Matrix3f matrix1 = Eigen::Matrix3f::Identity();

    matrix1 = cos_angle * matrix1;

    Eigen::Matrix3f matrix2;

    matrix2 <<
        axis.x() * axis.x(), axis.x()* axis.y(), axis.x()* axis.z(),
        axis.y()* axis.x(), axis.y()* axis.y(), axis.y()* axis.z(),
        axis.z()* axis.x(), axis.z()* axis.y(), axis.z()* axis.z();

    matrix2 = (1 - cos_angle) * matrix2;

    Eigen::Matrix3f matrix3;

    matrix3 <<
        0, -axis.z(), axis.y(),
        axis.z(), 0, -axis.x(),
        -axis.y(), axis.x(), 0;

    matrix3 = sin_angle * matrix3;

    rotation = matrix1 + matrix2 + matrix3;

    Eigen::Matrix4f res;
    res <<
        rotation(0, 0), rotation(0, 1), rotation(0, 2), 0,
        rotation(1, 0), rotation(1, 1), rotation(1, 2), 0,
        rotation(2, 0), rotation(2, 1), rotation(2, 2), 0,
        0, 0, 0, 1;
    // std::cout << res << std::endl;
    return res;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

      /*  Vector3f axis(1, 0, 0);
        r.set_model(get_rotation(axis, angle));*/
        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));
   
        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
