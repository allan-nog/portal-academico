#pragma once
#include <string>

/**
 * @brief Estrutura simples representando uma disciplina (Course).
 */
struct Course {
    std::string name;  ///< Nome da disciplina
    int hours;         ///< Carga horária
};

/**
 * @brief Classe base para usuários do sistema (Aluno, Professor, Admin).
 */
class User {
protected:
    std::string name;
    std::string email;
    std::string password;

public:
    /**
     * @brief Construtor default cria usuário vazio.
     */
    User() : name(""), email(""), password("") {}

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do usuário
     * @param email Email do usuário
     * @param password Senha (ou hash) do usuário
     */
    explicit User(const std::string& name, const std::string& email, const std::string& password);

    /// @return Nome do usuário
    const std::string& getName() const noexcept;
    /// @return Email do usuário
    const std::string& getEmail() const noexcept;
    /// @return Senha (ou hash) do usuário
    const std::string& getPassword() const noexcept;

    void setName(const std::string& newName) noexcept;
    void setEmail(const std::string& newEmail) noexcept;
    void setPassword(const std::string& newPassword) noexcept;

    /**
     * @brief Exibe informações básicas do usuário. Pode ser sobrescrito nas subclasses.
     */
    virtual void printInfo() const;

    /// Destrutor virtual para suportar polimorfismo.
    virtual ~User() = default;
};