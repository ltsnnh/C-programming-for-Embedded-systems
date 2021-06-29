# C PROGRAMMING FOR EMBEDDED SYSTEMS
---
### This project only uses open source tools
No Windows based IDE environments are used or implied! Cygwin, Linux, MacOS and BSD environments are suitable.
### Project structure
    C-programming-for-Embedded-systems/
        |- README.md
        |- Makefile             
        |- Makefile.incl        Rules for make file builds
        |- Variable-in-C/       
            |- example-1/       Example folder
            |   |- inc/
            |       |- *        User library files
            |   |- src/
            |       |- main.c   Source code
            |       |- task1.c  
            |       |- task2.c  
            |       |- task3.c  
            |   |- obj/
            |       |- *        Object files
            |   |- main         Executable file
            |   |- Makefile
            |   |- README.md
### How to use this Makefile To adapt this Makefile to your project you have to:
1. Change the BINARY variable to match your target name.
2. Put your C/C++ files in the `src/` folder.
3. Put your Header files in the `inc/` folder.
4. Object files in `obj/` folder, execultive program in root project directory.
5. If required, change the compiler and the flags.