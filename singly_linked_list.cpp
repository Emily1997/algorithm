/* 
����Ķ����ʹ��

����һ��ͨ����struct����ά��һ����ص�����-��node�������˽ڵ�ġ�ҵ�����ݡ��⣬��Ӷ��������ʹ����Щ���ݹ���һ������

�����Ŀ�ľ��ǡ���Ч�ʴ���ڵ�֮���˳��/�߼��������͡����顿���ƣ����ǡ����顿��ȱ���ǣ�
�����ȹ̶���-�����ڶ�̬����/�Ƴ�ĳ���ڵ㣬�ؼ��ɱ��ߣ�
��˳��̶���-����˳��ҪŲ��������̫�࣬ʱ��ɱ��ߣ�

��ˣ��������ɫ��������Ĳ����û��һ������ȥ������Ķ�����ά������������������ͨ�����������ӡ��ġ��ڵ㡿�����Լ�ά����������

�����кܶ��ֲ�ͬ�����ͣ���������˫�������Լ�ѭ������

������������򡿣�
1������һ���׽ڵ㣨���ף����Ըı䣩����һ��ĩ�ڵ㣨��β�����Ըı䣩�����ڵ������ʱ�����׺���βΪͬһ���ڵ㡣
2��ÿ���ڵ����һ����Nextָ�롿������β���ġ�Next=NULL���������Ľڵ��Next��������NULL��
3�������ṹһ����ͷ��β��������β���ӣ�Ҳ�����ڻ�·�������г���һ���ڵ����һ���ڵ�ָ��ͬһ���ڵ㣬�����г���һ���ڵ��ǰһ���ڵ�ָ��ͬһ���ڵ㡣

�����������ŵ㡿
1�������ŵ����߼��򵥣��ж��٣�����ʵ�ֿ��ٵ�˳�������
2������/ɾ��/�ƶ��ڵ��޸ĵ����ݺ��٣��������ȡ����ݿ��С���ڵ�λ�õ�����Ժ�С�����ʱ��ɱ�����һ����

����������ȱ�㡿
1��ֻ�ܸ���һ����֪�ڵ��������Ѱ��/����ÿ���ڵ㣬��������֪�ڵ㲻��ͷ�ڵ㣬ֻ�Ჿ�ֵĽڵ���Ա�����������ˣ��㲻�ò�ά�����桾���׽ڵ㡿���Ա�����ȫ������
2���ܷ��㡾˳��������������޷��������������

�����������;��
���������;�ܹ㷺����Ҫ�����Ķ��Ĵ�����ݣ��������ֿ顿��ͨ����������֯������
���������ƶ�������С�������ʵ�ֿ��ٵģ�����顢�ƶ��顢ɾ���顢�޸Ŀ飨���/��С����
1�������ļ������ݣ����ڴ��̿ռ䲻һ��һ���������䣬�ܶ��ļ��Ĳ�����ɾ�ģ�Ҳ�ᵼ�¿ռ���Ƭ������ˣ��ļ����Ƿֿ�洢�ģ�ͷ�鱣����Ŀ¼����ÿ��ָ����һ��ĵ�ַ�����һ���Next��ַΪ�ա�
2�����Ƶ����ΰ�����������ڲ����ڴ������ƣ��ĵ�����ÿ��/�δ洢����
3��������������������������ȶ��Խṹ������Ҫ���ٵĲ���/ɾ��/�ƶ�/�����������ַ��ϡ���������򡿶����Կ��ǲ�����������



��ѭ�����������뵥����һ������һ����ʽ�Ĵ洢�ṹ������ͬ���ǣ�ѭ����������һ������ָ����ָ���ѭ������ĵ�һ�������߱�ͷ��㣬�Ӷ�����һ�����ε�����
ѭ������������뵥������������һ�¡�����ͬ�������¼��㣺
1���ڽ���һ��ѭ������ʱ������ʹ�����һ������ָ��ָ���ͷ��㣬������������������ΪNULL�����������ʹ���������һ���������һ���µĽ�㡣
2�����ж��Ƿ񵽱�βʱ�����жϸý�������ֵ�Ƿ��Ǳ�ͷ��㣬������ֵ���ڱ�ͷָ��ʱ��˵���ѵ���β�����������������ж�����ֵ�Ƿ�ΪNULL��

��˫��������˫��������ʵ�ǵ�����ĸĽ��������ǶԵ�������в���ʱ����ʱ��Ҫ��ĳ������ֱ��ǰ�����в���ʱ���ֱ���ӱ�ͷ��ʼ���ҡ�
�����ɵ�������Ľṹ�����Ƶġ���Ϊ������ÿ�����ֻ��һ���洢ֱ�Ӻ�̽���ַ������
��ô�ܲ��ܶ���һ�����д洢ֱ�Ӻ�̽���ַ���������д洢ֱ��ǰ������ַ�����������һ��˫������ṹ�أ������˫������
��˫�������У����������������⣬������������һ���洢��Next:ֱ�Ӻ�̽��/��ڵ�/�ҽڵ�ĵ�ַ/ָ�롿��
һ���洢��Prev��ֱ��ǰ�����/ǰ�ڵ�/��ڵ�/��ַ/ָ�롿��
��ˣ�˫������ܷ��㡾˳��������͡������������Ҳ����Ҫ����ά��һ����ͷ�ڵ㡿������ν��ͷ�ڵ㡿����Ȼ����һ������ѭ�����������壬����ʱҪע����⡿��
*/


