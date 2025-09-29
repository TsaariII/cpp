#!/bin/bash

echo "TEST: sorted"
./PmergeMe 1 2 3 4 5

echo "TEST: reverse"
./PmergeMe 5 4 3 2 1

echo "TEST: invalid input (text)"
./PmergeMe 5 abc 3

echo "TEST: duplicate values"
./PmergeMe 1 2 2 3 4

echo "TEST: 3000 elements"
# ./PmergeMe $(jot 100000 1 | sort -R | head -n 3000 | tr '\n' ' ')
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')