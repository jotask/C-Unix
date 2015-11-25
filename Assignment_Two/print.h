/* 
 * File:   print.h
 * Author: jota
 *
 * Created on 24 November 2015, 22:50
 */

#ifndef PRINT_H
#define PRINT_H

void printNode(comp_node_ptr node);

int knowFeet(float data);

float knowInches(float data);

void print_competition_nodes(comp_node_ptr node, void (*action)(comp_node_ptr));

void print_node_information(comp_node_ptr node);

#endif /* PRINT_H */

