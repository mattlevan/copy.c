# copy.c
A program for copying text files.

####HOW TO COMPILE
1. run command make - to build program
2. run ./MyCopy.exe - to run the copy program
3. follow onscreen prompts to copy your files

---
####SystemCalls
UNIX/Linux: To view the system calls the operating system makes while
running this program, run `strace ./a.out`.

---
####Prompt
Write a C program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Be sure to include all necessary error checking, including a) if the source file does not exists,  it should print a message and ask for the source file name, until the source file does exist; b) if destination file does exist, it should ask the user whether to replace the existing file or not. If user answers yes, it proceeds to replace the existing file; if user answer no, it terminates.

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility , and Solaris and Mac OS X use the dtrace facility. As Windows systems do not provide such features, you will have to trace through the Win32 version of this program using a debugger.

It is done in group of two students. Please submit a .zip file, which includes:

1. your source program, and

2. README file, including i) how to compile and run your program, ii) the list of system calls involved, supported by screen shots, iii) two member members' name and each's specific contribution to the project.

To start with, Google and read carefully:

how to trace system calls in XXX, where XXX is either windows, linux/unix, or mac os x.

Please note that all submissions are final, that is, it allows only one attempt.


