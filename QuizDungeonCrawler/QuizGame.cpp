#include "QuizGame.h"

QuizGame::QuizGame()
{
}

QuizGame::~QuizGame()
{
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: mainMenu
	Description: This function is the main control loop of the entire program. It's a function that runs in a loop,
	repeatedly displaying a menu to the user and responding to the user's input.
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::mainMenu()
{
	// Variables
	// Bool
	bool quitGame = false;
	// Int
	int menuSelect = 0;

	while (!quitGame)
	{
		// Main Menu
		std::cout << "---------- Main Menu ----------" << std::endl;
		std::cout << "Select a number in the menu to continue. " << std::endl;
		std::cout << "1) - Play Game -" << std::endl;
		std::cout << "2) - Load Game -" << std::endl;
		std::cout << "3) - Save Game -" << std::endl;
		std::cout << "4) - Edit Game -" << std::endl;
		std::cout << "5) - How To Play -" << std::endl;
		std::cout << "6) - Quit -" << std::endl << std::endl;
		std::cout << "Main Menu Choice: ";

		// Input Validation to make sure the user is inputting the right information.
		if (std::cin >> menuSelect)
		{
			std::cout << std::endl;

			// Switch Case for Menu Select
			switch (menuSelect)
			{
			case 1:
			{
				playGame();
				break;
			}
			case 2:
			{
				loadGame();
				break;
			}
			case 3:
			{
				saveGame();
				break;
			}
			case 4:
			{
				editGame();
				break;
			}
			case 5:
			{
				howToPlay();
				break;
			}
			case 6:
			{
				std::cout << "Thank you for playing!!!" << std::endl;
				std::cout << "Have a fun day!!!" << std::endl;
				std::cout << "Good luck with your Studies!!!" << std::endl;
				quitGame = true;
				break;
			}
			default:
			{
				std::cout << "Invalid choice, please select a number between 1 and 6." << std::endl;
				break;
			}
			}

		}
		else
		{
			// User entered the wrong information, also clearing the input buffer as well
			std::cout << "" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: playGame
	Description: This function is the is going to be the main function responsible for playing the game. Allowing the player
	to pick either one subject or all subject, to be quized on the subjects while being in the dungeon.
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::playGame()
{
	// Variables
	int currentIndex = 0;
	string userName, userGuess, correctAnswer;
	bool isGameRunning = true;
	// In the future do this in the subjects to keep track easier
	vector<int> questionTracker;
	srand(time(nullptr));

	// Check to see if Subjects is Empty
	if (areSubjectsEmpty())
	{
		std::cout << "You have no subjects present!" << std::endl;
		std::cout << "Please add Subjects before procceding!" << std::endl;
		return;
	}


	// Check for Questions and Answers in each Subject
	if (areQuestionsPresent())
	{
		std::cout << "You have one or more subjects with Empty Questions!" << std::endl;
		std::cout << "Please questions to those subjects before procceding!" << std::endl;
		return;
	}
	
	// Initialize the Player Character with a unique UserName
	Player player1(getUsername());

	while (isGameRunning)
	{
		// Variables
		// In the future get a functions for return a random Index for subject Index, and for Questions
		int randomQuestionNum = getRandomIndexQuestion(currentIndex);

		system("CLS");
		player1.DisplayInfo();
		// Display Monster

		std::cout << subjects[currentIndex].returnQuestion(randomQuestionNum) << std::endl;
		correctAnswer = subjects[currentIndex].returnAnswer(randomQuestionNum);
		userGuess = getUserGuess();

		correctAnswer = toLowerString(correctAnswer);
		userGuess = toLowerString(userGuess);

		if (compareGuessandAnswer(userGuess, correctAnswer))
		{
			std::cout << "Correct...The answer was " << correctAnswer << std::endl;
			std::cout << "You can attack the monster..." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Incorrect...The answer was " << correctAnswer << std::endl;
			std::cout << "You get attacked the monster..." << std::endl;
			player1.takeAtkOnVit(player1.calAtk(), player1.calDef());
			std::cout << std::endl;
		}

		if (player1.getVit() <= 0)
		{
			isGameRunning = false;
		}

	}

	std::cout << std::endl;
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: loadGame
	Description: This function is responsible for loading the game. From loading the subjects, questions, and answers to the 
	players stats, and current floor level. 
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::loadGame()
{
	std::cout << "Please wait while we load the game from your last save data!" << std::endl;
	subjects = saveandload.loadGame(subjects);
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: saveGame
	Description: This function is responsible for saving the game. From loading the subjects, questions, and answers to the
	players stats, and current floor level.
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::saveGame()
{
	std::cout << "Please wait while we save the game to your local save location!" << std::endl;
	saveandload.saveGame(subjects);
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: editGame
	Description: This function is responsible for editing thegame, from editing subjects, questions, and answers.
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::editGame()
{
	// Variables
	// Int
	int editSelect = 0;
	// Bool
	bool isEdit = true;

	while (isEdit)
	{
		// Edit menu
		std::cout << "---------- Edit Menu ----------" << std::endl;
		std::cout << "Select a number in the menu to continue. " << std::endl;

		// If Subjects are empty, Only let user Add a subject, otherwise offer them the full menu
		if (!subjects.empty())
		{
			std::cout << "1) - Add A Subject -" << std::endl;
			std::cout << "2) - Remove a Subject -" << std::endl;
			std::cout << "3) - Print Subject -" << std::endl;
			std::cout << "4) - Edit A Subject -" << std::endl;
		}
		else
		{
			std::cout << "1) - Add A Subject -" << std::endl;
		}

		std::cout << "5) - Return To Main Menu -" << std::endl;
		std::cout << "6) - Quit -" << std::endl << std::endl;
		std::cout << "Main Menu Choice: ";

		// Input Validation for the edit menu
		if (std::cin >> editSelect)
		{
			std::cout << std::endl;

			switch (editSelect)
			{
			case 1:
			{
				addSubject();
				break;
			}
			case 2:
			{
				removeSubject();
				break;
			}
			case 3:
			{
				printSubject();
				break;
			}
			case 4:
			{
				editSubject();
				break;
			}
			case 5:
			{
				// Returns User back to the Main Menu 
				std::cout << "Returning Back to Main Menu" << std::endl;
				isEdit = false;
				break;
			}
			case 6:
			{
				std::cout << "Thank you for playing!!!" << std::endl;
				std::cout << "Have a fun day!!!" << std::endl;
				std::cout << "Good luck with your Studies!!!" << std::endl;
				exit(0);
			}
			default:
			{
				break;
			}
			}
		}
		// If User has made a wrong input, notifities user and clears the input stream
		else
		{
			std::cout << "Invalid input, please enter a number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: howToPlay
	Description: This function is responsible for teaching the player
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::howToPlay()
{
	std::cout << "This will tell you the Rules of the Game!!!" << std::endl;
	std::cout << std::endl;
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: addSubject
	Description: This function is responsible for adding a user created subject into the vector of subjects
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::addSubject()
{
	std::string subjectName;

	// Prompt for subject name
	std::cout << "---------- Add Subject ----------" << std::endl;
	std::cout << "Enter the name of the subject you would like to add: " << std::endl;

	// Get the subject name, including spaces
	std::cin.ignore(); // Clear out the newline character from the previous input
	std::getline(std::cin, subjectName);

	// Input validation
	if (subjectName.empty())
	{
		std::cout << "Subject name cannot be empty. Please try again." << std::endl;
		return;
	}

	for (const auto& subject : subjects)
	{
		if (subject.getSubjectName() == subjectName)
		{
			std::cout << "This subject already exists. Please try again." << std::endl;
			return;
		}
	}

	// Add the subject to the list
	subjects.push_back(Subject(subjectName));
	std::cout << subjectName << " has been added successfully.\n" << std::endl;
}


/*---------------------------------------------------------------------------------------------------------------------------
	Function: removeSubject
	Description: This function is responsible for removing a user created subject into the vector of subjects
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::removeSubject()
{
	// Variables
	// int
	int editRemoveIndex = -1;
	// bool
	bool removingSubject = true;

	std::cout << "---------- Remove Subject ----------" << std::endl;
	// Check if subjects is empty
	if (subjects.empty())
	{
		std::cout << "You have no subjects present!" << std::endl;
		return;
	}

	printSubject();

	while (removingSubject)
	{
		std::cout << "Which subject would you like to be removed, please select the index, or -1 to go back: ";
		std::cin >> editRemoveIndex;

		// Check if input is valid
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
			continue;
		}

		if (editRemoveIndex == -1)
		{
			removingSubject = false; // Stop the loop if user wants to go back
		}
		else if (editRemoveIndex >= 0 && editRemoveIndex < subjects.size())
		{
			// Once the editRemoveIndex is found, you can use that to remove it from the vector
			subjects.erase(subjects.begin() + editRemoveIndex);
			removingSubject = false;  // Stop the loop after removing the subject
		}
		else
		{
			std::cout << "The number you selected was not a part of the index. \nPlease enter a number between 0 and " << subjects.size() - 1 << std::endl;
		}
	}

	std::cout << std::endl;
}


/*---------------------------------------------------------------------------------------------------------------------------
	Function: printSubject
	Description: This function is responsible for adding a user created subject into the vector of subjects
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::printSubject()
{
	std::cout << "---------- List of Subjects ----------" << std::endl;
	if (subjects.empty() == true)
	{
		std::cout << "There are no subjects to print!" << std::endl;
	}
	for (int i = 0; i < subjects.size(); i++)
	{
		std::cout << i << ") " << subjects[i].getSubjectName() << std::endl;
	}
	std::cout << endl;
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: editSubject
	Description: This function is responsible for editing a user created subject into the vector of subjects
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::editSubject()
{
	// Variables
	// int
	int editSubjectIndex = -1;
	// Bool
	bool editingSubject = true;

	// Check if Subjects is empty
	if (subjects.empty()) {
		std::cout << "No subjects available to edit." << std::endl;
		return;
	}

	printSubject();
	std::cout << "Which subject would you like to edit? Please select the index, or enter -1 to go back: ";
	std::cin >> editSubjectIndex;

	while (editingSubject)
	{
		// Check if input is valid
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
			continue;
		}

		if (editSubjectIndex == -1)
		{
			editingSubject = false;  // User chose to go back
		}
		else if (editSubjectIndex >= 0 && editSubjectIndex < subjects.size())
		{
			editingSubject = false;  // User entered a valid index
			editSubjectMenu(editSubjectIndex);
		}
		else
		{
			std::cout << "The number you selected was not a part of the index. \nPlease enter a number between 0 and " << subjects.size() - 1 << std::endl;
		}

		if (editingSubject)
		{
			std::cout << "Which subject would you like to edit? Please select the index: ";
			std::cin >> editSubjectIndex;
		}
	}
	std::cout << std::endl;
}


/*---------------------------------------------------------------------------------------------------------------------------
	Function: editSubjectMenu
	Description: This function is main control loop for editing a user created subject, from question, answers, and name of 
	the subject.
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::editSubjectMenu(int index)
{
	// Variables
	// Int
	int editSubjectChoice = 0;
	// Bool
	bool isEditSubject = true;

	while (isEditSubject)
	{
		std::cout << "----------" << subjects[index].getSubjectName() << "----------" << std::endl;
		std::cout << "Select a number in the edit subject menu to continue. " << std::endl;

		if (!subjects[index].isSubjectQuestionEmpty())
		{
			std::cout << "1) - Add Questions -" << std::endl;
			std::cout << "2) - Remove a Question -" << std::endl;
			std::cout << "3) - Print Questions -" << std::endl;
			std::cout << "4) - Edit a Question" << std::endl;
		}
		else
		{
			std::cout << "1) - Add Questions -" << std::endl;
		}

		std::cout << "5) - Return to Edit Menu -" << std::endl;
		std::cout << "6) - Quit -" << std::endl;
		std::cout << "Subject Menu Choice: ";

		if (std::cin >> editSubjectChoice)
		{
			std::cout << std::endl;
			switch (editSubjectChoice)
			{
			case 1:
				addQuestion(index);
				break;
			case 2:
				if (!subjects[index].isSubjectQuestionEmpty()) {
					removeQuestion(index);
				}
				break;
			case 3:
				if (!subjects[index].isSubjectQuestionEmpty()) {
					printQuestion(index);
				}
				break;
			case 4:
				if (!subjects[index].isSubjectQuestionEmpty()) {
					editQuestion(index);
				}
				break;
			case 5:
				std::cout << "Returning Back to Edit Menu" << std::endl;
				return;
			case 6:
				std::cout << "Quitting game..." << std::endl;
				exit(0);
			default:
				std::cout << "Invalid choice, please select a number from the menu." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Invalid input, please enter a number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: addQuestion
	Description: This function is responsible for adding a user created question into the vector of questions, and answers
	into the vector of answers
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::addQuestion(int index)
{
	std::cout << "----------" << subjects[index].getSubjectName() << "----------" << std::endl;
	subjects[index].sAddQuestion();
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: removeQuestion
	Description: This function is responsible for adding a user created question into the vector of questions, and answers
	into the vector of answers
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::removeQuestion(int index)
{
	std::cout << "----------" << subjects[index].getSubjectName() << "----------" << std::endl;
	subjects[index].sRemoveQuestion();
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: removeQuestion
	Description: This function is responsible for printing a user created question into the vector of questions, and answers
	into the vector of answers
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::printQuestion(int index)
{
	std::cout << "----------" << subjects[index].getSubjectName() << "----------" << std::endl;
	subjects[index].sPrintQuestions();
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: editQuestion
	Description: This function is responsible for editing the questions and answers.
---------------------------------------------------------------------------------------------------------------------------*/
void QuizGame::editQuestion(int index)
{

}

bool QuizGame::areSubjectsEmpty()
{
	if (subjects.empty())
	{
		return true;
	}
	return false;
}

bool QuizGame::areQuestionsPresent()
{
	// Variables
	bool isQuestionsEmpty = false;

	for (int i = 0; i < subjects.size(); i++)
	{
		if (subjects[i].getQuestionSize() <= 0)
		{
			std::cout << subjects[i].getSubjectName() << " subject has no qestions." << std::endl;
			std::cout << "Please add question and answers to that subject before play the game!" << std::endl;
			isQuestionsEmpty = true;
		}
	}
	return isQuestionsEmpty;
}

bool QuizGame::compareGuessandAnswer(string userGuess, string answer)
{
	if (userGuess.compare(answer) == 0)
	{
		return true;
	}
	return false;
}

/*---------------------------------------------------------------------------------------------------------------------------
	Function: getUsername
	Description: This function is responsible for getting the name the user wants to be called by when playing the game.
---------------------------------------------------------------------------------------------------------------------------*/
string QuizGame::getUsername()
{
	// Variables
	string userName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

	std::cout << "Please Enter a User Name: ";
	std::getline(std::cin, userName);
	std::cout << std::endl;

	return userName;
	// NOTE To Self: The issue I think it was having was the input buffer was not cleared out so I had to clear out the input buffer 
	// in order to proceed with the code. It was skipping lines 630 - 632 because of this. Having like 628 is clearing the buffer
	// so that the user can add a usernanme as normal. 
}

string QuizGame::getUserGuess()
{
	// Variables
	string userGuess;

	std::getline(std::cin, userGuess);
	return userGuess;
}

int QuizGame::getRandomIndexQuestion(int currentIndex)
{
	//Variables
	srand(time(nullptr));
	int randomQuestionNum = rand() % subjects[currentIndex].getQuestionSize();
	

	return randomQuestionNum;
}


