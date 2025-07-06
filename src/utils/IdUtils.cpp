#include "IdUtils.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>

std::string generateStudentRegistration(int courseCode) {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;

    // gera 4 dígitos aleatórios
    int randPart = rand() % 10000;

    std::ostringstream oss;
    oss << year << std::setw(2) << std::setfill('0') << month << std::setw(2) << std::setfill('0') << courseCode << std::setw(4) << std::setfill('0') << randPart;

    return oss.str();
}

std::string generateTeacherSiape() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;

    // gera 4 dígitos aleatórios
    int randPart = rand() % 10000;

    std::ostringstream oss;
    oss << year << std::setw(2) << std::setfill('0') << month << "99" << std::setw(4) << std::setfill('0') << randPart;

    return oss.str();
}
