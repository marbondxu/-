#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int a, b, c;
	for (int i = 100;i < 1000;i++) {
		a = i / 100;//百位
		b = i % 100 / 10;//十位
		c = i % 10;//个位
		if (a * a * a + b * b * b + c * c * c == i) {
			printf("%d ", i);
		}

	}printf("\n");
	system("pause");
	return 0;
}