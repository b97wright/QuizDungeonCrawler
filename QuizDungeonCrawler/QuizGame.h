#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Subject.h"
#include "SaveandLoad.h"
#include "Player.h"

using std::vector;

class QuizGame
{
public:
	QuizGame();
	~QuizGame();

	// Main Menu
	void mainMenu();
	void playGame();
	void loadGame();
	void saveGame();
	void editGame();
	void howToPlay();

	// Edit Menu
	void addSubject();
	void removeSubject();
	void printSubject();
	void editSubject();

	// Edit Subject Menu
	void editSubjectMenu(int index);
	void addQuestion(int index);
	void removeQuestion(int index);
	void printQuestion(int index);
	void editQuestion(int index);

	// Play Game CHANGE THIS
	bool areSubjectsEmpty();
	bool areQuestionsPresent();
	bool compareGuessandAnswer(string userGuess, string answer);
	string getUsername();
	string getUserGuess();
	int selectSubject();
	int getRandomIndexSubject();
	int getRandomIndexQuestion(int currentIndex);
	string toLowerString(string str)
	{
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}

private:
	// Vectors 
	vector<Subject> subjects;
	SaveandLoad saveandload;
};

