// 欢迎使用
// b=1;
// a=1;
// a+1+1-b=
// result is :2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "lianbiao.h"
#include "evaluate.h"

#define SIZE_STR 50
#define SIZE_WORD 20

/* 获取一个句子 */
int s_get(char *str);

/* 获取一个单词 */
int word_get(char *dest_str,const char *str);

/* 删除单词 */
int word_del(int del,char *sou_str);



int main()
{
	List head=malloc(sizeof(Node ));
	head=create_fun_stack("hello word");
	char str[SIZE_STR];
	memset(str,0,sizeof(char )*SIZE_STR);
	char word[SIZE_WORD];
	memset(word,0,sizeof(char )*SIZE_WORD);
	
	printf("welcome!\n");
	printf("press '#' to end the programmer!\n");
	printf("egs:");
	printf("\ta=3;\n");
	printf("\tb=5;\n");
	printf("\ta+b+250=\n");
	printf("\tresult is :258\n");
	printf("\t#\n");
	printf("please always remember:\n");
	printf(":::if you use a undefined variable\n");
	printf(":::it will get a unexcepted rsult!\n");
	printf("press any key to start \n");
	getch();
	printf("please input some legal sentences finished with ';'\n");
	int KEY=1;
	while(KEY){
		int lenght=s_get(str);
		char case_ch=str[lenght-1];
		switch(case_ch)
		{
			case ';':
				str[lenght-1]='\0';
				lenght=word_get(word,str);
				add_fun_stack(head,word);
				word_del(lenght,str);
				while((32 == str[0]) || ('=' == str[0]))
					word_del(1,str);
				assign_fun_stack(head,word,calc(head,str));
				break;
				
			case '=':
				str[lenght-1]='\0';
				printf("result is :%d\n",calc(head,str));
				break;
			
			case '#':
				KEY=0;
			
		}
		memset(str,0,sizeof(char )*SIZE_STR);
		memset(word,0,sizeof(char )*SIZE_WORD);
	}
	
	
	
	
	
	
	free_fun_stack(head);
	return 0;
}

int s_get(char *str)
{
	int i=0;
	char ch;
	while('\n' != (ch=getchar())){
		str[i++]=ch;
	}
	str[i]='\0';
	return i;
}


int word_get(char *dest_str,const char *str)
{
	int i=0;
	int j=0;
	char ch;
	while(('=' != (ch=str[i++])) && (';' != ch)){
		if(32 == ch)
			continue;
		dest_str[j++]=ch;
	}
	dest_str[j]='\0';
	
	
	return j;
}

int word_del(int del,char *sou_str)
{
	char str[SIZE_STR];
	memset(str,0,sizeof(char )*SIZE_STR);
	
	char ch;
	int i=del;int j=0;
	while('\0' != (ch=sou_str[i++])){
		str[j++]=ch;
	}
	str[j]='\0';
	
	i=0;j=0;
	memset(sou_str,0,sizeof(char )*SIZE_STR);
	
	while('\0' != (ch=str[j++])){
		sou_str[i++]=ch;
	}
	sou_str='\0';
	
	return i;
}












