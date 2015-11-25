#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"
#include "print.h"

/* 
 * This file have functions for print information about the tree
 * 
 * File:   print.c
 * Author: Jose Vives
 *
 * Created on 19 November 2015, 16:42
 */

/*
 * Print a all the table with the header table information
 * @param root
 *      the root node from we start to print all the information
 * @param competition_nodes
 *      The competition name for this competition
 * @param competition_date
 *      The competition date for this competition
 */
void print_competition_table(comp_node_ptr root, char * competition_name, char * competition_date){
    
    /* Check if we are passing a null pointer for check if we have a tree */
    if(root == NULL){
        printf("The tree has not been created. Can't print the tree.");
        return;
    }
    
    /* Print the table header */
    printf("Competition: %s    Date: %s \n", competition_name, competition_date);
    printf("%-10s %5s %16s %18s %18s %20s \n", "NAME", "Competitor number", "CUCUMBER", "CARROT", "BEAN", "TOTAL");
    printf("====================================================================================================================\n");
    
    /* Start to walk to the tree */
    print_competition_nodes(root);
    
}

/*
 * Print the information from a selected node
 * @param node
 *      The node we want print his information
 */
void printNode(comp_node_ptr node){
    
    /* Check if the node we want print his information is NULL */
    if(node == NULL){
        printf("Can't print information from one NULL node. \n");
        return;
    }
    
    /* Print his information */
    float total;
    total = totalLength(node);
    
    printf("%-20s %-5d %10dft  %5.2fin %10dft  %5.2fin %10dft  %5.2fin %10dft  %5.2fin\n",
            node -> name,
            node -> id,
            knowFeet(node -> cucumber), 
            knowInches(node -> cucumber),
            knowFeet(node -> carrot), 
            knowInches(node -> carrot),
            knowFeet(node -> bean), 
            knowInches(node -> bean),
            knowFeet(total), 
            knowInches(total)
            );
    
}

/*
 * Convert the total inches to feet
 * @param data
 *      The inches we want know the feet
 * @return int
 *      The int feet value from the data we passed
 */
int knowFeet(float data){
    
    int result;
    result = 0;
    
    result = data / 12;
    
    return result;
}

/*
 * Convert the total inches to inches subtracting the feet
 * @param data
 *      The total inches we want know the inches
 * @return float
 *      The float inches value from the data we passed
 */
float knowInches(float data){
    
    int feet;
    float result;
    
    feet = knowFeet(data);
    feet *= 12;
    
    result = 0;
    result = data - feet;
    
    return result;
    
}

/*
 * Call recursively this method for go throw all nodes in the tree, from
 * the node with less value (the last node in the left children from all nodes) to the node with the
 * greatest value (the last node in the right children from all nodes)
 */
void print_competition_nodes(comp_node_ptr node){
    
    /* Check if have a left node. If have go to that node */
    if(node -> left != NULL){
        print_competition_nodes(node -> left);
    }
    
    /* Print this node*/
    printNode(node);
    
    /* Check if have a right node. If have go to that node*/
    if(node -> right != NULL){
        print_competition_nodes(node -> right);
    }
}