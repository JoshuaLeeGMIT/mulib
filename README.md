# `mulib`

A simple C library for convenience and basic data structures

### Design

`TODO`

### Features

`mulib`'s goal is to to offer various basic data structures that make working
with C easier. These could include:

* Binary search trees
* Hash tables
* Self-sizing strings

### Installation

`TODO`

### Out-of-memory strategy

What to do if `malloc()` returns `NULL`? `mulib` chooses the segfault strategy.
It doesn't check the return value of internal `malloc()` calls. As a result,
your program will crash if `malloc()` returns `NULL`.
