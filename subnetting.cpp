//subnetting calculator using c program
//by sushan poudyal

#include<stdio.h>
#include<math.h>
int main()
{
	printf("hello this is sushan poudyal\n\n\n");
    int ip1,ip2,ip3,ip4,CIDR,onbit,offbit,networkid,host,blocksize;
    char cl;
    printf("enter IP address \n");
    scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
    
    do
    {
        if((ip1 >255 || ip2 >255 || ip3 >255 || ip4 >255) || (ip1 == 127 || ip2 == 191 || ip3 == 255) || (ip1 == 0 && ip2 == 0 && ip3 == 0 &&ip4 == 0))
        {
           
            printf(" enter a valid IP address\n");
            scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
        }
    }while((ip1 >255 || ip2 >255 || ip3 >255 || ip4 >255) || (ip1 == 127 || ip2 == 191 || ip3 == 255) || (ip1 == 0 && ip2 == 0 && ip3 == 0 && ip4 == 0));

      
           
            printf("Enter CIDR \n");
            
            scanf("%d", &CIDR);
        do{
        
            if(CIDR > 32 || CIDR == 0)
            {
               
                printf("enter a valid CIDR\n");
            
                scanf("%d", &CIDR);
            }
        }while(CIDR > 32);
         
    
    if(ip1 <=127) {
        cl = 'A';
    }else if(ip1 <=190) {
        cl = 'B';
    }else {
        cl = 'C';
    }
    
    switch (cl) {
        case 'A':
            if(CIDR >= 8) {
                onbit = CIDR - 8; 
            }else {
                onbit = 8 - CIDR;
            }
            break;
        case 'B':
            if(CIDR >= 16) {
                onbit = CIDR - 16;
            }else {
                onbit = 16 - CIDR;
            }
            break;
        case 'C':
            if(CIDR >= 24) {
                onbit = CIDR - 24;
            }else {
                onbit = 24 -CIDR;
            }
    }
    
    switch (cl) {
        case 'A':
            offbit = 32 - CIDR;
            break;
        case 'B':
            offbit = 32 -CIDR;
            break;
        case 'C':
            offbit = 32 -CIDR;
            break;
    }
    networkid = pow(2,onbit);
    host = pow(2,offbit)-2;
    
    
    switch(onbit) {
        case 1:
            blocksize = 128;
            break;
        case 2:
            blocksize = 64;
            break;
        case 3:
            blocksize = 32;
            break;
        case 4:
            blocksize = 16;
            break;
        case 5:
            blocksize = 8;
            break;
        case 6:
            blocksize = 4;
            break;
        case 7:
            blocksize = 2;
            break;
        case 8:
            blocksize = 1;
            break;
    }
   
    printf("your ip  %d.%d.%d.%d/%d is of cl %c\n",ip1,ip2,ip3,ip4,CIDR,cl);
     printf("Number of onbit is:\t%d \n", onbit);
     printf("Number of offbit is:\t%d \n", offbit);
     printf("networkid:\t%d \n", networkid);
    printf("host:\t%d \n", host);
    printf("blocksize:\t%d \n", blocksize);

}

