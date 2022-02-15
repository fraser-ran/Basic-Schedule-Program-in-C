#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"


//void printMenu();

int main()
{
   char currTerm[MAX_STR];
  int choice = -1;
  int id = 0;

  CourseType *c = NULL;

  CourseArrayType courses;
  ScheduleType sched;

  initCourses(&courses);

  clearSchedule(&sched);

  strcpy (currTerm,"NONE SELECTED");


  while (choice != 0) {

    printMenu(currTerm, &choice);

    if (choice == 0) 
      break;
    
    switch(choice) {

      case 1:   // Reset current term

        strcpy (currTerm,"NONE SELECTED");

        clearSchedule(&sched);
        printf("\nPlease enter a new term: ");
        scanf("%s", currTerm);

        break;

      case 2:   // Print courses for current term

        printCourses(&courses, currTerm);

        break;

      case 3:   // Add course to schedule
        printf("\nPlease enter the course ID of a course in current term: ");
        scanf("%d", &id);
        if (findCourse(&courses, id, &c) == C_NOK){
          // is not ok
          printf(" \n bad id");
        }
        else if  (strcmp(currTerm, c->term)!=0){
          // course does not exist in term;
          printf(" \n bad term");
        }
        else{
            // is not in term
            if (addToSchedule(&sched, c) == C_OK){
              printf("\n Succesfully Added \n");
            }
            else{
              // not added success
              printf(" \n bad sched");
            }
        }
        
        break;

      case 4:   // Print schedule

        printf("\nCURRENT TERM: %s\n", currTerm);
        printSchedule(&sched, currTerm);
        

        break;

      case 5:   // Clear schedule
        clearSchedule(&sched);

        break;

      default:

        break;
    }
  }

  cleanCourses(&courses);


  return 0;
}

/*
  Function:  printMenu
  Purpose:   displays the menu, reads the user's selection, 
             and returns the selection
       in:   the current term
      out:   the user's selection from the menu
   return:   nothing
*/
void printMenu(char *term, int *choice)
{
  int c = -1;
  int numOptions = 5;
  char str[MAX_STR];

  printf("\nMAIN MENU -- CURRENT TERM: %s\n", term);
  printf("  (1) Reset current term\n");
  printf("  (2) Print courses\n");
  printf("  (3) Add to schedule\n");
  printf("  (4) Print schedule\n");
  printf("  (5) Clear schedule\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &c);
  }

  *choice = c;
}

