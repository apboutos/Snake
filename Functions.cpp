#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

#include "Functions.h"
#include "Globals.h"
#include "Snake.h"

using namespace std;

//The attributes of the screen

const int SCREEN_WIDTH =480;
const int SCREEN_HEIGHT = 504;


//----------------------------- Functions ------------------------------------//
// Initializes SDL, Sets audio format and creates the main game window

bool init()
{
 SDL_Init( SDL_INIT_EVERYTHING );
 window = SDL_CreateWindow("Snake",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          SCREEN_WIDTH, SCREEN_HEIGHT,
                          SDL_WINDOW_SHOWN);

 screen = SDL_GetWindowSurface( window );
 Mix_OpenAudio( 23000, MIX_DEFAULT_FORMAT, 2, 2048 ); //44100
 TTF_Init();
 IMG_Init(IMG_INIT_PNG);
 return(1);
}


//----------------------------------------------------------------------------//
// Loads all media, including the graphics, the game sounds and music

bool loadmedia()
{
    background                = IMG_Load( "Images/Backrounds/Backround1.bmp" );
    apple                     = IMG_Load( "Images/Fruits/Apple.png" );
    pear                      = IMG_Load( "Images/Fruits/Pear.png" );
    orange                    = IMG_Load( "Images/Fruits/Orange.png" );
    watermelon                = IMG_Load( "Images/Fruits/Watermelon.png" );
    snakebody_vertical        = IMG_Load( "Images/Snake/Snakebody_vertical.png");
    snakebody_horizontal      = IMG_Load( "Images/Snake/Snakebody_horizontal.png");
    snakehead_left            = IMG_Load( "Images/Snake/Snakehead_left.png");
    snakehead_right           = IMG_Load( "Images/Snake/Snakehead_right.png");
    snakehead_up              = IMG_Load( "Images/Snake/Snakehead_up.png");
    snakehead_down            = IMG_Load( "Images/Snake/Snakehead_down.png");
    snake_tail_up             = IMG_Load( "Images/Snake/Snake_tail_up.png");
    snake_tail_down           = IMG_Load( "Images/Snake/Snake_tail_down.png");
    snake_tail_left           = IMG_Load( "Images/Snake/Snake_tail_left.png");
    snake_tail_right          = IMG_Load( "Images/Snake/Snake_tail_right.png");
    scorelogo                 = IMG_Load( "Images/Writing/Score.png");
    no0                       = IMG_Load( "Images/Writing/No0.png");
    no1                       = IMG_Load( "Images/Writing/No1.png");
    no2                       = IMG_Load( "Images/Writing/No2.png");
    no3                       = IMG_Load( "Images/Writing/No3.png");
    no4                       = IMG_Load( "Images/Writing/No4.png");
    no5                       = IMG_Load( "Images/Writing/No5.png");
    no6                       = IMG_Load( "Images/Writing/No6.png");
    no7                       = IMG_Load( "Images/Writing/No7.png");
    no8                       = IMG_Load( "Images/Writing/No8.png");
    no9                       = IMG_Load( "Images/Writing/No9.png");
    brick_wall                = IMG_Load( "Images/Backrounds/Brick_wall.bmp" );
    newgame                   = IMG_Load( "Images/Writing/New_game.png" );
    menuquit                  = IMG_Load( "Images/Writing/Menu_quit.png" );
    newgamedark               = IMG_Load( "Images/Writing/New_game_dark.png" );
    menuquitdark              = IMG_Load( "Images/Writing/Menu_quit_dark.png" );
    snakebody_turn_left_up    = IMG_Load( "Images/Snake/Snakebody_turn_left_up.png" );
    snakebody_turn_left_down  = IMG_Load( "Images/Snake/Snakebody_turn_left_down.png" );
    snakebody_turn_right_up   = IMG_Load( "Images/Snake/Snakebody_turn_right_up.png" );
    snakebody_turn_right_down = IMG_Load( "Images/Snake/Snakebody_turn_right_down.png" );
    avatar                    = IMG_Load( "Images/Snake/Avatar.png" );
    game_over                 = IMG_Load( "Images/Writing/Game_over.png" );
    title                     = IMG_Load ("Images/Backrounds/Title.bmp");
    apple_bite                = Mix_LoadWAV( "Sounds/Apple_bite.wav" );
    orange_bite               = Mix_LoadWAV( "Sounds/Orange_bite.wav" );
    pear_bite                 = Mix_LoadWAV( "Sounds/Pear_bite.wav" );
    gameover_sound            = Mix_LoadWAV( "Sounds/Gameover_sound.wav" );
    menufont                  = TTF_OpenFont ( "Images/Writing/CALJOETRIAL.ttf", 35 );
    musictrack[0]             = Mix_LoadMUS( "Music/Track1.mp3" );
    musictrack[1]             = Mix_LoadMUS( "Music/Track2.mp3" );
    musictrack[2]             = Mix_LoadMUS( "Music/Track3.mp3" );
    musictrack[3]             = Mix_LoadMUS( "Music/Track4.mp3" );
    musictrack[4]             = Mix_LoadMUS( "Music/Track5.mp3" );
    musictrack[5]             = Mix_LoadMUS( "Music/Track6.mp3" );
    musictrack[6]             = Mix_LoadMUS( "Music/Track7.mp3" );
    musictrack[7]             = Mix_LoadMUS( "Music/Track8.mp3" );
    musictrack[8]             = Mix_LoadMUS( "Music/Track9.mp3" );
    musicmenu                 = Mix_LoadMUS( "Music/menutrack.mp3");
    return(1);
}
//----------------------------------------------------------------------------//
// Unloads all graphics, sounds and music from memory and shuts down SDL subsystems

