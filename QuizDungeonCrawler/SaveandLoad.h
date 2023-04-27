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
	vector<Subject> loadGame(vector<Subject> subSave);
private:
	string subSaveName;
};

