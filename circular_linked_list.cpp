/* 
ѭ������
���뵥����һ������һ����ʽ�Ĵ洢�ṹ������ͬ���ǣ�ѭ����������һ������ָ����ָ���ѭ������ĵ�һ�������߱�ͷ��㣬
�Ӷ�����һ�����ε����������ṹ����

���Ĺ������£�

1���ڽ���һ��ѭ������ʱ������ӵ�һ���ڵ㿪ʼ������β�����ģ����нڵ㶼�ǡ�Next!=NULL����
2��ֻ����һ���ڵ㣨���������һ���ڵ㣩��Nextָ��ͬһ���ڵ㣬����Сѭ�������ƻ����ѭ����
3���ڲ�����Ƴ�ʱ����Ҫ���֡�Next���ĵ�����ѭ����ϵ�����ǲ�Ҫ����/ά�����ĸ���ͷ���͡��ĸ���β����
4�����ڿ���ͨ���κ�һ���ڵ��Next���������������κ�һ���ڵ㿪ʼNext���������Իص����Լ�����Ҳ�Ǳ���CLL�������������  


ѭ������ı��Σ��Ҳ�֪���Ķ����ƣ�
1�����ض��Ľڵ�Ͽ�����ɵ�����sll������Ȼ�γ�һ��ͷ��β��
2����cll��ĳ���ڵ��Next����Ϊ���������ڵ㣬ĳ���ڵ��ɶ���ڵ��Nextָ���γɴ�������������������������γɶ������Ͽ�����

Ӧ�ã�

1����ʵ��Ӧ���У������ֻ��Ҫ����һ������ǰ�ڵ㡿������Ҫ����ÿ���ڵ㣬ͨ������������ÿ���ڵ���������ˣ�
2�������ȷʵ��Ҫһ����ͷ�ڵ�-���ȼ���Ľڵ㡿/��β�ڵ�-������Ľڵ㡿��������Լ�����������

��ǣ�

1��sll����ǰ���˺ü���Ŀ���ʱ�����������test caseҲ�ü�ʮ����ԭ�����࣬ɾ��һ���֣���
2��cll����һ���ǳɣ��ۼƲ���2Сʱ�㶨��test caseҲ���٣��󲿷�һ��ͨ����
3��Ϊʲô��ԭ����Ϊsll��cll�򵥣����Ϊ��ά����header���͡�tail�������ø��Ӷ������׳���
4����ˣ�ΰ����ǡ�ģ�͡��ķ����ߣ���������д������Щʵ����Щ�㷨�Ĵ��룬��ģ���ô���򻯺�ֱ�ۡ���
�������븴�ӵľ��أ������Դ�Ҫը����ʱ���������Ƿ񡰺����˶����ݵ���֯������û��ʹ�úõ�ģ�͡���
��û�С����顿�İ����£����������ʵ��2�����ݵıȽϣ�3������Ҳ���ã�4����ͷ���ˣ�5���������������ϵ���
���ԣ�������˵û���κ�ģ�ͺ��㷨ѵ�����ˣ�д��һ�Ѵ��룬���˼���ĳ���Ա����Ӧ��͵Ц����Ҳ��Ҫ���Լ���Ц��
�����ģ�͡��㷨����ôЩ�����ʵ�������ģʽ���㷨�������޾��ģ���������ʱ���뵽���ǣ��������ǣ�Ҳ���Է����Լ���ģ�͡��㷨��
*/

#include <ios>
#include <iostream>

//�ڵ�ṹ
struct cll_node
{
	//��һ���ڵ�/�ҽڵ�
	cll_node*next;//Ƕ�׽ṹ


	//�ڵ����ݣ����԰�������Ҫ��һ��������ݣ�����/�������ޣ��������㷨Ҳ�޹أ�
	//�������Ҳ������һ��ָ�룬ָ��ĳ�����ṹ���ݡ������������ڱ������ǡ�һ������֯�����ݵ������������
	//ͬ�������ݼ�����ʹ�ö����������֯�����������ã�����/��/ջ/����֮�ࡾ��֯�ߡ������Ǹ�����Ҫ-���ݵ�ʹ��ģʽ������֯���ǡ�
	int data;	
};



void cll_display(cll_node*from)
{
	if(from!=NULL)
	{
		//����
		int i=0;
		cll_node*n=from;
		while(n != NULL) //��һ���жϣ�����Ӧѭ�������Ͽ�������������
		{
			std::cout << "node[" << i++ << "]=" << n->data << std::endl;
			n=n->next;
			if(n==from) break;//�ص���ʼ�����Ľڵ㣬ֹͣ������
		}
	}
}


//Ѱ��ǰһ�ڵ㡾�κνڵ㶼��ǰһ�ڵ�Ŷ��
cll_node*cll_seek_prev(cll_node*node)
{

	if(node==NULL)
	{
		std::cout << "cll_seek_prev: the node is NULL!" << std::endl;
		return NULL;	
	}	


	//����
	int i=0;
	cll_node*n=node;

	while(n != NULL)//��һ���жϣ�����Ӧѭ�������Ͽ�������������
	{
		if(n->next==node) return n;
		n=n->next;
		if(n==node) break;//�ص���ʼ�����Ľڵ㣬ֹͣ������
	}

	//��Ч�Ľڵ㣨�����ϲ����ܣ�
	std::cout << "cll_seek_prev: The previous node can not be found! The specified node may had been moved out." << std::endl;
	return NULL;
}

//����һ�������ݵĽڵ㲢����ĳ���ڵ�֮��
//existing_node==NULL��������һ���ڵ�
//��Զ���᷵��NULL��
cll_node* cll_insert_after(cll_node* existing_node)
{

	cll_node*new_node=new  cll_node();
	//cll_node*new_node=(cll_node*)malloc(sizeof(cll_node));

	new_node->next=NULL;//���븳ֵNULL����������ֵ��δ֪�ģ�

	//��ʼ���ڵ�����
	new_node->data=0;

	if(existing_node==NULL)
	{
		//������һ���ڵ㣨��ѭ����
		new_node->next = new_node;
	}
	else
	{
		//��������ԭ����������������˳�����Ҫ��
		//�����ѭ�������ϣ����·���Ҳ�ʺ�������β�ڵ㡣
		new_node->next = existing_node->next;
		existing_node->next = new_node;
	}

	return new_node;	
}

//����һ�������ݵĽڵ㲢����ĳ���ڵ�֮ǰ����Ч�ʺ���������ʹ�ã�
//existing_node==NULL��������һ���ڵ�
cll_node* cll_insert_before(cll_node* existing_node)
{

	if(existing_node==NULL)
	{
		//������һ���ڵ㣨��ѭ����
		return cll_insert_after(NULL);
	}
	else
	{
		cll_node*prev_node = cll_seek_prev(existing_node);
		if(prev_node != NULL) return cll_insert_after(prev_node);
	}

	//��existing_node������ʱ��
	return NULL;
}
//����һ�����ݽڵ㲢����ĳ���ڵ�֮��
//existing_node==NULL��������һ���ڵ�
//��Զ���᷵��NULL��
cll_node* cll_insert_data_after(cll_node* existing_node, int data)
{
	cll_node*new_node=cll_insert_after(existing_node);
	new_node->data=data;
	return new_node;
}
//����һ�����ݽڵ㲢����ĳ���ڵ�֮ǰ����Ч�ʺ���������ʹ�ã�
//existing_node==NULL��������һ���ڵ�
cll_node* cll_insert_data_before(cll_node* existing_node, int data)
{
	cll_node*new_node=cll_insert_before(existing_node);
	if(new_node!=NULL) new_node->data=data;
	return new_node;
}

