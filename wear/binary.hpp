#pragma once
#include <sstream> // for std::stringstream
#include <string>  // for std::string
#include <vector>  // for ABC
namespace wear {
    unsigned BinEcnode(unsigned translationValue) // Converting decimal code to binary
    {
        unsigned resultTranslateValue{ NULL };
        unsigned d{ 1 };
        while (translationValue > 0) {
            resultTranslateValue += (translationValue % 2) * d;
            translationValue = translationValue / 2;
            d = d * 10;
        }

        return resultTranslateValue;
    }

    unsigned BinDecode(unsigned translationValue) // To convert the binary code to decimal code
    {
        unsigned resultTranslateValue{ NULL };
        unsigned k{ 1 };
        while (translationValue > 0) {
            resultTranslateValue += (translationValue % 2) * k;
            k *= 2;
            translationValue = unsigned(translationValue / 10);
        }

        return resultTranslateValue;
    }

    auto BinMulti(int binaryValue, int multValue)
    {
        return wear::BinEcnode(wear::BinDecode(binaryValue) * multValue);
    }
    auto BinDivide(int binaryValue, int divideValue)
    {
        return wear::BinEcnode(wear::BinDecode(binaryValue) / divideValue);
    }
    auto BinPow(int binaryValue, int powValue)
    {
        return wear::BinEcnode(wear::BinDecode(binaryValue) ^ powValue);
    }
    auto BinAdd(int binaryValue, int addValue)
    {
        return wear::BinEcnode(wear::BinDecode(binaryValue) + addValue);
    }
    auto BinSubtract(int binaryValue, int subtractValue)
    {
        return wear::BinEcnode(wear::BinDecode(binaryValue) - subtractValue);
    }
    std::string BinToHex(unsigned translationValue) // Converting binary / decimal code to hex
    {
        std::stringstream stream;
        stream << "0x" << std::hex << translationValue;
        return stream.str();
    }
} // namespace wear