# 🌳 i32-BST & AVL Tree
Handcrafted Binary Search Tree & AVL Self-Balancing Tree in pure C.

![AVL Rotation Diagram](https://p11-flow-imagex-sign.byteimg.com/tos-cn-i-a9rns2rl98/b3634870900f4f348e0397c2176c02f1.png~tplv-a9rns2rl98-image.png?lk3s=8e244e95&rcl=202605101959177A4C6059FB23C05364B3&rrcfp=dafada99&x-expires=2094638357&x-signature=L7mAe0357cmnmqz70hGztTFiiz0%3D)

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
