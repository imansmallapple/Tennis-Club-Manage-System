#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include"club.hpp"
//remove player, remove coach, and avoid using return list
using namespace std;
//-------------------------------------------------------------------------------------------------------------
//test function in class club
//Check method in 'Club'(AddCourt, AddCoach and AddPlayer)
//Testing for create a club, add a court, a coach and a student
//check the number of court, coach and player is 1 or not(to check if the add is success or not)
//fail case: 'add failed' will be shown on the screen
void test01();
//test2: print the existing lists of court, coach and player
//Check method in 'Club'(printCourtList, printCoachList and printPlayerList)
//test for printing club information with correct input id case
//test for print club information with wrong input id case
void test02();
//test for adding wrong cases: 
//Check method in 'Club'(AddCourt, AddCoach and AddPlayer)
//test case 1: add existing object in the club
//test case 2: add wrong input parameter when adding court 'size' and 'type'
//test case 3: add objects with reached to the max number
//test result 1: 'input id already exists will be printed' for add existing object
//test result 2: 'Ileagal type input!' or 'Ileagal size input!' will be printed for input court's wrong parameter
//test result 3: 'Add failed! Court number reached max number' for add objects with max number
void test03();
//test method in 'Club'(getCourtNumber, getCoachNumber and getPlayerNumber)
//Add one court, one coach and one player in the club and check the current member number
//correct case: current member number in club will be printed
void test04();
//test for update coach's and player's qualification and level while adding coach and player
//correct case:
//if input coach id is valid, the function will check this coach's experience, and upgrade his level and salary via experience
//if input player id is valid, the function will check this player's win-rate, and upgrade his level , transfer fee and salary via experience
//fail case: 
//if input coach id is not vaild, an error message will be printed
void test05();
//test for print list of an empty club
void test06();
//test for checking print function in court's coach list and coach's player list
//Special case: if the court's coach number is zero, an empty message will be printed
//Correct case: if input id is valid, list information will be printed
//Wrong case: input wrong id, an error message will be printed(Input id corresponds with no court or coach)
void test07();
//Test assignment
//Assign a coach to court, assign a player to coach
//Correct case: assigned successful information will be printed
//Wrong case 1: if input coach id or player id is not valid, an error message will be printed
//Wrong case 2: if the court's coach number or coach's player number reached to the max number. an error message will be printed
void test08();
//test for remove object from existing court, coach and player
//Correct case: removed successful information will be printed
//Wrong case: input wrong id(not existing member), an error message will be printed
void test09();
//test for remove a court with existing coach, remove a coach with existing player
//Correct case: removed successful information will be printed
//Wrong case: if new input coach id is the removed coach id, an error message will be printed
void test10();
//test for reassignment
//Correct case:if input new id is valid, 'Added all players/coaches with coach/court id successful!' will be printed
//Wrong case: if input new id is not valid, an error message will be printed 
void test11();
//add dynamic club and test destructor
void test12();
//remove a coach and check both coachlist in club and court
void test13();
//remove a player and check both playerlist in club and coach
void test14();