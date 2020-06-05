#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void delay(unsigned int);

int main(){
	
	POINT cursorposition;
	int mX, mY;
	
	while (1){
		GetCursorPos(&cursorposition);
		mX = cursorposition.x;
		mY = cursorposition.y;
		
		if (GetAsyncKeyState(VK_LBUTTON)){
			printf("[%d, %d]\n", mX,mY);
			delay(1000);
		}
	}
	
	return 0;	
}

void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}