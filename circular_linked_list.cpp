/* 
循环链表：
是与单链表一样，是一种链式的存储结构，所不同的是，循环链表的最后一个结点的指针是指向该循环链表的第一个结点或者表头结点，
从而构成一个环形的链（单环结构）。

它的规则如下：

1、在建立一个循环链表时，从添加第一个节点开始就是首尾相连的，所有节点都是【Next!=NULL】。
2、只允许一个节点（不允许操作一个节点）的Next指向同一个节点，导致小循环，而破坏真个循环。
3、在插入和移出时，需要保持【Next】的单链和循环关系，但是不要关心/维护【哪个是头】和【哪个是尾】。
4、由于可以通过任何一个节点的Next来遍历整个环，任何一个节点开始Next遍历都可以回到它自己，这也是遍历CLL的最基本方法。  


循环链表的变形（我不知道阅读名称）
1：从特定的节点断开，变成单链表（sll），自然形成一个头和尾。
2：把cll的某个节点的Next，改为现有其它节点，某个节点变成多个节点的Next指向，形成带环的链表。多次这样做，可以形成多个环或断开环。

应用：

1：在实际应用中，你可能只需要保存一个【当前节点】，不需要保存每个节点，通过数组来保存每个节点就雷死人了！
2：如果你确实需要一个【头节点-最先加入的节点】/【尾节点-最后加入的节点】，你可以自己保存起来。

后记：

1：sll花了前后花了好几天的空闲时间整理出来，test case也好几十个（原来更多，删了一部分）。
2：cll几乎一气呵成，累计不到2小时搞定，test case也很少，大部分一次通过。
3：为什么？原来以为sll比cll简单，结果为了维护【header】和【tail】代码变得复杂而且容易出错。
4：因此，伟大的是【模型】的发明者，而不是我写出了这些实现这些算法的代码，【模型让代码简化和直观】。
当你陷入复杂的境地，当你脑袋要炸掉的时候，想想你是否“忽略了对数据的组织”，“没有使用好的模型”？
在没有【数组】的帮助下，你可以轻松实现2个数据的比较，3个数据也还好，4个就头大了，5个就足以让你想上吊。
所以，当你听说没有任何模型和算法训练的人，写了一堆代码，做了几年的程序员，你应该偷笑他，也不要让自己可笑。
经典的模型、算法就那么些，解决实际问题的模式、算法是无穷无尽的，解决问题的时候想到它们，利用它们，也可以发明自己的模型、算法。
*/

#include <ios>
#include <iostream>

//节点结构
struct cll_node
{
	//下一个节点/右节点
	cll_node*next;//嵌套结构


	//节点数据（可以包含你需要的一个多个数据，类型/数量无限，和以下算法也无关）
	//这个数据也可以是一个指针，指向某个【结构数据】，这样，等于本链表是【一组无组织的数据的体外的链表】，
	//同样的数据集可以使用多个链表来组织起来，或者用：数组/树/栈/链表之类【组织者】将他们根据需要-数据的使用模式，来组织它们。
	int data;	
};



void cll_display(cll_node*from)
{
	if(from!=NULL)
	{
		//遍历
		int i=0;
		cll_node*n=from;
		while(n != NULL) //加一个判断，以适应循环链表被断开后遍历不会出错。
		{
			std::cout << "node[" << i++ << "]=" << n->data << std::endl;
			n=n->next;
			if(n==from) break;//回到开始遍历的节点，停止遍历。
		}
	}
}


//寻找前一节点【任何节点都有前一节点哦】
cll_node*cll_seek_prev(cll_node*node)
{

	if(node==NULL)
	{
		std::cout << "cll_seek_prev: the node is NULL!" << std::endl;
		return NULL;	
	}	


	//遍历
	int i=0;
	cll_node*n=node;

	while(n != NULL)//加一个判断，以适应循环链表被断开后遍历不会出错。
	{
		if(n->next==node) return n;
		n=n->next;
		if(n==node) break;//回到开始遍历的节点，停止遍历。
	}

	//无效的节点（理论上不可能）
	std::cout << "cll_seek_prev: The previous node can not be found! The specified node may had been moved out." << std::endl;
	return NULL;
}

