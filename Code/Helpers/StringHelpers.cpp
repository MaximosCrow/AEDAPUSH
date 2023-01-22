//
// Created by bitor on 1/22/23.
//

#include "StringHelpers.h"

std::string to_upper(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}