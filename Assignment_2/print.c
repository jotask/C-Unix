#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"
#include "print.h"

void print_competition_table_function(comp_node_ptr root, char * competition_name, char * competition_date, void (* action)(comp_node_ptr, char*, char*)){
    action(root, competition_name, competition_date);
}

void print_competitors_information(comp_node_ptr root, char * competition_name, char * competition_date){
    
    printf("Competition: %s. Date: %s", competition_name, competition_date);
    printf("Competitor Contact Details");
    
    void (*action)(comp_node_ptr);
    
    print_competition_nodes(root, action);
    
}

void print_competition_table_(comp_node_ptr root, char * competition_name, char * competition_date){
    
    printf("Competition: %s. Date: %s", competition_name, competition_date);
    printf("NAME --- Competition Number --- Cucumber --- Carrot --- Runner Bean --- Total Length");
    printf("==========================================================================================");
    
    void(*action)(comp_node_ptr);
    
    print_competition_nodes(root, action);
    
}

void print_competition_nodes(comp_node_ptr node, void (* action)(comp_node_ptr)){
    
    if(node -> left != NULL){
        print_competition_nodes(node -> left, *action);
    }
    
    action(node);
    
    if(node -> right != NULL){
        print_competition_nodes(node -> right, *action);
    }
}

void print_node_result(comp_node_ptr node){
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
}

void print_node_information(comp_node_ptr node){
    
    printf("Competitor Name: ", node -> name);
    printf("Postal Address: ", node -> addres);
    printf("Telephone: ", node -> phone_number);
    printf("");
    
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