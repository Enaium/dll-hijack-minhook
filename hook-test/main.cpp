#include<windows.h>
#include<iostream>


int display(const char *text) {
    std::cout << text << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    return 0;
}

int main() {
    LoadLibrary("dinput8.dll");
    printf("Address: %p\n", display);
    display("Hello World!");
}
