/*Program dartcounter za stetje pikade
 * Avtor: Jernej Demojzes
 *        Deni Bacic
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "tools.h"
#include "cricket.h"
#include "three01.h"
#include "cricket21.h"
#include "cricketr.h"

/*
 * SPREMENLJIVKE
 */
int version_flag=0;
int help_flag=0;
int view_flag=0;
int rules_flag=0;
int cricket_flag=0;
int three01_flag=0;
int fife01_flag=0;
int nin01_flag=0;
int cricket21_flag=0;
int cricketr_flag=0;
char splayers[128]; 

/*
 * OBDELAVA ARGUMENTOV
 */

//Log options
static struct option long_options[] = {
  {"version",   0,  0,  0},
  {"help",  0,  0,  0},
  {"cricket",   1,  0,  0},
  {"301",   1,  0,  0},
  {"501",   1,  0,  0},
  {"901",   1,  0,  0},
  {"cricket21", 1,  0,  0},
  {"cricketr",  1,  0,  0},
  {0,             0,      0,      0}
};

//Procesiranje argumentov
void process_arguments(int argc, char ** argv) {
  int option_index = 0;
  int option = 0;
 
  int c;  
  while((c = getopt_long (argc, argv, "hv", long_options, &option_index))!=-1){
    switch (c){
      case 0:
        switch(option_index){
        case 0:
          version_flag=1;
          break;
        case 1:
          help_flag=1;
          break;
        case 2:
          cricket_flag=1;
          strcpy(splayers, optarg);
          break;  
        case 3:
          three01_flag=1;
          strcpy(splayers, optarg);
          break;
        case 4:
          fife01_flag=1;
          strcpy(splayers, optarg);
          break;
        case 5:
          nin01_flag=1;
          strcpy(splayers, optarg);
          break;
        case 6:
          cricket21_flag=1;
          strcpy(splayers, optarg);
          break;
        case 7:
          cricketr_flag=1;
          strcpy(splayers, optarg);
          break;
        }break;
        break;
      case 'h':
        help_flag=1;
        break;
      case 'v':
        version_flag=1;
        break;
      case '?':
        fatal_error("Neznan argument!");    
    }
  }
}

/*
 * MAIN FUNCTION
 */
int main(int argc, char ** argv) {
        // Obdelava argumentov
  if(argc!=1)
  process_arguments(argc, argv); 
      int pl=atoi(splayers); //konverta st igralcev v int
  // Akcija
    if (version_flag) 
      version();
    else if (help_flag) 
      print_help();
    else if (cricket_flag){
      clear();
      if((pl>=1)&&(pl<=4))
        cricket(pl);
      else
        fatal_error("Wrong player input");;
    }
    else if (three01_flag){
      clear(); 
      if((pl>=1)&&(pl<=4))
        dart_clasic(pl,301);
      else
        fatal_error("Wrong player input");;
      
    }
    else if (fife01_flag){
      clear(); 
      if((pl>=1)&&(pl<=4))
        dart_clasic(pl,501);
      else
        fatal_error("Wrong player input");;
    }  else if (cricket21_flag){
      clear(); 
      if((pl>=1)&&(pl<=4))
        cricket21(pl);
      else
        fatal_error("Wrong player input");
    } else if(cricketr_flag)
    {
      
      clear();
      if((pl>=1)&&(pl<=4))
      cricketr(pl);
    else
    fatal_error("Wrong player input");
    }

    else if (nin01_flag){
      clear();
      if((pl>=1)&&(pl<=4))
        dart_clasic(pl,901);
      else
        fatal_error("Wrong player input");;
    }
    else {
     clear();
     fatal_error("Napačen klic!\nUporabi darts -h za pomoč\n");
    }
}
