#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"
#include "print.h"

int knowFeet(float data);
float knowInches(float data);

/* 
 * This file have functions for print information about the tree
 * 
 * File:   print.c
 * Author: Jose Vives
 *
 * Created on 19 November 2015, 16:42
 */

void print_competition_table(comp_node_ptr root, char * competition_name, char * competition_date){
    
    printf("Competition: %s    Date: %s \n", competition_name, competition_date);
    printf("%-10s %5s %16s %18s %18s %20s \n", "NAME", "Competitor number", "CUCUMBER", "CARROT", "BEAN", "TOTAL");
    printf("====================================================================================================================\n");
    
    print_competition_nodes(root);
    
}

void printNode(comp_node_ptr node){
    
    if(node == NULL){
        printf("Can't print information from one NULL node. \n");
        return;
    }
    
    float total;
    total = totalLength(node);
    
    printf("%-20s %-5d %10dft %-3.2fin %10dft %-3.2fin %10dft %-3.2fin %10dft %-5.2fin\n",
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

int knowFeet(float data){
    
    int result;
    result = 0;
    
    result = data / 12;
    
    return result;
}

float knowInches(float data){
    
    int feet;
    float result;
    
    feet = knowFeet(data);
    feet *= 12;
    
    result = 0;
    result = data - feet;
    
    return result;
    
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