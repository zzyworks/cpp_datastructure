1. 使用`valgrind`检测内存泄漏问题`valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file={输出文件路径} {可执行文件}`
2. 使用`shell`来简化运行结果
3. 将结果输出到`log`文件中