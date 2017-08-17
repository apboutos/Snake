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

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

Snake::Snake()
{
    //Constructor
    //Initializes the position of all the body parts
    posX[0]=10;
    posY[0]=10;
    direction[0]='w';
    exist[0]=1;
    posX[1]=10;
    posY[1]=9;
    direction[1]='w';
    exist[1]=1;
    posX[2]=10;
    posY[2]=8;
    direction[2]='w';
    exist[2]=1;
    for (int i=3;i<=99;i++)
    {
        posX[i]=100;
        posY[i]=100;
        exist[i]=0;
        direction[i]='s';
    }
}

Snake::~Snake()
{
    //dtor
}
bool Snake::driver()
{
    for (int x=99;x>=1;x--) // This for inherits every tail piece with the position and direction
        {                   // of the previous tailpiece giving the illution of a moving tail
         posX[x]=posX[x-1];
         posY[x]=posY[x-1];
         direction[x]=direction[x-1];
        }
    static int counter=0;
    static int headdir=2;  //1=UP 2=DOWN 3=LEFT 4=RIGHT
    if (counter%5==0)
    {
        headdir = rand()%4 + 1;
    }
    counter++;
  if (headdir == UP  && direction[0] !='s')
  {
   direction[0]='w';
  }
  else if (headdir == DOWN && direction[0] !='w')
  {
   direction[0]='s';
  }
  else if (headdir == LEFT && direction[0] != 'd')
  {
   direction[0]='a';
  }
  else if (headdir == RIGHT && direction[0] !='a')
  {
   direction[0]='d';
  }

 if (direction[0] == 'a')
 {
  posX[0]--;
  if (posX[0]<0)
  {
   posX[0]=19;
  }
 }
 else if (direction[0] == 'd')
 {
  posX[0]++;
  if (posX[0]>19)
  {
   posX[0]=0;
  }
 }
  else if (direction[0] == 's')
  {
   posY[0]++;
   if (posY[0]>19)
   {
    posY[0]=0;
   }
  }
  else if (direction[0] == 'w')
  {
   posY[0]--;
   if (posY[0]<0)
   {
    posY[0]=19;
   }
  }

}



void Snake::reset()
{
    //Resets the position and existance of all the body parts
    posX[0]=10;
    posY[0]=10;
    direction[0]='w';
    exist[0]=1;
    posX[1]=10;
    posY[1]=9;
    direction[1]='w';
    exist[1]=1;
    posX[2]=10;
    posY[2]=8;
    direction[2]='w';
    exist[2]=1;
    for (int i=3;i<=99;i++)
    {
        posX[i]=100;
        posY[i]=100;
        exist[i]=0;
        direction[i]='s';
    }
}





void Snake::painter()
{
int x;


    //The following for{} paints the snake bodyparts if the exist bool is true
    for (x=1;x<=99;x++)
    {
     if (exist[x] == 1)//Paints the bodypiece only if it exists
     {
      if (exist[x+1] == 0)// If the next piece doesnt exist (this piece is a tail)
      {
       if (direction[x] == direction[x-1])// If the dir of the prev piece is the same as the dir of this piece then this piece is not a corner piece
       {
        switch (direction[x])
        {
         case 'd': apply_surface(posX[x]*24, posY[x]*24, snake_tail_left, screen );break;
         case 'a': apply_surface(posX[x]*24, posY[x]*24, snake_tail_right, screen );break;
         case 'w': apply_surface(posX[x]*24, posY[x]*24, snake_tail_down, screen );break;
         case 's': apply_surface(posX[x]*24, posY[x]*24, snake_tail_up, screen );break;
        }
       }
       else //If the dir of the prev piece is the not same as this piece's dir then this pice is a corner
       {
        switch (direction[x])
        {
         case 'w':if (direction[x-1] == 'd')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_left, screen );
                  }
                  if (direction[x-1] == 'a')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_right, screen );
                  }break;

         case 's':if (direction[x-1] == 'd')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_left, screen );
                  }
                  if (direction[x-1] == 'a')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_right, screen );
                  }break;

         case 'a':if (direction[x-1] == 'w')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_down, screen );
                  }
                  if (direction[x-1] == 's')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_up, screen );
                  }break;

         case 'd':if (direction[x-1] == 'w')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_down, screen );
                  }
                  if (direction[x-1] == 's')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snake_tail_up, screen );
                  }break;
        }
       }
      }
      else // It the next piece exists (this piece is not a tail)
      {
       if (direction[x] == direction[x-1])// If the dir of the prev piece is the same as the dir of this piece then this piece is not a corner piece
       {
        switch (direction[x])
        {
         case 'd': apply_surface(posX[x]*24, posY[x]*24, snakebody_horizontal, screen ); break;
         case 'a': apply_surface(posX[x]*24, posY[x]*24, snakebody_horizontal, screen ); break;
         case 'w': apply_surface(posX[x]*24, posY[x]*24, snakebody_vertical, screen ); break;
         case 's': apply_surface(posX[x]*24, posY[x]*24, snakebody_vertical, screen ); break;
        }
       }
       else //If the dir of the prev piece is the not same as this piece's dir then this pice is a corner
       {
        switch (direction[x])
        {
         case 'd':if (direction[x-1] == 'w')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_left_up, screen );
                  }
                  if (direction[x-1] == 's')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_left_down, screen );
                  }break;
         case 'a':if (direction[x-1] == 'w')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_right_up, screen );
                  }
                  if (direction[x-1] == 's')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_right_down, screen );
                  }break;
         case 'w':if (direction[x-1] == 'd')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_right_down, screen );
                  }
                  if (direction[x-1] == 'a')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_left_down, screen );
                  }break;
         case 's':if (direction[x-1] == 'd')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_right_up, screen );
                  }
                  if (direction[x-1] == 'a')
                  {
                   apply_surface(posX[x]*24, posY[x]*24, snakebody_turn_left_up, screen );
                  }break;
        }
       }
      }
     }
    }


    // Depending on the direction the snake moves the following switch() paints
    // the proper snakehead

    switch (direction[0])
    {
     case 'w': apply_surface(posX[0]*24, posY[0]*24, snakehead_up, screen );
               break;
     case 's': apply_surface(posX[0]*24, posY[0]*24, snakehead_down, screen );
               break;
     case 'a': apply_surface(posX[0]*24, posY[0]*24, snakehead_left, screen );
               break;
     case 'd': apply_surface(posX[0]*24, posY[0]*24, snakehead_right, screen );
               break;
    }
    SDL_UpdateWindowSurface( window );
}




