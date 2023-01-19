#include <iostream>
#include <vector>
#include <string>
using namespace std;
Game_Batievski::Game_Batievski() {   //пространство имен 

}

class Game_Batievski
{
	//св-ва 
private:
	enum Structure //список констант для построек 
	{

	};
	struct player //структура для игрока, прописываем все что будет у игрока 
	{
		string playername; //имя
		int kub1, kub2, kub3, kubdop, gold, stone, wood

	};
	struct building  //структура для построек 
	{

	};
	vector <building> bld;
	vector <player> play;

	unsigned int year; //беззнаковые числа 
	unsigned int phase;
	string playername; 


	resourses(int) {

	}
	vector <unsigned int> player;

	//конструктор 

public:
	Game_Batievski();
	void phase1();
	void phase2();
	void phase3();
	void phase4();
	void phase5();


}
//функция описания построек 
void building() {
	if () {

	}
}
//функции фаз 
void phase1() {
	if (int year == 1)
	{

	}
}

void phase2() {

}

void phase3() {

}

void phase4() {

}

void phase5() {

}
//
void Game_Batievski() {

}


int main()
{
	cout <<
}