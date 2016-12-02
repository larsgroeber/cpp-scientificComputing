Repository for the course "Advanced Introduction to C++ and Scientific Computing"

# Coding-Guidelines

## *Always* use braces (on new lines)

```c++
if ( test )
{
  // code
}

for ( int i = 0; i < N; i++ )
{
}
```

## *Always* use spaces between everything
```c++
std::cout << "Test" << std::endl;
void function_name ( int a, int b )
{
}

int a = 0;
a += 1;
a = a + 1:
a = exp( 2 ) / 3;

// except function calls
function_name( a, b );
```
## *No* non-const globals
```c++
// includes

const int N = 1;
const double test = 3;

int main ()
{
}
```

## Try to format your code nicely - 120 symbols per line max

```c++
printf( "This is just some random text %d %d %d"
        , a, b, c );

if ( long_name         == other_long_name
  && other_long_name2  == other_long_name3 )
{
}
```

## Misc

```c++
// pointers:
int* ptr;
// references:
int& ref;
```
