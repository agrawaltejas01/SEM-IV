/*
 * binary_search.cpp
 *
 *  Created on: 20-Dec-2017
 *      Author: e2002
 */

#include "binary_search.h"

int binary_search:: bsearch(int arr[],int beg,int end,int val)
{
		if(beg<=end)
		{
			int mid=(end+beg)/2;

			if(arr[mid]==val)
				return mid;

			else if(arr[mid]<val)
				return bsearch(arr,mid+1,end,val);

			else
				return bsearch(arr,beg,mid-1,val);

		}

		else
		{
			return -1;
		}
}