void close()
{
    //Unloads the images from memory and sets their pointers to NULL
    SDL_FreeSurface( title );
    title = NULL;

    SDL_FreeSurface( background );
    background = NULL;

    SDL_FreeSurface( snakehead_left );
    snakehead_left = NULL;

    SDL_FreeSurface( snakehead_right );
    snakehead_right = NULL;

    SDL_FreeSurface( snakehead_up );
    snakehead_up = NULL;

    SDL_FreeSurface( snakehead_down );
    snakehead_down = NULL;

    SDL_FreeSurface( apple );
    apple = NULL;

    SDL_FreeSurface( pear );
    pear = NULL;

    SDL_FreeSurface( orange );
    orange = NULL;

    SDL_FreeSurface( watermelon );
    watermelon = NULL;

    SDL_FreeSurface( snakebody_vertical );
    snakebody_vertical = NULL;

    SDL_FreeSurface( snakebody_horizontal );
    snakebody_horizontal = NULL;

    SDL_FreeSurface( scorelogo );
    scorelogo = NULL;

    SDL_FreeSurface( no0 );
    no0 = NULL;

    SDL_FreeSurface( no1 );
    no1 = NULL;

    SDL_FreeSurface( no2 );
    no2 = NULL;

    SDL_FreeSurface( no3 );
    no3 = NULL;

    SDL_FreeSurface( no4 );
    no4 = NULL;

    SDL_FreeSurface( no5 );
    no5 = NULL;

    SDL_FreeSurface( no6 );
    no6 = NULL;

    SDL_FreeSurface( no7 );
    no7 = NULL;

    SDL_FreeSurface( no8 );
    no8 = NULL;

    SDL_FreeSurface( no9 );
    no9 = NULL;

    SDL_FreeSurface( brick_wall );
    brick_wall = NULL;

    SDL_FreeSurface ( newgame );
    newgame = NULL;

    SDL_FreeSurface ( menuquit );
    menuquit = NULL;

    SDL_FreeSurface ( snakebody_turn_left_up );
    snakebody_turn_left_up = NULL;

    SDL_FreeSurface ( snakebody_turn_left_down );
    snakebody_turn_left_down = NULL;

    SDL_FreeSurface (snakebody_turn_right_up );
    snakebody_turn_right_up = NULL;

    SDL_FreeSurface (snakebody_turn_right_down );
    snakebody_turn_right_down = NULL;

    SDL_FreeSurface (game_over);
    game_over = NULL;

    SDL_FreeSurface (snake_tail_up );
    snake_tail_up = NULL;

    SDL_FreeSurface (snake_tail_down );
    snake_tail_down = NULL;

    SDL_FreeSurface (snake_tail_left );
    snake_tail_left = NULL;

    SDL_FreeSurface (snake_tail_right );
    snake_tail_right = NULL;

    SDL_FreeSurface (message);
    message = NULL;

    SDL_FreeSurface (avatar);
    avatar = NULL;
    //Unload Sounds and Music

    Mix_FreeChunk( apple_bite );
    apple_bite = NULL;

    Mix_FreeChunk( orange_bite );
    orange_bite = NULL;

    Mix_FreeChunk( pear_bite );
    pear_bite = NULL;

    Mix_FreeChunk( gameover_sound );
    gameover_sound = NULL;

    Mix_FreeMusic( musicmenu );
    musicmenu = NULL;

    for (int i=0;i<9;i++)
    {
        Mix_FreeMusic(musictrack[i]);
        musictrack[i] = NULL;
    }
    //Closes open fonts
    TTF_CloseFont (menufont);

    // Unloads the window and sets it's pointer to NULL
    SDL_DestroyWindow( window );
    window = NULL;
    Mix_Quit();
	IMG_Quit();
	TTF_Quit();
    // Closes SDL
    SDL_Quit();
}

//----------------------------------------------------------------------------//
// Applies loaded graphics on the screen

void apply_surface(int x,int y, SDL_Surface* source,SDL_Surface* destination)
{
 SDL_Rect coord;
 coord.x=x;
 coord.y=y;

 SDL_BlitSurface(source, NULL , destination, &coord);
}

//----------------------------------------------------------------------------//
// Paints the Mainmenu screen and manages player's input