//ɾ��һ���ڵ㣨����ɾ��Ψһ�ڵ㣩
bool cll_remove(cll_node* existing_node)
{
	cll_node*prev_node = cll_seek_prev(existing_node);
	if(prev_node==NULL) return false;

	if(prev_node != existing_node) 
	{		
		prev_node->next = existing_node->next;
	}

	delete existing_node;
	return true;
}

//��ת�����κ�һ���ڵ㿪ʼ������ת��
bool cll_reserve(cll_node* from)
{
	if(from==NULL) 	
	{
		std::cout << "cll_seek_prev: the from is NULL!" << std::endl;
		return NULL;	
	}	


	//ÿ�η�תһ��Nextָ�룡
	//ԭ˳��1 -> 2 -> 3 -> 4   
	//��һ�Σ�1 <- 2 -> 3 -> 4
	//�ڶ��Σ�1 <- 2 <- 3 -> 4
	//�����Σ�1 <- 2 <- 3 <- 4
	cll_node*node1=from;
	cll_node*node2=node1->next;
	cll_node*node3;
	while(true)
	{
		//��ǰ����Next�ڵ���һ��ѭ����node2��
		node3=node2->next;

		//��תһ��ָ�룡
		node2->next=node1;

		//����һ��[node1->node2->node3]->node4 ==> node1<-[node2 node3<-node4]
		node1=node2;		
		node2=node3;
		if(node1==from) break;
	}

	return true;
}

//�Ͽ�ѭ������
//existing_node���Ӵ˽ڵ��Ժ�Ͽ�
bool cll_break(cll_node* existing_node)
{
	if(existing_node!=NULL) 
	{
		existing_node->next=NULL;
		return true;
	}
	return false;
}

//�޸Ľڵ��Next�����԰ѶϿ������������Ҳ���ܰ����л��Ͽ������µĻ���
//
//1��������һ����A������cll��/��ֲ��������ڻ�A�ڸ��κ�һ���ڵ��Next��һ������һ���»�B����next_node �� precv_node����
//2��prev_node��ԭ����Next���û�нڵ㵽���ɻ�B֮��ġ�β�͡��ڵ㡣
//3��A������һ��ȱ�ڣ����һ���ڵ�ָ��next_node��һ����ζ����һ���ڵ�����һ��ָ��
//4��ԭ��A������һ���ջ������������ڲ��ڵ��γ�һ��С��/�ڻ�B��
//5����ԭ��A���κνڵ㣨������B���⻹���ڣ������Ե��ﻷB��
//6����ԭ��A���κ�B����Ľڵ㶼���Ա���ԭ��A���нڵ㣬��B���ڵ��κνڵ㶼��ֻ�ܡ�������B���ڵ����нڵ㡣
//   ��O���� => ��6���� �� ��9���͡� 
//   (1234)   ==> 12(34)   
//   (123456) ==> 123(456)
//    cll_link(n1, n2)
//    if(n1 >= n2) ���ڲ��֣�1...(n1....n2)  ����ֱ�����֣�end_node...1
//    if(n1 <= n2) ���ڲ��֣�(1...n1->n2->n2+1->...end_node) ����ֱ�����֣�n1+1.....n2
//7������ݹ�1->6����B���ڲ����κ�һ���ڵ��Next������ԭ����prev_node,next_node������ֻ���޸���B������ֹ���ѣ���һ������һ����C��B�������ǻ���������һ��ȱ�ڡ�
//������������δ������֤��
//8�������ԭA����B����Ľڵ����κ�һ���ڵ��Next�������γ�ͬ����ͬ��˳ʱ�����ʱ�룩�Ļ�������ǣ��˻���ԭ���Ļ����׷ֿ���
//   ��O���� => ��6���� �� ��9���� ==> ��6 6���� / ��9 9�� �� / ��oo�� �͡�
//   (1234)   ==> 12(34)    ==> (12)(34)  ==>  (1)(2)(3)(4)  
//   (123456) ==> 123(456)  ==> 1(23)4(56) / (123)(456)
//9����������»���һ�����γ��ˡ��ݾ��������ǻ������㡰���κνڵ㿪ʼ�����Դﵽ��B�������ǡ����κνڵ㿪ʼ��һ�����Ա���������B�����нڵ㡣��
bool cll_link(cll_node* prev_node, cll_node* next_node)
{
	if(prev_node!=NULL) 
	{
		prev_node->next=next_node;
		return true;
	}
	return false;
}

