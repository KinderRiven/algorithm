#include <stdio.h>
#include <malloc.h>
#include "bplus_tree.h"

bplus_node_t *list_header(bplus_node_t *bplus_node){
    while(bplus_node -> prev != NULL)
        bplus_node = bplus_node -> prev;
    return bplus_node;
}

bplus_node_t *list_index(bplus_node_t *bplus_node, int index){
    int cnt = 0;
    while(cnt < index){
        bplus_node = bplus_node -> next;
        cnt++;
    }
    return bplus_node;
}


inline bplus_tree_t*
new_bplus_tree(int level){

    bplus_tree_t* bplus_tree = (bplus_tree_t *)malloc(sizeof(bplus_tree_t));
    bplus_tree -> root = NULL;
    bplus_tree -> level = level;
    return bplus_tree;

}

inline bplus_node_t*
new_bplus_node(int value, node_type_t type){

    bplus_node_t* bplus_node = (bplus_node_t *)malloc(sizeof(bplus_node_t));
    bplus_node -> value = value;
    bplus_node -> type = type;
    bplus_node -> count = 0;
    bplus_node -> prev =
    bplus_node -> next =
    bplus_node -> left_link =
    bplus_node -> right_link =
    bplus_node -> parent =
    bplus_node -> child = NULL;
    return bplus_node;

}

inline void
bplus_tree_init(bplus_tree_t *bplus_tree, int level){

    bplus_tree -> root = NULL;
    bplus_tree -> level = level;

}

inline bplus_node_t*
bplus_tree_search_leaf(bplus_node_t *current_node, int value){

    //node type is leaf
    if(current_node -> type == leaf){
        while(current_node -> next != NULL){
            if(current_node -> next -> value > value)
                return current_node;
            else
                current_node = current_node -> next;
        }
        return current_node;
    }
    //node type is node
    else{
        while(current_node -> next != NULL){
            if(current_node -> next -> value > value)
                return bplus_tree_search_leaf(current_node -> child, value);
            else
                current_node = current_node -> next;
        }
        //larger than all of the value
        return bplus_tree_search_leaf(current_node -> child, value);
    }
}

inline void
bplus_tree_adjust(bplus_tree_t *bplus_tree, bplus_node_t *current_node){

    //if need not to adjust
    if(current_node -> count <= bplus_tree -> level){
        return;
    }
    else{
        if(current_node -> parent == NULL){

            bplus_node_t *mid_node = list_index(current_node, current_node -> count / 2);
            bplus_node_t *parent1 = new_bplus_node(current_node -> value, node);
            bplus_node_t *parent2 = new_bplus_node(mid_node -> value, node);

            current_node -> parent = parent1;
            parent1 -> child = current_node;
            parent1 -> count = 2;

            mid_node -> parent = parent2;
            parent2 -> child = mid_node;
            parent2 -> count = 1;

            parent1 -> next = parent2;
            parent2 -> prev = parent1;

            //cut
            mid_node -> prev -> right_link = mid_node;
            mid_node -> left_link = mid_node -> prev;
            mid_node -> prev -> next = NULL;
            mid_node -> prev = NULL;

            //count
            while(current_node != NULL){
                current_node -> count -= mid_node -> count;
                current_node = current_node -> next;
            }
            bplus_tree -> root = parent1;
        }
        else{

            bplus_node_t *mid_node = list_index(current_node, current_node -> count / 2);
            bplus_node_t *parent = current_node -> parent;

            bplus_node_t *new_node = new_bplus_node(mid_node -> value, node);
            new_node -> value = mid_node -> value;
            new_node -> prev = parent;
            new_node -> next = parent -> next;

            if(parent -> next != NULL)
                parent -> next -> prev = new_node;  //error
            parent -> next = new_node;
            //cut
            mid_node -> prev -> right_link = mid_node;
            mid_node -> left_link = mid_node -> prev;
            mid_node -> prev -> next = NULL;
            mid_node -> prev = NULL;

            //count
            new_node -> count = parent -> count;
            bplus_node_t *temp_node = parent;
            while(temp_node != NULL){
                temp_node -> count ++;
                parent = temp_node;
                temp_node = temp_node -> prev;
            }

            while(current_node != NULL){
                current_node -> count -= mid_node -> count;
                current_node = current_node -> next;
            }
            //link
            new_node -> child = mid_node;
            mid_node -> parent = new_node;

            //continue to adjust
            bplus_tree_adjust(bplus_tree, parent);
        }
    }
}

inline void
bplus_tree_update_min(bplus_tree_t *bplus_tree, bplus_node_t *bplus_node, int value){
    while(bplus_node -> parent != NULL){
        bplus_node -> value = value;
        bplus_node = bplus_node -> parent;
    }
    bplus_tree -> root = bplus_node;
}

inline void
bplus_tree_insert(bplus_tree_t *bplus_tree, int value){

    bplus_node_t *root = bplus_tree -> root;
    bplus_node_t *new_node = new_bplus_node(value, leaf);

    if(root == NULL){
        bplus_tree -> root = new_node;
    }
    else{
        bplus_node_t *location = bplus_tree_search_leaf(root, value);
        if(location -> value < value){
            new_node -> next = location -> next;
            new_node -> prev = location;
            if(location -> next != NULL){
                location -> next -> prev = new_node;
            }
            if(location -> right_link != NULL){
                new_node -> right_link = location -> right_link;
                location -> right_link -> left_link = new_node;
                location -> right_link = NULL;
            }
            location -> next = new_node;
        }
        else{
            new_node -> next = location;
            location -> prev = new_node;
            new_node -> parent = location -> parent;
            location -> parent = NULL;
            bplus_tree_update_min(bplus_tree, new_node, value);
        }
    }
    //adjust leaf floor
    bplus_node_t *header_node;
    while(new_node != NULL){
        new_node -> count = (new_node -> next == NULL) ? 1 : new_node -> next -> count + 1;
        header_node = new_node;
        new_node = new_node -> prev;
    }
    bplus_tree_adjust(bplus_tree, header_node);
}

inline void
bplus_tree_delete(){

}

inline void
bplus_tree_print(bplus_node_t *current_node){

    printf("[");
    while(current_node != NULL){
        printf("%d (%d) ", current_node -> value, current_node -> count);
        if(current_node -> child != NULL)
            bplus_tree_print(current_node -> child);
        current_node = current_node -> next;
    }
   printf("]");

}

inline void
bplus_tree_scan(bplus_tree_t *bplus_tree){

    bplus_node_t *temp_node = bplus_tree -> root;

    while(temp_node -> type == node){
        temp_node = temp_node -> child;
    }

    printf("\n[");
    while(temp_node != NULL){
        printf("%d ", temp_node -> value, temp_node -> type);
        if(temp_node -> right_link != NULL)
            temp_node = temp_node -> right_link;
        else
            temp_node = temp_node -> next;
    }
    printf("]\n");
}

inline void
list_print(bplus_node_t *header){
    while(header != NULL){
        printf("%d ", header -> value);
        header = header -> next;
    }
    puts("");
}

//10 50 30 20 40 100
//10 20 30 40 50 60
//10 20 30 5 21 22 100 40
//1 2 3 4 5 6 7 8 9 10 100 90 80 70 60 50 40 30 20 21 22 23 33 44
//1 2 3 4 5 6 7 8 9 10 100 90 80
