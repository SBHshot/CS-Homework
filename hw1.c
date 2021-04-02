#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 6

/*Function Prototypes*/
int isallnumber(char *str); //判斷輸入字串是否皆全為數字
void swap(int *a, int *b);
int * selection_sort(int * list);


/*Run the program.*/
int main (void){
	char string[256]; //儲存從鍵盤輸入的內容(數字、字母或是符號)
	char *token;	//儲存字串切割處理後內容
	int selection[255][SIZE]; //以2D array儲存下注號碼
	int lottery[SIZE+1]; //儲存中獎號碼
	int point = 0; //儲存對獎情形
	int money = 0; //儲存金額
	int k; //用來暫存
	int retry = 0; //判斷是否要重新輸入
	int counter = 0;//投注數目
	int num = 0; //每一注號碼數目
	int i,j,r,t;
	int enter;
	/*起始介紹*/
	printf("***歡迎使用大樂透對獎系統***\n\n");
	printf("Powered by E54071112黃穎俊\n\n");
	printf("###本程式使用說明###\n\n");
	printf("1.本程式在輸入號碼時,請以半型逗號隔開。\n");
	printf("2.本程式可連續輸入多筆下注號碼,每輸入一筆,請按enter儲存,並進行下一筆號碼的輸入。\n");
	printf("3.當輸入完畢後,請輸入f,即可輸入中獎號碼,並開始進行對獎;或是當您不想使用了,輸入e即可離開本程式。\n");
	printf("4.當您輸入f結束輸入後,若您發現尚有未輸入之號碼,您不必退出此程式;輸入c即可在繼續登記您下注的號碼。\n");
	printf("5.當您完成輸入後,卻發現還沒開獎,您也可以輸入e結束本程式。\n");
	printf("\n");
	/*輸入下注號碼*/
	while(r=1){ //當在執行頭獎輸入時,按"c"須返回下注號碼輸入,然後不斷重複(第3個while)
		while (1) { //此while迴圈為輸入下注號碼之條件判斷與控制(第1個while)
			printf("請輸入一注彩券號碼(共6個數字):");
	    	fgets(string,sizeof(string),stdin); //輸入內容

			if (strcmp(string,"f\n")==0){		//做字串中字符比較,若為"f"則跳出主要while迴圈,"e"則結束執行.
		        printf("輸入完畢\n");
		        break;							//strcmp為字串比較函數
		    }else if (strcmp(string,"c\n")==0){
				continue;
		    }else if (strcmp(string,"e\n")==0){
		        exit(0);
		    }
			
	    	token = strtok(string,",\n");		//將輸入字串中","去除,只留下數字、字母並儲存於token
			num = 0;
			retry = 0;
			while(token != NULL){				//判斷token內不為空的清況,若為空則不執行此while內程式
				if (isallnumber(token)==0){		//判斷是否全為數字,若否則return值為0,
		    		retry = 1;					//並且需要重新輸入(retry=1)
		    		printf("輸入格式錯誤\n");
		    		break;
		    	}
		    	selection[counter][num] = atoi(token); 	//token為字符串,用atoi函數將字符串轉為int,並儲存於整數陣列.
		    	if (selection[counter][num] <= 0 || selection[counter][num] > 49){ //判斷整數陣列中的數字是否位於範圍內
		    		printf("數字 %d 不在1-49內\n", selection[counter][num]);		  //若超出範圍,則判斷須重新輸入(retry=1),並跳脫while次迴圈
		    		retry = 1;
		    		break;
		    	}
		    	for (i=0; i < num; i++)		//若陣列數字皆在範圍內,則進一步判斷是否重複,若重複則顯示重複的數字,並跳脫for迴圈
		    	{
		    		if (selection[counter][i] == atoi(token))
		    		{
		    			retry =1;
						printf("數字重覆\n");
		    			break;
		    		}
		    	}
		    	if (retry==1){					//並且跳脫while迴圈
		    		break;
		    	}
		    	//當條件皆符合則清空token,並判斷下一個數字
		        token = strtok(NULL, ",\n");
		        num++;
			} //End while
			if (retry == 1){
	    		continue;
	    	}
	    	if (num != 6){	//判斷輸入數字數目是否滿足條件
	    		printf("數字超過6個或不到6個\n");
	    		continue;
	    	}
	  		//將陣列中數字進行BubbleSort排序
	     	for (i=0;i < SIZE;i++){
	      		for (j=i+1;j < SIZE;j++){
	      			if (selection[counter][i] > selection[counter][j]){
	          			k = selection[counter][i] ;
	          			selection[counter][i] = selection[counter][j];
	          			selection[counter][j] = k ;
	        		}
	      		}
	    	}
	    	//執行到此,完成一注號碼的儲存與輸入,counter+1進行下1注號碼儲存與輸入
	    	counter++;   	
		}
		printf("您總共輸入了%d注\n",counter);
		printf("以下是您的投注號碼\n");
		
		for (i = 0; i < counter ; i++)
		{
			printf("第%d注為: ",i+1);
			for (j = 0; j < SIZE; j++)
			{
				printf("%d ", selection[i][j]);
			}
			printf("\n");
			
		}

		/*輸入頭獎號碼*/
		printf("--------------------------------------------------------\n");
	  	while (1) {	//此while迴圈為輸入頭獎號碼之條件判斷與控制(第2個while)
	    	printf("請輸入本期大樂透開獎號碼:");
	    	fgets(string,sizeof(string),stdin); //輸入內容
	      			//將輸入字串中","去除,只留下數字、字母並儲存於token
		    if (strcmp(string,"c\n")==0){
				r=1;
				break;
		    }
		    else if (strcmp(string,"e\n")==0)
		    {
		        exit(0);
		    }
			token = strtok(string, ",\n");
	    	num=0;
	    	retry=0;
	    	while( token != NULL ) {			//判斷token內不為空的清況,若為空則不執行此while內程式
	    		if (isallnumber(token)==0){		//判斷是否全為數字,若否則return值為0,
	    		retry = 1;						//並且需要重新輸入(retry=1)
	    		printf("輸入格式錯誤\n");			//皆為數字則跳脫,接續執行下面程式
	    		break;
	    	}
	    	lottery[num] = atoi(token);			//token為字符串,用atoi函數將字符串轉為int,並儲存於整數陣列.
	    	if (lottery[num] <= 0 || lottery[num] > 49){	 //判斷整數陣列中的數字是否位於範圍內
	    		printf("數字 %d 不在1-49內\n", lottery[num]); //若超出範圍,則判斷須重新輸入(retry=1),並跳脫while主迴圈
	    		retry = 1;
	    		break;
	    	}
	    	for (i=0; i < num; i++)			//若陣列數字皆在範圍內,則進一步判斷是否重複,若重複則顯示重複的數字,並跳脫for迴圈
	    	{
	    		if (lottery[i] == atoi(token))
	    		{
	    			retry =1;
					printf("數字重覆\n");
	    			break;
	    		}
	    	}
	    	if (retry==1){
	    		break;
	    	}
	    	/*每執行完一次清除token*/	
			token = strtok(NULL, ",\n");
			/*當前述條件皆符合,儲存的數字+1*/
			num++;
	    	}
	    
		    if (retry == 1)
		    {
		    //	printf("輸入格式錯誤或數字不在1-49內或數字重覆\n");
		    	continue;
		    }
		    
		    if (num != 7){
		    	printf("數字超過7個或不到7個\n");
		    	continue;
		    }else if (num == 6){
		    	printf("請記得輸入特別號號碼");
		    	continue;
		    }else if (num == 7){
		    	printf("本期樂透頭獎中獎號碼輸入成功.\n");
		    	r=0;
		    	break;
		    }
	  	}
	  	if(r==0){
	  		break;
	  	}
	  	
	}
  	printf("本期樂透頭獎中獎號碼為: ");
  	int *sorted = selection_sort(lottery);
  	for (t = 0; t < SIZE; t++){
			printf("%d ",sorted[t]);
	}
	printf(" 特別號為:%d\n",lottery[6]);
	printf("----------------------準備就緒,開始兌獎---------------------\n");
	
	if (counter == 0)
	{
		printf("您未成功輸入號碼,無法為您對獎,程式結束.\n");
	}
	/*若是中了一般號碼,點數+1;中特別號的話,點數+10。再由所累積點數判斷獎項為何*/
	for (i = 0; i < counter; i++){
		for (j = 0; j < SIZE; j++){
			//比對是否中一般號碼
			for (k = 0; k < SIZE; k++){
				if (selection[i][j] == lottery[k]){
					point++;
				}
			}
			//比對是否中特別號
			if (selection[i][j] == lottery[6]){
				point+=10;
			}			
		}
		if (point==3){
			printf("第%d注中了普獎400元\n",i+1);
			money += 400;
		}else if (point==12){
			printf("第%d注中了柒獎400元\n",i+1);
			money += 400;
		}else if (point==13){
			printf("第%d注中了陸獎1000元\n",i+1);
			money += 1000;
		}else if (point==4){
			printf("第%d注中了伍獎2000元\n",i+1);
			money += 2000;
		}else if (point==14){
			printf("第%d注中了肆獎20000元\n",i+1);
			money += 20000;
		}else if (point==5){
			printf("第%d注中了參獎150000元\n",i+1);
			money += 150000;
		}else if (point==15){
			printf("第%d注中了貳獎5000000元\n",i+1);
			money += 5000000;
		}else if (point==6){
			printf("第%d注中了頭獎100000000元\n",i+1);
			money += 100000000;
		}else {
			printf("第%d注未中獎.\n",i+1);
			money += 0;
		}
		point = 0; //每注對獎後將點數歸0,避免點數持續累積
	}
	printf("總中獎金額為:%d元\n",money);
	printf("-------------程式結束.-----------------------\n");						

}
/*判斷是否全為數字的函數*/
int isallnumber(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) 
    {
        if (!isdigit(str[i]))	//利用isdigit判斷陣列中內容是否為數字
            return 0;
         
    }
    
    return 1;
}
/*交換*/
void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b= temp;
}
/*SelectionSort的實現*/
int * selection_sort(int *list){
  int i, j, min_id;
  for(i = 0; i < SIZE-1; i++){
    min_id = i;
    for(j=i+1; j < SIZE; j++){
      if (list[j] < list[min_id])
        min_id = j;
    }
    swap(&list[i], &list[min_id]); //送地址過去swap function
  }
  return list;
}