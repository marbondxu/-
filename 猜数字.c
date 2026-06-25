#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int numSeed() {
	
	srand((unsigned int)time(NULL)); 
	return rand() % 100 + 1;//生成0—100的随机数字
}

int guessWhat() {
	int number = numSeed();

	printf("我已生成1-100之间随机一个数字\n");
	printf("猜猜这是哪个数字：\n");

	int guess = 0;
	while (1) {
		scanf_s("%d", &guess);
		if (guess > number) {
			if (guess > number + 20) {
				printf("猜大了，差距很大\n");
			}
			else {
				printf("猜大了，差距不大\n");
			}
		}
		else if (guess < number) {
			if (guess < number - 20) {
				printf("猜小了，差距很大\n");
			}
			else {
				printf("猜小了，差距不大\n");
			}
		}
		else if (guess == number) {
			printf("恭喜你猜对了！！\n");
			break;
		}
	}
	printf("再玩一次？\n");
flag:
	printf("1 - 是   2 - 不玩了\n");
	int n;
	scanf_s("%d", &n);
	
	if (n == 1) {
		guessWhat();
		
	}
	else if (n == 2) {
		printf("\n感谢游玩！\n");
		return 0;
	}
	else {
		printf("只能输入 1 和 2 \n");
		goto flag;
	}
}
int main() {

	printf("这是一个猜数字游戏\n");
	guessWhat();
	
	system("pause");
	return 0;
}