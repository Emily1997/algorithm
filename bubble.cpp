/* 
   冒泡排序法【字符串/字符/数值排序】
*/

#include <ios>
#include <iostream>

//冒泡算法的内外循环
void bubble_sort(int Count)
{
	//不管升序还是降序都如此，这是最节省的循环次数！
	//假设Count为5，依次进行一下：

	//4-3,3-2,2-1,1-0    low=4 to 1, 比较4次完成后，位置0：是次最小值（升序）/次最大值（降序）
	//4-3,3-2,2-1        low=4 to 2, 比较3次完成后，位置1：是次最小值（升序）/次最大值（降序）
	//4-3,3-2            low=4 to 3, 比较2次完成后，位置2：是次最小值（升序）/次最大值（降序）
	//4-3                low=4 to 4, 比较1次完成后，位置3：是次最小值（升序）/次最大值（降序） 位置4：是次最小值（升序）/次最大值（降序）

	//也就是说内循环总是从Count-1开始，结束位置依次为：1，2,3,4（即【1】 到 【Count-1】）

	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{
		}
	}
}

//数值数组排序（采用冒泡法，直接改变输入的数组）
//values：数值数组指针（char*/int*/float*/double*/__int64*等值类型完全一致）
//Count：数值个数
//Accending：是否正序排列
void sort_values_1(int*values,int Count,bool Ascending)
{
	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{

			//是否需要交换
			//if((Ascending && values[low]<values[low-1])||(Ascending==false && values[low]>values[low-1]))
			if(Ascending == (values[low]<values[low-1]))
			{
				//确保临时变量的类似和被交换的数据类似完全一致！
				int tmp=values[low];
				values[low]=values[low-1];
				values[low-1]=tmp;
			}
		}
		std::cout << top-1 << ":" << values[top-1] << std::endl;
	}
}
//数值数组排序（采用冒泡法，直接改变输入的数组）
//values：数值数组指针（char*/int*/float*/double*/__int64*等值类型完全一致）
//Count：数值个数
//Accending：是否正序排列
//返回值：已经排序过的数值数组的指针（调用方负责释放内存）
int* sort_values_2(int*values,int Count,bool Ascending)
{
	//这里申请内容，返回给调用者，调用者负责delete此空间！
	//申请Count地址的数组（保存int的数组）
	int* sortedValuesPtr=(int*) malloc(sizeof(int)*Count);

	//把原始的字符串的指针复制返回数组
	//因为冒泡法是在【数组内不断交换数据】来排序的，即必须直接改变被排序的数组。
	for(int i=0; i<Count; i++) sortedValuesPtr[i]=values[i];


	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{
			//是否需要交换
			//if((Ascending && sortedValuesPtr[low]<sortedValuesPtr[low-1])||(Ascending==false && sortedValuesPtr[low]>sortedValuesPtr[low-1]))
			if(Ascending == (sortedValuesPtr[low]<sortedValuesPtr[low-1]))
			{
				//确保临时变量的类似和被交换的数据类似完全一致！
				int tmp=sortedValuesPtr[low];
				sortedValuesPtr[low]=sortedValuesPtr[low-1];
				sortedValuesPtr[low-1]=tmp;
			}
		}

		std::cout << top-1 << ":" << values[top-1] << std::endl;
	}
	return sortedValuesPtr;
}
void test_sort_values()
{	
	int ints[]={200,100,3,-10,1000,21,0,-3,12,-300};
	int Count=sizeof(ints)/sizeof(int);

	sort_values_1(ints,Count,false);
	std::cout << "Descending" << std::endl;
	for(int i=0;i<Count;i++) std::cout << ints[i] << std::endl;
	std::cout << std::endl;

	int* intsPtr=sort_values_2(ints,Count,true);
	std::cout << "Ascending" << std::endl;
	for(int i=0;i<Count;i++) std::cout << intsPtr[i] << std::endl;
	std::cout << std::endl;
	delete intsPtr;
}

