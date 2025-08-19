# Requirments
[TRL_DataTypes](TRL_DataTypes.md)

# Definition
TRL_Buffer is a `dynamic array` in C. Like an `std::vector<>` in C++.\
Basicly, an array that does malloc and memory related stuff itself without you bothering about it much.\
Well, you are still required to `Destroy` the buffer and shit when you are done using it.

# The Data Structure
This is the structure of `TRL_Buffer`
```cpp
{
  void *Raw
  unsigned long long (size_t) Size
  TRL_DataType Type;
}
```
- The `Raw` is the main data in the buffer that contains all the elements you gave it.\
- The `Size` gives you how many elements there are inside of the buffer. To get the actual size of the buffer elements, there is a seperate function.\
- The `Type` is basically the data type of the buffer specified in `TRL_DataType`.

# How To Use
***NOTE:*** You can refer to `Include/Buffer.h` to know more about the functions.
## First, you need to create a buffer by using `TRL_Buffer_Create`
```cpp
TRL_Buffer *buffer = TRL_Buffer_Create(TRL_DataType, size);
```
That will create the buffer and return the pointer to that buffer.

That's it now (if you have intellisense), you should get all the functions related to `TRL_Buffers` when you type `TRL_Buffer_`

# Functions
All the functions have one thing in common (Except Create). And that is, every function takes a TRL_Buffer param that specifies what buffer to work on.

## TRL_Buffer_Destroy
This will destroy the buffer provided by the parameter.\
Tho TRL handles all the hassle to dynamically allocate memory, it doesn't automatically delete memory.\
This is where you come in and do it yourself.

Example:
```cpp
TRL_Buffer_Destroy(buffer);
```
Thats it, it will `free` the `buffer` from memory.

## TRL_Buffer_Read
Used to read something from a buffer.\
The function will give you a `void*` which is the location of the index you specify in the TRL_Buffer_Read function.

Example:
```cpp
int returnValue = *(int *)TRL_Buffer_Read(buffer, 0);
```
This code snippet will get the value from index 0 in `buffer` and convert it into an `int*` and dereference it. This dereferenced value goes into the returnValue.

You don't have to but it is recomended to convert the variable to the data type you want before using it.\
you can also return the variable to an `int*` and dereference it later when you use it.

Now, you have to remember what data type you used for the buffer for using these functions.\
To make this a little easy on yourself you can name the buffer variables like this: `iBuffer` or `intBuffer` instead of just `buffer`.


## TRL_Buffer_Write
TRL_Buffer_Write is a function that just pushes a new value into the buffer at the end
```cpp
TRL_Buffer_Write(TRL_Buffer*, void*);
```
Here, the first param is the buffer you need to pass the value into.\
And the second param is the data you need to pass in.\

Now it is a bit tricky to pass in an `RValue` so this is an example if we consider the above created buffer:
```cpp
TRL_Buffer_Write(buffer, (int){10});
```
This passes in the value 10 into the buffer.\
You can also just create a variable and pass in that variable into the param by TypeCasting it.

## TRL_Buffer_WriteAt
This funtion is like Write but it will replace the value at a specified index.\
So if you have a buffer with 2 (0 and 1) elements and you WriteAt index 0, it will replace the value at index 0 with the newly given value inside the WriteAt function.

Example:
```cpp
TRL_Buffer_Write(buffer, &(int){69});
TRL_Buffer_Write(buffer, &(int){96});

TRL_Buffer_WriteAt(buffer, 0, &(int){6969});
```
This will change the value at index 0 which is 69 to 6969.

# TRL_Buffer_Remove
This function removes a value at specified index.\

Example:
```cpp
TRL_Buffer_Write(buffer, &(int){19});
TRL_Buffer_Write(buffer, &(int){29});
TRL_Buffer_Write(buffer, &(int){39})
TRL_Buffer_Remove(buffer, 0);
```
This will remove the element at 0 which is 19. and like any normal dynamic array out there, it also moves the buffer to the front.\
Meaning the second element will be first now and the third element will be second and so on...

# TRL_Buffer_GetActualSize()
This is a basic function that multiplies the `TRL_BufferSize` with `TRL_BufferType` to get the actual size in memory.

# TRL_Buffer_GetDataInType
This is a `#define` that returns the `TRL_BufferRaw` in the data type you provide.

Example:
```cpp
int *data = TRL_Buffer_GetDataInType(buffer, int);
```
This will return the `Raw` inside a `TRL_Buffer` as an `int*`.\
SO you basically have an int array now. A pointer array.