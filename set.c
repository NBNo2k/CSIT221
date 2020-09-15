#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set initialize()
{
	Set head = NULL;
	
	return head;
}

void display(Set s)
{
	nodeptr ptr=s;//initialize
	
	while(ptr!=NULL)
	{//condition
		printf("%d ",ptr->data);//task
		ptr = ptr->next;//update
	}
	printf("\n");
}

int contains(Set s, int elem)
{
	int found=0;
	nodeptr ptr=s;
	
	
	while(ptr!=NULL)
	{
		if(ptr->data==elem)
		{
			found=1;
			break;
		}
		ptr = ptr->next;
	}
	
	return found;
}

void swap(Set a, Set b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

Set add(Set s, int elem)
{
	if(contains(s,elem)==0)
	{
		nodeptr temp = (nodeptr)malloc(sizeof(Node));
		temp->data = elem;
		temp->next = s;
		s = temp;
	}
	
	int swapped, i;
	nodeptr ptr1;
	nodeptr lptr = NULL;
	
	//Checks empty list
	if(s == NULL)
		return;
	
	//Sorts into ascending order	
	do
	{
		swapped = 0;
		ptr1 = s;
		
		while(ptr1->next != lptr)
		{
			if(ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr =ptr1;
	}
	while(swapped);
	
	return s;
}



Set getUnion(Set s1, Set s2)
{
	Set result = initialize();
 	
	//traverse s1 and add to result
	nodeptr ptr = s1;
	
	while(ptr!=NULL)
	{
		result=add(result,ptr->data);
		ptr=ptr->next;
	}
	
	//traverse s2 and add to result
	ptr = s2;
	
	while(ptr!=NULL)
	{
		result=add(result,ptr->data);
		ptr=ptr->next;
	}
	
	return result;
}

Set intersection(Set result, Set s1, Set s2)
{
    nodeptr ptemp, qtemp, itemp, irear, ifront;
 
 	result = initialize();
 	
    ptemp = s1;
    while (ptemp != NULL)
    {
        qtemp = s2;
        ifront = result;
        while (qtemp != NULL && ptemp->data != qtemp->data)
        {
            qtemp = qtemp->next;
        }
        if (qtemp != NULL)
        {
            if (ifront != NULL)
            {
                if (ifront->data == qtemp->data)
                {
                    ptemp = ptemp->next;
                    continue;
                }
                ifront = ifront->next;
            }
            itemp = (nodeptr)malloc(sizeof(Node));
            itemp->data = qtemp->data;
            itemp->next = NULL;
            if (result == NULL)
            {
                result = itemp;
            }
            else
            {
                irear->next = itemp;
            }
            irear = itemp;
        }
        ptemp = ptemp->next;
    }
    
    return result;
}


Set difference(Set result, Set s1, Set s2)
{
	result = initialize();
	
	nodeptr ptemp, qtemp;
	
	ptemp = s1;
	qtemp = s2;
	while(ptemp != NULL && qtemp != NULL)
	{
		if(ptemp->data == qtemp->data)
		{
			ptemp = ptemp->next;
			qtemp = qtemp->next;
		}		
		else
		{
			if(ptemp->data < qtemp->data)
			{
				result = add(result, ptemp->data);
				ptemp = ptemp->next;
			}
			else
				qtemp = qtemp->next;
		}
	}

	while(ptemp != NULL)
	{
		result = add(result, ptemp->data);
		ptemp = ptemp->next;
	}
	
	return result;
}

Set symmetricdifference(Set result, Set s1, Set s2)
{
	result = initialize();
	
	//Traverse s1 and s2
	while(s1 != NULL && s2 != NULL)
	{
		//Checks what's not in set 2 and adds it to the result
		if(s1->data < s2->data)
		{
			result = add(result, s1->data);
			s1 = s1->next;
		}
		//Checks whats not in Set 1 and adds it to the result
		else if(s2->data < s1->data)
		{
			result = add(result, s2->data);
			s2 = s2->next;
		}
		else
		{
			s1 = s1->next;
			s2 = s2->next;
		}
	}
	
	return result;
}

int subset(Set s1, Set s2)
{	
	nodeptr ptemp = s1;
	nodeptr qtemp = s2;
	
	//If both lists are empty, return true
	if(s1 == NULL && s2 == NULL)
		return 1;
		
	//If either of the set is empty, return false
	if(s1 == NULL || s1 != NULL && s2 == NULL)
		return 0;
	
	//Traverse s2 
	while(s2 != NULL)
	{
		//Initialize qtemp with the current node of s2
		qtemp = s2;
		
		//Starts matching s1 with s2
		while(ptemp != NULL)
		{
			//Return false if s2 is empty and s1 is not
			if(qtemp == NULL)
				return 0;
				
			//If data is same, proceed
			else if(ptemp->data == qtemp->data)
			{
				ptemp = ptemp->next;
				qtemp = qtemp->next;
			}
			
			//Break loop if no equal found
			else
				break;
		}
		
		//Returns true if first list is gets traversed
		if(ptemp == NULL)
			return 1;
		
		//Initialize s1 with ptemp again	
		ptemp = s1;
		
		//Move to the next node of s2
		s2 = s2->next;
	}
	
	return 0;
}

int disjoint(Set s1, Set s2)
{
	Set result;
	
	nodeptr ptemp, qtemp, itemp, irear, ifront;
 
 	result = initialize();
 	
    ptemp = s1;
    while (ptemp != NULL)
    {
        qtemp = s2;
        ifront = result;
        while (qtemp != NULL && ptemp->data != qtemp->data)
        {
            qtemp = qtemp->next;
        }
        if (qtemp != NULL)
        {
            if (ifront != NULL)
            {
                if (ifront->data == qtemp->data)
                {
                    ptemp = ptemp->next;
                    continue;
                }
                ifront = ifront->next;
            }
            itemp = (nodeptr)malloc(sizeof(Node));
            itemp->data = qtemp->data;
            itemp->next = NULL;
            if (result == NULL)
            {
                return 1;
            }
            else
            {
                irear->next = itemp;
            }
            irear = itemp;
        }
        ptemp = ptemp->next;
    }
    
    return 0;		
}

int equal(Set s1, Set s2)
{
	 nodeptr ptemp = s1;
	 nodeptr qtemp = s2;
	
	//If both lists are empty, return true
	if(s1 == NULL && s2 == NULL)
		return 1;
		
	//If  set 1 is empty and s2 is not, return false
	if(s1 == NULL || s1 != NULL && s2 == NULL)
		return 0;
	
	//Traverse s2 
	while(s2 != NULL)
	{
		//Initialize qtemp with the current node of s2
		qtemp = s2;
		
		//Starts matching s1 with s2
		while(ptemp != NULL)
		{
			//Return false if s2 is empty and s1 is not
			if(qtemp == NULL)
				return 0;
				
			//Returns true if both sets are equal
			else if(ptemp->data == qtemp->data)
			{
				return 1;
			}
			
			//Break loop if no equal found
			else
				break;
		}
		
		//Returns true if first list is gets traversed
		if(ptemp == NULL)
			return 1;
		
		//Initialize s1 with ptemp again	
		ptemp = s1;
		
		//Move to the next node of s2
		s2 = s2->next;
	}
	
	return 0;
}
