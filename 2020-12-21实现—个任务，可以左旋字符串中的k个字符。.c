//字符串左旋题目内容:
//实现—个任务，可以左旋字符串中的k个字符。
//例如 :
//ABCD左旋一个字符得到BCDA，ABCD左旋两个字符得到CDAB，判断cdab是不是abcd的左旋而来
//abcdef
//bcdefa
//cdefab
//defabc
//efabcd
//fabcde
//abcdef
#include<stdio.h>
#include<assert.h>
#include<string.h>
void left_move(char* left, int k)
{
	assert(left);
	int len1 = strlen(left);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		int j = 0;
		char tem = *left;
		for (j = 0; j < len1 - 1; j++)
		{
			*(left + j) = *(left + j + 1);
		}
		*(left + len1 - 1) = tem;
	}
	//printf("%s",*left);
}
int left_roate(char* prt1, char* prt2)
{
	int len = strlen(prt1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(prt1,1);//调用此函数后，不需要返回值，直接进行左旋
		if(strcmp(prt1,prt2)==0)
		   return 1;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int  ret=left_roate(arr1,arr2);
	if (ret == 1)
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
