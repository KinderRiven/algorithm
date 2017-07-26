#include "bplus_tree.h"
#include <stdio.h>

inline void
debug(){
    bplus_tree_t *bplus_tree = new_bplus_tree(3);
    int value;
    while(scanf("%d", &value) != EOF){
        bplus_tree_insert(bplus_tree, value);
    }
    bplus_tree_print(bplus_tree -> root);
    bplus_tree_scan(bplus_tree);
}

int main(){
    debug();
    return 0;
}
