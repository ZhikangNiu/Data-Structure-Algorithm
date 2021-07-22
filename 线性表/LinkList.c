//
// Created by DaisyN on 2021-07-13.
//
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#define true 1
#define false 0

// 定义元素类型，此处以int为例子
typedef int ElemType;
// 定义元素状态
typedef int Status;
// 定义结构体
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
// LinkList是指向Node的指针
typedef struct Node *LinkList;

/*头插法初始化线性表，随机产生n个元素的值，建立代表头结点的单线性链表L*/
void InitListHead(LinkList *L,int n){
    // L是指向LinkList的指针
    LinkList p;
    int i;
    srand(time(0));  // 初始化随机种子
    *L = (LinkList)malloc(sizeof (Node)); // 分配一个空间
    //void *calloc(int num, int size);
    //在内存中动态地分配 num 个长度为 size 的连续空间，
    // 并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，
    // 并且每个字节的值都是0。
    (*L)->next = NULL;   // 先建立一个带头结点的单链表
    for (i = 0; i <n ; i++) {
        // 生成新的结点
        p = (LinkList) malloc(sizeof (Node));
        // 随机生成100以内的数字
        p->data = rand()%100+1;
        p->next = (*L)->next; // 这时间next没改变，如果放在下一步的话就改变了
        (*L)->next=p;  // 插入到表头
    }
}
/*尾插法初始化线性表，随机产生n个元素的值，建立代表头结点的单线性链表L*/
void InitListTail(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof (Node));
    r = *L;
    for (i = 0;  i<n ; i++){
        p = (Node*) malloc(sizeof (Node));
        p->data = p;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
/*求链表的长度*/
int ListLength(LinkList L){
    LinkList p = L; /*p指向表的第一个结点*/
    int j = 0;
    while (p){
        p = p->next;
        j++;
    }
    return j;
}
/*判断链表是否为空,若为空，返回true，不空，返回false*/
Status ListEmpty(LinkList L){
    return L->next ? false:true;
    /*
    if(L->next) return  false;
    else return true;
     */
}
/*删除整个单向链表，将l重置为空表*/
Status ClearList(LinkList *L){
    LinkList p,q;
    p = (*L)->next;
    while (p){
        q = p->next;
        // 释放内存空间
        free(p);
        // 往前移位
        p = q;
    }
    // 最后一步修改头结点的指针域
    p->next = NULL;
}
/* 用e返回L中第i个数据元素的值*/
Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    // 判断列表是否为空
    if(!p || j > i) return false;
    while (p && j<i){
        p = p->next;
        j++;
    }
    *e = p->data;
    return true;
}
// 删除l的第i个数据，并用e返回值，l的长度减1
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j = 1;
    LinkList p,q;
    // 好像p就是第一个元素
    p = *L;
    while (p->next && j<i){
        p = p->next;
        j++;
    }
    // 还需要判断第i个元素存在不存在
    if(!(p->next)||j>i) return false;
    // 变量q的作用不可以省略，上一个的指针域指向下下一个，并且释放空间
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}
// 在L中第i个位置之前插入新的数据元素e，L的长度+1
Status ListInsert(LinkList *L,int i,ElemType e){
    LinkList p,q;
    int j = 1;
    while (p->next && j<i){
        p = p->next;
        j++;
    }
    // 第i个元素不存在
    if(!p || j>i) return false;
    //分配空间
    q = (LinkList) malloc(sizeof (Node));
    // 注意顺序
    q->next = p->next;
    p->next = q;
    p->data = e;
    return true;
}
int main(){
    LinkList L;
    printf("num ",L);
}