//字符串数组排序（采用冒泡法，直接改变输入的数组）
//strings是字符串指针的数组，【char*strings[]】或【char**strings】
//Count：字符串个数
//Accending：是否正序排列
//CaseSensitive：是否大小写相关
//以下2个定义完全一致
//void sort_strings_1(char*strings[],int Count,bool Accending,bool CaseSensitive)
void sort_strings_1(char**strings,int Count,bool Accending,bool CaseSensitive)
{
	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{			
			int res;
			if(CaseSensitive)
			{
				res=strcmp(strings[low],strings[low-1]);
			}
			else
			{
				res=_stricmp(strings[low],strings[low-1]);			
			}

			//是否需要交换，一下2个语句等效。
			//if((Accending && res<0) || (Accending==false && res>0))
			if(Accending == res<0)
			{
				//直接交换字符串的指针！
				//互相复制字符串可能是错误的，因为原字符串可能是【字符串常量】，每个字符串的空间都是刚刚好的！
				//如果不是【字符串常量】，要复制，必须提前指定【MaxLength】，它必须够放下每个字符串，
				//而且每个字符串原来的空间容得下【MaxLength】，一般只适合通过二维字符数组构成【字符串阵列】
				char*ptr=strings[low];
				strings[low]=strings[low-1];
				strings[low-1]=ptr;
			}		
		}
	}
}
//字符串数组排序（采用冒泡法，直接改变输入的数组）
//strings是字符串指针的数组，【char*strings[]】或【char**strings】
//Count：字符串个数
//Accending：是否正序排列
//CaseSensitive：是否大小写相关
//返回值：已经排序过的字符串数组的指针（调用方负责释放内存）
//以下2个定义完全一致
//char** sort_strings_1(char*strings[],int Count,bool Accending,bool CaseSensitive)
char** sort_strings_2(char**strings,int Count,bool Accending,bool CaseSensitive)
{
	//这里申请内存，返回给调用者，调用者负责delete此空间！
	//申请Count地址的数组（保存char*的数组，其实每个地址的size都是一样的4字节）
	char**sortedStringsPtr=(char**) malloc(sizeof(char*)*Count);

	//把原始的字符串的指针复制返回数组
	//因为冒泡法是在【数组内不断交换数据】来排序的，即必须直接改变被排序的数组。
	for(int i=0; i<Count; i++) sortedStringsPtr[i]=strings[i];

	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{
			int res;

			if(CaseSensitive)
			{
				res=strcmp(sortedStringsPtr[low],sortedStringsPtr[low-1]);
			}
			else
			{
				res=_stricmp(sortedStringsPtr[low],sortedStringsPtr[low-1]);
			}

			//是否需要替换
			if(Accending == res<0)
			{
				char*ptr=sortedStringsPtr[low];
				sortedStringsPtr[low]=sortedStringsPtr[low-1];
				sortedStringsPtr[low-1]=ptr;
			}					
		}
	}
	return sortedStringsPtr;
}

//二维字符数组排序（采用冒泡法，直接改变输入的数组）
//strings：是字符二维数组（二维字符数组构成【字符串阵列】，每个字符串的空间是一样大的而且依次相邻的，但是每个字符串实际的长度可以不同）
//Count：字符串个数
//Accending：是否正序排列
//CaseSensitive：是否大小写相关
#define MAXSTRLEN 20
void sort_strings_3(char strings[][MAXSTRLEN+1],int Count,bool Accending,bool CaseSensitive)
{
	char tmp[MAXSTRLEN+1];

	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{
			int res;
			if(CaseSensitive)
			{
				res=strcmp(strings[low],strings[low-1]);
			}
			else
			{
				res=_stricmp(strings[low],strings[low-1]);			
			}

			//是否需要替换
			if(Accending == res<0)
			{
				//不可以复制指针，因为那是一个二维字符数组，没有指针！
				//或者说，整个二维数组只有一个指针就是第一个字符的开始。
				strcpy_s(tmp,MAXSTRLEN,strings[low]);
				strcpy_s(strings[low],MAXSTRLEN,strings[low-1]);
				strcpy_s(strings[low-1],MAXSTRLEN,tmp);
			}		
		}
	}
}

//二维字符数组排序（采用冒泡法，不改变输入的数组，返回排序后的数组）
//strings：是字符二维数组
//Count：字符串个数
//Accending：是否正序排列
//CaseSensitive：是否大小写相关
//返回值：已经排序过的字符串数组的指针（调用方负责释放内存）
char** sort_strings_4(char strings[][21],int Count,bool Accending,bool CaseSensitive)
{
	//这里申请内容，返回给调用者，调用者负责delete此空间！
	//申请Count地址的数组（保存char*的数组，其实每个地址的size都是一样的4字节）
	char**sortedStringsPtr=(char**) malloc(sizeof(char*)*Count);

	//把原始的字符串的指针复制返回数组
	//因为冒泡法是在【数组内不断交换数据】来排序的，即必须直接改变被排序的数组。
	for(int i=0; i<Count; i++) sortedStringsPtr[i]=strings[i];

	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{
			int res;

			if(CaseSensitive)
			{
				res=strcmp(sortedStringsPtr[low],sortedStringsPtr[low-1]);
			}
			else
			{
				res=_stricmp(sortedStringsPtr[low],sortedStringsPtr[low-1]);
			}

			//是否需要替换
			if(Accending == res<0)
			{
				char*ptr=sortedStringsPtr[low];
				sortedStringsPtr[low]=sortedStringsPtr[low-1];
				sortedStringsPtr[low-1]=ptr;
			}					
		}
	}
	return sortedStringsPtr;
}

