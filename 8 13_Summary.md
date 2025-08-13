# 8.13-中断和定时器、PWM

Created: 2025年8月12日 09:51

## 1. 中断

### ①嵌套向量中断控制器NVIC

- 控制中断的优先级、响应时间、嵌套等
- 中断嵌套：高抢占式优先级可以在具有低抢占式优先级的中断服务程序执行过程中被响应
  
    ![image-20250813200538309](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813200538309.png)
    
- 中断优先级数字越低越高

![image-20250813200558031](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813200558031.png)

上面图片为两个重要相关函数，可以去仔细看看怎么定义使用

## 2. TIM时钟

### ①定时器介绍

- ==时间测量、事件计数、PWM生成、输入捕获、输出比较等==

  > ①**时间测量**：通过EventStatics能够看到中断时间，（EventStop/Start放到合适的地方）设置预分频器和自动重载值，启动定时器，通过中断服务函数进行时间计数
  >
  > ②**事件计数**：配置定时器的输入捕获通道，设置输入捕获的极性和分频值，启动输入捕获并使能中断，在中断服务函数中进行事件计数
  >
  > ③**PWM生成**：配置定时器的时钟和计数模式，设置预分频器和自动重载值，配置PWM输出通道
  >
  > ④**输入捕获**：配置定时器的输入捕获通道，设置输入捕获的极性和分频值，启动输入捕获并使能中断，在中断服务函数中处理捕获值

- 多功能可编程定时器：可以简单延时，还能实现复杂的时序控制——嵌入式实时性的核心工具

- 32F405RGT6的计时器：（前三种可使用，通用定时器最常使用）

![image-20250813200611802](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813200611802.png)

要注意位宽，不要越界

### ②定时器的三个参数

1. 预分频器寄存器（TIMx_PSC）：对定时器分频
2. ==计数器寄存器（TIMX_CNT）==：在分频基础上，记一次数的时间等于1/f；
3. ==自动重载寄存器（TIMx_ARR）==：是CNT能达到的最大计数值，MaxNum*CNT=T

### ③通用定时器三个模式

- 向上计数模式：递增
- 向下计数模式：递减
- 中央对齐模式

### ④定时器溢出==时间计算==

![image-20250813200628191](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813200628191.png)

### ⑤4个独立通道

①输入捕获

②输出比较

③PWM生成

④单脉冲模式输出

## 3. PWM

- 脉冲宽度调制：通过改变脉冲信号中高电平所占时间比例来控制平均输出电压或功率的计数——==改变占空比==（高电平占完整周期的百分比）——可以实现呼吸灯的效果（GPIO不行，它只有高低电平两种状态0/1）
- 占空比越高，平均输出电压越高

![image-20250813200642210](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813200642210.png)

## 4.Math/MSG头文件和头文件



## 8.13作业

呼吸灯放在main函数，流水灯在中断函数

![image-20250813200653726](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813200653726.png)

### 【作业思考】

1. 关于中断：是只要到了1/t，就会自动进入中断，打断while循环正在进行的程序（应该也和优先级有关）

2. 关于呼吸灯和流水灯的配合，因为总感觉呼吸灯会被打断，不知道是不是我的错觉，所以写了一个判断，不会每次while走进呼吸灯部分，从而刘流畅了一些

3. 关于中断的使用，直接在初始化模块加入回调函数，就可以实现中断，不用放在while循环里

4. 回调里不可以有延迟，要不然会报警

5. ==输出不了printf的原因==

   > 寻求帮助之后做的更改：
   >
   > ①TIM1的设置更改为：预分频器和自动重载值167、 9999
   >
   > ②==sec累加的情况为每次中断+10==
   >
   > ③防止呼吸灯进入次数过多，增加`		if(sec%50<=25)`判断
   >
   > ④检查Number of Records
   >
   > ![image-20250813204121170](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813204121170.png)
   >
   > ⑤确认此处钟频![image-20250813204203069](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813204203069.png)![image-20250813204711536](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250813204711536.png)
   >
   > ⑥main里的eventstart/stop更改到TIM1里

   原因：①main的while里的eventstart/stop太频繁了，可能会影响printf的执行

   ​           ②确保sec累增时能进入判断