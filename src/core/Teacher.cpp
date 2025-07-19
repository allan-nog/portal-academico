#include "Teacher.h"
#include <iostream>

Teacher::Teacher(const std::string &name, const std::string &email, const std::string &password,
                 const std::string &siape)
    : User(name, email, password), siape(siape) {}

std::string Teacher::getSiape() const noexcept { return siape; }
void Teacher::setSiape(const std::string &newSiape) noexcept { siape = newSiape; }

void Teacher::addCourse(const Course &course) {
    teachingCourses.push_back(course);
}

void Teacher::printInfo() const {
    std::cout << "-----------------------------------\n";
    std::cout << "Teacher: " << getName() << "\n";
    std::cout << "Email: " << getEmail() << "\n";
    std::cout << "SIAPE: " << siape << "\n";

    std::cout << "Teaching courses:\n";
    for (const auto &c : teachingCourses) {
        std::cout << " - " << c.name << " (" << c.hours << "h)\n";
    }
    std::cout << "-----------------------------------\n";
}