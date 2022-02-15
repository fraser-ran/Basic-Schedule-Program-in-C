#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

/*
    Function:  initCourseArray
    Purpose:   initializes the course array
    in-out:   CourseArrayType 
    return:   nothing
*/
void initCourseArray( CourseArrayType *arr){
    arr->size = 0;
    
}
/*
Function:  addCourse
  Purpose:   adds the entered course to the enetered CourseArrayType
   in-out:   CourseArrayType and the CourseType
   return:   C_OK for success, C_NOK for failure
*/
int addCourse( CourseArrayType *arr, CourseType *c){
    if (arr-> size < MAX_ARR){
        arr->size++;
		arr-> elements[arr->size-1] = c;
		return C_OK;
	}
	else{
		return C_NOK;
	}
}


int findCourse(CourseArrayType *arr, int id, CourseType **c){
    for (int i = 0; i < arr->size; i++){
        if (arr->elements[i]->id == id){
            *c = arr->elements[i];
            return (C_OK);
        }
    }
    *c = NULL;
    return(C_NOK);
}