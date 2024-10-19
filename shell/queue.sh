# queue shell
../bin/exe_queue 5 > ../log/log_queue.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_queue.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_queue 5 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt