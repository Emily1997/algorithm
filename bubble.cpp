/* 
   ð�����򷨡��ַ���/�ַ�/��ֵ����
*/

#include <ios>
#include <iostream>

//ð���㷨������ѭ��
void bubble_sort(int Count)
{
	//���������ǽ�����ˣ��������ʡ��ѭ��������
	//����CountΪ5�����ν���һ�£�

	//4-3,3-2,2-1,1-0    low=4 to 1, �Ƚ�4����ɺ�λ��0���Ǵ���Сֵ������/�����ֵ������
	//4-3,3-2,2-1        low=4 to 2, �Ƚ�3����ɺ�λ��1���Ǵ���Сֵ������/�����ֵ������
	//4-3,3-2            low=4 to 3, �Ƚ�2����ɺ�λ��2���Ǵ���Сֵ������/�����ֵ������
	//4-3                low=4 to 4, �Ƚ�1����ɺ�λ��3���Ǵ���Сֵ������/�����ֵ������ λ��4���Ǵ���Сֵ������/�����ֵ������

	//Ҳ����˵��ѭ�����Ǵ�Count-1��ʼ������λ������Ϊ��1��2,3,4������1�� �� ��Count-1����

	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
		for(int low=Count-1; low>=top; low--)
		{
		}
	}
}

