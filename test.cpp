#include<iostream>
#include<cstdlib>
using namespace std;

int main(void) {
    int points = 1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        std::cout<<"In what stat do you want to put your points?:"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
}
