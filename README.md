# 🌳 i32-BST & AVL Tree
Handcrafted Binary Search Tree & AVL Self-Balancing Tree in pure C.



## ✨ Features
- Pure C implementation, no external dependencies
- Complete BST operations: insert, delete, min, max, in-order traversal
- AVL tree automatic balancing
- Support LL / LR / RR / RL rotation & rebalance
- Safe memory management & robust printing
- Clean, readable, debugged code

## 🚀 Usage
```c
tree_node *root = NULL;
root = tree_node_i32_add_avl(root, 14);
root = tree_node_i32_add_avl(root, 23);
tree_node_i32_print(root);
tree_node_i32_free(root);
