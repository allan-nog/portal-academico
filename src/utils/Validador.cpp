#include "Validador.h"

bool validateName(const std::string& name){
    if (name == name)
        return true;
    else
        return false;
}

bool validateEmail(const std::string& email){
    if (email == email)
        return true;
    else
        return false;
}

bool validatePassword(const std::string& password){
    if (password == password)
        return true;
    else
        return false;
}