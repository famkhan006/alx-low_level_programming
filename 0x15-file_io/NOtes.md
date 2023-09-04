# FILE I/O

0.Motivation
1.File Descriptors
2.open System Call
3.File Opening Modes and Flags
4.Standard Input, Output, and Error
5.write System Call
6.unistd Symbolic Constants

### MOTIVATION TO LEARN FILE I/O


I want to share the **immense motivation** behind learning file input/output (I/O) in C.

By **mastering file I/O**, you gain the power to **store and retrieve data persistently**. Imagine creating applications that remain valuable even after they've finished executing.

You'll be able to **process vast amounts of data efficiently**, perform **complex computations**, and seamlessly **interact with external resources** like databases and network sockets.

Mastering file I/O equips you with **essential skills for managing files and directories effortlessly**. It gives you an edge in a competitive job market and ensures your skills remain adaptable across programming languages.

Countless real-world applications rely on file I/O, from **text processing and database management** to **log file analysis** and **scientific data manipulation**. By mastering this skill, you'll be ready to tackle challenging projects and contribute to groundbreaking developments.

Moreover, file I/O skills are **invaluable for debugging and testing applications**. You can log debugging information, record program states, and capture error messages, making you a more efficient and effective programmer.

**Embrace the power of file I/O in C**. Let this knowledge drive your programming journey, unlock its potential, and create remarkable applications that shape the future of technology.

# File Descriptors

In Unix-like operating systems, file descriptors are used to represent open files or input/output sources. They are integer values that serve as references to files or devices opened by a process. File descriptors are typically used for reading from or writing to files, sockets, pipes, and other input/output resources.

## Standard File Descriptors

Unix-like systems have three standard file descriptors that are automatically opened for a process:

- **Standard Input** (`stdin`): Represented by file descriptor 0, it is the default input stream where a process reads data from. It is typically connected to the keyboard or another input source.
- **Standard Output** (`stdout`): Represented by file descriptor 1, it is the default output stream where a process writes its normal output. It is typically connected to the terminal or another output destination.
- **Standard Error** (`stderr`): Represented by file descriptor 2, it is the default output stream where a process writes error messages or diagnostic information. It is also typically connected to the terminal or an error log file.

## Non-Standard File Descriptors

File descriptors other than the standard ones can be obtained when opening files or creating new input/output resources using system calls like `open`, `socket`, or `pipe`. These file descriptors are assigned unique integer values greater than or equal to 3.

## File Descriptor Values

By convention, file descriptor values 0, 1, and 2 are reserved for the standard input, output, and error respectively. File descriptors obtained through system calls like `open` start from 3 and increment for each subsequent file or resource opened by the process.

When a file is successfully opened, the `open` system call returns a non-negative integer, which represents the file descriptor associated with the opened file. If the `open` call fails, it returns -1, indicating an error.

File descriptors can be used with various system calls to perform operations like reading, writing, seeking, and closing files or input/output resources.i


# The `open` System Call

The `open` system call is used to open files and create a new file descriptor. It provides a way to access files for reading, writing, or both, depending on the specified flags and mode.

## Syntax

The syntax for the `open` system call is as follows:

```c
#include <fcntl.h>

int open(const char *path, int flags, mode_t mode);
```

- `path`: The path to the file that needs to be opened.
- `flags`: Flags that control the behavior of the `open` call, such as read-only, write-only, or read-write access, creating the file if it doesn't exist, etc. These flags are defined in the `<fcntl.h>` header file.
- `mode`: The file mode that specifies the permissions to set for the newly created file, if applicable. This parameter is only used when creating a new file.

## Return Value

The `open` system call returns a new file descriptor if successful, which is a non-negative integer representing the opened file. If an error occurs, it returns -1, and the specific error code can be retrieved from the `errno` variable.

## Examples

Here are a few examples of using the `open` system call:

1. Opening an existing file in read-only mode:
   `````c
   int fd = open("file.txt", O_RDONLY);
   ```

