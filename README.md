# push_swap

### Mark: 84/100

push_swap, the only mandatory project of ring 2, involved sorting data on a stack, using a limited set of instructions, in the smallest amount of moves possible. This project acted as an introduction to various sorting algorithms, and the concept of time and space complexity, with the idea to have the most optimised data sorting algorithm based on the restrictions.

I opted to go down the path of bit comparisons, which is also known as a radix sort. I chose this algorithm as I enjoyed the logic behind the solution, and the mathematical approach. Having used bitwise operators in minitalk, and then worked with complex numbers in fract-ol, I liked the idea of going down the more mathematical route and working with the numbers in bit form.

### Running the program

To compile and run the program, run the following commands:

```bash

# Make using the Makefile

make	# Creates the push-swap executable

# Run the executable, using the following arguments

./push-swap <int_list>

# e.g. ./push-swap 1 6 2 4 3
```

### Checking results

> [!TIP]
> Use the included checker programs (provided by 42) to make sure the intergers are correctly sorted

To check the output is valid:

`./push_swap <int_list> | ./checker_programs/<checker_OS> <int_list>`{:.bash}
