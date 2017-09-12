#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include <iostream>

int right = 0;
int wrong = 0;

void add();/*加法运算*/
void addf();/*真分数加法运算*/
void minu();/*减法运算*/
void minuf();/*真分数减法运算*/
void mul();/*乘法运算*/
void mulf();/*真分数乘法运算*/
void di();/*除法运算*/
void dif();/*真分数除法运算*/
int common(int x, int y); /*求x,y的最大公约数*/
int lag();/*语言选择函数*/
int tag_fac();

int ag;
int tf;



void main()
{
	//Time t(0, 1, 0);
	//t.run();
	int choise;
    int con = 0;
	ag = lag();
	tf = tag_fac();
	if (ag)
	{
		std::cout << "\n" << "\t" << "\t" << "\t" << "小学简易四则运算" << "\n" << "\n";
	}
	else
	{
		std::cout << "\n" << "\t" << "\t" << "Welcome to elementary school, simple four arithmetic" << "\n" << "\n";
	}
	
	while (1)
	{
		if (ag)
		{
            std::cout<<"请选择："<<"\n";
			std::cout << "\t" << "\t" << "\t" << "加法运算（请输入1)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "减法运算（请输入2)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "乘法运算（请输入3)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "除法运算（请输入4)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "退出运算（请输入5)" << "\n";
		}
		else
		{
			std::cout << "Please select ：" << "\n";
			std::cout << "\t" << "\t" << "\t" << "Addition operation (enter 1)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "Aubtraction operation (enter 2)"<< "\n";
			std::cout << "\t" << "\t" << "\t" << "Multiply operation (enter 3)"<< "\n";
			std::cout << "\t" << "\t" << "\t" << "Division operation (enter 4)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "Withdraw from (enter 5)" << "\n";

		}
		
		if (con == 0)
			std::cin >> choise;
		switch (choise)
		{
		case 1:
			if (tf)
			{
				add();
			}
			else
			{ 
			addf(); 
			}
			break;
		case 2:
			if (tf)
			{
				minu();
			}else
			{
                minuf();
			}			
			break;
		case 3:
			if (tf){
				mul();
			}
			else{
				mulf();
			}
			break;
		case 4:
			if (tf){
				di();
			}
			else{
				dif();
			}
			break;
		case 5:
			return;
		}
		if (ag)
		{
			std::cout << "\n" << "\t" << "\t" << "\t" << "继续运算？（请输入1）" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "重新运算？（请输入2）" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "退出运算？（请输入3）" << "\n";
		}
		else
		{
			std::cout << "\n" << "\t" << "\t" << "\t" << "Continue operation ？（enter 1）" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "Again operation？（enter 2）" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "Withdraw from？（enter 3）" << "\n";
		}
		std::cin >> con;
		if (con == 1)
			con = 1;
		else if (con == 2)
			con = 0;
		else if (con == 3)
			break;
		else
		if (ag)
		{
            std::cout<<"抱歉!你输入的指令有误!请重新输入!"<<"\n";
		}
		else
		{
			std::cout << "Sorry, the instruction you typed is incorrect. Please re-enter it!" << "\n";
		}	
	}
	if (ag)
	{
		std::cout << "您总共完成了" << right + wrong << "道题" << "\n" << "正确" << right << "道" << "\n" << "错误" << wrong << "道" << "\n";
	}
	else
	{
		std::cout << "You've finished << right + wrong "<< "question altogether"<< "\n" << " correct" << right << "question " << "\n" << " wrong" << wrong << "question " << "\n";
	}
}

void add()/*加法运算*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a << "+" <<b <<"= ";
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a << "+ "<<b<<" = ";
	}
	std::cin>>c;
	if (a + b == c)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

void addf()/*分数加法运算*/
{
	int a1, a2, b1, b2, x, y, j, k;
	srand((unsigned)time(NULL));
	a1 = rand() % 100;
	do{
		a2 = (rand() % 99) + 1;
	}while (a1 < a2);
	a1 = a1 / common(a1, a2);
	a2 = a2 / common(a1, a2);
	b1 = rand() % 100;
	do{
		b2 = (rand() % 99) + 1;
	} while (b1 < b2);
	b1 = b1 / common(b1, b2);
	b2 = b2 / common(b1, b2);
    x = a1*b2 + a2*b1;
	y = a2*b2;
	x = x / common(x, y);
	y = y / common(x, y);
	
	
	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a1<< "/"<< a2 << "+" << b1<<"/" <<b2<< "= "<<std::endl;
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "+" << b1 << "/" << b2 << "= "<<std::endl;
	}
	if (ag)
	{
        std::cout << "请输入分子:";
	    std::cin >>j;
	    std::cout << "请输入分母:";
	    std::cin >> k;
	    std::cout << "你的答案为:" << j << "/" << k<<std::endl;
	}
	else
	{
		std::cout << "Enter the molecule, please:";
		std::cin >> j;
		std::cout << "Enter the denominator, please:";
		std::cin >> k;
		std::cout << "Your answer is:" << j << "/" << k << std::endl;
	}
	
	if (j == x&&k == y)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}
