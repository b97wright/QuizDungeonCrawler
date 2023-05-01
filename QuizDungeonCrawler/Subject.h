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

	string getSubjectName();
	int getQuestionSize();

	void sAddQuestion();
	void lAddQuestion(vector<string> loadQuestions);
	void sRemoveQuestion();
	void sPrintQuestions();
	void sEditQuestions();

	void generateQuestions();
	string removePunctuation();

	bool isSubjectQuestionEmpty();

	string returnQuestion(int index);

private:
	string Name;
	string CurrentGuessQuestion;
	vector<string> Q_Guess;
	vector<string> A_Guess;
	vector<int> isQuestionUsed;
	int questionRemoveIndex;
};

