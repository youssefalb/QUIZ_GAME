//
// Created by youssef albali on 09-Jun-21.
//

#include "Question.h"


Question::Question(char &answer, std::string &questInfo, std::vector<std::string> &Answers, int pts) {
	set(questInfo);
	for (auto &an:Answers) {
		Ans.push_back(new Answer(an));
	}
	Right_Answer = answer;
	_Pts = pts;
}

void Question::ask_question() {
	print();
	while (true) {
		std::cout << "Please enter the right answer: " << "\n";
		std::cin >> User_Answer;
		try {
			if (User_Answer.size() > 1) {
				throw 1;
			}

		}
		catch (int &e) {
			std::cout << "Please Answer the question with the corresponding character (a,b,c,d)" << "\n";
			continue;
		}
		break;
	}
	std::cout << "\n";
	validation();
}


Question::~Question() {
	for (auto &an:Ans) {
		delete an;
	}

}

void Question::print() {
	std::cout << get() << std::endl;
	for (auto &an:Ans) {
		an->print();
	}
}

void Question::validation() {

	if (User_Answer[0] == Right_Answer) {
		Correct = true;
	}
}


std::ostream &operator<<(std::ostream &o, Question &Q) {
	o << Q.get() << std::endl;
	for (auto &an:Q.Ans) {
		o << an->get() << "\n";
	}
	if (Q.Correct == true) {
		o << "Your Answer is " << Q.User_Answer << " ---> Correct" << "\n";
	} else {
		o << "Your Answer is " << Q.User_Answer << " ---> Wrong!" << "\n"
		  << "The correct Answer is: " << Q.Right_Answer << "\n";
	}

	return o;
}








