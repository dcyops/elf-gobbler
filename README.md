# Elf-Gobbler (non-functional)

## Overview
**Elf-Gobbler** is a proof of concept (POC) for a file infector. This project demonstrates how a file infector can operate by modifying executable files in the ELF (Executable and Linkable Format) commonly used in Unix-like operating systems.

## Features
- Scans for ELF files in a specified directory.
- Injects a payload into the identified ELF files.
- Ensures the infected files remain functional while carrying the payload.

## Requirements
- Unix-like operating system (Linux, FreeBSD, etc.)
- GCC (GNU Compiler Collection)

## Installation
Clone the repository to your local machine:
```bash
git clone https://github.com/yourusername/elf-gobbler.git
cd elf-gobbler
```

## Compilation

Compile the project using GCC:  
`gcc -o elf_gobbler elf_gobbler.c`

## Usage

1. Navigate to the project directory:  
`cd elf-gobbler`

2. Run the compiled program to start the infection process:
`./elf_gobbler /path/to/target/directory

## Disclaimer

This project is for educational purposes only. Use it responsibly and do not deploy it on systems without explicit permission. The authors are not responsible for any misuse of this software.
Contributing

Feel free to submit issues or pull requests if you have suggestions for improvements or find bugs.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
