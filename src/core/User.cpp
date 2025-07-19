#include "User.h"
#include <iostream>
using namespace std;

// Construtor parametrizado
User::User(const string& name, const string& email, const string& password)
    : name(name), email(email), password(password) {}

// Getters
const string& User::getName() const noexcept { return name; }
const string& User::getEmail() const noexcept { return email; }
const string& User::getPassword() const noexcept { return password; }

// Setters
void User::setName(const string& newName) noexcept { name = newName; }
void User::setEmail(const string& newEmail) noexcept { email = newEmail; }
void User::setPassword(const string& newPassword) noexcept { password = newPassword; }

// Impressão das informações básicas
void User::printInfo() const {
    cout << "Nome: " << name << "\nEmail: " << email << "\n";
}
