#include <stdio.h>
#include "typedef.h"
#include "bst.h"

int main(){
    tree_node* tree = NULL;
    tree = tree_node_i32_add_avl(tree,5);
    tree = tree_node_i32_add_avl(tree,2);
    tree = tree_node_i32_add_avl(tree,3);
    tree = tree_node_i32_add_avl(tree,4);
    tree = tree_node_i32_add_avl(tree,1);
    tree = tree_node_i32_add_avl(tree,6);
    tree_node_i32_print(tree);
}

//int main() {
//    tree_node *tree = tree_node_i32_create_node(32);
//    tree_node_i32_add(tree , 12);
//    tree_node_i32_add(tree , 6);
//    tree_node_i32_add(tree , 34);
//    tree_node_i32_add(tree , 33);
//    tree_node_i32_add(tree , 5);
//    tree_node_i32_add(tree , 2);
//    tree_node_i32_add(tree , 7);
//    tree_node_i32_add(tree , 45);
//    tree_node_i32_add(tree , 9);
//    tree_node_i32_add(tree , 38);
//    tree_node_i32_add(tree , 9);
//    tree_node_i32_add(tree , 67);
//    tree_node_i32_add(tree , 48);
//    tree_node_i32_add(tree , 7);
//    tree_node_i32_add(tree , 457);
//    tree_node_i32_add(tree , 25);
//    tree_node_i32_add(tree , 14);
//
//    //@Test
//    i32 min = tree_node_i32_min(tree);
//    printf("[MIN VALUE] min is : %d\n" , min);
//    tree_node_i32_print(tree);
//    tree = tree_node_i32_delete(tree , 7);
//    tree_node_i32_print(tree);
//
//    i32  a = 10;
//}
