#pragma once
#include <string>

// Valida nomes: pelo menos 2 palavras com letras, separado por espaço
bool validateName(const std::string& name);

// Valida e-mails para student ou teacher
bool validateEmail(const std::string& email, const std::string& userType);

// Valida senha: mínimo 6 caracteres (exemplo simples)
bool validatePassword(const std::string& password);