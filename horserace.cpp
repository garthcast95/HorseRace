#include<iostream>
#include<string>
#include <stdlib.h> 
#include<time.h> 
#include <unistd.h>
using namespace std;
void show_track(string track[5][15])
{
   for(int i=0;i<5;++i)
   {
	for(int j=0;j<15;++j)
	{
		cout<<track[i][j];
	}
	cout<<endl;
   }	
cout<<endl;
	
}
int get_loc(string track[15])
{
 
	for(int j=0;j<15;++j)
	{
          if(track[j]!=".")
	 	return j;
	}	
return -1;
}
int main()
{
   string racetrack[5][15];
   for(int i=0;i<5;++i)
   {
	for(int j=0;j<15;++j)
	{
		if(j==0)
			racetrack[i][j]=char(48+i);	//
		else					// initialization of the race track....
                	racetrack[i][j]=".";		//	
	}
   }
   srand(time(NULL));
   bool win=false;
   do{		
        show_track(racetrack);
	for (int i = 0; i<5;++i)
	{
		if(rand()%2)
		{
			int ind=get_loc(racetrack[i]);
			if(ind==-1)
			{
				win=true;
				show_track(racetrack);
				cout<<"horse "<<i<<" won the race!"<<endl;
				break;
			}
			else
			{
				racetrack[i][ind]=".";
				if((ind+1)<15)
				{
					racetrack[i][ind+1]=char(48+i);
				}
				else
				{
					win=true;
					show_track(racetrack);
					cout<<"horse "<<i<<" won the race!"<<endl;
					break;				
				}

			}	
		}
			 
   	}
        sleep(1);
	}while(!win);
return 0;
}
