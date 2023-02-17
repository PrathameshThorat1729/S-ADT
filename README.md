# S-ADT

S-ADT is an '**Simple Abstract Data Types**' in C++, made only as an Practice Point of View. This project is an great example of how an project is built from scratch and all setup is done. Anouther resone to create this is Learn, Practise and Save Data Structures in C++

# Folder Structure

- **include/** : Contains Header file with name _[Datatype].hpp_
- **src/** : Contains Source file with name _[Datatype].cpp_
- **test/** : Contains Test file for Each Data Structure respectively with name _[Datatype].test.cpp_
- **lib/** (after building) : Contains for Static libraries for each Data Structure respectively with name _lib[Datatype].a_
- **obj/** (after building) : Contains object file for each Data Structure respectively with name _[Datatype].o_

# Building Commands

## Debugging Build :

To create a Build for Testing perpose

```bash
$ make
```

## Release Build :

To create a Release Build

```bash
$ make release
```

# Testing :

To test a Single Data Structure at a time

```bash
$ make test/<Datatype>
```

# Cleaning :

To clean the workspace

```bash
$ make clean
```

# Note

- Each Datatype and It's respective files starts with Capital Letter
- After test build, binaries are stored in test/bin
- This project is created and tested in only Windows 10, WSL & Android (Termux)

# Contact

**Email** : thoratprathamesh1729@gmail.com </br>
**Github** : https://github.com/PrathameshThorat1729/ </br>
**Sololearn** : https://www.sololearn.com/profile/27868041/
