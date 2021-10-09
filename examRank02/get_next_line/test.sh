gcc -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line
./get_next_line < file > yours_.res
cat -e yours_.res > yours.res
cat -e < file > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res get_next_line