#include <ios>
#include <iostream>


//�ڵ�ṹ
struct sll_node
{
	//��һ���ڵ�/�ҽڵ�
	sll_node*next;//Ƕ�׽ṹ


	//�ڵ����ݣ����԰�������Ҫ��һ��������ݣ�����/�������ޣ��������㷨Ҳ�޹أ�
	//�������Ҳ������һ��ָ�룬ָ��ĳ�����ṹ���ݡ������������ڱ������ǡ�һ������֯�����ݵ������������
	//ͬ�������ݼ�����ʹ�ö����������֯�����������ã�����/��/ջ/����֮�ࡾ��֯�ߡ������Ǹ�����Ҫ-���ݵ�ʹ��ģʽ������֯���ǡ�
	int data;	
};

//�����������ֻ��Ҫһ��������Բ���ȫ�ֱ�����
//���з����ڲ���Ҫ����sll* listָ�롣

//���׽ڵ��ָ��
//������ģʽ������ȷά��һ��ͷָ�룬�����޷�ʵ����ȫ������
//sll_node*header;

//��β�ڵ��ָ��
//���������һ����Ҫ����������Ҫ���Ƿ�ͨ��sll_seek_tail��ѯ��
//sll_node*tail;

//�������������Ҫ�������ʵ���������������ָ�����������׵ĵ�ַ��
struct sll
{
	//���׽ڵ��ָ��
	//������ģʽ������ȷά��һ��ͷָ�룬�����޷�ʵ����ȫ������
	sll_node*header;

	//��β�ڵ��ָ��
	//���������һ����Ҫ����������Ҫ���Ƿ�ͨ��sll_seek_tail��ѯ��
	sll_node*tail;
};
sll* sll_create()
{
	sll*new_sll=new sll();
	new_sll->header=NULL;
	new_sll->tail=NULL;

	return new_sll;
}

//�����Ƿ�Ϊ��
bool sll_is_empty(sll* list)
{
	if(list==NULL) return true;
	return list->header==NULL;
}
void sll_display(sll* list)
{
	if(sll_is_empty(list))
	{
		std::cout << "sll_display: the linked list is empty!" << std::endl;;
		return;
	}
	//����
	int i=0;
	sll_node*n=list->header;
	while(n!=NULL)
	{
		std::cout << "node[" << i++ << "]=" << n->data << std::endl;
		n=n->next;
	}
}

//����û�м�������Ľڵ�
sll_node* sll_create_node(int data)
{
	//����2���Ч
	sll_node*new_node=new  sll_node();
	//ll_node*new_node=(ll_node*)malloc(sizeof(ll_node));

	new_node->next=NULL;//���븳ֵNULL����������ֵ��δ֪�ģ�

	//���ƽڵ�����
	new_node->data=data;

	return new_node;
}

