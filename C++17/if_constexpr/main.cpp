// Copyright (c) 2019 Matthias Deimbacher
// Licensed under MIT License

#include <iostream>
#include <string>
#include <type_traits>

int GetInt(){return 5;}
float GetFloat(){return 12.345;}
std::string GetString(){return std::string("asdf");}

template<class T> struct dependent_false : std::false_type {};
template <class ...> constexpr std::false_type always_false{};

template<typename T>
T GetValue(){
    if constexpr (std::is_same<T, int>()){
        return GetInt();
    } else if constexpr (std::is_same<T, float>()){
        return GetFloat();
    } else if constexpr (std::is_same<T, std::string>()){
        return GetString();
    } else {
        //static_assert(dependent_false<T>::value, "Type not supported");
        static_assert(always_false<T>, "Type not supported");  // a direct static_assert(false, ...) is not possible because then the template would be ill-formed and won't compile for any type
    }
}

int main()
{
    std::cout << "int " << GetValue<int>() << std::endl;
    std::cout << "float " << GetValue<float>() << std::endl;
    std::cout << "string " << GetValue<std::string>() << std::endl;
    // std::cout << "uint " << GetValue<unsigned int>() << std::endl;  // This won't compile because it ends in the else path of GetValue
}

