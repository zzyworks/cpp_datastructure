# demo shell
../bin/exe_demo > ../log/log_demo.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_demo.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_demo &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt