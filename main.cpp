#include "Game.h"




const int SCREEN_WIDTH	= 800;
const int SCREEN_HEIGHT = 640;

const int FPS			= 60;				// "we like 60 because its closest to the refresh rate on our monitors"
const int FRAME_DELAY	= 1000 / FPS;		// time inbetween frames?? or "how long a frame will take"




Game* game = nullptr;






int main(int argc, char* argv[]) {




	Uint32	frameStart;
	int		frameTime;




	game = new Game();

	game->init("Cool man!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, false);





	while (game->running()) {

		frameStart = SDL_GetTicks();				// get the running time at the top of the frame (ms)

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;	// gets How long it took to do ONE loop
		if (FRAME_DELAY > frameTime) {				// ensures that each frame takes the same amount of time
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	game->clean();

	return 0;
}