int mainmenu()
{
 int x,y,i=0;
 int selection=1;
 bool flag=1;
 SDL_Event event;

 // Painting the  backround

 apply_surface(x*0,y*0,title,screen);

 //Painting player choices
 message = TTF_RenderText_Solid( menufont, "New Game",menucolordark);
 apply_surface (10*24,6*24, message , screen);
 message = TTF_RenderText_Solid( menufont, "Scores", menucolor);
 apply_surface (10*24,11*24, message , screen);
 message = TTF_RenderText_Solid( menufont, "Quit", menucolor);
 apply_surface (10*24,16*24, message , screen);
 SDL_UpdateWindowSurface( window );

 while (flag) //Mainmenu mainloop, player can make a selection here
 {
  SDL_PollEvent (&event);
  if( event.type == SDL_KEYDOWN ) //If a key was pressed
  {
   if (event.key.keysym.sym==SDLK_UP && (selection!=1))
   {
    selection-=1;
   }
   if (event.key.keysym.sym==SDLK_DOWN && (selection!=3))
   {
    selection+=1;
   }
   if (event.key.keysym.sym==SDLK_RETURN)
   {
    flag=0;
   }
  }
  else if( event.type == SDL_QUIT ) // Player Xed the window
  {
   return(3);
  }

  if (selection==1)
  {
   message = TTF_RenderText_Solid( menufont, "New Game",menucolordark);
   apply_surface (10*24,6*24, message , screen);
   message = TTF_RenderText_Solid( menufont, "Scores", menucolor);
   apply_surface (10*24,11*24, message , screen);
   message = TTF_RenderText_Solid( menufont, "Quit", menucolor);
   apply_surface (10*24,16*24, message , screen);
   SDL_UpdateWindowSurface( window );
  }
  if (selection==2)
  {
   message = TTF_RenderText_Solid( menufont, "New Game",menucolor);
   apply_surface (10*24,6*24, message , screen);
   message = TTF_RenderText_Solid( menufont, "Scores", menucolordark);
   apply_surface (10*24,11*24, message , screen);
   message = TTF_RenderText_Solid( menufont, "Quit", menucolor);
   apply_surface (10*24,16*24, message , screen);
   SDL_UpdateWindowSurface( window );
  }
  if (selection==3)
  {
   message = TTF_RenderText_Solid( menufont, "New Game",menucolor);
   apply_surface (10*24,6*24, message , screen);
   message = TTF_RenderText_Solid( menufont, "Scores", menucolor);
   apply_surface (10*24,11*24, message , screen);
   message = TTF_RenderText_Solid( menufont, "Quit", menucolordark);
   apply_surface (10*24,16*24, message , screen);
   SDL_UpdateWindowSurface( window );
  }
  SDL_Delay(100);
 }
 return (selection);
}

//----------------------------------------------------------------------------//
// This function is responsible for painting everything on the screen

void constructor (char* fruit)

{
    int x,y;
    //Apply the background to the screen
    apply_surface( 0, 0, background, screen );

    //Paints the fruit
    switch (*fruit)
    {
     case 'a': apply_surface( fruitX*24, fruitY*24, apple, screen ); break;
     case 'p': apply_surface( fruitX*24, fruitY*24, pear, screen ); break;
     case 'o': apply_surface( fruitX*24, fruitY*24, orange, screen ); break;
     case 'w': apply_surface( fruitX*24, fruitY*24, watermelon, screen ); break;
    }

    //The following for{} paints the snake bodyparts if the exist bool is true
    for (x=1;x<=99;x++)
    {
     if (piece[x].exist == 1)//Paints the bodypiece only if it exists
     {
      if (piece[x+1].exist == 0)// If the next piece doesnt exist (this piece is a tail)
      {
       if (piece[x].direction == piece[x-1].direction)// If the dir of the prev piece is the same as the dir of this piece then this piece is not a corner piece
       {
        switch (piece[x].direction)
        {
         case 'd': apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_left, screen );break;
         case 'a': apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_right, screen );break;
         case 'w': apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_down, screen );break;
         case 's': apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_up, screen );break;
        }
       }
       else //If the dir of the prev piece is the not same as this piece's dir then this pice is a corner
       {
        switch (piece[x].direction)
        {
         case 'w':if (piece[x-1].direction == 'd')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_left, screen );
                  }
                  if (piece[x-1].direction == 'a')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_right, screen );
                  }break;

         case 's':if (piece[x-1].direction == 'd')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_left, screen );
                  }
                  if (piece[x-1].direction == 'a')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_right, screen );
                  }break;

         case 'a':if (piece[x-1].direction == 'w')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_down, screen );
                  }
                  if (piece[x-1].direction == 's')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_up, screen );
                  }break;

         case 'd':if (piece[x-1].direction == 'w')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_down, screen );
                  }
                  if (piece[x-1].direction == 's')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snake_tail_up, screen );
                  }break;
        }
       }
      }
      else // It the next piece exists (this piece is not a tail)
      {
       if (piece[x].direction == piece[x-1].direction)// If the dir of the prev piece is the same as the dir of this piece then this piece is not a corner piece
       {
        switch (piece[x].direction)
        {
         case 'd': apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_horizontal, screen ); break;
         case 'a': apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_horizontal, screen ); break;
         case 'w': apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_vertical, screen ); break;
         case 's': apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_vertical, screen ); break;
        }
       }
       else //If the dir of the prev piece is the not same as this piece's dir then this pice is a corner
       {
        switch (piece[x].direction)
        {
         case 'd':if (piece[x-1].direction == 'w')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_left_up, screen );
                  }
                  if (piece[x-1].direction == 's')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_left_down, screen );
                  }break;
         case 'a':if (piece[x-1].direction == 'w')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_right_up, screen );
                  }
                  if (piece[x-1].direction == 's')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_right_down, screen );
                  }break;
         case 'w':if (piece[x-1].direction == 'd')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_right_down, screen );
                  }
                  if (piece[x-1].direction == 'a')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_left_down, screen );
                  }break;
         case 's':if (piece[x-1].direction == 'd')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_right_up, screen );
                  }
                  if (piece[x-1].direction == 'a')
                  {
                   apply_surface(piece[x].posX*24, piece[x].posY*24, snakebody_turn_left_up, screen );
                  }break;
        }
       }
      }
     }
    }


    // Depending on the direction the snake moves the following switch() paints
    // the proper snakehead

    switch (piece[0].direction)
    {
     case 'w': apply_surface(piece[0].posX*24, piece[0].posY*24, snakehead_up, screen );
               break;
     case 's': apply_surface(piece[0].posX*24, piece[0].posY*24, snakehead_down, screen );
               break;
     case 'a': apply_surface(piece[0].posX*24, piece[0].posY*24, snakehead_left, screen );
               break;
     case 'd': apply_surface(piece[0].posX*24, piece[0].posY*24, snakehead_right, screen );
               break;
    }
    SDL_UpdateWindowSurface( window );
}

