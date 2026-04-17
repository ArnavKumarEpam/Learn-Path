#include "Widget_T7.h"
#include <iostream>
int main() {
    {
        Widget w;
        w.setName("PIMPL+RAII Example");
        w.printData();
    } // Widget and its Impl are destroyed here; resource cleanup printed
    return 0;
}
