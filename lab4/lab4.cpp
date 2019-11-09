// f0 * x^n + f1 * x^(n-1) + f2 * x^(n-2) + ... + f(n-1) * x + fn
#include <iostream>
using namespace std;

int reverse(int f0,int f1,int f2,int n, int x) {
	_asm {
		mov esi, f0
		cmp n, 0 //if n = 0, answer = f0
		je end_
		imul esi, x
		add esi, f1
		cmp n, 1 //n = 1, answer = f0 * x + f1
		je end_
		imul esi, x
		add esi, f2
		cmp n, 2 // n = 2, answer = (f0 * x + f1) * x + f2 
		je end_
		mov ecx, n
		sub ecx, 2
	c1: mov eax, f0
		mul f2
		mov ebx, 5
		mul ebx
		mov ebx, f1
		imul ebx, 2
		add eax, ebx
		mov ebx, f1
		mov f0, ebx
		mov ebx, f2
		mov f1, ebx
		mov f2, eax
		imul esi, x
		add esi, f2
		loop c1
	end_: mov eax, esi  //answer = (((f0 * x + f1) * x + f2) * x + f3) * x + f4 ... if n > 3
	}
}

int main() {
	int f0, f1, f2, n, x;
	cin >> f0 >> f1 >> f2 >> n >> x;
	cout << reverse(f0, f1, f2, n, x);
	return 0;
}
