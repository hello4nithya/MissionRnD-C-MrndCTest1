/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {

	if (head == NULL) return NULL;

	int temp = 0;
	struct node *first = head;
	struct node *second = head;

	while (second->next != NULL)
	{


		while (first->next != NULL)
		{
			if (first->data > first->next->data)
			{
				temp = first->data;
				first->data = first->next->data;
				first->next->data = temp;
			}
			first = first->next;
		}


		first = head;
		second = second->next;
	}
	return head;
}



int merge_circularlists(struct node **head1, struct node **head2){
	struct node *temp1;
	struct node *temp2 = (struct node*)malloc(20*sizeof(struct node));
	//struct node *t;
	int c = 0,c2=0,c1=0;
	if (*head1 == NULL && *head2 == NULL)
		return -1;
	if (*head1 == NULL && *head2 != NULL){
		temp2 = *head2;
		while (temp2 != NULL){
			temp2 = temp2->next;
			c2++;
		}
		return c2;
	}
	if (*head1 != NULL && *head2 == NULL){
		temp1 = *head1;
		while (temp1 != NULL){
			temp1 = temp1->next;
			c1++;
		}
		return c1;
	}
		
	
	else{
		temp1 = *head1;
		temp2 = *head2;

		while (temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = *head2;
		temp2 = sortLinkedList(*head1);
		while (temp2 != NULL){
			temp2 = temp2->next;
			c++;
		}
		return c;
	}
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	
}