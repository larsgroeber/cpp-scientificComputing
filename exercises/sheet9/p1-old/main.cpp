#include <iostream>	// standard IO
#include <stdio.h>	// printf()

typedef std::ostream& (*STRFUNC)(std::ostream&);

template <size_t size>
//making the Buffer(stolen from the lecture)
class BufferClass
{
private:
int pos;				     // for insertion
double data[size];

public:
bool isEmpty,isFull;

//the standard Buffer constructor
BufferClass<size>()
  { pos=0;
    isEmpty = true;
    isFull = true;
    if (size>0)
      isFull = false;
    for (int i=0;i<size;i++)
      data[i] = 0;
  }

template <typename T>
//the Method to write into the Buffer
BufferClass<size>& operator>>(T &outInt)
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

template <typename T>
//and to get something out of the Buffer
BufferClass<size>& operator<<(T newInt)
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
//The Buffer should be for 10 types, since I couldnt do it for other than int it's only for int
 BufferClass<10> myBuffer;
 int test = 0;
 int content = 0;
//
 printf("content of buffer: ");
 while (!myBuffer.isEmpty)
   {
   myBuffer >> test;
   printf("%4d",test);
   }
 printf("\n");
//inserting something in the Buffer and printing it
 myBuffer << 5.3;
 myBuffer << 7 << 9;
 printf("content of buffer: ");
 while (!myBuffer.isEmpty)
   {
   myBuffer >> test;
   printf("%4d",test);
   }
 printf("\n");
//
//looking if something is in the Buffer
 if (!myBuffer.isEmpty)
    printf("Der Buffer ist leer");
else
    printf("Es ist etwas im Buffer");
    myBuffer >> content;
//well something is, but we want to see what
    printf("Und zwar: ");
    printf("%4d",content);
//this is just so the output is less packed and more readable
 printf("\n");

 return 0;
}
