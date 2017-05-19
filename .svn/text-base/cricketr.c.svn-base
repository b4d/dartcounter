#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
void draw_cricketr(int player, char* color);
void input_cricketr(int times, int hit, int player);
int  preveri_zmagor(int player);
void vnosr();
void cricketr(int pl);
void input_centerr(int times, int player);
/*
 * VARIABLES
 */
int cricket_table[4][7][3]; //players/fields/hits
int cricket_score[4];       //players
int players;
/*
 * FUNCTIONS
 */
//Draw cricket table
void draw_cricketr(int player, char* color)
{
  int j,k;
  printf(color);
  printf("\n\n\n\t\t...:::||| PLAYER NR. %d |||:::...\n\n",player+1);
  printf("\t\t\t:: SCORE ::  %d\n\n",cricket_score[player]);
  printf(NOR);
  printf("\t20\t19\t18\t17\t16\t15\t ◎\n");
  for(k=0;k<3;k++){
    printf("\t");
    for(j=0;j<7;j++) 
    {
      if (j%2==0) printf(RED);
      else printf(YEL);
      if(cricket_table[player][j][k]==1)
        printf(" ● \t");
      else if(cricket_table[player][j][k]==0)
        printf(" ○ \t");
    }
    printf("%s\n", NOR);
  }
}
//input cricket score
void input_cricketr(int times, int hit, int player)
{
  int dodaj=0;
  int k,i;
  for(i=0;i<times;i++)
    for(k=2;k>=0;k--) {
      if(cricket_table[player][20-hit][k]==0)
      {
        cricket_table[player][20-hit][k]=1;
        dodaj++;
        break;
      }
    }
  if((times-dodaj)>0)
  {
    int x;
    for(x=0;x<players;x++)
      if(player != x)
        for(k=2;k>=0;k--)
          if(cricket_table[x][20-hit][k]==0)
          {
            cricket_score[x]+=hit*(times-dodaj);
            break;
          }
  }
}


void input_centerr(int times, int player)
{
  int dodaj=0;
  int k,i;
  for(i=0;i<times;i++)
    for(k=2;k>=0;k--)
      if(cricket_table[player][6][k]==0)
      {
        cricket_table[player][6][k]=1;
        dodaj++;
        break;
      }
  if((times-dodaj)>0)
  {
    int x;
    for(x=0;x<players;x++)
      if(player!=x)
        for(k=2;k>=0;k--)
          if(cricket_table[x][6][k]==0)
          {
            cricket_score[x]+=25*(times-dodaj);
            break;
          }
  }
}


int preveri_zmagor(int player)
{
  int i,j,k;
  for(j=0;j<7;j++)
    for(k=0;k<3;k++)
      if (cricket_table[player][j][k]==0) return 0;

  for(i=0;i<players;i++)
    if (i!=player)
      if (cricket_score[player] > cricket_score[i]) return 0;
  return 1;
}

void vnosr(int player) 
{  
  int times=0;
  int hit=0;
  printf("\n\n\n\t\t    Input hit: times value\n\t\t\t\t   ");
  scanf("%d %d", &times, &hit);
  if (hit==25 && (times>=1 && times<=2))
  {
    input_centerr(times, player);
  }
  if ((hit>=15 && hit<=20) && (times>=1 && times<=3))
  {
    input_cricketr(times, hit, player);
  }
}


void cricketr(int pl)
{
  players=pl;
  int i,j,k,round;
  for(round=1;round<=20;round++)
  {
    {
      for(i=0;i<players;i++)
      {
        for (k=0;k<3;k++)
        {
          printf("\t\t    ..::||  CRICKETR ||::..\n");
          printf("\t\t    ..::|| ROUND%4d ||::..\n",round);
          printf("\t\t    ..::|| PLAYER%3d ||::..\n",i+1);
          printf("\t\t    ..::|| THROW%4d ||::..\n",k+1);
          for (j=0;j<players;j++)
          {
            if (i==j) 
              draw_cricketr(j, RED);
            else 
              draw_cricketr(j, NOR);
          }
          vnosr(i);
          if (preveri_zmagor(i)==1) 
          {
            clear();
            draw_cricketr(i, RED);
            zmaga(i);
            break;
          }
          clear();
        }
      }
    }
  }
  int z,winner;
  int value=1000000;
  for(z=0;z<players;z++)
  {
    if(cricket_score[z]<value)
    {
      value=cricket_score[z];
      winner=z;
    }
  }
  clear();
  draw_cricketr(winner, RED);
  zmaga(winner);
}
