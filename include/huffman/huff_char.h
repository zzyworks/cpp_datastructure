#ifndef HUFF_CHAR_H
#define HUFF_CHAR_H

#define N_CHAR (0x80 - 0x20)

struct HuffChar {
  using value_type = char;
  using size_type = int;

  value_type ch;
  size_type weight;

  HuffChar(value_type c = '^', size_type w = 0);

  ~HuffChar();
};

bool operator<(const HuffChar& x, const HuffChar& y);
bool operator==(const HuffChar& x, const HuffChar& y);

#endif  // HUFF_CHAR_H