//��ֵ�������򣨲���ð�ݷ���ֱ�Ӹı���������飩
//values����ֵ����ָ�루char*/int*/float*/double*/__int64*��ֵ������ȫһ�£�
//Count����ֵ����
//Accending���Ƿ���������
void sort_values_1(int*values,int Count,bool Ascending)
{
	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
		for(int low=Count-1; low>=top; low--)
		{

			//�Ƿ���Ҫ����
			//if((Ascending && values[low]<values[low-1])||(Ascending==false && values[low]>values[low-1]))
			if(Ascending == (values[low]<values[low-1]))
			{
				//ȷ����ʱ���������ƺͱ�����������������ȫһ�£�
				int tmp=values[low];
				values[low]=values[low-1];
				values[low-1]=tmp;
			}
		}
		std::cout << top-1 << ":" << values[top-1] << std::endl;
	}
}
//��ֵ�������򣨲���ð�ݷ���ֱ�Ӹı���������飩
//values����ֵ����ָ�루char*/int*/float*/double*/__int64*��ֵ������ȫһ�£�
//Count����ֵ����
//Accending���Ƿ���������
//����ֵ���Ѿ����������ֵ�����ָ�루���÷������ͷ��ڴ棩
int* sort_values_2(int*values,int Count,bool Ascending)
{
	//�����������ݣ����ظ������ߣ������߸���delete�˿ռ䣡
	//����Count��ַ�����飨����int�����飩
	int* sortedValuesPtr=(int*) malloc(sizeof(int)*Count);

	//��ԭʼ���ַ�����ָ�븴�Ʒ�������
	//��Ϊð�ݷ����ڡ������ڲ��Ͻ������ݡ�������ģ�������ֱ�Ӹı䱻��������顣
	for(int i=0; i<Count; i++) sortedValuesPtr[i]=values[i];


	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
		for(int low=Count-1; low>=top; low--)
		{
			//�Ƿ���Ҫ����
			//if((Ascending && sortedValuesPtr[low]<sortedValuesPtr[low-1])||(Ascending==false && sortedValuesPtr[low]>sortedValuesPtr[low-1]))
			if(Ascending == (sortedValuesPtr[low]<sortedValuesPtr[low-1]))
			{
				//ȷ����ʱ���������ƺͱ�����������������ȫһ�£�
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

//�ַ����������򣨲���ð�ݷ���ֱ�Ӹı���������飩
//strings���ַ���ָ������飬��char*strings[]����char**strings��
//Count���ַ�������
//Accending���Ƿ���������
//CaseSensitive���Ƿ��Сд���
//����2��������ȫһ��
//void sort_strings_1(char*strings[],int Count,bool Accending,bool CaseSensitive)
void sort_strings_1(char**strings,int Count,bool Accending,bool CaseSensitive)
{
	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
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

			//�Ƿ���Ҫ������һ��2������Ч��
			//if((Accending && res<0) || (Accending==false && res>0))
			if(Accending == res<0)
			{
				//ֱ�ӽ����ַ�����ָ�룡
				//���ิ���ַ��������Ǵ���ģ���Ϊԭ�ַ��������ǡ��ַ�����������ÿ���ַ����Ŀռ䶼�Ǹոպõģ�
				//������ǡ��ַ�����������Ҫ���ƣ�������ǰָ����MaxLength���������빻����ÿ���ַ�����
				//����ÿ���ַ���ԭ���Ŀռ��ݵ��¡�MaxLength����һ��ֻ�ʺ�ͨ����ά�ַ����鹹�ɡ��ַ������С�
				char*ptr=strings[low];
				strings[low]=strings[low-1];
				strings[low-1]=ptr;
			}		
		}
	}
}
//�ַ����������򣨲���ð�ݷ���ֱ�Ӹı���������飩
//strings���ַ���ָ������飬��char*strings[]����char**strings��
//Count���ַ�������
//Accending���Ƿ���������
//CaseSensitive���Ƿ��Сд���
//����ֵ���Ѿ���������ַ��������ָ�루���÷������ͷ��ڴ棩
//����2��������ȫһ��
//char** sort_strings_1(char*strings[],int Count,bool Accending,bool CaseSensitive)
char** sort_strings_2(char**strings,int Count,bool Accending,bool CaseSensitive)
{
	//���������ڴ棬���ظ������ߣ������߸���delete�˿ռ䣡
	//����Count��ַ�����飨����char*�����飬��ʵÿ����ַ��size����һ����4�ֽڣ�
	char**sortedStringsPtr=(char**) malloc(sizeof(char*)*Count);

	//��ԭʼ���ַ�����ָ�븴�Ʒ�������
	//��Ϊð�ݷ����ڡ������ڲ��Ͻ������ݡ�������ģ�������ֱ�Ӹı䱻��������顣
	for(int i=0; i<Count; i++) sortedStringsPtr[i]=strings[i];

	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
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

			//�Ƿ���Ҫ�滻
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

//��ά�ַ��������򣨲���ð�ݷ���ֱ�Ӹı���������飩
//strings�����ַ���ά���飨��ά�ַ����鹹�ɡ��ַ������С���ÿ���ַ����Ŀռ���һ����Ķ����������ڵģ�����ÿ���ַ���ʵ�ʵĳ��ȿ��Բ�ͬ��
//Count���ַ�������
//Accending���Ƿ���������
//CaseSensitive���Ƿ��Сд���
#define MAXSTRLEN 20
void sort_strings_3(char strings[][MAXSTRLEN+1],int Count,bool Accending,bool CaseSensitive)
{
	char tmp[MAXSTRLEN+1];

	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
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

			//�Ƿ���Ҫ�滻
			if(Accending == res<0)
			{
				//�����Ը���ָ�룬��Ϊ����һ����ά�ַ����飬û��ָ�룡
				//����˵��������ά����ֻ��һ��ָ����ǵ�һ���ַ��Ŀ�ʼ��
				strcpy_s(tmp,MAXSTRLEN,strings[low]);
				strcpy_s(strings[low],MAXSTRLEN,strings[low-1]);
				strcpy_s(strings[low-1],MAXSTRLEN,tmp);
			}		
		}
	}
}

