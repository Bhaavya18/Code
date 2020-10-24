#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void longestseries(vector<int>&arr)
{
    unordered_map<int,bool>map;
    for(int ele: arr)
    {
        map[ele]=true;      //making each ele start
    }

    int size=-1;
    int number=-1;
     for(auto keys : map)
     {
         if(map.find(keys.first-1)!=map.end())
         {
             map[keys.first]=false;               //checking for potentail start
         }

     }

     for(auto keys : map)
     {
         if(keys.second)
         {
             int num=keys.first+1;
             int smallsize=1;

             while(map.find(num)!=map.end())
             {
                num++;
                smallsize++;
             }

             if(smallsize>size)
             {
                 size=smallsize;
                 number=keys.first;
             }
         }

     }
         
         for(int i=0;i<size;i++)
         {
             cout<<(number+i)<<" ";
         }
     }

    int main()
    {
        vector<int>arr={0,1,2,3,4,5,6,8,9,11,12,13,15,18};
        longestseries(arr);
        return 0;
    }



 
