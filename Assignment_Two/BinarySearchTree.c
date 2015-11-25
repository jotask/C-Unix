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
 * @param competitor_table_filename
 *      The filename from the file we want open
 * @param competition_name
 *      The char pointer to this value, for set up when we read the file
 * @param competition_date
 *      The char pointer to this value, for set up when we read the file
 * @return comp_node_ptr
 *      The root from the tree
 */
comp_node_ptr addCompetitorTable(char * competitor_table_filename, char * competition_name, char * competition_date){
    
    /* Initialise a id for each node on the tree */
    int id;
    id = 1;
    
    /* Create a few pointer variables */
    FILE * competitor_table_file;
    
    comp_node_ptr root;
    comp_node_ptr tmp_node;
    
    /* Open the file */
    competitor_table_file = fopen(competitor_table_filename, "r");
    
    /* Check if the file has been opened correctly. If not just return */
    if(competitor_table_file == NULL){
        printf("Can't open %s\n",competitor_table_filename);
        return NULL;
    }

    /* Read the first line and save his information */
    fscanf(competitor_table_file, "%[^\n]\n", competition_name);
    
    /* Read all the second line and save his information */
    fscanf(competitor_table_file, "%[^\n]\n", competition_date);

    /* Create the root node of the tree*/
    root = read_competitor_node(id, competitor_table_file);
    
    /* Start looping for create a new nodes until we get a NULL node, that
     means we ended the EOF from that file. We a node is created we add this
     node to the tree*/
    do{
        id++;
        tmp_node = read_competitor_node(id, competitor_table_file);
        add_competitor(root, tmp_node);
    }while(tmp_node != NULL);

    /* Close the file we open previously */
    fclose(competitor_table_file);
    
    /* Return the root we create */
    return root;
}

/*
 * Go line by line reading the information we have in the file for create
 * a new node for add this on the tree
 * @param id
 *      The id for this new node
 * @competitor_filename
 *      The pointer to the file opened
 * @return comp_node_ptr
 *      The pointer to the new node created
 */
comp_node_ptr read_competitor_node(int id, FILE * competitor_filename){
    
    /* Variable for know the status of the scan */
    int scan_status;
    
    /* Create a temp node */
    competitor_node * tmp_node;
    
    /* Allocate memory to this new node */
    tmp_node = calloc(1, sizeof(*tmp_node));
    
    /* Read the first line */
    scan_status = fscanf(competitor_filename, "%[^\n]\n", tmp_node -> name );
    
    /* Check if the first line was End Of Line. If is EOF liberate the memory
     * we previously allocate for this node and exit this function */
    if(scan_status == EOF){
        free(tmp_node);
        return NULL;
    }
    
    /* Create a buffer for read information and allocate enough memory*/
    char *buffer = malloc(sizeof(char)*(MAX_TEXT_LENGTH + 1));
    
    /* Set the id to the id we want */
    tmp_node -> id = id;
    
    /* Now just read line by line and set that line to one parameter
     * from the node we allocate before */
    
    fscanf(competitor_filename, "%[^\n]\n", tmp_node -> addres );
    
    fscanf(competitor_filename, "%[^\n]\n", tmp_node -> phone_number );
    
    fscanf(competitor_filename, "%[^\n]\n", buffer );
    tmp_node -> cucumber = converToInches(buffer);
    
    fscanf(competitor_filename, "%[^\n]\n", buffer );
    tmp_node -> carrot = converToInches(buffer);
    
    fscanf(competitor_filename, "%[^\n]\n", buffer );
    tmp_node -> bean = converToInches(buffer);
    
    /* Free the memory to the buffer */
    free(buffer);
    
    /* Return this node */
    return tmp_node;
    
}

/*
 *  Function for add a competitor previously created to the tree. This function
 * decide to which direction needs to be this new node on the tree, for placed
 * it to his correct place.
 * @param current
 *      The parent node
 * @param new
 *      The new node to add
 */
void add_competitor(comp_node_ptr current, comp_node_ptr new){
    
    /* Error check, if the the node we want add is null, we can add this to
     * the tree, so just skip return null */
    if(new == NULL){
        return;
    }
    
    /* Create local variables */
    float currentLength;
    float newLength;
    
    /* Calculate the length for the current node and for the new node
     for compare to each size from the tree we need to move*/
    currentLength = totalLength(current);
    newLength = totalLength(new);
    
    /* Check if the new node total length is greater or equal to the 
     * current node for decide which direction we need go deeper in the tree */
    if(currentLength <= newLength){
        /* we need to add new node on right subtree as
           it has less points than current node */
        if (current -> right == NULL) {
                /* right link currently null so add directly */
                current -> right = new;
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
        } else {
                /* must add further down subtree so recurse */
                add_competitor(current -> left, new);
        }
    }
    
}

/*
 * Convert a char array to a total inches
 * @param buffer
 *      The char array were we have the information
 * @return float
 *      The float value from the information we passed to this function
 */
float converToInches(char * buffer){
    
    /* Initialise some variables */
    int feet;
    float inches;
    float result;
    
    /* Look the char* for two values and set two each variables
     * previously defined */
    sscanf(buffer, "%d %f", &feet, &inches);
    
    /* Calculate the total inches from those values */
    result += (float)feet * 12;
    result += inches;
    
    /* Return the inches values */
    return result;
}

/* Calculate the total length of all fruits from a selected node
 * @param node
 *      The node we want calculate his total length from all his fruits
 *      or vegetables.
 * @return float
 *      The total length from all fruits and vegetable from the selected node
 */
float totalLength(comp_node_ptr node){
    
    float result;
    
    result = 0;
    result += node -> carrot;
    result += node -> bean;
    result += node -> cucumber;
    
    return result;
    
}