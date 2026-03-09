#include "whatever.hpp"

int main() {
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "min: " << ::min(c, d) << std::endl;
    std::cout << "max: " << ::max(c, d) << std::endl;

    double e = 4.2;
    double f = 42.0;
    ::swap(e, f);
    std::cout << "e: " << e << ", f: " << f << std::endl;
    std::cout << "min: " << ::min(e, f) << std::endl;
    std::cout << "max: " << ::max(e, f) << std::endl;
    char g = 'A';
    char h = 'Z';
    ::swap(g, h);
    std::cout << "g: " << g << ", h: " << h << std::endl;
    std::cout << "min: " << ::min(g, h) << std::endl;
    std::cout << "max: " << ::max(g, h) << std::endl;

    return 0;
}