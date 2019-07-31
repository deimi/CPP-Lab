#include <iostream>

#include <array>


template<typename T, int size_lhs, int size_rhs, int current_pos_lhs=size_lhs-1, int current_pos_rhs=size_rhs-1, typename... Ts>
constexpr std::array<T, size_lhs+size_rhs> Concatenate(const std::array<T, size_lhs> &lhs, const std::array<T, size_rhs> &rhs, const Ts&... rest){
    if constexpr (current_pos_rhs>=0) {
        return Concatenate<T, size_lhs, size_rhs, current_pos_lhs, current_pos_rhs-1, Ts...>(lhs, rhs, rhs[current_pos_rhs], rest...);
    }
    if constexpr (current_pos_lhs>=0) {
        return Concatenate<T, size_lhs, size_rhs, current_pos_lhs-1, current_pos_rhs, Ts...>(lhs, rhs, lhs[current_pos_lhs], rest...);
    }
    lhs.size();     // prevent "set but unused" warning
    rhs.size();     // prevent "set but unused" warning
    return std::array<T, size_lhs+size_rhs>{rest...};
}

// template<typename T, int size_lhs, int size_rhs>
// constexpr std::array<T, size_lhs+size_rhs> operator+(const std::array<T, size_lhs> &lhs, const std::array<T, size_rhs> &rhs){
//     return Concatenate<T, size_lhs, size_rhs>(lhs, rhs);
// }

int main(){
    // with constexpr, program size 43 assembler instructions (clang gobolt.org)
    // without constexpr, program size 451 assembler instructions (clang gobolt.org)  
    constexpr std::array<char, 5> test_a{'a','s','d','f','g'};
    constexpr std::array<char, 3> test_b{'q','w','e'};

    std::array<char, test_a.size()+test_b.size()> test_c = Concatenate<char, test_a.size(), test_b.size()>(test_a, test_b);
    // std::array<char, test_a.size()+test_b.size()> test_c = test_a + test_b;      // Error: template argument deduction failed
    // std::array<char, test_a.size()+test_b.size()> test_c = operator+<char,test_a.size(),test_b.size()>(test_a, test_b);

    // std::cout << "test_a: " << test_a[0] << test_a[1] << test_a[2] << test_a[3] << test_a[4] << std::endl;
    // std::cout << "test_b: " << test_b[0] << test_b[1] << test_b[2] << std::endl;
    // std::cout << "test_c: " << test_c[0] << test_c[1] << test_c[2] << test_c[3] << test_c[4] << test_c[5] << test_c[6] << test_c[7] << std::endl;


    return 0;
}