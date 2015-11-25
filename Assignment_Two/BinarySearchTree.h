/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: Jose Vives
 *
 * Created on 24 November 2015, 22:50
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

comp_node_ptr read_competitor_node(int id, FILE * competitor_filename);

void add_competitor(comp_node_ptr current, comp_node_ptr new);

float converToInches(char * buffer);

#endif /* BINARYSEARCHTREE_H */

