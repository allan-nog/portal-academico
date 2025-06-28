#pragma once
#include <string>

struct Disciplina {
    std::string nome;
    int cargaHoraria;
};

class User {
protected:
    std::string name;
    std::string email;
    std::string password;
public:
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
};