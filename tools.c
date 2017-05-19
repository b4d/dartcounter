#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * DEFINES
 */
#define RED "\033[22;31m"
#define YEL "\033[01;33m"
#define NOR "\033[01;37m"


/*
 * VARIABLES
 */
char version_nr[128]="Dartcounter version 0.01";
char * help_buffer;
void version();
void print_help();
void clear();
void fatal_error(const char * s);
int calc_score(int hit_score, int score);
int input();
void banner(char * number);
void zmaga(int pl);

/*
 * FUNCTION DEFINITIONS
 */
char * init_help();
void version();
void print_help();
void fatal_error(const char * s);
void clear();
int calc_score(int hit_score, int score);
int input();
void banner(char * number);
void zmaga(int pl);

/*
 * FUNCTIONS
 */

char * init_help()
{
  FILE * fp=fopen("help", "r");
  if(fp == NULL)
    fatal_error("Help file not found!!");
  long length=0;
  fseek(fp,0,SEEK_END);
  length=ftell(fp);
  help_buffer=malloc(length * sizeof(char));
  rewind(fp);
  int indexc=0;
  char ch;
  while((ch =(char)fgetc(fp))!=EOF)
  {
    help_buffer[indexc]=ch;
    indexc++;
  }
  fclose(fp);
  help_buffer[length]=0;
}

//funkcija za izpis verzije
void version()
{
  printf("%s\n",version_nr);
}

//funkcija za izpis pomoci
void print_help()
{
  clear();
  init_help();
  printf("%s",help_buffer);
  exit(1);
  free(help_buffer);
  exit(1);
}

//funkcija za javljanje napake
void fatal_error(const char * s)
{
  printf("ERROR: %s\n",s);
  exit(1);
}

//funkcija za clearscreen
void clear()
{
  if(system("clear")==-1)
    fatal_error("Ne morem izvrsiti ukaza clear");
}

//funkcija za odbijanje rezultata pri igrah 301 501 901
int calc_score(int hit_score, int score)
{
  if((score-hit_score)<0)
    return -1;
  else
    return score-hit_score;
}

//funkcija za vnos pri igrah 301, 501 in 901
int input()
{
  int return_shot=0;
  int times, hit;
  printf("\n\t\t    Input hit: times value\n\t\t\t\t   ");
  scanf("%d %d", &times, &hit);
  if (hit==25 && (times>=1 && times<=2))
    return_shot=times*hit;
  else if ((hit>=0 && hit<=20) && (times>=0 && times<=3))
    return_shot=times*hit;
  return return_shot;
}

//funkcija za risanje velikih stevilk
void banner(char * number)
{
  if(system(number)==-1)
    fatal_error("Baner required");
}

// funkcija zmaga
void zmaga(int pl)
{
  printf("\n\n%s\t\t\t WINNER IS PLAYER: %d%s\n", RED, pl+1, NOR);
  exit(1);
}

