#pragma once
#include <string>
#include <vector>
#include "User.h"

class Student : public User {
private:
    int registration;
    std::string course;
    int period;
    std::vector<Course> enrolledCourses;
public: 
    Student(const std::string &name, const std::string &email, const std::string &password, int registration, const std::string &course, int period);

    int getRegistration() const noexcept;
    const std::string& getCourse() const noexcept;
    int getPeriod() const noexcept;

    void setRegistration(int newRegistration) noexcept;
    void setCourse(const std::string &newCourse) noexcept;
    void setPeriod(int newPeriod) noexcept;

    void addCourse(const Course &course);
    void printInfo() const override;
};