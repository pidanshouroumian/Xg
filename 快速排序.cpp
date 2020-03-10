
/*
快速排序（Quick Sort）概念:是由冒泡排序改进而得到的。在冒泡排序过程中，只对相邻的两个记录进行比较，因此每次交换两个相邻记录时只能消除一个逆序。如果能通过两个（不相邻）记录的一次交换，消除多个逆序，则会大大加快排序的速度。快速排序方法中的一次交换可以消除多个逆序。
快速排序的算法步骤：在待排序的n个记录中任取一个记录（通常取第一个记录）作为枢轴（或支点），设其关键字为pivotkey。经过一趟排序后，把所有关键字小于pivotkey的记录交换到前面，把所有关键字大于pivotkey的记录交换到后面，结果将待排序记录分成两个子表，最后将枢轴放置在分界处的位置。然后，分别对左右子表重复上述过程，直至每个子表只有一个记录时排序完成。
例如对如下记录进行快速排序 :49,38,65,97,76,13,27,49*
下面将会对上述记录进行快速排序，排序的过程如下所示：
初始化：49（low/pivotkey）,38,65,97,76,13,27,49*（high）
第一趟排序以第一个数49作为枢轴进行快速排序
排序的过程是交替振荡逼近的：就是pivotkey先和数组中最后一个数进行比较，不交换的话就和倒数第二个数进行比较直到交换，如果交换了，pivotkey就和数组第一个数进行比较，如果不交换的话pivotkey就和就和第二个数进行比较，直到交换，交换后pivotkey就要和之前后面所交换的前一个数进行比较，依次下去，这就是交替振荡逼近法。
第一趟快速排序：{27，38，13}，49，{76，97，65，49*}
第二趟快速排序：{13}，27，{38}，49，{76，97，65，49*}
第三趟快速排序：13，27，38，49，{49，65}，76，{97}
第四趟快速排序：13，27，38，49，49*，{65}，76，97
第五趟快速排序：13，27，38，49，49*，65，76，97
——————————————
*/

#include<stdio.h>
#include<windows.h>
#include<malloc.h>

void swap(int array[], int low, int high)//用于交换数组中两个数值
{
	int temp;//中间变量用于交换两个数值
	temp = array[low];
	array[low] = array[high];
	array[high] = temp;
}

int partition(int array[], int low, int high)
{
	int pivotkey = array[low];//设置数组第一个元素为比较元素
	while (low < high)
	{
		while ((low<high) && (array[high] >= pivotkey))
		{/*数组最后一个元素比pivotkey大，那么array[high]就应该放
			在pivotkey的后面，所以high需要向前移动*/
			high--;
		}
		//否则就交换array[low]和array[high]的数值
		swap(array, low, high);
		while ((low<high) && (array[low] <= pivotkey))
		{
			low++;
		}
		//否则就交换array[low]和array[high]的数值
		swap(array, low, high);
	}
	return low;//最后返回枢轴的位置。
	
}

void Qsort(int array[], int low, int high)
{
	if (low<high)//如果符合判断条件的话就递归
	{
		int key = partition(array, low, high);//用key去接收第一躺排序之后枢轴的位置】、
		
		Qsort(array, low, key - 1);//左边子序列
		
		Qsort(array, key + 1, high);//右边子序列
	}
}

void Quicksort(int array[], int len)//快排开始
{
	Qsort(array, 0, len - 1);//调用递归函数
}


void Print(int array[], int len)//用于打印整个数组
{
	for ( int i = 0;i<len; i++)
	{
		printf("%5d",array[i]);
	}
}


int main (void)
{  
   int length;
   int i;
   int * pArr;
   
   printf("请输入你要存放的元素个数:\n");
   scanf("%d", &length);
   pArr = (int *)malloc(sizeof(int) * length); 

   printf("下面请依次输入你要进行比较的数字：\n");
   for(i=0; i<length ;++i)
   {  
	   //printf("请输入你赋给数组的值：\n");
	   scanf("%d", &pArr[i]);
   }
   
	Quicksort(pArr,length);//调用快速排序的函数对上面的数组进行快速排序
	printf("快速排序的结果为：\n");
	Print(pArr, length);
	printf("\n\n");
	system("pause");//暂停一下
	

   return 0;
}