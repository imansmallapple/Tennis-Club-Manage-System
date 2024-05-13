#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"default_values.hpp"
#include"coach.hpp"
#include"court.hpp"
#include"player.hpp"
using namespace std;
class Club
{
private:
	//find coach assigned
	Court* findCoachAssigned(int coachId);
	//find player assigned
	Coach* findPlayerAssigned(int playerId);
	list<Court*>allCourts;//court pointer list in the club
	list<Coach*>allCoachs;//coach pointer list in the club
	list<Player*>allPlayers;//player pointer list in the club
	string name, location;//club name and location
	//string* activity;//to be considered
	int maxCourt;//the number of court is limited by club space
	int id;//club id number
	//print basic interface information
	void showMenu();
public:
	Club(int courtNumber, string name, string location, int id) :maxCourt(courtNumber), name(name), location(location), id(id) {};//count number 1-5
	 ~Club();//****
	//Check if there exists input player and coach, if not exist, an error message will be printed
	void AssignPlayerToCoach(int playerId, int coachId);
	void AssignCoachToCourt(int coachId, int courtId);
	//delete pervious pointer and call assign method
	void ReassignPlayerToCoach(int playerId, int coachId);
	void ReassignCoachToCourt(int coachId, int courtId);

	//if input player id corresponds no player an error message will be printed
	//if player has assigned to a coach or a court, coach id and court will be printed
	//if player id is valid will no assignment, function will return true
	bool CheckPlayerValidity(int id);
	//if input coach id corresponds no coach an error message will be printed
	//if coach has been assigned to a court, true case will be returned
	bool CheckCoachValidity(int id);
	//if input court id corresponds no court an error message will be printed
	bool CheckCourtValidity(int id);
	//check if court id exists or not at first, and check if the number of court exceed max court number
	//then check input player number and coach number is within the max range or not
	//if not, an error message will be printed
	void AddCourt(int Id, char type, char size);
	void AddPlayer(string name, int id, int experience, float winRate);
	//according to given experience value automatic assign current coach's salary and level
	void AddCoach(string name, int id, int experience);
	//check if there exists a court with the input id
	//if not exist an error message will be printed
	//if this court's player list or coach list is not empty, a notice will be printed to user to reassign this court's player list and coach list to another court
	//if this court's player list and coach list are empty, delete this court and the point in the court list
	void RemoveCourt(int id);
	//check if there exists a coach with input id
	//if not exist an error message will be printed
	//if exists then check it's player list is empty or not
	//if this coach's player list is empty, delete this coach and the pointer in the coach list and court coach list
	//if not exist an notice will be printed to the user to reassign this coach's player list to another coach
	void RemoveCoach(int id);
	//check if there exists a player with input id
	//if not exist an error message will be printed
	//if exists then delete this player and the pointer
	void RemovePlayer(int id);
	//print all coaches with input court id
	//if given court it is not valid or empty, an error message will be printed
	void PrintCoach(int courtId);
	//print all players with input coach id
	void PrintPlayer(int coachId);
	void PrintClub(int clubId);
	//print all court in the club
	void printCourtList();
	//first check if there exist the court of input court id
	//if not exist an error message will be printed
	//if exist, input court's all coach will be printed
	void printCoachList();
	//firtst check if there exist the coach of input coach id
	//if not exist an error message will be printed
	//if exist, input coach's all player will be printed
	void printPlayerList();
	//if input id corresponds with no coach, an error message will be printed
//if input id is valid, the function will check this coach's experience, and upgrade his level with corrsponding experience, the salary will be modified as well
	void updateCoachData(int coachId);
	void updatePlayerData(int playerId);
	//get the number of courts in the club
	//this method is used for condition check
	size_t getCourtNumber();
	//get the number of coaches in the club
	size_t getCoachNumber();
	//get the number of players in the club
	size_t getPlayerNumber();
	//interface is used to interact with user with obvious instructions
	void interface();
};
