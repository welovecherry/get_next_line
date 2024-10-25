
```markdown
# Get Next Line

## Project Overview
**Get Next Line** is a project designed to implement a function that reads a line from a file descriptor. This project provides a function, `get_next_line()`, that reads from a file (or standard input) one line at a time, regardless of the length of the line. The goal is to manage file I/O efficiently and handle edge cases such as extremely long lines, multiple file descriptors, and incomplete reads.

## Key Concepts Learned
- **File I/O**: Working with file descriptors to read input from files or standard input.
- **Memory Management**: Efficiently managing memory with `malloc()`, `free()`, and dynamic memory allocation to handle variable-length input.
- **Buffers**: Using buffers to manage input and handle partial reads from a file descriptor.
- **Static Variables**: Using static variables to persist data across function calls, enabling continuous reading from the same file descriptor.
- **Edge Case Handling**: Managing edge cases like empty lines, end of file (EOF), and memory leaks.

## Function Prototype
The prototype for the `get_next_line()` function is as follows:

```c
int get_next_line(int fd, char **line);
```

- **fd**: The file descriptor to read from.
- **line**: A pointer to a string where the function will store the next line read.
- **return value**:
  - `1`: A line has been successfully read.
  - `0`: The end of the file has been reached.
  - `-1`: An error occurred.

## How to Build
### Prerequisites
You need to have **gcc** (GNU Compiler Collection) installed to compile the project.

### Build the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/get_next_line.git
   cd get_next_line
   ```

2. Compile the project using the provided `Makefile`:
   ```bash
   make
   ```

This will generate object files that can be linked to other projects where you need the `get_next_line` functionality.

## How to Use
To use **get_next_line** in your own project, include the `get_next_line.h` header file and link the object files during compilation.

1. Include the `get_next_line.h` header in your C files:
   ```c
   #include "get_next_line.h"
   ```

2. Compile your project and link the **get_next_line** function:
   ```bash
   gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o my_program
   ```

### Example Usage
Here is an example of how to use `get_next_line()` in a simple program:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    free(line); // Free the last line after EOF
    close(fd);
    return 0;
}
```

### Sample Output:
For an input file `example.txt` containing:
```
Hello, world!
42 Seoul
Get Next Line
```

The output will be:
```
Hello, world!
42 Seoul
Get Next Line
```

## Key Files
- **get_next_line.c**: Contains the main logic for reading a line from the file descriptor.
- **get_next_line_utils.c**: Contains utility functions that assist with memory management and string manipulation.
- **get_next_line.h**: Header file that defines the function prototypes and includes necessary libraries.
- **Makefile**: Automates the compilation process.

## Important Considerations
- **Buffer Size**: The `BUFFER_SIZE` macro defines the size of the buffer used to read from the file descriptor. Ensure that it is properly set for optimal performance.
- **Memory Leaks**: Always free the memory allocated for each line to prevent memory leaks.
- **Multiple File Descriptors**: The function should handle multiple file descriptors at the same time, such as reading from different files simultaneously.
- **End of File**: Properly detect the end of a file and return `0` when EOF is reached.

## Example with Multiple File Descriptors
You can test `get_next_line()` with multiple files by opening multiple file descriptors and calling the function on each one:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1;
char *line2;

get_next_line(fd1, &line1);
get_next_line(fd2, &line2);

printf("File1: %s\n", line1);
printf("File2: %s\n", line2);

free(line1);
free(line2);

close(fd1);
close(fd2);
```

## Testing
Test the function with various edge cases to ensure its robustness:
- **Empty files**: Ensure the function returns `0` for an empty file.
- **Long lines**: Test with very long lines that exceed the buffer size.
- **Multiple file descriptors**: Test reading from multiple files simultaneously.
- **Memory leaks**: Use a memory checker (e.g., `valgrind`) to ensure no memory is leaked.

## Conclusion
The **Get Next Line** project helped me gain a better understanding of how file input works in C, particularly with regard to buffers, memory management, and handling multiple file descriptors. The project is a valuable exercise in efficiently handling file I/O and managing dynamic memory.

---

This project is part of the **42 Seoul** curriculum and focuses on implementing a function that reads one line at a time from a file descriptor, managing memory efficiently, and handling edge cases.
```
