////////////hello+3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "lianbiao.h"
#include "evaluate.h"



/* 处理成可计算 */
bool is_ch(const char ch)
{
	if(
		('_' == ch) 
		||	('A' <= ch && 'Z' >= ch) 
		||  ('a' <= ch && 'z' >= ch) 
		||  ('0'<= ch && ch <= '9')
	  )	return true;
	else return false;
}
/* 加冒号 */
////////////hello+3
////////////hello:+:3:
void add(char* str)
{
	char str_tmp[SIZE_1];
	memset(str_tmp,0,sizeof(char)*SIZE_1);
	
	
	/* 添加 */
	int i=0;
	int j=0;
	char key='a';
	char ch;
	while('\0' != (ch=str[i++]))
	{
		/* 消空格 */
		if(32 == ch)
			continue;
		
	
		
		if(false == is_ch(ch))
		  {
			  str_tmp[j++]=':';
			  str_tmp[j++]=ch;
		  }
		else if(false == is_ch(key))
		{
			str_tmp[j++]=':';
			str_tmp[j++]=ch;
		}
		else if(true == is_ch(key))
			str_tmp[j++]=ch;
		
		key=ch;
	}
	str_tmp[j]=':';
	
	
	
	
	int i_i=0;
	if(':' == str_tmp[0])
		i_i=1;
	
	/* 转移 */
	i=0;
	while('\0' != (str[i]=str_tmp[(i++)+i_i]))
		continue;
}

/* 操作：优先级比较 1<2,返回true，即，直接入栈 */
/* 入栈时，temp_1为栈内元素，temp_2为栈外元素 */
bool compare_priority(char temp_1,char temp_2)
{
	/* 入栈时：
	   栈内：( 小于 + - 小于 * / 小于 ) 栈外 */
	if('#' == temp_1 )//栈内为空时,或栈外为冒号
		return true;
	else if(temp_1 == temp_2)//相同时
		return false;
	else if(('+' == temp_1 || '-' == temp_1) && ('+' == temp_2 || '-' == temp_2))//加减优先顺序
		return false;
	else if(('*' == temp_1 || '/' == temp_1) && ('*' == temp_2 || '/' == temp_2))//乘除优先顺序
		return false;
	else if(('+' == temp_1 || '-' == temp_1) && ('*' == temp_2 || '/' == temp_2))
		/* 加减小于乘除 */
		return true;
	else if(('+' == temp_2 || '-' == temp_2) && ('*' == temp_1 || '/' == temp_1))
		/* 乘除大于加减 */
		return false;
}

int add_ch(char *word_ch,int *i,char *word,int *k,int n)
{
	
	int i_i=0;
	for(;i_i<n;i_i++)
		word_ch[(*i)++]=word[i_i+(*k)];
	
	return (i_i-(*k));
}
int initialize(char *word_sym,int *i,int n)
{
	int i_i=0;
	
	for(;i_i<n;i_i++)
		word_sym[(*i)++]='\0';
	
}
int sort(char *word_ch,int *i,const char *str,int *k)
{
	/* 简单的动作而已 */
	/* 在按指定分配的情况下，是指针的位置不错 */
	char word[SIZE_2];int tmp_i=0;
	memset(word,0,sizeof(char)*SIZE_2);
	
	char word_sym[SIZE_1];int j=0;
	memset(word_sym,0,sizeof(char)*SIZE_1);
	word_sym[j++]='#';word_sym[j++]=':';
	
	char ch;int n=0;int zero=0;
	/* 每次只获取一个词语 */
	while('\0' != (ch=word[tmp_i++]=str[(*k)++])){
		if(':' != ch)	continue;//获取一个词
		
		n=tmp_i;
		if(true == is_ch(word[0]))
			add_ch(word_ch,i,word,&zero,n);
		else if('(' == word[0])
			sort(word_ch,i,str,k);
		else if(')' == word[0]){
			tmp_i=0;
			memset(word,0,sizeof(char)*SIZE_2);
			j-=2;
			while('#' != (ch=word[tmp_i++]=word_sym[j++])){
				if(':' != ch)	continue;//获取一个词
				n=tmp_i;
				add_ch(word_ch,i,word,&zero,2);
				j-=4;}
			return 0;}		
		else{
			if(true == compare_priority(word_sym[j-2],word[0]))
				add_ch(word_sym,&j,word,&zero,n);
			else{
				while(false == compare_priority(word_sym[j-2],word[0])){
					/* 左移 */
					j-=2;
					add_ch(word_ch,i,word_sym,&j,2);
					j+=2;
				
					/* 滞空 */
					j-=2;
					initialize(word_sym,&j,2);
					j-=2;}
				
				/* 添加 */
				add_ch(word_sym,&j,word,&zero,n);}}		
		tmp_i=0;
		memset(word,0,sizeof(char)*SIZE_2);}
		
		tmp_i=0;
		memset(word,0,sizeof(char)*SIZE_2);
		
		j-=2;
		while('#' != (ch=word[tmp_i++]=word_sym[j++])){
			if(':' != ch)	continue;//获取一个词
			n=tmp_i;
			add_ch(word_ch,i,word,&zero,2);
			j-=4;
			tmp_i=0;
			memset(word,0,sizeof(char)*SIZE_2);}
	return 0;
}








int search_num(List head,char* word)
{
	List p_tmp;
	int num=0;
	if(('0'<= word[0] && word[0] <= '9'))
	{
		int i=0;char ch;
		while('\0' != (ch=word[i++]))
			num=num*10+ch-48;
	}
	else
	{
		if(NULL != (p_tmp=seek_fun_stack(head,word)))
			num=p_tmp->var.var_value;
		else 
			exit(1);
	}
		
	return num;
}


/* 加减乘除运算函数 */
int yunsuan(int a,char ch,int b)
{
	switch(ch)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}


int calc(List head,char* str)
{
	add(str);
	// /* --                                                        */printf(str);printf("\n");
	
	char word_ch[SIZE_1];int i=0;
	memset(word_ch,0,sizeof(char)*SIZE_1);
	
	int k=0;
	sort(word_ch,&i,str,&k);
	i=0;
	
	// /* --                                                        */printf(word_ch);printf("\n");
	
	
	
	char ch;
	char word[SIZE_2];int tmp_i=0;
	memset(word,0,sizeof(char)*SIZE_2);
	
	int num[SIZE_2];int num_i=0;
	memset(num,0,sizeof(int )*SIZE_2);
	
	
	while('\0' != (ch=word[tmp_i++]=word_ch[i++])){
		if(':' != ch)	continue;
		word[tmp_i-1]='\0';
		if(true == is_ch(word[0]))
			num[num_i++]=search_num(head,word);
		else{
			num[num_i-2]=yunsuan(num[num_i-2],word[0],num[num_i-1]);
			num[num_i-1]='\0';
			num_i-=1;}
		
		tmp_i=0;
		memset(word,0,sizeof(char)*SIZE_2);}
	
	return num[0];
}



