# 说明

- 这是一个使用c++实现等待数据结构项目。
- 本项目在参考邓俊辉老师`<<c++书籍结构>>`书籍的基础上，使用出c++11标准实现。
- 若有侵权，联系删除

- 使用`valgrind`检测内存泄漏问题`valgrind --tool=memcheck --leak-check=full --show-reachable=yes --trace-children=yes  --log-file={输出文件路径} {可执行文件}`

- 使用`shell`来简化运行结果

- 将结果输出到`log`文件中



# 项目运行环境

### `vm`虚拟机下的`ubuntu`

- 版本号`#45~22.04.1-Ubuntu`



### `gcc`

- 版本号`gcc version 13.1.0 (Ubuntu 13.1.0-8ubuntu1~22.04) `



### `cmake`

- 版本号`cmake version 3.22.1`

  

### `valgrind`

- 查看是否内存泄漏的工具

- 版本号`valgrind`-3.18.1



# 如何运行？

- 以下都将`data_structure`作为工作路径

1. 使用`vscode`打开项目

```
code .
```



2. 找到`./tests`

- 这是主函数，也就是项目启动入口



3. 找到`./include/tests`

- 这是实现容器的测试头文件



4. 假设测试`vector`

```
1 将 ./include/tests/test_vector.hpp 中注释的main函数复制到 ./tests/main.cpp 中

2 将 ./tests 中CMakeLists.txt文件15行改为add_executable(exe_vector ${src})

3 进入 ./build 执行 cmake.. && make

4 所生成的可执行文件会到 ./bin 目录下

5 进入 ./shell 目录下，执行 shell vector.sh 会自动在log目录生成测试显示的信息
```



5. 其余同理



# 参考书籍

- [清华大学邓俊辉 数据结构`c/c++`]: https://pan.baidu.com/s/1nKtEGWYw8GiRzl8309MCcg?pwd=82tm