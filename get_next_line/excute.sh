rm -rf ./*.gch
rm -rf ./a.out
gcc -Werror -Wall -Wextra -D BUFFER_SIZE=${1} *.c
