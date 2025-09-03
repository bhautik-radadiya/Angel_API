#include <iostream>

//single link list...

struct single_list
{
	int val;
	single_list *next;
	single_list()
	{
		val = 0;
		next = NULL;
	}
};

void Add_Node(single_list **gptr, int data)
{
	single_list *local = new single_list;
	static single_list *static_local;
	if(NULL != local) {
		local->val = data;		 
	}
	if(NULL == *gptr)
	{
		local->next = NULL;
		*gptr = local;
		static_local = *gptr;
	}	
	else
	{
		local->next = static_local->next;
		static_local->next = local;
		static_local = local;
	}
}

void print_nodes(single_list *nodes) {
	single_list *local = NULL;

	if (NULL != nodes) local = nodes;
	
	while(NULL != local)
	{
		std::cout << local->val << " ";
		local = local->next;
	}
	std::cout<<std::endl;
}	

int main()
{
	//start adding node behind...
	single_list *gptr = NULL;
	
	Add_Node(&gptr, 5);
	Add_Node(&gptr, 10);
	Add_Node(&gptr, 15);
	Add_Node(&gptr, 52);
	
	print_nodes(gptr);	

	std::cout << "Hello MAC!!" <<std::endl;
	return 0;
}
