void sort(int left, int right)
{
	int i = left - 1;
	int t;
	if(left < right)
	{ 
		for(int j = left ; j < right; j++)
		{
			if( a[j] < a[right] ) // a[j]가 pivot보다 작으면
			{
				i++;
				if( i != j ) // pivot보다 큰 값이 i, j사이에 있으면	
				{
					t = a[j];
					a[j] = a[i];
					a[i] = t;
				}
			} 
		}
		t = a[i+1];
		a[i+1] = a[right];
		a[right] = t;  // pivot은 정렬 완료...
		sort(left, i); // pivot의 왼쪽 구간 
		sort(i+2, right);  // pivot의 오른쪽 구간..
	}
}