2. Creating a new file with read and write permissions:
   ````c
   int fd = open("newfile.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
   ```

3. Opening a file and truncating it to zero length:
   ````c
   int fd = open("file.txt", O_WRONLY | O_TRUNC);
   ```

## Common Flags

Here are some commonly used flags for the `open` system call:

- `O_RDONLY`: Open for reading only.
- `O_WRONLY`: Open for writing only.
- `O_RDWR`: Open for reading and writing.
- `O_CREAT`: Create the file if it doesn't exist.
- `O_TRUNC`: Truncate the file to zero length if it already exists.

Remember to include the `<fcntl.h>` header file to use these flags.




# File Opening Modes and Flags

When using the `open` system call, you can specify different modes and flags to control how a file is opened. Modes determine whether the file is opened for reading, writing, or both, while flags provide additional behaviors and options.

## Opening Modes

The opening modes specify the access mode for the file. They can be used individually or combined using the bitwise OR (`|`) operator.

- **Read-Only Mode**: Open the file for reading only.
  - Symbolic Constant: `O_RDONLY`
  - Numeric Value: `0`

- **Write-Only Mode**: Open the file for writing only.
  - Symbolic Constant: `O_WRONLY`
  - Numeric Value: `1`

- **Read-Write Mode**: Open the file for both reading and writing.
  - Symbolic Constant: `O_RDWR`
  - Numeric Value: `2`

## Opening Flags

Opening flags control various aspects of the file opening process. They can also be used individually or combined using the bitwise OR (`|`) operator.

- **Create Flag**: Create the file if it doesn't exist.
  - Symbolic Constant: `O_CREAT`
  - Numeric Value: `0100` (octal)

- **Truncate Flag**: Truncate the file to zero length if it already exists.
  - Symbolic Constant: `O_TRUNC`
  - Numeric Value: `01000` (octal)

- **Append Flag**: Set the file offset to the end of the file before each write operation.
  - Symbolic Constant: `O_APPEND`
  - Numeric Value: `02000` (octal)

- **Exclusive Flag**: Ensure that the file is created exclusively, failing if it already exists.
  - Symbolic Constant: `O_EXCL`
  - Numeric Value: `0200` (octal)

## Examples

Here are a few examples that illustrate the usage of opening modes and flags:

1. Opening an existing file in read-only mode:
   ```c
   int fd = open("file.txt", O_RDONLY);
   ```

2. Creating a new file with read and write permissions:
   `````c
   int fd = open("newfile.txt", O_CREAT | O_RDWR, 0644);
   ```

3. Opening a file in append mode:
   ````c
   int fd = open("logfile.txt", O_WRONLY | O_APPEND);
   ```

Remember to include the `<fcntl.h>` header file to use the symbolic constants for modes and flags.

```

This note provides an explanation of file opening modes and flags, including their symbolic constants, numeric values, and examples demonstrating their usage.

# Standard Input, Output, and Error File Descriptors

In Unix-like operating systems, standard input, output, and error are represented by file descriptors that are automatically opened for a process. These file descriptors provide a way to interact with the terminal or other input/output sources.

## Standard Input

Standard input, often referred to as `stdin`, is the default input stream for a process. It is typically connected to the keyboard or another input source.

- File Descriptor: 0
- Usage: Reading input data from the user or another program.

## Standard Output

Standard output, often referred to as `stdout`, is the default output stream for a process. It is typically connected to the terminal or another output destination.

- File Descriptor: 1
- Usage: Writing normal output or results of a program.

## Standard Error

Standard error, often referred to as `stderr`, is the default output stream for error messages and diagnostic information. It is also typically connected to the terminal or an error log file.

- File Descriptor: 2
- Usage: Writing error messages, warnings, or diagnostic information.

## Redirecting File Descriptors

File descriptors can be redirected to different sources or destinations using shell redirection operators. For example:

- To redirect `stdout` to a file:
  ```shell
  command > output.txt
  ```

- To redirect `stderr` to a file:
  `````shell
  command 2> error.txt
  ```

- To redirect both `stdout` and `stderr` to a file:
  ````shell
  command > output.txt 2>&1
  ```

## Examples

Here are a few examples that demonstrate the usage of standard input, output, and error file descriptors:

- Reading input from `stdin`:
  ````c
  char input[100];
  fgets(input, sizeof(input), stdin);
  ```

- Writing output to `stdout`:
  ````c
  printf("Hello, world!\n");
  ```

- Writing error messages to `stderr`:
  ````c
  fprintf(stderr, "Error: File not found.\n");
  ```

Remember that standard input, output, and error file descriptors are available by default in most programming languages and can be used for input/output operations.

```

This note provides an explanation of standard input, output, and error file descriptors, including their file descriptor numbers, usage, and examples demonstrating their usage.


# Write System Call

The `write` system call is used to write data from a buffer to a file or a file descriptor in Unix-like operating systems. It is a low-level I/O function that allows you to output data to an open file or a device.

## Function Signature

The function signature of the `write` system call is as follows:

```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```

- `fd`: The file descriptor representing the file or device to write to.
- `buf`: A pointer to the buffer containing the data to be written.
- `count`: The number of bytes to write from the buffer.

## Return Value

The `write` system call returns the number of bytes successfully written to the file or device. On error, it returns -1, indicating a failure.

## Example Usage

Here's an example that demonstrates the usage of the `write` system call:

```c
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char *message = "Hello, world!\n";
    ssize_t bytes_written = write(fd, message, strlen(message));
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
```

In this example, the `open` system call is used to open a file named "output.txt" in write-only mode. If the file is successfully opened, the `write` system call is used to write the message "Hello, world!\n" to the file. Finally, the `close` system call is used to close the file descriptor.

Remember to include the appropriate header files (`<unistd.h>` and `<fcntl.h>`) and handle error conditions when using the `write` system call.

```
# `unistd` Symbolic Constants

The `<unistd.h>` header file in Unix-like operating systems defines various symbolic constants related to system calls, file operations, and process management. These constants provide a convenient way to work with system-specific values and behavior.

## File Descriptors

The following symbolic constants are commonly used to represent standard file descriptors:

- `STDIN_FILENO`: The file descriptor for standard input (stdin). It is defined as `0`.
- `STDOUT_FILENO`: The file descriptor for standard output (stdout). It is defined as `1`.
- `STDERR_FILENO`: The file descriptor for standard error (stderr). It is defined as `2`.

## System Call Error Codes

The following symbolic constants are used to represent error codes returned by system calls:

- `EACCES`: Permission denied.
- `EINTR`: Interrupted system call.
- `EINVAL`: Invalid argument.
- `EIO`: Input/output error.
- `ENOMEM`: Out of memory.
- `ENOSPC`: No space left on device.

Note that these constants represent only a subset of the possible error codes. Consult the documentation or the `<errno.h>` header file for a comprehensive list of error codes.

## Process IDs

The following symbolic constants are used to represent process IDs:

- `PID_MAX`: The maximum value for a process ID.

## Process Execution

The following symbolic constants are used for process execution:

- `_POSIX_VERSION`: The version of the POSIX standard with which the system is compliant.

## Example Usage

Here's an example that demonstrates the usage of some `unistd` symbolic constants:

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Standard input file descriptor: %d\n", STDIN_FILENO);
    printf("Standard output file descriptor: %d\n", STDOUT_FILENO);
    printf("Standard error file descriptor: %d\n", STDERR_FILENO);

    printf("Permission denied error code: %d\n", EACCES);
    printf("Invalid argument error code: %d\n", EINVAL);

    printf("Maximum process ID: %d\n", PID_MAX);

    printf("POSIX version: %ld\n", _POSIX_VERSION);

    return 0;
}
```

In this example, various `unistd` symbolic constants are printed to the console.

Remember to include the `<unistd.h>` header file to access the `unistd` symbolic constants, and the appropriate headers for other functions used in your program.

```

