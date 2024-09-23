#include <iostream>
using namespace std;
int main()
{
	int card_1,card_2,card_3,card_4,card_5;
	int rem_1,rem_2,rem_3,rem_4,rem_5;
	int q_1,q_2,q_3,q_4,q_5;
	cout<<"Enter the value between (1-52)";
	cout<<"\nEnter the value of first card:";
	cin>>card_1;
	cout<<"\nEnter the value of second card:";
	cin>>card_2;
	cout<<"\nEnter the value of third card:";
	cin>>card_3;
	cout<<"\nEnter the value of fourth card:";
	cin>>card_4;
	cout<<"\nEnter the value of fifth card:";
	cin>>card_5;
	int count=0,count1=0;
	rem_1=card_1%13;
	rem_2=card_2%13;
	rem_3=card_3%13;
	rem_4=card_4%13;
	rem_5=card_5%13;
	if(card_1%13==0)
{
	q_1=(card_1/13)-1;
}
else 
{
	q_1=card_1/13;
}
if(card_2%13==0 )
{
	q_2=(card_2/13)-1;
}
else 
{
	q_2=card_2/13;
}
if(card_3%13==0 )
{
	q_3=(card_3/13)-1;
}
else
{
	q_3=card_3/13;
}
if(card_4%13==0 )
{
	q_4=(card_4/13)-1;
}
else
{
	q_4=card_4/13;
}
if(card_5%13==0 )
{
	q_5=(card_5/13)-1;
}
else
{
	q_5=card_5/13;
}
	if(rem_1 > rem_2)
	{
		swap(rem_1,rem_2);
	}
	if(rem_1 > rem_3)
	{
		swap(rem_1,rem_3);
	}
	if(rem_1 > rem_4)
	{
		swap(rem_1,rem_4);
	}
	if(rem_1>rem_5)
	{
		swap(rem_1,rem_5);
	}
	  if(rem_2>rem_3)
	  {
	  	swap(rem_2,rem_3);
	  }
	  if(rem_2>rem_4)
	  {
	  	swap(rem_2,rem_4);
	  }
	  if(rem_2>rem_5)
	  {
	  	swap(rem_2,rem_5);
	  }
	  if(rem_3>rem_4)
	  {
	  	swap(rem_3,rem_4);
	  }
	  if(rem_3>rem_5)
	  {
	  	swap(rem_3,rem_5);
	  }
	  if(rem_4>rem_5)
	  {
	  	swap(rem_4,rem_5);
	  }
	 int sum=0;
	  sum=rem_1+rem_2+rem_3+rem_4+rem_5; 
	   if(rem_1==rem_2)
	   {
	   	count++;
	   }
	   if(rem_2==rem_3)
	   {
	   	count++;
	   }
	   if(rem_3==rem_4)
	   {
	   	count++;
	   }
	   if(rem_4==rem_5)
	   {
	   	count++;
	   }
	   int temp;
	//   cout<<"\nThe value of count is"<<count;
	   if(count==4)
	   {
	   	if(rem_3!=rem_4 && rem_4==rem_3)
	   	{
	   		count1++;
	   		if(rem_4==rem_5)
	   		{
	   			count1++;
			   }
		   }
	   }
	   if(rem_1==rem_2 && rem_2!=rem_3 && rem_3==rem_4 && rem_4==rem_5)
	   {
	   	count1=3;
	   }
	   else if(rem_1==rem_2 && rem_2==rem_3 && rem_3!=rem_4 && rem_4==rem_5)
	   {
	   	count1=2;
	   }
	//   cout<<"\nThe value of count1 is "<<count1;
	   
	    if (q_1==q_2 && q_2==q_3 && q_3==q_4 && q_4==q_5)
	  {
	  	if(sum==34)
	  	{
	  		cout<<"\nThe set of cards you entered is a Royal flush ";
		  }
		  else if(sum%5==0)
		  {
		  	cout<<"\nThe set of cards you entered is a Straight flush";
		  }
		  else 
		  {
		  	cout<<"\The set of cards you entered is a Flush";
		  }
	  }
	  else if(count==3 && count1==3 || count==3 && count1==2)
	  {
	  	cout<<"\nThe set of cards you enteres is a full house";
	  }
	  else if (count==3)
	  {
	  	cout<<"\nThe set of cards you entered is a Four of a Kind";
	  }
	  else if(count==2)
	  {
	  cout<<"\nThe set of cards you entered is a Three of a Kind";
	  }
	  else if(count==1)
	  {
	  	cout<<"\nThe set of cards you entered is a Two pair card";
	  }
	  else if(sum%5==0)
	  {
	  	cout<<"\nThe set of cards you entered is straight";
	  }
	  else if(count==2 && count1==1)
	  {
	  	cout<<"\nThe set of cards you entered is two pair";
	  }
	  else 
	  {
	  	cout<<"\nThe set of cards you entered is a high card";
	  }
	  
	 /* cout<<"\n"<<rem_1;
	  cout<<"\n"<<rem_2;
	  cout<<"\n"<<rem_3;
	  cout<<"\n"<<rem_4;
	  cout<<"\n"<<rem_5;
	//  cout<<count;*/
}
