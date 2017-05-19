#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

/*
 * DEFINES
 */
#define RED "\033[22;31m"
#define YEL "\033[01;33m"
#define NOR "\033[01;37m"

/*
 * FUNCTIONS DEFINITIONS
 */
void set_game(int pl, int game);
void draw_score(char *color, int score, int player);
void dart_clasic(int pl, int game);
void zmaga(int pl);

/*
 * VARIABLES
 */
int dart_score[4];
int players;

/*
 * FUNCTIONS
 */
void set_game(int pl,int game)
{
  int i;
  for(i=0;i<=pl;i++)
    dart_score[i]=game;
}

void draw_score(char *color, int score, int player)
{
  char buf[10];
  char niz[30]="banner \"   ";
  sprintf(buf, "%d", score); 
  strcat(buf,"\"");
  strcat(niz, buf);
  printf("\t\t  ...:::||| PLAYER NR. %d |||:::...",player+1);
  printf(color);
  printf("\n");
  banner(niz);
  printf(NOR);
}

void dart_clasic(int pl, int game)
{
  int rounds=20;
  int i,j,k,l,shot;
  set_game(pl, game);
  players=pl;
  if(game==301)
    rounds=10;
  for (i=1;i<=rounds;i++)
  {
    for(j=0;j<players;j++)
    {
      int curent_player=dart_score[j];
      for(k=1;k<=3;k++) //met puscice
      {
        clear();
        printf("\t\t      ..::||    %d    ||::..\n", game);
        printf("\t\t      ..::|| ROUND%4d ||::..\n",i);
        printf("\t\t      ..::|| PLAYER%3d ||::..\n",j+1);
        printf("\t\t      ..::|| THROW%4d ||::..\n\n",k);
        for(l=0;l<players;l++)
        {
          if(j==l)
            draw_score(RED,curent_player,l);
          else
            draw_score(NOR,dart_score[l],l);
        }
        shot=input();
        if((curent_player=calc_score(shot,curent_player))==-1)
          break;
        if (curent_player==0) 
        {
          zmaga(j);
          break;
        }

      }
      if(curent_player!=-1) dart_score[j]=curent_player;
    }
  }
  int min_vrednost=901;
  int winner=-1;
  for (i=0;i<pl;i++)
  {
    if (dart_score[i]<=min_vrednost)
    {
      min_vrednost = dart_score[i];
      winner = i;
    }
  }
  zmaga(winner);
}
