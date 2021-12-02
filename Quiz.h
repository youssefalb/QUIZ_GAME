//
// Created by youssef albali on 16-Jun-21.
//

#ifndef MAIN_CPP_QUIZ_H
#define MAIN_CPP_QUIZ_H
#include <iostream>

class Quiz {
	std::string content;

public:

	std::string get();
	void set(const std::string &_Content);
	virtual void print() = 0;
	virtual ~Quiz()=default;
};


#endif //MAIN_CPP_QUIZ_H