#ifndef __QUEUEPOINT_H_
#define __QUEUEPOINT_H_
//#include "gravitation.h"

/* Définition d'une File de point */
	typedef struct QueueElement
	{
		point value;
		struct QueueElement *next;
	}QueueElement, *Queue;

/*Définition d'un booléen*/
    typedef enum Bool{
        FALSE, TRUE
    }Bool;

    

/*------------------------------------------*/

	/* Prototypes des fonctions */
    Queue newQueue();
    Bool isEmptyQueue(Queue qu);

    Queue pushQueue(Queue qu, point value);
	void freeQueue(Queue qu);
	void printQueue(Queue qu);
	int queueLenght(Queue qu);
	Queue popQueue(Queue qu);

#endif
