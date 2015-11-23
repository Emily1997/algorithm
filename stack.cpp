/* 
1���ṹ���ṹָ��

2:��ջ�㷨��������/���������
|   |
| 4 |
| 3 |
| 2 |
| 1 |
| 0 |
-----

3�����ʽ���㣨�������㣩�㷨��֧�����š�
4���ݹ��㷨
5���ַ����������ּ��㷨

ջ�㷨����;��
1�����ƺ������ù��̵���ڲ������ֲ���������ջ������ʱ��ľֲ���������ڲ����ĳ�ջ��
2�����ƣ����𼶽���/ԭ·�˳�����·������Ѱ��/���ԣ���

*/

#include <ios>
#include <iostream>
#include <fstream>


//�����Ķ�ջ���ַ������ݣ�
struct stack
{
	//�����������ݸ���
	int maxItem;
	//ÿ����������ֽ���
	int sizeofItem;
	//Ŀǰ��ջ�����ݸ���
	int count;
	//Ŀǰջ�����ݵ����/ָ�루count-1��
	int ptr;
	//�����������ݵ��ַ������� char[MaxItem][sizeofItem]
	char**items;
};

//������ջ
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

//�ͷŶ�ջ
void sk_destory(stack*s)
{
	delete s->items[0];
	delete s;
}

//��ջ
bool sk_push(stack*s,char*data)
{
	if(data==NULL || strlen(data) >= s->sizeofItem || s->count >= s->maxItem) return false;

	s->count++;
	s->ptr=s->count-1;

	strcpy_s(s->items[s->ptr], s->sizeofItem, data);
	return true;
}

//��ջ
bool sk_pop(stack*s,char*data)
{
	if(data==NULL || s->count <=0) return false;

	strcpy_s(data, s->sizeofItem, s->items[s->ptr]);
	s->count--;
	s->ptr=s->count-1;
	return true;
}

//��ʾ��ջ״̬
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
//������Լ���дһ���������룬�����������㷨��
//Ȼ��ʹ�����²�������������Ķ�ջ�Ƿ���ȫ��ȷ��
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

//��������

//�Ƿ�Ϊ�����
bool is_operator(char*str)
{
	return str[0]=='+'||str[0]=='-'||str[0]=='*'||str[0]=='/'||str[0]=='('||str[0]==')';
}

//�ַ�������������һ����ֵ�������
//ע��read_one�����ǲ���int&�������ʹ���index�ģ������֧���������ͣ�����ֱ�Ӵ���ַ��
bool read_one(char*str,int&index,char*sub)
{
	//����Ǵ���ַ��int* indexΪ�˺������뷽�㣬��������д��
	//��ȡ��int ii=*index;
	//�������룺 ii++;
	//returnǰ���У� *index=ii;

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

			//�Զ����Կհ׷�
			continue;
		}

		return false;
	}

	return i>0;
}

//����һ��
void cal(stack*s)
{
	char d1[21];
	char d2[21];
	char op[21];

	//��������������
	sk_pop(s,d2);//�Ҳ�����
	sk_pop(s,op);//�����
	sk_pop(s,d1);//�������

	double res;

	switch(op[0])
	{
	case '+': res=atof(d1) + atof(d2); break;
	case '-': res=atof(d1) - atof(d2); break;
	case '*': res=atof(d1) * atof(d2); break;
	case '/': res=atof(d1) / atof(d2); break;
	}

	//��������ջ
	char tmp[21];
	sprintf_s(tmp,"%f",res);
	sk_push(s,tmp);

	//sk_display(s);
}

//��ɲ������ŵ��������㺯�������ؽ����
//�������Ű��ӱ��ʽ���㣨�ݹ飩��֧������Ƕ�ס�
//��֧����Ч���ʽ�������б��ʽ��Ч�Լ�顣
float calculate(char*expression)
{
	//�ɵݹ麯����Ʒ���/ģʽ
	//1���ں�������/�����ڴ�/�ṹ/���󣬾���ʹ�þֲ��������������ⲿ��Ҳ���ǡ����εĽṹ��
	//2���������ϵ��ͨ����ڲ����ͷ���ֵ������һ�㲻�޸���ڲ�������ʹ��ָ�룩
	//3�����ڷ��������/��ʾ������Ϊ������/������롱ʹ�á�
	stack* s=sk_create(100,20);

	//���ʽ˳������ĵ�ǰλ��
	int index=0;
	char tmp[201];

	char op[21];
	bool ready=false;

	int qs=0;
	int qstart=0;
	int qsend=0;
	float res;

	//��һ��ѭ��������ÿһ����ֵ�����������ջ�����������������*/������ֵ���������㣨��ջ����������м�����ջ��
	//ע��read_one�����ǲ���int&�������ʹ���index�ģ������֧���������ͣ�����ֱ�Ӵ���ַ��
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

				//�ݹ���õ�ǰ�ĺ�����ֱ�ӷ��ؼ��������������Ҳ������һ����ջ��
				res=calculate(subexp);

				//�м�����ջ
				sprintf_s(tmp,201,"%f",res);
				sk_push(s,tmp);
			}

			//display(s);
			continue;
		}

		//seeking ) of sub expression. 
		//(...)�Ĵ�����̲�����Ⱦ����ǰ�����ջ��������������ֻҪ����û�����ŵ��������㡿��
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

	//��ɵڶ����ȼ������㣨+-����û�а��մ����ҵ�˳�򣬶��Ǵ��ҵ��󣬵��ǲ�Ӱ�����ս����
	//���Ҫȷ��ͬ���ȼ��ļ����Ǵ����ҵ�˳�򣬱�����ʱ���С���ջ�������Ϊ���Ƚ��ȳ�����
	while(s->count >= 3)
	{
		cal(s);
	}

	//������ɣ���ջһ��ֻ��һ�����������
	res=atof(s->items[0]);

	std::cout << std::endl << "last result=" << s->items[0] << std::endl;

	//display(s);

	//���ٶ�ջ
	sk_destory(s);	

	return res;
}