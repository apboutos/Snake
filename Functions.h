#ifndef FUNCTIONS_H
#define FUNCTIONS_H


int mainmenu();
int fruitpos (char* fruit);
int menuscores();
bool lose();
bool init();
bool loadmedia();
void getplayername();
void constructor (char* fruit);
void director (SDL_Event keyboardpress);
void scoredisplay();
void close();
void apply_surface(int x,int y, SDL_Surface* source,SDL_Surface* destination);
void GameOver();
void reset();
void loadscores();
std::string scoreconvert(int score);
SDL_Surface* load_PNG(std::string filename);

#endif
