# 🧠 C++ Modules – 1337 / 42 Network Journey

Welcome to my C++ modules journey, completed as part of the 1337/42 Curriculum.
This repository documents my understanding and progress through **C++ Modules 00 → 09**, focusing on object-oriented programming, templates, STL, and modern C++ techniques.

---

## 📘 What is Object-Oriented Programming (OOP)?

**Object-Oriented Programming (OOP)** is a paradigm where software is structured around *objects* rather than actions. Objects are instances of *classes*, which are blueprints for organizing both data and behavior.

### 🔑 Core OOP Principles:

| Concept           | Description                                                                        |
| ----------------- | ---------------------------------------------------------------------------------- |
| **Class**         | A blueprint that defines attributes and methods for objects.                       |
| **Object**        | An instance of a class — holds real data and behavior.                             |
| **Encapsulation** | Bundling of data and the methods that operate on that data.                        |
| **Inheritance**   | A class can inherit members and methods from another class.                        |
| **Polymorphism**  | Different objects can be treated through the same interface, behaving differently. |
| **Abstraction**   | Hiding complex details and showing only the essentials.                            |

---

## 📦 Module Breakdown & Key Concepts

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-12-55" src="https://github.com/user-attachments/assets/c2456f8b-1a3f-41f5-956f-30433eb14129" />

### 🥉 Module 00 – Basics of C++

#### 🔎 Topics Covered:

* **Namespaces**: Used to prevent name conflicts in large projects. (e.g., `std`)
* **Classes & Objects**: Core building blocks of OOP. A class is a blueprint; an object is a usable instance.
* **Member Functions**: Functions that belong to a class and operate on its data.
* **stdio Streams**: `cout`, `cin`, and `cerr` are used for input/output in C++.
* **Initialization Lists**: A concise way to initialize members in a constructor.
* **Static**: A static member is shared across all instances of a class.
* **Const**: Makes variables read-only or ensures a method doesn’t modify the object.

#### ✅ Skills Acquired:

* Building basic classes and objects.
* Applying access specifiers (`private`, `public`, `protected`).
* Writing constructors, destructors, and initialization lists.
* Differentiating between static vs instance members.
* Using const-correctness in class design.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-13-14" src="https://github.com/user-attachments/assets/bebfb4d4-b867-41ad-a9d1-0225e9cc6956" />

### 🥉 Module 01 – Memory & Pointers

#### 🔎 Topics Covered:

* **Memory Allocation**: Using `new` and `delete` to manage dynamic memory.
* **Pointers to Members**: Special pointer syntax to refer to class members.
* **References**: An alias to another variable (safer alternative to pointers).
* **Switch Statement**: A control flow construct to handle multiple conditions efficiently.

#### ✅ Skills Acquired:

* Allocating and freeing heap memory.
* Understanding the difference between stack and heap memory.
* Using pointers and references effectively.
* Applying switch-case logic to manage complex decision trees.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-13-29" src="https://github.com/user-attachments/assets/2284d46d-1f7b-4511-97d8-b92a93ee9b09" />

### 🥉 Module 02 – Operator Overloading & Canonical Form

#### 🔎 Topics Covered:

* **Ad-hoc Polymorphism**: Achieved using function/operator overloading.
* **Operator Overloading**: Custom behavior for operators like `+`, `<<`, `==`, etc.
* **Orthodox Canonical Form**:

  * Default constructor
  * Copy constructor
  * Copy assignment operator
  * Destructor

#### ✅ Skills Acquired:

* Implementing overloaded operators for custom types.
* Ensuring proper memory handling via Rule of Three.
* Building copy-safe and assignable classes.
* Understanding deep vs shallow copies.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-13-49" src="https://github.com/user-attachments/assets/30514e20-cb82-4f37-a2ce-b45d12321f40" />

### 🥉 Module 03 – Inheritance

#### 🔎 Topics Covered:

* **Inheritance**: Deriving a new class from an existing one.
* **Access Specifiers** in inheritance (`public`, `protected`, `private`).
* **Constructor chaining**: Calling base class constructors in derived classes.

#### ✅ Skills Acquired:

* Building class hierarchies.
* Reusing and extending functionality using inheritance.
* Understanding object slicing and how to avoid it.
* Designing more modular and testable code.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-14-01" src="https://github.com/user-attachments/assets/35236beb-7a2e-4caa-9d26-4e4c75617927" />

### 🥉 Module 04 – Abstract Classes & Interfaces

#### 🔎 Topics Covered:

