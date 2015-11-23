/* 
链表的定义和使用

链表一般通过【struct】来维护一组相关的数据-【node】，除了节点的【业务数据】外，添加额外的数据使得这些数据构成一个链。

链表的目的就是【高效率处理节点之间的顺序/逻辑】，它和【数组】类似，但是【数组】的缺点是：
【长度固定】-不利于动态插入/移除某个节点，控件成本高；
【顺序固定】-调整顺序要挪动的数据太多，时间成本高；

因此，链表的特色（和数组的差别）是没有一个看上去像数组的东西来维护【整个链表】，而是通过【互相连接】的【节点】本身自己维护整个链表。

链表有很多种不同的类型：单向链表，双向链表以及循环链表。

【单向链表规则】：
1：包含一个首节点（链首，可以改变），和一个末节点（链尾，可以改变），单节点的链表时，链首和链尾为同一个节点。
2：每个节点包含一个【Next指针】，【链尾】的【Next=NULL】，其它的节点的Next均不等于NULL。
3：单链结构一定有头和尾，不会首尾链接，也不存在环路，不会有超过一个节点的下一个节点指向同一个节点，不会有超过一个节点的前一个节点指向同一个节点。

【单向链表优点】
1：它的优点是逻辑简单，判断少，可以实现快速的顺序遍历。
2：插入/删除/移动节点修改的数据很少，与链表长度、数据块大小、节点位置的相关性很小，最大时间成本几乎一样。

【单向链表缺点】
1：只能根据一个已知节点或链首来寻找/遍历每个节点，如果这个已知节点不是头节点，只会部分的节点可以被遍历到，因此，你不得不维护保存【链首节点】，以便于完全遍历。
2：很方便【顺序遍历】，但是无法【反序遍历】。

【单链表的用途】
单链表的用途很广泛，需要经常改动的大块数据，往往【分块】后通过【链表】组织起来，
可以整体移动数据最小的情况下实现快速的：插入块、移动块、删除块、修改块（变大/变小）。
1：磁盘文件的数据：由于磁盘空间不一定一个连续分配，很多文件的不断增删改，也会导致空间碎片化，因此，文件都是分块存储的，头块保存在目录区，每块指向下一块的地址，最后一块的Next地址为空。
2：类似的情形包括：计算机内部的内存分配机制，文档处理【每行/段存储】。
3：队列问题解决：不像数组哪里“稳定性结构”，需要快速的插入/删除/移动/伸缩，而且又符合【单链表规则】都可以考虑采用它来处理。



【循环链表】：是与单链表一样，是一种链式的存储结构，所不同的是，循环链表的最后一个结点的指针是指向该循环链表的第一个结点或者表头结点，从而构成一个环形的链。
循环链表的运算与单链表的运算基本一致。所不同的有以下几点：
1、在建立一个循环链表时，必须使其最后一个结点的指针指向表头结点，而不是象单链表那样置为NULL。此种情况还使用于在最后一个结点后插入一个新的结点。
2、在判断是否到表尾时，是判断该结点链域的值是否是表头结点，当链域值等于表头指针时，说明已到表尾。而非象单链表那样判断链域值是否为NULL。

【双向链表】：双向链表其实是单链表的改进。当我们对单链表进行操作时，有时你要对某个结点的直接前驱进行操作时，又必须从表头开始查找。
这是由单链表结点的结构所限制的。因为单链表每个结点只有一个存储直接后继结点地址的链域，
那么能不能定义一个既有存储直接后继结点地址的链域，又有存储直接前驱结点地址的链域的这样一个双链域结点结构呢？这就是双向链表。
在双向链表中，结点除含有数据域外，还有两个链域，一个存储【Next:直接后继结点/后节点/右节点的地址/指针】；
一个存储【Prev：直接前驱结点/前节点/左节点/地址/指针】。
因此，双向链表很方便【顺序遍历】和【反序遍历】，也不需要单个维护一个【头节点】或无所谓【头节点】，当然它有一个【死循环的填入陷阱，遍历时要注意避免】。
*/


