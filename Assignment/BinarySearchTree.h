/* 
 * File:   BinarySearchTree.h
 * Author: Jose Vives Iznardo
 *
 * Created on 21 November 2015, 18:39
 */

#ifndef BINARYSEARCHTREE_H
#define	BINARYSEARCHTREE_H

comp_node_ptr read_competitor_node(int id, FILE * competitor_filename);
void add_competitor(comp_node_ptr current, comp_node_ptr new);
double calculateTotalLength(comp_node_ptr node);
double convertToInches(int feets, double inches);

#endif	/* BINARYSEARCHTREE_H */

