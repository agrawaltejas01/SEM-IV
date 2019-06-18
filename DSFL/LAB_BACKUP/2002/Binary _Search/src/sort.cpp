/*
 * sort.cpp
 *
 *  Created on: 20-Dec-2017
 *      Author: e2002
 */

#include "sort.h"


void sort:: bsort(int arr[],int n)
{
	int flag;
	for(int i=0;i<n-1;i++)
	{
		flag=0;

		for(int j=0;j<n-i-1;j++ )
		{
			if(arr[j]>arr[j+1])
			{
				flag=1;
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}

		if(flag==0)
			break;
	}
}

