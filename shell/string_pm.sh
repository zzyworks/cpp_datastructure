# string_pm shell

valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file=../log/log_valgrind.log ../bin/exe_string_pm people "now is the time for all good people to come" > ../log/log_string_pm.log 2>&1 &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_main.log &&

echo `date +"%Y-%m-%d %H:%M:%S"` >> ../log/log_valgrind.log