#include <ios>
#include <iostream>


//节点结构
struct sll_node
{
	//下一个节点/右节点
	sll_node*next;//嵌套结构


	//节点数据（可以包含你需要的一个多个数据，类型/数量无限，和以下算法也无关）
	//这个数据也可以是一个指针，指向某个【结构数据】，这样，等于本链表是【一组无组织的数据的体外的链表】，
	//同样的数据集可以使用多个链表来组织起来，或者用：数组/树/栈/链表之类【组织者】将他们根据需要-数据的使用模式，来组织它们。
	int data;	
};

//如果整个程序只需要一个链表可以采用全局变量。
//所有方法内不需要传递sll* list指针。

//链首节点的指针
//单链表模式必须正确维护一个头指针，否则无法实现完全遍历。
//sll_node*header;

//链尾节点的指针
//这个变量不一定需要，可以在需要的是否通过sll_seek_tail查询。
//sll_node*tail;

//如果整个程序需要多个链表实例，必须采用类似指针来保存链首的地址。
struct sll
{
	//链首节点的指针
	//单链表模式必须正确维护一个头指针，否则无法实现完全遍历。
	sll_node*header;

	//链尾节点的指针
	//这个变量不一定需要，可以在需要的是否通过sll_seek_tail查询。
	sll_node*tail;
};
sll* sll_create()
{
	sll*new_sll=new sll();
	new_sll->header=NULL;
	new_sll->tail=NULL;

	return new_sll;
}

//链表是否为空
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
	//遍历
	int i=0;
	sll_node*n=list->header;
	while(n!=NULL)
	{
		std::cout << "node[" << i++ << "]=" << n->data << std::endl;
		n=n->next;
	}
}

//创建没有加入链表的节点
sll_node* sll_create_node(int data)
{
	//以下2句等效
	sll_node*new_node=new  sll_node();
	//ll_node*new_node=(ll_node*)malloc(sizeof(ll_node));

	new_node->next=NULL;//必须赋值NULL，否则它的值是未知的！

	//复制节点数据
	new_node->data=data;

	return new_node;
}

//创建链首节点（这个方法可选，添加任何的第一个节点都会自动作为链首）
//data：节点数据，可以传入所有数据，也可以不传入数据，在返回的节点
sll_node* sll_create_header(sll* list, int data)
{
	if(list==NULL)
	{
		std::cout << "sll_create_header: list is NULL!" << std::endl;
		return NULL;
	}

	//每次节点都是立即创建的
	sll_node*new_node=sll_create_node(data);

	//链首节点
	list->header=new_node;

	//链尾节点
	list->tail=new_node;

	//创建一个链表的其它逻辑。

	//返回表头节点，如果有全局变量不一定需要。
	//但是完全没有全局变量时，返回头节点就是至关重要了，否则，这个链就丢了！
	return new_node;
}

//找已知节点的前节点
//从头节点开始遍历，找到已知节点的前一节点。
//这就是单链表的局限性！时间成本很高，尽量避免这个操作，否则，采用双向链表。
//node：已知节点，链首节点本身返回NULL。
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

	//链首节点没有【前节点】
	if(node==list->header) return NULL;

	//从链首开始遍历
	sll_node*n=list->header;
	while(n != NULL)
	{
		if(n->next == node) return n;

		n=n->next;
	}

	//无效的节点（理论上不可能）
	std::cout << "sll_seek_prev: The previous node can not be found! The specified node may had been moved out." << std::endl;
	return NULL;
}

//确定链尾
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

	//从链首开始遍历
	sll_node*n=list->header;
	while(n != NULL)
	{
		if(n->next == NULL) return n;

		n=n->next;
	}

	//无效的节点（理论上不可能）
	return NULL;
}

//获取从指定的节点到结尾的长度
//from为NULL：从链首开始的长度（整个链表的长度）
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

	//开始遍历
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

