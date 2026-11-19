#!/bin/sh
set -eu
gcc -std=c11 -Wall -Wextra -fPIC -c crypto.c -o crypto.o
ar rcs libcrypto_demo.a crypto.o
gcc -shared -o libcrypto_demo.so crypto.o
gcc -std=c11 -Wall -Wextra main.c ./libcrypto_demo.a -o bank_static
gcc -std=c11 -Wall -Wextra main.c -L. -lcrypto_demo -Wl,-rpath,'$ORIGIN' -o bank_dynamic
gcc -std=c11 -Wall -Wextra main_dlopen.c -o bank_dlopen -ldl
echo "Built bank_static, bank_dynamic and bank_dlopen"
ls -lh bank_static bank_dynamic
ldd ./bank_dynamic
