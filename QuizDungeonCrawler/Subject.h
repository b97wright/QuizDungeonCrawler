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

	bool isSubjectQuestionEmpty();

	string returnQuestion(int index);

private:
	string Name;
	vector<string> Q_Guess;
	vector<string> A_Guess;
	int questionRemoveIndex;
};

