
/*
��������Quick Sort������:����ð������Ľ����õ��ġ���ð����������У�ֻ�����ڵ�������¼���бȽϣ����ÿ�ν����������ڼ�¼ʱֻ������һ�����������ͨ�������������ڣ���¼��һ�ν���������������������ӿ�������ٶȡ��������򷽷��е�һ�ν������������������
����������㷨���裺�ڴ������n����¼����ȡһ����¼��ͨ��ȡ��һ����¼����Ϊ���ᣨ��֧�㣩������ؼ���Ϊpivotkey������һ������󣬰����йؼ���С��pivotkey�ļ�¼������ǰ�棬�����йؼ��ִ���pivotkey�ļ�¼���������棬������������¼�ֳ������ӱ������������ڷֽ紦��λ�á�Ȼ�󣬷ֱ�������ӱ��ظ��������̣�ֱ��ÿ���ӱ�ֻ��һ����¼ʱ������ɡ�
��������¼�¼���п������� :49,38,65,97,76,13,27,49*
���潫���������¼���п�����������Ĺ���������ʾ��
��ʼ����49��low/pivotkey��,38,65,97,76,13,27,49*��high��
��һ�������Ե�һ����49��Ϊ������п�������
����Ĺ����ǽ����񵴱ƽ��ģ�����pivotkey�Ⱥ����������һ�������бȽϣ��������Ļ��ͺ͵����ڶ��������бȽ�ֱ����������������ˣ�pivotkey�ͺ������һ�������бȽϣ�����������Ļ�pivotkey�ͺ;ͺ͵ڶ��������бȽϣ�ֱ��������������pivotkey��Ҫ��֮ǰ������������ǰһ�������бȽϣ�������ȥ������ǽ����񵴱ƽ�����
��һ�˿�������{27��38��13}��49��{76��97��65��49*}
�ڶ��˿�������{13}��27��{38}��49��{76��97��65��49*}
�����˿�������13��27��38��49��{49��65}��76��{97}
�����˿�������13��27��38��49��49*��{65}��76��97
�����˿�������13��27��38��49��49*��65��76��97
����������������������������
*/

#include<stdio.h>
#include<windows.h>
#include<malloc.h>

void swap(int array[], int low, int high)//���ڽ���������������ֵ
{
	int temp;//�м�������ڽ���������ֵ
	temp = array[low];
	array[low] = array[high];
	array[high] = temp;
}

int partition(int array[], int low, int high)
{
	int pivotkey = array[low];//���������һ��Ԫ��Ϊ�Ƚ�Ԫ��
	while (low < high)
	{
		while ((low<high) && (array[high] >= pivotkey))
		{/*�������һ��Ԫ�ر�pivotkey����ôarray[high]��Ӧ�÷�
			��pivotkey�ĺ��棬����high��Ҫ��ǰ�ƶ�*/
			high--;
		}
		//����ͽ���array[low]��array[high]����ֵ
		swap(array, low, high);
		while ((low<high) && (array[low] <= pivotkey))
		{
			low++;
		}
		//����ͽ���array[low]��array[high]����ֵ
		swap(array, low, high);
	}
	return low;//��󷵻������λ�á�
	
}

void Qsort(int array[], int low, int high)
{
	if (low<high)//��������ж������Ļ��͵ݹ�
	{
		int key = partition(array, low, high);//��keyȥ���յ�һ������֮�������λ�á���
		
		Qsort(array, low, key - 1);//���������
		
		Qsort(array, key + 1, high);//�ұ�������
	}
}

void Quicksort(int array[], int len)//���ſ�ʼ
{
	Qsort(array, 0, len - 1);//���õݹ麯��
}


void Print(int array[], int len)//���ڴ�ӡ��������
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
   
   printf("��������Ҫ��ŵ�Ԫ�ظ���:\n");
   scanf("%d", &length);
   pArr = (int *)malloc(sizeof(int) * length); 

   printf("����������������Ҫ���бȽϵ����֣�\n");
   for(i=0; i<length ;++i)
   {  
	   //printf("�������㸳�������ֵ��\n");
	   scanf("%d", &pArr[i]);
   }
   
	Quicksort(pArr,length);//���ÿ�������ĺ����������������п�������
	printf("��������Ľ��Ϊ��\n");
	Print(pArr, length);
	printf("\n\n");
	system("pause");//��ͣһ��
	

   return 0;
}