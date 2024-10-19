# bin_tree shell
../bin/exe_bin_tree 5 > ../log/log_bin_tree.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_bin_tree.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_bin_tree 5 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt