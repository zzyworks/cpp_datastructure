#include "bitmap.h"

void
Bitmap::init(size_t n) {
  n_ = (n + 7) / 8;  // 最低8字节，防止只存1字节
  map_ = new char[n_];
  memset(map_, 0, n_);
}

void
Bitmap::readFile(const char* file, size_t n) {
  FILE* fp = fopen(file, "r");
  fread(map_, sizeof(char), n_, fp);
  fclose(fp);
}

void
Bitmap::writeFile(const char* file) {
  FILE* fp = fopen(file, "w");
  fwrite(map_, sizeof(char), n_, fp);
  fclose(fp);
}

Bitmap::Bitmap(size_t n) {
  init(n);
}

Bitmap::Bitmap(const char* file, size_t n) {
  init(n);
  readFile(file, n);
}

Bitmap::~Bitmap() {
  if(map_) {
    delete[] map_;
    map_ = nullptr;
  }
}

void
Bitmap::set(size_t n) {
  expand(n);
  // (n & 0x07) = n % 8
  map_[n >> 3] |= (0x80 >> (n & 0x07));
}

void
Bitmap::clear(size_t n) {
  expand(n);
  map_[n >> 3] &= ~(0x80 >> (n & 0x07));
}

bool
Bitmap::test(size_t n) {
  expand(n);
  return map_[n >> 3] & (0x80 >> (n & 0x07));
}

void
Bitmap::expand(size_t n) {
  if(n < 8 * n_)
    return;
  size_t old_n = n_;
  char* old_map = map_;
  init(2 * n);
  memcpy(map_, old_map, old_n);
  delete[] old_map;
}

void
Bitmap::dump(const char* file) {
  writeFile(file);
}

std::string
Bitmap::bitsToString(size_t n) {
  std::string str(n, ' ');
  for(size_t i = 0; i != n; ++i)
    str[i] = test(i) ? '1' : '0';
  return str;
}