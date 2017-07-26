#ifndef BPLUS_TREE_H_INCLUDED
#define BPLUS_TREE_H_INCLUDED

#ifndef NULL
    #define NULL 0
#endif /// NULL

typedef enum{
    leaf = 0,
    node = 1
} node_type_t;

typedef struct bplus_node_t{

    struct bplus_node_t *parent;        //node's parent
    struct bplus_node_t *prev;          //node's left
    struct bplus_node_t *next;          //node's right
    struct bplus_node_t *child;         //node's child
    struct bplus_node_t *right_link;    //right  brother linker
    struct bplus_node_t *left_link;     //left   brother linker

    int value;                          //node's value
    int count;                          //node's count
    node_type_t type;                   //node's type

} bplus_node_t;

typedef struct bplus_tree_t{

    bplus_node_t *root;                 //b+tree's gen
    int level;                          //b+tree's level

} bplus_tree_t;

//list
bplus_node_t* list_header(bplus_node_t *bplus_node);
bplus_node_t* list_index(bplus_node_t *bplus_node, int index);

//new
inline bplus_tree_t* new_bplus_tree(int level);
inline bplus_node_t* new_bplus_node(int value, node_type_t type);

//option
inline void bplus_tree_init(bplus_tree_t *bplus_tree, int level);
inline void bplus_tree_adjust(bplus_tree_t *bplus_tree, bplus_node_t *current_node);
inline void bplus_tree_update_min(bplus_tree_t *bplus_tree, bplus_node_t *bplus_node, int value);
inline void bplus_tree_insert(bplus_tree_t *bplus_tree, int value);
inline void bplus_tree_delete();
inline bplus_node_t* bplus_tree_search_leaf(bplus_node_t *current_node, int value);

//print debug
inline void bplus_tree_print(bplus_node_t *current_node);
inline void bplus_tree_scan(bplus_tree_t *bplus_tree);
inline void list_print(bplus_node_t *header);

#endif // BPLUS_TREE_H_INCLUDED
