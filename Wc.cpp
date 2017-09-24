#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<io.h>


int *getTotalNum(char *filename, int *totalNum);//�����������������ַ�����ͳ��
int *getLineNum(char *filename, int *linenum);//��������ͳ��
int *getCharNum(char *filename, int *charnum);//���ַ�����ͳ��
int *getWordNum(char *filename, int *wordnum);//�Ե�������ͳ��
int* mixline(char *filename);//�ֱ��������У�ע���кͿ��е�ͳ��
int main() {
	char filename[30];
	// totalNum[0]: ������  totalNum[1]: ���ַ���  totalNum[2]: �ܵ�����
	int totalNum[3] = { 0, 0, 0 };
	int linenum, charnum, wordnum;

	printf("������·�����ļ���(Ĭ��·��Ϊ��Ŀ·��): ");
	gets_s(filename);
	while (1)
	{
		system("cls");
		int choise;
		printf("1.������-l��\n");
		printf("2.�ַ���(-c)\n");
		printf("3.������(-w)\n");
		printf("4.�������ַ���������������\n");
		printf("5.�з��༰����(-a)\n");
		printf("6.�˳�����\n");
		printf("���������ѡ��:");
		scanf_s("%d", &choise);
		system("cls");
		switch (choise)
		{
		case 1:
			getLineNum(filename, &linenum);
			printf("������%d\n", linenum);
			system("pause");
			break;
		case 2:
			getCharNum(filename, &charnum);
			printf("�ַ�����%d\n", charnum);
			system("pause");
			break;
		case 3:
			getWordNum(filename, &wordnum);
			printf("��������%d\n", wordnum);
			system("pause");
			break;
		
		case 4:
			if (getTotalNum(filename, totalNum)) {
				printf("�ܹ�: %d ��, %d ������, %d ���ַ�\n", totalNum[0], totalNum[2], totalNum[1]);
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
* ͳ���ļ����ַ�����������������
*
* @param  filename  �ļ���
* @param  totalNum  �ļ�ͳ������
*
* @return  �ɹ�����ͳ�����ݣ����򷵻�NULL
**/
int *getTotalNum(char *filename, int *totalNum) {
	FILE *fp;  // ָ���ļ���ָ��
	char buffer[1003];  //���������洢��ȡ����ÿ�е�����
	int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
	int i;  // ��ǰ�����������ĵ�i���ַ�
	char c;  // ��ȡ�����ַ�
	int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
	int charNum = 0;  // ��ǰ�е��ַ���
	int wordNum = 0; // ��ǰ�еĵ�����

	if ((fp = fopen(filename, "rb")) == NULL) {
		perror(filename);
		return NULL;
	}

	printf("��   ����  �ַ�\n");
	// ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
	while (fgets(buffer, 1003, fp) != NULL) {
		bufferLen = strlen(buffer);
		// ����������������
		for (i = 0; i<bufferLen; i++) {
			c = buffer[i];
			if (c == ' ' || c == '\t') {  // �����ո�
				!isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
				isLastBlank = 1;
			}
			else if (c != '\n'&&c != '\r') {  // ���Ի��з�
				charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
				isLastBlank = 0;
			}
		}

		!isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
		isLastBlank = 1;  // ÿ�λ�������Ϊ1

		// һ�н������������ַ������ܵ�������������
		totalNum[0]++;  // ������
		totalNum[1] += charNum;  // ���ַ���
		totalNum[2] += wordNum;  // �ܵ�����

		printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);

		// ���㣬����ͳ����һ��
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
				fseek(fp, -1, 1);    //fseek()�������Զ��ļ�ָ����в�����ʹָ����ǰ�����
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
	printf("�ļ��հ���Ϊ: %d\n", blankline);
	printf("�ļ�������Ϊ: %d\n", codeline);
	printf("�ļ�ע����Ϊ: %d\n", noteline);
	rewind(fp);

	return 0;
}

