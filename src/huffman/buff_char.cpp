#include "huff_char.h"

HuffChar::HuffChar(value_type c, size_type w) : ch(c), weight(w) {}

HuffChar::~HuffChar() = default;

bool operator<(const HuffChar& x, const HuffChar& y) {
  return x.weight > y.weight;
}

bool operator==(const HuffChar& x, const HuffChar& y) {
  return x.weight == y.weight;
}