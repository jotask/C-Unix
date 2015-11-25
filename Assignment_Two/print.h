/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   print.h
 * Author: jota
 *
 * Created on 24 November 2015, 22:50
 */

#ifndef PRINT_H
#define PRINT_H

void print_competition_table(comp_node_ptr root, char * competition_name, char * competition_date);

void printNode(comp_node_ptr node);

int knowFeet(float data);

float knowInches(float data);

void print_competition_nodes(comp_node_ptr node);


#endif /* PRINT_H */