//字符数组排序（采用冒泡法，直接改变输入的数组）
//chars：字符数组的指针（保存了一个字符串，或者字符数组-不一定有0结束符）
//Count：字符个数
//Accending：是否正序排列
//CaseSensitive：是否大小写相关
void sort_chars_1(char* chars,int Count,bool Accending,bool CaseSensitive)
{
	//外循环控制从最下发往上比较的最后一个位置
	for(int top=1; top<=(Count-1); top++)
	{
		//总是从下面【i】一个和上方一个【i-1】比较
		for(int low=Count-1; low>=top; low--)
		{
			int res;
			if(CaseSensitive)
			{
				res=strncmp(chars+low,chars+low-1,1);
			}
			else
			{
				res=_strnicmp(chars+low,chars+low-1,1);		
			}

			//是否需要替换
			if(Accending == res<0)
			{
				char tmp=chars[low];
				chars[low]=chars[low-1];
				chars[low-1]=tmp;
			}
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS
void test_sort_strings()
{	
	//【字符串常量】数组，每个strings[x]对应一个【字符串常量/const char*】的地址。
	char*strings[]={"hello","Emily","world","abc","yes","no"};
	int Count=6;

	//就地排序法：直接在原数组上排序
	sort_strings_1(strings,Count,false,true);
	std::cout << "Descending, Case Sensitive" << std::endl;
	for(int i=0;i<Count;i++) std::cout << strings[i] << std::endl;
	std::cout << std::endl;

	//外部排序法：把排序后的字符串指针的数组返回。
	std::cout << "Ascending, Case Insensitive" << std::endl;
	char**stringPtrs=sort_strings_2(strings,Count,true,false);
	for(int i=0;i<Count;i++) std::cout << stringPtrs[i] << std::endl;
	std::cout << std::endl;

	//二维字符数组构成的【字符串阵列】
	char chars[6][MAXSTRLEN+1]={"hello","Emily","world","abc","yes","no"};
	std::cout << sizeof(chars) << std::endl;//(MAXSTRLEN+1) * 6

	//就地排序法：直接在原字符串阵列上排序，字符串会在不同的行/列上移动。
	sort_strings_3(chars,6,false,true);
	std::cout << "Descending, Case Sensitive" << std::endl;
	for(int i=0;i<6;i++) std::cout << chars[i] << std::endl;
	std::cout << std::endl;

	//外部排序法：把排序后的字符串指针的数组返回。
	char** ptrs=sort_strings_4(chars,6,true,true);
	std::cout << "Ascending, Case Sensitive" << std::endl;
	for(int i=0;i<6;i++) std::cout << ptrs[i] << std::endl;
	std::cout << std::endl;
	delete ptrs;

	//字符数组构成的字符串，"Hello World!" 本身是【字符串常量】
	//但是char string[]的string本身没有被指定为【字符串常量】可以修改内部字符,但是不可以超过长度。
	char string[]="Hello World!";

	//就地排序法：直接在原字符串阵列上排序，字符串会在不同的行/列上移动。	
	sort_chars_1(string,strlen(string),true,false);
	std::cout << "Ascending, Case Insensitive" << std::endl;
	for(int i=0;i<strlen(string);i++) std::cout << string[i] << std::endl;
	std::cout << std::endl;

	//下属定义方法【字符串常量】,const_string虽然没有指定为const char*，
	//但是，它指向的地址却是，因此不可以修改它的内部字符。
	const char* const_string="Hello World!";
	//因此必须复制后再就地排序，等于外部排序。
	char*ptr=new char[201];
	strcpy_s(ptr,200,const_string);//确保const_string的长度不会超过200。
	sort_chars_1(ptr,strlen(ptr),false,false);
	std::cout << "Descending, Case Insensitive" << std::endl;
	for(int i=0;i<strlen(ptr);i++) std::cout << ptr[i] << std::endl;
	std::cout << std::endl;
}