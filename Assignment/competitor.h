/* 
 * File:   competitor.h
 * Author: Jota
 *
 * Created on 20 November 2015, 11:40
 */

#ifndef COMPETITOR_H
#define	COMPETITOR_H

#define FILE_NAME "hort_2013.txt";

#define MAX_TEXT_LENGTH 79

typedef struct competitor_status {
    
    int id;
    char name[MAX_TEXT_LENGTH];
    char addres[MAX_TEXT_LENGTH];
    char phone_number[MAX_TEXT_LENGTH];
    float cucumber;
    float carrot;
    float bean;

    struct competitor_status * left; /* links to teams with more or same points */
    struct competitor_status * right; /* links to teams with less points */
    
} competitor_node;

typedef competitor_node * comp_node_ptr;

comp_node_ptr addCompetitorTable(char * competitor_table_filename, char * competition_name, char * competition_date);
comp_node_ptr read_competitor_node(int id, FILE * competitor_filename);
void add_competitor(comp_node_ptr current, comp_node_ptr new);

double calculateTotalPoints(comp_node_ptr node);

void print_competition_nodes(comp_node_ptr node);
double knowInches(double inches);
int knowFeets(double inches);

#endif	/* COMPETITOR_H */