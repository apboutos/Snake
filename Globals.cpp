#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string.h>

#include "Globals.h"

//--------------------- Global Variables -------------------------------------//

struct tail piece[100];

struct highscore score[5];

int fruitX, fruitY;
int scorecount;
int bodypiececount=3;
int lives;
int kol;


SDL_Window* window = NULL;

SDL_Surface *screen = NULL;
SDL_Surface *brick_wall = NULL;
SDL_Surface *snakehead_left = NULL;
SDL_Surface *snakehead_right = NULL;
SDL_Surface *snakehead_up = NULL;
SDL_Surface *snakehead_down = NULL;
SDL_Surface *background = NULL;
SDL_Surface *apple = NULL;
SDL_Surface *pear = NULL;
SDL_Surface *orange = NULL;
SDL_Surface *watermelon = NULL;
SDL_Surface *snakebody_vertical = NULL;
SDL_Surface *snakebody_horizontal = NULL;
SDL_Surface *scorelogo = NULL;
SDL_Surface *no0 = NULL;
SDL_Surface *no1 = NULL;
SDL_Surface *no2 = NULL;
SDL_Surface *no3 = NULL;
SDL_Surface *no4 = NULL;
SDL_Surface *no5 = NULL;
SDL_Surface *no6 = NULL;
SDL_Surface *no7 = NULL;
SDL_Surface *no8 = NULL;
SDL_Surface *no9 = NULL;
SDL_Surface *newgame = NULL;
SDL_Surface *menuquit = NULL;
SDL_Surface *newgamedark = NULL;
SDL_Surface *menuquitdark = NULL;
SDL_Surface *snakebody_turn_left_up = NULL;
SDL_Surface *snakebody_turn_left_down = NULL;
SDL_Surface *snakebody_turn_right_up = NULL;
SDL_Surface *snakebody_turn_right_down = NULL;
SDL_Surface *game_over = NULL;
SDL_Surface *snake_tail_up = NULL;
SDL_Surface *snake_tail_down = NULL;
SDL_Surface *snake_tail_left = NULL;
SDL_Surface *snake_tail_right = NULL;
SDL_Surface *message = NULL;
SDL_Surface *avatar = NULL;
SDL_Surface *title = NULL;

TTF_Font *menufont = NULL;

SDL_Color menucolor = {0,220,0};
SDL_Color menucolordark = {0,150,0};

Mix_Music *musictrack[9];

Mix_Music *musicmenu = NULL;

Mix_Chunk *apple_bite = NULL;
Mix_Chunk *orange_bite = NULL;
Mix_Chunk *pear_bite = NULL;
Mix_Chunk *gameover_sound = NULL;