//�������׽ڵ㣨���������ѡ������κεĵ�һ���ڵ㶼���Զ���Ϊ���ף�
//data���ڵ����ݣ����Դ����������ݣ�Ҳ���Բ��������ݣ��ڷ��صĽڵ�
sll_node* sll_create_header(sll* list, int data)
{
	if(list==NULL)
	{
		std::cout << "sll_create_header: list is NULL!" << std::endl;
		return NULL;
	}

	//ÿ�νڵ㶼������������
	sll_node*new_node=sll_create_node(data);

	//���׽ڵ�
	list->header=new_node;

	//��β�ڵ�
	list->tail=new_node;

	//����һ������������߼���

	//���ر�ͷ�ڵ㣬�����ȫ�ֱ�����һ����Ҫ��
	//������ȫû��ȫ�ֱ���ʱ������ͷ�ڵ����������Ҫ�ˣ�����������Ͷ��ˣ�
	return new_node;
}

//����֪�ڵ��ǰ�ڵ�
//��ͷ�ڵ㿪ʼ�������ҵ���֪�ڵ��ǰһ�ڵ㡣
//����ǵ�����ľ����ԣ�ʱ��ɱ��ܸߣ���������������������򣬲���˫������
//node����֪�ڵ㣬���׽ڵ㱾����NULL��
sll_node*sll_seek_prev(sll* list, sll_node*node)
{
	if(list==NULL)
	{
		std::cout << "sll_seek_prev: list is NULL!" << std::endl;
		return NULL;
	}

	if(sll_is_empty(list))
	{
		std::cout << "sll_seek_prev: The linked list is empty!" << std::endl;
		return NULL;
	}

	if(node==NULL)
	{
		std::cout << "sll_seek_prev: the node is NULL!" << std::endl;
		return NULL;	
	}	

	//���׽ڵ�û�С�ǰ�ڵ㡿
	if(node==list->header) return NULL;

	//�����׿�ʼ����
	sll_node*n=list->header;
	while(n != NULL)
	{
		if(n->next == node) return n;

		n=n->next;
	}

	//��Ч�Ľڵ㣨�����ϲ����ܣ�
	std::cout << "sll_seek_prev: The previous node can not be found! The specified node may had been moved out." << std::endl;
	return NULL;
}

//ȷ����β
sll_node*sll_seek_tail(sll* list)
{
	if(list==NULL)
	{
		std::cout << "sll_seek_tail: list is NULL!" << std::endl;
		return NULL;
	}

	if(sll_is_empty(list))
	{
		return NULL;
	}

	//�����׿�ʼ����
	sll_node*n=list->header;
	while(n != NULL)
	{
		if(n->next == NULL) return n;

		n=n->next;
	}

	//��Ч�Ľڵ㣨�����ϲ����ܣ�
	return NULL;
}

//��ȡ��ָ���Ľڵ㵽��β�ĳ���
//fromΪNULL�������׿�ʼ�ĳ��ȣ���������ĳ��ȣ�
int sll_deepth(sll* list, sll_node*from)
{
	if(list==NULL)
	{
		std::cout << "sll_seek_loop_node: list is NULL!" << std::endl;
		return 0;
	}

	if(sll_is_empty(list))
	{
		std::cout << "sll_seek_loop_node: The linked list is empty!" << std::endl;
		return 0;
	}

	if(from==NULL)
	{		
		return sll_deepth(list,list->header);	
	}	

	//��ʼ����
	int count=0;
	sll_node*n=from;
	while(n != NULL)
	{
		if(n->next == NULL) return count;

		n=n->next;
		count++;
	}
	return count;
}

//����һ���½ڵ�new_node����֪�ڵ�existing_node�ĺ���/�ұ�
//existing_nodeΪNULL��������β֮��
bool sll_insert_node_after(sll* list,sll_node* new_node, sll_node*existing_node)
{
	if(list==NULL)
	{
		std::cout << "sll_insert_node_after: list is NULL!" << std::endl;
		return false;
	}

	if(sll_is_empty(list))
	{
		new_node->next=NULL;
		list->header=new_node;
		list->tail=new_node;
		return true;
	}

	if(existing_node==NULL)
	{
		return sll_insert_node_after(list, new_node, list->tail);		
	}
	else
	{		
		//��������ԭ����������������˳�����Ҫ��
		new_node->next = existing_node->next;
		existing_node->next = new_node;

		//�µ���β
		if(new_node->next==NULL) list->tail=new_node;

		return true;
	}
}

