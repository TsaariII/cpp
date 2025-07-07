#!/bin/bash

# Path to your executable
EXEC=./converter

# List of test cases
tests=(
    'a'           # valid char
    'z'           # valid char
    '0'           # valid int
    '-42'         # negative int
    '42.0f'       # valid float
    '42.0'        # valid double
    '+inff'       # float pseudo-literal
    '-inff'       # float pseudo-literal
    'nanf'        # float pseudo-literal
    '+inf'        # double pseudo-literal
    '-inf'        # double pseudo-literal
    'nan'         # double pseudo-literal
    '2147483647'  # INT_MAX
    '2147483648'  # INT_MAX + 1 (overflow)
    '-2147483648' # INT_MIN
    '-2147483649' # INT_MIN - 1 (underflow)
    '123abc'      # invalid
    '6t'          # invalid
    ''            # empty string
    ' '           # space only
    '9999999999999999999999999999999999' # massive overflow
)

# Run tests
for input in "${tests[@]}"; do
    echo "===== Test: '$input' ====="
    $EXEC "$input"
    echo
done