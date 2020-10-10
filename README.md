## 数据结构 严蔚敏 吴伟民 版



### 前言

**为什么要创建这个项目？**

首先，我学习数据结构并不是看这本书学习的，但是这是我们学校（想必也是大多数学校）学习数据结构的教材。上课时，看了书中的部分代码，觉得写的不错，有点出乎我的预料。所以想好好的看看这本书，并且记录下自己的学习过程。

**如何评价这本书？**

这本书截至目前在豆瓣上的评分只有 [7.0](https://book.douban.com/subject/2024655/) （通常没有超过 8 分的计算机书籍我是没有兴趣看的）。7.0 分对于这本书是否合适？

我的答案是：合适也不合适。如果这本书不是作为教材——大多数学生的入门书，我相信评分至少勉强能达到 8 分。起初我看这本书时，完全搞不懂书中在写什么，但是当我有了一定基础之后再看这本书，我发现这本书并没有想象中的晦涩。所以在这里，我希望这个项目可以帮助各位初学者更好的学习这本书，领略到其中精华。

[严蔚敏 的 《数据结构(C语言版)》 这本书在豆瓣评分为什么不高？](https://www.zhihu.com/question/27668938/answer/179414563) 

更多关于数据结构与算法的讨论，请关注我的另外两个仓库：

- https://github.com/hairrrrr/Data-Structure

- https://github.com/hairrrrr/Algorithm



### 目录

推荐在正式学习之前先看看下面的注意一节

练习 一栏中只展示个人认为比较好的题目，更详细的列表请戳链接（练习）

作业 一栏中题目的完整描述请戳链接（作业）

| 章节          | 案例                                                         | [练习]() ::1st_place_medal: | [作业 ](https://github.com/hairrrrr/DataStructure/tree/master/HomeWork) ::computer_mouse: |
| ------------- | ------------------------------------------------------------ | --------------------------- | ------------------------------------------------------------ |
| 第二章 线性表 | [合并线性表（2.1 2.2）](https://github.com/hairrrrr/DataStructure/blob/master/Demo/02_Linear_list/2-1_2-2.md) |                             | 字母的插入删除                                               |
|               | [线性表的顺序表示和实现（2.4 ~ 2.7）](https://github.com/hairrrrr/DataStructure/blob/master/Demo/02_Linear_list/2-3_2-7.md) |                             | 集合的并，交，差集运算                                       |
|               | [线性表的链式表示和实现（2.8 ~ 2.12）](https://github.com/hairrrrr/DataStructure/blob/master/Demo/02_Linear_list/2-8-2_2-12.md) |                             |                                                              |
|               | [静态链表表示和实现（2.13 ~ 2.17）](https://github.com/hairrrrr/DataStructure/blob/master/Demo/02_Linear_list/2-13_2-17.md) |                             |                                                              |
|               | [循环链表的表示]()                                           |                             |                                                              |
|               | [双向链表的表示和实现]()                                     |                             |                                                              |
|               | [链表综合（2.20 2.21）]()                                    |                             |                                                              |
|               | [一元多项式的表示及相加（相乘）（2.22 2.23）]()              |                             |                                                              |
|               |                                                              |                             |                                                              |
|               |                                                              |                             |                                                              |



### 注意

这一节我会说明我对于本书某些部分的理解和个人的编码习惯，方便大家更好的理解我的代码。

#### 01 引用 & 是什么？它和指针有什么区别？

上数据结构的第一次课看课本时，我就注意到了似乎作者喜欢向函数传递引用。比如算法 2.1 中：

```c
void union(List* La, List* Lb)
{
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for(i = 1; i <= Lb.len; i++)
    {
        GetElem(Lb, i, e);
        if(!LocateElem(La, e, Equal))
        	ListInsert(La, ++La_len, e);
    }
}
```

这本教材应该是应用于整个计算机学院的。这就带来一个问题，没有学 C++ 的同学可能会不理解这里 `&` ，也就是引用的含义。

首先什么是引用？

在 Java 中：

```java
Scanner s = new Scanner(System.in);
```

我们可以说 s 是一个 Scanner 类对象的引用。这里引用的含义有点类似于 C 语言中的指针。

其实 C++ 中的引用的本质就是指针。引用的好处之一是便利了程序员，不需要再像 C 那样向函数传地址，然后再在函数中解引用才能改变变量的值了：

```cpp
void pass_by_ref(int& a)
{
    a = 20; // 直接使用 a 就可以修改 main 中 a 的内容
}
void pass_by_ptr(int* a)
{
    *a = 20; // 需要自己解引用
}

int main(void)
{
    int a = 10;
    pass_by_ref(a);  // 直接传递 a 即可
    pass_by_ptr(&a); // 传递 a 的地址
}
```

关于引用的更多内容，在这里不再展开。

上面说了引用的好处，其实在这门课里，完全可以使用指针代替引用，而且个人认为会让程序更加清晰明了。

另外，C 语言编译器 **不支持**  `&` 语法。如果要使用引用，你需要使用 C++ 编译器（在 VS 中将文件后缀 `.c` 改为 `.cpp`）。这就好像和朋友去吃饭，你只吃了一口，但是要给所有人买单一样。

现在我们可以将 `union()` 函数改为传递指针版本：

```c
void union(List* La, List* Lb)
{
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for(i = 1; i <= Lb.len; i++)
    {
        GetElem(Lb, i, &e);
        if(!LocateElem(La, e, Equal))
        	ListInsert(La, ++La_len, e);
    }
}
```



#### 02 传值 or 传指针？

教材中的 `union()` 函数第一个参数传递的是引用（指针），第二个参数传递的是值。

作者的逻辑很好理解，既然我要向 La 中插入 Lb 中的不存在于 La 中的元素，要改变的是 La，而 Lb 是不改变的。因此，就按指针传递 La，按值传递 Lb。

这样的写法有错吗？没有。但是我不推荐大家这样写。

学习 C 语言时我们就知道，传递指针的好处除了可以 “真正” 的改变传入参数的值之外，还可以提高程序的效率。虽然 Lb 的值没有改变，但是传递 Lb 的指针可以降低程序的时间，空间复杂度，这在 Lb 占用内存十分多的时候尤为明显。如果你害怕 Lb 的值被修改，可以传递 `const` 指针：

```c
void union(List* La, const List* Lb);
```

`const `保证 Lb 指向的内容不被 `union` 函数修改。



#### 03 是否使用头节点

我个人喜欢使用头节点，原因是在插入和删除节点时不需要考虑是否是头插/头删的问题：

```c
// 删除值为 val 的节点

// 无头节点 
// 可能要更改 first 要传入 first 的地址，指针类型为 List**
void del_no_head(List** first, ElemType val)
{
    List* cur = *first;
    List* prev = cur;
    while(cur)
    {
        if(cur->_data == val)
        {
            // 如果是头删，需要更改链表的头
            if(cur == *first)
            {
                // 头节点向后移动
                *first = (*first)->_next;
                free(cur);
                cur = *first;
                prev = cur;
            }
            else 
            {
                prev->_next = cur->_next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->_next;
        }
    }
}

// 有头节点
void del_has_head(List* head, ElemType val)
{
    List* cur = head->_next;
    // 将 prev 初始化为 头节点
    List* prev = head;
    while(cur)
    {
        // 不需要单独考虑删除头节点
        if(cur->_data == val)
        {
            prev->_next = cur->_next;
            free(cur);
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->_next;
        }
    }
}
```



#### 04 关于头节点的传参

[关于链表表头传参问题](https://www.cctechblog.cn/_posts/2020-04-19-%E5%85%B3%E4%BA%8E%E9%93%BE%E8%A1%A8%E7%9A%84%E8%A1%A8%E5%A4%B4%E4%BC%A0%E5%8F%82/)



### 相关资料推荐

[B 站严奶奶的视频](https://www.bilibili.com/video/BV1ns411r7Cn?p=4)

[GitHub 项目](https://github.com/kangjianwei/Data-Structure)

[博客](https://blog.csdn.net/lady_killer9/article/details/82695895)