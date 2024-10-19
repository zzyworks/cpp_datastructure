# string_pm shell

../bin/exe_string_pm people "now is the time for all good people to come" > ../log/log_string_pm.txt 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_string_pm.txt &&

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.txt ../bin/exe_string_pm people "now is the time for all good people to come" &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.txt