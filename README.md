*This project has been created as part of the 42 curriculum by
pecavalc.*

# Philosophers --- 42 Core Curriculum

## Description

This repository contains my implementation of the **Dining
Philosophers** problem, a classical synchronization problem used to
explore concepts of **concurrency**, **thread coordination**, and
**shared resource management**.

The goal of the project is to simulate philosophers sitting around a
table who alternate between **thinking**, **eating**, and **sleeping**
while sharing a limited number of forks. The challenge is to design the
program so that:

-   No **deadlocks** occur
-   Philosophers may or not **starve** depending on input parameters
-   Shared resources are accessed **safely**

The project is part of the **42 School Core Curriculum** and focuses on
building a deep understanding of **POSIX threads**, **mutexes**, and
**synchronization mechanisms** in C.

Key technical topics explored in this implementation:

-   Multithreading using `pthread`
-   Mutex-based synchronization
-   Deadlock prevention strategies
-   Precise timing control for thread routines
-   Monitoring threads and simulation state
-   Safe access to shared data structures

------------------------------------------------------------------------

## Instructions

### Compilation

Clone the repository and compile the project using `make`:

``` bash
git clone <repository-url> philosophers
cd philosophers
make
```

This will produce the executable:

    philo

### Usage

Run the program with the following arguments:

``` bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

``` bash
./philo 5 800 200 200
```

Arguments:

-   `number_of_philosophers` --- number of philosophers (and forks)
-   `time_to_die` --- time (ms) a philosopher can live without eating
-   `time_to_eat` --- time (ms) spent eating
-   `time_to_sleep` --- time (ms) spent sleeping
-   `number_of_times_each_philosopher_must_eat` --- optional limit for
    meals

The simulation ends when:

-   A philosopher dies
-   All philosophers have eaten the required number of meals (if
    specified)

------------------------------------------------------------------------

## Resources

### Articles & Documentation

-   Oceano's Blog --- *Philosophers 42 Guide*\
    https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2

-   Wikipedia --- *Concurrency (Computer Science)*\
    https://en.wikipedia.org/wiki/Concurrency\_(computer_science)

### Books

-   **Understanding and Using C Pointers --- Richard Reese**\
    A practical guide to pointers, dynamic memory management, and safe
    handling of complex data structures in C.

-   **Expert C Programming: Deep C Secrets --- Peter van der Linden**\
    A classic book exploring advanced C programming techniques and
    insights into the language and its behavior.

-   **C: How to Program --- Deitel & Deitel**\
    A comprehensive reference covering the fundamentals of C programming
    and software development practices.

### Use of AI

AI tools (primarily ChatGPT) were used as **a learning and support tool
during development**. The assistance included:

-   Explaining **concurrency concepts** and synchronization patterns
-   Discussing **design strategies** for the dining philosophers problem
-   Reviewing and improving **code readability and structure**
-   Helping write **documentation and README content**
-   Assisting with **debugging discussions and conceptual explanations**

All implementation decisions, architecture, and final code were written
and validated manually as part of the learning process.