#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getint(int ascii);

int main(){
    char ip[15];
    printf("Enter the Ip address of the:\n");
    scanf("%s",ip);
    int iparray[4];
    
    char concatstr[3];
    int count=0;
    //printing ip address;
    for(int i=0;i<15;i++){
        
        int dot=(int)'.';
        int dotip=(int)ip[i];
        if(dot == dotip){
            int intip=atoi(concatstr);
            iparray[count]=intip;
            count+=1;
            concatstr[0]='\0';
            continue;
        }
        int newint=(int)ip[i];
        int value=getint(newint);
        char string[20];
        sprintf(string,"%d",value);
        strcat(concatstr,string);
    }

    int intiplast=atoi(concatstr);
    iparray[count]=intiplast;




    //check class of ip address

    if(iparray[1] > 255||iparray[2] > 255||iparray[3] > 255){
        printf("this is invalid ip address");
    }else{
        // printf("THis is class A ip address");
        if(iparray[0] >= 0 && iparray[0] <=127){
            printf("THis is class A ip address");
        }else if(iparray[0] >=128 && iparray[0] <=191){
            printf("THis is class B ip address");
        }else if(iparray[0] >=192 && iparray[0] <=223){
            printf("THis is class C ip address");
        }else if(iparray[0] >=224 && iparray[0] <=239){
            printf("THis is class D ip address");
        }else if(iparray[0] >=240 && iparray[0] <=255){
            printf("THis is class E ip address");
        }else{
            printf("this is invalid ip address");
        }

    }

    return 0;
}





int getint(int ascii){
    int count=0;
    for(int i=48;i<=57;i++){
        if(ascii==i){
            return count;
        }
        count+=1;
    }
    
}