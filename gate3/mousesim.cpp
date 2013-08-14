#include <stdio.h>
#include <Windows.h>

int main(void) {
    INPUT input;
    
    input.type = INPUT_MOUSE;
    input.mi.dx = 100;
    input.mi.dy = 100;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
    
    SendInput(1, &input, sizeof(input));
    return 0;
}