//----------------------------------------------------------------------------//
// Handles the player's arrow input and gives directions for the head's movement

void director (SDL_Event keyboardkey)

{

  if ((GetAsyncKeyState(VK_UP))  && piece[0].direction !='s')
  {
   piece[0].direction='w';
  }
  else if (GetAsyncKeyState(VK_DOWN) && piece[0].direction !='w')
  {
   piece[0].direction='s';
  }
  else if (GetAsyncKeyState(VK_LEFT) && piece[0].direction != 'd')
  {
   piece[0].direction='a';
  }
  else if (GetAsyncKeyState(VK_RIGHT) && piece[0].direction !='a')
  {
   piece[0].direction='d';
  }

 if (piece[0].direction == 'a')
 {
  piece[0].posX--;
  if (piece[0].posX<0)
  {
   piece[0].posX=19;
  }
 }
 else if (piece[0].direction == 'd')
 {
  piece[0].posX++;
  if (piece[0].posX>19)
  {
   piece[0].posX=0;
  }
 }
  else if (piece[0].direction == 's')
  {
   piece[0].posY++;
   if (piece[0].posY>19)
   {
    piece[0].posY=0;
   }
  }
  else if (piece[0].direction == 'w')
  {
   piece[0].posY--;
   if (piece[0].posY<0)
   {
    piece[0].posY=19;
   }
  }

}

//----------------------------------------------------------------------------//
// Defines the conditions that end the main gameloop

bool lose()

{
 int x;
 for (x=2;x<=99;x++)
 {
  if (piece[0].posX==piece[x].posX && piece[0].posY==piece[x].posY && piece[x].exist==1)
  {
   return (0);
  }
 }
 return (1);
}

//----------------------------------------------------------------------------//
// Determines the random position where the fruit appears as well as what kind
// of fruit it is. Returns the snake's growth

int fruitpos(char *fruit)
{
 int x,temp;
 int snakegrowth=0; // How much the snake will grow depending on the fruit eaten
 bool flag=true;

 if ((piece[0].posX == fruitX) && (piece[0].posY == fruitY))
 {
  switch (*fruit)
  {
   case 'a': snakegrowth=1; scorecount +=5; Mix_PlayChannel( -1, apple_bite, 0 ); break;
   case 'p': snakegrowth=1; scorecount +=10; Mix_PlayChannel( -1, pear_bite, 0 ); break;
   case 'o': snakegrowth=2; scorecount +=20; Mix_PlayChannel( -1, orange_bite, 0 ); break;
   case 'w': snakegrowth=2; scorecount +=50; Mix_PlayChannel( -1, orange_bite, 0 ); break;
  }
  temp=rand()%10 +1;
  if (temp>=1 && temp <=4)
  {
   *fruit = 'a';
  }
  else if (temp>=5 && temp <=7)
  {
   *fruit = 'p';
  }
  else if (temp>=8 && temp <=9)
  {
   *fruit = 'o';
  }
  else
  {
   *fruit = 'w';
  }
  while(flag)
  {
   flag=false;
   fruitX=rand()%18 + 1;  // Randomly determines the spawn position of the next fruit
   fruitY=rand()%18 + 1;
   for (x=0;x<=99;x++)
   {
    if (fruitX==piece[x].posX && fruitY==piece[x].posY)
    {
     flag=true; //Prevents fruit from spawning under a body piece
    }
   }
   if ((fruitX<=12 && fruitX>=6) && (fruitY==6 || fruitY==12))
   {
    flag=true; // Prevents fruit from spawning under the borders
   }
  }
  return(snakegrowth);
 }
 else
 {
  return(snakegrowth); // No fruit was eaten this turn
 }
}
//----------------------------------------------------------------------------//
// Resets the position of the head, pieces, direction and resets score

