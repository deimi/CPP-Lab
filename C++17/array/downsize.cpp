#include <array>
#include <iostream>

template<typename T, int dest_size, int current_pos=(dest_size-1), typename... Ts>
constexpr std::array<T, dest_size> DownsizeByOne(std::array<T, dest_size+1> other, Ts... rest){
    if constexpr(current_pos>0){
        return DownsizeByOne<T, dest_size, current_pos-1, Ts...>(other, other[current_pos], rest...);
    }
    return std::array<T, dest_size>{other[current_pos], rest...};
}

template<typename T, int dest_size, int source_size, int current_pos=(dest_size-1), typename... Ts>
constexpr std::array<T, dest_size> Downsize(std::array<T, source_size> other, Ts... rest){
    static_assert(dest_size<source_size, "Destination not smaller than source");
    if constexpr(current_pos>0){
        return Downsize<T, dest_size, source_size, current_pos-1, Ts...>(other, other[current_pos], rest...);
    }
    return std::array<T, dest_size>{other[current_pos], rest...};
}

int main(){
    // with constexpr, program size 48 assembler instructions (clang gobolt.org)
    // without constexpr, program size 455 assembler instructions (clang gobolt.org)        
    // constexpr std::array<char, 5> test5{'a','s','d','f','q'};
    // constexpr std::array<char, 4> test4 = DownsizeByOne<char,4>(test5);
    // constexpr std::array<char, 3> test3 = DownsizeByOne<char,3>(test4);
    // constexpr std::array<char, 2> test2 = DownsizeByOne<char,2>(test3);

    // with constexpr, program size 48 assembler instructions (clang gobolt.org)
    // without constexpr, program size 474 assembler instructions (clang gobolt.org)        
    constexpr std::array<char, 5> test5{'a','s','d','f','q'};
    constexpr std::array<char, 4> test4 = Downsize<char,4,5>(test5);
    constexpr std::array<char, 3> test3 = Downsize<char,3,5>(test5);
    constexpr std::array<char, 2> test2 = Downsize<char,2,5>(test5);
    //constexpr std::array<char, 5> test_failed = Downsize<char,5,5>(test5);      // compile time error because destination must be smaller than source

    // std::cout << "test5: " << test5[0] << test5[1] << test5[2] << test5[3] << test5[4] << std::endl;
    // std::cout << "test4: " << test4[0] << test4[1] << test4[2] << test4[3] << std::endl;
    // std::cout << "test3: " << test3[0] << test3[1] << test3[2] << std::endl;
    // std::cout << "test2: " << test2[0] << test2[1] << std::endl;

    return 0;
}