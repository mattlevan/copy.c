# copy.c
A program for copying text files.

Bradley Taniguchi: First draft, program structure, prompt(), file_exists()
Matt Levan: Naming cleanup, copy(), system calls in README

####INSTRUCTIONS
1. `gcc copy.c -o copy.o`
2. `./copy.o`
3. Follow onscreen prompts to copy your files

---
####SystemCalls
UNIX/Linux: To view the system calls the operating system makes while
running this program, run:

`strace ./copy.o`

For Windows: ... run:

`example code`

For Mac OS X/Solaris: ... run:

`dtrace ./copy.o`


Included in this repository is `strace_log` which is a log created by
running `strace -ostrace_log ./copy.o`.

List of system calls listed in `strace_log` in order of occurrence (no
repeats) with the line of occurrence in the first bullet point:

1. `int execve(const char *filename, char *const argv[], char *const envp[]
);`

  * Line 1: `execve("./copy.o", ["./copy.o"], [/* 28 vars */]) = 0`
  * Executes the program pointed to by the filename.

2. `int brk(void *addr);`

  * Line 2: `brk(0) = 0x676000`
  * Changes data segment size, maybe allocates memory.

3. `int access(const char *pathname, int mode);`

  * Line 3: `access(/etc/ld.so.nohwcap", F_OK) = -1 ENOENT (No such file or
  directory)`
  * Check a user's permissions for a file.

4. `void *mmap(void *addr, size_t length, int prot, int flags, int fd,
off_t offset);`

  * Line 4: `mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|
  MAP_ANONYMOUS, -1, 0) = 0x7f16f3652000`
  * Map or unmap files or devices into memory (loading of header?).

5. `open(const char *pathname, int flags) = 4`

  * Line 6: `open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 4`
  * Opens and possibly creates a file.

7. `int fstat(int fd, struct stat *buf);`

  * Line 7: `fstat(4, {st_mode=S_IFREG|0644, st_size=48760, ...}) = 0`
  * Gets file status.

8. `int close(int fd);`

  * Line 9: `close(4)`
  * Closes a file descriptor so that it no longer refers to any file.

9. `int mprotect(void *addr, size_t len, int prot);`

  * Line 15: `mprotect(0x7f16f3228000, 2093056, PROT_NONE) = 0`
  * Set protection on a region of memory.

10. `int arch_prctl(int code, unsigned long addr);`

  * Line 21: `arch_prctl(ARCH_SET_FS, 0x7f16f3643740)`
  * Set architecture-specific thread state.

11. `int munmap(void *addr, size_t length);`

  * Line 25: `munmap(0x7f16f36546000, 48760)`
  * Map or unmap files or devices into memory.

12. `ssize_t write(int fd, const void *buf, size_t count);`

  * Line 30: `write(1, "Enter name of source file: ", 27) = 27`
  * Write to a file descriptor. In this case, maybe it writes the text to
the screen.

13. `ssize_t read(int fd, void *buf, size_t count);`

  * Line 31: `read(0, "makefile\n", 1024) = 9`
  * Read from a file descriptor.

14. `void exit_group(int status);`

  * Line 53: `exit_group(0)`
  * Exit all threads in a process. I believe 0 indicates a successful
  execution.

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


