#include "Student.h"
#include <iostream>

Student::Student(const std::string &name, const std::string &email, const std::string &password,
                 const std::string &registration, const std::string &course, int period)
    : User(name, email, password), registration(registration), course(course), period(period) {}

std::string Student::getRegistration() const noexcept { return registration; }
const std::string& Student::getCourse() const noexcept { return course; }
int Student::getPeriod() const noexcept { return period; }

void Student::setRegistration(const std::string &newRegistration) noexcept { registration = newRegistration; }
void Student::setCourse(const std::string &newCourse) noexcept { course = newCourse; }
void Student::setPeriod(int newPeriod) noexcept { period = newPeriod; }

void Student::addCourse(const Course &course) {
    enrolledCourses.push_back(course);
}

void Student::printInfo() const {
    std::cout << "-----------------------------------\n";
    std::cout << "Student: " << getName() << "\n";
    std::cout << "Email: " << getEmail() << "\n";
    std::cout << "Course: " << course << "\n";
    std::cout << "Registration: " << registration << "\n";
    std::cout << "Period: " << period << "\n";

    std::cout << "Enrolled courses:\n";
    for (const auto &c : enrolledCourses) {
        std::cout << " - " << c.name << " (" << c.hours << "h)\n";
    }
    std::cout << "-----------------------------------\n";
}
