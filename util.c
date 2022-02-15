#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"


void convertDelDays(DeliveryDaysType dd, char *ddStr);
void formatName(char *instruct, char* name);


/*
    Function:  printCourses
    Purpose:   Prints the courses in the correct format
    in-out:   CourseArrayType and the term
    return:   nothing
*/
void printCourses(CourseArrayType *arr, char *term){
    char dayType[2];
    
    int temp;
    char nameForm[11];

    for(int i = 0; i<arr->size; i++){
        char time[6];
        char hourType[2];
        char minType[2];
        
        if (strcmp(term, arr->elements[i]->term)==0){
            if ( arr->elements[i]->startTime.hour < 10){
                temp = arr->elements[i]->startTime.hour;
                sprintf(hourType, "%d",temp );
                strcpy(time, "0");
                strcat(time, hourType);
                strcat(time,":");
            }
            else{
                temp = arr->elements[i]->startTime.hour;

                sprintf(hourType,"%d", temp);
                strcpy(time, hourType);
                strcat(time,":");
            }

            if (arr->elements[i]->startTime.mins<10){
                temp = arr->elements[i]->startTime.mins;
                sprintf(minType,"%d", temp);
                strcat(time, "0");
                strcat(time, minType);
                

            }
            else{
                temp = arr->elements[i]->startTime.mins;
                sprintf(minType, "%d", temp/10);
                strcat(time, minType);
                strcat(time, "0");
            }
            formatName(arr->elements[i]->instructor, nameForm );
            convertDelDays(arr->elements[i]->delDays, dayType);
            printf("%d %s %s %c %s %s %s %s",arr->elements[i]->id, arr->elements[i]->term, arr->elements[i]->code, arr->elements[i]->section, nameForm, dayType, time, "\n" );
        }
    
    }
}


void cleanCourses(CourseArrayType *arr){
    for (int i = 0; i< arr->size; i++){
        free(arr->elements[i]);
    }

}

void convertDelDays(DeliveryDaysType dd, char *ddStr){
    if (dd == 0){
        strcpy(ddStr, "MW");
    }
    else if (dd == 1 ){
        strcpy(ddStr, "TR");
    }

    else{
        strcpy(ddStr, "WF");
    }
}
/*
    Function:   formatName
    Purpose:    formats the name of the instructor to fit the sched
    in-out:     str of instructtors name, and a str of sizeof = 11
    return:     nothing
*/
void formatName(char *instruct, char* name){    
    int diff = 11 - strlen(instruct);
    strcpy(name, instruct);
    for (int i = 0; i < diff; i++){
        strcat(name," ");
    }
}
