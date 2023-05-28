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
	string inputQuestion;
	string inputAnswer;
	bool addingQnA = true;

	std::cout << "---------- Add Question ----------" << std::endl;

	while (addingQnA)
	{
		bool addingAnswer = true;  // Reset addingAnswer to true for each new question

		std::cout << "Enter a question (or -1 to quit): ";
		std::getline(cin, inputQuestion);
		// Quit if the user entered -1
		if (inputQuestion == "-1")
		{
			// If no questions have been added yet, prompt the user to add at least one
			if (Q_Guess.empty()) {
				std::cout << "Please add at least one question before quitting." << std::endl;
				continue;
			}
			else {
				addingQnA = false;
				break;
			}
		}

		// If the input is not empty and not -1, add it to the questions
		if (!inputQuestion.empty() && inputQuestion != "-1")
		{
			Q_Guess.push_back(inputQuestion);

			while (addingAnswer)
			{
				std::cout << "Enter an answer: ";
				std::getline(cin, inputAnswer);
				// If the user enters -1 or an empty answer, remind them to input a valid answer
				if (inputAnswer == "-1" || inputAnswer.empty())
				{
					std::cout << "Please provide a valid answer for the question before quitting or continuing." << std::endl;
					std::cout << "Because you entered a question, you must enter an answer for the question." << std::endl;
				}
				else
				{
					A_Guess.push_back(inputAnswer);
					addingAnswer = false;
				}
			}
		}
	}

	std::cout << std::endl;
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
	// Variable
	bool removingQuestion = true;


	cout << "---------- Remove Question ----------" << endl;
	// Checks to see if the Q_Guess vector is empty
	if (Q_Guess.empty())
	{
		cout << "You have no Questions in " << Name << endl;
		return;
	}

	sPrintQuestions();
	cout << "Which question would you like to be removed, please select the index, or -1 to go back: ";

	while (removingQuestion)
	{
		cin >> questionRemoveIndex;

		if (questionRemoveIndex == -1)
		{
			removingQuestion = false;
		}
		else if (questionRemoveIndex >= 0 && questionRemoveIndex < Q_Guess.size())
		{
			// If the index is found in the vector, we can now remove those values found in the respective index
			Q_Guess.erase(Q_Guess.begin() + questionRemoveIndex);
			A_Guess.erase(A_Guess.begin() + questionRemoveIndex); 
			removingQuestion = false;
		}
		else
		{
			cout << "The number you selected was not part of the index. \nPlease enter a number between 0 through " << Q_Guess.size() - 1 << endl;
			cout << "Which question would you like to be removed, please select the index: ";
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
	if (Q_Guess.empty())
	{
		cout << "You have no Questions in " << Name << endl;
		return;
	}

	sPrintQuestions();
	cout << "Which question would you like to edit, please select the index, or -1 to go back: ";

	bool editingQuestion = true;
	while (editingQuestion)
	{
		cin >> questionEditIndex;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear out the new line character from the previous inputs

		if (questionEditIndex == -1)
		{
			editingQuestion = false;
		}
		else if (questionEditIndex >= 0 && questionEditIndex < Q_Guess.size())
		{
			string question;
			string answer;

			cout << "Please Enter a new Question: " << endl;
			getline(cin, question);
			cout << "Please enter a new Answer for the question: " << endl;
			getline(cin, answer);

			// If the index is valid, we can now edit those values found in the respective index
			Q_Guess[questionEditIndex] = question;
			A_Guess[questionEditIndex] = answer; 
			editingQuestion = false;
		}
		else
		{
			cout << "The number you selected was not part of the index. \nPlease enter a number between 0 through " << Q_Guess.size() - 1 << endl;
			cout << "Which question would you like to be removed, please select the index: ";
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
