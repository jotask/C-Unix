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

void print_competition_table(comp_node_ptr root, char * competition_name, char * competition_date){
    
    printf("Competition: %s. Date: %s \n", competition_name, competition_date);
    printf("NAME --- Competition Number --- Cucumber --- Carrot --- Runner Bean --- Total Length \n");
    printf("==========================================================================================\n");
    
    print_competition_nodes(root);
    
}

void printNode(comp_node_ptr node){
    
    if(node == NULL){
        printf("Can't print information from one NULL node. \n");
        return;
    }
    
    printf("%s *** %d *** %s *** %.2f *** %.2f *** %.2f \n",
            node -> name,
            node -> id,
            node -> phone_number,
            node -> cucumber,
            node -> carrot,
            node -> bean
            );
    
}

void print_competition_nodes(comp_node_ptr node){
    
    if(node -> left != NULL){
        print_competition_nodes(node -> left);
    }
    
    printNode(node);
    
    if(node -> right != NULL){
        print_competition_nodes(node -> right);
    }
}

int knowFeets(double inches){
    
    int feets;
    
    feets = inches / 12;
    
    return feets;
}

double knowInches(double inches){
    
    double inches_result;
    
    int feet;
    feet = knowFeets(inches);
    
    inches_result = (feet * 12) - inches;
    
    return inches_result;
    
}