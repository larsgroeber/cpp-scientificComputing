#include <iostream>	// standard IO
#include <stdio.h>	// printf()

typedef std::ostream& (*STRFUNC)(std::ostream&);

template <size_t size>
class BufferClass
{
private:
int pos;				     // for insertion
double data[size];

public:
bool isEmpty,isFull;

BufferClass<size>()			     // standard constructor
  { pos=0;
    isEmpty = true;
    isFull = true;
    if (size>0)
      isFull = false;
    for (int i=0;i<size;i++)
      data[i] = 0;
  }

template <class T>
BufferClass<size>& operator>>(T &outInt)	     // like cin >> variable
  {
  if (pos>0)
    {
    pos--;
    isFull = false;
    }
  if (pos==0)
    isEmpty = true;
  outInt = data[pos];
  return *this;
  }

template <class T>
BufferClass<size>& operator<<(T newInt)	    // like cout << variable
  {
  if (!isFull)
    {
    data[pos] = newInt;
    isEmpty = false;
    }
  if (pos<(size-1))
    {
    pos++;
    }
  else
    isFull = true;
  return *this;
  }

};

int main()
{
 BufferClass<10> myBuffer;	// a buffer for up-to 10 integers
 double test = 0;
//
 printf("content of buffer: ");
 while (!myBuffer.isEmpty)
   {
   myBuffer >> test;
   printf("%4d",test);
   }
 printf("\n");
//
 myBuffer << 3.3;
 myBuffer << 4 << 5;
 printf("content of buffer: ");
 while (!myBuffer.isEmpty)
   {
   myBuffer >> test;
   printf("%4d",test);
   }
 printf("\n");
//
 return 0;
}
