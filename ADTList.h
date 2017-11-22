#pragma once
#include "Object.h"
#include <iostream>
class ADTList : public Object{
protected:
 int size;
public:
  ADTList();
  virtual ~ADTList();
  virtual bool insert (Object*,int)=0;
  virtual Object* remove(int)=0;
  virtual Object* first()const=0;
  virtual Object* last()const=0;
  virtual void clear()=0;
  virtual int indexOf(Object*)const=0;
  virtual Object* get(int)const=0;
  virtual bool isEmpty()const=0;
  virtual bool isFull()const=0;
  int Size()const;

};
