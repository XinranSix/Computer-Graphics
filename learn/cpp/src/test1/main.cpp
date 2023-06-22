#include "fmt/format.h"
#include <iostream>

int main() {
    std::string s = fmt::format("{0}is{1}", "abra", 12);
    std::cout << s << std::endl;
    return 0;
}