void reset()

{
 int x;
 piece[0].posX=5;
 piece[0].posY=5;
 piece[0].exist=1;
 piece[1].posX=5;
 piece[1].posY=4;
 piece[1].exist=1;
 piece[2].posX=5;
 piece[2].posY=3;
 piece[2].exist=1;
 fruitX = 5;
 fruitY = 14;
 piece[0].direction='s';
 piece[1].direction='s';
 piece[2].direction='s';
 if (lives==-1)
 {
  scorecount=0;
 }
 bodypiececount=3;
 for (x=3;x<=99;x++) // Sets the default position existance and direction of the snake's body
     {
      piece[x].exist=0;
      piece[x].posX=0;
      piece[x].posY=0;
      piece[x].direction='s';
     }
}

//----------------------------------------------------------------------------//
// Handles the Game Over announcement

void GameOver()

{
  int y;
  Mix_PlayChannel( -1, gameover_sound, 0 );
  for (y=-480;y<=0;y++)
  {
   apply_surface( 0*24, y, game_over, screen );
   SDL_UpdateWindowSurface( window );
  }


}
//----------------------------------------------------------------------------//
// Loads the scores form data.txt

void loadscores()
{
 int i;
 std::ifstream scorefiler; // Declaring an stream item
 scorefiler.open("data"); //Opens the data.txt file
 for (i=0;i<=4;i++)
 {
  scorefiler >> score[i].playername
             >> score[i].stringscore
             >> score[i].intscore;
 }
 scorefiler.close();
}
//----------------------------------------------------------------------------//
//

