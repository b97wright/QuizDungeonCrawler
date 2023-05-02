#include "QuizGame.h"

QuizGame::QuizGame()
{
	mainIsPlaying = true;
	isInGame = true;
	isEdit = true;
	isEditSubject = true;
	menuChoice = -1;
	editChoice = -1;
	editSubjectChoice = -1;
	editRemoveIndex = -1;
	editSubjectIndex = -1;
}

QuizGame::~QuizGame()
{
}

// ---------- Main Menu ----------
// ---------- mainMenu ----------
/* -------------------------------
This is where you will be able to branch 
off between the different parts of the 
game, wether that is playing, loading, 
saving, editing or simply learn how to 
play the game
   ------------------------------- */
void QuizGame::mainMenu()
{
	while (mainIsPlaying)
	{
		// Main Menu 
		cout << "---------- Main Menu ----------" << endl;
		cout << "Select a number in the menu to continue. " << endl;
		cout << "1) - Play Game -" << endl;
		cout << "2) - Load Game -" << endl;
		cout << "3) - Save Game -" << endl;
		cout << "4) - Edit Game -" << endl;
		cout << "5) - How To Play -" << endl;
		cout << "6) - Quit -" << endl;
		cout << "Main Menu Choice: ";
		cin >> menuChoice;
		cout << endl;

		// Switch Menu for the Main Menu Choice
		switch (menuChoice)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			// Line 
			loadGame();
			break;
		}
		case 3:
		{
			// Line 
			saveGame();
			break;
		}
		case 4:
		{
			// Line 
			editGame();
			break;
		}
		case 5:
		{
			// Line 
			howToPlay();
			break;
		}

		case 6:
		{
			cout << "Thank you for playing!!!" << endl;
			cout << "Have a fun day!!!" << endl;
			cout << "Good luck with your Studies!!!" << endl;
			mainIsPlaying = false;
			break;
		}
		default:
		{
			break;
		}
		}

	}
}

// ---------- playGame ----------
/* -------------------------------
This is the function that is responsible 
for leading the play to be able to start 
the game. This function will lead the player 
into setting up the game an other nemours parts 
that the player will have to do in order to 
set the game up. 

TODO: Make the Play Game Function part of the game,
also set up the Enitity Class, Player Class, Enemy Class 
   ------------------------------- */
void QuizGame::playGame()
{
	int index;
	printSubject();
	cout << "\nSelect a Subject that you would like to be tested in: " << endl;
	cin >> index;

	// this is just a sample

}

// ---------- loadGame ----------
/* -------------------------------
This is the function that is responsible
for allow the player to load the game with 
the subjects, questions and player data 
for the game. 

TODO: need to load the player Data 
   ------------------------------- */
void QuizGame::loadGame()
{
	cout << "Please wait while we load the game from your last save data!" << endl;
	subjects = saveandload.loadGame(subjects);
}

// ---------- saveGame ----------
/* -------------------------------
This is the function that is responsible
for allow the player to save the game with
the subjects, questions and player data
for the game.

TODO: need to save the player Data
   ------------------------------- */
void QuizGame::saveGame()
{
	cout << "Please wait while we save the game to your local save location!" << endl;
	saveandload.saveGame(subjects);
}

// ---------- editGame ----------
/* -------------------------------
This is the function that is responsible
for allow the player to edit the game. 
This is for the difficulty for the game, 
edit the subjects for the game as well 
that the player will use in game. 

TODO: Edit the play game settings, 
how hard the game is
   ------------------------------- */
