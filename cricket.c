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
void draw_cricket(int player, char* color);
void input_cricket(int times, int hit, int player);
int  preveri_zmago(int player);
int vnos();
void cricket(int pl);
void input_center(int times, int player);
/*
 * VARIABLES
 */
int cricket_table[4][7][3]; //players/fields/hits
int cricket_score[4];   //players
int players;
/*
 * FUNCTIONS
 */
//Draw cricket table
void draw_cricket(int player, char* color)
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
        if (j%2==0) 
	  printf(RED);
        else 
	  printf(YEL);
      if(cricket_table[player][j][k]==1)
        printf(" ● \t");
      else if(cricket_table[player][j][k]==0)
        printf(" ○ \t");
        }
    printf("%s\n", NOR);
  }
}
//input cricket score
void input_cricket(int times, int hit, int player)
{
  int add=0;
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
            add=1;
  }
  if(add==1)
    cricket_score[player]+=hit*(times-dodaj);
}


void input_center(int times, int player)
{
  int add=0;
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
            add=1;
  }
  if(add==1)
    cricket_score[player]+=25*(times-dodaj);
}


int preveri_zmago(int player)
{
    int i,j,k;
    for(j=0;j<7;j++)
      for(k=0;k<3;k++)
        if (cricket_table[player][j][k]==0) return 0;

    for(i=0;i<players;i++)
      if (i!=player)
        if (cricket_score[player] < cricket_score[i]) return 0;
    return 1;
}

int vnos(int player) 
{  
    char first_word[3];
    char second_word[3];
    int times=0;
    int hit=0;
    int error=0;
    printf("\n\n\n\t\t    Input hit: times value\n\t\t\t\t   ");
    if(scanf("%2s %2s", first_word, second_word) != 2)
        error = 1;
    if(getchar() != '\n' || error)
    {
        while(getchar() != '\n');
        return 0;
    }
    if(sscanf(first_word,"%d", &times) != 1)
        return 0;
    if(sscanf(second_word,"%d", &hit) != 1)
        return 0;
    if (hit==25 && (times>=1 && times<=2))
    {
      input_center(times, player);
        return 1;
    }
    if ((hit>=15 && hit<=20) && (times>=1 && times<=3))
    {
      input_cricket(times, hit, player);
        return 1;
    }
    if ((hit>=1 && hit<=14) && (times>=1 && times<=3))
        return 1;
    if (hit == 0 && times == 0)
        return 1;

    return 0;
}


void cricket(int pl)
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
                printf("\t\t    ..::||  CRICKET  ||::..\n");
                printf("\t\t    ..::|| ROUND%4d ||::..\n",round);
                printf("\t\t    ..::|| PLAYER%3d ||::..\n",i+1);
                printf("\t\t    ..::|| THROW%4d ||::..\n",k+1);
                for (j=0;j<players;j++)
                {
                  if (i==j) 
                    draw_cricket(j, RED);
                  else 
                    draw_cricket(j, NOR);
                }
                while(!vnos(i));
                if (preveri_zmago(i)==1) 
                {
                  clear();
                  draw_cricket(i, RED);
                  zmaga(i);
                  break;
                }
                clear();
              }
         }
     }
  }
    int z,winner;
    int value=0;
    for(z=0;z<players;z++)
    {
      if(cricket_score[z]>value)
      {
        value=cricket_score[z];
        winner=z;
      }
    }
    clear();
    draw_cricket(winner, RED);
    zmaga(winner);
}