//��ά�ַ��������򣨲���ð�ݷ������ı���������飬�������������飩
//strings�����ַ���ά����
//Count���ַ�������
//Accending���Ƿ���������
//CaseSensitive���Ƿ��Сд���
//����ֵ���Ѿ���������ַ��������ָ�루���÷������ͷ��ڴ棩
char** sort_strings_4(char strings[][21],int Count,bool Accending,bool CaseSensitive)
{
	//�����������ݣ����ظ������ߣ������߸���delete�˿ռ䣡
	//����Count��ַ�����飨����char*�����飬��ʵÿ����ַ��size����һ����4�ֽڣ�
	char**sortedStringsPtr=(char**) malloc(sizeof(char*)*Count);

	//��ԭʼ���ַ�����ָ�븴�Ʒ�������
	//��Ϊð�ݷ����ڡ������ڲ��Ͻ������ݡ�������ģ�������ֱ�Ӹı䱻��������顣
	for(int i=0; i<Count; i++) sortedStringsPtr[i]=strings[i];

	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
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

			//�Ƿ���Ҫ�滻
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

//�ַ��������򣨲���ð�ݷ���ֱ�Ӹı���������飩
//chars���ַ������ָ�루������һ���ַ����������ַ�����-��һ����0��������
//Count���ַ�����
//Accending���Ƿ���������
//CaseSensitive���Ƿ��Сд���
void sort_chars_1(char* chars,int Count,bool Accending,bool CaseSensitive)
{
	//��ѭ�����ƴ����·����ϱȽϵ����һ��λ��
	for(int top=1; top<=(Count-1); top++)
	{
		//���Ǵ����桾i��һ�����Ϸ�һ����i-1���Ƚ�
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

			//�Ƿ���Ҫ�滻
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
	//���ַ������������飬ÿ��strings[x]��Ӧһ�����ַ�������/const char*���ĵ�ַ��
	char*strings[]={"hello","Emily","world","abc","yes","no"};
	int Count=6;

	//�͵����򷨣�ֱ����ԭ����������
	sort_strings_1(strings,Count,false,true);
	std::cout << "Descending, Case Sensitive" << std::endl;
	for(int i=0;i<Count;i++) std::cout << strings[i] << std::endl;
	std::cout << std::endl;

	//�ⲿ���򷨣����������ַ���ָ������鷵�ء�
	std::cout << "Ascending, Case Insensitive" << std::endl;
	char**stringPtrs=sort_strings_2(strings,Count,true,false);
	for(int i=0;i<Count;i++) std::cout << stringPtrs[i] << std::endl;
	std::cout << std::endl;

	//��ά�ַ����鹹�ɵġ��ַ������С�
	char chars[6][MAXSTRLEN+1]={"hello","Emily","world","abc","yes","no"};
	std::cout << sizeof(chars) << std::endl;//(MAXSTRLEN+1) * 6

	//�͵����򷨣�ֱ����ԭ�ַ��������������ַ������ڲ�ͬ����/�����ƶ���
	sort_strings_3(chars,6,false,true);
	std::cout << "Descending, Case Sensitive" << std::endl;
	for(int i=0;i<6;i++) std::cout << chars[i] << std::endl;
	std::cout << std::endl;

	//�ⲿ���򷨣����������ַ���ָ������鷵�ء�
	char** ptrs=sort_strings_4(chars,6,true,true);
	std::cout << "Ascending, Case Sensitive" << std::endl;
	for(int i=0;i<6;i++) std::cout << ptrs[i] << std::endl;
	std::cout << std::endl;
	delete ptrs;

	//�ַ����鹹�ɵ��ַ�����"Hello World!" �����ǡ��ַ���������
	//����char string[]��string����û�б�ָ��Ϊ���ַ��������������޸��ڲ��ַ�,���ǲ����Գ������ȡ�
	char string[]="Hello World!";

	//�͵����򷨣�ֱ����ԭ�ַ��������������ַ������ڲ�ͬ����/�����ƶ���	
	sort_chars_1(string,strlen(string),true,false);
	std::cout << "Ascending, Case Insensitive" << std::endl;
	for(int i=0;i<strlen(string);i++) std::cout << string[i] << std::endl;
	std::cout << std::endl;

	//�������巽�����ַ���������,const_string��Ȼû��ָ��Ϊconst char*��
	//���ǣ���ָ��ĵ�ַȴ�ǣ���˲������޸������ڲ��ַ���
	const char* const_string="Hello World!";
	//��˱��븴�ƺ��پ͵����򣬵����ⲿ����
	char*ptr=new char[201];
	strcpy_s(ptr,200,const_string);//ȷ��const_string�ĳ��Ȳ��ᳬ��200��
	sort_chars_1(ptr,strlen(ptr),false,false);
	std::cout << "Descending, Case Insensitive" << std::endl;
	for(int i=0;i<strlen(ptr);i++) std::cout << ptr[i] << std::endl;
	std::cout << std::endl;
}