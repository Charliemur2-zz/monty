<img src="https://bdn-data.s3.amazonaws.com/uploads/2020/03/33554421_H26278923-600x400.jpeg">

# MONTY

The **monty** programm takes a file with Monty Bytes Code and interprets it for been executed bt the system.
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
The monty programm takes the file and use the lines within to execute them.
***FLOW CHART***

[![INSERT YOUR GRAPHIC HERE](http://i.imgur.com/dt8AUb6.png)]()

---

## Table of Contents

- [Installation](#installation)
- [Features](#features)
- [Contributing](#contributing)
- [Team](#team)
- [Support](#support)
- [License](#license)


---

## Example

```
vagrant:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vagrant:~/monty$ ./monty bytecodes/00.m
3
2
1
vagrant:~/monty$
```
```
julien@ubuntu:~/monty$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
vagrant:~/monty$ ./monty bytecodes/06.m
1
2
3
vagrant:~/monty$
```
---

## Installation

Copy the **monty** executable file, and execute.

---

## Features
## Usage
```
vagrant:~/monty$ ./monty [FILE_name]
```

## Documentation

<a href="https://en.wikipedia.org/wiki/Bytecode">`ByteCode`</a><br>
<a href="https://mariadb.org/tag/monty-program-ab/">`Monty Programm`</a>

---

## Contributing

> To get started...

### Step 1

- **Option 1**
    - 🍴 Fork this repo!

- **Option 2**
    - 👯 Clone this repo to your local machine using

### Step 2

- **HACK AWAY!** 🔨🔨🔨

### Step 3

- 🔃 Create a new pull request using.
---

## Team

https://github.com/Charliemur2
---

## Support

Feel free to contact me!

- GitHub at <a href="https://github.com/Charliemur2">`Charliemur2`</a>
- Twitter at <a href="https://twitter.com/charliesoka">`@charliesoka`</a>
- Insert more social links here.

---

## License

Free Source Code
