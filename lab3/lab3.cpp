#include<iostream> 
using namespace std; 
int n; 
int func(int x, int y, int z, int i) { 
	__asm{ 
		mov eax,i 
		sub eax,3 
		mov ecx,eax 
		c1: 
		mov eax, x 
		mul z 
		mov ebx,5 
		mul ebx 
		mov ebx, y 
		imul ebx, 2 
		add eax, ebx 
		mov n,eax 
		mov eax, y 
		mov x,eax 
		mov eax, z 
		mov y,eax 
		mov eax, n 
		mov z,eax 
		loop c1 
	} 
} 

int main(void) { 
	int x, y, z, n; 
	int i; 
	cout « endl « "x="; 
	cin » x; 
	cout « endl « "y="; 
	cin » y; 
	cout « endl « "z="; 
	cin » z; 
	cout « endl « "i= (i should be >= 3)"; 
	cin » i; 
	n = func(x, y, z, i); 
	cout« "f(" «i« ") = "«n«endl; 
	return n; 
}