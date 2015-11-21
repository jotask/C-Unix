#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "competitor.h"

void print_competition_table(comp_node_ptr root, char * competition_name, char * competition_date){
    
    printf("Competition: %s. Date: %s", competition_name, competition_date);
    printf("NAME --- Competition Number --- Cucumber --- Carrot --- Runner Bean --- Total Length");
    printf("==========================================================================================");
    
    print_competition_nodes(root);
    
}

void print_competition_nodes(comp_node_ptr node){
    
    if(node -> left != NULL){
        print_competition_nodes(node -> left);
    }
    double total = calculateTotalPoints(node);
    int totalFeets = knowFeets(total);
    double totalInches =  knowInches(total);
    
    printf("%s --- %d --- %d ft %f in --- %d ft %f in --- %d ft %f in --- %d ft %f in",
            node -> name,
            node -> id,
            knowFeets(node -> cucumber),
            knowInches(node -> cucumber),
            knowFeets(node -> carrot),
            knowInches(node -> carrot),
            knowFeets(node -> bean),
            knowInches(node -> bean),
            totalFeets,
            totalInches
            );
    
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
    
    inches_result = inches;
    
    return inches_result;
}