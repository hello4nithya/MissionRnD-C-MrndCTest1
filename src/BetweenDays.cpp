/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int diff_year(struct node *date1head, struct node *date2head){
	struct node *temp1, *temp2;
	temp1 = date1head;
	temp2 = date2head;
	int i = 0,n1=0,n2=0;
	for (i = 0; i < 4; i++){
		temp1 = temp1->next;
	}
	for (i = 0; i < 4; i++){
		n1 = (n1 * 10) + temp1->data;
		temp1 = temp1->next;
	}
	for (i = 0; i < 4; i++){
		temp2 = temp2->next;
	}
	for (i = 0; i < 4; i++){
		n2 = (n2 * 10) + temp2->data;
		temp2 = temp2->next;
	}
	if (n1 > n2){
		return n1 - n2;
	}
	else if (n1 == n2){
		return 0;
	}
	else{
		return n2 - n1;
	}

}
int diff_month(struct node *date1head, struct node *date2head){
	struct node *temp1, *temp2;
	temp1 = date1head;
	temp2 = date2head;
	int i = 0, n1 = 0, n2 = 0;
	for (i = 0; i < 2; i++){
		temp1 = temp1->next;
	}
	for (i = 0; i < 2; i++){
		n1 = (n1 * 10) + temp1->data;
		temp1 = temp1->next;
	}
	for (i = 0; i < 2; i++){
		temp2 = temp2->next;
	}
	for (i = 0; i < 2; i++){
		n2 = (n2 * 10) + temp2->data;
		temp2 = temp2->next;
	}
	if (n1 > n2){
		return n1 - n2;
	}
	else if (n1 == n2){
		return 0;
	}
	else{
		return n2 - n1;
	}

}
int diff_day(struct node *date1head, struct node *date2head){
	struct node *temp1, *temp2;
	temp1 = date1head;
	temp2 = date2head;
	int i = 0, n1 = 0, n2 = 0;
	
	for (i = 0; i < 2; i++){
		n1 = (n1 * 10) + temp1->data;
		temp1 = temp1->next;
	}
	
	for (i = 0; i < 2; i++){

		n2 = (n2 * 10) + temp2->data;
		temp2 = temp2->next;
	}
	if (n1 > n2){
		return n1 - n2;
	}
	else if (n1 == n2){
		return 0;
	}
	else{
		return n2 - n1;
	}

}


int between_days(struct node *date1head, struct node *date2head){
	int y, m, d;
	if (date1head == NULL || date2head == NULL)
	 return -1;
	y = diff_year(date1head, date2head);
	m = diff_month(date1head, date2head);
	d = diff_day(date1head, date2head);
	return (y * 365) + (m * 30) + d;
}