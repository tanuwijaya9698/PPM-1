//#include<iostream>
//
//using namespace std;
//
//void go_quick_sort(int *arr, int left, int right)
//{
//	if (left<right)
//	{
//	  int i = left, j = right,tmp;
//      int pivot = arr[(left + right) / 2];
//      while (i <= j) {
//            while (arr[i] < pivot)
//                  i++;
//            while (arr[j] > pivot)
//                  j--;
//            if (i <= j) {
//                  tmp = arr[i];
//                  arr[i] = arr[j];
//                  arr[j] = tmp;
//                  i++;
//                  j--;
//            }
//      };
// 
//      /* recursion */
//      if (left < j)
//            go_quick_sort(arr, left, j);
//      if (i < right)
//            go_quick_sort(arr, i, right);
//	}
//}
//
//void quicksort(int arr[])
//{
//	cout << "Length of array = " << (sizeof(arr)/sizeof(arr[0]))<<endl;
//	go_quick_sort(arr,0,9);
//	for (int i = 0; i < 10; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//}
//
//void mergesort(int *arr)
//{
//
//}
//
//int interpolation_search(int *arr, int ke)
//{
//	return 0;
//}
//
//void main()
//{
//	int arr1[] = {98,1,5,234,12,7,10,6,4,11};
//	int arr2[] = {37,32,99,3,621,5,13,2,90,771};
//	cout << "Length of array = " << (sizeof(arr1)/sizeof(arr1[0]))<<endl;
//	quicksort(arr1);
///*	mergesort(arr2);
//	for(int i=0;i<10;i++)
//	{
//	   cout<<arr1[i]<<" ";
//	}cout<<endl;
//	for(int i=0;i<10;i++){
//	   cout<<arr2[i]<<" ";
//	}cout<<endl;
//	*/
//	cout<<interpolation_search(arr1,6)<<endl;
//}

#include<iostream>

using namespace std;

void go_quick_sort(int *arr, int left, int right)
{
	if (left<right)
	{
	  int i = left, j = right,tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            go_quick_sort(arr, left, j);
      if (i < right)
            go_quick_sort(arr, i, right);
	}
}

void quicksort(int arr[])
{
	cout << "Length of array = " << (sizeof(arr)/sizeof(arr[0]))<<endl;
	go_quick_sort(arr,0,9);
}

void merge(int[],int,int,int);


void go_merge_sort(int arr[],int batas_bawah,int batas_atas)
{
	int tengah = 0;
	if(batas_bawah<batas_atas)
	{
		tengah = (batas_bawah+batas_atas)/2;
		go_merge_sort(arr,batas_bawah,tengah);
		go_merge_sort(arr,tengah+1,batas_atas);
		merge(arr,batas_bawah,tengah,batas_atas);
	}
}

void merge(int arr[], int batas_bawah,int tengah,int batas_atas)
{
	int b[50];
	int h = batas_bawah;
	int idx = batas_bawah;
	int j = tengah + 1;

	while((h<=tengah) && (j<=batas_atas))
	{
		if ( arr[h] <= arr[j] )  //array sebelah kiri lebih kecil dari arr[tengah] dan sebelah kanan pasti lebih besar dari arr[tengah] 
		{
			b[idx] = arr[h];
			h++;
		}
		else
		{
			b[idx] = arr[j];
			j++;
		}
		idx++;
	}
	if( h > tengah )  //jika masih ada sisa ditransferkan 
	{
		for(int k=j; k<=batas_atas; k++)
		{
			b[idx]=arr[k];
			idx++;
		}
	}
	else
	{
		for(int k=h; k<=tengah; k++)
		{
			b[idx]=arr[k];
			idx++;
		}
	}
	for(int k=batas_bawah;k<=batas_atas;k++)  //mengembalikan ke array aslinya dari temporary b
		arr[k]=b[k];
}

void mergesort(int *arr)
{
	go_merge_sort(arr,0,9);
}


int interpolation_search(int *arr, int data)
{
   int batas_bawah = 0;
   int batas_atas = 9 - 1;
   int tengah = -1;  
   int index = -1;

   while (batas_bawah <= batas_atas) {
      tengah = batas_bawah + (((double)(batas_atas - batas_bawah) / (arr[batas_atas] - arr[batas_bawah])) * (data - arr[batas_bawah]));
      if(arr[tengah] == data) {
         index = tengah;
		 batas_bawah=batas_atas + 1; //memaksa kluar loop
      } else {
         if(arr[tengah] < data) {
            batas_bawah = tengah + 1;
         } else {
            batas_atas = tengah - 1;
         }
      }               
   }
   return index;
}


void main()
{
	int arr1[] = {98,1,5,234,12,7,10,6,4,11};
	int arr2[] = {37,32,99,3,621,5,13,2,90,771};
	cout << "Jumlah Kotak Array = " << (sizeof(arr1)/sizeof(arr1[0]))<<endl;
	quicksort(arr1);
	mergesort(arr2);
	for(int i=0;i<10;i++)
	{
	   cout<<arr1[i]<<" ";
	}cout<<endl;
	for(int i=0;i<10;i++){
	   cout<<arr2[i]<<" ";
	}cout<<endl;
	cout<<interpolation_search(arr1,6)<<endl;
}