The above... I mean below text teaches you how to setup the library for your own use.

1. Make sure you downloaded the package from github which has the `.lib` file and all the headers.\
  **NOTE:** If you want to compile the library for yourself, go to [BUILD.md](BUILD.md)
2. Extract the package into your project root foler.\
  **NOTE:** The extracted stuff will also contain a `CMakeLists.txt` with default setup. If you have your own, make sure not to extract that file.

Now You should have the folders:

- Include
- Library

The `Library` folder will contain a `TRL.lib`\
The `Include` folder will contain all the functions you need.

Thats it really.\
I don't wanna write out what to do with every single setup.\
But with CMake you just need to add this line to you `CMakeLists.txt`
```
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Library/TRL.lib)
```

And you need to add this into your includes:

```
target_include_directories(${PROJECT_NAME} PUBLIC
  ...
  <PATH_TO_TRL_INCLUDE_FOLDER>
  ...
)
```
EXAMPLE:
```
target_include_directories(${PROJECT_NAME} PUBLIC
  ...
  ${PROJECT_SOURCE_DIR}/Include
  ...
)
```

Thats it really. Unless I forgot about something.\
I will add it if I did.