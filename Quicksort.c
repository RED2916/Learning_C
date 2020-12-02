// EXP1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#define MAXSPACE 80

using namespace std;

int quicksort( int target[],int begin, int end);
int partition(int target[], int pivot, int begin, int end );

int count=0;
int com_count=0;

int main(void)
{
	ifstream INF;
	int target[MAXSPACE];
	int length=0;
	int i;
	INF.open("input1-data.txt");
	if( !INF.is_open() ){
		cout << "Error!" << endl;
	}
	while( !INF.eof() ){ // read the data in the file
		INF >> target[length];
		//cout << target[length] << endl;
		length++;
	}
	quicksort(target,0,length-1);//length - 1!!
	for( i = 0 ; i < length ; i++ ){
		cout << target[i] << endl;
	}
	cout << "swap_count:" << count << endl;
	cout << "com_count:" << com_count << endl;
	getchar();
	return 0;
}

int quicksort( int target[],int begin, int end){//quicksort function
	int n= end - begin +1;
	int i;
	int pivot = begin;
	i=partition( target,pivot,begin,end);
	if( (i-1) > begin ){ //judge whether the program should continue to compare the array
		quicksort(target,begin,i-1);
	}
	if( (i+1) < end ){
		quicksort(target,i+1,end);
	}
	return 1;
}

int partition(int target[], int pivot, int begin, int end ){ // partition function
	int i=begin+1,j=end;
	int first_begin=begin+1,first_end=end;
	int temp;
	int cross_flag = 0;//judge cross or not
	begin=begin+1;//!!
	while( 1 ){
		for( j = end ; j>i ; j-- ){ //pay attention to this order!!!
			/*if( j<=i )
			{
				break;
			}*/
			/*if( j==begin ){
				continue;
			}*/
			if( target[j]<target[pivot]  ){
				com_count++;
				//end=j-1;
				break;
			}
			else{
				if( j == end && end != first_end ){
					continue;
				}
				else{
					com_count++;
				}
			}
		}
		/*if( j>i ){
			end=j-1;
		}*/
		for( i=begin/*begin+1*/; i<j ; i++ ){//!!
			/*if( i>=j )
			{
				break;
			}*/
			/*if( i==begin ){
				continue;
			}*/
			if( target[i]>target[pivot] ){
				com_count++;
				//begin=i+1;
				break;
			}
			else{
				if( i == begin && begin != first_begin ){
					continue;
				}
				else{
				 com_count++;
				}
			}
		}
		/*if( j>i ){
			begin=i+1;
		}*/
		/*swap*/
		if( i == j ){
			if( target[pivot] > target[i] )
			{
				temp= target[i];
				target[i]=target[pivot];
				target[pivot]=temp;
				//com_count++;
				count++;
			}
			else{//cross
				com_count++;//!!!
				return pivot; // pay attention!
			}
			break;
		}
		else{
			temp= target[i];
			target[i]=target[j];
			target[j]=temp;
			count++;
			//end--;
			//begin++;
		}
	}
	return i;
}
