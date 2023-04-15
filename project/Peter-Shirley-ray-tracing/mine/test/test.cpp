#include <iostream>
#include<time.h>
#include <sstream>

int main()
{
    time_t now = time(NULL);
    tm* tm_t = localtime(&now);
    std::stringstream ss;
    ss << "year:" << tm_t->tm_year + 1900 << " month:" << tm_t->tm_mon + 1 << " day:" << tm_t->tm_mday
       << " hour:" << tm_t->tm_hour << " minute:" << tm_t->tm_min << " second:" << tm_t->tm_sec;

    std::cout << ss.str();

    int wait;
    std::cin >> wait;
}