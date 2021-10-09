# --Push_swap--

Push_swap is a School 42 project. The purpose of this project is to create sorting algorithm.

## How to use:
```
make re && make bonus && make clean

ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG

echo $ARG

./push_swap $ARG | ./checker $ARG
```