//
// Created by youssef albali on 13-Jun-21.
//

#include "Answer.h"


Answer::Answer(const std::string &ANSWER) {
	set(ANSWER);
}

void Answer::print() {
	std::cout << get() << "\n";
}

















/*
void Answer::validation(char &User_answer) {
	if(User_answer==Right_Answer){
		std::cout<<"Correct Answer, Congrats :))"<<"\n";
		Increment_score();

	}
	else
	{
		std::cout<<"Wrong Answer, Maybe next time......."<<"\n";
		std::cout<<score<<"\n";



	}
}
void Answer::Increment_score()
{
	score+=10;
	std::cout<<score<<"\n";
}
*/