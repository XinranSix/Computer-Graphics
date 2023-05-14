//
// Created by yaojie on 2023/5/4.
//

#include <iostream>
#include <vector>

std::vector<std::vector<int>> max_pooling(std::vector<std::vector<int>> &mat) {
    std::vector<std::vector<int>> res(2, std::vector<int>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int max = mat[2 * i][2 * j];
            for (int k = 2 * i; k <= 2 * i + 1; k++) {
                for (int m = 2 * j; m <= 2 * j + 1; m++) {
                    max = mat[k][m] > max ? mat[k][m] : max;
                }
            }
            res[i][j] = max;
        }
    }
    return res;
}

int main() {
    system("chcp 65001");
    std::vector<std::vector<int>> mat{
            {1, 1, 2, 4},
            {5, 6, 7, 8},
            {3, 2, 1, 0},
            {1, 2, 3, 4}
    };
    auto res = max_pooling(mat);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
