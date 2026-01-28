#include <iostream>
#include "platform.h"

using namespace std;

int main() {

#if defined(WINDOWS)
    cout << "Operating System: Windows" << endl;
#elif defined(LINUX)
    cout << "Operating System: Linux" << endl;
#elif defined(MAC)
    cout << "Operating System: Mac" << endl;
#else
    cout << "Operating System: Unknown OS" << endl;
#endif

    return 0;
}
