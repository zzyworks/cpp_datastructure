# bin_tree shell
../bin/exe_huffman ../input/huffman-text-0.txt test_data > ../log/log_huffman.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_huffman.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_huffman ../input/huffman-text-0.txt test_data &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt