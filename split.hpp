#pragma once
#include <sstream>          // for std::stringstream
#include <string>          // for std::string
#include "matrix.hpp"     // for wear::matrix

namespace wear {
    using namespace std;
    using namespace wear;

    matrix< string > split(string textToSplit, char splitSymbol) // Splitting text into characters
    {
        matrix< string > result;
        string token;
        stringstream ss(textToSplit);

        while (getline(ss, token, splitSymbol))
            result.push_back(token);
        return result;
    }
} // namespace wear