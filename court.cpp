#pragma once
#include"court.hpp"
#include"club.hpp"

Court::Court(int Id, char type, char size) {

	this->courtId = Id;
	this->maxCoach = MaxCourtCoachNumber;
	this->courtType = type;
	this->courtSize = size;
}

void Court::linkCoach(Coach& coach) {
	courtCoaches.push_back(&coach);
}

void Court::releaseCoach(Coach& coach) {
	courtCoaches.remove(&coach);
}

int Court::getId() { return courtId; }

size_t Court::getCoachNumber() { return courtCoaches.size(); }

//list<Coach*>Court::getCourtCoaches() { return courtCoaches; }

void Court::printCourt() {
	cout << "Court id: " << this->courtId << "  " << "type: ";
	if (this->courtType == 'I') {
		cout << "Indoor" << "  ";
	}
	else {
		cout << "Outdoor" << "  ";
	}
	cout << "size: ";
	if (this->courtSize == 'L') {
		cout << "Large" << "  ";
	}
	else if (this->courtSize == 'M') {
		cout << "Middle" << "  ";
	}
	else {
		cout << "Small" << "  ";
	}
	cout << endl;
}

void Court::printCoachList() {
	for (Coach* coach : courtCoaches) {
		//all the details should be in class coach, another print coach 
		coach->printCoach();
	}
}

void Court::hireCoach(int coachId) {
	for (Coach* coach : courtCoaches) {
		if (coach->getId() == coachId) {//find coach
			this->linkCoach(*coach);
		}
	}
}

#if 1
void Court::fireAllCoach(int id, Club* club) {
		//Club club(1, "Tennis Club", "Zloty Tarsy", 01);
	for (Coach* coach : courtCoaches) {
		cout << "Please find another court to place current court's coach(id:  " << coach->getId() << "): ";
		this->releaseCoach(*coach);
		int newId = 0;
		cin >> newId;
		if (newId == id) {
			cout << "ileagal operation! You can't assign this coach!" << endl;
			return;
		}

		club->ReassignCoachToCourt(coach->getId(), newId);
	}
}
//				//have to return list to get coach id in  club method "ReassignCoachToCourt
//				list<Coach*>courtCoachList = court->getCourtCoaches();
//				for (Coach* coach : courtCoachList) {
//					cout << "Please find another court to place current court's coach(id:  " << coach->getId() << "): ";
//					court->releaseCoach(*coach);
//					int newId = 0;
//					cin >> newId;
//					if (newId == id) {
//						cout << "Ileagal operation! You can't assign this coach!" << endl;
//						return;
//					}
//					ReassignCoachToCourt(coach->getId(), newId);
//				}
//				allCourts.remove(court);
//				cout << "This court removed successful!" << endl;
//				return;
//			}
//		}
//		else {
//			//didn't exist corresponding court id
//			cout << "Input court id is not exist!" << endl;
//			return;
//#endif
#endif
/*void printCoachList() {
	if (courtCoaches.empty()) {
		cout << "Current court's coach list is empty!" << endl;
		return;
	}
	for (list<Coach*>::iterator it = courtCoaches.begin(); it != courtCoaches.end(); it++) {
		cout << "Coach name: " << (*it)->getCoachName() << "  id:" << (*it)->getId()
			<< "  salary:" << (*it)->getSalary() << "  experience:" << (*it)->getExperience()
			<< "  qualification:" << (*it)->getQualification() << "  " << endl;
	}
}*/

Court::~Court() {
	courtCoaches.clear();
	cout << "Court with id: " << this->courtId << " has been removed" << endl << endl;
}

bool Court::checkCoachInCourt(int coachId) {
	if (courtCoaches.empty()) {
		return 0;
	}
	else {
		for (Coach* coach : courtCoaches) {
			if (coach->getId() == coachId)
				return 1;
		}
		return 0;
	}
}