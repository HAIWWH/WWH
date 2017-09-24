#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<io.h>


int *getTotalNum(char *filename, int *totalNum);//对行数，单词数，字符数的统计
int *getLineNum(char *filename, int *linenum);//对行数的统计
int *getCharNum(char *filename, int *charnum);//对字符数的统计
int *getWordNum(char *filename, int *wordnum);//对单词数的统计
int* mixline(char *filename);//分别计算代码行，注释行和空行的统计
int main() {
	char filename[30];
	// totalNum[0]: 总行数  totalNum[1]: 总字符数  totalNum[2]: 总单词数
	int totalNum[3] = { 0, 0, 0 };
	int linenum, charnum, wordnum;

	printf("请输入路径及文件名(默认路径为项目路径): ");
	gets_s(filename);
	while (1)
	{
		system("cls");
		int choise;
		printf("1.行数（-l）\n");
		printf("2.字符数(-c)\n");
		printf("3.单词数(-w)\n");
		printf("4.行数、字符数、单词数汇总\n");
		printf("5.行分类及数量(-a)\n");
		printf("6.退出程序\n");
		printf("请输入你的选择:");
		scanf_s("%d", &choise);
		system("cls");
		switch (choise)
		{
		case 1:
			getLineNum(filename, &linenum);
			printf("行数：%d\n", linenum);
			system("pause");
			break;
		case 2:
			getCharNum(filename, &charnum);
			printf("字符数：%d\n", charnum);
			system("pause");
			break;
		case 3:
			getWordNum(filename, &wordnum);
			printf("单词数：%d\n", wordnum);
			system("pause");
			break;
		
		case 4:
			if (getTotalNum(filename, totalNum)) {
				printf("总共: %d 行, %d 个单词, %d 个字符\n", totalNum[0], totalNum[2], totalNum[1]);
			}
			else {
				printf("Error!\n");
			}
			system("pause");
			break;
		case 5:
			mixline(filename);
			system("pause");
			break;
		case 6:
			exit(0);
		default:
			break;
		}

	}

	system("pause");
	return 0;
}

/**
* 统计文件的字符数、单词数、行数
*
* @param  filename  文件名
* @param  totalNum  文件统计数据
*
* @return  成功返回统计数据，否则返回NULL
**/
int *getTotalNum(char *filename, int *totalNum) {
	FILE *fp;  // 指向文件的指针
	char buffer[1003];  //缓冲区，存储读取到的每行的内容
	int bufferLen;  // 缓冲区中实际存储的内容的长度
	int i;  // 当前读到缓冲区的第i个字符
	char c;  // 读取到的字符
	int isLastBlank = 0;  // 上个字符是否是空格
	int charNum = 0;  // 当前行的字符数
	int wordNum = 0; // 当前行的单词数

	if ((fp = fopen(filename, "rb")) == NULL) {
		perror(filename);
		return NULL;
	}

	printf("行   单词  字符\n");
	// 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
	while (fgets(buffer, 1003, fp) != NULL) {
		bufferLen = strlen(buffer);
		// 遍历缓冲区的内容
		for (i = 0; i<bufferLen; i++) {
			c = buffer[i];
			if (c == ' ' || c == '\t') {  // 遇到空格
				!isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
				isLastBlank = 1;
			}
			else if (c != '\n'&&c != '\r') {  // 忽略换行符
				charNum++;  // 如果既不是换行符也不是空格，字符数加1
				isLastBlank = 0;
			}
		}

		!isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
		isLastBlank = 1;  // 每次换行重置为1

		// 一行结束，计算总字符数、总单词数、总行数
		totalNum[0]++;  // 总行数
		totalNum[1] += charNum;  // 总字符数
		totalNum[2] += wordNum;  // 总单词数

		printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);

		// 置零，重新统计下一行
		charNum = 0;
		wordNum = 0;
	}

	return totalNum;
}

int* getLineNum(char *filename, int *linenum)
{
	FILE *fp;
	char buffer[1003];
	int count = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}
	while (fgets(buffer, 1003, fp) != NULL)
	{
		count++;
	}
	*linenum = count;

}

int *getCharNum(char *filename, int *charnum)
{
	FILE *fp;
	char buffer[1003];
	char c;
	int bufferLen;
	int i;
	int count = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}
	while (fgets(buffer, 1003, fp) != NULL)
	{
		bufferLen = strlen(buffer);
		for (i = 0; i< bufferLen; i++)
		{
			c = buffer[i];
			if (c != '\t'&&c != ' '&&c != '\n'&&c != '\r')
				count++;
		}
	}
	*charnum = count;


}

int *getWordNum(char *filename, int *wordnum)
{
	FILE *fp;
	char buffer[1003];
	int bufferLen;
	int i;
	char c;
	int isLastBlank = 0;
	int count = 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}
	while (fgets(buffer, 1003, fp) != NULL)
	{
		bufferLen = strlen(buffer);
		for (i = 0; i < bufferLen; i++)
		{
			c = buffer[i];
			if (c == ' ' || c == '\t')
			{
				!isLastBlank&&count++;
				isLastBlank = 1;
			}
			else
			{
				isLastBlank = 0;
			}
		}
		!isLastBlank&&count++;
		isLastBlank = 1;
	}
	*wordnum = count;
}

int* mixline(char *filename)
{
	FILE *fp;
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		perror(filename);
		return NULL;
	}
	int i = 0, blankline = 0, codeline = 0, noteline = 0;
	char sign;
	do{
		if (feof(fp))
			break;
		sign = fgetc(fp);
		if ((feof(fp)))
			break;
		while (sign == '\t' || sign == ' ')
			sign = fgetc(fp);
		if (sign == '\n')
		{
			sign = fgetc(fp);
			i = 1;
			while (sign == '\t' || sign == ' ')
				sign = fgetc(fp);
			if (sign == '\n')
			{
				blankline++;
				i = 0;
			}
			else if (sign == '}' || sign == '{')
			{
				sign = fgetc(fp);
				while (sign == '\t' || sign == ' ')
				{
					sign = fgetc(fp);
					i++;
				}
				if (sign == '\n')
				{
					blankline++;
					i = 0;
				}
				else if ((feof(fp)))
					blankline++;
				else
				{
					fseek(fp, -i, 1);
					i = 0;
				}
			}
			else
				fseek(fp, -1, 1);    //fseek()函数可以对文件指针进行操作，使指针向前或向后
		}
		else if (sign == '}' || sign == '/')
		{
			sign = fgetc(fp);
			while (sign == ' ' || sign == '\t')
				sign = fgetc(fp);
			if (sign == '/' || sign == '*')
			{
				noteline++;
				while (sign != '\n')
				{
					sign = fgetc(fp);
					if (feof(fp))
						break;
				}
				if (!(feof(fp)))
					fseek(fp, -1, 1);
			}
		}
		else
		{
			codeline++;
			while (sign != '\n')
				sign = fgetc(fp);
			fseek(fp, -1, 1);
		}

	} while (1);
	printf("文件空白行为: %d\n", blankline);
	printf("文件代码行为: %d\n", codeline);
	printf("文件注释行为: %d\n", noteline);
	rewind(fp);

	return 0;
}

