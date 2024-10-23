# sorts shell
../bin/exe_sorts > ../log/log_sorts.log 2>&1 && 

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_sorts.log &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.log ../bin/exe_sorts &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.log