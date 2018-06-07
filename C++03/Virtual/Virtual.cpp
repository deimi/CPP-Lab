#include <string>
#include <iostream>


using namespace std;

class CAnimal {
    private:
        string name = "Generic Animal";
    
    public:
        void scream() {
            cout << "I'm an animal" << endl;
        };

        virtual void greet() {
            cout << "My name is " << name << endl;
        };
};

class CCow : public CAnimal {
    private:
        string name = "lucy the cow";

    public:
        void scream() {
            cout << "I'm a cow" << endl;
        };

         void greet() {
            cout << "My name is " << name << endl;
        };
};




int main() {
    CCow aCow;
    CAnimal* pAnimal = &aCow;
    
    cout << "Cow screaming" << endl;
    aCow.scream();

    cout << "Cow greeting" << endl;
    aCow.greet();

    cout << "Animal screaming" << endl;
    pAnimal->scream();

    cout << "Animal greeting" << endl;
    pAnimal->greet();

    return 0;
}