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

/*---------------------------------------------------------------------------------------------------------------------------
	Function: getSubjectName
	Description: This function is responsible for returning the name of the current subject that is being used at the moment.
---------------------------------------------------------------------------------------------------------------------------*/
string Subject::getSubjectName() const
{
	return Name;
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: getQuestionSize
	Description: This function is responsible for returning the the size of the Question Vector for the current subject that is
	being used.
---------------------------------------------------------------------------------------------------------------------------*/
int Subject::getQuestionSize()
{
	return Q_Guess.size();
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: sAddQuestion
	Description: This function is responsible for adding questions and answers to the Questions Vector and Answers vector.
---------------------------------------------------------------------------------------------------------------------------*/
void Subject::sAddQuestion()
{
	// Variables
	// int
	int questionCount = -1;
	// string
	string inputQuestions;
	string inputAnswers;

	// Prompt the user to add a question
	cout << "Add questions/answers for current subject. Or input -1 to quit." << endl;

	std::cin.ignore(); // Clear out the new line character from the peverious inputs, if any
	std::getline(std::cin, inputQuestions);
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Input Validation
	while (inputQuestions != "-1")
	{
		Q_Guess.push_back(inputQuestions);

		std::cin.ignore(); // Clear out the new line character from the peverious inputs
		std::getline(std::cin, inputAnswers);

		// Input Validation
		while (inputAnswers != "-1")
		{

		}

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


/*---------------------------------------------------------------------------------------------------------------------------
	Function: lAddQuestion
	Description: This function is responsible for loading questions and answers to the Questions Vector and Answers vector.
---------------------------------------------------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------------------------------------------
	Function: sRemoveQuestion
	Description: This function is responsible forremoving questions and answers to the Questions Vector and Answers vector.
---------------------------------------------------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------------------------------------------
	Function: sPrintQuestions
	Description: This function is responsible for printing questions and answers from the Questions Vector and Answers vector.
---------------------------------------------------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------------------------------------------
	Function: sEditQuestions
	Description: This function is responsible for editing questions and answers from the Questions Vector and Answers vector.
---------------------------------------------------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------------------------------------------
	Function: generateQuestions
	Description: This function is responsible: TBD.
---------------------------------------------------------------------------------------------------------------------------*/
void Subject::generateQuestions(int index)
{
	// Get the question from the index
	// Then you will remove the Punctuation from the question
	// Then you will split the question up into words, IE: i am the dog, I, am, the, dog
	// Then you will pick a word to black out
	// What ever word is blacked out, you will make replace it with _____ for the question on screen
	// The replaced word will be stored in answer so the user can guess the word. 
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: generateQuestions
	Description: This function is responsible: TBD.
---------------------------------------------------------------------------------------------------------------------------*/
string Subject::removePunctuation()
{
	return string();
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: isSubjectQuestionEmpty
	Description: This function is responsible returning if Question Vector is empty
---------------------------------------------------------------------------------------------------------------------------*/
bool Subject::isSubjectQuestionEmpty()
{
	return Q_Guess.empty();
}


/*---------------------------------------------------------------------------------------------------------------------------
	Function: returnQuestion
	Description: This function is responsible returning the question at the index found in the Question Vector
---------------------------------------------------------------------------------------------------------------------------*/
string Subject::returnQuestion(int index)
{
	return Q_Guess[index];
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: returnQuestion
	Description: This function is responsible returning the answer at the index found in the Answer Vector
---------------------------------------------------------------------------------------------------------------------------*/
string Subject::returnAnswer(int index)
{
	return A_Guess[index];
}
