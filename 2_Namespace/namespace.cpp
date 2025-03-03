#include <iostream>

void show_thread1();

void show_thread2();
void standardspace();

namespace fake_thread1
{
    int x=1;
    // To use it, call `<namespace>::<variable>`
    // `::` is called as the scope resolution oper
} // namespace fake_thread1

namespace fake_thread2
{
    int x=0x7c;
} // namespace fake_thread2



int main() {

    fake_thread1::x += fake_thread2::x;
    show_thread1();
    fake_thread2::x -= fake_thread1::x;
    show_thread2();
    fake_thread1::x += fake_thread2::x;
    show_thread1();

    int x; // Local(Clousure) variable is the "closest"
    // int x=1; // Error prompt: redeclaration of ‘int x’

    standardspace();
    std::cout<<"The value of x is: "<<x<<'\n';
    std::cout<<"The value of fake_thread1::x is: "<<fake_thread1::x<<'\n';
    std::cout<<"The value of fake_thread2::x is: "<<fake_thread2::x<<'\n';

    return 0;
}

void show_thread1() {
    using namespace fake_thread1;
    // `using` determines "current" namespace

    std::cout<<"Thread1:x: "<<x<<'\n';

    
}

void show_thread2() {
    using namespace fake_thread2;
    std::cout << "Thread2:x: " << x<<'\n';
}

void standardspace() {
    using namespace std;
    string name = "Test";

    cout<<name<<'\n';
}