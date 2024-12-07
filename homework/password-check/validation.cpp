#include "validation.hpp"
#include <ctype.h>
#include <algorithm>

std::string getErrorMessage(ErrorCode code) 
{

	switch (code) {
    case ErrorCode::Ok:
        return "Ok";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs to have at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs to have at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs to have at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs to have at least one uppercase letter";
    case ErrorCode::PasswordsDoNotMatch:
        return "Passwords do not match";
    }
}

bool doPasswordsMatch(std::string pass_1, std::string pass_2) 
{
    if (pass_1 == pass_2) 
    {
        return true;
    } 
    else return false;
}

ErrorCode checkPasswordRules(std::string pass) 
{
    int characters = 0;
    int number = 0;
    int specialCharacter = 0;
    int uppercasLetter = 0;

    for (auto x : pass)
    {
        if (std::isalnum(x))
        {
            characters++;
            if (std::isupper(x)) uppercasLetter++; 
            else if (std::isdigit(x)) number++;
        } 
        if (std::ispunct(x)) specialCharacter++;
    }

    if (characters < 9) 
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } 
    else if (number == 0) 
    {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } 
    else if (specialCharacter == 0) 
    {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } 
    else if (uppercasLetter == 0) 
    {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    } 
    else return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string str_1, std::string str_2)
{
    if (doPasswordsMatch(str_1, str_2)) return checkPasswordRules(str_1);
    else return ErrorCode::PasswordsDoNotMatch;
}