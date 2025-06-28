#pragma once
#include <string>
#include <vector>
#include "User.h"

class Teacher : public User {
private:
    int siape;
    std::vector<Course> teachingCourses;
public:
    Teacher(const std::string &name, const std::string &email, const std::string &password, int siape);

    int getSiape() const noexcept;
    void setSiape(int newSiape) noexcept;

    void addCourse(const Course &course);
    void printInfo() const override;
};