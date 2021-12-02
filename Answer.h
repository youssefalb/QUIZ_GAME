//
// Created by youssef albali on 13-Jun-21.
//

#ifndef MAIN_CPP_ANSWER_H
#define MAIN_CPP_ANSWER_H

#include <iostream>
#include"Quiz.h"

class Answer : public Quiz {


public:
	explicit Answer(const std::string &ANSWER);//to avoid any implicit conversions
	void print() override;

};


#endif //MAIN_CPP_ANSWER_H
