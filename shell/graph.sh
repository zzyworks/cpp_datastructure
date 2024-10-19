# graph shell
../bin/exe_graph -import < ../input/graph.prim.0009+0028.txt > ../log/log_graph.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_graph.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_graph -import < ../input/graph.prim.0009+0028.txt &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt