/* 
1：结构、结构指针

2:堆栈算法（先入后出/单向进出）
|   |
| 4 |
| 3 |
| 2 |
| 1 |
| 0 |
-----

3：表达式计算（四则运算）算法，支持括号。
4：递归算法
5：字符串分析、分拣算法

栈算法的用途：
1：类似函数调用过程的入口参数、局部变量的入栈，返回时候的局部变量、入口参数的出栈。
2：类似：“逐级进入/原路退出”的路径处理（寻找/尝试）。

*/

#include <ios>
#include <iostream>
#include <fstream>


//基本的堆栈（字符串数据）
struct stack
{
	//最多允许的数据个数
	int maxItem;
	//每个数据最大字节数
	int sizeofItem;
	//目前堆栈内数据个数
	int count;
	//目前栈顶数据的序号/指针（count-1）
	int ptr;
	//用来保存数据的字符串数组 char[MaxItem][sizeofItem]
	char**items;
};

//创建堆栈
stack* sk_create(int maxItem,int sizeofItem)
{
	stack*s=new stack();

	s->maxItem=maxItem;
	s->sizeofItem=sizeofItem;

	s->items=(char**)malloc(sizeof(char*)*s->maxItem);

	char*ptr=new char [ s->maxItem * s->sizeofItem];
	for(int i=0; i < s->maxItem; i++)
	{
		s->items[i] = ptr + i* s->sizeofItem;
	}
	s->count=0;
	s->ptr=-1;
	return s;
}

//释放堆栈
void sk_destory(stack*s)
{
	delete s->items[0];
	delete s;
}

//入栈
bool sk_push(stack*s,char*data)
{
	if(data==NULL || strlen(data) >= s->sizeofItem || s->count >= s->maxItem) return false;

	s->count++;
	s->ptr=s->count-1;

	strcpy_s(s->items[s->ptr], s->sizeofItem, data);
	return true;
}

//出栈
bool sk_pop(stack*s,char*data)
{
	if(data==NULL || s->count <=0) return false;

	strcpy_s(data, s->sizeofItem, s->items[s->ptr]);
	s->count--;
	s->ptr=s->count-1;
	return true;
}

