## ==结果展示==

![image-20250810210319508](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250810210319508.png)

1. 其中队列，是通过1-50的循环赋值而输入，最后输出是FIFO的顺序

2. 下半部分展示的是栈的输入输出，分别是int类型 float类型 unsigned int 类型，满足先入后出

本次程序在VSCode软件中生成，而后通过配置CMakeLists.txt，外加CMake、MinGW编译器实现环境的配置（不重启软件识别不到来着），最后结果已经展示



==***【ps疑问】：在观察栈的top指针变化以及数据存入是，发现第二个float变量本身初始设置3.00；但是top被memcpy显示的暂时变量是“0”，但是又很显然，最后提取输出数据是正常的，不是很清楚这是什么情况***==



