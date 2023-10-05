#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include <list>

class Game {
public:

    Game();
    ~Game();

    static SDL_Renderer *renderer;
    static SDL_Event event;

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    static void update();
    static void render();
    void clean();

    bool running() const { return isRunning; }


private:
    int counter{};
    bool isRunning{};

    SDL_Window *window{};

};

#endif /* Game_hpp */