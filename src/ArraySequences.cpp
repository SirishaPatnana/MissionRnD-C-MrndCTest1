/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	int i, j, diff[100], c, finalarr[7], d = 0;
	if (arr == NULL || len < 3)
		return NULL;
	for (i = 0; i < len; i++)
	{
		c = 1;
		for (j = i; j < len; j++)
		{
			diff[j] = arr[j] - arr[j + 1];
			if (j>i)
			{
				if (diff[j - 1] == diff[j])
					c++;
				else
					break;
			}
		}
		if (c >= 2)
		{
			finalarr[d++] = i;
			finalarr[d++] = j;
			i = j;
		}
	}
	for (i = 0; i < len; i++)
	{
		c = 1;
		for (j = i; j < len; j++)
		{
			diff[j] = arr[j + 1] / arr[j];
			if (j>i && diff[j] != 1)
			{
				if (diff[j - 1] == diff[j])
					c++;
				else
					break;
			}
		}
		if (c >= 2)
		{
			finalarr[d++] = i;
			finalarr[d++] = j;
		}
	}
	return finalarr;
}