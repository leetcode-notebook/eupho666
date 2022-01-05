#include <vector>
#include <iostream>
using namespace std;

class A{
    private:
        int num;
    public:
        // A() = default;
        A() = default;
        inline virtual void print() {
            cout << "A" << endl; 
        }
};

class B: public A {
    public:
    inline void print() override {
        cout << "B" << endl;
    }
};

class C {
    public:
    explicit C(int i){};
    operator double(){

    }
};

int main(){
    C c = 1;
    return 0;
}