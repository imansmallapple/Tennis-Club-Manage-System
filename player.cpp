#include"player.hpp"


int Player::getId() { return this->id; }

int Player::getExperience() { return this->experience; }


float Player::getWinRate() { return this->winRate; }

void Player::modifyLevel(char level) {
	this->level = level;
}

void Player::modifySalary(char level) {
	srandSeed();
	if (level == 'D') {
		this->salary = rand() % 2000 + 2000;
	}
	else if (level == 'C') {
		this->salary = rand() % 4000 + 4000;
	}
	else if (level == 'B') {
		this->salary = rand() % 8000 + 22000;
	}
	else if (level == 'A') {
		this->salary = rand() % 30000 + 60000;
	}
}

void Player::modifyTransferFee(char level) {
	srandSeed();
	if (level == 'D') {
		this->transferFee = rand() % 5000 + 5000;
	}
	else if (level == 'C') {
		this->transferFee = rand() % 10000 + 20000;
	}
	else if (level == 'B') {
		this->transferFee = rand() % 30000 + 50000;
	}
	else if (level == 'A') {
		this->transferFee = rand() % 80000 + 120000;
	}
}

void Player::srandSeed() {
	srand((unsigned int)time(NULL));
}

void Player::printPlayer() {
	cout << "Player name: " << this->name << "  " << "id: " << this->id << "  "
		<< "transfer fee: " << this->transferFee << "  " << "experience: " << this->experience << "  "
		<< "salary: " << this->salary << "  " << "win-rate: " << this->winRate << "%  "
		<< "level: " << this->level << "  " << endl;
}
Player::~Player() {
	cout << "Player with id: " << this->id << " has been removed" << endl << endl;
}