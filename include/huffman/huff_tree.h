#ifndef HUFF_TREE_H
#define HUFF_TREE_H

#include "bin_tree.hpp"
#include "huff_char.h"

/*DSA*///typedef BinTree<HuffChar> HuffTree; //Huffman树，由BinTree派生，节点类型为HuffChar
#define HuffTree BinTree<HuffChar> //Huffman树，由BinTree派生，节点类型为HuffChar

#endif  // HUFF_TREE_H