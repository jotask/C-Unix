#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"

/* 
 * 
 * This file only have the main function, where all the program starts and end
 * 
 * File:   main.c
 * Author: Jose Vives
 *
 * Created on 19 November 2015, 16:42
 */

int main(int argc, char** argv) {
    
    /* A pointer to the memory where the root node lives */
    comp_node_ptr root;
    
    /* The competition name for a competion */
    char competition_name[MAX_TEXT_LENGTH];
    
    /* The competition date */
    char competition_date[MAX_TEXT_LENGTH];
    
    /* Declare a variable for store the the file we want to load */
    char * filename = FILE_NAME;
    
    /* ask the user for the file we want to load */
    /* scanf("%s", filename); */
    
    /* Create the Tree from the file we want and keep a pointer to the 
     * root node from the tree
     */
    root = addCompetitorTable(filename, competition_name, competition_date);
    
    /* Print the competitor table using our printing function */
    print_competition_table(root, competition_name, competition_date);
    
    /* Return 0 because all run without any problem */
    return (EXIT_SUCCESS);
    
}

