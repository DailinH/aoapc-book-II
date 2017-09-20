# 《算法竞赛入门经典(第二版)》 学习进度记录
> 所有上传代码均使用Visual Studio 2017编译成功
### [第6章 数据结构基础][1]
- **例题6-1**([UVA 210][5])

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

**解题思路**  
发现我的这个思路按照输入输出完全对不上啊orz  
大概还是菜
参考文章[http://blog.csdn.net/acvay/article/details/43054111][6]  
> 题意  模拟程序并行运行  
> STL队列 双端队列 的应用  用双端队列维护即将执行的程序  再用个队列维护等待变量释放的程序   用lock表示变量锁定状态  
> 先将所有程序依次放到执行队列中  每次取出队首程序运行不超过lim时间  未运行完又放到执行队列队尾  
> 遇到lock时  若当前锁定状态为false就将锁定状态变为true  否则将当前程序放到等待队列队尾并结束运行  
> 遇到unlock时  若等待队列有程序  就将等待队列队首程序放到执行队列队首  
> 遇到end时 退出当前执行(不再进队尾)  
emmm不行我想去睡觉了....
GOOD NIGHT CRUEL WORLD


'''




[1]:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=837
<!-- AC -->
[2]: https://img.shields.io/badge/AC-%E2%88%9A-brightgreen.svg
<!-- WA -->
[3]: https://img.shields.io/badge/WA-%C3%97-red.svg
<!-- TLE -->
[4]: https://img.shields.io/badge/TLE----yellow.svg
[5]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=838&page=show_problem&problem=146
[6]: http://blog.csdn.net/acvay/article/details/43054111