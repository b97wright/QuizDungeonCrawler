#include "Subject.h"

Subject::Subject()
{
	Name = "subject name";
	CurrentGuessQuestion = "-1";
}

Subject::Subject(string sn)
{
	Name = sn;
}

// ---------- getSubjectName ----------
/* -------------------------------
This function returns the name of the 
current classs
   ------------------------------- */
string Subject::getSubjectName()
{
	return Name;
}

// ---------- getQuestionSize ----------
/* -------------------------------
This function returns the size of 
Q_Guess vector
   ------------------------------- */
int Subject::getQuestionSize()
{
	return Q_Guess.size();
}

// ---------- sAddQuestion ----------
/* -------------------------------
This function is responsible for adding
question and answers that the user 
wants to add
   ------------------------------- */
void Subject::sAddQuestion()
{
	int questionCount = 1;
	string inputQuestions;
	string inputAnswers;

	cout << "Add questions/answers for current subject. Or input -1 to quit." << endl;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (inputQuestions != "-1")
	{ // TODO fix this, it is taking an empty string for some reason
		cout << questionCount << ") ";
		getline(cin, inputQuestions);
		if (inputQuestions != "-1")
		{
			Q_Guess.push_back(inputQuestions);
			cout << "Answer: ";
			cin >> inputAnswers;
			A_Guess.push_back(inputAnswers);
			cout << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		questionCount++;
	}
	cout << endl;
}

// ---------- lAddQuestion ----------
/* -------------------------------
This function is responsible for adding
question, used explictedly by the 
saveandload class
   ------------------------------- */
void Subject::lAddQuestion(vector<string> loadQuestions, vector<string> loadAnswers)
{
	for (int i = 0; i < loadQuestions.size(); i++)
	{
		Q_Guess.push_back(loadQuestions[i]);
	}

	for (int i = 0; i < loadAnswers.size(); i++)
	{
		A_Guess.push_back(loadAnswers[i]);
	}
}

// ---------- sEditQuestions ----------
/* -------------------------------
This function is responsible for removing
the questions and answers that are found
Q_Guess, and A_Guess vectors.
   ------------------------------- */
void Subject::sRemoveQuestion()
{
	cout << "---------- Remove Question ----------" << endl;
	// Checks to see if the Q_Guess vector is empty
	if (Q_Guess.empty() == true)
	{
		cout << "You have no Questions in " << Name << endl;;
	}
	else
	{
		sPrintQuestions();
		cout << "Which subject would you like to be removed, please select the index, or -1 to go back: ";
		cin >> questionRemoveIndex;

		if (questionRemoveIndex == -1)
		{

		}
		else
		{
			// What is happening here is we first get the vector size, and make sure that the index can be found in the vector
			int currentMax = Q_Guess.size();
			while (!(questionRemoveIndex >= 0 && questionRemoveIndex <= currentMax))
			{
				cout << "The number you selected was not apart of the index. \nPlease enter a number between 0 through " << Q_Guess.size() - 1 << endl;
				cout << "Which subject would you like to be removed, please select the index: ";
				cin >> questionRemoveIndex;

			}

			// If the index is found in the vector, we can now remove those valeus found in the resective index
			Q_Guess.erase(Q_Guess.begin() + questionRemoveIndex);
		}
	}
	cout << endl;
}

// ---------- sPrintQuestions ----------
/* -------------------------------
This function is responsible for editing
the questions and answers that are found
Q_Guess, and A_Guess vectors.
   ------------------------------- */
void Subject::sPrintQuestions()
{
	cout << "---------- List of Questions ----------" << endl;
	for (int i = 0; i < Q_Guess.size(); i++)
	{
		cout << i << ") " << Q_Guess[i] << endl;
		cout << i << " Answer: " << A_Guess[i] << endl;
	}
	cout << endl;
}

// ---------- sEditQuestions ----------
/* -------------------------------
This function is responsible for editing
the questions and answers that are found
Q_Guess, and A_Guess vectors.
   ------------------------------- */
void Subject::sEditQuestions()
{
	cout << "---------- Edit Question ----------" << endl;
	// Checks to see if the Q_Guess vector is empty
	if (Q_Guess.empty() == true)
	{
		cout << "You have no Questions in " << Name << endl;;
	}
	else
	{
		sPrintQuestions();
		cout << "Which subject would you like to edit, please select the index, or -1 to go back: ";
		cin >> questionEditIndex;

		if (questionEditIndex == -1)
		{

		}
		else
		{
			// What is happening here is we first get the vector size, and make sure that the index can be found in the vector
			int currentMax = Q_Guess.size();
			while (!(questionEditIndex >= 0 && questionEditIndex <= currentMax))
			{
				cout << "The number you selected was not apart of the index. \nPlease enter a number between 0 through " << Q_Guess.size() - 1 << endl;
				cout << "Which subject would you like to be removed, please select the index: ";
				cin >> questionEditIndex;

			}

			string question;
			string answer;

			// If the index is found in the vector, we can now edit those valeus found in the resective index
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please Enter a new Question: " << endl;
			getline(cin, question);
			cout << "Please enter a new Answer for the question: " << endl;
			cin >> answer;

			Q_Guess[questionEditIndex] = question;
			A_Guess[questionEditIndex] = answer;


		}
	}
	cout << endl;
}

// ---------- generateQuestions ----------
/* -------------------------------
This function is responsible for generating 
questions and answers from the Q_Guess vector
so that the guess Questions are random. Takes in 
an index so it knows what question to use. 
   ------------------------------- */
void Subject::generateQuestions(int index)
{
	// Get the question from the index
	// Then you will remove the Punctuation from the question
	// Then you will split the question up into words, IE: i am the dog, I, am, the, dog
	// Then you will pick a word to black out
	// What ever word is blacked out, you will make replace it with _____ for the question on screen
	// The replaced word will be stored in answer so the user can guess the word. 
}

// ---------- removePunctuation ----------
/* -------------------------------
This function is under construction and will
be determined at a later date.
   ------------------------------- */
string Subject::removePunctuation()
{
	return string();
}

// ---------- isSubjectQuestionEmpty ----------
/* -------------------------------
This function return the a boolean 
to check to see if Q_Guess vector is empty
   ------------------------------- */
bool Subject::isSubjectQuestionEmpty()
{
	return Q_Guess.empty();
}


// ---------- returnQuestion ----------
/* -------------------------------
This function return the string found
in the Q_Guess vector at the index.
   ------------------------------- */
string Subject::returnQuestion(int index)
{
	return Q_Guess[index];
}

// ---------- returnAnswer ----------
/* -------------------------------
This function return the string found 
in the A_Guess vector at the index.
   ------------------------------- */
string Subject::returnAnswer(int index)
{
	return A_Guess[index];
}
