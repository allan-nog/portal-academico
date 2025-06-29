#include "Validador.h"
#include <regex>
#include <cctype>

// -------------------------------------------------------------
// Valida nome: exige pelo menos 2 palavras (com espaços) só letras
bool validateName(const std::string& name) {
    std::regex nameRegex(R"(^[A-Za-zÀ-ÿ]+( [A-Za-zÀ-ÿ]+)+$)");
    return std::regex_match(name, nameRegex);
}

// -------------------------------------------------------------
// Valida e-mail conforme o tipo: student ou teacher
bool validateEmail(const std::string& email, const std::string& userType) {
    if (userType == "student") {
        std::regex studentRegex(R"(^[a-zA-Z0-9._%+-]+@aluno\.[a-zA-Z]+\.br$)");
        return std::regex_match(email, studentRegex);
    } else if (userType == "teacher") {
        std::regex teacherRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z]+\.br$)");
        return std::regex_match(email, teacherRegex);
    }
    return false;
}

// -------------------------------------------------------------
// Valida senha: pelo menos 6 caracteres (pode sofisticar depois)
bool validatePassword(const std::string& password) {
    return password.length() >= 6;
}
