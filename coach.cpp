#include"coach.hpp"
#include"club.hpp"
void Coach::linkPlayer(Player& player) {
	coachPlayers.push_back(&player);
}
void Coach::releasePlayer(Player& player) {
	coachPlayers.remove(&player);
}
int Coach::getId() { return id; }
//void printPlayerList() {
//	if (coachPlayers.empty()) {
//		cout << "Current coach's player list in empty!" << endl;
//		return;
//	}
//	for (list<Player*>::iterator it = coachPlayers.begin(); it != coachPlayers.end(); it++) {
//		cout << "Player name: " << (*it)->getPlayerName() << "  id: " << (*it)->getId()
//			<< "  tansfer fee: " << (*it)->getTransferFee() << "  experience: " << (*it)->getExperience()
//			<< "  salary: " << (*it)->getSalary() << "  win rate: " << (*it)->getWinRate() << "  level: " << (*it)->getLevel() << endl;
//	}
//}
size_t Coach::getPlayerNumber() { return coachPlayers.size(); }

int Coach::getExperience() { return this->experience; }

//list<Player*>Coach::getCoachPlayers() { return coachPlayers; }
void Coach::modifyQualification(char qualification) {
	this->qualification = qualification;
}
void Coach::modifySalary(char qualification) {
	srandSeed();
	if (qualification == 'D') {
		this->salary = rand() % 2000 + 8000;
	}
	else if (qualification == 'C') {
		this->salary = rand() % 10000 + 10000;
	}
	else if (qualification == 'B') {
		this->salary = rand() % 20000 + 20000;
	}
	else if (qualification == 'A') {
		this->salary = rand() % 40000 + 70000;
	}
}
void Coach::srandSeed() {
	srand((unsigned int)time(NULL));
}

void Coach::printCoach() {
	cout << "Coach name: " << this->name << "  " << "id: " << this->id << "  "
		<< "salary: " << this->salary << "  " << "experience: " << this->experience << "  "
		<< "qualification: " << this->qualification << "  " << endl;
}

void Coach::printPlayerList() {
	for (Player* player : coachPlayers) {
		//all the details should be in class coach, another print coach 
		player->printPlayer();
	}
}
#if 1
void Coach::hirePlayer(int playerId) {
	for (Player* player : coachPlayers) {
		if (player->getId() == playerId) {//find coach
			this->linkPlayer(*player);
		}
	}
}
#endif

Coach::~Coach() {
	coachPlayers.clear();
	cout << "Coach with id: " << this->id << " has been removed" << endl << endl;
}

bool Coach::checkPlayerInCoach(int playerId) {
	if (coachPlayers.empty()) {
		return 0;
	}
	else {
		for (Player* player : coachPlayers) {
			if (player->getId() == playerId)
				return 1;
		}
		return 0;
	}
}

void Coach::fireAllPlayer(int id, Club* club) {
	for (Player* player : coachPlayers) {
		cout << "Please find another coach to place current coach's player(id:  " << player->getId() << "): ";
		this->releasePlayer(*player);
		int newId = 0;
		cin >> newId;
		if (newId == id) {
			cout << "ileagal operation! You can't assign this player!" << endl;
			return;
		}

		club->ReassignPlayerToCoach(player->getId(), newId);
	}
}