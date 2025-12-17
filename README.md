# 🚀 CPP Module 02

> This module introduces "Ad-hoc" polymorphism, operator overloading, and the Orthodox Canonical Class Form, focusing on creating robust and reusable classes.

---

## 🎯 Project Goals

The objective of this module is to understand and implement **operator overloading**, which allows C++ operators to work with user-defined types. It also introduces the **Fixed-point number** representation as a practical example of custom data types, requiring a strict adherence to the **Orthodox Canonical Form** to ensure proper object copying and assignment.

## 🛠️ Technical Details

* **Orthodox Canonical Form:** Implementing the four essential member functions: Default Constructor, Copy Constructor, Copy Assignment Operator, and Destructor.
* **Ad-hoc Polymorphism:** Using function overloading to define multiple functions with the same name but different parameters.
* **Operator Overloading:** Customizing the behavior of operators such as `=`, `<<`, `>`, `<`, `==`, `+`, `-`, `*`, `/`, and increment/decrement operators.
* **Fixed-point Representation:** Developing a class that handles non-integer numbers using fixed-point arithmetic, providing a balance between performance and precision compared to floating-point.
* **Floating-point Conversion:** Learning how to convert between integers, floats, and fixed-point values using bitwise operations.

## ⚙️ How to Compile & Run

This project contains a separate `Makefile` inside each exercise directory (e.g., `ex00/`, `ex01/`).

1.  Clone the repository:
    ```bash
    git clone [https://github.com/carlopezc/CPP02.git](https://github.com/carlopezc/CPP02.git)
    cd CPP02
    ```
2.  To compile and run a specific exercise, navigate into its folder:

    **Example (ex00):**
    ```bash
    cd ex00
    make
    ./fixed
    ```
