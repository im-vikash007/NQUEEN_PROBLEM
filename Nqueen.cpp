#include<bits/stdc++.h>
using namespace std;
bool is_safe(char arr[100][100],int row ,int col,int n)
{ // check is queen already present in row 
    for(int i=0;i<col;i++)
    {
        if(arr[row][i]=='Q')
          return false;
    }
  // check is queen already present in column
    for(int i=0;i<row;i++)
    {
       if(arr[i][col]=='Q')
          return false;
    }
  //checking presence of queen in diagonally up left
   for(int i=row,j=col;i>=0&&j>=0;i--,j--)
   {
       if(arr[i][j]=='Q')
         return false;
   }
  //checking presence of quen in diagonally up right
  for(int i=row,j=col;i>=0&&j<n;i--,j++)
   {
       if(arr[i][j]=='Q')
         return false;
   }
   return true;
}
bool nqueen(char arr[100][100],int row,int n)
{
    if(row>=n)
    { for(int i=0;i<n;i++)
      {
       for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
       }
      cout<<endl;
      return false; // return true for only solution if exist
    }
    for(int col=0;col<n;col++)
    {
        if(is_safe(arr,row,col,n))
        {   arr[row][col]='Q';
            bool next_possible=nqueen(arr,row+1,n);
            if(next_possible)
               return true; //recursion
        }
        arr[row][col]='.';
    }
    return false;// backtracking
}
int main()
{
   int n;
   cin>>n;
   char arr[100][100];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
         arr[i][j]='.';
   }
   nqueen(arr,0,n); 
  return 0;
}
