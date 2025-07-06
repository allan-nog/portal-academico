#include "Validador.h"
#include <regex>
#include <cctype>
using namespace std;

// -------------------------------------------------------------
// Valida nome: exige pelo menos 2 palavras (com espaços) só letras
bool validateName(const string& name) {
    regex nameRegex(R"(^[A-Za-zÀ-ÿ]+( [A-Za-zÀ-ÿ]+)+$)");
    return regex_match(name, nameRegex);
}

// -------------------------------------------------------------
// Valida e-mail conforme o tipo: student ou teacher
bool validateEmail(const string& email, const string& userType) {
    if (userType == "student") {
        regex studentRegex(R"(^[a-zA-Z0-9._%+-]+@aluno\.[a-zA-Z]+\.br$)");
        return regex_match(email, studentRegex);
    } else if (userType == "teacher") {
        regex teacherRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z]+\.br$)");
        return regex_match(email, teacherRegex);
    }
    return false;
}

// -------------------------------------------------------------
// Valida senha: pelo menos 6 caracteres (pode sofisticar depois)
bool validatePassword(const string& password) {
    return password.length() >= 6;
}
