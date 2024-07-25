#include <iostream>
#include <vector>
#include <string>

namespace SoftUni {
    namespace CppFundamentals {
        using namespace std;
        vector <string> lectures {
                "Basic Syntax",
                "Functions, Arrays, Vectors",
                "Strings and Streams",
                "STL Linear Containers",
                "STL Associative Containers",
                "Classes and Objects"
        };
    }
    namespace CppAdvanced {
        using namespace std;
        vector <string> lectures {
                "Pointers and References",
                "Memory Management",
                "Advanced C++ Class Members",
                "Code Organization",
                "Destructors, Copy Assignment, Construction",
                "Inheritance and Polymorphism",
                "Pure-Virtual Members and Multiple Inheritance"
        };
    }
}

namespace geometry2d {
    struct vector {
        int x, y;
    };
}

int main() {
    std::cout << "=== C++ Fundamentals ===" << std::endl;
    for (std::string s : SoftUni::CppFundamentals::lectures) {
        std::cout << s << std::endl;
    }

    std::cout << "=== C++ Advanced ===" << std::endl;
    for (std::string s : SoftUni::CppAdvanced::lectures) {
        std::cout << s << std::endl;
    }

    using namespace std;
    using namespace geometry2d;

    return 0;
}