* **Subtype Polymorphism**: Using base class pointers/references to handle derived types.
* **Virtual Functions**: Enables runtime polymorphism.
* **Abstract Classes**: Classes with at least one pure virtual function (`= 0`).
* **Interfaces**: Pure abstract classes that define a contract.

#### ✅ Skills Acquired:

* Implementing dynamic polymorphism.
* Designing interfaces and abstract hierarchies.
* Writing polymorphic code that is flexible and extendable.
* Understanding the role of virtual destructors.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-14-12" src="https://github.com/user-attachments/assets/5ccce2a5-2a25-4aeb-b260-5e1f9ddb15dd" />

### 🥉 Module 05 – Exceptions & Error Handling

#### 🔎 Topics Covered:

* **try / catch / throw**: Basic exception handling constructs.
* **Exception Safety**: Writing code that stays safe under failure.
* **RAII**: Pattern to manage resources automatically via object lifetime.

#### ✅ Skills Acquired:

* Catching and throwing exceptions cleanly.
* Designing exception-safe constructors and destructors.
* Managing resources using RAII to avoid leaks.
* Differentiating between recoverable and non-recoverable errors.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-14-33" src="https://github.com/user-attachments/assets/f6338f98-8764-42ef-bc0c-302d49ab3ecb" />

### 🥉 Module 06 – Type Casting in C++

#### 🔎 Topics Covered:

* **static\_cast**: Compile-time type conversion.
* **dynamic\_cast**: Runtime type-safe downcasting (needs polymorphism).
* **const\_cast**: Removing `const`/`volatile` qualifiers.
* **reinterpret\_cast**: Bit-level conversion; very low-level and unsafe.

#### ✅ Skills Acquired:

* Choosing the right cast for the right context.
* Understanding cast limitations and dangers.
* Writing cleaner and safer conversion code.
* Debugging with proper use of dynamic\_cast.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-14-52" src="https://github.com/user-attachments/assets/482be8b7-0a70-4c0c-966e-385d3aee5654" />

### 🥉 Module 07 – Templates

#### 🔎 Topics Covered:

* **Function Templates**: Generic functions that work with any type.
* **Class Templates**: Classes that take types as parameters.
* **Template Instantiation**: Compiler-generated code for used types.

#### ✅ Skills Acquired:

* Writing and using generic code.
* Creating reusable containers and algorithms.
* Understanding the cost of template bloat.
* Exploring template specialization and SFINAE.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-15-02" src="https://github.com/user-attachments/assets/c681c7c4-c190-40a4-9a69-70a008618472" />

### 🥉 Module 08 – Containers, Iterators, and Algorithms

#### 🔎 Topics Covered:

* **Templated Containers**: `map`, `stack`, `vector`, `deque`,  `list`, etc.
* **Iterators**: Objects for traversing containers.
* **STL Algorithms**: `sort`, `find`, `lower_bound` `count`, `for_each`, etc.

#### ✅ Skills Acquired:

* Navigating and manipulating STL containers.
* Writing efficient loops with iterators.
* Using algorithms to write expressive and high-level logic.
* Integrating lambda functions with STL.

---

<img width="743" height="168" alt="Screenshot from 2025-07-31 10-15-18" src="https://github.com/user-attachments/assets/2e410721-ce20-419d-920d-321955562aa8" />

### 🥉 Module 09 – STL (Standard Template Library)

#### 🔎 Topics Covered:

* **Containers**: `map`, `stack`, `vector`, `deque`,  `list`, etc.
* **Iterators**: `begin()`, `end()`, `rbegin()`, `rend()`
* **Algorithms**: `sort`, `find`, `lower_bound` `count`, `for_each`, etc.
* **Utilities**: `pair`, `function`, `bind`, `tuple`

#### ✅ Skills Acquired:

* Mastering STL components.
* Writing idiomatic, high-level C++.
* Leveraging generic programming and composability.
* Building expressive, readable, and maintainable code.

* 👉 To explore the **Merge-Insertion Sort (Ford-Johnson Algorithm)** built as part of this module, check out the implementation here: [Ford-Johnson Algorithm Repo](https://github.com/samir-ouaammou/Ford-Johnson-Algorithm)

---

## 🏁 Final Thoughts

Completing these modules gave me a rock-solid foundation in modern C++.
From mastering **OOP**, to leveraging **templates** and **STL**, every concept brought me one step closer to becoming a proficient, confident developer.
Check the `/exXX/` folders for my implementations.

---

> 📨 Feel free to reach out, contribute, or ask me anything!   
 
🧑‍💻 **Author**: [Samir Ouaammou](https://github.com/Samir-Ouaammou)  
🎓 **1337 School / 42 Network**   
🚀 Passionate about C++, Linux, and clean code!  
