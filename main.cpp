#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <windows.h>
#include "Functions.h"
#include "Globals.h"
#include "Snake.h"

using namespace std;


int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{

    int x,selection;
    bool quit=false; // This flag handles the gameloop stop if game is Xed
    char fruit; // The kind of fruit currently on the screen [o=orange a=apple p=pear w=watermelon]
    SDL_Event X_event; //The X event handler
    SDL_Event keyboard_event; //The keyboard event handler

    //------------------------------------------------------------------------//

    init(); //Initializes SDL etc
    loadmedia();
    loadscores();
    Snake enemy; //Declares enemy snake item
    //getplayername();
    while (quit==false) // Checks if the player Xed the window
    {
     if( Mix_PlayingMusic() == 0 )//If there is no music playing
  	    {
          Mix_PlayMusic( musicmenu, 1 );
        }
     selection=mainmenu(); //Displays mainmenu and returns player's choice
     if (selection == 3) // If choice returned is 3(quit) then break loop and end game
     {
      quit=true;
     }
     else if(selection ==2)
     {
	  if (menuscores()==0) //If window Xed inside menuscores, end game
	  {
	   quit=true;
	  }
	 }
     else if(selection ==1) // If choise is 1(new game) start the game
     {
      Mix_HaltMusic();
      lives = 2;
      int currenttrack=-1;
      while(lives>=0 && quit==false)//Livesloop, keeps reseting the game when player dies
      {                             //until he runs out of lives or Xes the window
       reset(); // Resets the snake
       enemy.reset();
       fruit ='a'; //Makes the first fruit to appear an apple

       while (lose() && quit==false) //Main GameLoop, stops if player Xes the window or loses
       {
        if( Mix_PlayingMusic() == 0 )//If there is no music playing
  	    {
          currenttrack++;
          Mix_PlayMusic( musictrack[currenttrack],1 );
          if (currenttrack>8) currenttrack = 0;
        }
        while(SDL_PollEvent(&X_event)!=0)// This event handler handles the gameloop stop if the
        {                                // user presses X on the window
         if( X_event.type == SDL_QUIT )
         {
          quit=true;
         }
        }

        for (x=99;x>=1;x--) // This for inherits every tail piece with the position and direction
        {                   // of the previous tailpiece giving the illution of a moving tail
         piece[x].posX=piece[x-1].posX;
         piece[x].posY=piece[x-1].posY;
         piece[x].direction=piece[x-1].direction;
        }
        bodypiececount += fruitpos(&fruit); // Increases snake depending on the return value
        for(x=0;x<=99;x++)                  // of fruitpos
        {
         if (x<bodypiececount)
         {
          piece[x].exist=1;
         }
        }

        director(X_event);
        constructor(&fruit);  //Paints screen
        scoredisplay(); //Paints score screen
        //enemy.driver();
        //enemy.painter();
        SDL_Delay( 200 );
       }
       lives--;
       Mix_PlayChannel( -1, gameover_sound, 0 );
       if (lives==-1 && quit==false) // Display game over screen when player lost all lives
       {                             // and while he hasnt Xed the window
		Mix_HaltMusic();
	    GameOver();
	    if (scorecount > score[4].intscore)
        {
             getplayername();
        }

        SDL_Delay (500);
		reset(); //Resets snake and score
		enemy.reset();
	   }
      }
     }
    }
    close(); // Ends SDL etc
    return 0;
}




