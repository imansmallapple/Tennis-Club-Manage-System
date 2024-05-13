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
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.interface();
#if 0
	test10();
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