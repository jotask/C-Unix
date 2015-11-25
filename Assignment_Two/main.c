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
    root = NULL;
    
    /* The competition name for a competition */
    char competition_name[MAX_TEXT_LENGTH];
    
    /* The competition date */
    char competition_date[MAX_TEXT_LENGTH];
    
    /* Declare a variable for store the the filename we want to load and
     * allocate memory for this variable for prevent segmentation fault */
    char * filename = (char*)malloc(FILENAME_LENGTH);
    
    /* ask the user for the file we want to load */
    printf("Please enter the name of the file you want load: ");
    scanf("%s", filename);
    
    /* Create the Tree from the file we want and keep a pointer to the 
     * root node from the tree
     */
    root = addCompetitorTable(filename, competition_name, competition_date);
    
    /* Start the traverse functions*/
    printf("================================================================== \n");
    printf("             Printing traversing tree functions \n");
    printf("================================================================== \n \n \n");
    
    /* Print the competition table. The function pointer is call inside this methods
     * I did in this way for print the header of this table
     */
    print_competition_table(root, competition_name, competition_date);
    
    printf("\n \n \n \n");
    
    /* Print the competitor table information. The function call is called inside
     * this method, i did in this way for print the header information */
    print_information_table(root, competition_name, competition_date);
    
    /* Return 0 because all run without any problem */
    return (EXIT_SUCCESS);
    
}