//����һ���½ڵ�new_node����֪�ڵ��existing_nodeǰ��/���
//existing_nodeΪNULL��Ҫ��������֮ǰ
bool sll_insert_node_before(sll* list, sll_node*new_node, sll_node* existing_node)
{
	if(list==NULL)
	{
		std::cout << "sll_insert_node_before: list is NULL!" << std::endl;
		return false;
	}

	if(sll_is_empty(list))
	{
		new_node->next=NULL;
		list->header=new_node;
		list->tail=new_node;
		return true;
	}

	if(existing_node==NULL)
	{
		return sll_insert_node_before(list, new_node, list->header);		
	}
	else
	{
		if( existing_node==list->header)
		{
			new_node->next=list->header;

			//���붼ͷ�����������µ����ף�
			//ע�⣺������һ����ȷ��headerָ�룬��������ı���������⣡
			list->header=new_node;
		}
		else
		{
			sll_node* prev_node=sll_seek_prev(list, existing_node);
			new_node->next=prev_node->next;
			prev_node->next=new_node;
		}
	}
	return true;
}
//��һ���������뵽���������ָ���ڵ�֮��/��
//existing_nodeΪNULL�����뵽��β
bool sll_merge_after(sll* list, sll_node* existing_node, sll* sublist)
{
	if(list==NULL)
	{
		std::cout << "sll_merge_after: list is NULL!" << std::endl;
		return false;
	}
	if(sll_is_empty(sublist))
	{		
		std::cout << "sll_merge_after: sublist is empty!" << std::endl;
		return false;
	}

	if(sll_is_empty(list))
	{
		list->header=sublist->header;
		list->tail=sublist->tail;
		return true;
	}

	if(existing_node==NULL)
	{
		return sll_merge_after(list,list->tail, sublist);
	}
	else
	{
		sublist->tail->next = existing_node->next;
		existing_node->next=sublist->header;
		if(sublist->tail->next == NULL) list->tail=sublist->tail;
		return true;
	}
}
//��һ���������뵽���������ָ���ڵ�֮ǰ/��
//existing_nodeΪNULL�����뵽����֮ǰ/��
bool sll_merge_before(sll* list, sll_node* existing_node, sll* sublist)
{
	if(list==NULL)
	{
		std::cout << "sll_merge_before: list is NULL!" << std::endl;
		return false;
	}
	if(sll_is_empty(sublist))
	{		
		std::cout << "sll_merge_before: sublist is empty!" << std::endl;
		return false;
	}

	if(sll_is_empty(list))
	{
		list->header=sublist->header;
		list->tail=sublist->tail;
		return true;
	}

	if(existing_node==NULL)
	{
		return sll_merge_before(list,list->header, sublist);
	}
	else
	{
		if( existing_node==list->header)
		{
			sublist->tail->next=list->header;

			//���붼ͷ�����������µ����ף�
			list->header=sublist->header;
		}
		else
		{
			sll_node* prev_node=sll_seek_prev(list, existing_node);
			sublist->tail->next=prev_node->next;
			prev_node->next=sublist->header;
		}		
	}
	return true;
}
//����һ���ڵ㵽��֪�ڵ�ĺ���/�ұ�
//existing_nodeΪNULL��������β֮��
sll_node* sll_insert_after(sll* list, sll_node*existing_node, int data)
{
	if(list==NULL)
	{
		std::cout << "sll_insert_after: list is NULL!" << std::endl;
		return false;
	}
	sll_node* new_node=sll_create_node(data);
	if(sll_insert_node_after(list, new_node, existing_node)==false) return NULL;
	return new_node;
}

//����һ���ڵ㵽��֪�ڵ��ǰ��/���
//existing_nodeΪNULL��Ҫ��������֮ǰ
sll_node* sll_insert_before(sll* list, sll_node*existing_node, int data)
{
	if(list==NULL)
	{
		std::cout << "sll_insert_before: list is NULL!" << std::endl;
		return false;
	}
	sll_node* new_node=sll_create_node(data);
	if(sll_insert_node_before(list, new_node, existing_node)==false) return NULL;
	return new_node;
}