void getplayername()
{
 int x,y;
 std::string playername="";
 std::string stringscore;
 SDL_Event event;
 bool quit = false;
 bool nameEntered = false;
 // Painting the brick backround
 for (x=0;x<=19;x++)
 {
  for (y=0;y<=20;y++)
  {
   apply_surface (x*24,y*24,brick_wall,screen);
  }
 }
 message = TTF_RenderText_Solid( menufont,"New Highscore", menucolor);
 apply_surface (4*24,3*24, message , screen);
 message = TTF_RenderText_Solid( menufont,"enter name", menucolor);
 apply_surface (4*24,6*24, message , screen);
 SDL_UpdateWindowSurface( window );

 while (nameEntered == false)//The main readingloop, stops when name
 {                                                      //surpasssed 8 leters or user pressed enter
  SDL_PollEvent(&event);
  if(( event.type == SDL_KEYDOWN ) && (playername.length() <=10)) //If a key is pressed
  {
   if((SDL_GetModState() & KMOD_CAPS) == KMOD_CAPS)// If caps lock is on
   {
        switch (event.key.keysym.sym) //Adds the letter or number pressed to the string
        {
            case SDLK_0: playername += '0'; break;
            case SDLK_1: playername += '1'; break;
            case SDLK_2: playername += '2'; break;
            case SDLK_3: playername += '3'; break;
            case SDLK_4: playername += '4'; break;
            case SDLK_5: playername += '5'; break;
            case SDLK_6: playername += '6'; break;
            case SDLK_7: playername += '7'; break;
            case SDLK_8: playername += '8'; break;
            case SDLK_9: playername += '9'; break;
            case SDLK_a: playername += 'A'; break;
            case SDLK_b: playername += 'B'; break;
            case SDLK_c: playername += 'C'; break;
            case SDLK_d: playername += 'D'; break;
            case SDLK_e: playername += 'E'; break;
            case SDLK_f: playername += 'F'; break;
            case SDLK_g: playername += 'G'; break;
            case SDLK_h: playername += 'H'; break;
            case SDLK_i: playername += 'I'; break;
            case SDLK_j: playername += 'J'; break;
            case SDLK_k: playername += 'K'; break;
            case SDLK_l: playername += 'L'; break;
            case SDLK_m: playername += 'M'; break;
            case SDLK_n: playername += 'N'; break;
            case SDLK_o: playername += 'O'; break;
            case SDLK_p: playername += 'P'; break;
            case SDLK_q: playername += 'Q'; break;
            case SDLK_r: playername += 'R'; break;
            case SDLK_s: playername += 'S'; break;
            case SDLK_t: playername += 'T'; break;
            case SDLK_u: playername += 'U'; break;
            case SDLK_v: playername += 'V'; break;
            case SDLK_w: playername += 'W'; break;
            case SDLK_x: playername += 'X'; break;
            case SDLK_y: playername += 'Y'; break;
            case SDLK_z: playername += 'Z'; break;

        }
   }
   else
   {
        switch (event.key.keysym.sym) //Adds the letter or number pressed to the string
        {
            case SDLK_0: playername += '0'; break;
            case SDLK_1: playername += '1'; break;
            case SDLK_2: playername += '2'; break;
            case SDLK_3: playername += '3'; break;
            case SDLK_4: playername += '4'; break;
            case SDLK_5: playername += '5'; break;
            case SDLK_6: playername += '6'; break;
            case SDLK_7: playername += '7'; break;
            case SDLK_8: playername += '8'; break;
            case SDLK_9: playername += '9'; break;
            case SDLK_a: playername += 'a'; break;
            case SDLK_b: playername += 'b'; break;
            case SDLK_c: playername += 'c'; break;
            case SDLK_d: playername += 'd'; break;
            case SDLK_e: playername += 'e'; break;
            case SDLK_f: playername += 'f'; break;
            case SDLK_g: playername += 'g'; break;
            case SDLK_h: playername += 'h'; break;
            case SDLK_i: playername += 'i'; break;
            case SDLK_j: playername += 'j'; break;
            case SDLK_k: playername += 'k'; break;
            case SDLK_l: playername += 'l'; break;
            case SDLK_m: playername += 'm'; break;
            case SDLK_n: playername += 'n'; break;
            case SDLK_o: playername += 'o'; break;
            case SDLK_p: playername += 'p'; break;
            case SDLK_q: playername += 'q'; break;
            case SDLK_r: playername += 'r'; break;
            case SDLK_s: playername += 's'; break;
            case SDLK_t: playername += 't'; break;
            case SDLK_u: playername += 'u'; break;
            case SDLK_v: playername += 'v'; break;
            case SDLK_w: playername += 'w'; break;
            case SDLK_x: playername += 'x'; break;
            case SDLK_y: playername += 'y'; break;
            case SDLK_z: playername += 'z'; break;

        }
   }

  }

   //If backspace was pressed and string isnt empty
   else if ( event.key.keysym.sym == SDLK_BACKSPACE)
   {
    playername = playername.substr(0,size_t(playername.size()-1) );//Remove a character from the end of the string

   }
   //If enter was pressed
   else if( event.key.keysym.sym == SDLK_RETURN)
   {
    nameEntered = true;//Break the loop
   }
   for (x=0;x<=19;x++)
   {
    for (y=0;y<=20;y++)
    {
     apply_surface (x*24,y*24,brick_wall,screen);
    }
   }
  message = TTF_RenderText_Solid( menufont,"New Highscore", menucolor);
  apply_surface (4*24,3*24, message , screen);
  message = TTF_RenderText_Solid( menufont,"enter name", menucolor);
  apply_surface (4*24,6*24, message , screen);
  message = TTF_RenderText_Solid( menufont,playername.c_str(), menucolor);
  apply_surface (4*24,8*24, message , screen);
  SDL_UpdateWindowSurface( window );
  }

 // Getting the string equivalent of the current score
 stringscore = scoreconvert(scorecount);
 //Updating the score array with the newest score
 int n=0;
 while(1)
 {
     if (scorecount > score[n].intscore)
     {
       break;
     }
     n++;
 }
 for (int i=4;i>n;i--)
 {
     score[i].playername = score[i-1].playername;
     score[i].stringscore = score[i-1].stringscore;
     score[i].intscore = score[i-1].intscore;
 }
 score[n].playername = playername;
 score[n].stringscore = stringscore;
 score[n].intscore = scorecount;



 //Updating the data.txt file
 std::ofstream scorewriter;
 scorewriter.open("data");
     for (int e=0;e<5;e++)
     {
         scorewriter << score[e].playername << endl
                     << score[e].stringscore << endl
                     << score[e].intscore << endl;
     }
  //scorewriter.close;
}




//----------------------------------------------------------------------------//
//Displays the highest five socre of the player after he makes thee score(2)
//choise in main menu

int menuscores()
{
 int x,y;
 SDL_Event event;
 // Painting the brick backround
 for (x=0;x<=19;x++)
 {
  for (y=0;y<=20;y++)
  {
   apply_surface (x*24,y*24,brick_wall,screen);
  }
 }
 //Paints the hig scores logo
 message = TTF_RenderText_Solid( menufont,"HIGH SCORES", menucolor);
 apply_surface (4*24,0*24, message , screen);
 //Paints the 5 stored scores
 for (y=0;y<=4;y++)
 {
  message = TTF_RenderText_Solid( menufont, score[y].playername.c_str(), menucolor);
  apply_surface (0*24,(y*2+4)*24, message , screen);
  message = TTF_RenderText_Solid( menufont, score[y].stringscore.c_str(), menucolor);
  apply_surface (15*24,(y*2+4)*24, message , screen);
 }
 //Paints the return instructions
 message = TTF_RenderText_Solid( menufont,"Press enter", menucolor);
 apply_surface (0*24,18*24, message , screen);
 SDL_UpdateWindowSurface( window );

 //Waits for enter to be pressed to return to main menu
 while (1)
 {
  SDL_PollEvent(&event); //If window is Xed return 0
  if (event.type==SDL_QUIT)
  {
   return(0);
  }
  if (event.type==SDL_KEYDOWN) //If enter is pressed return 1
  {
   if(event.key.keysym.sym==SDLK_RETURN)
   {
    return(1);
   }
  }
 }

}

//----------------------------------------------------------------------------//
//Converts an in score to a string score format

