#include <SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *textures[2] = {0};

static SDL_Texture* LoadTexture(char *filename,SDL_Renderer *renderer,int text_num)
{
    SDL_Surface *temp_surface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,temp_surface);
    SDL_FreeSurface(temp_surface);
    textures[text_num] = texture;
    return texture;
}
