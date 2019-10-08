#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <stdexcept>

std::string foo_small(){
    return "foo_small";
}

std::string foo_big(){
    return "foo_big";
}

template<typename F, typename F2>
void bar(int i, F disp_table, const F2& lambda_default){
    try{
        std::cout << disp_table.at(i)() << std::endl;
    }
    catch(std::out_of_range){
        std::cout << lambda_default() << std::endl;
    }
}

int main() {

    std::map<int, std::function<std::string()>> my_map;
    my_map[-100] = foo_small;
    my_map[100] = foo_big;
    my_map[0] = [](){return "zero";};

    bar(
        -100,
        my_map,
        [](){return "default";}
    );

    bar(
        0,
        my_map,
        [](){return "default";}
    );

    bar(
        100,
        my_map,
        [](){return "default";}
    );

    bar(
        123,
        my_map,
        [](){return "default";}
    );

    return 0;
}