void QuizGame::editGame()
{
	while (isEdit)
	{
		// Edit Menu
		cout << "---------- Edit Game ----------" << endl;
		cout << "Select a number in the edit menu to continue. " << endl;
		cout << "1) - Add a Subject -" << endl;
		cout << "2) - Remove a Subject -" << endl;
		cout << "3) - Print Subject -" << endl;
		cout << "4) - Edit a Subject" << endl;
		cout << "5) - Return to Main Menu -" << endl;
		cout << "Edit Game Choice: ";
		cin >> editChoice;
		cout << endl;

		// This If statement is checking to see if subjects is empty and it will fire but only if the player does not pick 
		// option 5 or 1. 
		if (subjects.empty() == true && editChoice != 5 && editChoice != 1)
		{
			cout << "Please add a subject(s) before wanting to remove, edit or print a subject(s)!\n" << endl;
		}
		else
		{
			// Switch statement for Edit Menu
			switch (editChoice)
			{
			case 1:
			{
				// Line 
				addSubject();
				break;
			}
			case 2:
			{
				// Line
				removeSubject();
				break;
			}
			case 3:
			{
				// Line
				printSubject();
				break;
			}
			case 4:
			{
				// Line
				editSubject();
				break;
			}
			case 5:
			{
				// Returns User back to the Main Menu 
				cout << "Returning Back to Main Menu" << endl;
				isEdit = false;
				break;
			}
			default:
			{
				break;
			}
			}
		}



	}
	isEdit = true;
	cout << endl;
}
// ---------- How To Play ----------
/* -------------------------------
This is the function that is responsible
for teaching the player the ins and outs 
of this small game. This ranges from 
teaching the player how to make subjects 
for them to add questions, to teaching the 
player how to edit the game for play and 
how to do anything else to make this game 
function as intended. 

TODO: Add a How to Play Section
   ------------------------------- */
void QuizGame::howToPlay()
{
	cout << "This will tell you the Rules of the Game!!!" << endl;
	cout << endl;
}

// ---------- Edit Menu ----------
// ---------- addSubject ----------
/* -------------------------------
This is the function that is responsible
for allow the player add a subject vector 
that they want to be able to be tested from 
while playing the game. 

TODO: TBD
   ------------------------------- */
void QuizGame::addSubject()
{
	cout << "---------- Add Subject ----------" << endl;
	cout << "What subject woudl you like to be added: " << endl;
	cin >> subjectName;

	subjects.push_back(Subject(subjectName));
	cout << endl;
}

// ---------- removeSubject ----------
/* -------------------------------
This is the function that is responsible
for allow the player remove a subject vector 
that they want to be able to be tested from
while playing the game.

TODO: TBD
   ------------------------------- */
void QuizGame::removeSubject()
{
	// Debating wether I need this because I already do the check back on line 171, but I will keep it for now. Address Later
	cout << "---------- Remove Question ----------" << endl;
	if (subjects.empty() == true)
	{
		cout << "You have no subjects present!" << endl;;
	}
	else
	{
		printSubject();
		cout << "Which subject would you like to be removed, please select the index, or -1 to go back: ";
		cin >> editRemoveIndex;

		// Need to do a different way in which I check this because having the empty if loop is kinda goofy NGL
		if (editRemoveIndex == -1)
		{

		}
		// What is happening here is we are trying to find the index of the question that you want to remove
		else
		{
			int currentMax = subjects.size();
			while (!(editRemoveIndex >= 0 && editRemoveIndex <= currentMax))
			{
				cout << "The number you selected was not apart of the index. \nPlease enter a number between 0 through " << subjects.size() - 1 << endl;
				cout << "Which subject would you like to be removed, please select the index: ";
				cin >> editRemoveIndex;

			}

			// Once the editRemoveIndex is found, you can use that to remove it from the vector
			subjects.erase(subjects.begin() + editRemoveIndex);
		}
	}
	cout << endl;
}

// ---------- printSubject ----------
/* -------------------------------
This is the function that is responsible
for allow the player print all subject that 
are found in the subjects vector. 

TODO: TBD
   ------------------------------- */
void QuizGame::printSubject()
{
	cout << "---------- List of Subjects ----------" << endl;
	if (subjects.empty() == true)
	{
		cout << "There are no subjects to print!" << endl;
	}
	for (int i = 0; i < subjects.size(); i++)
	{
		cout << i << ") " << subjects[i].getSubjectName() << endl;
	}
	cout << endl;
}

