#include"club.hpp"
void Club::AssignPlayerToCoach(int playerId, int coachId) {
	//check coach and player are exists
	if (!CheckCoachValidity(coachId) || !CheckPlayerValidity(playerId)) {
		cout << "Input id corresponds with no coach or player!" << endl;
		return;
	}
	for (Coach* coach : allCoachs) {
		{
			if (coach->getId() == coachId) {//find coach
				//check coach's player number is less than 4 or not
				if (coach->getPlayerNumber() >= MaxCoachPlayerNumber) {
					cout << "This coach has no remaining place for new player!" << endl;
					return;
				}
				else {
					//assign player
					for (Player* player : allPlayers) {
						if (player->getId() == playerId) {//find player
							coach->linkPlayer(*player);//linkage
						}
					}
					cout << "Player with id " << playerId << " has been assigned to coach with id " << coachId <<" successfully!" << endl;
				}
			}
		}
	}
}
void Club::AssignCoachToCourt(int coachId, int courtId) {
	//check coach and court are exists
	if (!(CheckCoachValidity(coachId)) || !CheckCourtValidity(courtId)) {
		cout << "Input id corresponds with no coach or court!" << endl;
		return;
	}
	for (Court* court : allCourts) {
		if (court->getId() == courtId) {//find court
			//check court's coach number is less than 2 or not
			if (court->getCoachNumber() >= MaxCourtCoachNumber) {
				cout << "This court has no remaining place for new coach!" << endl;
				return;
			}
			else {
				//assign coach
				for (Coach* coach : allCoachs) {
					if (coach->getId() == coachId) {//find coach
						court->linkCoach(*coach);//linkage
					}
				}
				cout << "Coach with id " << coachId << " has been assigned to court with id " << courtId << " successfully!" << endl;
			}
		}
	}
}
void Club::ReassignPlayerToCoach(int playerId, int coachId) {
	//first check given coach id exists or not
	for (Coach* coach : allCoachs) {
		//find coach
		if (coach->getId() == coachId) {
			coach->hirePlayer(playerId);
#if 0
			list<Player*>coachPlayerList = coach->getCoachPlayers();
			for (Player* player : coachPlayerList) {
				if (player->getId() == playerId) {//find player
					coach->linkPlayer(*player);
				}
			}
#endif
			cout << "Added all players with coach id " << coachId << " successful! " << endl;
			return;
		}
	}
	cout << "INPUT COACH ID NOT EXISTS!" << endl;
}
void Club::ReassignCoachToCourt(int coachId, int courtId) {
	//first check given court id exists or not
	for (Court* court : allCourts) {
		//find court
		if (court->getId() == courtId) {
			court->hireCoach(coachId);
#if 0
			list<Coach*>courtCoachList = court->getCourtCoaches();
			for (Coach* coach : courtCoachList) {
				if (coach->getId() == coachId) {//find coach
					court->linkCoach(*coach);
				}
			}
#endif
			cout << "Added all coaches with court id " << courtId << " successful! " << endl;
			return;
		}
	}
	cout << "INPUT COURT ID NOT EXIST!" << endl;
}
bool Club::CheckPlayerValidity(int id) {
	for (Player* player : allPlayers) {
		if (player->getId() == id) {
			cout << "Check player exists" << endl;
			return true;
		}
	}
	return false;
}
bool Club::CheckCoachValidity(int id) {
	for (Coach* coach : allCoachs) {
		if (coach->getId() == id) {
			return true;
		}
	}
	return false;
}
bool Club::CheckCourtValidity(int id) {
	for (Court* court : allCourts) {
		if (court->getId() == id) {
			return true;
		}
	}
	return false;
}
void Club::AddCourt(int Id, char type, char size) {
#if 1
	//add failed case, court already exists or exceed the max number
	if (CheckCourtValidity(Id)) {
		cout << "Input id already exists a court!" << endl;
		return;
	}
	else {
		if (getCourtNumber() >= MaxCourtNumber) {
			//print default value
			cout << "Add failed! Court number reached max number: " << MaxCourtNumber << "!" << endl;
			return;
		}
		else if (type != 'I' && type != 'O') {
			cout << "Ileagal type input!" << endl;
			return;
		}

		else if (size != 'L' && size != 'M' && size != 'S') {
			cout << "Ileagal size input!" << endl;
			return;
		}
	}
#endif
#if 0
	for (Court* court : allCourts) {
		//use method check validity
			//cout << "court id: " << court->getId() << endl;
		if (court->getId() == Id) {
			cout << "Input id already exists a court!" << endl;
			return;
		}
		else if (getCourtNumber() >= MaxCourtNumber) {
			//print default value
			cout << "Add failed! Court number reached max number: " <<MaxCourtNumber<<"!"<< endl;
			return;
		}
		else if(type!= 'I' && type!= 'O') {
			cout << "Ileagal type input!" << endl;
			return;
		}

		else if (size != 'L' && size != 'M' && size != 'S') {
			cout << "Ileagal size input!" << endl;
			return;
		}
	}
#endif
	//add court to the club
	Court* court = new Court(Id, type, size);//create the court
	allCourts.push_back(court);
	cout << "current court number: " << getCourtNumber() << endl;
}
void Club::AddPlayer(string name, int id, int experience, float winRate) {
	if (CheckPlayerValidity(id)) {
		cout << "Input id already exists a player!" << endl;
		return;
	}
	else {
		if (getPlayerNumber() >= MaxPlayerNumber) {
			cout << "Add failed! Player number reached max " << MaxPlayerNumber << endl;
			return;
		}
	}
#if 0
	//add failed case, player already exists or exceed the max number MaxPlayerNumber
	for (Player* player : allPlayers) {
		if (player->getId() == id) {
			cout << "Input id already exists a player!" << endl;
			return;
		}
		else if (getPlayerNumber() >= MaxPlayerNumber) {
			cout << "Add failed! Player number reached max " <<MaxPlayerNumber<< endl;
			return;
		}
	}
#endif
	//add player to the club
	Player* player = new Player(name, id, experience, winRate);
	allPlayers.push_back(player);
	updatePlayerData(player->getId());
	cout << "Current player number: " << getPlayerNumber() << endl;
}
void Club::AddCoach(string name, int id, int experience) {
	if (CheckCoachValidity(id)) {
		cout << "Input id already exists a coach!" << endl;
		return;
	}
	else {
		if (getCoachNumber() >= MaxCoachNumber) {
			cout << "Add failed! Coach number reached max 10!" << endl;
			return;
		}
	}
#if 0
	//add failed cases, coach already exist or exceed the max number 10
	for (Coach* coach : allCoachs) {
		if (coach->getId() == id) {
			cout << "Input id already exists a coach!" << endl;
			return;
		}
		else if (getCoachNumber() >= MaxCoachNumber) {
			cout << "Add failed! Coach number reached max 10!" << endl;
			return;
		}
	}
#endif
	//add coach to the club
	Coach* coach = new Coach(name, id, experience);
	allCoachs.push_back(coach);
	updateCoachData(coach->getId());
	cout << "Current coach number: " <<getCoachNumber() << endl;
}
void Club::RemoveCourt(int id) {
	for (Court* court : allCourts) {
		//find it
		if (court->getId() == id) {
			//empty content
			if (court->getCoachNumber() == 0) {
				allCourts.remove(court);
				cout << "This court removed successful!" << endl;
				return;
			}
			else {//not empty	
				//here need get all the coach id and use reassign to make current court empty
#if 1
				court->fireAllCoach(id,this);
				/*int newId = 0;
				cin >> newId;
				if (newId == id) {
					cout << "Ileagal operation! You can't assign this coach!" << endl;
					return;
				}*/
				allCourts.remove(court);
				cout << "This court removed successful!" << endl;
				return;
			}
		}
		else {
			//didn't exist corresponding court id
			cout << "Input court id is not exist!" << endl;
			return;
#endif
#if 0
				//have to return list to get coach id in  club method "ReassignCoachToCourt
				list<Coach*>courtCoachList = court->getCourtCoaches();
				for (Coach* coach : courtCoachList) {
					cout << "Please find another court to place current court's coach(id:  " << coach->getId() << "): ";
					court->releaseCoach(*coach);
					int newId = 0;
					cin >> newId;
					if (newId == id) {
						cout << "Ileagal operation! You can't assign this coach!" << endl;
						return;
					}
					ReassignCoachToCourt(coach->getId(), newId);
				}
				allCourts.remove(court);
				cout << "This court removed successful!" << endl;
				return;
			}
		}
		else {
			//didn't exist corresponding court id
			cout << "Input court id is not exist!" << endl;
			return;
#endif
		}
	}
}
void Club::RemoveCoach(int id) {
	for (Coach* coach : allCoachs) {
		//find it
		if (coach->getId() == id) {
			//empty content
			if (coach->getPlayerNumber() == 0) {
				allCoachs.remove(coach);
				Court* court = findCoachAssigned(id);
				if (court != nullptr) {
					court->releaseCoach(*coach);
				}
				cout << "This coach already fired!" << endl;
				return;
			}
			else {//not empty
				//here need get all the player id and use reassign to make current coach empty
#if 1
				coach->fireAllPlayer(id, this);
				/*int newId = 0;
				cin >> newId;
				if (newId == id) {
					cout << "Ileagal operation! You can't assign this coach!" << endl;
					return;
				}*/
				allCoachs.remove(coach);
				cout << "This court removed successful!" << endl;
				return;
			}
		}
		else {
			//didn't exist corresponding court id
			cout << "Input court id is not exist!" << endl;
			return;
#endif
#if 0
				cout << "Please enter another coach's id to place current coach's player: ";
				list<Player*>coachPlayerList = coach->getCoachPlayers();
				for (Player* player : coachPlayerList) {
					coach->releasePlayer(*player);
					//find another existing coach, if not exist return wrong case
					int newId = 0;
					cin >> newId;
					if(newId == id){
						cout << "Ileagal operation! You can't assign this player!" << endl;
						return;
					}
					ReassignPlayerToCoach(player->getId(), newId);
				}
				allCoachs.remove(coach);
				Court* court = findCoachAssigned(id);
				if (court != nullptr) {
					court->releaseCoach(*coach);
				}
				//here also require to release the linkage between coach and court
				cout << "This coach already fired!" << endl;
				return;
			}
		}
		else {
			//didn't exist corresponding coach id
			cout << "Input coach id is not exists!" << endl;
			return;
#endif
		}
	}
}
void Club::RemovePlayer(int id) {
	for (Player* player : allPlayers) {
		//find it
		if (player->getId() == id) {
			//class player has no content
			allPlayers.remove(player);
			Coach* coach = findPlayerAssigned(id);
			if (coach != nullptr) {
				coach->releasePlayer(*player);
			}
			cout << "This player already fired!" << endl;
			return;
		}
		else {
			//didn't exist corresponding player id
			cout << "Input player id is not exists!" << endl;
			return;
		}
	}
}
void Club::PrintCoach(int courtId) {
	if (!(CheckCourtValidity(courtId))) {
		cout << "Input id corresponds with no court!" << endl;
		return;
	}
	//REQUIRE UPDATE IN THE SAME CLASS PLACES
	for (Court* court : allCourts) {
		//find the court
		if (court->getId() == courtId) {
			court->printCoachList();
			//change it with new nethod in court print coaches without parameter******
			//get current court's all coaches
#if 0
			list<Coach*>courtCoachList = court->getCourtCoaches();
			for (Coach* coach : courtCoachList) {
		//all the details should be in class coach, another print coach 
				coach->printCoach();
			}
			return;
#endif
			if (court->getCoachNumber() == 0) {
				cout << "The court's coach list is empty!" << endl;
			}
		}
	}
	
}
void Club::PrintPlayer(int coachId) {
	if (!(CheckCoachValidity(coachId))) {
		cout << "Input id corresponds with no coach!" << endl;
		return;
	}
	for (Coach* coach : allCoachs) {
		//find the coach
		if (coach->getId() == coachId) {
			coach->printPlayerList();
#if 0
			//get current coach's all players
			list<Player*>coachPlayerList = coach->getCoachPlayers();
			for (Player* player : coachPlayerList) {
				player->printPlayer();
			}
			return;
#endif
			if (coach->getPlayerNumber() == 0) {
				cout << "The coach's player list is empty!" << endl;
			}
		}
	}
}
void Club::PrintClub(int clubId) {
	if (this->id == clubId) {
		cout << "Club name: " << this->name << "  id:" << this->id << "   max court number: " << this->maxCourt << "   location: " << this->location << " " << endl;
	}
	else
	{
		cout << "Input club id corresponding no club!" << endl;
	}
}
void Club::printCourtList() {
	if (allCourts.empty()) {
		cout << "Court list is empty!" << endl;
		return;
	}
	for (list<Court*>::iterator court = allCourts.begin(); court != allCourts.end(); court++) {
		(*court)->printCourt();
	}
}
void Club::printCoachList() {
	if (allCoachs.empty()) {
		cout << "Coach list is empty!" << endl;
		return;
	}
	for (list<Coach*>::iterator coach = allCoachs.begin(); coach != allCoachs.end(); coach++) {
		(*coach)->printCoach();
	}// int salary, int experience, char qualification
}
void Club::printPlayerList() {
	if (allPlayers.empty()) {
		cout << "Player list is empty!" << endl;
		return;
	}
	for (list<Player*>::iterator player = allPlayers.begin(); player != allPlayers.end(); player++) {
		(*player)->printPlayer();
	}
}
size_t Club::getCourtNumber() {
	return allCourts.size(); 
}
size_t Club::getCoachNumber() {
	return allCoachs.size(); 
}
size_t Club::getPlayerNumber() {
	return allPlayers.size(); 
}
void Club::updateCoachData(int coachId) {
	for (Coach* coach : allCoachs) {
		//find it
		if (coach->getId() == coachId) {
			//update qualification and salary, 1 year experience with 'D' qualification, salary (2000-10000)
			//2 year experience with 'C' qualification, salary(10000-20000)
			//3 year experience with 'B' qualification, salary(20000-40000)
			//4 year experience with 'A' qualification, salary(40000-70000)
			if (coach->getExperience() == 1) {
				coach->modifyQualification('D');
				coach->modifySalary('D');
			}
			else if (coach->getExperience() == 2) {
				coach->modifyQualification('C');
				coach->modifySalary('C');
			}
			else if (coach->getExperience() == 3) {
				coach->modifyQualification('B');
				coach->modifySalary('B');
			}
			else if (coach->getExperience() == 4) {
				coach->modifyQualification('A');
				coach->modifySalary('A');
			}
		}
	}
}
void Club::updatePlayerData(int playerId) {
	for (Player* player : allPlayers) {
		//find it
		if (player->getId() == playerId) {
			//update level and salary,   'D' level: win-rate: under 35, salary (2000-4000), transfer fee: 5000-10000
			//'C' level: win-rate: 35-50, salary(4000-8000), transfer fee: 10000-30000
			//'B' level: win-rate: 50-70, salary(8000-30000), transfer fee: 30000-80000
			//'A' level: win-rate: more than 70, salary(30000-90000), transfer fee: 80000-200000
			if (player->getWinRate() >= 0 && player->getWinRate() < 35) {
				player->modifyLevel('D');
				player->modifySalary('D');
				player->modifyTransferFee('D');
			}
			else if (player->getWinRate() >= 35 && player->getWinRate() < 50) {
				player->modifyLevel('C');
				player->modifySalary('C');
				player->modifyTransferFee('C');
			}
			else if (player->getWinRate() >= 50 && player->getWinRate() < 70) {
				player->modifyLevel('B');
				player->modifySalary('B');
				player->modifyTransferFee('B');
			}
			else if (player->getWinRate() >= 70) {
				player->modifyLevel('A');
				player->modifySalary('A');
				player->modifyTransferFee('A');
			}
		}
	}
}
//remove menu
//void Club::showMenu() {
//	cout << "---------------------------------------------------------------------------------" << endl;
//	//check court list, coach list or player list
//	cout << "--------------------1. Check list information            ------------------------" << endl;
//	//find one member in the club(player or coach)
//	cout << "--------------------2. Check assignment                  ------------------------" << endl;
//	//add player, coach or court
//	cout << "--------------------3. Add member or buy court           ------------------------" << endl;
//	//remove player, coach or sell court
//	cout << "--------------------4. Remove member or sell court       ------------------------" << endl;
//	//modify information of player, coach or court
//	cout << "--------------------5. Member assignment                 ------------------------" << endl;
//	//quit system
//	cout << "--------------------6. Exit system                       ------------------------" << endl;
//	cout << "---------------------------------------------------------------------------------" << endl;
//}
//void Club::interface() {
//	int key = 0;
//	bool circle = false;
//	while (!circle) {
//		showMenu();
//		cout << "Welcome to tennis club manage system! Please enter your choice: ";
//		cin >> key;
//		while (key != 1 && key != 2 && key != 3 && key != 4 && key != 5 && key != 6) {
//			cin >> key;
//			cin.clear();
//			cin.ignore();
//			cout << "Invalid input! Please enter correct option: ";
//		}
//		switch (key) {
//		case 1:
//			int choice1;
//			cout << "-------------------------" << endl;
//			cout << "1. Check court list" << endl;
//			cout << "2. Check coach list" << endl;
//			cout << "3. Check player list" << endl;
//			cout << "-------------------------" << endl;
//			cout << "Please enter which list item you want to check: ";
//			cin >> choice1;
//			while (choice1 != 1 && choice1 != 2 && choice1 != 3) {
//				cin >> choice1;
//				cin.clear();
//				cin.ignore();
//				cout << "Invalid input! Please enter correct option: " << endl;
//			}
//			switch (choice1) {
//			case 1:
//				cout << "-------------------------" << endl;
//				cout << "Court list: " << endl;
//				printCourtList();
//				cout << "-------------------------" << endl;
//				break;
//			case 2:
//				cout << "-------------------------" << endl;
//				cout << "Coach list: " << endl;
//				printCoachList();
//				cout << "-------------------------" << endl;
//				break;
//			case 3:
//				cout << "-------------------------" << endl;
//				cout << "Player list: " << endl;
//				printPlayerList();
//				cout << "-------------------------" << endl;
//				break;
//			default:
//				cin.clear();
//				cin.ignore();
//				break;
//			}
//			break;
//		case 2:
//			int choice2;
//			cout << "-------------------------" << endl;
//			cout << "1. Check coach assignment situation" << endl;
//			cout << "2. Check player assignment situation" << endl;
//			cout << "-------------------------" << endl;
//			cout << "Please enter which assignment situation you want to check: ";
//			cin >> choice2;
//			while (choice2 != 1 && choice2 != 2) {
//				cin >> choice2;
//				cin.clear();
//				cin.ignore();
//				cout << "Invalid input! Please enter correct option: " << endl;
//			}
//			switch (choice2) {
//			case 1:
//				int courtId;
//				cout << "-------------------------" << endl;
//				cout << "Please enter court id: ";
//				cin >> courtId;
//				cout << "-------------------------" << endl;
//				cout <<"Court with id: "<<courtId<<" assignment situation: " << endl;
//				PrintCoach(courtId);
//				cout << "-------------------------" << endl;
//				break;
//			case 2:
//				int coachId;
//				cout << "-------------------------" << endl;
//				cout << "Please enter coach id: ";
//				cin >> coachId;
//				cout << "-------------------------" << endl;
//				cout << "Coach with id: " << coachId << " assignment situation: " << endl;
//				PrintPlayer(coachId);
//				cout << "-------------------------" << endl;
//				break;
//			default:
//				cin.clear();
//				cin.ignore();
//				break;
//			}
//			break;
//		case 3:
//			int choice3;
//			cout << "-------------------------" << endl;
//			cout << "1. Add a coach to the club" << endl;
//			cout << "2. Add a player to the club" << endl;
//			cout << "3. Buy a court to the club" << endl;
//			cout << "-------------------------" << endl;
//			cout << "Please enter your choice: ";
//			cin >> choice3;
//			while (choice3 != 1 && choice3 != 2 && choice3 != 3) {
//				cin >> choice3;
//				cin.clear();
//				cin.ignore();
//				cout << "Invalid input! Please enter correct option: " << endl;
//			}
//			switch (choice3) {
//			case 1:
//			{
//				string coachName;//need brackets to use variable inside 'case'
//				int coachId;
//				int coachExperience;
//				cout << "-------------------------" << endl;
//				cout << "Please enter new coach's name: ";
//				cin.get();
//				getline(cin, coachName);
//				cout << "Please enter new coach's id: ";
//				cin >> coachId;
//				cout << "Please enter new coach's experience: ";
//				cin >> coachExperience;
//				cout << "-------------------------" << endl;
//				AddCoach(coachName, coachId, coachExperience);
//			}
//				break;
//			case 2:
//			{
//				string playerName;
//				int playerId;
//				int playerExperience;
//				float winRate;
//				cout << "-------------------------" << endl;
//				cout << "Please enter new player's name: ";
//				cin.get();
//				getline(cin, playerName);
//				cout << "Please enter new player's id: ";
//				cin >> playerId;
//				cout << "Please enter new player's experience: ";
//				cin >> playerExperience;
//				cout << "Please enter new player's win-rate: ";
//				cin >> winRate;
//				cout << "-------------------------" << endl;
//				AddPlayer(playerName, playerId, playerExperience, winRate);
//			}
//				break;
//			case 3:
//				int courtId;
//				cout << "Please enter new court's id: ";
//				cin >> courtId;
//				cout << "-------------------------" << endl;
//				AddCourt(courtId);
//			default:
//				cin.clear();
//				cin.ignore();
//				break;
//			}
//			break;
//		case 4:
//			int choice4;
//			cout << "-------------------------" << endl;
//			cout << "1. Sell court in the club" << endl;
//			cout << "2. Fire coach in the club" << endl;
//			cout << "3. Fire player in the club" << endl;
//			cout << "-------------------------" << endl;
//			cout << "Please enter your option: ";
//			cin >> choice4;
//			while (choice4 != 1 && choice4 != 2 && choice4 != 3) {
//				cin >> choice4;
//				cin.clear();
//				cin.ignore();
//				cout << "Invalid input! Please enter correct option: " << endl;
//			}
//			switch (choice4) {
//			case 1:
//				int courtID;
//				cout << "-------------------------" << endl;
//				printCourtList();
//				cout << "-------------------------" << endl;
//				cout << "Please enter court id which you want sell: ";
//				cin >> courtID;
//				RemoveCourt(courtID);
//				cout << "-------------------------" << endl;
//				break;
//			case 2:
//				int coachID;
//				cout << "-------------------------" << endl;
//				printCoachList();
//				cout << "-------------------------" << endl;
//				cout << "Please enter coach id whom you want fire: ";
//				cin >> coachID;
//				RemoveCoach(coachID);
//				cout << "-------------------------" << endl;
//				break;
//			case 3:
//				int playerID;
//				cout << "-------------------------" << endl;
//				printPlayerList();
//				cout << "-------------------------" << endl;
//				cout << "Please enter player id whom you want fire: ";
//				cin >> playerID;
//				RemovePlayer(playerID);
//				cout << "-------------------------" << endl;
//				break;
//			default:
//				cin.clear();
//				cin.ignore();
//				break;
//			}
//			break;
//		case 5:
//			int choice5;
//			cout << "-------------------------" << endl;
//			cout << "1. Assign a player to a coach" << endl;
//			cout << "2. Assign a coach to a court" << endl;
//			cout << "-------------------------" << endl;
//			cout << "Please enter your choice: ";
//			cin >> choice5;
//			while (choice5 != 1 && choice5 != 2) {
//				cin >> choice5;
//				cin.clear();
//				cin.ignore();
//				cout << "Invalid input! Please enter correct option: " << endl;
//			}
//			switch (choice5) {
//			case 1:
//			{
//				int CoachId;
//				int PlayerId;
//				cout << "-------------------------" << endl;
//				printCoachList();
//				cout << "-------------------------" << endl;
//				cout << "Please enter the coach id: ";
//				cin >> CoachId;
//				cout << "-------------------------" << endl;
//				printPlayerList();
//				cout << "Please enter the player id: ";
//				cin >> PlayerId;
//				AssignPlayerToCoach(PlayerId, CoachId);
//				cout << "-------------------------" << endl;
//			}
//				break;
//			case 2:
//				int CoachID;
//				int CourtId;
//				cout << "-------------------------" << endl;
//				printCourtList();
//				cout << "-------------------------" << endl;
//				cout << "Please enter the court id: ";
//				cin >> CourtId;
//				cout << "-------------------------" << endl;
//				printCoachList();
//				cout << "Plwase enter the coach id: ";
//				cin >> CoachID;
//				AssignCoachToCourt(CoachID, CourtId);
//				cout << "-------------------------" << endl;
//				break;
//			default:
//				cin.clear();
//				cin.ignore();
//				break;
//			}
//			break;
//		case 6:
//			cout << "Thank you for using my system!" << endl;
//			circle = true;
//			break;
//		default:
//			cin.clear();
//			cin.ignore();
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//}
Club::~Club() {
	while (!allPlayers.empty()) {
		delete allPlayers.front();
		allPlayers.pop_front();
	}
	while (!allCoachs.empty()) {
		delete allCoachs.front();
		allCoachs.pop_front();
	}
	while (!allCourts.empty()) {
		delete allCourts.front();
		allCourts.pop_front();
	}
	cout << "Club: " << this->name << " has been removed" << endl << endl;
}
Court* Club::findCoachAssigned(int coachId) {
	for (Court* court : allCourts) {
		if (court->checkCoachInCourt(coachId)) {
			return court;
		}
	}
	return nullptr;
}
Coach* Club::findPlayerAssigned(int playerId) {
	for (Coach* coach : allCoachs) {
		if (coach->checkPlayerInCoach(playerId)) {
			return coach;
		}
	}
	return nullptr;
}