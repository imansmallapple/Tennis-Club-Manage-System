#include"test.hpp"
//-------------------------------------------------------------------------------------------------------------
//test function in class club
//Check method in 'Club'(AddCourt, AddCoach and AddPlayer)
//Testing for create a club, add a court, a coach and a student
//check the number of court, coach and player is 1 or not(to check if the add is success or not)
//fail case: 'add failed' will be shown on the screen
void test01() {
	cout << "test1: test for create a club" << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.AddCourt(01,'I','L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);

	if (club.getCoachNumber() == 1 && club.getCourtNumber() == 1 && club.getPlayerNumber() == 1) {
		cout << "add successful!" << endl;
		cout << "Coach number:" << club.getCoachNumber() << " " << "court number: " << club.getCourtNumber() << " "
			<< "Player number: " << club.getPlayerNumber() << " " << endl;
	}
	else {
		cout << "add failed!" << endl;
	}
}
//test2: print the existing lists of court, coach and player
//Check method in 'Club'(printCourtList, printCoachList and printPlayerList)
//test for printing club information with correct input id case
//test for print club information with wrong input id case
void test02() {
	cout << "test2: print the existing lists of court, coach and player:" << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.AddCourt(01,'I','L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);

	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();
	cout << "test for print club information: " << endl;
	club.PrintClub(1);
	cout << "test for print club wrong case(print not existing member in the club): " << endl;
	club.PrintClub(2);
}
//test for adding wrong cases: 
//Check method in 'Club'(AddCourt, AddCoach and AddPlayer)
//test case 1: add existing object in the club
//test case 2: add wrong input parameter when adding court 'size' and 'type'
//test case 3: add objects with reached to the max number
//test result 1: 'input id already exists will be printed' for add existing object
//test result 2: 'Ileagal type input!' or 'Ileagal size input!' will be printed for input court's wrong parameter
//test result 3: 'Add failed! Court number reached max number' for add objects with max number
void test03() {//****forgot print results
	cout << "test3: test for add member wrong case:" << endl;
	Club club(1, "Tennis Club", "Stary Miasto", 01);
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Wrong case 1: Trying to add an existing court, coach and player: " << endl;
	club.AddCourt(01,'I','L');
	//test for adding existing court
	club.AddCourt(01,'I','L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	//test for adding existing coach
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	//test for adding existing player
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	//test for adding court in case of number exceed its max number
	cout << endl;

	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Wrong case 2: Test for adding ileagal type and size parameter: " << endl;
	club.AddCourt(2, 'M', 'L');
	club.AddCourt(2, 'I', 'C');
	cout << endl;

	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Wrong case 3: " << endl;
	cout << "Adding court when the club already existing " << MaxCourtNumber << " courts(max: " << MaxCourtNumber << "): " << endl;
	club.AddCourt(02,'I','L');
	club.AddCourt(03,'I','L');
	club.AddCourt(04,'I','L');
	club.AddCourt(05,'I','L');
	club.AddCourt(06,'O','M');//not successful
	//here I changed the max player number from 80 to 10 for easier testing
	cout << "Adding player when the player number reached to the max number:" << endl;
	club.AddPlayer("A", 2, 1, 1);
	club.AddPlayer("B", 3, 1, 1);
	club.AddPlayer("C", 4, 1, 1);
	club.AddPlayer("D", 5, 1, 1);
	club.AddPlayer("E", 6, 1, 1);
	club.AddPlayer("F", 7, 1, 1);
	club.AddPlayer("G", 8, 1, 1);
	club.AddPlayer("H", 9, 1, 1);
	club.AddPlayer("I", 10, 1, 1);
	club.AddPlayer("J", 11, 1, 1);//not successful***
	cout << "Adding coach when the coach number reached to the max number: " << endl;
	club.AddCoach("A", 2, 1);
	club.AddCoach("B", 3, 1);
	club.AddCoach("C", 4, 1);
	club.AddCoach("D", 5, 1);
	club.AddCoach("E", 6, 1);
	club.AddCoach("F", 7, 1);
	club.AddCoach("G", 8, 1);
	club.AddCoach("H", 9, 1);
	club.AddCoach("I", 10, 1);
	club.AddCoach("J", 11, 1);//not successful***
	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();
}
//test method in 'Club'(getCourtNumber, getCoachNumber and getPlayerNumber)
//Add one court, one coach and one player in the club and check the current member number
//correct case: current member number in club will be printed
void test04() {//***
	cout << "Test 4: test method of getCourtNumber, getCoachNumber and getPlayerNumber: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.AddCourt(01, 'I', 'L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();
}
//test for update coach's and player's qualification and level while adding coach and player
//correct case:
//if input coach id is valid, the function will check this coach's experience, and upgrade his level and salary via experience
//if input player id is valid, the function will check this player's win-rate, and upgrade his level , transfer fee and salary via experience
//fail case: 
//if input coach id is not vaild, an error message will be printed
void test05() {
	cout << "test 5: update coach's and player's qualification and level: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddPlayer("Haolin Li", 01, 1, 30);
	cout << "Coach's salary and level will be given automatically according to input experience:" << endl;
	club.printCoachList();
	cout << "Player's salary, transfer fee and level will be given automatically according to input win-rate:" << endl;
	club.printPlayerList();
}
//test for print list of an empty club
void test06() {
	cout << "test6: test for club empty object: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();
}
//test for checking print function in court's coach list and coach's player list
//Special case: if the court's coach number is zero, an empty message will be printed
//Correct case: if input id is valid, list information will be printed
//Wrong case: input wrong id, an error message will be printed(Input id corresponds with no court or coach)
void test07() {
	cout << "test 7: Checking print function in court's coach list and coach's player list: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	//have assignment right now, test cases in the court's list
	club.AddCourt(01, 'O', 'S');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddCoach("Athas", 02, 2);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	club.AddPlayer("Jenny", 02, 1, 70.0);
	//club.AssignCoachToCourt(01, 01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Test special case: test for print current court's coach list with 0 coach: " << endl;
	club.PrintCoach(01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Test special case: test for print current coach's player list with 0 player: " << endl;
	club.PrintPlayer(01);

	cout << "--------------------------------------------------------" << endl;
	cout << "Assignment: " << endl;
	club.AssignPlayerToCoach(01, 01);
	club.AssignCoachToCourt(01, 01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Check coach list in club: " << endl;
	club.printCoachList();

	cout << "--------------------------------------------------------" << endl;
	cout << "Test for correct case: " << endl;
	cout << "Check coach list in court: " << endl;
	club.PrintCoach(01);

	cout << "--------------------------------------------------------" << endl;
	cout << "Check player list in club: " << endl;
	club.printPlayerList();

	cout << "--------------------------------------------------------" << endl;
	cout << "Check player list in coach: " << endl;
	club.PrintPlayer(01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Wrong case: " << endl;
	club.PrintCoach(02);
	club.PrintPlayer(03);
}
//Test assignment
//Assign a coach to court, assign a player to coach
//Correct case: assigned successful information will be printed
//Wrong case 1: if input coach id or player id is not valid, an error message will be printed
//Wrong case 2: if the court's coach number or coach's player number reached to the max number. an error message will be printed
void test08() {//need more prints********before case & after case
	cout << "Test 8: test for assignment, assign a coach to court, and assign a player to coach: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.AddCourt(01, 'I', 'L');

	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddCoach("A", 2, 1);
	club.AddCoach("B", 3, 1);

	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	club.AddPlayer("A", 2, 1, 1);
	club.AddPlayer("B", 3, 1, 1);
	club.AddPlayer("C", 4, 1, 1);
	club.AddPlayer("D", 5, 1, 1);

	cout << "--------------------------------------------------------" << endl;
	cout << "Correct assignment case: " << endl;
	club.AssignPlayerToCoach(01, 01);
	club.AssignCoachToCourt(01, 01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Wrong case 1: if input coach id or player id is not valid, an error message will be printed: " << endl;
	club.AssignPlayerToCoach(11, 11);
	cout << "--------------------------------------------------------" << endl;
	cout << "Wrong case 2: the court's coach number or coach's player number reached to the max number: " << endl;
	cout << "For court adding coach with max coach number: " << endl;
	club.AssignCoachToCourt(02, 01);
	club.AssignCoachToCourt(03, 01);

	cout << "--------------------------------------------------------" << endl;
	cout << "For coach adding player with max player number: " << endl;
	club.AssignPlayerToCoach(02, 01);
	club.AssignPlayerToCoach(03, 01);
	club.AssignPlayerToCoach(04, 01);
	club.AssignPlayerToCoach(05, 01);
}
//test for remove object from existing court, coach and player
//Correct case: removed successful information will be printed
//Wrong case: input wrong id(not existing member), an error message will be printed
void test09() {
	cout << "test 9: remove a court, coach and player from existing object: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	//no assignment right now, only test cases in the club's list
	club.AddCourt(01,'I','L');
	club.AddCourt(02,'I','L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddCoach("Kindy", 02, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	club.AddPlayer("Tomasz Jay", 02, 1, 34.0);
	cout << "--------------------------------------------------------" << endl;
	cout << "Before remove a court, coach and player: " << endl;
	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();

	cout << "--------------------------------------------------------" << endl;
	cout << "After remove a court, coach and player: " << endl;
	club.RemoveCoach(01);
	club.RemoveCourt(01);
	club.RemovePlayer(01);
	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();
	cout << "--------------------------------------------------------" << endl;
	cout << "Wrong case(remove with wrong input id): " << endl;
	club.RemoveCourt(11);
	club.RemoveCoach(11);
	club.RemovePlayer(11);
	club.printCourtList();
	club.printCoachList();
	club.printPlayerList();
}
//test for remove a court with existing coach, remove a coach with existing player
//Correct case: removed successful information will be printed
//Wrong case: if new input coach id is the removed coach id, an error message will be printed
void test10() {
	cout << "test 10: test for remove a court with existing coach, remove a coach with existing player: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	//have assignment right now, test cases in the court's list
	club.AddCourt(01, 'I', 'L');
	club.AddCourt(02, 'I', 'L');

	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddCoach("Athas", 02, 1);

	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	cout << "--------------------------------------------------------" << endl;
	cout << "Assignment: " << endl;
	club.AssignPlayerToCoach(01, 01);
	club.AssignCoachToCourt(01, 01);//with player 1
	club.AssignCoachToCourt(02, 01);//with no player
	cout << "--------------------------------------------------------" << endl;
	cout << "Before remove a court with existing coach: " << endl;
	club.printCoachList();
	club.printCourtList();
	cout << "--------------------------------------------------------" << endl;
	//club.printPlayerList();
	//cout << "Remove a coach with existing player: " << endl;
	//club.RemoveCoach(01);
	//cout << "After removement: " << endl;
	//club.printCoachList();
	//club.printPlayerList();
	cout << "After remove a court with existing coach: " << endl;
	club.RemoveCourt(01);
	club.printCourtList();
	club.printCoachList();
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Before remove a coach with existing player: " << endl;
	club.printPlayerList();
	club.printCoachList();
	cout << "--------------------------------------------------------" << endl;
	cout << "After remove a coach with existing player: " << endl;
	club.RemoveCoach(01);
	club.printPlayerList();
	club.printCoachList();
}
//test for reassignment
//Correct case:if input new id is valid, 'Added all players/coaches with coach/court id successful!' will be printed
//Wrong case: if input new id is not valid, an error message will be printed 
void test11() {//need more prints before assign & after assign
	cout << "Test 11: test for reassignment: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	club.AddCourt(01, 'I', 'L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddCoach("A", 2, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	club.AddPlayer("A", 02, 1, 50.0);	
	cout << "--------------------------------------------------------" << endl;
	cout << "Assignment: " << endl;
	club.AssignPlayerToCoach(01, 01);
	club.AssignCoachToCourt(01, 01);//with player 1
	cout << "--------------------------------------------------------" << endl;
	cout << "Correct case: " << endl;
	club.ReassignCoachToCourt(02, 01); 
	club.ReassignPlayerToCoach(02, 01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Wrong case: " << endl;
	club.ReassignCoachToCourt(02, 02);
	club.ReassignPlayerToCoach(02, 03);
}
//add dynamic club and test destructor
void test12() {
	cout << "test 12: test for destructor(automatic): " << endl;
	Club club1(1, "Tennis Club", "Zloty Tarsy", 01);
	club1.AddCourt(01, 'I', 'L');
	club1.AddCoach("Jiaxu Luo", 01, 1);
	club1.AddPlayer("Haolin Li", 01, 1, 50.0);
	cout << "-------------------------------------------------------------" << endl;
	cout << "test for destructor(dynamic): " << endl;
	Club* club2 = new Club(2, "Tennis CLUB", "Stary Miasto", 02);
	club2->AddCourt(02, 'I', 'L');
	club2->AddCoach("Luo Jiaxu", 02, 1);
	club2->AddPlayer("Li Haolin", 02, 1, 50.0);
	cout << "-------------------------------------------------------------" << endl;
	delete club2;
}

void test13() {
	cout << "test 13: remove a coach which had been assign to a court, check coach list in club and court: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	//no assignment right now, only test cases in the club's list
	club.AddCourt(01, 'I', 'L');
	club.AddCourt(02, 'I', 'L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	club.AddCoach("Kindy", 02, 1);
	//club.AddPlayer("Haolin Li", 01, 1, 50.0);
	//club.AddPlayer("Tomasz Jay", 02, 1, 34.0);
	cout << "--------------------------------------------------------" << endl;
	cout << "assignment: " << endl;
	club.AssignCoachToCourt(01, 01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Before remove coach: " << endl;
	cout << "list in club: " << endl;
	//club.printCourtList();
	club.printCoachList();
	cout << "list in court with id 1: " << endl;
	club.PrintCoach(01);
	cout << "--------------------------------------------------------" << endl;
	cout << "After remove a coach: " << endl;
	cout << "list in club: " << endl;
	club.RemoveCoach(01);
	//club.RemoveCourt(01);
	//club.RemovePlayer(01);
	//club.printCourtList();
	club.printCoachList();
	cout << "list in court with id 1: " << endl;
	club.PrintCoach(01);
	//club.printPlayerList();
}

void test14() {
	cout << "test 14: remove a player which had been assign to a coach, check player list in club and court: " << endl;
	Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	//no assignment right now, only test cases in the club's list
	//club.AddCourt(01, 'I', 'L');
	//club.AddCourt(02, 'I', 'L');
	club.AddCoach("Jiaxu Luo", 01, 1);
	//club.AddCoach("Kindy", 02, 1);
	club.AddPlayer("Haolin Li", 01, 1, 50.0);
	club.AddPlayer("Tomasz Jay", 02, 1, 34.0);
	cout << "--------------------------------------------------------" << endl;
	cout << "assignment: " << endl;
	club.AssignPlayerToCoach(01, 01);
	cout << "--------------------------------------------------------" << endl;
	cout << "Before remove player: " << endl;
	cout << "list in club: " << endl;
	//club.printCourtList();
	club.printPlayerList();
	cout << "list in coach with id 1: " << endl;
	club.PrintPlayer(01);
	cout << "--------------------------------------------------------" << endl;
	cout << "After remove a player: " << endl;
	cout << "list in coach: " << endl;
	club.RemovePlayer(01);
	//club.RemoveCourt(01);
	//club.RemovePlayer(01);
	//club.printCourtList();
	club.printPlayerList();
	cout << "list in court with id 1: " << endl;
	club.PrintPlayer(01);
	//club.printPlayerList();
}