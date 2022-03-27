void mySort(void)
{
	int n, i, j, temp;
	scanf("%d",&n);
	int array[n];
	
	for (i = 0; i < n; ++ i) {
		scanf("%d",&array[i]);
	}
	
	/* bubble_sort */
	for (i = 0; i < n-1; ++ i) {
		for (j = 0; j < n-1; ++ j) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for (i = 0; i < n; ++ i) {
	    printf("%d ",array[i]);
	}
}