//显示堆栈状态
void sk_display(stack*s)
{
	std::cout << "count=" << s->count << std::endl;
	std::cout << "ptr=" << s->ptr << std::endl;
	std::cout << "sizeofItem=" << s->sizeofItem << std::endl;
	std::cout << "maxItem=" << s->maxItem << std::endl;
	for(int i=s->count-1;i>=0;i--)
	{
		std::cout << "items[" << i << "]=[" << s->items[i] << "]" << std::endl;
	}
}
//你必须自己重写一遍上述代码，以熟练掌握算法。
//然后使用以下测试用例测试你的堆栈是否完全正确。
bool test_stack()
{
	stack* s=sk_create(10, 20);

	char tmp[201];

	int testcase=1;
	//std::cout << "Test case " << testcase << "failed:" << "" << std::endl;

	testcase=1;
	if(sk_pop(s, tmp)==true)
	{
		std::cout << "Test case " << testcase << " failed:" << "pop a empty stack should be disabled." << std::endl;
		return false;
	}

	testcase=2;
	if(sk_push(s, "hEllo123")==false)
	{
		std::cout << "Test case " << testcase << " failed:" << "sk_push into a empty stack failed." << std::endl;
		return false;
	}
	if(sk_pop(s, tmp)==false)
	{
		std::cout << "Test case " << testcase << " failed:" << "sk_pop one item stack failed." << std::endl;
		return false;
	}

	testcase=3;
	if(strcmp(tmp, "hEllo123")!=0)
	{
		std::cout << "Test case " << testcase << " failed:" << "sk_pop data error." << std::endl;
		return false;
	}

	if(sk_pop(s, tmp)==true)
	{
		std::cout << "Test case " << testcase << " failed:" << "pop a empty stack should be disabled." << std::endl;
		return false;
	}

	testcase=4;
	if(sk_push(s, "1234567890123456789")==false)
	{
		std::cout << "Test case " << testcase << " failed:" << "sk_push process size error (-1)." << std::endl;
		return false;
	}

	testcase=5;
	if(sk_push(s, "12345678901234567890")==true)
	{
		std::cout << "Test case " << testcase << " failed:" << "sk_push process size error (+1)." << std::endl;
		return false;
	}

	testcase=6;
	if(sk_push(s, "1234567890123456789012345678901234567890")==true)
	{
		std::cout << "Test case " << testcase << " failed:" << "sk_push process size error (+n)." << std::endl;
		return false;
	}

	testcase=7;
	if(sk_push(s, "1111")==false)
	{
		std::cout << "Test case " << testcase << " failed 1:" << "sk_push error." << std::endl;
		return false;
	}
	if(sk_push(s, "2222")==false)
	{
		std::cout << "Test case " << testcase << " failed 2:" << "sk_push error." << std::endl;
		return false;
	}
	if(sk_pop(s, tmp)==false)
	{
		std::cout << "Test case " << testcase << " failed 3:" << "sk_pop error." << std::endl;
		return false;
	}
	if(strcmp(tmp, "2222")!=0)
	{
		std::cout << "Test case " << testcase << " failed 4:" << "sk_pop data error." << std::endl;
		return false;
	}
	if(sk_pop(s, tmp)==false)
	{
		std::cout << "Test case " << testcase << " failed 5:" << "sk_pop last item error." << std::endl;
		return false;
	}
	if(strcmp(tmp, "1111")!=0)
	{
		std::cout << "Test case " << testcase << " failed 6:" << "sk_pop data error." << std::endl;
		return false;
	}

	testcase=8;
	if(sk_push(s, "")==false)
	{
		std::cout << "Test case " << testcase << " failed 1:" << "sk_push string of length=0 failed." << std::endl;
		return false;
	}
	if(sk_pop(s, tmp)==false)
	{
		std::cout << "Test case " << testcase << " failed 2:" << "sk_pop last item error." << std::endl;
		return false;
	}
	if(strcmp(tmp, "")!=0)
	{
		std::cout << "Test case " << testcase << " failed 3:" << "sk_pop string of length=0 error." << std::endl;
		return false;
	}

	testcase=9;
	//empty the stack
	while(sk_pop(s, tmp)==true);

	for(int i=0;i<s->maxItem;i++) 
	{
		if(sk_push(s, "1")==false)
		{
			std::cout << "Test case " << testcase << " failed 1:" << "sk_push item[" << i << "] failed (maxItem)." << std::endl;
			return false;
		}
	}
	if(sk_push(s, "x")==true)
	{
		std::cout << "Test case " << testcase << " failed 1:" << "sk_push maxItem error (+1)." << std::endl;
		return false;
	}


	sk_destory(s);

	std::cout << "TEST ALL CASES SUCCESSFULLY!!!" << std::endl;
	return true;
}

//四则运算

//是否为运算符
bool is_operator(char*str)
{
	return str[0]=='+'||str[0]=='-'||str[0]=='*'||str[0]=='/'||str[0]=='('||str[0]==')';
}

//字符串分析，读出一个数值或运算符
//注意read_one函数是采用int&引用类型处理index的，如果不支持引用类型，可以直接传地址。
bool read_one(char*str,int&index,char*sub)
{
	//如果是传地址，int* index为了后续代码方便，可以这样写：
	//读取：int ii=*index;
	//后续代码： ii++;
	//return前进行： *index=ii;

	int i=0;

	for(; str[index]!=0; index++)
	{
		if(is_operator(str+index))
		{
			if(i==0)
			{
				sub[i]=str[index];
				sub[++i]=0;
				index++;
			}
			break;
		}

		if(str[index] >= '0' && str[index] <= '9') 
		{
			sub[i]=str[index];
			sub[++i]=0;
			continue;
		}

		if(str[index] == '.')
		{
			sub[i]=str[index];
			sub[++i]=0;
			continue;
		}

		if(str[index] == ' ' || str[index] == '\t' || str[index] == '\r' || str[index] == '\n')
		{
			if(i>0){index++; break;}

			//自动忽略空白符
			continue;
		}

		return false;
	}

	return i>0;
}

