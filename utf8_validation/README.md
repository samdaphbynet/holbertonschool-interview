# UTF-8 Validation

## Description
This project contains a Python script that validates whether a given data set represents a valid UTF-8 encoding.

## Resources
Read or watch:
- [UTF-8](https://en.wikipedia.org/wiki/UTF-8)
- [Characters, Symbols, and the Unicode Miracle](https://www.youtube.com/watch?v=MijmeoH9LT4)

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All files will be interpreted/compiled on Ubuntu 14.04 LTS using Python3 (version 3.4.3)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Code should use the PEP 8 style (version 1.7.x)
- All files must be executable

## Tasks
### 0. UTF-8 Validation
Write a method that determines if a given data set represents a valid UTF-8 encoding.

Prototype: `def validUTF8(data)`
Return: `True` if data is a valid UTF-8 encoding, else return `False`
- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

## Files
- `0-validate_utf8.py`: Python script containing the implementation of UTF-8 validation method.
- `0-main.py`: Main file for testing the UTF-8 validation method.

## Usage
```
./0-main.py
```