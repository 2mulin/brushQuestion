// Test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


char* myString()
{
	char buffer[6] = { 0 };						//局部变量，存储在栈区
	char* s = (char*)"Hello World!";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}

int main()
{
	printf("%s\n", myString());
	return 0;
}
