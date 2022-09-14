
#include<assert.h>
#include<ctype.h>
#include<iostream>
#include<stdlib.h>
#include"useful.h"
using namespace std;

void display(double x) {
	const char STAR = '*';
	const char BLANK = ' ';
	const char VERTICAL_BAR = '|';
	const int LIMIT = 39;
	int i;
	if (x < -LIMIT)
		x = -LIMIT;
	else if (x > LIMIT)
		x = LIMIT;
	for (int i = -LIMIT; i < 0; i++) {
		if (i > x)
			cout << STAR;
		else
			cout << BLANK;
	}
	cout << VERTICAL_BAR;
	for (int i = 1; i <= LIMIT; i++) {
		if (i <= x)
			cout << STAR;
		else
			cout << BLANK;
	}
}
//返回浮点0-1的随机数
double random_fraction() {
	//cstdlib
	return rand() / double(RAND_MAX);
}
double random_real(double low, double high) {
	assert(low <= high);
	return low + random_fraction()*(high - low);
}
void eat_line() {
	char next;
	do
		cin.get(next);//一直等待，直到按下回车
	while (next != '\n');
}
//传入一个数组
bool inquire(const char query[]) {
	char answer;
	do {
		cout << query << "[Yes or No]" << endl;
		cin >> answer;
		answer = toupper(answer);//这个表示变成大写
		eat_line();
	}
	while ((answer != 'Y') && (answer != 'N'));//如果输入的不是yes/no就继续询问
	return (answer == 'Y');//返回输入的是否为yes，是返回true否则返回false
}
