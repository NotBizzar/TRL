# Dependencies
So... First, You Will Need These:

1. Cmake
2. Ninja (Other Generators Are Not Tested)
3. Clang (Other Compilers Are Not Tested)
4. MSVC Build Tools (If You Are On Windows)

# Cloning The Repo
This section will take you through the cloning process. The first thing you need to do.\
It's easy really, just follow the steps:

1. Open the command line, and go to the folder where you want this repo to be cloned.
2. Type in the command:
```
https://github.com/NotHalls/TRL.git
```
3. Well, that's it. now just `cd` into the folder named `TRL`\
  a. It's `cd` if you are on `Unix`, `Windows Terminal` or `Git Bash` to open a `dir`/`folder`
4. All you need to do is run the below command and continue to the **Building** section
```
cd TRL
```

# Building
## From VSCode
If you are on VSCode, there is an easy way to do things:

1. Install the `CMakeTools Extension` from Microsoft [LINK](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
2. Now go to the extensions settings and set this setting [cmake.useCMakePresets](vscode://settings/cmake.useCMakePresets) to `always`\
  a. **NOTE:** This is only if you want to use CMakePresets.json provided by this project. If you dont wanna use that, then you can setup your own environment structure in any IDE you want. But it is recomended to use CMakePresets because thats the only way we tested it. :)
3. Now you need to do is, hit `Ctrl + Shift + P`. It's the key to open the command pallet. `>`
4. Then, search for the command named `>CMake: Select Configure Preset`. This selects the configuration preset from CMakePresets.json
5. VSCode should configure the project automatically now, but just to be safe, run the next command: `>CMake: Configure`
6. Good, you are all set. Now you just need to build the project. You Can Skip to the **Compiling** section

## From Command Line
Well, Command Line would be my first choice too. I mean, who the fuck likes easy stuff anyway right.\
Now, we will be using CMakePresets because it's just way better OK?

1. Make sure you are in the project folder where you will see folders: `TotallyReliableLibrary/` and `Test/`. With those you will also see a `CMakeLists.txt` and `CMakePresets.json` files.

Before we continue, You need to know all the presets available.\
The Available Presets Are:\
- Clang-Debug
- Clang-Release
- Clang-Export

If you want more, just add them to the CMakePresets.json.\
or delete any if you dont need them.

Now, all you need to do is run this command:
```
cmake --preset <THE_PRESET_NAME>
```
This will build the nessesary stuff into a folder named `build`.\
Thats it, you are ready to compile the project now.


# Compiling
Well, the last part is here

## From VSCode
Its just two buttons/commands (In the command pallet `>`) for this.

1. You can `F5` or run `>CMake: Build` in the command pallet to compile and run the project.
2. You can `F7` or run `>CMake: Debug` to only compile the project and not run it.

Alternatively, you can `Ctrl + Shift + F5` or run `>CMake: Run Without Debugging` in the command pallet to compile and run the project wihtout Debugging it.


## From Command Line
One command. That's it! Just one fucking command...\
unless you get errors.


Make sure you are in the root folder of the project like before and run this command:
```
cmake --build build
```

Greate! Now you should have an executable in `${ProjectRoot}/bin/<BuildPlatform>-<BuildType>-<Compiler>/Test.exe`. You just need to run it.

Just do you are not confused, If you are compiling from `Windows` using `Debug` mode and using the `Clang` compiler, you should get the folder path for your executable like this:\
`${ProjectRoot}/bin/Windows-Debug-Clang/Test.exe`