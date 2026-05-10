//
// Created by 26432 on 2026/5/9.
//

#ifndef I32_BST_BST_H
#define I32_BST_BST_H

#include "typedef.h"

typedef enum{
    HOUSCEFAN
}had;
typedef struct tree_node{
    i32                     v;
    i32                     size;
    i32                     height;
    struct tree_node*       left;
    struct tree_node*       right;
}tree_node;

tree_node* tree_node_i32_create_node(i32 v);

void tree_node_i32_add(tree_node * h , i32 v);

void tree_node_i32_add_method(tree_node* h , tree_node* new_node);

//void tree_node_i32_print(tree_node* h);
//
//void tree_node_i32_print_method(tree_node *h , i32 index , i32 min);

i32 tree_node_i32_min(tree_node* h);

i32 tree_node_i32_max(tree_node* h);

tree_node *tree_node_i32_delete_method(tree_node *h, i32 t_v);

tree_node* tree_node_i32_delete(tree_node *h, i32 t_v);

void tree_node_i32_free(tree_node* pTreeNode);

//AVL

i32 get_height(tree_node* h);

i32 get_buf(tree_node* h);

void update_height(tree_node *h);

tree_node *tree_node_i32_add_avl(tree_node *h, i32 v);

tree_node *tree_node_i32_add_avl_method(tree_node *h, i32 v);

//print
// 中序遍历打印（稳定、不会漏、格式正确）
void tree_node_i32_print_method(tree_node *h);

void tree_node_i32_print(tree_node *h);
#endif //I32_BST_BST_H
