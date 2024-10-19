#ifndef BITMAP_H
#define BITMAP_H

#include <utility>
#include <cstdio>
#include <cstring>
#include <string>

class Bitmap {
private:
  char* map_; // 比特图所存放的空间
  size_t n_;  // 所需字节大小，容量为n_*sizeof(char)*8比特

  void init(size_t n);

  void readFile(const char* file, size_t n);

  void writeFile(const char* file);

public:
  Bitmap(size_t n = 8);

  Bitmap(const char* file, size_t n = 8);

  ~Bitmap();

  // 设置位图
  void set(size_t n);

  // 清除位图
  void clear(size_t n);

  // 获取位图
  bool test(size_t n);

  // 若被访问的Bitmap[k]已出界，则需扩容
  void expand(size_t n);

  // 将位图整体导出至指定的文件，以便对此后的新位图批量初始化
  void dump(const char* file);

  std::string bitsToString(size_t n);
};

#endif  // BITMAP_H