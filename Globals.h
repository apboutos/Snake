#ifndef GLOBALS_H
#define GLOBALS_H

//--------------------- Global Variables -------------------------------------//

extern int fruitX, fruitY; // Fruit's cartesian position
extern int scorecount; // The scorekeeper
extern int bodypiececount; // Keeps track of the sanke's body pieces
extern int lives; // Player's lives
extern int kol;

//This struct contains information on the position of each tail piece
//if they exist and the current side they are facing.

extern struct tail
{
 int posX,posY;     // Cartesian coordinates of each body piece
 bool exist;  // Determines whether the body piece is paintable or not
 char direction; // Piece's moving direction
} piece[100];

//This struct keeps the hightscores and the players names they belong

extern struct highscore
{
 std::string playername;
 std::string stringscore; //Score in string format for painting
 int intscore; //Score in int format for comparisons
} score[5];

//SDL Surfaces

extern SDL_Window* window;

extern SDL_Surface *screen;
extern SDL_Surface *brick_wall;
extern SDL_Surface *snakehead_left;
extern SDL_Surface *snakehead_right;
extern SDL_Surface *snakehead_up;
extern SDL_Surface *snakehead_down;
extern SDL_Surface *background;
extern SDL_Surface *apple;
extern SDL_Surface *pear;
extern SDL_Surface *orange;
extern SDL_Surface *watermelon;
extern SDL_Surface *snakebody_vertical;
extern SDL_Surface *snakebody_horizontal;
extern SDL_Surface *scorelogo;
extern SDL_Surface *no0;
extern SDL_Surface *no1;
extern SDL_Surface *no2;
extern SDL_Surface *no3;
extern SDL_Surface *no4;
extern SDL_Surface *no5;
extern SDL_Surface *no6;
extern SDL_Surface *no7;
extern SDL_Surface *no8;
extern SDL_Surface *no9;
extern SDL_Surface *newgame;
extern SDL_Surface *menuquit;
extern SDL_Surface *newgamedark;
extern SDL_Surface *menuquitdark;
extern SDL_Surface *snakebody_turn_left_up;
extern SDL_Surface *snakebody_turn_left_down;
extern SDL_Surface *snakebody_turn_right_up;
extern SDL_Surface *snakebody_turn_right_down;
extern SDL_Surface *game_over;
extern SDL_Surface *snake_tail_up;
extern SDL_Surface *snake_tail_down;
extern SDL_Surface *snake_tail_left;
extern SDL_Surface *snake_tail_right;
extern SDL_Surface *message;
extern SDL_Surface *avatar;
extern SDL_Surface *title;
// TTF fonts
extern TTF_Font *menufont;
// SDL Color for fonts
extern SDL_Color menucolor;
extern SDL_Color menucolordark;
// SDL Music tracks
extern Mix_Music *musictrack[9];

extern Mix_Music *musicmenu;

// SDL Sounds
extern Mix_Chunk *apple_bite;
extern Mix_Chunk *orange_bite;
extern Mix_Chunk *pear_bite;
extern Mix_Chunk *gameover_sound;


#endif
