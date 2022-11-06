#include <stdio.h>
#include <string.h>

int decimal_to_binary(char binaryip[]);

int main(){
    int subnetA=255;

    int subnetB[2]={255,255};
    // int subnetB_frag_2=255;

    int subnetC[3]={255,255,255};
    // int subnetC_frag_2=255;
    // int subnetC_frag_3=255;

    char binip[35];
    printf("Enter the ip address you want t check for:\n");
    scanf("%s",binip);
    // printf("%s\n",binip);
    int deciparray[4];
    int networkid[3];
    char formatedstring[100];
    // char binaryip[8]="11111111";
    char newstring[8];
    int count=0;
    for(int i=0;i<=34;i++){
        int dot=(int)'.';
        char string[3];
        int intipvalue=(int)binip[i];
        if(dot==intipvalue){
            int value=decimal_to_binary(newstring);
            deciparray[count]=value;
            newstring[0]='\0';
            count+=1;
            continue;
        }

        if(intipvalue==48){
            sprintf(string,"%d",0);
            strcat(newstring,string);
        }else if(intipvalue==49){
            sprintf(string,"%d",1);
            strcat(newstring,string);
        }
        // printf("%s\n",newstring);
       
    }
    int value=decimal_to_binary(newstring);
    deciparray[count]=value;

    if(deciparray[1] > 255||deciparray[2] > 255||deciparray[3] > 255){
        printf("this is invalid ip address");
    }else{
        // printf("THis is class A ip address");
        if(deciparray[0] >= 0 && deciparray[0] <=127){
            printf("THis is class A ip address\n");
            int netid=deciparray[0] & subnetC[0];
            networkid[0]=netid;
            sprintf(formatedstring,"Netork id is:  %d.0.0.0",networkid[0]);
            printf("%s",formatedstring);
        }else if(deciparray[0] >=128 && deciparray[0] <=191){
            printf("THis is class B ip address\n");
            for(int i=0;i<=1;i++){
                int netid=deciparray[i] & subnetC[i];
                networkid[i]=netid;
            }
            sprintf(formatedstring,"Netork id is:  %d.%d.0.0",networkid[0],networkid[1]);
            printf("%s",formatedstring);
        }else if(deciparray[0] >=192 && deciparray[0] <=223){
            printf("THis is class C ip address\n");
            for(int i=0;i<=2;i++){
                int netid=deciparray[i] & subnetC[i];
                networkid[i]=netid;
            }
            sprintf(formatedstring,"Netork id is: %d.%d.%d.0",networkid[0],networkid[1],networkid[2]);
            printf("%s",formatedstring);
        }else if(deciparray[0] >=224 && deciparray[0] <=239){
            printf("THis is class D ip address\n");
            printf("Class D ip address has no Network ID\n");
        }else if(deciparray[0] >=240 && deciparray[0] <=255){
            printf("THis is class E ip address\n");
            printf("Class E ip address has no Network ID\n");
        }else{
            printf("this is invalid ip address");
        }

    }

    return 0;
}


int decimal_to_binary(char binaryip[]){
    int sum=0;
    int pow=7;
    for(int i=0;i<=7;i++){
        
        int powerproduct=1;
        int decimalvalue;
        int asciivalue=(int)binaryip[i];
        if(asciivalue==48){
            decimalvalue=0;
        }else if(asciivalue==49){
            decimalvalue=1;
        }

        if(pow==0){
            powerproduct=1;
        }else{
            for(int j=1; j<=pow; j++){
            powerproduct*=2;
            }
        }
        int calc=powerproduct*decimalvalue;
        sum+=calc;
        // printf("%d\n",calc);
        pow-=1;
      
    }
    return sum;
}