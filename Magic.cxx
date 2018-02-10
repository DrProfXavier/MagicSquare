#include<iostream>
#include<iomanip>
#include<stdio.h>
#include <algorithm>
#include <utility>
//I'm sorry for the length, classes and 2d arrays were giving me trouble
 
using namespace std;


void printArr(int *arr, int size, int num)//most complicated
	{
		cout<<"Magic Square # " << num << " is:" <<endl<<endl;
		int i, j;
		for (i = 0 ; i<size; i++)
		{
			for (j = 0; j<size; j++)
				printf("%5d", *((arr+i*size)+j));						
				cout<<endl;
		}
		cout<<endl;
		
		//checkSum(&transArr[0][0],size);
	}
	
void checkSum(int *arr, int size)//Check sums
{
	cout<<"Checking the sums of every row: "; //rows
	int sumSquare[size][size];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			sumSquare[r][c] = *((arr+r*size)+c);//new array 
		}
	}
	
	int firstSum = 0;//first sum
	for (int j = 0; j < size; j++)
	{
		firstSum += sumSquare[0][j];
	}
	
	for (int i = 0; i < size; i++)//checking rows
	{
		int sum = 0;
		for (int j = 0; j < size; j++)
		{
			sum += sumSquare[i][j];
		}
		cout << sum <<" ";
	}
	cout<<endl;
	
	//columns now
	cout<< "Checking the sums of every column: ";
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = 0; j < size; j++)
		{
			sum += sumSquare[j][i];
		}
		cout << sum <<" ";
	}
	cout<<endl;
	
	//diagon alley
	cout<<"Checking sums of every diagonal: ";
	int Diag1Sum = 0, Diag2Sum = 0;
	for (int i = 0; i < size; i++)
	{
		Diag1Sum += sumSquare[i][i];
	}
	for (int i = 0; i < size; i++)
	{
		Diag2Sum += sumSquare[size - 1 - i][i];
	}
	cout<<Diag1Sum<<" "<<Diag2Sum<<endl<<endl;
}		
	
void horiDivide(int *arr, int size, int ord)
{
	int horiDivArray[size][size];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			horiDivArray[r][c] = *((arr+r*size)+c);//set new array's values to reffered values in param.
		}
	}
	int x,y;
	for (x=0;x<size;x++)
	{
		for (y=0; y<size/2 ;y++)
		{
			swap(horiDivArray[x][y], horiDivArray[x][(size/2) + ((size/2)-y)]);
		}
	}
	printArr(&horiDivArray[0][0],size,ord);
	checkSum(&horiDivArray[0][0],size);		
}
void vertDivide(int *arr, int size, int ord)
{
	int vertDivArray[size][size];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			vertDivArray[r][c] = *((arr+r*size)+c);//set new array's values to reffered values in param.
		}
	}
	int x,y;
	for (x=0;x<size/2;x++)
	{
		for (y = 0; y < size ; y++)
		{
			swap(vertDivArray[x][y], vertDivArray[(size/2) + ((size/2)-x)][y]);
		}
	}
	printArr(&vertDivArray[0][0],size,ord);
	checkSum(&vertDivArray[0][0],size);
}
//swaps left and right columns
void horiFlip(int *arr, int size, int ord)
	{
		int horiArr[size][size];
		for (int r = 0; r < size; r++)
		{
			for (int c = 0; c < size; c++)
			{
				horiArr[r][c] = *((arr+r*size)+c);//set new array's values to reffered values in param.
			}
		}
		
		//manipulate horiArr
		int x, y = size-1;
		for (x = 0; x < size; x++)
		{
			swap(horiArr[x][0], horiArr[x][y]);//built in swap function
		}
		printArr(&horiArr[0][0], size, ord);//test print before manipulation, works so far
		checkSum(&horiArr[0][0], size);
	}
	
void vertFlip(int *arr, int size, int ord)
	{
		int vertArr[size][size];
		for (int r = 0; r < size; r++)
		{
			for (int c = 0; c < size; c++)
			{
				vertArr[r][c] = *((arr+r*size)+c);
			}
		}
		
		//manipulate vertArr
		int r=size-1, c; //changed vars to r and c for clarity
		for (c = 0; c < size; c++)
		{
			swap(vertArr[0][c], vertArr[r][c]);
		}
		printArr(&vertArr[0][0], size, ord);//test print before manipulation, works so far
		checkSum(&vertArr[0][0], size);		
	}
	
