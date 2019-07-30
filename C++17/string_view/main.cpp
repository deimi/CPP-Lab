#include <string>
#include <string_view>

//4     inline static const std::string test1 = "asdf";
//4     inline static const std::string test2 = "qwer";

int main() {
//    constexpr std::string_view test1 = "asdf";
//    constexpr std::string_view test2 = "qwer";
//    std::string test = std::string(test1) + std::string(test2);       //programm code size 190

//    std::string_view test1 = "asdf";
//    std::string_view test2 = "qwer";
//    std::string test = std::string(test1) + std::string(test2);         //programm code size 270

//    static const std::string test1 = "asdf";
//    static const std::string test2 = "qwer";
//    std::string test = test1 + test2;               //programm code size 418

//4    std::string test = test1 + test2;               //programm code size 399

    constexpr std::string_view test1 = "asdf";
    constexpr std::string_view test2 = "qwer";
    std::string test(test1);
    test.append(test2);             //programm code size 131

  return 0;
}