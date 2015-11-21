#include <stdio.h>
#include <stdlib.h>
#include "competitor.h"

int main(int argc, char** argv) {
    
    comp_node_ptr root;
    char competition_name[MAX_TEXT_LENGTH];
    char competition_date[MAX_TEXT_LENGTH];
    
    char * filename = FILE_NAME;
    
    //scanf("%s", filename);
    
    root = addCompetitorTable(filename, competition_name, competition_date);
    
    return (EXIT_SUCCESS);
}

