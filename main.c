#define SDL_main main
#include <SDL.h>
#include "game.c"

#define WIDTH 600
#define HEIGHT 400
#define TITLE "Breakout"

static SDL_Window *window;
static SDL_Renderer *renderer;

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(TITLE,
                                                      SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                                      WIDTH,HEIGHT,
                                                      0);
    renderer = SDL_CreateRenderer(window,
                                                         -1,
                                                          0);

    populate_board(WIDTH,HEIGHT);

    int close_requested = 0;
    SDL_Event event;
    int xpos = 300;
    int ypos = 300;
    int cx = 30;
    int cy = 40;
    int cvx = 10;
    int cvy = 10;
    int prev_x = 0;
    LoadTexture("C:\\Users\\Retard\\Desktop\\breakout\\assets\\piece.png",renderer,0);
    LoadTexture("C:\\Users\\Retard\\Desktop\\breakout\\assets\\circle.png",renderer,1);
    while(!close_requested)
    {
        SDL_Rect control_rect = draw_control(renderer,xpos,ypos,prev_x);
        close_requested = move_board(renderer,WIDTH,HEIGHT,control_rect);
           SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_d)
                {
                    if((xpos + 15) <  WIDTH )
                    {
                        prev_x = xpos;
                        xpos += 15;
                    }
                }
                if(event.key.keysym.sym == SDLK_a)
                {
                    if((xpos - 15) > -100)
                    {
                        prev_x = xpos;
                        xpos -= 15;
                    }
                }
                break;
            }
        }
    }
    SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_INFORMATION,
        "GAME OVER",
        "Game is over!",
        window
    );
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    return 0;
}