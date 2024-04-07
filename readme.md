# CVB

A command line utility used for extracting and printing lines from a file.

## How To Use

```shell
$ ./CVB.out [FLAGS]... [Filename]
```

Note: If no filename or a ``-`` is entered the input will be read from stdin.

### Flags

- ```--help```: Displays help menu
- ```-s n```: Prints input from specified line (default: first line)
- ```-e n```: Prints input until specified line (default: last line)
- ```-n [FORMAT]```: Prints with leading zeros
  - ```n```: Width of line number field
  - ```R```: right bound (default)
  - ```O```: right bound with leading zeros
  - ```L```: left bound
  - ```N```: line number begins with zero
- ```-v```: Displays status and file information while processing
- ```-q```: Displays status and file information without displaying the input
- ```--version```: Displays the version number

## Installation

To clone and run this application, you'll need [Git](https://git-scm.com/download/win) and [MinGW](https://www.mingw-w64.org/downloads/) installed on your computer.\
From your command line:

```shell
# Clone this repository
$ git clone git@github.com:Jakob-Mierl/CVB.git
# Go into repository
$ cd CVB
# Compile source code
$ gcc main.c -o CVB.out
# Run the app
$ ./CVB.out
```
