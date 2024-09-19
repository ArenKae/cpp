#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "iostream"
#include "string"
#include "sstream"
#include "stdlib.h"
#include "iomanip"
#include "climits"
#include "math.h"

class ScalarConverter
{
    public:
        static  void convert(const std::string &input);
        static  std::string findType(const std::string &input);
        static  bool isChar(const std::string &input);
        static  bool isInt(const std::string &input);
        static  bool isFloat(const std::string &input);
        static  bool isDouble(const std::string &input);
        static  void toInt(const std::string &input, const std::string &type);
        static  void toDouble(const double &value, const std::string &input, const int &p, const std::string &type);
        static  void toFloat(const double &value, const std::string &input, const int &p, const std::string &type);
        static  void toChar(const double &value, const std::string &input, const std::string &type);
    private:
        ScalarConverter(){};
};

#endif