#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include"player.hpp"
#include"default_values.hpp"
using namespace std;
class Club;
class Coach
{
private:
	string name;
	int salary, id, experience;
	char qualification;//char type can only choose'A','B','C','D'
	list<Player*>coachPlayers;
	int maxPlayer;//max player number (most 8)
public:
	//constructor
	Coach(string name, int id, int experience) :name(name), id(id), experience(experience) {
		this->maxPlayer = MaxCoachPlayerNumber;
	}
	~Coach();
	//add the pointer between this coach and designated player
	void linkPlayer(Player& player);
	//delete the pointer between this coach and designated player
	void releasePlayer(Player& player);
	int getId();
	//void printPlayerList();
	size_t getPlayerNumber();
	//for update use
	int getExperience();

	//get coach list in order to be used in remove court function
	//list<Player*>getCoachPlayers();//not object oriented
	//used for modify information in club class
	void modifyQualification(char qualification);
	//used for modify information in club class
	void modifySalary(char qualification);
	void srandSeed();

	//print this coach's information
	void printCoach();
	//print player list of this coach
	void printPlayerList();
	//hire a player of this coach
	void hirePlayer(int playerId);
	//fire a player of this coach
	//void firePlayer(int playerId);
	//check if coach is exist in the court or not, if exists return true, else return false
	bool checkPlayerInCoach(int playerId);
	//the reason why here require to input court id, is this need to be compared in further condition
	void fireAllPlayer(int id, Club* club);
};