
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
//���ظ���0-1�������
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
		cin.get(next);//һֱ�ȴ���ֱ�����»س�
	while (next != '\n');
}
//����һ������
bool inquire(const char query[]) {
	char answer;
	do {
		cout << query << "[Yes or No]" << endl;
		cin >> answer;
		answer = toupper(answer);//�����ʾ��ɴ�д
		eat_line();
	}
	while ((answer != 'Y') && (answer != 'N'));//�������Ĳ���yes/no�ͼ���ѯ��
	return (answer == 'Y');//����������Ƿ�Ϊyes���Ƿ���true���򷵻�false
}