//�Ƿ���ѭ���������ڻ���
//from����ʼ���ԵĽڵ㣨�����ڻ��ڻ��⣩
bool cll_is_loop(cll_node* from)
{
	//�������뵽�ķ������Ǵ��κ�һ�㿪ʼ���Next��ֻҪ�ܻص����Լ����Ǵ��ڻ�������NextΪNULL�Ͳ��ǡ�
	//��������ָ�������Ŀ���Ǽ����жϵ�ѭ������?������ѭ���ĵ�������û���κ�����ģ���
	//���Ҫ�жϴ��ڲ����ڻ����Ǻܼ򵥣�����Ҫ֪������ھ�ֻ�ܲ���׷�ӵĿ���ָ���㷨�ˡ�
	//�����Ǵ�ʦ����������ָ���㷨-ΰ��ķ���������ԭ�����Ҹ����ı�����
	//
	//1��һֻ�ٶȿ���ڹ��һֻ�������ڹ꣬��ͬһ���������ܵ�����ͬһ�������������ͬһ����Ҳ����ν������ͬһ�������ƶ�����ô����һ�����ԴӺ���ϳ��ڹꡣ
	//2������ܵ������޳��ȵ�ֱ�ߣ����ӻ����ڹ�Խ��ԽԶ����Զ����ϳ���
	//3��Ҳ����˵�ٶȿ�ĸϳ��ٶ���������Ϊ�ܵ��ǻ��εģ��ܵÿ�Ļ������NȦ���ܵ����Ļ�����NȦ����ˣ���һ���ڻ����ܵ���ĳ���ط��ᱻ�ϳ�����
	//
	//4����������仯һ�£�������Ӻ��ڹ�������һ��ֱ�ߡ���ѭ�����߼��ɡ���Ȼ�����ͬһ�������ܵ���
	//   ��ô�������ǵ�������һ���ڻ����ڣ�����л��εĻ��������ڻ��⡿��
	//
	//5�����������ٱ仯һ�£�ֱ�ߺͻ����ܵ������ɵȾ���Ĺ��ӡ���ʯ����ɣ���������Ǻܿ����ģ��ڹ�һ�θպÿ���������һ��ʯͷ������������һ����2���ʯͷ��
	//   ���ң����Ӻ��ڹ궼������ͳһ�ĺ��ӣ���1��2��3����������ô����ĸϳ����ǣ�����ĳ����ʯ�ϣ�Ҫô���������ڹ����棬Ҫô�ڹ������������桱��
	//
	//
	//
	//fast pointer/cusor and slow pointer also start from the same existing node.
	cll_node*fast=from;
	cll_node*slow=from;
	bool loop=false;
	int i=0;
	while(true)
	{		
		i++;

		//this judgement should be made before meeting/overtaking. Not in while also.
		//judge the fast pointer only! it will encounter with tail first!
		if(fast==NULL || fast->next==NULL) break;

		//fast pointer always move on 2 nodes per time
		fast=fast->next->next;

		//slow pointer move on 1 node per time.
		slow=slow->next;

		//encountering/overtaking, then slow and fast should be in the loop! 
		//why it can be fast->next==slow or it can be fast->next->next==slow, and so on ?
		//that's, if the slow is at any "front" nodes, these nodes should be in the loop.
		//���������fast->next==slow�����жϣ���Ϊ��while�������Ա仯�Ķ�����ɢ����Ծ��
		//fast��һ���Կ��slowһ���ڵ㣨����ÿһ�ζ��������ַ�ʽ������
		//��ˣ�������fast->next==slow���жϣ��Ϳ���ȷ����ʱ���������Ҳ�������ˣ�
		//����˼�������fast�������ٶȶ�����2���أ�
		if(fast==slow || (fast!=NULL &&  fast->next==slow)) {loop=true;break;}
	}

	std::cout << "total while count=" << i << std::endl;
	return loop;
}
//��ָ���Ľڵ㿪ʼѰ��������ڣ����6�ͣ�
//outside_node�����ڻ��⣬���from�ڻ��ڻ�ԭ�����ǣ�����O�͵�cll������ֵ�����ǻ��ڵ��κνڵ㣬��һ�����ǻ���ڡ�
cll_node*cll_find_loop(cll_node* outside_node)
{
	//2��Nextָ��Ľڵ���ǻ���ڣ���ˣ�����ͨ��һά�������ۼ�Next�ǿ��Եģ��㷨���£�
	//һά����Ĵ�СΪ�ڵ��������±�Ϊ��from��ʼ�ڵ�λ�á�������Ϊ�ڵ��data���������ظ������ҷ�ΧΪֹ��Ҳ������Ϊ�ڵ�ĵ�ַ�����ܴ󡿣�ֵΪ��next������
	//�����������±��ڲ�֪���Ǹ������ǰ��ֻ��һֱ������ȥ����ˣ��򵥵�����ʵ�����޷������ֻ�ܲ���hash��
	//��ˣ������������߼���hash������ģʽ�ǽ�����˵ģ�����data��ľ���1-N֮���������ֵ�պÿ�����Ϊ������±ꡣ
	//�����Ǵ�ʦ����������ָ���㷨-ΰ��ķ�����

	//fast pointer/cusor and slow pointer also start from the same existing node.
	cll_node*fast=outside_node;
	cll_node*slow=outside_node;

	int i=0;
	while(fast!=NULL && fast->next!=NULL)
	{		
		i++;

		//slow pointer move on 1 node per time.
		slow=slow->next;

		//fast pointer always move on 2 nodes per time
		fast=fast->next->next;

		//encountering/overtaking, then slow and fast should be in the loop!
		//this point is the precise point of encountering.
		//fastָ����ڵڼ�Ȧ��slowָ������
		if (slow == fast) break;
	}

	//had not encountered, reach tail.
	if (fast == NULL || fast->next == NULL)	return NULL;

	//make slow pointer move on from header or any nodes outside of loop.
	slow = outside_node;
	while (slow != fast)
	{
		slow = slow->next;

		//the fast pointer is in the loop, and it also move on 1 node per time.
		//so the encounter pointer should be the loop's port/entrance.
		//ע�⣺
		//��������2��ָ����ƶ��ٶ���һ�µģ����ֻҪһ�������Ļ��ᣬ
		//Ҳ���ǣ�����������ָ�루slow���պý��뻷�ڵ�һ�̣�ĳ��ѭ����������������Ҳ����˵��������ǻ���ڡ�
		//��ο����Ի����������ϣ��������ĵ���cll_find_loop.txt��
		fast = fast->next;
	}
	std::cout << "total while count=" << i << std::endl;

	return slow;
}

