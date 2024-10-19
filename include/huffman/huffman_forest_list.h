#ifndef HUFFMAN_FOREST_LIST_H
#define HUFFMAN_FOREST_LIST_H

#include <list>
#include <memory>

#include "huff_tree.h"

//Huffman森林
using HuffForest = std::list<std::unique_ptr<HuffTree>>;

#endif  // HUFFMAN_FOREST_LIST_H