#include <iostream>
#include <math.h>
#include <time.h>
int main(){
    srand(time(NULL)); //resets random seed
    std::cout<<(((rand() % 3)+1));
}