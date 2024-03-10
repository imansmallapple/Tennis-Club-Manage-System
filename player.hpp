#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include<time.h>
using namespace std;
class Player {
private:
	string name;
	int id;
	int transferFee;
	int experience;
	int salary;
	float winRate;
	char level;
public:
	//constructor with name,id,transfer fee, experience, salary, win rate and level
	Player(string name, int id, int experience, float winRate)
		:name(name), id(id), experience(experience), winRate(winRate) {};
	~Player();

	//print this player's information
	void printPlayer();

	//for update use
	int getId();
	int getExperience();
	float getWinRate();
	//used for modify information in club class
	void modifyLevel(char level);
	void modifySalary(char level);
	void modifyTransferFee(char level);
	void srandSeed();	
};
