#include "SaveandLoad.h"

SaveandLoad::SaveandLoad()
{
	subSaveName = "";
}

SaveandLoad::~SaveandLoad()
{
}

void SaveandLoad::saveGame(vector<Subject> subSave)
{
	// cout << "---------- List of Subjects ----------" << endl;
	if (subSave.empty() == true)
	{
		cout << "There are no subjects to save!" << endl;
	}
	for (int i = 0; i < subSave.size(); i++)
	{
		// make the save area
		string myFile_Path = "F:\\Documents\\Visual Studio Community Code\\QuizDungeonCrawler\\QuizDungeonCrawler\\SaveData\\" + subSave[i].getSubjectName() + ".txt";
		ofstream myFile(myFile_Path, ofstream::trunc);


		if (myFile.is_open())
		{
			for (int j = 0; j < subSave[i].getQuestionSize(); j++)
			{
				string inputIntoFile;
				inputIntoFile = subSave[i].returnQuestion(j);
				myFile << inputIntoFile << endl;
			}
			myFile << "END OF FILE!";
			myFile.close();
		}
		else
		{
			cout << "Could Not Open File!!!";
		}
	}

	// Save Player Character
	cout << endl;
}

vector<Subject> SaveandLoad::loadGame(vector<Subject> subLoad)
{
	// Load Subjects
	const string directory = "F:\\Documents\\Visual Studio Community Code\\QuizDungeonCrawler\\QuizDungeonCrawler\\SaveData\\";
	bool wasSubEmpty = true;
	int subLoadIndex = -1;
	vector<string> questions;

	for (const auto& file : std::filesystem::directory_iterator(directory))
	{
		subLoadIndex = -1;
		wasSubEmpty = false;
		if (file.is_regular_file())
		{
			string fileName = file.path().filename().string();
			size_t dotPosition = fileName.find_last_of('.');
			fileName = fileName.substr(0, dotPosition);
			cout << "FileName: " << fileName << endl;

			subLoad.push_back(fileName);

			// find where subject index is and use that index to add to the subject questions

			for (int i = 0; i < subLoad.size(); i++)
			{
				if (subLoad[i].getSubjectName() == fileName)
				{
					int subLoadIndex = i;
				}
			}


			ifstream ifs(file.path().string());


			if (ifs.is_open())
			{
				string line;
				while (getline(ifs, line))
				{
					if (line != "END OF FILE!")
					{
						questions.push_back(line);
					}
					
				}
				// Fix this subLoad[subLoadIndex].sAddQuestion();
				ifs.close();
			}
			else
			{
				cout << "Error unable to open file " << file.path().string() << endl;
			}
		}
	}

	if (wasSubEmpty == true)
	{
		cout << "It seem that you have no save files to load from!" << endl;
	}

	return subLoad;
	// Load Player Character 
}
