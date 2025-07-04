#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const string &name, const string &email, const string &password, int registration, const string &course, int period) : User(name, email, password), registration(registration), course(course), period(period) {}

int Student::getRegistration() const noexcept { return registration; }
const std::string& Student::getCourse() const noexcept { return course; }
int Student::getPeriod() const noexcept { return period; }

void Student::setRegistration(int newRegistration) noexcept { registration = newRegistration; }
void Student::setCourse(const std::string &newCourse) noexcept { course = newCourse; }
void Student::setPeriod(int newPeriod) noexcept { period = newPeriod; }

void Student::addCourse(const Course &course) {
    enrolledCourses.push_back(course);
}

void Student::printInfo() const {
    cout << "-----------------------------------\n";
    cout << "Student: " << getName() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Course: " << course << endl;
    cout << "Registration: " << registration << endl;
    cout << "Period: " << period << endl;

    cout << "Enrolled courses:\n";
    for (const auto &c : enrolledCourses) {
        cout << " - " << c.name << " (" << c.hours << "h)\n";
    }
    cout << "-----------------------------------\n";
}