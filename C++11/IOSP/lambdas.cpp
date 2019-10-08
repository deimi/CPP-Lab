#include <iostream>
#include <string>

std::string foo_small(){
    return "foo_small";
}

std::string foo_big(){
    return "foo_big";
}

template<typename F, typename F2>
void bar(int i, const F& lambda_small, const F2& lambda_big){
    if(i<0)
        std::cout << lambda_small() << std::endl;
    else
        std::cout << lambda_big() << std::endl;
}

int main() {

    bar(
        -100,
        [](){return foo_small();},
        [](){return foo_big();}
    );

    bar(
        100,
        [](){return foo_small();},
        [](){return foo_big();}
    );

    return 0;
}