//����֪�ڵ�prev_node����һ���ڵ��Ƴ�������ɾ����
//node��Ҫ�Ƴ��Ľڵ㣬������ΪNULL��
bool sll_moveout_node(sll* list, sll_node*node)
{
	if(sll_is_empty(list))
	{
		std::cout << "sll_moveout_node: The linked list is empty!" << std::endl;
		return false;
	}

	if(node==NULL)
	{
		std::cout << "sll_moveout_node: the node is NULL!" << std::endl;
		return false;	
	}


	//�Ƴ�������
	if(node==list->header)
	{							
		sll_node* next_node = node->next;

		//ֻ��һ�����׽ڵ�ʱ���������Ƴ����׽ڵ㣡
		if(next_node==NULL) 
		{
			std::cout << "sll_moveout_node: The only one node can not be moved out!" << std::endl;
			return false;
		}

		//�������׽ڵ�
		list->header = node->next;
	}
	else
	{		
		//�����Ƴ����ף�prev_nodeһ�����ڡ�
		sll_node* prev_node=sll_seek_prev(list, node);

		sll_node* next_node = node->next;	

		//�Ƴ�����β��
		if(next_node == NULL)
		{
			//�µ���β�ڵ㣡
			prev_node->next=NULL;
			list->tail=prev_node;
		}
		else
		{
			//�Ƴ��м�ڵ㣺����Ҫ�Ķ�һ��ָ�룡����ǡ����õĽṹ���ԡ�����ļ򻯡���
			prev_node->next = node->next;
		}
	}
	return true;
}



//ɾ����֪�ڵ�ĺ�һ���ڵ�
//node:��֪�ڵ�
bool sll_remove(sll* list, sll_node*node)
{
	if(node==NULL)
	{
		std::cout << "sll_remove: the node is NULL!" << std::endl;
		return false;
	}
	else
	{
		if(node==list->header && node==list->tail)
		{
			list->header=NULL;
			list->tail=NULL;
			delete node;
		}
		else
		{
			sll_moveout_node(list, node);
			delete node;
		}
	}
	return true;
}


//�ƶ�ָ���ڵ�node��exiting_node�ڵ�֮��
//exiting_nodeΪNULL���Ƶ���β
bool sll_move_node_after(sll* list, sll_node*node,sll_node*exiting_node)
{
	if(node==NULL)
	{
		std::cout << "sll_move_node_after: the node is NULL!" << std::endl;
		return false;
	}
	if(sll_moveout_node(list, node))
	{
		if(sll_insert_node_after(list, node, exiting_node))
		{
			return true;
		}
	}
	return false;
}

//�ƶ�ָ���ڵ�node��exiting_node�ڵ�֮ǰ
//exiting_nodeΪNULL���Ƶ�����
bool sll_move_node_before(sll* list, sll_node*node,sll_node*exiting_node)
{
	if(node==NULL)
	{
		std::cout << "sll_move_node_before: the node is NULL!" << std::endl;
		return false;
	}
	if(sll_moveout_node(list, node))
	{
		if(sll_insert_node_before(list, node, exiting_node))
		{
			return true;
		}
	}
	return false;
}
//��������
//from����ʼ��ѯ�Ľڵ㣬NULL��ʾ�����׿�ʼ��ѯ
sll_node* sll_find_data(sll*list, sll_node*from, int data)
{
	if(sll_is_empty(list))
	{
		std::cout << "sll_find_data: The linked list is empty!" << std::endl;
		return NULL;
	}

	sll_node*n=from;
	if(n==NULL) n=list->header;
	while(n!=NULL)
	{
		if(n->data==data) return n;
		n=n->next;
	}
	return NULL;
}

