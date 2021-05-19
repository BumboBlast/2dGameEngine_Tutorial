#include "Game.h"


Game* game = nullptr;

const int SCREEN_WIDTH	= 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* argv[]) {

	game = new Game();

	game->init("Cool man!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running()) {



		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}