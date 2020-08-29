#include<bits/stdc++.h>
#include<iostream>
#define operationTime 18
#include<time.h>
using namespace std;

class CustomerSimulation{
	int customers,arrival,servicetime,wait;
	public:
		CustomerSimulation():customers(0),arrival(0),servicetime(0){}
		
		int nCustomers()
		{ 
			customers=(rand()%18+1);
			cout<<customers<<endl;
			return customers;
		}
		int serTime()
		{
			servicetime=(3+rand()%((8-3)+1));
			return servicetime;
		}
		int arrivalTime()
		{
			arrival=(rand()%50+1); //no customer can arrive after 50th minuite oh hour
			return arrival;
		}
	
		void sortCustomers(int arr[],int n)
		{
			int i,j,flag;
			for(i=0;i<n;i++)
			{	flag=0;
				for(j=0;j<n-i-1;j++)
				{
					if(arr[j]>arr[j+1]){
						int t=arr[i];
						arr[i]=arr[j];
						arr[j]=t;
						flag=1;}
				}
				if(flag==0){
					break;}	
			}
		}
	/*	int waitingTime(int cno)
		{
		}
		*/
};
template<class T>
class Queue:public CustomerSimulation{
	private:
		T *data;
		int NoOfcustomers;   //size
		int front;           //first
		int rear;            //last
		int cCount;
		int wait;
		T *servicetime;       //to store service time for each customer
	public:
		
		Queue(int n)
		{
			NoOfcustomers=n;
			data=new T[NoOfcustomers];
			servicetime=new T[NoOfcustomers];
			front=0;
			rear=0;
			cCount=0;
		}
		int Tservice;
		bool isFull()
		{
			if(getsize()==NoOfcustomers){
				return 1;
			}
			else
				return 0;
		}	
		bool isEmpty()
		{
			if(getsize()==0)
				return 1;
			else
				return 0;	
		}
		T getfront()
		{
			return data[front];
		}
		
		int enqueue(T x)
		{
			if(this->isFull())
				cout<<"Queue full";
			else
			{
				cCount++;
				data[rear]=x;
				servicetime[rear]=serTime();
				Tservice=Tservice+servicetime[rear];
				rear++;
			}
		}
		
		int waitingTime(int cno)
		{
			if(cno>0){
				wait+=servicetime[cno-1];
				return wait%100;
			}
			else if(cno==0)
			{
				if(wait>60)
					wait-=(60-data[cno]);
				else
					wait=0;
				return wait%60;
			}
		}
			
		int dequeue()
		{
			int wt=this->waitingTime(front);
			front++;
			cCount--;
			for(int i=0;i<cCount;i++){
				data[i]=data[i+1];
			}
			return wt;          // waiting time will be returned when dequeued
		}
		
		int getsize()
		{
			return cCount;
		}	
};

main()
{
	srand(time(NULL));
	CustomerSimulation cs;
	int CstPerHour[operationTime],customerInOpHour=0,i,j,l,noOfcustomers=0,waitSum=0;
	int avgWait[operationTime],avgService=0,TsumService;
	ofstream outputFile;
	outputFile.open("A2 Q3.txt");
	
	for(i=1;i<=operationTime;i++)
	{
		cout<<"customers in hour "<<i<<" : ";
		noOfcustomers=cs.nCustomers();
		CstPerHour[i-1]=noOfcustomers;                     //get noOfcustomers per hour
		customerInOpHour+=noOfcustomers;                    //total customer in 18 hours;
		Queue<int> q(noOfcustomers);
		int arrivaltimes[noOfcustomers];
		for(l=0;l<noOfcustomers;l++)
		{
			arrivaltimes[l]=cs.arrivalTime();
		}
		cs.sortCustomers(arrivaltimes,noOfcustomers);
		for(j=0;j<noOfcustomers;j++){
			q.enqueue(arrivaltimes[j]);
		}
		
		for(j=0;j<noOfcustomers;j++){
			int y=q.dequeue(); 
			waitSum+=y;
		}
		
		avgWait[i-1]=(int)(waitSum/noOfcustomers);    //average waiting time in each hour
		avgService=(int)(q.Tservice/noOfcustomers);   //avg serice time in ith hour
		TsumService+=avgService;                      //total service time for 18 hours
	}
	
		int avg=(int)(TsumService/operationTime);     //avg service time by 18 hours
		outputFile<<"Total number of customers in 18 hours : "<<customerInOpHour<<endl<<endl;
		
		for(l=0;l<operationTime;l++)
		{
			outputFile<<"Customer in hour "<<l+1<<" : "<<CstPerHour[l]<<endl;
			outputFile<<"Average Waiting Time Of Hour "<<l+1<<" : "<<avgWait[l]<<endl;
	    	outputFile<<"Average Customer in Hour "<<l+1<<" : "<<(int)(avgWait[l]/CstPerHour[l])<<endl;
	    
		}
		cout<<"\nTotal customers in operational hours : "<<customerInOpHour;
		cout<<"\nAverage customers in 18 hours : "<<(int)(customerInOpHour/18)<<endl;
		outputFile<<"Total average service time for 18 Hours is "<<" : "<<avg<<endl;
		
	
}
