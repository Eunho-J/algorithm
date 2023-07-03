#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c;
    glfwGetVersion(&a, &b, &c);
    cout << a << "." << b << "." << c << endl;
    return 0;
}