//����/�ͷ��ڴ棨ע�⣺��������һ��ѭ�������ǲ������������ٵģ���������ظ�����-�쳣���򲿷�����-�ڴ涪ʧ��
int cll_destory(cll_node* existing_node)
{
	int count=0;
	if(existing_node != NULL)
	{
		cll_node*n = existing_node;
		while(n != NULL)
		{
			cll_node*nn=n->next;		
			//std::cout << "delete " << n->data << std::endl;
			delete n;		
			count++;
			n=nn;
			if(n==existing_node) break;
		}
	}
	return count;
}


bool cll_test()
{
	//���ڿ���ͨ���κ�һ���ڵ�Next����������ˣ���ʵ��Ӧ���У������ֻ��Ҫ����һ����ǰ�ڵ㣬
	//����Ҫ����ÿ���ڵ㣬ͨ������������ÿ���ڵ���������ˣ�
	//�����ȷʵ��Ҫһ����ͷ�ڵ�-���ȼ���Ľڵ㡿/��β�ڵ�-������Ľڵ㡿��������Լ�����������
	cll_node*n1=NULL;
	cll_node*n2=NULL;
	cll_node*n3=NULL;
	cll_node*n4=NULL;
	cll_node*n5=NULL;
	cll_node*loop=NULL;
	int testcase=0;

	//insert the first node
	testcase=1;
	if((n1=cll_insert_data_after(NULL,1))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after first node failed." << std::endl; 
		return false;
	}
	if(cll_destory(n1)!=1)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}


	//insert 2 nodes
	testcase=2;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after 2 nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n2 || n2->next!=n1) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_insert_data_after order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n2)!=2)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}


	//insert 3 nodes (1-2-3)-1
	testcase=3;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n2,3))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after 3 nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n2 || n2->next!=n3 || n3->next != n1) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_insert_data_after order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n2)!=3)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}


	//insert 3 nodes (1-3-2)-1
	testcase=4;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n1,3))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after 3 nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n3 || n3->next!=n2 || n2->next != n1) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_insert_data_after order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n2)!=3)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}


	//insert 3 nodes (3-1-2)-3
	testcase=5;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_before(n1,3))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_before 3 nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n3->next!=n1 || n1->next!=n2 || n2->next != n3) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_insert_data_before order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n2)!=3)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//insert 4 nodes (1-2-4-3)-1
	testcase=6;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n2,3))==NULL || (n4=cll_insert_data_after(n2,4))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_before 3 nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n2 || n2->next!=n4 || n4->next != n3 || n3->next != n1) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_insert_data_after order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n2)!=4)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//remove only 1 node
	testcase=7;
	if((n1=cll_insert_data_after(NULL,1))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after first node failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_remove(n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_remove only node failed." << std::endl; 
		return false;
	}

	//remove 1 of 2 nodes
	testcase=8;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_remove(n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_remove 1 node failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n2->next!=n2) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_remove order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n2)!=1)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//remove 1 of 2 nodes
	testcase=9;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_remove(n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_remove 1 node failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n1) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_remove order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n1)!=1)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}


	//remove nodes
	testcase=10;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n2,3))==NULL || (n4=cll_insert_data_after(n3,4))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_remove(n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_remove 1 node failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_remove(n3)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_remove 1 node failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n4 || n4->next!=n1) 
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_remove order error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n1)!=2)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "5: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//reverse 1/2/3 nodes list
	testcase=11;
	if((n1=cll_insert_data_after(NULL,1))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_reserve(n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_reserve 1 node list failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_reserve set next error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if((n2=cll_insert_data_after(n1,2))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_insert_data_after node 2 error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_reserve(n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "5: cll_reserve 2 nodes list failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n2->next!=n1 && n1->next!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "6: cll_reserve set next error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if((n3=cll_insert_data_after(n1,3))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "7: cll_insert_data_after node 3 error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_reserve(n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "8: cll_reserve 3 nodes list failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(n1->next!=n2 && n2->next!=n3 || n3->next!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "9: cll_reserve set next error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n1)!=3)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}


	//reverse 5 nodes
	testcase=12;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n2,3))==NULL || (n4=cll_insert_data_after(n3,4))==NULL || (n5=cll_insert_data_after(n4,5))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	cll_display(n1);
	if(cll_reserve(n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_reserve 5 nodes list failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	cll_display(n5);
	if(n5->next!=n4 && n4->next!=n3 || n3->next!=n2 || n2->next!=n1 || n1->next!=n5)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_reserve set next error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_destory(n1)!=5)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//cll_is_loop
	testcase=13;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n2,3))==NULL || (n4=cll_insert_data_after(n3,4))==NULL || (n5=cll_insert_data_after(n4,5))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n5)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}	
	if(cll_break(n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "5: cll_break failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n1)==true)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "6: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n2)==true)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "7: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n5)==true)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "8: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}	

	if(cll_link(n2, n3)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "9: cll_link failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n5)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "10: cll_is_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	//�����������������������ٵĽڵ�����һ�����ԣ�
	if(cll_destory(n1)!=5)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "11: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//cll_is_loop
	testcase=14;
	if((n1=cll_insert_data_after(NULL,1))==NULL || (n2=cll_insert_data_after(n1,2))==NULL || (n3=cll_insert_data_after(n2,3))==NULL || (n4=cll_insert_data_after(n3,4))==NULL || (n5=cll_insert_data_after(n4,5))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after nodes failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	//make a small loop (1->2->3->4->5)  ==>  1->2->(3->4->5)  һ�����ű�ʾһ����(head -> tail)
	if(cll_link(n5, n3)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_link failed." << std::endl; 
		cll_destory(n1);
		return false;
	}

	//���κ�һ���ڵ㣨���ܻ���/���⣩�����Բ��Ե�����
	if((loop=cll_find_loop(n1))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_find_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	if((loop!=n3))
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "5: cll_find_loop error." << std::endl; 
		cll_destory(n1);
		return false;
	}
	//the loop port should be found from outside nodes.
	if(cll_find_loop(n1)!=n3 || cll_find_loop(n2)!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "6: cll_find_loop error." << std::endl; 
		//cll_destory(n1);
		return false;
	}
	if(cll_is_loop(n1)==false || cll_find_loop(n2)==false || cll_find_loop(n3)==false || cll_find_loop(n4)==false || cll_find_loop(n5)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "7: cll_is_loop error." << std::endl; 
		//cll_destory(n1);
		return false;
	}
	//cll_find_loop from nodes inside the loop.
	std::cout << "cll_find_loop(n3)=" << cll_find_loop(n4)->data << std::endl; 
	std::cout << "cll_find_loop(n4)=" << cll_find_loop(n4)->data << std::endl; 
	std::cout << "cll_find_loop(n5)=" << cll_find_loop(n5)->data << std::endl; 


	//restore
	if(cll_link(n5, n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "8: cll_link failed." << std::endl; 
		//cll_destory(n1);
		return false;
	}
	//make a small loop (1->2->3->4->5)  ==>  1->2->3->(4->5)  һ�����ű�ʾһ����(head -> tail)
	if(cll_link(n5, n4)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "9: cll_link failed." << std::endl; 
		cll_destory(n1);
		return false;
	}
	//the loop port should be found from outside nodes.
	if(cll_find_loop(n1)!=n4 || cll_find_loop(n2)!=n4 || cll_find_loop(n3)!=n4)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "10: cll_find_loop error." << std::endl; 
		//cll_destory(n1);
		return false;
	}
	//cll_find_loop from nodes inside the loop.
	std::cout << "cll_find_loop(n4)=" << cll_find_loop(n4)->data << std::endl; 
	std::cout << "cll_find_loop(n5)=" << cll_find_loop(n5)->data << std::endl; 

	if(cll_link(n5, n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "11: cll_link failed." << std::endl; 
		//cll_destory(n1);
		return false;
	}
	if(cll_destory(n1)!=5)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "12: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	//ceate a big listed list.
	testcase=15;
	int N=10000;
	cll_node*n=NULL;
	cll_node**ns=(cll_node**) malloc (sizeof(cll_node*)*N);
	for(int i=0;i<N;i++)
	{
		n=cll_insert_data_after(n,i);		
		ns[i]=n;
	}
	for(int i=0;i<N;i++)
	{
		if(ns[i]->data!=i) 
		{
			std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_insert_data_after error." << std::endl; 
			cll_destory(n1);
			return false;
		}
	}

	int a=1000,b=900;
	for(b=200;b<a;b++)
	{
		int port=a>b?b:a;

		//link a loop
		if(cll_link(ns[a], ns[b])==false)
		{
			std::cout << "CASE" << testcase << " ERROR-" <<  "1: cll_link failed." << std::endl; 
			cll_destory(n1);
			return false;
		}

		//the loop port should be found from outside nodes.
		if(cll_find_loop(ns[100])!=ns[port])
		{
			std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_find_loop error." << std::endl; 
			//cll_destory(n1);
			return false;
		}

		//restore
		if(cll_link(ns[a], ns[a+1])==false)
		{
			std::cout << "CASE" << testcase << " ERROR-" <<  "3: cll_link failed." << std::endl; 
			cll_destory(n1);
			return false;
		}
	}


	if(cll_destory(n)!=N)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "4: cll_destory the count of deleted nodes error." << std::endl; 
		return false;
	}

	std::cout << "TEST ALL " << testcase << " CASES SUCCESSFULLY!!!" << std::endl;
	return true;
}


/*
Լɪ�����⣺
��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ��
�ӱ��Ϊ��k�����˿�ʼ������������m�����Ǹ��˳��У�
������һ�����ִӡ�1����ʼ������������m�����Ǹ����ֳ��У�
���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�
���磺n = 6,k = 1,m = 5
�Ƴ�˳��5��4��6��2��3��1��


17���͵ķ�����ѧ�Ҽ�˹���ڡ���Ŀ����Ϸ���⡷�н�������һ�����£�
15����ͽ��15 ���ǽ�ͽ��������գ����뽫һ�����Ͷ�뺣�У�������˲����������ѣ���������һ���취��
30����Χ��һԲȦ���ӵ�һ���˿�ʼ���α�����ÿ�����ھŸ��˾ͽ�������󺣣����ѭ������ֱ������15����Ϊֹ��
�������ŷ�������ʹÿ��Ͷ��󺣵Ķ��Ƿǽ�ͽ��


Լɪ���������⣺
�������������Ϊ1��2��3��...��N��N���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ�����루����������
��ָ�����Ϊ1���˿�ʼ����˳ʱ�뷽����1��ʼ˳����������ָ����Mʱֹͣ������
��M���˳��У���������������Ϊ�µ�Mֵ��������˳ʱ�뷽�����һ���˿�ʼ�����´�1�������������ƣ�ֱ�����е���ȫ������Ϊֹ��
�����һ������������е�˳������N��30��M������ֵ�Ӽ������롣
*/

void Joseph_circle()
{

	//total nodes
	int N=6;

	//the first node (base 1) to count
	int K=1;

	//the turn to move out
	int M=5;

	//create the circle
	cll_node*n=NULL;
	cll_node*knode=NULL;
	for(int i=1;i<=N; i++)
	{
		n=cll_insert_data_after(n,i);
		if(i==K) knode=n;//save the [header] or [current] node your needs.
	}

	bool done=false;
	int i=1;
	while(!done)
	{				
		for(n=knode, i=1; i<M; i++) n = n->next;

		//get the it's next before delete it.
		knode=n->next;

		//the only one node left.
		done= n->next == n;

		//remove out
		std::cout << n->data << " is moved out" << std::endl;
		cll_remove(n);		
	}
}

//����ⷨ
void Joseph_circle_array()
{
	bool a[101]={0};//��������������㣿
	int n,m,i,f=0,t=0,s=0;
	n=6;
	m=5;
	do
	{
		++t;//���ö��Ȧ�е�����λ��
		if(t>n)	t=1;//����ģ�⻷״�����һ�����һ������
		if(!a[t]) s++;//��t��λ������������

		if(s==m)//��ǰ��������m
		{
			s=0;//����������
			std::cout<<t<<' ';//�����ɱ�˱��
			a[t]=1;//�˴�������������Ϊ��
			f++;//��������+1
		}
	}while(f!=n);//ֱ�������˶���ɱ��Ϊֹ
}