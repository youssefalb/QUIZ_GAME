//
// Created by youssef albali on 09-Jun-21.
//

#ifndef MAIN_CPP_QUESTION_H
#define MAIN_CPP_QUESTION_H

#include <iostream>
#include "Answer.h"
#include<vector>
#include"Quiz.h"



class Question : public Quiz {
	std::string User_Answer;
	char Right_Answer;
	std::vector<Quiz *> Ans;


public:
	int _Pts;
	bool Asked=false;
	bool Correct=false;

	Question(char &answer, std::string &questInfo, std::vector<std::string> &Answers,int pts);

	void ask_question();

	void validation();

	~Question() override;

	void print() override;
	friend std::ostream& operator<<(std::ostream& os,  Question& Q);
};


#endif //MAIN_CPP_QUESTION_H
