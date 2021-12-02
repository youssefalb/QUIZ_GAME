
#include<iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include"Question.h"
#include "FileManager.h"

int main() {
	std::vector<Question *> qst;
	FileManager quiz1("text.txt", &qst);
	while (!quiz1.opened) {
		std::string filePath;
		std::cout << "Please input the right file" << "\n";
		std::cin >> filePath;
		quiz1 += filePath;
	}
	FileManager _Movefile=std::move(quiz1);


	//_Movefile+="text1.txt";
	int NumOfQsts = 5;

	std::vector<int> Rand(qst.size());
	for (int i = 0; i < Rand.size(); i++) { Rand[i] = i; }
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(Rand.begin(), Rand.end(), std::default_random_engine(seed));
	std::cout << "\n\n\t\t\t\t\t\t\tWelcome to the QUIZ"
			  << "\n\n\n";
	std::cout << "The quiz will be in form of questions with Multiple_choice answers(a,b,c,d), "
				 "answer each question by choosing the right corresponding character" << "\n";
	std::cout << "Press Enter to start the quiz... " << "\n";
	std::cin.get();
	for (int i = 0; i < NumOfQsts; i++) {

		qst[Rand[i]]->ask_question();
		qst[Rand[i]]->Asked = true;
	}
	int TotalScore = 0;
	int Possible_pts = 0;
	for (auto &Qs: qst) {
		if (Qs->Asked) {
			Possible_pts += Qs->_Pts;
			if (Qs->Correct) {
				TotalScore += Qs->_Pts;
			}
		}
	}

	_Movefile.WriteToFile(TotalScore, Possible_pts);

}