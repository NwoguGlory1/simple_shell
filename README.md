# Simple Shell Project - Nwogu Glory and Miriam Akanwa

### Description

This Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell. Additional functions are also included. This program was written entirely in C as a milestone project for ALX SWE C14.

### Installation

Clone this repository into your working directory. For best results, files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

### Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

#### Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

```~$
echo "ls" | ./shell
```

In non-interactive mode, the program will exit after finishing your desired command(s).

#### Included Built-Ins

Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var][value] | Set an environment variable and value. If the variable exists, the value will be updated. |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the directory.                                                                     |
| help [built-in]     | Read documentation for a built-in.                                                        |

The following built-in commands may be supported in future versions:

| Command | Definition                     |
| ------- | ------------------------------ |
| alias   | Set an Alias.                  |
| history | View the history of the shell. |

#### Outside Programs

Our shell can run outside programs by typing their absolute paths (/bin/ls) or the executable name (ls), IF their directory is included in the PATH.

### Examples

```~$
$ ls -l
total 8
drwxrwxr-x 1 vagrant vagrant Apr 2 13:23 directory_1
drwxrwxr-x 2 vagrant vagrant Apr 2 20:30 directory_2
```

```~$
$ /bin/pwd
/home/vagrant/shell
```

```~$
$ hello world
./hsh: 1: hello: not found
```
