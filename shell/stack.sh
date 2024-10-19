# stack shell
../bin/exe_stack 5 > ../log/log_stack.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_stack.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_stack 5 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt