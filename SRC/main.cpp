#include <iostream>
#include "System.h"
#include "Iwriter.h"
#include "Ireader.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    KeyboardReader reads;
    KeyBoardWriter writes;
    System system1;
    system1.startApp(reads,writes);
    return 0;
}