//创建一个空数据的节点并插入某个节点之后
//existing_node==NULL：创建第一个节点
//永远不会返回NULL！
cll_node* cll_insert_after(cll_node* existing_node)
{

	cll_node*new_node=new  cll_node();
	//cll_node*new_node=(cll_node*)malloc(sizeof(cll_node));

	new_node->next=NULL;//必须赋值NULL，否则它的值是未知的！

	//初始化节点数据
	new_node->data=0;

	if(existing_node==NULL)
	{
		//创建第一个节点（自循环）
		new_node->next = new_node;
	}
	else
	{
		//把它链入原来的链表，以下语句的顺序很重要！
		//如果此循环链表被断，以下方法也适合于链表尾节点。
		new_node->next = existing_node->next;
		existing_node->next = new_node;
	}

	return new_node;	
}

//创建一个空数据的节点并插入某个节点之前（低效率函数，避免使用）
//existing_node==NULL：创建第一个节点
cll_node* cll_insert_before(cll_node* existing_node)
{

	if(existing_node==NULL)
	{
		//创建第一个节点（自循环）
		return cll_insert_after(NULL);
	}
	else
	{
		cll_node*prev_node = cll_seek_prev(existing_node);
		if(prev_node != NULL) return cll_insert_after(prev_node);
	}

	//仅existing_node不存在时！
	return NULL;
}
//创建一个数据节点并插入某个节点之后
//existing_node==NULL：创建第一个节点
//永远不会返回NULL！
cll_node* cll_insert_data_after(cll_node* existing_node, int data)
{
	cll_node*new_node=cll_insert_after(existing_node);
	new_node->data=data;
	return new_node;
}
//创建一个数据节点并插入某个节点之前（低效率函数，避免使用）
//existing_node==NULL：创建第一个节点
cll_node* cll_insert_data_before(cll_node* existing_node, int data)
{
	cll_node*new_node=cll_insert_before(existing_node);
	if(new_node!=NULL) new_node->data=data;
	return new_node;
}

//删除一个节点（允许删除唯一节点）
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

//翻转（从任何一个节点开始整个翻转）
bool cll_reserve(cll_node* from)
{
	if(from==NULL) 	
	{
		std::cout << "cll_seek_prev: the from is NULL!" << std::endl;
		return NULL;	
	}	


	//每次翻转一个Next指针！
	//原顺序：1 -> 2 -> 3 -> 4   
	//第一次：1 <- 2 -> 3 -> 4
	//第二次：1 <- 2 <- 3 -> 4
	//第三次：1 <- 2 <- 3 <- 4
	cll_node*node1=from;
	cll_node*node2=node1->next;
	cll_node*node3;
	while(true)
	{
		//提前备份Next节点下一次循环的node2）
		node3=node2->next;

		//翻转一个指针！
		node2->next=node1;

		//后移一个[node1->node2->node3]->node4 ==> node1<-[node2 node3<-node4]
		node1=node2;		
		node2=node3;
		if(node1==from) break;
	}

	return true;
}

//断开循环链表
//existing_node：从此节点以后断开
bool cll_break(cll_node* existing_node)
{
	if(existing_node!=NULL) 
	{
		existing_node->next=NULL;
		return true;
	}
	return false;
}