std::string scoreconvert(int score)
{
 char digit[5];
 digit[4]='\0';
 if (score>0 && score<10) //Eg 7 -> 0007
 {
  digit[0]='0';
  digit[1]='0';
  digit[2]='0';
  switch(score)
  {
   case 0: digit[3]='0';break;
   case 1: digit[3]='1';break;
   case 2: digit[3]='2';break;
   case 3: digit[3]='3';break;
   case 4: digit[3]='4';break;
   case 5: digit[3]='5';break;
   case 6: digit[3]='6';break;
   case 7: digit[3]='7';break;
   case 8: digit[3]='8';break;
   case 9: digit[3]='9';break;
  }
 }
 else if(score>=10 && score<100)//EG 37 -> 0037
 {
  digit[0]='0';
  digit[1]='0';
  switch(score/10)
  {
   case 0: digit[2]='0';break;
   case 1: digit[2]='1';break;
   case 2: digit[2]='2';break;
   case 3: digit[2]='3';break;
   case 4: digit[2]='4';break;
   case 5: digit[2]='5';break;
   case 6: digit[2]='6';break;
   case 7: digit[2]='7';break;
   case 8: digit[2]='8';break;
   case 9: digit[2]='9';break;
  }
  switch(score%10)
  {
   case 0: digit[3]='0';break;
   case 1: digit[3]='1';break;
   case 2: digit[3]='2';break;
   case 3: digit[3]='3';break;
   case 4: digit[3]='4';break;
   case 5: digit[3]='5';break;
   case 6: digit[3]='6';break;
   case 7: digit[3]='7';break;
   case 8: digit[3]='8';break;
   case 9: digit[3]='9';break;
  }
 }
 else if(score>=100 && score<1000)//Eg 457 -> 0457
 {
  digit[0]='0';
  switch(score/100)
  {
   case 0: digit[1]='0';break;
   case 1: digit[1]='1';break;
   case 2: digit[1]='2';break;
   case 3: digit[1]='3';break;
   case 4: digit[1]='4';break;
   case 5: digit[1]='5';break;
   case 6: digit[1]='6';break;
   case 7: digit[1]='7';break;
   case 8: digit[1]='8';break;
   case 9: digit[1]='9';break;
  }
  switch((score%100)/10)
  {
   case 0: digit[2]='0';break;
   case 1: digit[2]='1';break;
   case 2: digit[2]='2';break;
   case 3: digit[2]='3';break;
   case 4: digit[2]='4';break;
   case 5: digit[2]='5';break;
   case 6: digit[2]='6';break;
   case 7: digit[2]='7';break;
   case 8: digit[2]='8';break;
   case 9: digit[2]='9';break;
  }
  switch((score%100)%10)
  {
   case 0: digit[3]='0';break;
   case 1: digit[3]='1';break;
   case 2: digit[3]='2';break;
   case 3: digit[3]='3';break;
   case 4: digit[3]='4';break;
   case 5: digit[3]='5';break;
   case 6: digit[3]='6';break;
   case 7: digit[3]='7';break;
   case 8: digit[3]='8';break;
   case 9: digit[3]='9';break;
  }
 }
 else if (score>=1000 && score<=9999)
 {
  switch(score/1000)
  {
   case 0: digit[0]='0';break;
   case 1: digit[0]='1';break;
   case 2: digit[0]='2';break;
   case 3: digit[0]='3';break;
   case 4: digit[0]='4';break;
   case 5: digit[0]='5';break;
   case 6: digit[0]='6';break;
   case 7: digit[0]='7';break;
   case 8: digit[0]='8';break;
   case 9: digit[0]='9';break;
  }
  switch((score%1000)/100)
  {
   case 0: digit[1]='0';break;
   case 1: digit[1]='1';break;
   case 2: digit[1]='2';break;
   case 3: digit[1]='3';break;
   case 4: digit[1]='4';break;
   case 5: digit[1]='5';break;
   case 6: digit[1]='6';break;
   case 7: digit[1]='7';break;
   case 8: digit[1]='8';break;
   case 9: digit[1]='9';break;
  }
  switch(((score%1000)%100)/10)
  {
   case 0: digit[2]='0';break;
   case 1: digit[2]='1';break;
   case 2: digit[2]='2';break;
   case 3: digit[2]='3';break;
   case 4: digit[2]='4';break;
   case 5: digit[2]='5';break;
   case 6: digit[2]='6';break;
   case 7: digit[2]='7';break;
   case 8: digit[2]='8';break;
   case 9: digit[2]='9';break;
  }
  switch(((score%1000)%100)%10)
  {
   case 0: digit[3]='0';break;
   case 1: digit[3]='1';break;
   case 2: digit[3]='2';break;
   case 3: digit[3]='3';break;
   case 4: digit[3]='4';break;
   case 5: digit[3]='5';break;
   case 6: digit[3]='6';break;
   case 7: digit[3]='7';break;
   case 8: digit[3]='8';break;
   case 9: digit[3]='9';break;
  }
 }
 else
 {
  return("imba");
 }

 std::string stringscore(digit);
 return(stringscore);
}

