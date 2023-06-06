//
// Created by yaojie on 2023/5/4.
//

#include <iostream>
#include <vector>
#include <array>

const std::array<std::array<int, 3>, 3> mat3{
        1, 0, 1,
        0, 1, 0,
        1, 0, 1
};

std::vector<std::vector<int>> cnn(std::vector<std::vector<int>> &mat) {
    if (mat.size() < 3 && mat[0].size() < 3) return {};
    std::vector<std::vector<int>> res(mat.size() - 2, std::vector<int>(mat[0].size() - 2, 0));
    for (int i = 1; i < mat.size() - 1; ++i) {
        for (int j = 1; j < mat[i].size() - 1; ++j) {
            for (int k = -1; k <= 1; ++k) {
                for (int m = -1; m <= 1; ++m) {
                    res[i - 1][j - 1] += mat[i + k][j + m] * mat3[k + 1][m + 1];
                }
            }
        }
    }
    return res;
}

int main() {
    system("chcp 65001");
    std::vector<std::vector<int>> mat{
            {1, 1, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 1, 1, 1},
            {0, 0, 1, 1, 0},
            {0, 1, 1, 0, 0}
    };
    auto res = cnn(mat);
    if (res.size() == 0) {
        return 0;
    }
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}