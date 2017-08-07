#ifndef _EVALUATE_H_
#define _EVALUATE_H_

#include<stdbool.h>


#define SIZE 20
#define SIZE_1 100//一句话
#define SIZE_2 20//一个词




bool is_ch(const char ch);

void add(char* str);

/* 操作：优先级比较 1<2,返回true，即，直接入栈 */
/* 入栈时，temp_1为栈内元素，temp_2为栈外元素 */
bool compare_priority(char temp_1,char temp_2);

int add_ch(char *word_ch,int *i,char *word,int *k,int n);

int initialize(char *word_sym,int *i,int n);

int sort(char *word_ch,int *i,const char *str,int *k);





int search_num(List head,char* word);

/* 加减乘除运算函数 */
int yunsuan(int a,char ch,int b);

int calc(List head,char* str);


                                 





#endif