//----------------------------------------------------------------------------//
// Displays the score at the bottom of the screen

void scoredisplay()
{
 int x,y;

 for (x=0;x<=19;x++)
    {
     for (y=20;y<=21;y++)
      {
        apply_surface( x*24, y*24, brick_wall, screen );
      }
    }
  apply_surface( 0*24, 20*24, avatar,screen ); //Displays snake avatar
  apply_surface( 4*24, 20*24, scorelogo, screen ); //Displays score logo

  switch (lives)  //Displays lives
  {
   case 0: apply_surface( 2*24, 20*24, no0,screen );break;
   case 1: apply_surface( 2*24, 20*24, no1,screen );break;
   case 2: apply_surface( 2*24, 20*24, no2,screen );break;
   case 3: apply_surface( 2*24, 20*24, no3,screen );break;
   case 4: apply_surface( 2*24, 20*24, no4,screen );break;
   case 5: apply_surface( 2*24, 20*24, no5,screen );break;
   case 6: apply_surface( 2*24, 20*24, no6,screen );break;
   case 7: apply_surface( 2*24, 20*24, no7,screen );break;
   case 8: apply_surface( 2*24, 20*24, no8,screen );break;
   case 9: apply_surface( 2*24, 20*24, no9,screen );break;
  }
  if (scorecount>=1000 && scorecount <=9999) //Discplays score counter
  {
   switch(scorecount/1000)
   {
    case 0: apply_surface( 12*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 12*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 12*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 12*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 12*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 12*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 12*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 12*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 12*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 12*24, 20*24, no9, screen ); break;
   }
   switch((scorecount%1000)/100)
   {
    case 0: apply_surface( 13*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 13*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 13*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 13*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 13*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 13*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 13*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 13*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 13*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 13*24, 20*24, no9, screen ); break;
   }
   switch(((scorecount%1000)%100)/10)
   {
    case 0: apply_surface( 14*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 14*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 14*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 14*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 14*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 14*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 14*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 14*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 14*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 14*24, 20*24, no9, screen ); break;
   }
   switch(((scorecount%1000)%100)%10)
   {
    case 0: apply_surface( 15*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 15*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 15*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 15*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 15*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 15*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 15*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 15*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 15*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 15*24, 20*24, no9, screen ); break;
   }
  }
  else if (scorecount>=100 && scorecount <=999)
  {
   apply_surface( 12*24, 20*24, no0, screen );
   switch (scorecount/100)
   {
    case 0: apply_surface( 13*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 13*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 13*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 13*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 13*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 13*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 13*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 13*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 13*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 13*24, 20*24, no9, screen ); break;
   }
   switch ((scorecount%100)/10)
   {
    case 0: apply_surface( 14*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 14*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 14*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 14*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 14*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 14*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 14*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 14*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 14*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 14*24, 20*24, no9, screen ); break;
   }
   switch ((scorecount%100)%10)
   {
    case 0: apply_surface( 15*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 15*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 15*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 15*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 15*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 15*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 15*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 15*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 15*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 15*24, 20*24, no9, screen ); break;
   }
  }
  else if (scorecount>=10 && scorecount <=99)
  {
   apply_surface( 12*24, 20*24, no0, screen );
   apply_surface( 13*24, 20*24, no0, screen );
   switch (scorecount/10)
   {
    case 0: apply_surface( 14*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 14*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 14*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 14*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 14*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 14*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 14*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 14*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 14*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 14*24, 20*24, no9, screen ); break;
   }
   switch (scorecount%10)
   {
    case 0: apply_surface( 15*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 15*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 15*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 15*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 15*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 15*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 15*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 15*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 15*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 15*24, 20*24, no9, screen ); break;
   }
  }
  else if (scorecount>=0 && scorecount <=9)
  {
   apply_surface( 12*24, 20*24, no0, screen );
   apply_surface( 13*24, 20*24, no0, screen );
   apply_surface( 14*24, 20*24, no0, screen );
   switch (scorecount)
   {
    case 0: apply_surface( 15*24, 20*24, no0, screen ); break;
    case 1: apply_surface( 15*24, 20*24, no1, screen ); break;
    case 2: apply_surface( 15*24, 20*24, no2, screen ); break;
    case 3: apply_surface( 15*24, 20*24, no3, screen ); break;
    case 4: apply_surface( 15*24, 20*24, no4, screen ); break;
    case 5: apply_surface( 15*24, 20*24, no5, screen ); break;
    case 6: apply_surface( 15*24, 20*24, no6, screen ); break;
    case 7: apply_surface( 15*24, 20*24, no7, screen ); break;
    case 8: apply_surface( 15*24, 20*24, no8, screen ); break;
    case 9: apply_surface( 15*24, 20*24, no9, screen ); break;
   }
  }
  else
  {
   apply_surface( 12*24, 20*24, no9, screen );
   apply_surface( 13*24, 20*24, no9, screen );
   apply_surface( 14*24, 20*24, no9, screen );
   apply_surface( 15*24, 20*24, no9, screen );
  }

  SDL_UpdateWindowSurface( window );
}

