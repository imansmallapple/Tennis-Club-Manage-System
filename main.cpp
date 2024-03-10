#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include"default_values.hpp"
#include"player.hpp"
#include"coach.hpp"
#include"court.hpp"
#include"club.hpp"
#include"test.hpp"
using namespace std;

int main() {
	//测试案例拾参数别输入贰（会寄），输壹没事
	test10();
#if 0
	test11();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test09();
	test10();
#endif
	system("pause");
	return 0;
}