//��ת/������������ת
bool sll_reverse(sll*list)
{
	if(sll_is_empty(list))
	{
		std::cout << "sll_reverse: The linked list is empty!" << std::endl;
		return false;
	}

	//����ԭ�еĴ����߼�ʵ�֣��߼��򵥣�ʱ��ɱ�������ĸߣ�
	//����Ƴ��󲢲��end֮���м䲻������Ч�ʱȡ�����ÿ�����������ã�
	//1234,1->4��2341����2->4��3421����3->4��4321����
	/*
	sll_node*start_moving=list->header;
	sll_node*end=list->tail;
	while(start_moving!=end)
	{		
		//prepare the next node of moving
		sll_node*next_start_moving = start_moving->next;
		
		if(sll_moveout_node(list, start_moving)==false) return false;

		if(sll_insert_node_after(list, start_moving, end)==false) return false;
		
		start_moving = next_start_moving;
	}
	*/

	//ÿ�η�תһ��Nextָ�룡
	//ԭ˳��1 -> 2 -> 3 -> 4   
	//��һ�Σ�1 <- 2 -> 3 -> 4
	//�ڶ��Σ�1 <- 2 <- 3 -> 4
	//�����Σ�1 <- 2 <- 3 <- 4
	sll_node*node1=list->header;
	sll_node*node2=node1->next;
	sll_node*node3;

	//reverse each node up to tail (not include tail) 
	//one node list will no reverse
	while(node1 != list->tail)
	{
		std::cout << node1->data << std::endl;
		//��ǰ����Next�ڵ���һ��ѭ����node2��
		node3=node2->next;

		//��תһ��ָ�룡
		node2->next=node1;
				
		//����һ��[node1->node2->node3]->node4 ==> node1<-[node2 node3<-node4]
		node1=node2;		
		node2=node3;
	}

	sll_node*e=list->tail;
	list->tail=list->header;
	list->header=e;
	list->tail->next=NULL;
	return true;
}

//ʹ�õ�������ѭ������
void sll_circulate(sll* list)
{
	if(list!=NULL) 
	{
		list->tail->next=list->header;
	}
}

unsigned int sll_destory(sll* list)
{
	unsigned int count=0;
	if(list!=NULL)
	{
		sll_node*n=list->header;
		while(n != NULL)
		{
			sll_node*nn=n->next;		
			//std::cout << "delete " << n->data << std::endl; 
			delete n;	
			count++;
			n=nn;
		}
		list->header=NULL;
		list->tail=NULL;
		delete list;
	}

	return count;
}

