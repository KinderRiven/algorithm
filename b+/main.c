#include "src/bplus_tree.h"
#include <stdio.h>
#include <time.h>

static void
bplus_tree_insert_test(bplus_tree_t *bplus_tree, char *file){

    freopen(file, "r", stdin);
    int value;
    while(scanf("%d", &value) != EOF){
        bplus_tree_insert(bplus_tree, value);
    }
    fclose(stdin);
    freopen("CON", "r", stdin);
}

static void
bplus_tree_delete_test(bplus_tree_t *bplus_tree, char *file){
    freopen(file, "r", stdin);
    int value;
    while(scanf("%d", &value) != EOF){
        bplus_tree_delete(bplus_tree, value);
    }
    fclose(stdin);
    freopen("CON", "r", stdin);
}

static void
bplus_tree_search_test(bplus_tree_t *bplus_tree, char *file){
    freopen(file, "r", stdin);
    int value;
    while(scanf("%d", &value) != EOF){
        bplus_tree_search_equal_leaf(bplus_tree -> root, value);
    }
    fclose(stdin);
    freopen("CON", "r", stdin);
}

static double
calc_timer(clock_t start, clock_t end){
    return (double)(end - start) / CLK_TCK;
}

inline void
auto_test(){
    bplus_tree_t *bplus_tree = new_bplus_tree(5);
    clock_t start, end;
    int opt;
    char filename[128];
    while(scanf("%d", &opt) != EOF){
        //insert
        start = clock();
        if(opt == 1){
            printf("Input test filename : ");
            scanf("%s",filename);
            bplus_tree_insert_test(bplus_tree, filename);
        }
        //delete
        else if(opt == 2){
            printf("Input test filename : ");
            scanf("%s",filename);
            bplus_tree_delete_test(bplus_tree, filename);
        }
        //search
        else if(opt == 3){
            printf("Input test filename : ");
            scanf("%s",filename);
            bplus_tree_search_test(bplus_tree, filename);
        }
        //scan
        else if(opt == 4){
            printf("Input scan times : ");
            scanf("%d",&opt);
            int count;
            while(opt--){
                count = bplus_tree_scan(bplus_tree);
            }
            printf("Element Count : %d\n", count);
        }
        end = clock();
        printf("Cost %f seconds.\n", calc_timer(start, end));
    }
}

inline void
hand_test(){

    bplus_tree_t *bplus_tree = new_bplus_tree(3);
    int opt, value;

    while(scanf("%d", &value) != EOF){
        bplus_tree_insert(bplus_tree, value);
    }

    while(scanf("%d", &opt) != EOF){
        //print
        if(opt == 0){
            bplus_tree_print(bplus_tree -> root);
            puts("");
        }
        //insert
        else if(opt == 1){
            scanf("%d", &value);
            bplus_tree_insert(bplus_tree, value);
        }
        //delete
        else if(opt == 2){
            scanf("%d", &value);
            bplus_tree_delete(bplus_tree, value);
        }
        //search
        else if(opt == 3){
            scanf("%d", &value);
            bplus_node_t *bplus_node = bplus_tree_search_equal_leaf(bplus_tree -> root, value);
            if(bplus_node != NULL)
                printf("Found!\n");
            else
                printf("Null!\n");
        }
        //scan
        else if(opt == 4){
            int count = bplus_tree_scan(bplus_tree);
            printf("Count : %d\n", count);
        }
    }
}

int main(){
    //auto_test();
    hand_test();
    return 0;
}


// 10 50 30 20 40 100
// 10 20 30 40 50 60
// 10 20 30 5 21 22 100 40
// 1 2 3 4 5 6 7 8 9 10 100 90 80 70 60 50 40 30 20 21 22 23 33 44
// 1 2 3 4 5 6 7 8 9 10 100 90 80
// 10 9 8 7 6 5 4 3 2 1
// 9 8 7 6 5 4 1 2 3
// 10 20 30 40 9 8 7 1 2 5 4 3
// 10 20 30 40 35 45
// 2 30 2 40 2 10 2 35
// 10 20 30 40 50 60 70 80
