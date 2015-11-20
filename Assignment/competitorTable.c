#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"

comp_node_ptr read_competitor_node(FILE * competitor_table_file)
{
	int scan_status;

	competitor_node * temp_compt_node;

	/* Dynamically request memory for one node*/

	temp_compt_node = calloc(1, sizeof(competitor_node));


	scan_status = fscanf(competitor_table_file, "%s %s %d %d %d %d %d",
		temp_compt_node -> name,
		& temp_compt_node -> postal_addres,
		& temp_compt_node -> phone_number,
		& temp_compt_node -> id,
		& temp_compt_node -> cucumber,
		& temp_compt_node -> carrot,
		& temp_compt_node -> bean);
	if (scan_status == EOF) {
		printf("Problem reading competitor table entry\n");
		return NULL;
	} else {
		printf("Read competitor table entry for %s with %d id\n",
			temp_compt_node -> name,
			temp_compt_node -> id);
		return temp_compt_node;
	}
}


void add_compt_node(comp_node_ptr current, comp_node_ptr new)
{
	if (new -> id < current -> id) {
		/* we need to add new node on right subtree as
		   it has less id than current node */
		if (current -> right == NULL) {
			/* right link currently null so add directly */
			current -> right = new;
			printf("Just added %s to right link of %s\n",
				new -> name, current -> name );
		} else {
			/* must add further down subtree so recurse */
			add_compt_node(current -> right, new);
		}
	} else {
		/* we need to add new node on left subtree as
		   it has more or same points as current node */
		if (current -> left == NULL) {
			/* left link currently null so add directly */
			current -> left = new;
			printf("Just added %s to left link of %s\n",
				new -> name, current -> name );
		} else {
			/* must add further down subtree so recurse */
			add_compt_node(current -> left, new);
		}
	}

}


comp_node_ptr getCompetitorTable(char * competitor_table_filename, char * last_update)
{
    int comp;

    FILE * competitor_table_file;

    comp_node_ptr tree_top_ptr;
    comp_node_ptr temp_node_ptr;

    competitor_table_file = fopen(competitor_table_filename, "r");

    if (competitor_table_file != NULL) {

        fscanf(competitor_table_file, "%s", last_update);

	/* Get the first team status information
		from the file and put it at the top
		of the tree
	*/

	tree_top_ptr = read_competitor_node(competitor_table_file);

	/* for for the rest of the teams, get the data
		from the file and add them into the tree
	*/

        for (comp = 1 ; comp < NUM_TEAMS; comp++) {
		temp_node_ptr = read_competitor_node(competitor_table_file);

		/* and now add the new node into the tree */
		add_compt_node(tree_top_ptr, temp_node_ptr);
        }
    } else {
        printf("Failed to open competitor table file\n");
        return NULL;
    }
    fclose(competitor_table_file);
    return tree_top_ptr;
}