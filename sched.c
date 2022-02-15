#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

int  computeSlotFromTime(int hrs, int mins, int *slot);
int  computeDaysFromDel(DeliveryDaysType dd, int *d1, int *d2);


int addToSchedule(ScheduleType *sched, CourseType *c){
    int firstDay;
    int secDay;
    int timeSlot;

    if (computeDaysFromDel(c->delDays, &firstDay, &secDay) == C_NOK){
        return C_NOK;
    }
    if (computeSlotFromTime(c->startTime.hour, c->startTime.mins, &timeSlot) == C_NOK){
        return C_NOK;
        
    }
    sched->courses[firstDay][timeSlot] = c;
    sched->courses[secDay][timeSlot] = c;
    return C_OK;

    /*else{
        return C_NOK;
    }*/
}


/*
    Function:   printSchedule
    Purpose:    print all the courses scheduled in the correct format
    in-out:     ScheduleType, char*(String)
    return:     nothing
*/
void printSchedule(ScheduleType *sched, char *term){
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("|                MON               TUE               WED                THU               FRI      |\n");
    printf("----------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < NUM_SLOTS; i++){
            char info[NUM_DAYS][20];
            char names[NUM_DAYS][20];
            char temp[10];
            char instruct[11];
            char goodName[11];
            char slots[6][10] = {"| 08:30 |", "| 10:00 |", "| 11:30 |", "| 13:00 |", "| 14:30 |", "| 16:00 |"};

            for (int k = 0; k < NUM_DAYS; k++ ){
                if (sched->courses[k][i] != NULL){
                    strcpy(instruct, sched->courses[k][i]->instructor);
                    formatName(instruct, goodName);
                    if (k == 0){
                        strcpy(info[k],"   " );
                        strcat(info[k], sched->courses[k][i]->code);
                        sprintf(temp, "%c", sched->courses[k][i]->section);
                        strcat(info[k], " ");
                        strcat(info[k], temp);
                        strcat(info[k], "    ");
                        strcpy(names[k],"   ");
                        strcat(names[k], goodName);
                        strcat(names[k], "    ");

                    }
                    else if (k == 1){
                        strcpy(info[k],"   " );
                        strcat(info[k], sched->courses[k][i]->code);
                        sprintf(temp, "%c", sched->courses[k][i]->section);
                        strcat(info[k], " ");
                        strcat(info[k], temp);
                        strcat(info[k], "    ");

                        strcpy(names[k],"   ");
                        strcat(names[k], goodName);
                        strcat(names[k], "    ");
                    }
                    else if (k == 2){
                        strcpy(info[k],"   " );
                        strcat(info[k], sched->courses[k][i]->code);
                        sprintf(temp, "%c", sched->courses[k][i]->section);
                        strcat(info[k], " ");
                        strcat(info[k], temp);
                        strcat(info[k], "    ");

                        strcpy(names[k],"   ");
                        strcat(names[k], goodName);
                        strcat(names[k], "    ");
                    }
                    else if (k == 3){
                        strcpy(info[k],"   " );
                        strcat(info[k], sched->courses[k][i]->code);
                        sprintf(temp, "%c", sched->courses[k][i]->section);
                        strcat(info[k], " ");
                        strcat(info[k], temp);
                        strcat(info[k], "    ");

                        strcpy(names[k],"   ");
                        strcat(names[k], goodName);
                        strcat(names[k], "    ");
                    }
                    else if (k == 4){
                        strcpy(info[k],"   " );
                        strcat(info[k], sched->courses[k][i]->code);
                        sprintf(temp, "%c", sched->courses[k][i]->section);
                        strcat(info[k], " ");
                        strcat(info[k], temp);
                        strcat(info[k], "    ");

                        strcpy(names[k],"   ");
                        strcat(names[k], goodName);
                        strcat(names[k], "    ");
                    }
                }
                else{
                    if (k == 0){
                        strcpy(info[k], "                  ");
                        strcpy(names[k], "                  ");
                    }
                    else if(k == 1){
                        strcpy(info[k], "                  ");
                        strcpy(names[k], "                  ");
                    }
                    else if(k == 2){
                        strcpy(info[k], "                  ");
                        strcpy(names[k], "                  ");
                    }
                    else if(k == 3){
                        strcpy(info[k], "                  ");
                        strcpy(names[k], "                  ");
                    }
                    else if(k == 4){
                        strcpy(info[k], "                  ");
                        strcpy(names[k], "                  ");
                    }
                }
            }
            printf("%s", slots[i]);
            for (int f = 0; f < NUM_DAYS; f++){
                    printf("%s", info[f]);     
                }
                printf("|");
                printf("\n");
                printf("|       |");
                for (int n = 0; n<NUM_DAYS; n++){
                    printf("%s", names[n]);
                }
                printf("|");
                printf("\n");
                printf("----------------------------------------------------------------------------------------------------\n");
        }
}
 

/*
    Function:  clearSchedule
    Purpose:   empties the schedule
    in-out:   ScheduleType
    return:   nothing
   */
void clearSchedule(ScheduleType *sched){
    for (int i = 0; i<NUM_DAYS; i++){
        for (int k = 0; k<NUM_SLOTS;k++){            
            sched->courses[i][k] = NULL;
        }
    }

}


/*
    Function:   computeDaysFromDel
    Purpose:    compute the specific class days
    in-out:     DelyveryDaysType, int, int
    return:     success or fail flag
*/
int  computeDaysFromDel(DeliveryDaysType dd, int *d1, int *d2){
    if (dd == C_MON_WED){
        *d1 = 0;
        *d2 = 2;
        return C_OK;
    }

    else if (dd == C_TUE_THU){
        *d1 = 1;
        *d2 = 3;
        return C_OK;
    }

    else if (dd == C_WED_FRI){
        *d1 = 2;
        *d2 = 4;
        return C_OK;
    }
    else{
        return C_NOK;
    }
    

}

int  computeTimeFromSlot(int slot, int *hrs, int *mins);

int  computeSlotFromTime(int hrs, int mins, int *slot){
    if (hrs == 8 && mins == 30){
        *slot = 0;
        return C_OK;
    }
    else if (hrs == 10 && mins == 0){
        *slot = 1;
        return C_OK;
    }
    else if (hrs == 11 && mins == 30){
        *slot = 2;
        return C_OK;
    }
    else if (hrs == 13 && mins == 0){
        *slot = 3;
        return C_OK;
    }
    else if (hrs == 14 && mins == 30)    {
        *slot = 4;
        return C_OK;
    }

    else if (hrs == 16 && mins == 0){
        *slot = 5;
        return C_OK;
    }
    else{
        return C_NOK;
    }   
}