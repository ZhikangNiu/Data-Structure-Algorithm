//
// Created by DaisyN on 2021-07-21.
//
#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0
#define MAXSIZE 20
typedef int QElemType; //元素的数据类型，看情况而定
typedef int Status;
typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
}QueueOrder;
/*
InitQueue（*Q)：初始化操作，建立一个空队列Q.
DestroyQueue（*Q）：若队列存在，则销毁它。
ClearQueue（*Q)：将队列Q清空
QueueEmpty（Q)：若队列为空，返回true，否则返回false
GetHead（Q，*e）：若队列Q存在且非空，用e返回队列Q的队头元素。
EnQueue（*Q,e）：若队列Q存在，插入新元素e到队列Q中并成为队尾元素。
DeQueue（* Q,* e）：删除队列Q中队头元素，并用e返回其值。
QueueLength（Q)：返回队列Q的元素格数
 */
Status InitQueue(QueueOrder *Q){
    Q->front=0;
    Q->rear=0;
    return true;
}
Status ClearQueue(QueueOrder *Q){
    Q->front = 0;
    Q->rear = 0;
    return true;
}
int QueueLength(QueueOrder Q){
    if(Q.rear>=Q.front) return Q.rear-Q.front;
    else return Q.rear+MAXSIZE-Q.front;
    /*
     *return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
     */
}
Status QueueEmpty(QueueOrder Q){
   return (Q.rear == Q.front)? true:false; // 当且仅当均为0的时候相等
}
Status DestroyQueue(QueueOrder *Q){
    free(Q);
}
Status GetHead(QueueOrder Q,QElemType *e){
    if(Q.rear == Q.front) return false;
    *e = Q.data[Q.front];
}
Status EnQueue(QueueOrder *Q,QElemType e){
    if((Q->rear+1)%MAXSIZE == (Q->front)){
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE; //这个条件一定要记住,rear向后移一位
    return true;
}
Status DeQueue(QueueOrder *Q,QElemType *e){
    if(Q->rear == Q->front) return false;
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE; // front向后移动一位
    return true;

}
Status QueueShow(QueueOrder Q)
{
    int i=Q.front;
    if (i == Q.rear) return false;
    while((i+Q.front)!=Q.rear){
        printf("%d ",Q.data[i]);
        i=(i+1)%MAXSIZE;
    }
    printf("\n");
    return true;
}
int main()
{
    Status j;
    int i=0,l;
    QElemType d;
    QueueOrder Q;
    InitQueue(&Q);
    printf("------start------\n");
    printf("Empty?%u(1:Y 0:N)\n",QueueEmpty(Q));
    printf("-----------------\n");
    printf("please input the item of the queue until encounter (<=%d)\n",MAXSIZE-1);
    do{
        /* scanf("%d",&d); */
        d=i+100;
        if(d==-1)
            break;
        i++;
        EnQueue(&Q,d);
    }while(i<MAXSIZE-1);
    printf("-----------------\n");
    printf("Queue Length is %d now\n",QueueLength(Q));
    printf("Empty?%u(1:Y 0:N)\n",QueueEmpty(Q));
    printf("-----------------\n");
    printf("delete item from head to the end in range(%d),and insert item in the end:\n",MAXSIZE);
    for(l=1;l<=MAXSIZE;l++){
        DeQueue(&Q,&d);
        printf("Deleted item is %d,Inserted item is :%d \n",d,l+1000);
        /* scanf("%d",&d); */
        d=l+1000;
        EnQueue(&Q,d);
    }
    printf("-----------------\n");
    l=QueueLength(Q);
    printf("Now Queue has \n");
    QueueShow(Q);
    printf("the number of inserted items in all : %d\n",i+MAXSIZE);
    if(l-2>0) printf("Delete %d items:\n",l-2);
    while(QueueLength(Q)>2){
        DeQueue(&Q,&d);
        printf("Deleted item is %d\n",d);
    }

    j=GetHead(Q,&d);
    ClearQueue(&Q);
    printf("------cleaning------\n");
    printf("Empty?%u(1:Y 0:N)\n",QueueEmpty(Q));
    return 0;
}
