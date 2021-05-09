#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gravitation.h"
#include "queuePoint.h"

/**
 * @brief Create a new queue
 * 
 * @return Queue 
 */
Queue newQueue(){
    return NULL;
}

/**
 * @brief Function return 1 if the queue is empty, 0 otherwise
 * 
 * @param qu 
 * @return Bool 
 */
Bool isEmptyQueue(Queue qu){
    if (qu == NULL)
        return TRUE;
    return FALSE;
}

/**
 * @brief 
 * 
 * @param qu 
 * @param value 
 * @return Queue 
 */
Queue pushQueue(Queue qu, point value){
    Queue new;
    Queue tmp = qu;

    new = malloc(sizeof(value));
    if (new == NULL){
        printf("Echec de l'allocation dynamique \n");
        exit(EXIT_FAILURE);
    }
    new->next = NULL;
    new->value = value;

    if (isEmptyQueue(qu)){
        qu = newQueue();
        qu = new;
        return qu;
    }
    
    while (!isEmptyQueue(tmp->next)){
        tmp = tmp->next;
    }

    tmp->next = new;
    return qu;
}

/**
 * @brief Procedure to display a queue
 * 
 * @param qu 
 */
void printQueue(Queue qu){

    while (!isEmptyQueue(qu)){
        printf("(%f, %f)\n", qu->value.x, qu->value.y);
        qu = qu->next;
    }
}

/**
 * @brief Procedure to free a queue
 * 
 * @param qu 
 */
void freeQueue(Queue qu){
    Queue tmp;
    int i = 0;

    while (!isEmptyQueue(qu)){
        i++;
        tmp = qu->next;
        free(qu);
        qu = tmp;
    }

    printf("\n%d element libere\n", i);
}

/**
 * @brief Function that return the lenght of a queue
 * 
 * @param qu 
 * @return int 
 */
int queueLenght(Queue qu){
    int i = 0;

    while (!isEmptyQueue(qu)){
        i++;
        qu = qu->next;
    }
    
    return i;
}

/**
 * @brief Function to remove the first element of a queue
 * 
 * @param qu 
 * @return Queue 
 */
Queue popQueue(Queue qu){
    Queue tmp;

    if (isEmptyQueue(qu))
    {
        printf("La queue est vide");
        return newQueue();
    }

    tmp = qu->next;
    free(qu);
    return tmp;
}