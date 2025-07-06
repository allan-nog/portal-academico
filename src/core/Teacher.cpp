#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(const string &name, const string &email, const string &password, int siape) 
    : User(name, email, password), siape(siape) {}

int Teacher::getSiape() const noexcept { return siape; }
void Teacher::setSiape(int newSiape) noexcept { siape = newSiape; }

void Teacher::addCourse(const Course &course) {
    teachingCourses.push_back(course);
}

void Teacher::printInfo() const {
    cout << "-----------------------------------\n";
    cout << "Teacher: " << getName() << "\n";
    cout << "Email: " << getEmail() << "\n";
    cout << "SIAPE: " << siape << "\n";

    cout << "Teaching courses:\n";
    for (const auto &c : teachingCourses) {
        cout << " - " << c.name << " (" << c.hours << "h)\n";
    }
    cout << "-----------------------------------\n";
}