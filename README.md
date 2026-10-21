
# Command-Line Interpreter

A command-line interpreter written in **C++** as an individual project for the Object-Oriented Programming course at the University of Belgrade, School of Electrical Engineering.

The application parses and executes text-based commands, including file operations, input/output redirection, command pipelines, and batch execution.

## Features

- Interactive command prompt with a configurable prompt symbol
- Parsing of commands, arguments, and options
- Input redirection (`<`) and output redirection (`>` and `>>`)
- Command pipelines (`|`)
- Batch execution of commands from a text file
- Console and file input/output
- Error handling through custom exception classes

## Supported Commands

| Command | Purpose |
| --- | --- |
| `echo` | Display text or file contents |
| `prompt` | Change the prompt symbol |
| `time` | Display the current time |
| `date` | Display the current date |
| `touch` | Create a file |
| `rm` | Remove a file |
| `truncate` | Clear a file's contents |
| `wc` | Count words or characters |
| `tr` | Transform text |
| `head` | Display the first lines of input |
| `batch` | Execute commands from a file |

## Architecture & OOP Design

The implementation separates parsing, command execution, and input/output handling:

- **`Program`** manages the interpreter's execution flow and creates the appropriate command objects.
- **`Parser`** processes command syntax, arguments, redirections, and pipelines.
- **`Commands`** is an abstract base class with a pure virtual `execute()` method, implemented by individual command classes.
- **`Reader`, `ConsoleReader`, and `FileReader`** provide a shared interface for console and file input.
- **`Print`** handles output, while **`Errors`** defines custom exception types.

The design uses **inheritance, runtime polymorphism, and abstraction** to organize command implementations. It also uses **`std::unique_ptr`** for ownership management in parsing and the **Singleton pattern** in components such as `Program`.

## Example Usage

```text
echo "Hello World!"
time
date
touch notes.txt
echo "Hello World!" > output.txt
wc -w < input.txt
```

File-based commands require valid file paths and, where applicable, existing input files.

## Running the Project

Open `CLI projekat.sln` in **Visual Studio 2022**, build the solution, and run the console application.

## Author

**Stefan Bozic** — [GitHub](https://github.com/stefanbozic78)