//������Լ���дһ���������룬�����������㷨��
//Ȼ��ʹ�����²�������������Ķ�ջ�Ƿ���ȫ��ȷ��
bool sll_test()
{
	sll*list=sll_create();
	sll_node*n1=NULL;
	sll_node*n2=NULL;
	sll_node*n3=NULL;
	sll_node*n4=NULL;
	sll_node*n5=NULL;

	int testcase=0;

	testcase=1;
	std::cout << "CASE" << testcase << std::endl;
	try
	{
		sll_destory(list);
	}
	catch(...)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_destory with empty list failed." << std::endl; 
		return false;
	}

	//insert the first node
	testcase=2;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	if((n1=sll_insert_before(list,NULL,1))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" <<  "1: sll_insert_before with empty list failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "2: sll_insert_before next error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "3: sll_insert_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail != n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "4: sll_insert_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(sll_destory(list)!=1)
	{
		std::cout << "CASE" << testcase << " ERROR" <<  "-5: sll_destory deleted nodes error." << std::endl; 
		return false;
	}

	//insert the first node
	testcase=3;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	if((n1=sll_insert_after(list,NULL,1))==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "1: insert the first node error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "2: sll_insert_before next error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "3: sll_insert_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail != n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "4: sll_insert_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(sll_destory(list)!=1)
	{
		std::cout << "CASE" << testcase << " ERROR" <<  "5: sll_destory deleted nodes error." << std::endl; 
		return false;
	}

	//insert 2 nodes to tail
	testcase=4;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,2);
	if(n1==NULL || n2==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_insert_after other node failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=n2 || n2->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "1: sll_insert_after error on order." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "2: sll_insert_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "3: sll_insert_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(sll_destory(list)!=2)
	{
		std::cout << "CASE" << testcase << " ERROR" <<  "-4: sll_destory deleted nodes error." << std::endl; 
		return false;
	}

	//insert 2 nodes to tail with NULL
	testcase=5;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,NULL,2);
	if(n1==NULL || n2==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_insert_after other node failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=n2 || n2->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_insert_after error on order." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_insert_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_insert_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(sll_destory(list)!=2)
	{
		std::cout << "CASE" << testcase << " ERROR" <<  "-4: sll_destory deleted nodes error." << std::endl; 
		return false;
	}

	//insert 2 nodes before NULL
	testcase=6;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_before(list,NULL,1);
	n2=sll_insert_before(list,NULL,2);
	if(n1==NULL || n2==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_insert_before failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_insert_before error on order." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_insert_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_insert_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//insert node before another
	testcase=7;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_before(list,NULL,1);
	n2=sll_insert_before(list,n1,2);
	if(n1==NULL || n2==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_insert_before failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_insert_before error on order." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_insert_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_insert_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//insert after a node with next node
	testcase=8;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,NULL,2);
	n3=sll_insert_after(list,n1,3);
	if(n3==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_insert_after other node has next node failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//move node with no changing
	testcase=9;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_before(list,n1,2);
	if(sll_move_node_after(list,n2,n1)==false || n1->next!=n2 || n2->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_move_node_after (not changing) error with order." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//exchange 2 nodes
	testcase=10;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_before(list,n1,2);
	if(sll_move_node_after(list,n1,n2)==false || n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_move_node_after error with order." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_move_node_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_move_node_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//move to tail
	testcase=11;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,2);
	n3=sll_insert_after(list,n2,3);
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_insert_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_insert_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}

	if(sll_move_node_after(list,n2,NULL)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_move_node_after to tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n3->next!= n2 || n2->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_move_node_after order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-5: sll_move_node_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-6: sll_move_node_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//move tail to header
	testcase=12;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,2);
	n3=sll_insert_after(list,n2,3);
	if(sll_move_node_before(list,n3,NULL)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_move_node_before to tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n3->next!=n1 || n1->next!=n2 || n2->next!=NULL)
	{	
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_move_node_before order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_move_node_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_move_node_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//move middle node to header
	testcase=13;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,2);
	n3=sll_insert_after(list,n2,3);
	if(sll_move_node_before(list,n2,list->header)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_move_node_after to header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n2->next!=n1 || n1->next!=n3 || n3->next!=NULL)
	{	
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_move_node_before order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_move_node_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_move_node_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//remove the first node
	testcase=14;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	if(sll_remove(list, n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_remove the only one node failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_remove the only one node set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_remove the only one node set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//remove header
	testcase=15;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,1);
	if(sll_remove(list, n1)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_remove header failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_remove the only one node set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_remove the only one node set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);


	//remove tail
	testcase=16;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,1);
	if(sll_remove(list, n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_remove tail failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_remove tail set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_remove tail set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);


	//remove middle
	testcase=17;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,1);
	n3=sll_insert_after(list,n2,1);
	if(sll_remove(list, n2)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_remove middle failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=n3 || n3->next!=NULL)
	{	
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_move_node_before order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_remove middle set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_remove middle set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//insert before tail
	testcase=18;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);
	n2=sll_insert_after(list,n1,1);
	n3=sll_insert_before(list,n2,1);
	if(n3==NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-0: sll_insert_before tail failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=n3 || n3->next!=n2 || n2->next!=NULL)
	{	
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_insert_before order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_insert_before middle set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_remove middle set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//merge into empty list
	testcase=19;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	sll*sublist=sll_create();
	n1=sll_insert_after(sublist,NULL,1);
	if(sll_merge_after(list,NULL,sublist)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_merge_after failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_merge_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_merge_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);
	//sll_destory(sublist);

	//merge after one node list
	testcase=20;	
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	sublist=sll_create();
	n2=sll_insert_after(sublist,NULL,2);
	if(sll_merge_after(list,n1,sublist)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_merge_after failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_merge_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_merge_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);
	//sll_destory(sublist);

	//merge before one node list
	testcase=21;	
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	sublist=sll_create();
	n2=sll_insert_after(sublist,NULL,2);
	if(sll_merge_before(list,n1,sublist)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_merge_before failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_merge_before order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_merge_before set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_merge_before set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);
	//sll_destory(sublist);

	//merge into midder of list
	testcase=22;	
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	n2=sll_insert_after(list,NULL,2);	
	n3=sll_insert_after(list,NULL,3);	
	sublist=sll_create();
	n4=sll_insert_after(sublist,NULL,400);
	n5=sll_insert_after(sublist,NULL,500);
	if(sll_merge_after(list,n2,sublist)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_merge_after failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n2->next!=n4 || n4->next!=n5 || n5->next!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_merge_after order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_merge_after set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_merge_after set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	//sll_display(list);
	sll_destory(list);
	//sll_destory(sublist);

	//reverse of 1 node list
	testcase=26;	
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	if(sll_reverse(list)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_reverse 1 node failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_reverse order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_reverse set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_reverse set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//reverse of 2 nodes list
	testcase=27;	
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	n2=sll_insert_after(list,NULL,2);	
	if(sll_reverse(list)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_reverse 2 nodes failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_reverse order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n2)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_reverse set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_reverse set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//reverse of 3 nodes list
	testcase=30;
	std::cout << "CASE" << testcase << std::endl;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	n2=sll_insert_after(list,NULL,2);	
	n3=sll_insert_after(list,NULL,3);		
	if(sll_reverse(list)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_reverse 3 nodes failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	//sll_display(list);
	if(n3->next!=n2 || n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_reverse order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n3)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_reverse set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_reverse set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);

	//reverse of 5 nodes list: 12345 -> 54321
	testcase=31;	
	std::cout << "CASE" << testcase << std::endl;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();
	n1=sll_insert_after(list,NULL,1);	
	n2=sll_insert_after(list,NULL,2);	
	n3=sll_insert_after(list,NULL,3);		
	n4=sll_insert_after(list,NULL,4);		
	n5=sll_insert_after(list,NULL,5);		
	if(sll_reverse(list)==false)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: sll_reverse 3 nodes failed." << std::endl; 
		sll_destory(list);
		return false;
	}
	//sll_display(list);
	if(n5->next!=n4 || n4->next!=n3 || n3->next!=n2 ||  n2->next!=n1 || n1->next!=NULL)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: sll_reverse order error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->header!=n5)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: sll_reverse set header error." << std::endl; 
		sll_destory(list);
		return false;
	}
	if(list->tail!=n1)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: sll_reverse set tail error." << std::endl; 
		sll_destory(list);
		return false;
	}
	sll_destory(list);




	//ceate a big listed list.
	testcase=99;
	std::cout << "CASE" << testcase << std::endl;
	list=sll_create();	
	sll_node*n=NULL;
	int i=0;
	for(;i<10000;i++)
	{
		n=sll_insert_after(list,n,i);		
	}
	if( list->tail->data!=9999)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-1: the tail node error." << std::endl; 
		sll_destory(list);
		return false;
	}

	for(;i<20000;i++)
	{
		n=sll_insert_before(list,n,i);		
	}
	if( list->tail->data!=9999)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-2: the tail node error." << std::endl; 
		sll_destory(list);
		return false;
	}


	for(;i<30000;i++)
	{
		n=sll_insert_before(list,NULL,i);		
	}
	if(n != list->header)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-3: the header node error." << std::endl; 
		sll_destory(list);
		return false;
	}

	for(;i<40000;i++)
	{
		n=sll_insert_after(list,NULL,i);		
	}
	if(list->tail->data!=39999)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-4: the header node error." << std::endl; 
		sll_destory(list);
		return false;
	}

	int d=sll_deepth(list,NULL);
	std::cout << "total nodes: " << d << std::endl; 

	if(d!=39999)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-5: sll_deepth error." << d << std::endl; 
		sll_destory(list);
		return false;
	}

	if(sll_destory(list)!=40000)
	{
		std::cout << "CASE" << testcase << " ERROR" << "-5: sll_destory deleted nodes error." << d << std::endl; 
		return false;
	}

	std::cout << "TEST ALL " << testcase << " CASES SUCCESSFULLY!!!" << std::endl;
	return true;
}

