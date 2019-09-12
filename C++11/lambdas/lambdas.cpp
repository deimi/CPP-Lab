#include <iostream>

int main(){
    int a = 5;

    auto lambda = [=, &a](){std::cout << a << std::endl;};

    lambda();
    
    a=40;
    lambda();
}