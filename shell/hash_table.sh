# hash_table shell
../bin/exe_hash_table 5 > ../log/log_hash_table.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_hash_table.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_hash_table 5 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt