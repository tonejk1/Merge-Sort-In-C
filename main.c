#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[], int n);
void merge(int a[], int b[], int c[], int na, int nb, int nc);
void printarray(int*a,int n);

int main()
{
	int a[] = { 12, 11, 13, 5, 6, 7,11,11,11,44,8787,0,12};
	int n = sizeof(a) / sizeof(a[0]);
	printf("Initial array\n\n");
	printarray(a,n);
	mergesort(a,n);
	printf("\n\nSorted array\n\n");
	printarray(a,n);
	printf("\n\n");
	return 0;
}

void mergesort(int a[], int n)
{
	if (n == 1)
		return;
	int l[n / 2];
	int r[n - n / 2];
	for (int i = 0; i < n / 2; i++)
	{
		l[i] = a[i];
		r[i] = a[i + n / 2];
	}

	if ((n - n / 2) > (n / 2))
		r[n / 2] = a[n - 1];
	mergesort(l, n / 2);
	mergesort(r, n - n / 2);
	merge(a, l, r, n, n / 2, n - n / 2);
}

void merge(int a[], int b[], int c[], int na, int nb, int nc)
{
	int i = 0, j = 0;
	for (int k = 0; k < na; k++)
	{
		if (i < nb && j < nc)
		{
			if (b[i] < c[j])
			{
				a[k] = b[i];
				i++;
			}
			else if (c[j] < b[i])
			{
				a[k] = c[j];
				j++;
			}
			else
			{
				a[k] = b[i];
				a[k + 1] = c[j];
				i++;
				j++;
				k++;
			}
		}
		else if (i < nb)
		{
			a[k] = b[i];

			i++;
		}
		else if (j < nc)
		{
			a[k] = c[j];
			j++;
		}
	}
}

void printarray(int*a,int n)
{
  	for (int i = 0; i < n; i++)
	{
	    if((i%5)|| i==0)
		printf("%d  ", a[i]);
		else
        printf("\n%d  ", a[i]);
	}
}
