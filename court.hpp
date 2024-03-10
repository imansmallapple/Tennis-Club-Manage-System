#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
//#include"club.hpp"
#include"coach.hpp"
#include"default_values.hpp"
using namespace std; 
class Club;
class Court {
private:
	//some other data
	int courtId;
	//court type can only be given 'I' or 'O', which means indoor and outdoor respectively
	//court size can only be given 'L', 'M' or 'S', which means large size, middle size and small size respectively
	char courtType, courtSize;
	list<Coach*>courtCoaches;//court coachs 
	int maxCoach;//max coach number (most 2)
public:
	//set court with coachs and players
	Court(int Id, char type, char size);
	~Court();
	//link pointer between designated coach and court
	void linkCoach(Coach& coach);
	//delete pointer between court and designated coach
	void releaseCoach(Coach& coach);
	int getId();
	//print this court's all coach, if there is no coach, an error message will be printed
	//void printCoachList();
	//used for condition check: if the coach number exceed the max court number(2) or not
	size_t getCoachNumber();
	//get coach list in order to be used in remove court function
	//list<Coach*>getCourtCoaches();//not object oriented
	//print court information
	void printCourt();
	//print coach list in this court
	void printCoachList();
	//hire a coach to court
	void hireCoach(int coachId);
	//fire all coaches in this court
	//required to remove all coaches while removing a not empty court
	//the reason why here require to input court id, is this need to be compared in further condition
	void fireAllCoach(int id,Club* club);
	//check if coach is exist in the court or not, if exists return true, else return false
	bool checkCoachInCourt(int coachId);
};