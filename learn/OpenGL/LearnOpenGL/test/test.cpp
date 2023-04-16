#include <fmt/core.h>
#include <vector>
#include <fmt/std.h>

int main() {
    std::string message = fmt::format("Tee answer is {}", 42);
    fmt::print(message);

    auto out = std::vector<char>();
    fmt::format_to(std::back_inserter(out), "{}", 42);

    return 0;
}