//计算一次
void cal(stack*s)
{
	char d1[21];
	char d2[21];
	char op[21];

	//倒过来读操作数
	sk_pop(s,d2);//右操作数
	sk_pop(s,op);//运算符
	sk_pop(s,d1);//左操作数

	double res;

	switch(op[0])
	{
	case '+': res=atof(d1) + atof(d2); break;
	case '-': res=atof(d1) - atof(d2); break;
	case '*': res=atof(d1) * atof(d2); break;
	case '/': res=atof(d1) / atof(d2); break;
	}

	//运算结果入栈
	char tmp[21];
	sprintf_s(tmp,"%f",res);
	sk_push(s,tmp);

	//sk_display(s);
}

//完成不含括号的四则运算函数，返回结果。
//遇到括号按子表达式计算（递归），支持括号嵌套。
//不支持无效表达式，不进行表达式有效性检查。
float calculate(char*expression)
{
	//可递归函数设计方法/模式
	//1：在函数创建/销毁内存/结构/对象，尽量使用局部变量，不传到外部，也就是【自治的结构】
	//2：对外的联系仅通过入口参数和返回值，而且一般不修改入口参数（即使传指针）
	//3：不在方法内输出/显示，仅作为“函数/处理代码”使用。
	stack* s=sk_create(100,20);

	//表达式顺序分析的当前位置
	int index=0;
	char tmp[201];

	char op[21];
	bool ready=false;

	int qs=0;
	int qstart=0;
	int qsend=0;
	float res;

	//第一次循环：读出每一个数值或运算符，入栈；对于优先运算符（*/）和数值，立即计算（在栈顶的三个项）中间结果入栈。
	//注意read_one函数是采用int&引用类型处理index的，如果不支持引用类型，可以直接传地址。
	while(read_one(expression,index,tmp))
	{
		if(tmp[0]=='(')
		{
			//read_one always move index to next data.
			if(qs==0) qstart=index-1;

			qs++;
			continue;
		}

		if(tmp[0]==')')
		{
			qs--;

			if(qs==0) 
			{
				//read_one always move index to next data.
				qsend=index-1;

				//get the the inner part of (....), remove ( and ).
				qstart++;
				qsend--;
				char subexp[201];
				strncpy_s(subexp, 201, expression + qstart, qsend - qstart + 1);
				//std::cout << "[" << subexp << "]" << std::endl;

				//递归调用当前的函数，直接返回计算结果，计算过程也创建了一个堆栈。
				res=calculate(subexp);

				//中间结果入栈
				sprintf_s(tmp,201,"%f",res);
				sk_push(s,tmp);
			}

			//display(s);
			continue;
		}

		//seeking ) of sub expression. 
		//(...)的处理过程不【污染】当前这个堆栈——这得真个函数只要处理【没有括号的四则运算】。
		if(qs>0)
		{
			continue;
		}



		if(is_operator(tmp))
		{
			strcpy_s(op,21,tmp);			
		}
		else
		{
			if(op[0]=='*' || op[0]=='/')
			{
				ready=true;
			}
		}

		sk_push(s,tmp);	

		if(ready)
		{	
			cal(s);
			ready=false;
		}
	}

	//完成第二优先级的运算（+-），没有按照从左到右的顺序，而是从右到左，但是不影响最终结果。
	//如果要确保同优先级的计算是从左到右的顺序，必须这时进行“倒栈”，或改为“先进先出”。
	while(s->count >= 3)
	{
		cal(s);
	}

	//计算完成，堆栈一定只有一项——计算结果。
	res=atof(s->items[0]);

	std::cout << std::endl << "last result=" << s->items[0] << std::endl;

	//display(s);

	//销毁堆栈
	sk_destory(s);	

	return res;
}