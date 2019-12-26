#include<iostream>
namespace test
{
template<class T>
class vector {
public:
  typedef T* iterator;
  typedef const T* const_iterator;
  //////////////////////////////////////
  //构造与销毁
  vector()
    : _start(nullptr)
    , _finish(nullptr)
    , _endofstorage(nullptr)
  {}
  vector(int n, const T &data)
    : _start(new T[n])
  {
    for(size_t i = 0; i < n; ++i)
      _start[i] = data;
    _finish = _start + n;
    _endofstorage = _finish;
  }
  //[first,last)
  template<class Iterator>
  vector(Iterator fir, Iterator last)
  {
    size_t n = 0;
    auto it = fir; 
    while(it != last)
    {
      ++n;
      ++it;
    }
    _start = new T[n];
    for(size_t i = 0; i < n; ++i)
      _start[i] = *fir++;
    _finish = n + _start;
    _endofstorage = n + _start;
  }
  vector(const vector<T>& v)
    : _start(nullptr)
      , _finish(nullptr)
      , _endofstorage(nullptr)
  {
    reserve(v.capacity());
    iterator it = begin();
    const_iterator vit = v.c_begin();
    while(vit != v.c_end())
    {
      *it++ = *vit++;
    }
    _finish = _start + v.size();
    _endofstorage = _start + v.capacity();
  }
  vector<T>& operator=(const vector<T>& v)
  {
    swap(v);
    return *this;
  }
  ~vector()
  {
    if(_start)
    {
      delete[] _start;
      _start = _finish = _endofstorage = nullptr;
    }
  }
  //////////////////////////////////////
  //迭代器
  iterator begin()
  {
    return _start;
  }
  iterator end()
  {
    return _finish;
  }
  const_iterator c_begin() const
  {
    return _start;
  }
  const_iterator c_end() const
  {
    return _finish;
  }

  //////////////////////////////////////
  //容量操作
  size_t size()const
  {
    return _finish - _start;
  }
  size_t capacity()const
  {
    return _endofstorage - _start;
  }
  bool empty()const
  {
    return _start == _finish;
  }
  //T():
  //如果T代表内置类型，T()---> 0
  //如果T代表自定义类型，T()--->调用该类的无参构造函数
  void resize(size_t newsize,const T &data = T())
  {
    size_t oldsize = size();
    if(newsize > oldsize)//新的size > 旧的size，分为两种情况：1.新的size大于容量，2.新的size不大于容量
    {
       size_t cap = capacity();
       if(newsize > cap)//新的size大于容量，扩容
         reserve(newsize);
       for(;oldsize < newsize; ++oldsize)//用data填充开辟的空间
         _start[oldsize] = data;

    }
    _finish = _start + newsize;//更新finish
  }
  void reserve(size_t newCapacity)
  {
    size_t oldCapacity = capacity();
    if(newCapacity > oldCapacity)
    {
      T *temp = new T[newCapacity];//申请新空间
      size_t n = size();
      if(_start)
      {
      //memcpy(temp,_start,size() * sizeof(T));
      for(size_t i = 0; i < n; ++i)//拷贝元素
        temp[i] = _start[i];
      delete[] _start;
      } 
      _start = temp;
      _finish = n + _start;
      _endofstorage = _start + newCapacity;
    }
  }
  /////////////////////////////////////
  //元素访问操作
 T &operator[](size_t index)
 {
   assert(index < size());
   return _start[index];
 }
 const T &operator[](size_t index)const
 {
   assert(index < size());
   return _start[index];
 }
 T &front()
 {
   return *_start;
 }
 const T &front()const
 {
   return *_start;
 }
 T &back()
 {
   return *(_finish - 1);
 }
 const T &back()const
 {
   return *(_finish - 1);
 }
  /////////////////////////////////////
  //修改操作
  void push_back(const T &data)
  {
    if(_finish == _endofstorage)//判断是否需要扩容
    {
      reserve(capacity() * 2 + 3);
    }
    *_finish++ = data;
  }
  void pop_back()
  {
    _finish--;
  }
  //返回值的含义：返回新插入元素的位置
  iterator insert(iterator pos, const T &data)
  {
    if(_finish == _endofstorage)//判断是否需要扩容
    reserve(capacity() * 2);
    auto it = _finish;//搬移[pos,_finish)之间的元素
    while(it > pos)
    {
     *it = *(it - 1);
      it--;
    }
    *pos = data;
    ++_finish;
    return pos;
  }
  iterator erase(iterator pos)//删除pos位置元素，返回下一个元素的位置
  {
   if(pos == end()) 
     return pos;
   auto it = pos + 1;//it代表要搬移元素的位置
   while(it != _finish)
   {
   *it = *(it - 1);
   it++;
   }
   --_finish;
   return pos;
  }
  void clear()
  {
    _finish = _start; 
  }
private:
T *_start;
T *_finish;
T *_endofstorage;

 };
}
void TestVector1()
{
  test::vector<int> v1;
  test::vector<int> v2(10,5);
  int arr[] = {1,2,3,4,5};
  test::vector<int> v3(arr,arr + sizeof(arr)/sizeof(arr[0]));
  test::vector<int> v4(v2);
}
int main()
{
  TestVector1();
  return 0;
}
