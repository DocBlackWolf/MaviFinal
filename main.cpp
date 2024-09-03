#include "libs.h"
#include "Game.h"



int main(int argc, _TCHAR* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Game game;
	game.Loop();
	return 0;

}