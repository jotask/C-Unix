/* 
 * File:   competitor.h
 * Author: Jota
 *
 * Created on 20 November 2015, 11:40
 */

#ifndef COMPETITOR_H
#define	COMPETITOR_H

#define NUM_TEAMS 17
#define MAX_NAME_LENGTH 24

typedef struct competitor_status {
    
    char name[MAX_NAME_LENGTH];
    char postal_addres[];
    int phone_number;
    int id;
    int cucumber;
    int carrot;
    int bean;

    struct competitor_status * left; /* links to teams with more or same points */
    struct competitor_status * right; /* links to teams with less points */
    
} competitor_node;

typedef competitor_node * comp_node_ptr;

#endif	/* COMPETITOR_H */

