// crash_test.cpp
int main() {
    int* ptr = nullptr;
    *ptr = 42; // Null pointer dereference triggers crash
    return 0;
}


// Load Program and Core File

// gdb ./program core
// Print the Backtrace

// (gdb) bt
// # Outputs the series of function calls active at the time of crash
// View Source and Line at Crash

// (gdb) l
// # Shows corresponding source code around crash point
// Inspect Variables

// (gdb) frame 0           # Move to the innermost stack frame (crash point)
// (gdb) info locals       # List local variables and their values
// (gdb) print varName     # Print specific variable (replace varName)
// Examine Call Stack and Arguments

// (gdb) frame N           # Move to previous/outer stack frames (N = frame number)
// Program received signal SIGSEGV, Segmentation fault.
// 0x000055555555513d in main () at Task7.cpp:4
// 4           *ptr = 42; // Null pointer dereference triggers crash
// (gdb) bt
// #0  0x000055555555513d in main () at Task7.cpp:4
// (gdb) l
// 1       // crash_test.cpp
// 2       int main() {
// 3           int* ptr = nullptr;
// 4           *ptr = 42; // Null pointer dereference triggers crash
// 5           return 0;
// 6       }
// (gdb) frame 0
// #0  0x000055555555513d in main () at Task7.cpp:4
// 4           *ptr = 42; // Null pointer dereference triggers crash
// (gdb) info locals
// ptr = 0x0
// (gdb) print varName
// ❌️ No symbol "varName" in current context.
// (gdb) print ptr
// $1 = (int *) 0x0
// (gdb) fram N
// ❌️ No symbol "N" in current context.
// (gdb) frame N
// ❌️ No symbol "N" in current context.
// (gdb) info args
// No arguments.
// (gdb) 