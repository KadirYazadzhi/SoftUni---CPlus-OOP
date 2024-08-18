#include "Echo.h"

bool echoOn = true;

void echo(const std::string & echo) {
    if (echoOn) {
        std::cout << echo << std::endl;
    }
}