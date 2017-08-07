#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "lianbiao.h"









/*------------------------------------------------------------------------------------*/
/*                                                                           局部函数 */
/* 句子复制函数 */ //n为长度
void copy_sentence_(char* destination,const char* source,int n)
{
	
	int j=0;
	while((n > j) && (destination[j] = source[j++]))
		// 以定长或空结尾
		continue;//比对关键字
	destination[n]='\0';
}
/* 句子比较函数 */ 
bool compare_sentence_(const char* destination,const char* source)
{
	int j=0;
	while(('\0' != destination[j]) && (destination[j] == source[j]))
		// 以定长或空结尾
		j++;//比对关键字
	
	if('\0' == source[j])
		return true;
	else 
		return false;
}


/*------------------------------------------------------------------------------------*/
/*                                                                       链表所用函数 */
/* 操作：创建一个链表 */
/*前置条件：*tmp_var_name指向名称数组，ymp_var_length即为长度*/
List create_fun_stack(const char* tmp_var_name)
{
	int tmp_var_length=0;
	while('\0' != tmp_var_name[tmp_var_length++])
		continue;
	tmp_var_length-=1;
	
	
	List head_copy;
	head_copy=(List )malloc(sizeof(Node ));
	if(NULL == head_copy)
		return NULL;
	memset(head_copy->var.var_name,0,sizeof(char)*SIZE);
	copy_sentence_(head_copy->var.var_name,tmp_var_name,tmp_var_length);
	head_copy->var.var_length=tmp_var_length;
	head_copy->next=NULL;
	return head_copy;
}





/* 操作：新加入项 */
List add_fun_stack(const List head,char* tmp_var_name)
{
	int tmp_var_length=0;
	while('\0' != tmp_var_name[tmp_var_length++])
		continue;
	tmp_var_length-=1;
	
	
	
	List padd=(List )malloc(sizeof(Node ));
	if(NULL == padd)
		return padd;
	List padd_seek=head;
	
	while(NULL != padd_seek->next)
		padd_seek=padd_seek->next;
	
	padd_seek->next=padd;
	
	
	
	copy_sentence_(padd->var.var_name,tmp_var_name,tmp_var_length);
	
	padd->var.var_length=tmp_var_length;
	
	padd->next=NULL;

	
	return padd;
}





/* 操作：链表查找 */
/* 前置条件：*seek_var_name指向所需查找的内容 */
/* 后置条件：返回所查询内容所在节点链表的指针 */
/* 危险：如果将两个字符串直接比较有潜在危险 */
List seek_fun_stack(const List head,const char* seek_var_name)
{
	List p_seek=head;
	/* 直接比对所有 */
	
	while( (NULL != p_seek) && (true != compare_sentence_(seek_var_name,p_seek->var.var_name)) )
		p_seek=p_seek->next;
	return p_seek;
	/* 没有找到返回空 */
}


/* 赋值 */
List assign_fun_stack(const List head,const char* seek_var_name,const int value)
{

	List p_seek=head;
	
	/* 直接比对所有 */
	while( (p_seek) && (true != compare_sentence_(seek_var_name,p_seek->var.var_name)))
		p_seek=p_seek->next;
	
	p_seek->var.var_value=(NULL == p_seek) ? 0 : value;
	
	return p_seek;
	/* 没有找到返回空 */
}



/* 操作：释放内存 */
void free_fun_stack(List head)
{
	List free_tmp_1=head;
	List free_tmp_2=head->next;
	while(NULL != free_tmp_2)
	{
		free(free_tmp_1);
		free_tmp_1=free_tmp_2;
		free_tmp_2=free_tmp_2->next;
	}
	free(free_tmp_1);
}
/*------------------------------------------------------------------------------------*/