//插入一个新节点new_node到已知节点existing_node的后面/右边
//existing_node为NULL：插入链尾之后。
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
		//把它链入原来的链表，以下语句的顺序很重要！
		new_node->next = existing_node->next;
		existing_node->next = new_node;

		//新的链尾
		if(new_node->next==NULL) list->tail=new_node;

		return true;
	}
}

//插入一个新节点new_node到已知节点的existing_node前面/左边
//existing_node为NULL：要插入链首之前
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

			//插入都头，等于有了新的链首！
			//注意：必须有一个正确的header指针，否则后续的遍历会出问题！
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
//将一个子链表并入到现有链表的指定节点之后/右
//existing_node为NULL：接入到链尾
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
//将一个子链表并入到现有链表的指定节点之前/左
//existing_node为NULL：接入到链首之前/左
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

			//插入都头，等于有了新的链首！
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
//插入一个节点到已知节点的后面/右边
//existing_node为NULL：插入链尾之后。
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

//插入一个节点到已知节点的前面/左边
//existing_node为NULL：要插入链首之前
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


//把已知节点prev_node的下一个节点移出链表（不删除）
//node：要移出的节点，不允许为NULL。
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


	//移出换链首
	if(node==list->header)
	{							
		sll_node* next_node = node->next;

		//只有一个链首节点时，不允许移出链首节点！
		if(next_node==NULL) 
		{
			std::cout << "sll_moveout_node: The only one node can not be moved out!" << std::endl;
			return false;
		}

		//重设链首节点
		list->header = node->next;
	}
	else
	{		
		//不是移出链首，prev_node一定存在。
		sll_node* prev_node=sll_seek_prev(list, node);

		sll_node* next_node = node->next;	

		//移出换链尾！
		if(next_node == NULL)
		{
			//新的链尾节点！
			prev_node->next=NULL;
			list->tail=prev_node;
		}
		else
		{
			//移出中间节点：仅需要改动一个指针！这就是【良好的结构】对【代码的简化】！
			prev_node->next = node->next;
		}
	}
	return true;
}



//删除已知节点的后一个节点
//node:已知节点
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


//移动指定节点node到exiting_node节点之后
//exiting_node为NULL：移到链尾
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

//移动指定节点node到exiting_node节点之前
//exiting_node为NULL：移到链首
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
//查找数据
//from：开始查询的节点，NULL表示从链首开始查询
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

//翻转/反序整个链表翻转
bool sll_reverse(sll*list)
{
	if(sll_is_empty(list))
	{
		std::cout << "sll_reverse: The linked list is empty!" << std::endl;
		return false;
	}

	//利用原有的代码逻辑实现（逻辑简单，时间成本比下面的高）
	//逐个移除后并插回end之后，中间不调换，效率比【依次每两个调换】好！
	//1234,1->4后（2341），2->4后（3421），3->4后（4321）。
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

	//每次翻转一个Next指针！
	//原顺序：1 -> 2 -> 3 -> 4   
	//第一次：1 <- 2 -> 3 -> 4
	//第二次：1 <- 2 <- 3 -> 4
	//第三次：1 <- 2 <- 3 <- 4
	sll_node*node1=list->header;
	sll_node*node2=node1->next;
	sll_node*node3;

	//reverse each node up to tail (not include tail) 
	//one node list will no reverse
	while(node1 != list->tail)
	{
		std::cout << node1->data << std::endl;
		//提前备份Next节点下一次循环的node2）
		node3=node2->next;

		//翻转一个指针！
		node2->next=node1;
				
		//后移一个[node1->node2->node3]->node4 ==> node1<-[node2 node3<-node4]
		node1=node2;		
		node2=node3;
	}

	sll_node*e=list->tail;
	list->tail=list->header;
	list->header=e;
	list->tail->next=NULL;
	return true;
}

//使得单链表变成循环链表
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

//你必须自己重写一遍上述代码，以熟练掌握算法。
//然后使用以下测试用例测试你的堆栈是否完全正确。
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

