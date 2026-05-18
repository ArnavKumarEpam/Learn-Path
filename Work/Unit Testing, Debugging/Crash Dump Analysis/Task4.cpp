// stack_overflow.cpp
#include <iostream>
void recurse() {
    recurse(); // No base case!
}
int main() {
    recurse();
    return 0;
}
