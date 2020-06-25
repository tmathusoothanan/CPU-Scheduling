#include<stdio.h>
cal_turnaround_time(int x,int y);
cal_waiting_time(int x, int y);

int processcount , i;
	int  arivaltime[10] , bursttime[10] ;
	int a[] = {1,2,3,4,5,66};

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
	
	
	//Calculate completation time
	int complitation_time[10];
	//int s;
	for(s=0; s<processcount; s++){
		if(s == 0){
			
			//for first process
			complitation_time[s] = arivaltime[s] + bursttime[s];
			
		}else if(complitation_time[s - 1] < arivaltime[s]){
			
			//arival time > complitation time
			complitation_time[s] = arivaltime[s] + bursttime[s];
			
		}else{
			
			complitation_time[s] = complitation_time[s - 1] + bursttime[s];
		}
		
		
	}
	
	//print completion time
	int t;
	for(t=0; t<processcount; t++){
		//printf("completion times are %d \t\n",complitation_time[t] );
	}
	
	
	//call turnaround time function
	int x;
	int turn[10];
	for(x=0; x<processcount; x++){
		
		turn[x] = cal_turnaround_time(x, complitation_time[x]);
		//printf("process %d is turnaround time is %d\n", x+1 , turn[x]);
	
	}
	
	//call waiting time function
	int m;
	int waiting[10];
	for(m = 0; m< processcount; m++){
		
		waiting[m] = cal_waiting_time(m, complitation_time[m]);
		//printf("process %d is vaiting time is %d\n", m+1 , waiting[m]);
	}
	
	
	//calculate Average turnaround time
	float avg_turn=0;
	int v;
	for(v = 0; v< processcount; v++){
		avg_turn += turn[v];
	}
	
	
	//calculate average waiting time
	float avg_wait = 0;
	int w;
	for(w=0; w<processcount; w++){
		avg_wait += waiting[w];
	}
	
	
	
	//calculate throughput
	float throughput = (float)processcount/((float)complitation_time[processcount - 1] - (float)arivaltime[0] );	
	//printf("Throughput is %f\n" , throughput);
	
	
	
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	//Printing final result
	printf("Process \t\t Arival Time \t\t Burst Time \t\t Completion time \t\t turnaround Time \t Waiting time\n");
	int z;
	for(z = 0; z<processcount; z++){
		printf("Process %d \t------------    %d \t--------    %d \t\t--------    %d \t\t-------------     %d \t-------------    %d\n\n\n", z+1, arivaltime[z],bursttime[z],complitation_time[z],turn[z], waiting[z] );
	} 
	
	
	printf("Average turnaround time is %f\n" , avg_turn/processcount);
	printf("Average Waiting time is %f\n" , avg_wait/processcount);
	printf("Throughput is %f\n" , throughput);
	
	
	//Print the garnt chart
	
	//for(i=0;i<processcount;i++){
	//	if(i != processcount-1){
	//		if(i==0){
				
	//			printf("%d  ---->  %d ",arivaltime[i],complitation_time[i]);
	//			printf(" P%d ",i+1);
				
	//		}else{
	//			printf("%d  ---->  %d ",complitation_time[i-1],complitation_time[i]);
	//			printf(" P%d ",i+1);
	//		}
			
	//	}
		
	//}
	
	return 0;
}


//calculate turnaround time
int cal_turnaround_time(int x, int y){
	int turnaround_time;
	
	turnaround_time = y - arivaltime[x];
		
	
	return turnaround_time;
}

//calculate waiting time
int cal_waiting_time(int x, int y){
	int waiting_time;
	
	int w = arivaltime[x] + bursttime[x];
	waiting_time = y - w;
	return waiting_time;
}
































