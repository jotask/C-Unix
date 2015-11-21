#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"
#include "BinarySearchTree.h"

comp_node_ptr addCompetitorTable(char * competitor_table_filename, char * competition_name, char * competition_date){
    
    int id;
    id = 1;
    
    FILE * competitor_table_file;
    
    comp_node_ptr root;
    comp_node_ptr tmp_node;
    
    competitor_table_file = fopen(competitor_table_filename, "r");
    
    if(root == NULL){
        
        printf("Can't open %s\n",competitor_table_filename);
        return NULL;
        
    } else {
        
        fscanf(competitor_table_file, "%s", competition_name);
        fscanf(competitor_table_file, "%s", competition_date);
        
        root = read_competitor_node(id, competitor_table_file);
        
        do{
            id++;
            tmp_node = read_competitor_node(id, competitor_table_file);
            add_competitor(root, tmp_node);
        }while(tmp_node != NULL);
        
    }
    fclose(competitor_table_file);
    return root;
}

comp_node_ptr read_competitor_node(int id, FILE * competitor_filename){
    
    int scan_status;
    
    competitor_node * tmp_node;
    
    tmp_node = calloc(1, sizeof(tmp_node));
    
    scan_status = fscanf(competitor_filename, "%s",
            tmp_node -> name
            );
    
    if(scan_status == EOF){
        printf("Problem reading file. \n");
        return NULL;
    } else {
        printf("Competitor entry for %s", tmp_node -> name);
    }
    
    fscanf(competitor_filename, "%s", tmp_node -> name );
    fscanf(competitor_filename, "%s", tmp_node -> addres );
    fscanf(competitor_filename, "%s", tmp_node -> phone_number );
    int feet;
    double inches;
    fscanf(competitor_filename, "%d %lf", &feet, &inches );
    fscanf(competitor_filename, "%d %lf", &feet, &inches );
    fscanf(competitor_filename, "%d %lf", &feet, &inches );
    
    return tmp_node;
    
}

void add_competitor(comp_node_ptr current, comp_node_ptr new){
    
    if(new == NULL){
        return;
    }
    
    double pointsCurrent = calculateTotalPoints(current);
    double pointsNew = calculateTotalPoints(new);
    
    if(pointsCurrent <= pointsNew){
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

double calculateTotalPoints(comp_node_ptr node){
    
    double points;
    points = 0;
    
    points += node -> cucumber;
    points += node -> carrot;
    points += node -> bean;
    
    return points;
    
}

double convertToInches(int feets, double inches){
    
    double totalInches;
    totalInches = 0;
    
    totalInches += ( feets * 12 );
    totalInches += inches;
    
    return totalInches;
    
}