#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <memory>
#include <vector>

#include "bitmap.h"
#include "dictionary.hpp"
#include "entry.hpp"
#include "prime_nlt.h"

#include <iostream>

const char* PRIME_FILE =
  "/home/zzy0/vscode_workspace/data_structure/input/"
  "prime-1048576-bitmap.txt";

#define lazilyRemoved(x) (lazy_removal_->test(x))
#define markAsRemoved(x) (lazy_removal_->set(x))

// 字符
__attribute__((unused)) static size_t
hashCode(char c) {
  return (size_t)c;
}

// 整数以及长长整数
__attribute__((unused)) static size_t
hashCode(int k) {
  return (size_t)k;
}

__attribute__((unused)) static size_t
hashCode(long long i) {
  return (size_t)((i >> 32) + (int)i);
}

//生成字符串的循环移位散列码（cyclic shift hash code）
//对于英语单词，"循环左移5位"是实验统计得出的最佳值
__attribute__((unused)) static size_t
hashCode(char s[]) {
  int h = 0;                                    //散列码
  for(size_t n = strlen(s), i = 0; i < n; i++)  //自左向右，逐个处理每一字符
  {
    h = (h << 5) | (h >> 27);
    h += (int)s[i];
  }                  //散列码循环左移5位，再累加当前字符
  return (size_t)h;  //如此所得的散列码，实际上可理解为近似的“多项式散列码”
}

template<class K, class V>
class Hashtable : public Dictionary<K, V> {
  friend class UnionPrint;

public:
  using size_type = int;
  using key_type = K;
  using value_type = V;
  using reference_k = K&;
  using const_reference_k = const K&;
  using reference_v = V&;
  using const_reference_v = const V&;
  using pointer_k = K*;
  using const_pointer_k = const K*;
  using pointer_v = V*;
  using const_pointer_v = const V*;

private:
  std::vector<std::unique_ptr<Entry<K, V>>> ht_;  // 桶数组，存放词条指针
  size_type capacity_;                            // 桶数组容量
  size_type size_;                                // 词条数量
  std::unique_ptr<Bitmap> lazy_removal_;          // 懒惰删除标记

protected:
  /*
 * 沿关键码k对应的查找链，找到与之匹配的桶（供查找和删除词条时调用）
 * 试探策略多种多样，可灵活选取；这里仅以线性试探策略为例
 */
  size_type probe4Hit(const K& key) {
    //从起始桶（按除余法确定）出发
    size_type r = hashCode(key) % capacity_;
    //*DSA*/printf(" ->%d", r);
    //沿查找链线性试探：跳过所有冲突的桶，以及带懒惰删除标记的桶
    while((ht_[r] && (key != ht_[r]->base.first))
          || (!ht_[r] && lazilyRemoved(r)))
      r = (r + 1) % capacity_;
    //*DSA*/printf(" ->%d", r);
    //*DSA*/printf("\n");
    //调用者根据ht[r]是否为空，即可判断查找是否成功
    return r;
  }

  /*
 * 沿关键码k对应的查找链，找到首个可用空桶（仅供插入词条时调用）
 * 试探策略多种多样，可灵活选取；这里仅以线性试探策略为例
 */
  size_type probe4Free(const K& key) {
    int r = hashCode(key) % capacity_;  //从起始桶（按除余法确定）出发
    //*DSA*/printf(" ->%d", r); //首个试探的桶单元地址
    //沿查找链逐桶试探，直到首个空桶（无论是否带有懒惰删除标记）
    while(ht_[r])
      r = (r + 1) % capacity_;
    //*DSA*/   while (ht[r]) { r = (r+1) % M; printf(" ->%d", r); } printf("\n");
    return r;  //为保证空桶总能找到，装填因子及散列表长需要合理设置
  }

  /*
 * 重散列算法：装填因子过大时，采取“逐一取出再插入”的朴素策略，对桶数组扩容
 * 不可简单地（通过memcpy()）将原桶数组复制到新桶数组（比如前端），否则存在两个问题：
 * 1）会继承原有冲突；2）可能导致查找链在后端断裂——即便为所有扩充桶设置懒惰删除标志也无济于事
 */
  void rehash() {
    size_type old_capacity = capacity_;
    std::vector<std::unique_ptr<Entry<K, V>>> old_ht = std::move(ht_);
    //容量至少加倍
    capacity_ = primeNLT(PRIME_FILE, 2 * capacity_, 1048576);
    size_ = 0;
    ht_.resize(capacity_);
    //新开懒惰删除标记比特图
    lazy_removal_ = nullptr;
    lazy_removal_ = std::make_unique<Bitmap>(capacity_);
    //*DSA*/printf("A bucket array has been created with capacity = %d\n\n", M);
    for(size_type i = 0; i < old_capacity; i++) {
      if(old_ht[i])  //将非空桶中的词条逐一
        put(old_ht[i]->base.first, old_ht[i]->base.second);  //插入至新的桶数组
    }
    //释放原桶数组——由于其中原先存放的词条均已转移，故只需释放桶数组本身
    // old_ht.clear();
  }

public:
  //创建一个容量不小于c的散列表（为测试暂时选用较小的默认值）
  Hashtable(size_type capacity = 5) {
    //不小于capacity的素数capacity_
    capacity_ = primeNLT(PRIME_FILE, capacity, 1048576);
    size_ = 0;
    //开辟桶数组（还需核对申请成功），初始装填因子为N/M = 0%
    ht_.resize(capacity_);
    //懒惰删除标记比特图
    lazy_removal_ = std::make_unique<Bitmap>(capacity_);
    //*DSA*/printf("A bucket array has been created with capacity = %d\n\n", M);
  }

  Hashtable(Hashtable&& other)
      : ht_(std::move(other.ht_)),
        capacity_(other.capacity_),
        size_(other.size_),
        lazy_removal_(std::move(other.lazy_removal_)) {}

  virtual ~Hashtable() = default;

  Hashtable& operator=(Hashtable&& other) {
    if(this != &other) {
      ht_ = std::move(other.ht_);
      capacity_ = other.capacity_;
      size_ = other.size_;
      lazy_removal_ = std::move(other.lazy_removal_);
    }
    return *this;
  }

  size_type capacity() const { return capacity_; }

  // 当前词条总数
  size_type size() const override { return size_; }

  //插入（禁止雷同词条，故可能失败）
  bool put(const key_type& key, const value_type& value) override {
    if(ht_[probe4Hit(key)])
      return false;  //雷同元素不必重复插入
    //为新词条找个空桶（只要装填因子控制得当，必然成功）
    int r = probe4Free(key);
    ht_[r] = std::make_unique<Entry<K, V>>(key, value);
    ++size_;  //插入（注意：懒惰删除标记无需复位）
    if(size_ * 2 > capacity_)
      rehash();  //装填因子高于50%后重散列
    return true;
  }

  // 读取词条
  pointer_v get(const key_type& key) override {
    size_type r = probe4Hit(key);
    return ht_[r] ? &(ht_[r]->base.second) : nullptr;
  }

  //删除词条
  bool erase(const key_type& key) override {
    size_type r = probe4Hit(key);
    if(!ht_[r])
      return false;  //对应词条不存在时，无法删除
    ht_[r] = nullptr;
    markAsRemoved(r);
    --size_;
    return true;
    //否则释放桶中词条，设置懒惰删除标记，并更新词条总数
  }
};

#endif  // HASH_TABLE_HPP