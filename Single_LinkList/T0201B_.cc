/*
 * @Description: T0201B_链表合并（有重复数据）
 * @Author: HailayLin
 * @Date: 2021-10-22 18:15:10
 * @LastEditTime: 2021-10-22 21:03:52
 * @FilePath: \Algorithm\Single_LinkList\T0201B_.cc
 */

/**
 * @brief 题目内容：
在T0201的基础上修改程序，将两个非递减的有序链表合并为一个非递减的有序链表。要求：
（1）结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间；
（2）表中允许有重复的数据。

例1（第2、8行为输入）：
Empty!
77 88 77
There are 3 scores in the Linklist:
77
77
88

56 79 82 99
There are 4 scores in the Linklist:
56
79
82
99

There are 7 scores in the Linklist:
56
77
77
79
82
88
99

 请注意，main()函数必须按如下所示编写：
int main()
{
    SingleList<int> sa,sb;
    sa.show(); //遍历链表 
    int s;
    for(int i=0; i<3; i++)
    {         cin>>s;         sa.Insert(s);     }  //构造可有重复元素的非递减单链表sa
    sa.show(); //遍历链表
    for(int i=0; i<4; i++)
    {         cin>>s;         sb.Insert(s);     } //构造可有重复元素的非递减单链表sa 
    sb.show();
    sa.MergeLink(sb); //合并两个链表 
    sa.show();
    return 0;
}
 * 
 */

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int Status;

template<typename T>
struct ListNode{
    T data;
    ListNode<T> *next; 
};

template<typename T>
class SingleList
{
public:
    // 链表元素个数,初始化为0
    int length = 0;
    // 单链表初始化
    SingleList();
    // 链表逐个删除
    ~SingleList();
    // 链表插入元素
    Status Insert(T elem);
    // 链表展示
    Status show();
    // 合并带有重复元素的链表
    Status MergeLink(SingleList<T> sb);
private:
    ListNode<T> *head;
};

template<typename T>
SingleList<T>::SingleList()
{
    head = new ListNode<T>;
    head->data = -2147483648;
    head->next = NULL;
    length = 0;
}

template<typename T>
SingleList<T>::~SingleList()
{
    ListNode<T> *p; 
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

template<typename T>
Status SingleList<T>::show()
{
    if(head->next == NULL)
    {
        cout << "Empty!" << endl;
        return ERROR;
    }
    ListNode<T> *p = head->next;
    cout << "There are " << this->length << " scores in the Linklist:" << endl;
    while(p != NULL)
    {
        cout << p->data << endl; 
        p = p->next;
    }
    cout << endl;
    return OK;
}

/**
 * @brief 在单链表合适的位置插入元素
 * 
 * @tparam T 
 * @param elem 
 * @return Status 
 */
template<typename T>
Status SingleList<T>::Insert(T elem)
{
    ListNode<T> *p = head;
    // 1. 一开始有元素，比较大小，比elem小和大的中间插入
    while(p->next != NULL)
    {
        if(p->data <= elem && p->next->data >= elem)
        {
            ListNode<T> *s = new ListNode<T>;
            s->next = NULL;
            s->data = elem;
            s->next = p->next;
            p->next = s;
            length++;
            return OK;
        }
        p = p->next;
    }
    // 2. 一开始没有元素或者elem比所有元素都要大，从后面接入
    if(p->next == NULL)
    {
        ListNode<T> *s = new ListNode<T>;
        s->next = NULL;
        s->data = elem;
        p->next = s;
        length++;
    }
    return OK;
}

/**
 * @brief 合并有序链表，结果链表仍使用原来两个链表的存储空间，
 * 不另外占用其他的存储空间；表中允许有重复的数据
 * 
 * 方法：类似Insert函数里面，找合适的区间后插入
 * @tparam T 
 * @param sb 
 * @return Status 
 */
template<typename T>
Status SingleList<T>::MergeLink(SingleList<T> sb)
{
    // 0. 长度变为二者之和
    length = sb.length + length;
    // 1. a表不为空，把b按照顺序插入
    ListNode<T> *pa = head;
    ListNode<T> *pb = sb.head->next;
    sb.head = NULL;      //这行还不能删掉，否则输出乱码？
    ListNode<T> *s;
    while(pa->next != NULL && pb != NULL)
    {
        if(pa->data <= pb->data && pb->data <= pa->next->data)
        {
            s = pb;
            pb = pb->next;
            s->next = pa->next;
            pa->next = s;
        }
        else pa = pa->next;
    }
    // 2. a为空，b不为空，sb接到sa后面
    if(pa->next == NULL && pb != NULL)
    {
        pa->next = pb;
        pb = NULL;
    }
    return OK;
}

int main()
{
    SingleList<int> sa,sb;
    sa.show(); //遍历链表 
    int s;
    for(int i=0; i<3; i++)
    {         cin>>s;         sa.Insert(s);     }  //构造可有重复元素的非递减单链表sa
    sa.show(); //遍历链表
    for(int i=0; i<4; i++)
    {         cin>>s;         sb.Insert(s);     } //构造可有重复元素的非递减单链表sa 
    sb.show();
    sa.MergeLink(sb); //合并两个链表 
    sa.show();
    return 0;
}