void minu()/*减法运算*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a << "-" << b << "= ";
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a << "- " << b << " = ";
	}
	std::cin>>c;
	if (a - b == c)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		
		wrong++;
	}
}

void minuf()/*分数减法运算*/
{
	int a1, a2, b1, b2, x, y, j, k;
	srand((unsigned)time(NULL));
	a1 = rand() % 100;
	do{
		a2 = (rand() % 99) + 1;
	} while (a1 < a2);
	a1 = a1 / common(a1, a2);
	a2 = a2 / common(a1, a2);
	b1 = rand() % 100;
	do{
		b2 = (rand() % 99) + 1;
	} while (b1 < b2);
	b1 = b1 / common(b1, b2);
	b2 = b2 / common(b1, b2);
	x = a1*b2 - a2*b1;
	y = a2*b2;
	x = x / common(x, y);
	y = y / common(x, y);


	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "-" << b1 << "/" << b2 << "= " << std::endl;
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "-" << b1 << "/" << b2 << "= " << std::endl;
	}
	if (ag)
	{
		std::cout << "请输入分子:";
		std::cin >> j;
		std::cout << "请输入分母:";
		std::cin >> k;
		std::cout << "你的答案为:" << j << "/" << k << std::endl;
	}
	else
	{
		std::cout << "Enter the molecule, please:";
		std::cin >> j;
		std::cout << "Enter the denominator, please:";
		std::cin >> k;
		std::cout << "Your answer is:" << j << "/" << k << std::endl;
	}

	if (j == x&&k == y)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}


void mul()/*乘法运算*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a << "*" << b << "= ";
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a << "*" << b << " = ";
	}
	std::cin>>c;
	if (a*b == c)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}
void mulf()/*分数乘法运算*/
{
	int a1, a2, b1, b2, x, y, j, k;
	srand((unsigned)time(NULL));
	a1 = rand() % 100;
	do{
		a2 = (rand() % 99) + 1;
	} while (a1 < a2);
	a1 = a1 / common(a1, a2);
	a2 = a2 / common(a1, a2);
	b1 = rand() % 100;
	do{
		b2 = (rand() % 99) + 1;
	} while (b1 < b2);
	b1 = b1 / common(b1, b2);
	b2 = b2 / common(b1, b2);
	x = a1*b1;
	y = a2*b2;
	x = x / common(x, y);
	y = y / common(x, y);


	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "*" << b1 << "/" << b2 << "= " << std::endl;
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "*" << b1 << "/" << b2 << "= " << std::endl;
	}
	if (ag)
	{
		std::cout << "请输入分子:";
		std::cin >> j;
		std::cout << "请输入分母:";
		std::cin >> k;
		std::cout << "你的答案为:" << j << "/" << k << std::endl;
	}
	else
	{
		std::cout << "Enter the molecule, please:";
		std::cin >> j;
		std::cout << "Enter the denominator, please:";
		std::cin >> k;
		std::cout << "Your answer is:" << j << "/" << k << std::endl;
	}

	if (j == x&&k == y)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

void di()/*除法运算*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 99+1;/*不能出现等于0的情况*/
	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << a << "/" << b << "= ";
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << a << "/" << b << " = ";
	}
	std::cin >> c;
	if (a / b == c)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

void dif()/*分数除法运算*/
{
	int a1, a2, b1, b2, x, y,j,k;
	srand((unsigned)time(NULL));
	a1 = rand() % 100;
	do{
		a2 = (rand() % 99) + 1;
	} while (a1 < a2);
	a1 = a1 / common(a1, a2);
	a2 = a2 / common(a1, a2);
	b1 = rand() % 100;
	do{
		b2 = (rand() % 99) + 1;
	} while (b1 < b2);
	b1 = b1 / common(b1, b2);
	b2 = b2 / common(b1, b2);
	x = a1*b2 ;
	y = a1*b2;
	x = x / common(x, y);
	y = y / common(x, y);


	if (ag)
	{
		std::cout << "请回答：" << "\n" << "\t" << "\t" << "("<<a1 << "/" << a2 <<")"<<" / " <<"("<< b1 << "/" << b2 <<")"<< "= " << std::endl;
	}
	else
	{
		std::cout << " Please answer：" << "\n" << "\t" << "\t" << "(" << a1 << "/" << a2 << ")" << " / " << "(" << b1 << "/" << b2 << ")" << "= " << std::endl;
	}
	if (ag)
	{
		std::cout << "请输入分子:";
		std::cin >> j;
		std::cout << "请输入分母:";
		std::cin >> k;
		std::cout << "你的答案为:" << j << "/" << k << std::endl;
	}
	else
	{
		std::cout << "Enter the molecule, please:";
		std::cin >> j;
		std::cout << "Enter the denominator, please:";
		std::cin >> k;
		std::cout << "Your answer is:" << j << "/" << k << std::endl;
	}

	if (j == x&&k == y)
	{
		if (ag)
		{
			std::cout << "回答正确!" << "\n";
		}
		else
		{
			std::cout << "Answer right!" << "\n";
		}
		right++;
	}
	else
	{
		if (ag)
		{
			std::cout << "回答错误!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

int common(int x, int y) /*求x,y的最大公约数*/
{
	int r;
	while (y >0)
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}
int lag()/*语言选择*/
{
	int ag = 0;
	std::cout << "\t" << "请选择语言(Please select language):1.中文(Chinese ) 0.英文(English)" << std::endl;
	std::cin >> ag;
	return ag;
}
int tag_fac()/*整数分数选择*/
{
	int tf = 0;
	if (ag)
	{
		std::cout << "\t" << "请选择整数运算还是分数运算：1.整数  0.真分数" << std::endl;
	}
	else
	{
		std::cout << "\t" << "Select integer or fractional operation：1.integer  0.fraction" << std::endl;
	}
	std::cin >>tf;
	return tf;
}