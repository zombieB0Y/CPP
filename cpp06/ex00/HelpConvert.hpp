#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <iomanip>

class HelpConvert {
private:
    static void printConversionResult(char c, const std::string& type);
    static void printConversionResult(int i, const std::string& type);
    static void printConversionResult(float f, const std::string& type);
    static void printConversionResult(double d, const std::string& type);
    static void printConversionResult(const std::string& val, const std::string& type);

public:
    HelpConvert();
    HelpConvert(const HelpConvert& other);
    HelpConvert& operator=(const HelpConvert& other);
    ~HelpConvert();

    class ConversionError : public std::exception {
    private:
        std::string _msg;
    public:
        ConversionError(const std::string& msg) throw();
        virtual ~ConversionError() throw();
        virtual const char* what() const throw();
    };

    static void isChar(const std::string &s);
    static void isInt(const std::string &s);
    static void isFloat(const std::string &s);
    static void isDouble(const std::string &s);
    static void isPseudoLiteral(const std::string &s);
};
