#ifndef _LIANBIAO_H_
#define _LIANBIAO_H_

#include<stdbool.h>


#define SIZE 20

/* ---------------------------------------------------------------------------------- */
/* 定义全局的结构体变量 */
/* 变量池 */
struct Var
{
	char var_name[SIZE];
	int var_length;
	int var_value;
};//定义变量节点
typedef struct Var Item;
typedef struct node
{
	Item var;
	struct node* next;
} Node;//读取变量的链表
typedef Node* List;//定义结构体变量指针

/*                                       头文件                                      */
/*------------------------------------------------------------------------------------*/
/*                                                                       链表所用函数 */
/* 操作：创建一个链表 */
/*前置条件：*tmp_var_name指向名称数组，ymp_var_length即为长度*/
List create_fun_stack(const char* tmp_var_name);

/* 操作：新加入项 */
List add_fun_stack(const List head,char* tmp_var_name);

/* 操作：链表查找 */
/* 前置条件：*seek_var_name指向所需查找的内容 */
/* 后置条件：返回所查诈骗内容所在节点链表的指针 */
List seek_fun_stack(const List head,const char* seek_var_name);



/* 操作：为链表项赋值 */
List assign_fun_stack(List head,const char* seek_var_name,const int value);

/* 操作：释放内存 */
void free_fun_stack(List head);

/* 句子复制 */
void copy_sentence_(char* destination,const char* source,int n);

/* 句子比较 */
bool compare_sentence_(const char* destination,const char* source);


#endif