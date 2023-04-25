#pragma once
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include "Subject.h"

using namespace std;

class SaveandLoad
{
public:
	SaveandLoad();
	~SaveandLoad();

	void saveGame(vector<Subject> subSave);
	void loadGame();
private:
	string subSaveName;
};