// ---------- editSubject ----------
/* -------------------------------
This is the function that is responsible
for the player to edit a subject of their choosing 
allowing them to progress to the edit subject menu.

TODO: TBD
   ------------------------------- */
void QuizGame::editSubject()
{
	printSubject();
	cout << "Which subject would you like to be edit, please select the index: ";
	cin >> editSubjectIndex;

	int currentMax = subjects.size();
	while (!(editSubjectIndex >= 0 && editSubjectIndex <= currentMax))
	{
		cout << "The number you selected was not apart of the index. \nPlease enter a number between 0 through " << subjects.size() - 1 << endl;
		cout << "Which subject would you like to edit, please select the index: ";
		cin >> editSubjectIndex;
	}
	cout << endl;
	editSubjectMenu(editSubjectIndex);

}

// ---------- Edit Subject Menu ----------
// ---------- editSubject ----------
/* -------------------------------
This is where you will be able to branch
off between the different parts for 
editing a subject. 

TODO: TBD
   ------------------------------- */
void QuizGame::editSubjectMenu(int index)
{
	// FYI the index is there so the code can choose the right index for the Vector of subjects. IE 0 = MATH, 1 = SCIE, etc.
	while (isEditSubject)
	{
		cout << "----------" << subjects[index].getSubjectName() << "----------" << endl;
		cout << "Select a number in the edit subject menu to continue. " << endl;
		cout << "1) - Add Questions -" << endl;
		cout << "2) - Remove a Question -" << endl;
		cout << "3) - Print Questions -" << endl;
		cout << "4) - Edit a Question" << endl;
		cout << "5) - Return to Edit Menu -" << endl;
		cout << "Subject Menu Choice: ";
		cin >> editSubjectChoice;
		cout << endl;

		if (subjects[index].isSubjectQuestionEmpty() == true && editSubjectChoice != 5 && editSubjectChoice != 1)
		{
			cout << "Please add a question(s) in the subject: " << subjects[index].getSubjectName() << " before wanting to remove, edit or print a question(s)!\n" << endl;
		}
		else
		{
			// Main Switch for Subject Choice
			switch (editSubjectChoice)
			{
			case 1:
			{
				// Line
				addQuestion(index);
				break;
			}
			case 2:
			{
				// Line
				removeQuestion(index);
				break;
			}
			case 3:
			{
				// Line
				printQuestion(index);
				break;
			}
			case 4:
			{
				// Line
				printQuestion(index);
				break;
			}
			case 5:
			{
				// Returns back to the Edit Menu
				cout << "Returning Back to Edit Menu" << endl;
				isEditSubject = false;
				break;
			}
			default:
				break;
			}
		}
	}
	isEditSubject = true;
	cout << endl;
}

// ---------- addQuestion ----------
/* -------------------------------
This function links to the add function for
a specific subjects questions. Add a question 
to the specific subjects vector for questions. 

TODO: TBD
   ------------------------------- */
void QuizGame::addQuestion(int index)
{
	cout << "----------" << subjects[index].getSubjectName() << "----------" << endl;
	subjects[index].sAddQuestion();
}

// ---------- removeQuestion ----------
/* -------------------------------
This function links to the remove function for
a specific subjects questions. Remove a specific 
question at the index the user imputs.

TODO: TBD
   ------------------------------- */
void QuizGame::removeQuestion(int index)
{
	cout << "----------" << subjects[index].getSubjectName() << "----------" << endl;
	subjects[index].sRemoveQuestion();
}

// ---------- printQuestion ----------
/* -------------------------------
This function links to the print function for
a specific subjects questions. Pritns all the 
questions for the specific subject.

TODO: TBD
   ------------------------------- */
void QuizGame::printQuestion(int index)
{
	cout << "----------" << subjects[index].getSubjectName() << "----------" << endl;
	subjects[index].sPrintQuestions();
}

// ---------- editQuestion ----------
/* -------------------------------
This is where you will be able to branch
off between the different parts for
editing a subject.

TODO: Finish the edit question function
   ------------------------------- */
void QuizGame::editQuestion(int index)
{

}