//修改节点的Next（可以把断开链表接起来，也可能把现有环断开构成新的环）
//
//1：假设有一个环A（整个cll环/或局部环），在环A内改任何一个节点的Next，一定导致一个新环B：（next_node 到 precv_node）。
//2：prev_node的原来的Next变成没有节点到达，变成环B之外的【尾巴】节点。
//3：A环增加一个缺口：多出一个节点指向next_node，一定意味者另一个节点少了一个指向。
//4：原环A不再是一个闭环，而是它的内部节点形成一个小环/内环B。
//5：从原环A的任何节点（不管是B环外还是内）都可以到达环B。
//6：从原环A的任何B环外的节点都可以遍历原环A所有节点，从B环内的任何节点都【只能】遍历到B环内的所有节点。
//   “O”型 => “6”型 或 “9”型。 
//   (1234)   ==> 12(34)   
//   (123456) ==> 123(456)
//    cll_link(n1, n2)
//    if(n1 >= n2) 环内部分：1...(n1....n2)  环外直道部分：end_node...1
//    if(n1 <= n2) 环内部分：(1...n1->n2->n2+1->...end_node) 环外直道部分：n1+1.....n2
//7：如果递归1->6，从B环内部改任何一个节点的Next（不含原来的prev_node,next_node，否则只是修改了B环的起止而已），一定导致一个环C，B环不再是环，再增加一个缺口。
//以下两种情形未彻底验证：
//8：如果从原A环的B环外的节点再任何一个节点的Next，可以形成同方向（同样顺时针或逆时针）的环，如果是，此环和原来的环彻底分开。
//   “O”型 => “6”型 或 “9”型 ==> “6 6”型 / “9 9” 型 / “oo” 型。
//   (1234)   ==> 12(34)    ==> (12)(34)  ==>  (1)(2)(3)(4)  
//   (123456) ==> 123(456)  ==> 1(23)4(56) / (123)(456)
//9：如果不成新环，一定是形成了“捷径”，但是还是满足“从任何节点开始都可以达到环B”，但是“从任何节点开始不一定可以遍历整个环B的所有节点。”
bool cll_link(cll_node* prev_node, cll_node* next_node)
{
	if(prev_node!=NULL) 
	{
		prev_node->next=next_node;
		return true;
	}
	return false;
}

//是否是循环链表（存在环）
//from：开始测试的节点（可以在环内或环外）
bool cll_is_loop(cll_node* from)
{
	//最容易想到的方法就是从任何一点开始组个Next，只要能回到它自己就是存在环，遇到Next为NULL就不是。
	//下拉快慢指针的做法目的是减少判断的循环次数?（对于循环的单链表是没有任何意义的！）
	//因此要判断存在不存在环，是很简单，但是要知道环入口就只能采用追加的快慢指针算法了。
	//以下是大师的著名快慢指针算法-伟大的发明，以下原理是我给它的比喻：
	//
	//1：一只速度快的乌龟和一只度慢的乌龟，从同一条“环形跑道”的同一个点出发（不是同一个点也无所谓），往同一个方向移动，那么兔子一定可以从后面赶超乌龟。
	//2：如果跑道是无限长度的直线，兔子会离乌龟越来越远，永远不会赶超，
	//3：也就是说速度快的赶超速度慢的是因为跑道是环形的，跑得快的会先完成N圈，跑得慢的会后完成N圈，因此，【一定在环形跑道的某个地方会被赶超】。
	//
	//4：现在问题变化一下，如果兔子和乌龟是先走一条直线【不循环的线即可】，然后进入同一个环形跑道，
	//   那么，【他们的相遇点一定在环形内，如果有环形的话，不是在环外】。
	//
	//5：现在问题再变化一下，直线和环形跑道都是由等距离的过河“跳石”组成，间距的设计是很考究的，乌龟一次刚好可以跳到下一颗石头，而兔子总是一次跳2块颗石头。
	//   而且，兔子和乌龟都是听从统一的号子：“1，2，3，跳”。那么上面的赶超就是：“在某块跳石上，要么兔子骑在乌龟上面，要么乌龟骑在兔子上面”。
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
		//必须包含“fast->next==slow”的判断！因为，while不是线性变化的而是离散或跳跃，
		//fast会一次性跨过slow一个节点（甚至每一次都是以这种方式相遇）
		//因此，包含“fast->next==slow”判断，就可以确保及时这种情况，也算相遇了！
		//延伸思考：如果fast是三倍速度而不是2倍呢？
		if(fast==slow || (fast!=NULL &&  fast->next==slow)) {loop=true;break;}
	}

	std::cout << "total while count=" << i << std::endl;
	return loop;
}
//从指定的节点开始寻到环的入口（针对6型）
//outside_node必须在环外，如果from在环内或原来就是（整个O型的cll）返回值可能是环内的任何节点，不一定就是环入口。
cll_node*cll_find_loop(cll_node* outside_node)
{
	//2个Next指向的节点就是环入口，因此，可以通过一维数组来累加Next是可以的，算法如下：
	//一维数组的大小为节点总数，下标为从from开始节点位置【不可以为节点的data，它可能重复，而且范围为止，也不可以为节点的地址，它很大】，值为和next次数。
	//问题是上述下标在不知道那个环入口前，只能一直递增下去。因此，简单的数组实际上无法解决，只能采用hash表。
	//因此，这个问题借助高级的hash表，数组模式是解决不了的，除非data真的就是1-N之类的连续数值刚好可以作为数组的下标。
	//以下是大师的著名快慢指针算法-伟大的发明！

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
		//fast指针会在第几圈和slow指针相遇
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
		//注意：
		//由于现在2个指针的移动速度是一致的，因此只要一次相遇的机会，
		//也就是，必须是外面指针（slow）刚好进入环内的一刻（某次循环），马上相遇，也就是说相遇点就是环入口。
		//请参考来自互联网的资料，复制在文档：cll_find_loop.txt。
		fast = fast->next;
	}
	std::cout << "total while count=" << i << std::endl;

	return slow;
}

