
#include <array>

using std::array;

typedef array<int, 5> TArrayFive;
typedef array<int, 5> TArrayFive2;
typedef array<int, 6> TArraySix;

class CArrayFive : public array<int,5> {
};

class CArrayFive2 : public array<int,5> {
};

int main() {

    TArrayFive tArrayFive = {0};
    TArrayFive2 tArrayFive2 = {0};
    array<int,5> arrayFive = {0};
    CArrayFive cArrayFive;
    CArrayFive2 cArrayFive2;    
    TArraySix tArraySix = {0};

    //tArrayFive = tArraySix;       // Compile error - no operator =

    tArrayFive = tArrayFive2;       // not a problem now, but if one typedef changes its going to be a pain in the ass!!!!
                                    // The programmer should not be tempted to assign these to typedefs because they are the same at the moment
                                    // Better use two real differnt types which need explizit cast functions for assigning => Flexability

    tArrayFive = arrayFive;

    //cArrayFive = arrayFive;       // Compile error - no operator = 

    //cArrayFive = cArrayFive2;       // Compile error - no operator =

    return 0;
}