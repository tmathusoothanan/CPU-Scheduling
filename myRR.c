#include<stdio.h>

cal_completion_time();
cal_turnarround_time(int x , int y);
cal_waiting_time(int x, int y);



int i, processcount, time_quantam, arivaltime[10], bursttime[10],tempbursttime[10], temp[10], complitation_time[10];

int main(){
	printf("Enter the number of process \t");
	scanf("%d" , &processcount);
	
	//taking the inputs and save into appropriate variables
	for(i = 0; i < processcount; i++){
		
		printf("Process %d \n", i+1);
		printf("Enter the arrival time  \n");
		scanf("%d" , &arivaltime[i]);
		
		printf("Enter the Burst time  \n");
		scanf("%d" , &bursttime[i]);
		
	}
	
	
	printf("Enter the Time Quantam  \n");
	scanf("%d" , &time_quantam);
	
	for(i=0;i<processcount;i++){
		tempbursttime[i] = bursttime[i];
	}
	
	//sorting arival time and burst time
	int s,p;
	for(s=0; s< processcount; s++){
		
		for(p=s+1; p< processcount; p++){
			//arival time 1 > arival time 2 
			if(arivaltime[s]>arivaltime[p]){
				
				int tempar = arivaltime[s];
				arivaltime[s] = arivaltime[p];
				arivaltime[p] = tempar;
				
				int tempber = bursttime[s];
				bursttime[s] = bursttime[p];
				bursttime[p] = tempber;
				
			}else if(arivaltime[s] == arivaltime[p]){
				if(bursttime[s]>bursttime[p]){
					int tempar = arivaltime[s];
					arivaltime[s] = arivaltime[p];
					arivaltime[p] = tempar;
				
					int tempber = bursttime[s];
					bursttime[s] = bursttime[p];
					bursttime[p] = tempber;
				}
			}
		
		}
	
	
}	

for(i=0;i<processcount;i++){
	printf("%d" , arivaltime[i]);
	printf("%d\n" , bursttime[i]);
}

// call complection time function
int a = cal_completion_time();

//call turnaround function
int turn[10];
for(i=0;i<processcount;i++){
	turn[i] = cal_turnarround_time(i ,complitation_time[i] );
	//printf("turnaround time is %d\n" , turn[i]);
}

// call waiting time function
int waiting[10];
	for(i = 0; i< processcount; i++){
		
		waiting[i] = cal_waiting_time(i, complitation_time[i]);
		//printf("process %d is waiting time is %d\n", i+1 , waiting[i]);
	}
	
	
	
	
	
	
	
	
	//print average turnaround time
	float avg_turn=0.0;

	for(i = 0; i< processcount; i++){
		avg_turn += turn[i];
	}
	avg_turn = avg_turn/processcount;
//	printf("Average turnaround time is %f\n", avg_turn);
	
	//print average waiting time
	float avg_wait = 0;
	for(i=0; i<processcount; i++){
		avg_wait += waiting[i];
	}
	avg_wait = avg_wait/processcount;
//	printf("Average waiting time is %f\n", avg_wait);

//calculate throughput
float throughput = (float)processcount/((float)complitation_time[processcount - 1] - (float)arivaltime[0] );
	
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	//Printing final result
	printf("Process \t\t Arival Time \t\t Burst Time \t\t Completion time \t\t turnaround Time \t Waiting time\n");

	for(i = 0; i<processcount; i++){
		printf("Process %d \t------------    %d \t--------    %d \t\t--------    %d \t\t-------------     %d \t-------------    %d\n\n\n", i+1, arivaltime[i],tempbursttime[i],complitation_time[i],turn[i], waiting[i] );
	} 
	
	
	printf("Average turnaround time is %f\n", avg_turn);
	printf("Average waiting time is %f\n", avg_wait);
	printf("Throughput is %f\n", throughput);
	return 0;
	
}

//calculate completion time

int cal_completion_time(){

	int total=0;
	for(i=0;i<processcount;i++){
		total += bursttime[i];
	}
	
	int j;
	for(j=0;j<10;j++){
	
	for(i=0; i<processcount; i++){
		
		//if berst time is 0 then no need to perform this operation
		if(bursttime[i]!=0){
		
		//for first process
		if(i == 0){
			
			if(j==0){
				
				if(bursttime[i]<=time_quantam){
					complitation_time[i] = arivaltime[i] + bursttime[i] + temp[i];
					bursttime[i] = 0;
				}else{
					temp[i] += time_quantam;
					complitation_time[i] = time_quantam;
					bursttime[i] = bursttime[i] - time_quantam;
				}
			
			}else{
				if(bursttime[i]<=time_quantam){
					complitation_time[i] = complitation_time[processcount-1] + bursttime[i];//
					bursttime[i] = 0;
				
				}else{
					//didnt reach this place
					temp[i] += time_quantam;
					complitation_time[i] = complitation_time[processcount-1];
					bursttime[i] = bursttime[i] - time_quantam;
					printf("hello %d = ",complitation_time[i]);
				}
			}
			
		}else if(complitation_time[i - 1] < arivaltime[i]){
			
			if(j==0){
				
				if(bursttime[i]<=time_quantam){
					complitation_time[i] = arivaltime[i] + bursttime[i] + temp[i];
					bursttime[i] = 0;
				}else{
					temp[i] += time_quantam;
					complitation_time[i] = time_quantam;
					bursttime[i] = bursttime[i] - time_quantam;
				}
			
			}else{
				if(bursttime[i]<=time_quantam){
					complitation_time[i] = complitation_time[processcount-1] + bursttime[i];//
					bursttime[i] = 0;
				
				}else{
					//didnt reach this place
					temp[i] += time_quantam;
					complitation_time[i] = complitation_time[processcount-1];
					bursttime[i] = bursttime[i] - time_quantam;
					printf("hello %d = ",complitation_time[i]);
				}
			}
			
			
			
		}else{
			
			if(j==0){
			
				if(bursttime[i]<=time_quantam){
					complitation_time[i] = complitation_time[i-1] + bursttime[i] + temp[i];
					bursttime[i] = 0;
				}else{
					temp[i] += time_quantam;
					complitation_time[i] = complitation_time[i-1] + time_quantam;
					bursttime[i] = bursttime[i] - time_quantam;
				}	
			}else{
				
				if(bursttime[i]<=time_quantam){
					complitation_time[i] = complitation_time[i-1] + bursttime[i];//
					bursttime[i] = 0;
				}else{
					temp[i] += time_quantam;
					complitation_time[i] = complitation_time[i-1] + time_quantam;
					bursttime[i] = bursttime[i] - time_quantam;
				}
				
			}
		}
		
	}
	}
	
	
	total=0;
	for(i=0;i<processcount;i++){
		total += bursttime[i];
	}
	
//	printf("Total is %d" , total);
	
}
	
	
for(i=0;i<processcount;i++){
	//printf("process %d completion time %d\n",i,complitation_time[i]);
}	
		
	return 1;
	
}

//Calculate turnaround time
int cal_turnarround_time(int x , int y){
	return y - arivaltime[x];
}



//calculate waiting time
int cal_waiting_time(int x, int y){
	int waiting_time;
	
	int w = arivaltime[x] + tempbursttime[x];
	//printf("arival time is %d and burst time is %d and y is %d \n",arivaltime[x],bursttime[x], y);
	waiting_time = y - w;
	return waiting_time;
}



