#pragma once
#include <string>

/**
 * @brief Representa um requerimento feito por um aluno.
 */
class Request {
private:
    std::string studentEmail; ///< Email do aluno solicitante
    std::string description;  ///< Texto do requerimento
    std::string timestamp;    ///< Data e hora do requerimento (YYYY-MM-DD HH:MM:SS)
public:
    Request() = default;

    /**
     * @brief Construtor principal.
     */
    explicit Request(const std::string& studentEmail, const std::string& description, const std::string& timestamp);

    const std::string& getStudentEmail() const noexcept;
    const std::string& getDescription() const noexcept;
    const std::string& getTimestamp() const noexcept;

    void setDescription(const std::string& newDescription) noexcept;
    void setTimestamp(const std::string& newTimestamp) noexcept;

    /**
     * @brief Exibe o requerimento formatado no console.
     */
    void print() const;
};