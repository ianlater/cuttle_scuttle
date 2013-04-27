#include <iostream>
#include <string>
#ifndef MY_LIST_H
#define MY_LIST_H
const int DEFAULT_LIST_SIZE = 100;
using namespace std;

template <typename T>
class MyList {
public:
  MyList();
  MyList(unsigned int capacity);
  ~MyList();
  void push_back(T val);
  T& at(unsigned int loc) ;
  unsigned int size() const;
  void print();
  bool remove(T val);
  T& operator[](unsigned int loc);
private:
  T* data_;
  unsigned int size_;
  unsigned int capacity_;
  int e_;//for managing errors
};

template <typename T>
MyList<T>::MyList()
{
  capacity_=DEFAULT_LIST_SIZE;
  data_=new T[capacity_];
  size_=0;
  e_=0;
}
template <typename T>
MyList<T>::MyList(unsigned int capacity)
{
  capacity_=capacity;
  data_=new T[capacity_];
  size_=0;
  e_=0;
}
template <typename T>
MyList<T>::~MyList()
{
  delete []data_;
}
template <typename T>
void MyList<T>::push_back(T val)
{
  if(size_>=capacity_){
    capacity_=capacity_*2;
    T* temp=new T[capacity_];
    for (unsigned int i=0;i<size_;i++){
	temp[i]=data_[i];
    }
    delete[] data_;
    data_=temp;
  }
  data_[size_++]=val;
}
template <typename T>
T& MyList<T>::at(unsigned int loc)
{
  if(loc>=size_){
  e_=1;
  throw loc;
  }
  return data_[loc];
}
template <typename T>
unsigned int MyList<T>::size()const
{
  return size_;
}
template <typename T>
void MyList<T>::print(){
  for(unsigned int i=0; i<size_;i++){
    cout<<data_[i]<<" ";
  }
}

template <typename T>
bool MyList<T>::remove(T val){
  for(unsigned int i=0;i<size_;i++){
    if(data_[i]==val){
      T* temp=new T[capacity_];
      for (unsigned int j=0;j<size_-1;j++){
        if(j>=i)
          temp[j]=data_[j+1];
        else
          temp[j]=data_[j];
      }
      delete[] data_;
      data_=temp;
      size_--;
      return true;
    }
  }
throw false;
}
template <typename T>
T& MyList<T>::operator[](unsigned int loc){
  return at(loc);
}

#endif
