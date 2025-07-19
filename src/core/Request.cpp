#include "Request.h"
#include <iostream>

Request::Request(const std::string& studentEmail, const std::string& description, const std::string& timestamp)
    : studentEmail(studentEmail), description(description), timestamp(timestamp) {}

const std::string& Request::getStudentEmail() const noexcept {
    return studentEmail;
}

const std::string& Request::getDescription() const noexcept {
    return description;
}

const std::string& Request::getTimestamp() const noexcept {
    return timestamp;
}

void Request::setDescription(const std::string& newDescription) noexcept {
    description = newDescription;
}

void Request::setTimestamp(const std::string& newTimestamp) noexcept {
    timestamp = newTimestamp;
}

void Request::print() const {
    std::cout << "-----------------------------------\n";
    std::cout << "Aluno: " << studentEmail << "\n";
    std::cout << "Data: " << timestamp << "\n";
    std::cout << "Requerimento: " << description << "\n";
    std::cout << "-----------------------------------\n";
}