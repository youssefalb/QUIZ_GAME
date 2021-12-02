//
// Created by youssef albali on 13-Jun-21.
//

#ifndef MAIN_CPP_FILEMANAGER_H
#define MAIN_CPP_FILEMANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include "Question.h"
#include "Answer.h"
#include <fstream>
class FileManager {

	std::vector<Question*>*_qst;

public:
	bool opened;

	FileManager(std::string filePath,std::vector<Question*>*qst);//qst is a ptr to a vector of pointers of type "Question"
	bool readFile(const std::string &sFileName);
	FileManager(FileManager &&_File);
	~FileManager();
	void operator+=(const std::string &filePath);
	bool WriteToFile(int Total_score,int Possible_pts,const std::string &Outputfile="Results.txt");
};


#endif //MAIN_CPP_FILEMANAGER_H
