#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"
#include "BinarySearchTree.h"

/* 
 * 
 * Contains all the functions for build the tree for a competition
 * 
 * File:   BinarySearchTree.c
 * Author: Jose Vives
 *
 * Created on 19 November 2015, 16:42
 */

/*
 * Create tree reading the file, and creating his node from the information
 * provided by the file. Return the root node from the tree, for keep his
 * reference.
 */
comp_node_ptr addCompetitorTable(char * competitor_table_filename, char * competition_name, char * competition_date){
    
    int id;
    id = 1;
    
    FILE * competitor_table_file;
    
    comp_node_ptr root;
    comp_node_ptr tmp_node;
    
    competitor_table_file = fopen(competitor_table_filename, "r");
    
    if(competitor_table_file == NULL){
        
        printf("Can't open %s\n",competitor_table_filename);
        return NULL;
        
    }
        
    fscanf(competitor_table_file, "%[^\n]\n", competition_name);
    
    fscanf(competitor_table_file, "%[^\n]\n", competition_date);

    root = read_competitor_node(id, competitor_table_file);

    return root;
    
    do{
        id++;
        tmp_node = read_competitor_node(id, competitor_table_file);
        add_competitor(root, tmp_node);
    }while(tmp_node != NULL);
        
    fclose(competitor_table_file);
    return root;
}

comp_node_ptr read_competitor_node(int id, FILE * competitor_filename){
    
    int scan_status;
    
    competitor_node * tmp_node;
    
    tmp_node = calloc(1, sizeof(tmp_node));
    
    scan_status = fscanf(competitor_filename, "%s", tmp_node -> name );
    
    if(scan_status == EOF){
        printf("End Of File. \n");
        return NULL;
    } else {
        printf("Competitor entry for %s \n", tmp_node -> name);
    }
    
    fscanf(competitor_filename, "%s", tmp_node -> addres );
    fscanf(competitor_filename, "%s", tmp_node -> phone_number );
    int feet;
    double inches;
    fscanf(competitor_filename, "%d %lf", &feet, &inches );
    tmp_node -> carrot = convertToInches(feet, inches);
    
    fscanf(competitor_filename, "%d %lf", &feet, &inches );
    tmp_node ->cucumber = convertToInches(feet, inches);
    
    fscanf(competitor_filename, "%d %lf", &feet, &inches );
    tmp_node -> bean = convertToInches(feet, inches);
    
    return tmp_node;
    
}

/*
 *  Function for add a competitor previously created to the tree. This function
 * decide to which direction needs to be this new node on the tree, for placed
 * it to his correct place
 */
void add_competitor(comp_node_ptr current, comp_node_ptr new){
    
    /* Error check, if the the node we want add is null, we can add this to
     * the tree, so just skip return null */
    if(new == NULL){
        return;
    }
    /* Calculate the total length for the current node */
    double lengthCurrent = calculateTotalLength(current);
    
    /* Calculate the total length for the new node we want to add */
    double lengthNew = calculateTotalLength(new);
    
    /* Check if the new node total length is greater or equal to the 
     * current node for decide which direction we need go deeper in the tree */
    if(lengthCurrent <= lengthNew){
        /* we need to add new node on right subtree as
           it has less points than current node */
        if (current -> right == NULL) {
                /* right link currently null so add directly */
                current -> right = new;
                printf("Just added %s to right link of %s\n",
                        new -> name, current -> name );
        } else {
                /* must add further down subtree so recurse */
                add_competitor(current -> right, new);
        }
    }else{
        /* we need to add new node on left subtree as
           it has more or same points as current node */
        if (current -> left == NULL) {
                /* left link currently null so add directly */
                current -> left = new;
                printf("Just added %s to left link of %s\n",
                        new -> name, current -> name );
        } else {
                /* must add further down subtree so recurse */
                add_competitor(current -> left, new);
        }
    }
    
}

/*
 * Calculate the total length from one node summing all the length of
 * all the fruits his have
 */
double calculateTotalLength(comp_node_ptr node){
    
    double points;
    points = 0;
    
    points += node -> cucumber;
    points += node -> carrot;
    points += node -> bean;
    
    return points;
    
}

/*
 * Convert feet and inches, to the sum of those values in inches
 */
double convertToInches(int feets, double inches){
    
    double totalInches;
    totalInches = 0;
    
    totalInches += ( feets * 12 );
    totalInches += inches;
    
    return totalInches;
    
}