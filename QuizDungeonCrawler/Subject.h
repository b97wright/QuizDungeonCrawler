#pragma once
#include <iostream>
#include <vector>
#include <String>

using namespace std;
using std::vector;
using std::string;

class Subject
{
public:
	Subject();
	Subject(string sn);

	string getSubjectName() const;
	int getQuestionSize();

	void sAddQuestion();
	void lAddQuestion(vector<string> loadQuestions, vector<string> loadAnswers);
	void sRemoveQuestion();
	void sPrintQuestions();
	void sEditQuestions();
	// add change name function

	void generateQuestions(int index);
	string removePunctuation();

	bool isSubjectQuestionEmpty();

	string returnQuestion(int index);
	string returnAnswer(int index);

private:
	string Name;
	string CurrentGuessQuestion;
	vector<string> Q_Guess;
	vector<string> A_Guess;
	string currentGuessQuestion;
	string currentGuessAnswer;
	vector<int> isQuestionUsed;
	int questionRemoveIndex;
	int questionEditIndex;
};

