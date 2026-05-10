//
// Created by 26432 on 2026/5/9.
//

#include <stdio.h>
#include "typedef.h"
#include "bst.h"
#include "stdlib.h"

tree_node *tree_node_i32_create_node(i32 v) {
    tree_node *newNode = (tree_node *) malloc(sizeof(tree_node));
    newNode->v = v;
    newNode->size = 1;
    newNode->height = 2;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void tree_node_i32_add(tree_node *h, i32 v) {
    tree_node *newNode = tree_node_i32_create_node(v);
    tree_node_i32_add_method(h, newNode);
}

void tree_node_i32_add_method(tree_node *h, tree_node *new_node) {
    if (new_node->v < h->v) {
        if (h->left == NULL) {
            h->left = new_node;
            h->size++;
            return;
        }
        tree_node_i32_add_method(h->left, new_node);
    } else if (new_node->v > h->v) {
        if (h->right == NULL) {
            h->right = new_node;
            h->size++;
            return;
        }
        tree_node_i32_add_method(h->right, new_node);
    } else {
        return;
    }
}

//void tree_node_i32_print(tree_node *h) {
//    printf("[");
//    i32 index = 0;
//    i32 min = tree_node_i32_min(h);
//    tree_node_i32_print_method(h, index, min);
//    printf("]\n");
//}
//
///*h_v = 45 , up_v = 38 */
//void tree_node_i32_print_method(tree_node *h, i32 index, i32 min) {
//    if (h == NULL)return;
//    index++;
//    tree_node_i32_print_method(h->left, index, min);
//    if (h->v == min) {
////        printf("\n[]%d\n" , min);
//        printf("%d", h->v);
//        return;
//    }
//    printf(",%d", h->v);
//    tree_node_i32_print_method(h->right, index, min);
//    return;
//}


int first = 1;
// 中序遍历打印（稳定、不会漏、格式正确）
void tree_node_i32_print_method(tree_node *h) {
    if (h == NULL) return;
    tree_node_i32_print_method(h->left);
    // 自己

    if (first) {
        printf("%d", h->v);
        first = 0;
    } else {
        printf(",%d", h->v);
    }
    tree_node_i32_print_method(h->right);
}

void tree_node_i32_print(tree_node *h) {
    printf("[");
    tree_node_i32_print_method(h);
    printf("]\n");
}

i32 tree_node_i32_min(tree_node *h) {
    if (h->left == NULL)return h->v;
    return tree_node_i32_min(h->left);
}

i32 tree_node_i32_max(tree_node *h) {
    if (h->right == NULL)return h->v;
    return tree_node_i32_max(h->right);
}

tree_node *tree_node_i32_delete(tree_node *h, i32 t_v) {

    tree_node_i32_delete_method(h, t_v);
}

tree_node *tree_node_i32_delete_method(tree_node *h, i32 t_v) {
    if (h == NULL)return NULL;
    if (t_v < h->v) {
        h->left = tree_node_i32_delete_method(h->left, t_v);
    } else if (t_v > h->v) {
        h->right = tree_node_i32_delete_method(h->right, t_v);
    } else {
        if (h->right == NULL) {
            tree_node *t = h->left;
            free(h);
            return t;
        }
        if (h->left == NULL) {
            tree_node *t = h->right;
            free(h);
            return t;
        }
        // if have double branch
        i32 min = tree_node_i32_min(h->right);
        h->v = min;
        h->right = tree_node_i32_delete(h->right, min);
    }
    return h;
}

void tree_node_i32_free(tree_node *pTreeNode) {
    if (pTreeNode == NULL)return;
    tree_node_i32_free(pTreeNode->left);
    tree_node_i32_free(pTreeNode->right);
    free(pTreeNode);
}

//AVL
i32 get_height(tree_node *h) {
    if (h == NULL)return 0;
    return h->height;
}

i32 get_buf(tree_node *h) {
    if (h == NULL)return 0;
    return get_height(h->left)
           - get_height(h->right);
}

void update_height(tree_node *h) {
    h->height = get_height(h->left) > get_height(h->right) ?
           get_height(h->left) + 1 : get_height(h->right) + 1;
}

tree_node *right_rotate(tree_node *h) {
    tree_node *x = h->left;
    tree_node *z = x->right;
    x->right = h;
    h->left = z;
    update_height(h);
    update_height(x);
    return x;
}

tree_node *left_rotate(tree_node *h) {
    tree_node *x = h->right;
    tree_node *z = x->left;

    x->left = h;
    h->right = z;

    update_height(h);
    update_height(x);
    return x;
}

tree_node *tree_node_i32_add_avl(tree_node *h, i32 v) {
    h = tree_node_i32_add_avl_method(h, v);
    return h;
}

tree_node *tree_node_i32_add_avl_method(tree_node *h, i32 v) {
    if (h == NULL) {
        tree_node *newNode = tree_node_i32_create_node(v);
        return newNode;
    }
    if (v < h->v) {
        h->left = tree_node_i32_add_avl_method(h->left, v);
    } else if (v > h->v) {
        h->right = tree_node_i32_add_avl_method(h->right, v);
    } else {
        return h;
    }
    update_height(h);
    i32 buf = get_buf(h);
    if (buf > 1 && get_buf(h->left) >= 0) { // LL ： 新节点在子节点的左边，就是强左。可以直接右旋
        h = right_rotate(h);
    }
        /*
     * *
        h
       /
      A
       \
        B

    不判断在子节点的左边还是右边的话，直接旋就会变成：
         A
          \
           h
         /
       B

    这样，就没意义
         所以先让h的左节点A左旋一下
         h
       /
      A
     / \
    B   NULL

        h再右旋
         A
        / \
       B   h
     */
    else if (buf > 1 && get_buf(h->left) < 0) { // LR
        h->left = left_rotate(h->left);
        h = right_rotate(h);
    } else if (buf < -1 && get_buf(h->right) <= 0) { // RR
        h = left_rotate(h);
    } else if (buf < -1 && get_buf(h->right) > 0) { // RL
        h->right = right_rotate(h->right);
        h = left_rotate(h);
    }
    return h;
}
























