# CPP Module 02

## Description

This project is the third C++ module of the 42 Common Core.

Its goal is to introduce fixed-point numbers and several important C++ concepts through the implementation of a `Fixed` class using:

* Orthodox Canonical Form
* fixed-point number representation
* constructors and destructors
* copy construction
* copy assignment
* operator overloading
* comparison operators
* arithmetic operators
* increment and decrement operators
* static member functions

The project is compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

---

## Exercises

### ex00 - My First Class in Orthodox Canonical Form

This exercise introduces the Orthodox Canonical Form.

It implements a `Fixed` class with:

* a private integer storing the raw fixed-point value
* a static constant integer storing the number of fractional bits
* a default constructor
* a copy constructor
* a copy assignment operator
* a destructor
* `getRawBits()`
* `setRawBits()`

The goal is to understand how objects are created, copied, assigned and destroyed in C++.

#### Usage

```bash
cd ex00
make
./fixed
```

---

### ex01 - Towards a more useful fixed-point number class

This exercise extends the `Fixed` class so it can represent useful numeric values.

It adds:

* a constructor from `int`
* a constructor from `float`
* `toFloat()`
* `toInt()`
* an overload of the insertion operator `<<`

The class stores numbers internally as fixed-point values using 8 fractional bits.

For example:

```text
10      -> stored internally as 10 << 8
42.42f  -> stored internally as roundf(42.42f * 256)
```

#### Usage

```bash
cd ex01
make
./fixed_point
```

---

### ex02 - Now we’re talking

This exercise adds operator overloading to the `Fixed` class.

It implements:

* comparison operators:

  * `>`
  * `<`
  * `>=`
  * `<=`
  * `==`
  * `!=`

* arithmetic operators:

  * `+`
  * `-`
  * `*`
  * `/`

* increment and decrement operators:

  * pre-increment
  * post-increment
  * pre-decrement
  * post-decrement

* static member functions:

  * `min`
  * `max`

The smallest representable increment is one raw unit:

```text
1 / 256 = 0.00390625
```

This is why incrementing a `Fixed` value increases its raw value by 1.

#### Usage

```bash
cd ex02
make
./fixed_operators
```

---

## Build rules

Each exercise contains its own `Makefile`.

Available rules:

```bash
make
make clean
make fclean
make re
```

---

## Notes

This module is written using the C++98 standard.

The code avoids:

* `printf`
* `malloc`
* `free`
* `using namespace std`
* STL containers and algorithms

From this module onward, classes are implemented using the Orthodox Canonical Form unless stated otherwise.

The goal of this module is to understand how fixed-point numbers can be represented manually in C++, while also learning how operator overloading allows custom classes to behave more like built-in numeric types.
