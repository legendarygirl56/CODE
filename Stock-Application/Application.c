#include<stdio.h>
#include<stdlib.h>

int begin,end;

int cross(int a[20],int low,int mid,int high){
		int i;
		int left_sum = 0,right_sum = 0, sum = 0;
		for(i=mid;i>=low;i--)
			sum = sum +a[i];
				if(sum > left_sum)
					left_sum = sum;
					
			sum = 0;
			for(i=high;i>mid;i--)
				sum = sum + a[i];
					if(sum>right_sum)
						right_sum = sum;
			
			return left_sum + right_sum;
		
	}

int max_sum(int a[20],int low,int high){
		int mid, left_sum, right_sum, cross_sum;
		if(low==high)
			return a[low];
			mid = (low+high)/2;
		left_sum = max_sum(a,low,mid);
		right_sum = max_sum(a,mid+1,high);
		cross_sum = cross(a,low,mid,high);
		
		if(left_sum > right_sum && left_sum > cross_sum){
			begin =low;
			end = mid;
			return left_sum;
		}
			
		else if(right_sum > left_sum && right_sum > cross_sum){
			begin = mid + 1;
			end = high;
			return right_sum;
		}
			
		else{
			begin = low;
			end = high; 
			return cross_sum;
		}
}

int main(){
	int i,n,a[20],max;
	printf("Enter the size of array \n");
	scanf("%d",&n);
	
	printf("enter the array \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);	
	
	max = max_sum(a,0,n-1);	
	
	printf("%d\n",max);
	
	printf("from %d to %d \n",begin+1,end+1);
	
	return 0;
	}
