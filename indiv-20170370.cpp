#include <iostream>
#include <algorithm>

using namespace std;


int jump(int arr[],int s,int n){ //to move from the first column to the last column with the lowest total cost

int sorarr[s],x=0;
for(int i=0;i<s;i++){sorarr[i]=arr[i];}
sort(&sorarr[0],&sorarr[s-1]);

for(int i=0;i<s;i++){ //to check if elements of array sorted or not , x=1 if not
    if(sorarr[i]!=arr[i]){x=1;}
}

if(s-1==n){return 0;} //check to see if we are at the end of array, stopping case

else{  //now check which costs less, a jumping two columns or moving to the adjacent column

   if(x==1){

      if(n<s-3){ //check if more two positions from the end
          if(arr[n+1]<arr[n+2]){return arr[n+1]+jump(arr,s,n+1);}//move to the adjacent column
          else{return arr[n+2]+jump(arr,s,n+2);} //jump to land two columns over
      }
      else{return arr[s-1];} //there is no jump,move to the end
   }

   else{return arr[n+2]+jump(arr,s,n+2);}

}

}

int main()
{
   int arrsize;
   cout<<"enter the size of array : "<<endl;
   cin>>arrsize ;
   int arr[arrsize] ;
   cout<<"ARRAY:"<<endl;

   arr[0]=0; //first column, which always contains 0
   cout<<arr[0]<<endl;
   for(int i=1;i<arrsize;i++){cin>>arr[i];}

   cout<<"The Lowest total cost= "<<jump(arr,arrsize,0); //The cost is the sum of the costs of the columns visited

    return 0;
}
