#include <stdio.h>
#include<string.h> 
int main()
{
	FILE *fp = NULL;
	char buff[255];
	int min=0;
	int sec=0;
	int totaltime=0;
	fp = fopen("time2.txt", "r");
	for(int i=0;i<100;i++){
		if(fgets(buff, 10, (FILE*)fp)==NULL){
			//printf("Read over!\n");
			break;
			}
		int k=0;
		int flag=0;
		for(int j=0;j<10;j++){
			if((buff[j]-48)<0)
				break;
			if(k==0&&buff[j+1]!=58){
				min=min+((int)buff[j]-48)*10;
				//printf("min is %d,buff[%d]is %d\n",min,j,((int)buff[j]-48));
				k++;
				flag=1;
			}
			else if(buff[j+1]==58){
                                min=min+((int)buff[j]-48);
				//printf("min is %d,buff[%d]is %d\n",min,j,((int)buff[j]-48));
				k++;
			}
			else if(buff[j]==58)
				k++;
			else if(buff[j-1]==58){
                                sec=sec+((int)buff[j]-48)*10;
				//printf("sec is %d,buff[%d]is %d\n",sec,j,((int)buff[j]-48));
                                k++;
                        }
			else if(flag==1&&k==4){
				sec=sec+((int)buff[j]-48);
				//printf("sec is %d,buff[%d]is %d\n",sec,j,((int)buff[j]-48));
				break;
			}
			else if(flag==0&&k==3){
				sec=sec+((int)buff[j]-48);
				//printf("sec is %d,buff[%d]is %d\n",sec,j,((int)buff[j]-48));
				//printf("Next Line\n");
				break;
			}
}

		memset(buff,0,255);
}
	fclose(fp);
	totaltime=min*60+sec;
	double totalhour=(double)totaltime/3600.0;
	printf("TotalHour is %lf\n",totalhour);
}
