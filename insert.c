#include<stdio.h>
int main(){
	int i,n,item,element,index;
	int arr[7]={20,25,30,35,40,45};
	printf("enter the element u wana add after ");
	scanf("%d",&element);
	for(i=0;i<6;i++){
		if(arr[i]==element)
	{index=i;
	break;
		}	
		
	}

    
	printf("enter the element u wana add  ");
	scanf("%d",&item);
	for(i=6;i>index+1;i--){
		arr[i]=arr[i-1];
		
	}
	arr[index+1]=item;
	
	for(i=0;i<7;i++){
		printf("%d\n",arr[i]);
	}

	return 0;
	
}
