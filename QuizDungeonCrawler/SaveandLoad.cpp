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
				inputIntoFile = subSave[i].returnAnswer(j);
				myFile << inputIntoFile << endl;
			}
			myFile << "END File";
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
    const string directory = "F:\\Documents\\Visual Studio Community Code\\QuizDungeonCrawler\\QuizDungeonCrawler\\SaveData\\";
    bool wasSubEmpty = true;
    vector<string> questions;
    vector<string> answers;
    bool isQuestion = true;

    for (const auto& file : std::filesystem::directory_iterator(directory))
    {
        wasSubEmpty = false;
        if (file.is_regular_file())
        {
            string fileName = file.path().filename().string();
            size_t dotPosition = fileName.find_last_of('.');
            fileName = fileName.substr(0, dotPosition);
            cout << "FileName: " << fileName << endl;

            subLoad.push_back(fileName);

            // Get a reference to the last added Subject
            Subject& currentSubject = subLoad.back();

            ifstream ifs(file.path().string());

            if (ifs.is_open())
            {
                string line;
                // Clear questions and answers vectors for each file
                questions.clear();
                answers.clear();
                while (getline(ifs, line))
                {
                    if (line != "END File")
                    {
                        if (isQuestion)
                        {
                            questions.push_back(line);
                            isQuestion = false;
                        }
                        else
                        {
                            answers.push_back(line);
                            isQuestion = true;
                        }
                    }
                    else
                    {
                        break;
                    }

                }
                currentSubject.lAddQuestion(questions, answers);
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
}

