//
// Created by youssef albali on 13-Jun-21.
//

#include "FileManager.h"

using namespace std;

FileManager::FileManager(std::string filePath, std::vector<Question *> *qst) {
	_qst = qst;
	opened=readFile(filePath);
}

bool FileManager::readFile(const std::string &sFileName) {
	std::ifstream inFile;
	inFile.open(sFileName);

	std::string line;
	if (inFile) {
		//reading lines
		while (getline(inFile, line)) {

			if (!line.empty()) {

				std::string question;
				std::vector<std::string> answers;
				char rightAns;
				int pts;

				size_t place = line.find(';');//it will store the num Of the first semicolon in our line
				question = line.substr(0, place);//assigning the qst

				for (int i = 0; i < 4; ++i) {
					std::string tmp;
					size_t end = line.find(';', place + 1);// the next char
					tmp = line.substr(place + 1, (end - place - 1));
//					place +1 which is the next char to the end -(place + 1)

					place = end;
					answers.push_back(tmp);
				}
				rightAns = line.substr(place + 1).at(0);
				pts = stoi(line.substr(place + 3));
				_qst->push_back(new Question(rightAns, question, answers, pts));//create a new qst object in memory
			}
		}
		inFile.close();
	} else {
		std::cout << "Failed to open input file: " << sFileName << "\n";
		return false;
	}
	return true;
}

FileManager::~FileManager() {
	if(!_qst) return;
	for (auto &Qst:*_qst) {
		delete Qst;
	}
}

void FileManager::operator+=(const string &filePath) {
	opened=readFile(filePath);
}





bool FileManager::WriteToFile(int Total_Score, int Possible_pts, const string &Outputfile) {
	int Counter = 1;
	std::ofstream outFile;
	outFile.open(Outputfile);
	if (outFile) {
		std::cout << "Successfully opened output file: " << Outputfile << "\n";
		outFile << "You got->>>" << Total_Score << "/" << Possible_pts << "\n";
		for (auto &QSTS:*_qst) {
			if (QSTS->Asked) {
				outFile << "Question " << Counter++ << ": ";
				outFile << *QSTS << "\n";
			}

		}


		outFile.close();
	} else {
		std::cout << "Failed to open output file: " << Outputfile << "\n";
		return false;
	}
	return true;
}
FileManager::FileManager(FileManager &&File) {
	opened=File.opened;
	_qst= File._qst;
	File._qst= nullptr;
}















