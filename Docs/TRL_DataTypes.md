# Definition
`TRL_DataType` is C a `Struct` that specifies a data type that will be used with a DataStructure or an Algorithm.

# DataType
TRL_DataType is and enum which is basicly a set of in house data types used inside TRL to kinda replace templates.\
Well, it doesn't *REPLACE* the data types in C but instead it specifies the type of a DataStructure's Data.

If you want to know what DataTypes there are inside TRL just checkout the Datatype.h in the `Include` folder that came with the github package or in the `TotallyReliableLibrary/Include` folder if you cloned the project.

You wont be using it in many cases by there is a function called `TRL_DataTypeValue(TRL_DataType type)` that takes in a TRL_DataType as param and gives how much memory that DataType occupies.\
This function is a `static inlined function` so dont worry about performence that much. And modern should be able to optimize this away easily.

# Use Case
A good use case for this struct is the [Buffer](Buffer.md).

Basicly, when creating a buffer, you will have to specify the DataType in use.\
You have to do this because C doesn't have `templates` so TRL uses a `void *` for specifying unspecified data.\
And when using the DataStructure, the functions convert the data inside the DataStructure to use the specified DataType.

Example: (More about the function provided below in [Buffer.md](Buffer.md))
```cpp
TRL_Buffer *buffer = TRL_Buffer_Create(TRL_DataType_Int, 0);
```
This code snippet shows a function that uses TRL_DataType as a parameter.\
As you can see, to create a buffer, we need to specify what data type the buffer is.

It is basicly like `std::vector<int>` but instead of using templates, we pass in an in house DataType.
