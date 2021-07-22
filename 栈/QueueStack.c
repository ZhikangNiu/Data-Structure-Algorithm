//
// Created by DaisyN on 2021-07-22.
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define true 1
#define false 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node,*QueuePtr;  //QueuePtr是指向Node的指针

typedef struct {   //队列的链表结构
    QueuePtr front,rear;  //队头队尾的指针
}LinkQueue;

Status InitQueue(LinkQueue *Q){
    /*第一遍自己写，还需要写出下一个节点的指针=NULL
    Q->front=Q->rear;
    return true;
    */
    QueuePtr s = (QueuePtr)malloc(sizeof (struct Node));
    if(!s) exit(OVERFLOW);//分配内存失败
    Q->front=Q->rear=s;//分配每个结点的空间
    Q->front->next = NULL;
    return true;
}
/*
 * Destroy和clear的区别在于
 * Destroy 是将所有空间释放
 * clear是清除元素，使其变为初始化的Queue
 */
Status DestroyQueue(LinkQueue *Q){
    QueuePtr p,q;
    p = Q->front;
    while (p){
        q = p->next;
        free(p);
        p = q;
    }
    return true;
}
Status ClearQueue(LinkQueue *Q){
    QueuePtr p,q;
    p = Q->front->next;
    Q->front->next=NULL;
    Q->rear = Q->front;
    //初结点和末结点的空间不能释放，只能释放中间的空间
    while(p){
        q = p;
        free(q);
        p = q->next;
    }
    return true;
}
Status QueueEmpty(LinkQueue *Q){
    if(Q->front == Q->rear) return true;
    else return false;
}
int QueueLength(LinkQueue Q){
    QueuePtr p;
    int i = 0;
    p =  Q.front;
    while (Q.rear!=p){
        i++;
        p = p->next;
    }
    return i;
}
Status EnQueue(LinkQueue *Q,ElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof (struct Node));
    if(!s) exit(OVERFLOW);  //OVERFLOW是math.h一个宏定义，其数值为3，出现了溢出运算
    s->data = e;
    s->next = NULL;
    Q->rear->data = s->data;
    Q->rear = s;
    Q->rear->next=s->next;  //这块的话我还需要在考虑下
    return true;
    /*下方代码是参考代码
     Status EnQueue(LinkQueue *Q,QElemType e){
        QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
        if(!s)
        exit(OVERFLOW);
        s->data=e;
        s->next=NULL;
        Q->rear->next=s;
        Q->rear=s;
        return OK;
}
    */
}
Status GetHead(LinkQueue Q,ElemType *e){
    if(Q.front ==Q.rear) return false;
    *e = Q.front->next->data;
    return true;
}
Status DeQueue(LinkQueue *Q,ElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear) return false;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p) Q->rear=Q->front;
    free(p);
    return true;
}
Status Show(LinkQueue Q){
    QueuePtr p;
    p = Q.front->next;
    while(Q.rear!=p){
        printf("%d",p->data);
        p = p->next;
    }
    return true;
}
