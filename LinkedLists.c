//这是一个关于链表的全面详细的代码
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkNode{//设置链表元素
    int data;
    struct LinkNode *pre;
    struct LinkNode *next;
}Node;

typedef struct LinkNode *LinkNode;

void InitList(LinkNode *L){//初始化操作，建立空链表
    int n;
    LinkNode head = (LinkNode*)malloc(sizeof(Node));
    head -> next = NULL;
    head -> pre = NULL;
    (*L) = head;
    printf ("创建的链表的长度是：");
    scanf ("%d", &n);
    for (int i = 0; i < n; i ++){
        LinkNode p = (LinkNode*)malloc(sizeof(Node));
        printf("请输入节点的内容：");
        scanf ("%d", &p -> data);
        (*L) -> next = p;
        p -> next = NULL;
        p -> pre = (*L);
        (*L) = p;
    }
    (*L) = head;
}
bool ListEmpty(LinkNode L){//若链表为空，返回true，否则返回false
    if (L -> next == NULL)
        return true;
    else
        return false;

}

void ClearList(LinkNode L){//将链表清空
    LinkNode p1, p2;
    p1 = L -> next;
    while (p1){
        p2 = p1 -> next;
        free(p1);
        p1 = p2;
    }
    L -> next = NULL;
}

void DestroyList(LinkNode *L){//将链表销毁

}

bool GetElem(LinkNode L, int i, int *e){//将链表L中第i个元素的值返回给e
    int j = 1;
    LinkNode p;
    p = L -> next;
    while (p && j < i){
        p = p -> next;
        j ++;
    }
    if (!p || j > i)
        return false;
    *e = p -> data;
    return true;
}

void LocateElem(LinkNode L, int e){//在链表L中查找与给定值e相等的元素，如果查找成功，返回改元素在表中的序号以表示成功，否则，返回0表示失败

}

void ListInsert(LinkNode *L, int i, int e){//在链表L中的第i个位置插入新元素e

}

void ListDelete(LinkNode *L, int i, int *e){//删除链表L中的第i个位置的元素，并用e返回其值

}

void Listlength(LinkNode L){//返回链表L的元素个数

}

void unionL(LinkNode *L, LinkNode L2){//将所有在链表L2中但不在L中的元素插入到L中

}

int main()
{
    LinkNode L;
    return 0;
}
