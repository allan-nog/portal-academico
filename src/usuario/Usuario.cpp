#include "Usuario.h"
#include <iostream>
using namespace std;

// Constructor
User::User(const std::string& name, const std::string& email, const std::string& password) : name(name), email(email), password(password) {}

// Getters
const std::string& User::getName() const noexcept { return name; }
const std::string& User::getEmail() const noexcept { return email; }
const std::string& User::getPassword() const noexcept { return password; }

// Setters
void User::setName(const std::string& newName) noexcept { name = newName; }
void User::setEmail(const std::string& newEmail) noexcept { email = newEmail; }
void User::setPassword(const std::string& newPassword) noexcept { password = newPassword; }

void User::printInfo() const {
    cout << "Nome: " << name << "\nEmail: " << email << "\n";
}