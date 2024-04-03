# CVB
A command line utility used for extracting and printing lines from a file.
## How To Use
```shell
$ ./CVB.out [FLAGS]... [Filename]
```
Note: If no filename or a ``-`` is entered the input will be read from stdin.
### Flags
- With ```-h (or) --help```: Displays help menu
- With ```-s n```: Prints input from specified line (default: first line)
- With ```-e n```: Prints input until specified line (default: last line)
- With ```-n [FORMAT]```: Prints with leading zeros
    - With ```-n n```: Width of line number field
    - With ```-n R```: right bound (default)
    - With ```-n O```: right bound with leading zeros
    - With ```-n L```: left bound
    - With ```-n N```: line number begins with zero
- With ```-i```: Displays status and file information while processing
- With ```-q```: Displays status and file information without displaying the input
- With ```-v (or) --version```: Displays the version number
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