void megaFlip(int *arr, int size, int ord)
	{
		int megaArr[size][size];
		for (int r = 0; r < size; r++)
		{
			for (int c = 0; c < size; c++)
			{
				megaArr[r][c] = *((arr+r*size)+c);//set new array's values to reffered values in param.
			}
		}
		//manipulate horizontally
		int x, y = size-1;
		for (x = 0; x < size; x++)
		{
			swap(megaArr[x][0], megaArr[x][y]);
		}
		//manipulate vertically
		int r=size-1, c; //changed vars to r and c for clarity
		for (c = 0; c < size; c++)
		{
			swap(megaArr[0][c], megaArr[r][c]);
		}
		printArr(&megaArr[0][0], size, ord);
		checkSum(&megaArr[0][0], size);
	}
	
void transpose(int *arr, int size, int ord)
	{
		int tempArr[size][size];
		int transArr[size][size];
		for (int r = 0; r < size; r++)
		{
			for (int c = 0; c < size; c++)
			{
				tempArr[r][c] = *((arr+r*size)+c);//set new array's values to reffered values in param.
			}
		}
		
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
			{
				transArr[j][i]=tempArr[i][j];
			}
		printArr(&transArr[0][0],size,ord);
		horiFlip(&transArr[0][0],size,6);
		vertFlip(&transArr[0][0],size,7);
		megaFlip(&transArr[0][0],size,8);
	}
	
int main()
{
  int n;
  cout<< "Enter the size of a magic square: ";
  cin>>n;
  if ((n > 15) || (n < 3)) 
	{
		cin.clear();
		cin.ignore();
		cout << "Not a valid number. Please re-enter: ";
		cin >> n;	
		if ((n > 15) || (n < 3)) {return 1;}
	}
  int magicSquare[n][n]; //initialize array
  
  for(int i = 0; i < n; i++) //set all indices to 0
	{
		for(int j = 0; j < n; j++) 
		{
			magicSquare[i][j] = 0;
		}
	}

  // Set the indices for the middle of the top row
  int i =0 ;
  int j= n / 2;
  int newRow, newCol;
  
  // Fill each element of the array using siamese method
  for ( int value = 1; value <= n*n; value++ )
  {
     magicSquare[i][j] = value; //place value from 1->n^2
     
     // Find the next cell, wrapping around if necessary.
     newRow = (i - 1); //up one
     newCol = (j + 1); //to the right
     if (newRow < 0) {newRow = n-1;}   //overflow, move to bottom
     if (newCol > (n-1)) {newCol = 0;} //overflow, move to left end
     
     /* If the cell is empty, remember those indices for the
      next assignment. */
     if ( magicSquare[newRow][newCol] == 0 )
     {
        i = newRow;
        j = newCol;
     }
     else { i = (i + 1); }
  }  
  if (n > 3)
  {
	printArr(&magicSquare[0][0], n, 1); //1st square print main() created magicSquare
	checkSum(&magicSquare[0][0], n);
	//child squares
	horiFlip(&magicSquare[0][0], n,2);//horizontal flip, 2nd
	vertFlip(&magicSquare[0][0], n,3);//flip Vertical, 3rd
	megaFlip(&magicSquare[0][0], n,4);//flip both ways, 4th
	transpose(&magicSquare[0][0], n,5);//"transpose", 5th, 6th, 7th, and 8th
	horiDivide(&magicSquare[0][0], n,9);//Swap left and right HALVES
	vertDivide(&magicSquare[0][0], n,10);
  } 
  else
  {
	printArr(&magicSquare[0][0], n, 1); //1st square print main() created magicSquare
	checkSum(&magicSquare[0][0], n);
	//child squares
	horiFlip(&magicSquare[0][0], n,2);//horizontal flip, 2nd
	vertFlip(&magicSquare[0][0], n,3);//flip Vertical, 3rd
	megaFlip(&magicSquare[0][0], n,4);//flip both ways, 4th
	transpose(&magicSquare[0][0], n,5);
  }
	  
  
}