//销毁/释放内存（注意：不是整个一个循环链表是不可以这样销毁的，否则可能重复销毁-异常，或部分销毁-内存丢失）
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
	//由于可以通过任何一个节点Next来遍历，因此，在实际应用中，你可能只需要保存一个当前节点，
	//不需要保存每个节点，通过数据来保存每个节点就雷死人了！
	//如果你确实需要一个【头节点-最先加入的节点】/【尾节点-最后加入的节点】，你可以自己保存起来。
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
	//不重新连接起来，以下销毁的节点数据一定不对！
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
	//make a small loop (1->2->3->4->5)  ==>  1->2->(3->4->5)  一对括号表示一个环(head -> tail)
	if(cll_link(n5, n3)==false)
	{
		std::cout << "CASE" << testcase << " ERROR-" <<  "2: cll_link failed." << std::endl; 
		cll_destory(n1);
		return false;
	}

	//从任何一个节点（不管环内/环外）都可以测试到环！
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
	//make a small loop (1->2->3->4->5)  ==>  1->2->3->(4->5)  一对括号表示一个环(head -> tail)
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
约瑟夫环问题：
已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
从编号为【k】的人开始报数，数到【m】的那个人出列；
他的下一个人又从【1】开始报数，数到【m】的那个人又出列；
依此规律重复下去，直到圆桌周围的人全部出列。
例如：n = 6,k = 1,m = 5
移出顺序：5，4，6，2，3，1。


17世纪的法国数学家加斯帕在《数目的游戏问题》中讲了这样一个故事：
15个教徒和15 个非教徒在深海上遇险，必须将一半的人投入海中，其余的人才能幸免于难，于是想了一个办法：
30个人围成一圆圈，从第一个人开始依次报数，每数到第九个人就将他扔入大海，如此循环进行直到仅余15个人为止。
问怎样排法，才能使每次投入大海的都是非教徒。


约瑟夫密码问题：
问题描述：编号为1、2、3、...、N的N个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。
从指定编号为1的人开始，按顺时针方向自1开始顺序报数，报到指定数M时停止报数，
报M的人出列，并将他的密码作为新的M值，从他在顺时针方向的下一个人开始，重新从1报数，依此类推，直至所有的人全部出列为止。
请设计一个程序求出出列的顺序，其中N≤30，M及密码值从键盘输入。
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

//数组解法
void Joseph_circle_array()
{
	bool a[101]={0};//这样会把所有清零？
	int n,m,i,f=0,t=0,s=0;
	n=6;
	m=5;
	do
	{
		++t;//逐个枚举圈中的所有位置
		if(t>n)	t=1;//数组模拟环状，最后一个与第一个相连
		if(!a[t]) s++;//第t个位置上有人则报数

		if(s==m)//当前报的数是m
		{
			s=0;//计数器清零
			std::cout<<t<<' ';//输出被杀人编号
			a[t]=1;//此处人已死，设置为空
			f++;//死亡人数+1
		}
	}while(f!=n);//直到所有人都被杀死为止
}