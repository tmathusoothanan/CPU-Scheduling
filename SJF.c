#include<stdio.h>    
 int main(){  
   int arivaltime[10], bursttime[10], complitation_time[10], waiting_time[10], temp[10], turnarround_time[10];  
   
    
   int n, i, k, processes_completed=0, pointer = 0, time =0, c;  
   
   printf("Enter the number of processes: ");  
   scanf("%d",&n);  
   printf("Enter <ProcessName> <ArrivalTime> <BurstTime>\n");  
   for(i=0;i<n;i++){
   		
   		printf("Enter the ArrivalTime \n"); 
   		scanf("%d",&arivaltime[i]);
   		
   		printf("Enter the BurstTime \n");
		scanf("%d",&bursttime[i]); 
   }  
      
   for(i=0; i<n; i++){  
     complitation_time[i] = -1;  
     temp[i] = bursttime[i];  
   }  
   while(processes_completed!=n){  
     c = 0;  
     for(i=0; i<n; i++)  
       if(complitation_time[i]<0 && arivaltime[i]<=time)  
         c++;  
     if(c==0){
       time++;
   	}else{  
       pointer = 0;  
       while(arivaltime[pointer]>time || complitation_time[pointer]>0)  
         pointer++;  
       for(k=pointer+1; k<n; k++){
	   
         if(arivaltime[k]<=time && complitation_time[k]<0 && bursttime[pointer]>bursttime[k]){
           		pointer = k;
			}
		}
       if(complitation_time[pointer]<0){
         time=time+bursttime[pointer];  
         bursttime[pointer] = 0;  
         complitation_time[pointer] = time;  
         waiting_time[pointer] = complitation_time[pointer] - ( arivaltime[pointer]+ temp[pointer] );  
         turnarround_time[pointer] = complitation_time[pointer] - arivaltime[pointer];  
         processes_completed++;  
       }  
     }  
   }  
   printf("\nprocess\t arivaltime\t berst time\t complitation_time\t waiting_time\t turnarround_time\n");  
   for(i=0;i<n;i++) {
    	printf("process %d\t %d\t      %d\t              %d\t                     %d\t                     %d\n",i+1, arivaltime[i],temp[i],complitation_time[i],waiting_time[i],turnarround_time[i]);
	}
	
	//calculate average turnaround time 
	float avg_turn = 0;
	for(i=0; i<n; i++){
		avg_turn+=turnarround_time[i];
	}
	
	//calculate average waiting time
	float avg_wait = 0;
	for(i=0; i<n; i++){
		avg_wait += waiting_time[i];
	}
	
	//calculate throughput
	float throughput = (float)n/((float)complitation_time[n - 1] - (float)arivaltime[0] );
	printf("n is %d complitation time is %d arival time is %d", n ,complitation_time[n - 1], arivaltime[0] );
	
	printf("\n");
	printf("\n");
	printf("Average turn around time is %f\n", avg_turn/n );
	printf("Average waiting time is %f\n", avg_wait/n );
	printf("Throughput is %f\n", throughput );
   return 0;  
 }
 
 
 
 
