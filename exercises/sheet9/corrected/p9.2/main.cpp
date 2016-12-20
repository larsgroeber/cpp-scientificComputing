/*************************************************
*	Comments by Bulcsu Sandor: "// BS: "
*	Points: 2/6
*************************************************/

// BS: stored data type should be templated
// BS: not only the input/output one
// BS: methods for reset, current load and state are missing
// BS: isEmpty and isFull should be private
// BS: size not templated

/**
* Solution of problem 2, sheet 9.
* by Lars Gröber, Hendrik Edelmann and Robert Söder
*/

#include <iostream>	// standard IO
#include <stdio.h>	// printf()

// BS: not needed!
typedef std::ostream& (*STRFUNC)(std::ostream&);

// BS: size should be speified by the constructor
// BS: and not templated
template <size_t size>
//making the Buffer(stolen from the lecture)
class BufferClass
{
private:
int pos;				     // for insertion

// BS: the data type is hard-coded here...
double data[size];

public:
bool isEmpty,isFull;
// BS: these should be private

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
// BS: ok!

template <typename T>
//the Method to write into the Buffer
// BS: but this is extraction
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
// BS: ok!

template <typename T>
//and to get something out of the Buffer
// BS: and this is insertion
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
// BS: test should be double here

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
