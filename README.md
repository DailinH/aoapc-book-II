# 《算法竞赛入门经典(第二版)》 学习进度记录
> 所有上传代码均使用Visual Studio 2017编译成功  
<!-- > ~~由于uvaoj等待时间过长，故改用vjudge.net做题~~  
> 发现vjudge.net好像是直接用了uva的oj判题orz -->
<!-- TOC -->

- [《算法竞赛入门经典(第二版)》 学习进度记录](#算法竞赛入门经典第二版-学习进度记录)
    - [[第6章 数据结构基础][1]](#第6章-数据结构基础1)
        - [**例题6-1**([UVA 210][5])](#例题6-1uva-2105)
        - [**例题6-2**([uva514][7])](#例题6-2uva5147)
        - [**例题6-3**([uva442][8])[50min]](#例题6-3uva442850min)
        - [**例题6-4**([uva11988][9])](#例题6-4uva119889)

<!-- /TOC -->

----------------------


## [第6章 数据结构基础][1]

| 类别    | 题号   | 完成状态 | 开始日期  | 完成日期 |
| ------- | ------ | -------- | --------- | -------- |
| 例题6-1 | uva210 | skipped| 2017-9-20 | /        |
| 例题6-2 | uva514 | ![][2] | 2017-9-21 |2017-9-21|
| 例题6-3 | uva442 | ![][2] |2017-9-22|2017-9-22|


### **例题6-1**([UVA 210][5])

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


### **例题6-2**([uva514][7])
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

### **例题6-3**([uva442][8])[50min]
**题目要点：**  
简单矩阵乘法问题，略   
emmm...我为什么做了这么久？？？   
码代码10分钟，debug半小时 (╯‵□′)╯︵┻━┻

**解题思路**  
比较简单，没啥特殊思路……  
可能是太久没做题了 实际写算法的时候就有很多细节没注意到  

### **例题6-4**([uva11988][9])
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
