# **《算法竞赛入门经典(第二版)》 学习进度记录**
> 所有上传代码均使用Visual Studio 2017编译成功  
<!-- > ~~由于uvaoj等待时间过长，故改用vjudge.net做题~~  
> 发现vjudge.net好像是直接用了uva的oj判题orz -->

<!-- TOC -->

- [**《算法竞赛入门经典(第二版)》 学习进度记录**](#%E3%80%8A%E7%AE%97%E6%B3%95%E7%AB%9E%E8%B5%9B%E5%85%A5%E9%97%A8%E7%BB%8F%E5%85%B8%E7%AC%AC%E4%BA%8C%E7%89%88%E3%80%8B-%E5%AD%A6%E4%B9%A0%E8%BF%9B%E5%BA%A6%E8%AE%B0%E5%BD%95)
    - [**第6章 数据结构基础**](#%E7%AC%AC6%E7%AB%A0-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E5%9F%BA%E7%A1%80)
        - [**例题6-01**](#%E4%BE%8B%E9%A2%986-01)
        - [**例题6-02**](#%E4%BE%8B%E9%A2%986-02)
        - [**例题6-03**](#%E4%BE%8B%E9%A2%986-03)
        - [**例题6-04**](#%E4%BE%8B%E9%A2%986-04)
        - [**例题6-05**](#%E4%BE%8B%E9%A2%986-05)
        - [**例题6-06**](#%E4%BE%8B%E9%A2%986-06)
        - [**例题6-07**](#%E4%BE%8B%E9%A2%986-07)
        - [**例题6-08**](#%E4%BE%8B%E9%A2%986-08)
        - [**例题6-09**](#%E4%BE%8B%E9%A2%986-09)
        - [**例题6-10**](#%E4%BE%8B%E9%A2%986-10)
        - [**例题6-11**](#%E4%BE%8B%E9%A2%986-11)

<!-- /TOC -->

----------------------


## **第6章 数据结构基础**

| 类别    | 题号   | 完成状态 | 开始日期  | 完成日期 |
| ------- | ------ | -------- | --------- | -------- |
| 例题6-1 | [UVA 210][5] | skipped| 2017-9-20 | /        |
| 例题6-2 |[UVA 514][7]| ![][2] | 2017-9-21 |2017-9-21|
| 例题6-3 | [UVA 442][8] | ![][2] |2017-9-22|2017-9-22|
| 例题6-4 | [UVA 11988][9] | ![][2] |2017-9-22|2017-9-22|
| 例题6-5 | [UVA 12657][10] | ![][2] |2017-9-23|2017-9-23|
| 例题6-6 | [UVA 679][11] | ![][2] |2017-9-23|2017-9-24|
| 例题6-7 | [UVA 122][12] | skipped | | |
| 例题6-8 | [UVA 548][14] | ![][2] |2017-9-29|2017-9-29|
| 例题6-9 | [UVA 839][15] | ![][2] |2017-9-29|2017-9-29|
| 例题6-10 | [UVA 699][16] | ![][2] |2017-9-29|2017-9-29|
| 例题6-11 | [UVA 297][17] | ![][2] |2017-9-29|2017-9-29|



### **例题6-01**
**题目要点：**
1. 模拟并行程序
2. 分为running和ready两个状态
3. 每个程序的序列<=25条命令，每条命令一行，包含结束符
1. 有*variable = constant*, *print variable*, *lock*, *unlock*, *end*五种命令
1. variable为单个小写字母，constant为正数整数<100，**为所有程序共享**
1. 所有var初始化为0
1. 每条statement需要整数长时间来运行
1. 两个程序之间时长为quantum
1. 程序在ready队列中，满足FIFO
1. 队列原始顺序为输入的顺序,lock和unlock使队列顺序改变
1. lock和unlock不可相互嵌套；lock导致
1. block队列中存放被lock的序列。unlock之后，block首元素被移至ready队列首位
1. 输入： 程序数 五条命令分别所用时间 quantum占用时间
1. 输出： 运行过程中的输出命令 -> 程序编号：对应值

**解题思路:**  
发现我的这个思路按照输入输出完全对不上啊orz  
大概还是菜
参考文章[http://blog.csdn.net/acvay/article/details/43054111][6]  
> 题意  模拟程序并行运行  
> STL队列、双端队列的应用  
> 用双端队列维护即将执行的程序,再用个队列维护等待变量释放的程序   
> 用lock表示变量锁定状态 
> 先将所有程序依次放到执行队列中,每次取出队首程序运行不超过lim时间,未运行完又放到执行队列队尾  
> 遇到lock时:若当前锁定状态为false就将锁定状态变为true;否则将当前程序放到等待队列队尾并结束运行  
> 遇到unlock时:若等待队列有程序,就将等待队列队首程序放到执行队列队首  
> 遇到end时 退出当前执行(不再进队尾)  


### **例题6-02**  
**题目要点：**  
题目比较简单，使用一个stack作为中转队列即可解决问题。  
输入：  
第一行为元素总数  
第二行以后为所有目标序列  
0标志该block结束  
连续两个0标志输入结束  
输出：  
Yes/No，不同block之间以空行分隔

**解题思路:**   
设中转队列为stack s
重点应该在于分析出栈的各种情况

    if 即将入栈 == 目标元素
        该元素无需入栈
    else if 栈顶元素 == 目标元素
        栈顶元素出栈
    else 
        元素入栈

### **例题6-03**
[50min]  
**题目要点：**  
简单矩阵乘法问题，略   
emmm...我为什么做了这么久？？？   
码代码10分钟，debug半小时 (╯‵□′)╯︵┻━┻

**解题思路**  
比较简单，没啥特殊思路……  
可能是太久没做题了 实际写算法的时候就有很多细节没注意到  

### **例题6-04**

**题目要点：**  
利用链表解决  

**解题思路：**  
- 方法1  
    0|1|2
    -|-|-
    前一个字母的位置|现在所包含的字母|后一个字母的位置  
    链表并不需要一定用指针完成。  
    比较关键的部分应该在于模拟指针数组的处理

        if 处理'['  
            curPos = 0;  
            虚拟指针移向头部（0 char 1）  
        else if 处理']'  
            curPos = seqNum;  
            虚拟指针移向尾部(seqNum char seqNum+1)  
        else if 处理正常输入字符  
            seqNum++  
            curPos++  

        if 现在位置处于头部(curPos < seqNum)  
            所有大于curPos的[0][2]项都加1  
        else if 位置处于尾部  
            只需添加当前字符  


- 方法二  
想到一种新的做法：  
刚刚那种做法其实比较累赘.  
将数组简化成二维:
0|1
-|-
序号|所含字符的原顺序
然后按照序号排序  
emmm 先思考一下会不会超时  
如果用自带的sort 复杂度应该是nlgn  
100000个字母排序,时间就是10^5..  
不过挨个读取的话,复杂度是n,这里应该相差不多.  
伪代码如下:  

        //注意,seqNum所指向的位置应该尚未填充数字
        if 处理'['  
            curPos = 0; 
            先使之前所有的元素顺序++
        else if 处理']'  
            //如果之前出现过[ (指针现在位于头部)
            if curPos != seqNum
                for i=1:(seqNum-curPos)
                    sequences[i][0]+=curPos;
            //将指针移到尾部
        else if 处理正常输入字符  
            sequences[seqNum][0] = seqNum;
            sequences[seqNum][1] = i;
            seqNum++;
            curPos++;  


嗯，再次成功绕晕自己  
二维数组排序貌似只能自己写？ 结果写好了以后还是tle了
QAQ

- 方法三  
回到指针方法 （参考书中代码）
顺便膜一发刘教主，代码超美啊

        if '['
            光标移到首位0
        else if ']'  
            光标移到末位last(last为空)
        else
            第i位的下一位位当前位的下一位
            当前为的下一位位第i位（相互关联）
            if 光标在末尾
                更新最后一个字符编号
            更新当前位置编号cur为i

另外需要注意的是头尾相关联的两个指针。这一关系同时也被用作for循环的终止关系，即当“下一个”指向第0个字母的时候，表示整个读取过程都结束了。

### **例题6-05**

**题目要点：**  
构造双向链表保存盒子顺序

**解题思路：**  
伪代码如下  

    //处理每条命令
        if 逆转
            inv = !inv
        else 
            输入X和Y
            if op = 3 && X在Y右侧
                交换XY，使X在Y左侧//便于简化XY相连的情况
            if 逆转为真 op=3-op
            if op = 1 && X 在Y 左侧  免处理该命令
            if op = 2 && X 在Y 右侧  免处理该命令
            
            if op=1 
                连接 X左 -- X右
                连接 Y左侧 -- X
                连接 X -- Y
            else if op= 2
                连接 X左 -- X右
                连接 X --Y右侧
                连接 Y -- X
            else if op = 3
                if X与Y相连
                    X左 -- Y
                    Y -- X
                    X -- Y右侧
                else
                    X左 -- Y
                    Y -- X右
                    Y左 -- X
                    X -- Y右

最后求所有奇数位置的盒子编号之和
首先遍历找出起始点位置。
   
    if inv == TRUE //若逆转
        Right[Start] = 0;
        ans += Start;
        for int i = 0; i<boxNum; i+=2
            Start = Left[Left[Start]];
            ans+= Start;
    else
        //Left[Start] = boxNum;
        Left[Start] = 0;    
        ans += Start;
        for int i = 0; i<boxNum; i+=2
            Start = Right[Right[Start]];
            ans+= Start;

然后就WA了T_T
直接给的数据跑出来答案是没有问题。在Debug里面第一例答案就不正确：

    3 6
    3 1 3
    1 3 2
    2 3 2
    2 2 3
    2 1 3
    3 2 1
    Case 1: 7
            
而正确答案应该为4.

Command | Sequence
-|-
original| 1 - 2 - 3
3 1 3 | 3 - 2 - 1
1 3 2 | 1 - 3 - 2
2 3 2 | 1 - 2 - 3
2 2 3 | 1 - 3 - 2
2 1 3 | 3 - 1 - 2
3 2 1 | 3 - 2 - 1

无论如何也得不出7的说呀  
可能是3+1+3？  
估计是我的输出序列出了问题。

学习一下刘教主的输出

    step1 求取所有顺序奇数位的和
    step2 判断是否为偶数的逆转序列。若为逆转序列，则用所有数的和-顺序奇数位的和

QAQ膜教主！比我混乱的写法不知道高到哪里去了

改过了以后仍然有问题……开启调试状态  
以出现问题的Morass -- Case 2为例

    输入数据：
    8 13
    2 7 6
    3 3 4
    3 4 7
    1 7 3
    1 5 8
    4
    2 1 3
    1 2 4
    2 1 8
    2 7 3
    3 5 2
    2 8 3
    3 4 5
    输出数据：
    Case 2: 19
    我的错误输出：
    Case 2: 17
    
打印我的输出序列，显示为：7 8 3 6 4 2 5 1  
感觉已经inv过的输出序列一样……
实际过程与我的过程对比应该是

command|sequence|My Sequence
-|-|-
original| 1 2 3 4 5 6 7 8 |1 2 4 3 5 6 7 8
2 7 6| 1 2 3 4 5 6 7 8|1 2 4 3 5 6 7 8
3 3 4| 1 2 4 3 5 6 7 8|...
3 4 7| 1 2 7 3 5 6 4 8|1 2 7 3 5 6 4 8
1 7 3| 1 2 7 3 5 6 4 8|1 2 7 3 6 4 5 8
1 5 8| 1 2 7 3 6 4 5 8|1 2 7 3 6 4 5 8 
4| 8 5 4 6 3 7 2 1|
2 1 3| 8 5 4 6 3 1 7 2|inv（2 7 1 3 6 4 5 8）
1 2 4| 8 5 2 4 6 3 1 7 |inv（7 1 3 6 4 2 5 8）
2 1 8| 8 1 5 2 4 6 3 7 |inv（7 3 6 4 2 5 1 8）
2 7 3| 8 1 5 2 4 6 3 7 |inv（7 3 6 4 2 5 1 8）
3 5 2| 8 1 2 5 4 6 3 7 |**inv（7 8 3 6 4 2 5 1）**  **错误！**
2 8 3| 1 2 5 4 6 3 8 7 |...
3 4 5| 1 2 4 5 6 3 8 7 |...

经过debug找到错误，发现是在判断inv使cmds=3-cmds的时候，漏掉了判断cmds！=3  
终于AC了orz

### **例题6-06**

**题目要点：**  
虽然题目是树结构，但是如果用数组模拟遍历的方法来做显然非常耗时。  
这里考虑采用数学方法进行解题尝试  
**解题思路：**  
对于落到某k点上的第I个小球  

    if I为奇数
        I向左走
        落到第k*2个小球上
        I=(I+1)/2
    else if I为偶数
        I向右走
        落到第k*2+1个小球上
        
第一次的时候tle了， 检查发现多次输入命令的循环在break处顺序出现了错误，导致无法正常多次读入命令和执行。  
更改后AC。  


### **例题6-07**

**题目要点：**  
大概就是单纯地填充树就行了？  
趁机练一下树的指针结构orz  

**解题思路：**  
写一个node类，利用指针动态构造树结构。  
strchr函数(见[https://baike.baidu.com/item/strchr/10985184?fr=aladdin][13] )

### **例题6-08**

**题目要点：**  
难度不大，主要是考察bfs吧

**解题思路：**  
出了个错反复查了半天orz  
最后发现其实应该是bfs在初始化的时候赋sum出错了  
尴尬  

### **例题6-09**

**题目要点：**  
本质仍然是二叉树，由于永远优先处理左枝，所以用bfs进行处理即可。

**解题思路：**  
在解题的时候忘记把分支的重量计入总重量了，当然WA……  
改过这个错以后就AC了  
而且当时看了好几遍都没看出来咋回事儿  
心路历程如下：  

    --“这次再不ac我就是狗”
    5秒后
    --”汪汪汪”


### **例题6-10**

**题目要点：**  
ezy

**解题思路：**  
是否可用deque进行解答？  
赋值一个位置标记position  来记录树根的位置   
题中是采用一边build一边计数的方法
开一个足够大的数组，将position直接记在中间（2333感觉很粗暴啊）

### **例题6-11**

**题目要点：**  
因为四分树的子树数量一定为0或者4  
若为p则继续生成子树  
否则则为叶

**解题思路：**  
我觉得也可以不用递归绘图啊orz  
反正只有到了叶节点处才能绘图  
不如记录一个depth，如果curdepth<depth,则黑色点的数量*pow(4,depth - curdepth);  
不行 好像和题意不符  

[一次性AC的感觉棒极了]  
不过下次注意一下传值的问题QAQ  
第一次尝试的时候由于赋值给draw的时候用了直传而无法计算结果  
还是生疏了啊  






<!-- ### **例题6-**([uva][])
**题目要点：**  
**解题思路：**   -->

[1]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=837
<!-- AC -->
[2]: https://img.shields.io/badge/AC-%E2%88%9A-brightgreen.svg
<!-- WA -->
[3]: https://img.shields.io/badge/WA-%C3%97-red.svg
<!-- TLE -->
[4]: https://img.shields.io/badge/TLE----yellow.svg
[5]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=146
[6]: http://blog.csdn.net/acvay/article/details/43054111
[7]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
[8]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=383
[9]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=3139
[10]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=4395
[11]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=620
[12]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=58
[13]:https://baike.baidu.com/item/strchr/10985184?fr=aladdin;
[14]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=489
[15]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=780
[16]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=640
[17]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=233