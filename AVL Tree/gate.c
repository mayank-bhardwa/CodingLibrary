#include <stdio.h>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int a[4][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};
	printf("%d\n",**a);
	printf("%d\n",**(a+**a+2) );
	printf("%d\n",*(*(a+ **a+2)+3));
	return 0;
}