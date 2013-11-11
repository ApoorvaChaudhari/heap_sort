/*
 *  heap.c
 *  
 *
 *  Created by Apoorva Chaudhari on 6/20/12.
 *  Copyright 2012 Rutgers University. All rights reserved.
 *
 */

void swap(int *i, int *j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void createheap( int a[], int n)
{
	int i, f, s;
	for( i=1; i<n; i++)
	{
		s = i;
		f = (i-1)/2;
		while(a[f] < a[s])
		{
			swap( &a[f], &a[s]);
			s = f;
			if ( s == 0) 
				break;
			
			f = (s-1)/2;
		}
	}
}

void heapsort( int a[], int n)
{
	int i,s;
	
	createheap(a,n);
	
	for( i= n-1 ; i >= 1; --i)
	{
		swap(&a[0], &a[i]);
		
		createheap(a, i);
	}
}

int main()
{
	int i;
	int a[]={10,5,25,8,29,16,40};
	heapsort(a,7);
	
	for ( i=0; i<=6; i++)
	{
		printf("%d\n", a[i]);
	}
	
	return 0;
}

