export LIBRARY_PATH=${PWD}
export LD_LIBRARY_PATH=${PWD}

make re && gcc -g -o test00 test00.c -I./include/ -I./libft/ -L./libft/ -lft -lft_malloc_x86_64_Darwin && ./test01
/usr/bin/time -l ./test01