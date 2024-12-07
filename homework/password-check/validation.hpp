// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard - #pragma once

#pragma once
#include <iostream>
#include <string>

enum class ErrorCode 
{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoNotMatch
};

std::string getErrorMessage(ErrorCode);
bool doPasswordsMatch(std::string, std::string);
ErrorCode checkPasswordRules(std::string);
ErrorCode checkPassword(std::string, std::string);