#include <iostream>
#include <string>
#include <functional>

std::string foo_small(){
    return "foo_small";
}

std::string foo_big(){
    return "foo_big";
}

void bar(int i, const std::function< std::string() >& lambda_small, const std::function< std::string() >& lambda_big){
// template<typename F, typename F2>
// void bar(int i, const F& lambda_small, const F2& lambda_big){
    if(i<0)
        std::cout << lambda_small() << std::endl;
    else
        std::cout << lambda_big() << std::endl;
}

int main() {

    bar(
        -100,
        foo_small,
        foo_big
    );

    bar(
        100,
        foo_small,
        foo_big
    );

    return 0;
}