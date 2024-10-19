# sorts shell
../bin/exe_sorts > ../log/log_sorts.txt 2>&1 && 

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_sorts.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_sorts &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt