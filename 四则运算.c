#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include <iostream>

int right = 0;
int wrong = 0;

void add();/*�ӷ�����*/
void addf();/*������ӷ�����*/
void minu();/*��������*/
void minuf();/*�������������*/
void mul();/*�˷�����*/
void mulf();/*������˷�����*/
void di();/*��������*/
void dif();/*�������������*/
int common(int x, int y); /*��x,y�����Լ��*/
int lag();/*����ѡ����*/
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
		std::cout << "\n" << "\t" << "\t" << "\t" << "Сѧ������������" << "\n" << "\n";
	}
	else
	{
		std::cout << "\n" << "\t" << "\t" << "Welcome to elementary school, simple four arithmetic" << "\n" << "\n";
	}
	
	while (1)
	{
		if (ag)
		{
            std::cout<<"��ѡ��"<<"\n";
			std::cout << "\t" << "\t" << "\t" << "�ӷ����㣨������1)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "�������㣨������2)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "�˷����㣨������3)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "�������㣨������4)" << "\n";
			std::cout << "\t" << "\t" << "\t" << "�˳����㣨������5)" << "\n";
		}
		else
		{
			std::cout << "Please select ��" << "\n";
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
			std::cout << "\n" << "\t" << "\t" << "\t" << "�������㣿��������1��" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "�������㣿��������2��" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "�˳����㣿��������3��" << "\n";
		}
		else
		{
			std::cout << "\n" << "\t" << "\t" << "\t" << "Continue operation ����enter 1��" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "Again operation����enter 2��" << "\n";
			std::cout << "\n" << "\t" << "\t" << "\t" << "Withdraw from����enter 3��" << "\n";
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
            std::cout<<"��Ǹ!�������ָ������!����������!"<<"\n";
		}
		else
		{
			std::cout << "Sorry, the instruction you typed is incorrect. Please re-enter it!" << "\n";
		}	
	}
	if (ag)
	{
		std::cout << "���ܹ������" << right + wrong << "����" << "\n" << "��ȷ" << right << "��" << "\n" << "����" << wrong << "��" << "\n";
	}
	else
	{
		std::cout << "You've finished << right + wrong "<< "question altogether"<< "\n" << " correct" << right << "question " << "\n" << " wrong" << wrong << "question " << "\n";
	}
}

void add()/*�ӷ�����*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	if (ag)
	{
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a << "+" <<b <<"= ";
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a << "+ "<<b<<" = ";
	}
	std::cin>>c;
	if (a + b == c)
	{
		if (ag)
		{
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

void addf()/*�����ӷ�����*/
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
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a1<< "/"<< a2 << "+" << b1<<"/" <<b2<< "= "<<std::endl;
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "+" << b1 << "/" << b2 << "= "<<std::endl;
	}
	if (ag)
	{
        std::cout << "���������:";
	    std::cin >>j;
	    std::cout << "�������ĸ:";
	    std::cin >> k;
	    std::cout << "��Ĵ�Ϊ:" << j << "/" << k<<std::endl;
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
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}
void minu()/*��������*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	if (ag)
	{
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a << "-" << b << "= ";
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a << "- " << b << " = ";
	}
	std::cin>>c;
	if (a - b == c)
	{
		if (ag)
		{
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		
		wrong++;
	}
}

void minuf()/*������������*/
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
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "-" << b1 << "/" << b2 << "= " << std::endl;
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "-" << b1 << "/" << b2 << "= " << std::endl;
	}
	if (ag)
	{
		std::cout << "���������:";
		std::cin >> j;
		std::cout << "�������ĸ:";
		std::cin >> k;
		std::cout << "��Ĵ�Ϊ:" << j << "/" << k << std::endl;
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
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}


void mul()/*�˷�����*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 100;
	if (ag)
	{
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a << "*" << b << "= ";
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a << "*" << b << " = ";
	}
	std::cin>>c;
	if (a*b == c)
	{
		if (ag)
		{
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}
void mulf()/*�����˷�����*/
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
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "*" << b1 << "/" << b2 << "= " << std::endl;
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a1 << "/" << a2 << "*" << b1 << "/" << b2 << "= " << std::endl;
	}
	if (ag)
	{
		std::cout << "���������:";
		std::cin >> j;
		std::cout << "�������ĸ:";
		std::cin >> k;
		std::cout << "��Ĵ�Ϊ:" << j << "/" << k << std::endl;
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
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

void di()/*��������*/
{
	int a, b, c;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	b = rand() % 99+1;/*���ܳ��ֵ���0�����*/
	if (ag)
	{
		std::cout << "��ش�" << "\n" << "\t" << "\t" << a << "/" << b << "= ";
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << a << "/" << b << " = ";
	}
	std::cin >> c;
	if (a / b == c)
	{
		if (ag)
		{
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

void dif()/*������������*/
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
		std::cout << "��ش�" << "\n" << "\t" << "\t" << "("<<a1 << "/" << a2 <<")"<<" / " <<"("<< b1 << "/" << b2 <<")"<< "= " << std::endl;
	}
	else
	{
		std::cout << " Please answer��" << "\n" << "\t" << "\t" << "(" << a1 << "/" << a2 << ")" << " / " << "(" << b1 << "/" << b2 << ")" << "= " << std::endl;
	}
	if (ag)
	{
		std::cout << "���������:";
		std::cin >> j;
		std::cout << "�������ĸ:";
		std::cin >> k;
		std::cout << "��Ĵ�Ϊ:" << j << "/" << k << std::endl;
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
			std::cout << "�ش���ȷ!" << "\n";
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
			std::cout << "�ش����!" << "\n";
		}
		else
		{
			std::cout << "Wrong answer!" << "\n";
		}
		wrong++;
	}
}

int common(int x, int y) /*��x,y�����Լ��*/
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
int lag()/*����ѡ��*/
{
	int ag = 0;
	std::cout << "\t" << "��ѡ������(Please select language):1.����(Chinese ) 0.Ӣ��(English)" << std::endl;
	std::cin >> ag;
	return ag;
}
int tag_fac()/*��������ѡ��*/
{
	int tf = 0;
	if (ag)
	{
		std::cout << "\t" << "��ѡ���������㻹�Ƿ������㣺1.����  0.�����" << std::endl;
	}
	else
	{
		std::cout << "\t" << "Select integer or fractional operation��1.integer  0.fraction" << std::endl;
	}
	std::cin >>tf;
	return tf;
}