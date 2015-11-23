/* 
树/树型结构

和其它算法结构相比（如：链表），树更多是以“数据结构”的面目出现，
其它算法结构经常不会在节点之类的“结构”内包含过多业务数据/实体数据，只是保存实体数据的指针/编号/ID。
而树的也是有节点构成的，这些节点内往往包含某个实体的一组信息，而不是实体数据的指针/编号/ID。
树也是通过某个节点本身包含其它节点或节点的指针把所有节点组织起来的，也是一组“自理的结构”，不需要外的模式来保存每个节点（如：数组）。

树和链表的异同
1：与线性的列表结构不一样，树型结构往往是用来体现节点之间的【层级关系】、【包含关系】，是【非线性数据结构】。
2：也就是说链表结构的节点之间没有层级关系，一般是平行的，但是树节点之间一定有层级关系。
3：链表的节点之间是“一个到一个”的关系，树的关系是“父节点-若干个子节点”的关系。
4：它们都属于嵌套关系（递归模式）。

树根(root)：
1：树的起点（一般树都是倒着画的），树根一般位于顶层，树根的规则是：没有父节点（上级节点）的节点。
2：一般树根都是单个节点/唯一的，但是也可以包含多个平级的根节点，各自有自己的分子，在这种情况下，也可以特地给增加它们一个虚拟根（程序自己管理）以满足“根节点是唯一的规则”。
3：一般树根是不会变化的，如果它会变化的话，问题会复杂化，在这种情况下可以考虑增加一个虚拟的树根节点，
这个根是人为加上去的，不对应任何实际的对象，因此，你的代码可以让它永远是老大！

分支节点/子节点(child/children)：
1：非树根节点都是分支节点或子节点，每个树根或父节点都包含1个或1个以上的子节点（直属节点）。
2：同属一个父节点的子节点，叫兄弟节点，它们是同级的。
3：子节点增加了自己的子节点后，它自己也成了父节点。


父节点(parent)：
1：至少包含一个子节点的节点。
2：树根节点是一种特殊的节点。
3：当父节点的子节点（以及子节点的子节点）都被删除后，父节点就变成子节点。

叶子节点(leaf)：
1：没有子节点的节点。
2：也就是末级节点，就像树叶子上不可能再长出分支来。

路径与深度：
1：从树根开始，沿着分支到达某个节点的路径，如果每个节点都有一个ID的话，从根节点ID开始构成一个路径，如：“1/3/5/6”。
2：深度：是指路径的长度，就是离根节点的距离，一般树根节点深度是“0”，树根的子节点的深度是“1”，以此类推。
3：从树根到达最远的叶子的深度，就是整个树的深度。

无序树(Unordered Tree)与有序树(Ordered Tree)：
1：无序树(Unordered Tree)：树中任意一个结点的各孩子结点之间的次序构成无关紧要的树。通常树指无序树。
2：有序树(Ordered Tree)：树中任意一个结点的各孩子结点有严格排列次序的树。

二叉树：
1：任何一个节点最多只能有2个子节点（叫左节点和右节点）的树。


注意：
1：以上的关系是嵌套的（递归的），可以归结为一种统一的关系：父节点-子节点。
2：以上节点类型都是动态的，在节点的增删改过程，每个节点的属性会变化。


树的操作
1：往下遍历，树的基本遍历模式都是从根节点或任意一个节点开始往下遍历（读取子节点），然后递归，读取所有下级节点直到叶子。一般都是通过访问父节点的“children_count”和“children”2个数据来实现往下遍历。
2：往上遍历，如果需要网上遍历，一般在设计节点时增加一个父节点的指针，如：Parent，通过子节点的Parent寻找父节点，然后递归遍历的树根节点。
3：节点插入：增加某个父节点的Children集合，有时需要处理同级子节点的排序问题。
4：节点删除：从某个父节点的Children集合内移除一个子节点（包括这个节点的下级子节点，即：整个分支）。
5：分支移动：将某个子节点从现有的父节点移到其它父节点（可能是其它层级的），除了被移动的整个分支的任何节点都是可能新父节点。

从数据节点的结构设计来看，节点插入/删除/移动都只设置一个某两个父节点（移动时）的Children集合的修改，不会扩大到其它节点，因此树是很高效的动态结构。
*/

#include <ios>
#include <iostream>

#pragma warning( disable : 4996) 

struct treenode
{
	//节点ID（往往是代表数据实体的ID，可选）
	int id;
	//子节点的个数（初始为0）
	int children_count;
	//子节点集合（指针数组）
	treenode* children;//嵌套结构

	//以下为节点的业务数据（一般和树的算法无关）：

	//一般结构内，采用“字符串数组”来存放string，而不是采用依赖外部空间的字符指针。
	//使得一个节点复制给另一个节点时，title也复制了，否则2个节点的title指向了同一个字符指针（当然可以重新赋值）
	char title[101]; 
	//如果直接用char[]就是直接申请了一个指定大小的空间用于储存char（一个指针）
	//此时就不能title=另一个指针
	//i.e. char title[101];等价于
	//char* title=new title[10];
	//上述3个写法title都是指一个指针（地址）
	//title[i]都是访问该位置的一个char
};


treenode* findnode_and_its_children(treenode* startnode, int id)//*表示地址（返回值是treenode的地址）
{
	std::cout<<"startnode id="<<startnode->id<<std::endl;

	if (startnode->id==id) 
	{
		return startnode;
	}

	if (startnode->children_count >0)
	{
		for (int i=0;i<startnode->children_count;i++)
		{
			treenode* c=&startnode->children[i];//取那个儿子的结构的地址用&
			treenode* n=findnode_and_its_children (c,id);//开始递归调用（自己调用自己）,n为返回值
			if(n!=NULL) return n;//n=null说明c的儿孙们都不是
		}
	}
	return NULL;//特殊地址0，用于指针（表不存在）
}

void test_tree()
{
	treenode root;
	root.id=1;
	strcpy(root.title, "grandfather");
	root.children_count=2;
	root.children=new treenode[root.children_count];

	treenode* father1=&root.children[0];
	father1->id=2; //当father只是一个地址的时候对于结构的访问时 要用-> (不能用.）
	strcpy(root.children[0].title, "father1");

	treenode* father2=&root.children[1];
	father2->id=3;
	strcpy(father2->title, "father2");
	father2->children_count=0;

	//new: Allocates memory for an object or array of objects of type-name
	//from the free store and returns a suitably typed, nonzero pointer to the object.

	father1->children_count=1;
	father1->children=new treenode[father1->children_count];
	father1->children[0].id=4;
	strcpy(father1->children[0].title,"daughter");

	int id=14;

	treenode* r=findnode_and_its_children(&root,id);//&放在变量前面的时候 取变量所在的地址
	if(r!=NULL) std::cout<<"Tree node id="<<id<<"'s title is "<< r->title;


	//用delete回收空间
	delete root.children;
	delete father1->children;
}