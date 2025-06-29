#pragma once
#include <string>

struct Course {
    std::string name; // nome da disciplina
    int hours;  // carga horária
};

class User {
protected:
    std::string name;
    std::string email;
    std::string password;
public:
    User() : name(""), email(""), password("") {}  // <<<<<< adiciona este construtor
    User(const std::string& name, const std::string& email, const std::string& password);
    
    // getters retornando referência constante
    const std::string& getName() const noexcept;
    const std::string& getEmail() const noexcept;
    const std::string& getPassword() const noexcept;

    // setters recebendo referência constante
    void setName(const std::string& newName) noexcept;
    void setEmail(const std::string& newEmail) noexcept;
    void setPassword(const std::string& newPassword) noexcept;

    virtual void printInfo() const;

    virtual ~User() = default; // Virtual para garantir destruição correta
};