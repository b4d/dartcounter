#include <string.h>
#include <stdio.h>
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
void draw_cricket21(int player, char* color);
void input_cricket21(int times, int hit, int player);
int  preveri_zmago21(int player);
int vnos21();
void cricket21(int pl);
void input_center21(int times, int player);
/*
 * VARIABLES
 */
int cricket_table[4][7][3];   //players/fields/hits
int players;
/*
 * FUNCTIONS
 */
//Draw cricket table
void draw_cricket21(int player, char* color)
{
  int j,k;
    printf(color);
  printf("\n\n\n\t\t...:::||| PLAYER NR. %d |||:::...\n\n",player+1);
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
void input_cricket21(int times, int hit, int player)
{
  int k,i;
  for(i=0;i<times;i++)
    for(k=2;k>=0;k--) {
      if(cricket_table[player][20-hit][k]==0)
      {
        cricket_table[player][20-hit][k]=1;
        break;
      }
        }
}


void input_center21(int times, int player)
{
  int k,i;
  for(i=0;i<times;i++)
    for(k=2;k>=0;k--)
      if(cricket_table[player][6][k]==0)
      {
        cricket_table[player][6][k]=1;
        break;
      }
}


int preveri_zmago21(int player)
{
    int i,j,k;
    for(j=0;j<7;j++)
        for(k=0;k<3;k++)
            if (cricket_table[player][j][k]==0) return 0;
    return 1;
}


int vnos21(int player) 
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
      input_center21(times, player);
        return 1;
    }
    if ((hit>=15 && hit<=20) && (times>=1 && times<=3))
    {
      input_cricket21(times, hit, player);
        return 1;
    }
    if ((hit>=1 && hit<=14) && (times>=1 && times<=3))
        return 1;
    if (hit == 0 && times == 0)
        return 1;

    return 0;
}



void cricket21(int pl)
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
                                draw_cricket21(j, RED);
                            else 
                                draw_cricket21(j, NOR);
                        }
                        while(!vnos21(i));
                        if (preveri_zmago21(i)==1) 
                        {
                            clear();
                            draw_cricket21(i, RED);
                            zmaga(i);
                            break;
                        }
                        clear();
                    }
                }
            }
  }
    int filds_hit[]={0,0,0,0};
    for(i=0;i<players;i++)
      for(j=0;j<7;j++)
        for(k=0;k<3;k++)
          if(cricket_table[i][j][k]==1)
            filds_hit[i]++;
    int max=0;
    int winner;
    for(i=0;i<players;i++)
      if(filds_hit[i]>max)
      {
        max=filds_hit[i];
        winner=i;
      }
    clear();
    draw_cricket(winner, RED);
    zmaga(winner);
}
