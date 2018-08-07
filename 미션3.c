#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

#define black 0 // ���� ���� (��ũ��) 
#define blue 1
#define green 2
#define blue_green 3
#define red 4
#define purple 5
#define yellow 6
#define white 7
#define color_bright 8
typedef struct { // ���� ����� ����ü 
	char *date;
	char * clock;
	int  important_level;
	int  group;
	char * title;
	char * content;
} Plan;

int n=0,num = 8,location_cursor=1; // �⺻ ���� ���� ���� ���ϱ� 

int keyboard_input(); // Ű���� ó�� �ޱ� 
void SetColor(int color, int bgcolor); // ���� ���� ��� ���� �����Ѵ�. 
void gotoxy(int x, int y); // Ŀ���� ��ġ�� �̵���Ų��.
void CursorView(char show); //Ŀ������� 
void put_cursor(int x); // �����ִ� ( Ư������ )  Ŀ���� ��ġ ���� �� �߸��� Ű���� �Է½� �۵� 

int main(void) {
 	int i;
 	Plan * arr = (Plan *) malloc(sizeof(Plan) * num); // ���� ���� ����ü ���� 
	Plan * group0 = (Plan *) malloc(sizeof(Plan) * num); int group0_n = 0;
	Plan * group1 = (Plan *) malloc(sizeof(Plan) * num); int group1_n = 0;
	Plan * group2 = (Plan *) malloc(sizeof(Plan) * num); int group2_n = 0;
	Plan * group3 = (Plan *) malloc(sizeof(Plan) * num); int group3_n = 0;
	Plan * group4 = (Plan *) malloc(sizeof(Plan) * num); int group4_n = 0;
 	 	
 	CursorView(0);
 	FILE * read1 = fopen("input.txt", "r"); // ���ϰ��� ��Ʈ�� ���� 	
	n = 0;
	char buf[1000]; // ������ ������ �ľ��ϱ� ���� ����
	while(fgets(buf, 1000, read1) != NULL) {
		n++;
	}
	
	while(n > num){ // ���� ������ �Ҵ�� ũ�⺸�� ū ��� 
	
		num *= 2; // ���� ���� ���� 2��� ���ϱ� 
		arr = (Plan *)realloc(arr,sizeof(Plan ) * num); // ũ�� ���Ҵ��ϱ� 
		group0 = (Plan *)realloc(group0,sizeof(Plan ) * num); // ũ�� ���Ҵ��ϱ� 
		group1 = (Plan *)realloc(group1,sizeof(Plan ) * num); // ũ�� ���Ҵ��ϱ� 
		group2 = (Plan *)realloc(group2,sizeof(Plan ) * num); // ũ�� ���Ҵ��ϱ� 
		group3 = (Plan *)realloc(group3,sizeof(Plan ) * num); // ũ�� ���Ҵ��ϱ� 
		group4 = (Plan *)realloc(group4,sizeof(Plan ) * num); // ũ�� ���Ҵ��ϱ� 
	}
	 
	fclose(read1); // read1 ���� (���� �д� ��ġ �ʱ�ȭ�� ����)	

	FILE * read2 = fopen("input.txt", "r"); // read2 ����  (���� �д� ��ġ �ʱ�ȭ�� ����)
	for(i=0;i<n;i++){
		arr[i].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
		arr[i].clock = (char *) malloc(sizeof(char) * 10);
		arr[i].title = (char *) malloc(sizeof(char) * 300);
		arr[i].content = (char *) malloc(sizeof(char) * 300);
		fscanf(read2,"%s %s %d %d %s %s",arr[i].date,arr[i].clock,&arr[i].important_level,&arr[i].group,arr[i].title,arr[i].content); // �Է� �ޱ� 
	}
	fclose(read2); // read2 ���� (���� �д� ��ġ �ʱ�ȭ�� ����) 
	
	for(i=0;i<n;i++){
		char tmp_date[10],tmp_clock[5];
		strcpy(tmp_date,arr[i].date); // ���� ��¥, �ð��� ���� �Ͽ� �ӽ� �迭�� ���� 
		strcpy(tmp_clock,arr[i].clock); 
		arr[i].date[4] = '.';  // ��� �� ���� 
		arr[i].date[5] = tmp_date[4];
		arr[i].date[6] = tmp_date[5];
		arr[i].date[7] = '.';
		arr[i].date[8] = tmp_date[6];
		arr[i].date[9] = tmp_date[7];
		arr[i].date[10] = '.';
		arr[i].date[11] = 0;
		arr[i].clock[2]= ':';
		arr[i].clock[3] = tmp_clock[2];
		arr[i].clock[4] = tmp_clock[3];
		arr[i].clock[5] = 0;
	}
	
	for(i=0;i<n;i++){
	
		switch(arr[i].group){
			case 0:
				group0[i].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
				group0[i].clock = (char *) malloc(sizeof(char) * 10);
				group0[i].title = (char *) malloc(sizeof(char) * 300);
				group0[i].content = (char *) malloc(sizeof(char) * 300);
				strcpy(group0[i].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
				strcpy(group0[i].clock, arr[i].clock);
				strcpy(group0[i].title, arr[i].title);
				strcpy(group0[i].content, arr[i].content);
				group0[i].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
				group0[i].group = arr[i].group;
				group0_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
				break;		
			
			case 1:
				group1[group1_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
				group1[group1_n].clock = (char *) malloc(sizeof(char) * 10);
				group1[group1_n].title = (char *) malloc(sizeof(char) * 300);
				group1[group1_n].content = (char *) malloc(sizeof(char) * 300);
				strcpy(group1[group1_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
				strcpy(group1[group1_n].clock, arr[i].clock);
				strcpy(group1[group1_n].title, arr[i].title);
				strcpy(group1[group1_n].content, arr[i].content);
				group1[group1_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
				group1[group1_n].group = arr[i].group;
				group1_n++; // �׷��� ���� ������ 1�� ���Ѵ�.
				break;
					
			case 2:
				group2[group2_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
				group2[group2_n].clock = (char *) malloc(sizeof(char) * 10);
				group2[group2_n].title = (char *) malloc(sizeof(char) * 300);
				group2[group2_n].content = (char *) malloc(sizeof(char) * 300);
				strcpy(group2[group2_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
				strcpy(group2[group2_n].clock, arr[i].clock);
				strcpy(group2[group2_n].title, arr[i].title);
				strcpy(group2[group2_n].content, arr[i].content);
				group2[group2_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ� 
				group2[group2_n].group = arr[i].group;
				group2_n++; // �׷��� ���� ������ 1�� ���Ѵ�.
				break;	
				
			case 3:
				group3[group3_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
				group3[group3_n].clock = (char *) malloc(sizeof(char) * 10);
				group3[group3_n].title = (char *) malloc(sizeof(char) * 300);
				group3[group3_n].content = (char *) malloc(sizeof(char) * 300);
				strcpy(group3[group3_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
				strcpy(group3[group3_n].clock, arr[i].clock);
				strcpy(group3[group3_n].title, arr[i].title);
				strcpy(group3[group3_n].content, arr[i].content);
				group3[group3_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
				group3[group3_n].group = arr[i].group;
				group3_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;	
				
			case 4:
				group4[group4_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
				group4[group4_n].clock = (char *) malloc(sizeof(char) * 10);
				group4[group4_n].title = (char *) malloc(sizeof(char) * 300);
				group4[group4_n].content = (char *) malloc(sizeof(char) * 300);
				strcpy(group4[group4_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
				strcpy(group4[group4_n].clock, arr[i].clock);
				strcpy(group4[group4_n].title, arr[i].title);
				strcpy(group4[group4_n].content, arr[i].content);
				group4[group4_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
				group4[group4_n].group = arr[i].group;
				group4_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
				break;	
		}
		
	}

		printf("��ġ |    ��¥     |  �ð� | �߿䵵|  �׷�� |     ���� &  ���� \n");
		
			for(i=0;i<n;i++){
				if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
				switch(arr[i].group){
					case 0:
						printf("     | %s | %s | %d��° | ����(0) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;
					 
					case 1:
						printf("     | %s | %s | %d��° | ���(1) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break; 
					
					case 2:
						printf("     | %s | %s | %d���� | ���(2) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 3:
						printf("     | %s | %s | %d���� | �޽�(3) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 4:
						printf("     | %s | %s | %d��° | ����(4) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	 
				}
				SetColor(white,black);
		}
	put_cursor(1);
	
	while(1){
		put_cursor(1);
		system("cls");
			printf("��ġ |    ��¥     |  �ð� | �߿䵵|  �׷�� |     ���� &  ���� \n");
		
			for(i=0;i<n;i++){
				if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
				switch(arr[i].group){
					case 0:
						printf("     | %s | %s | %d��° | ����(0) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;
					 
					case 1:
						printf("     | %s | %s | %d��° | ���(1) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break; 
					
					case 2:
						printf("     | %s | %s | %d���� | ���(2) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 3:
						printf("     | %s | %s | %d���� | �޽�(3) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 4:
						printf("     | %s | %s | %d��° | ����(4) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	 
				}
				SetColor(white,black);
		}
		put_cursor(1);
		int input = keyboard_input(); // Ű���� �Է�! 
		if(input == 1){
			if(location_cursor > 1){
				put_cursor(-1);
				location_cursor--;
				put_cursor(1);
			}
		}
		else if (input == -1){
			if(location_cursor < n){
				put_cursor(-1);
				location_cursor++;
				put_cursor(1);
			}
		}
		else if (input == 0){
			system("cls");
			switch(arr[location_cursor-1].group){
				case 0:
					printf("%d��° ����\n�Ͻ�(��¥) : %s \n�Ͻ�(�ð�) :  %s \n�߿䵵 : %d��°\n �׷� :  ����(0) \n���� : %s \n���� : %s\n",location_cursor,arr[location_cursor-1].date,arr[location_cursor-1].clock,arr[location_cursor-1].important_level,arr[location_cursor-1].title,arr[location_cursor-1].content); // ��� ��� 
					break;
					 
				case 1:
					printf("%d��° ����\n�Ͻ�(��¥) : %s \n�Ͻ�(�ð�) :  %s \n�߿䵵 : %d��°\n �׷� :  ���(1) \n���� : %s \n���� : %s\n",location_cursor,arr[location_cursor-1].date,arr[location_cursor-1].clock,arr[location_cursor-1].important_level,arr[location_cursor-1].title,arr[location_cursor-1].content); // ��� ���
					break; 
					
				case 2:
					printf("%d��° ����\n�Ͻ�(��¥) : %s \n�Ͻ�(�ð�) :  %s \n�߿䵵 : %d��°\n �׷� :  ���(2) \n���� : %s \n���� : %s\n",location_cursor,arr[location_cursor-1].date,arr[location_cursor-1].clock,arr[location_cursor-1].important_level,arr[location_cursor-1].title,arr[location_cursor-1].content); // ��� ���
					break;
					
				case 3:
					printf("%d��° ����\n�Ͻ�(��¥) : %s \n�Ͻ�(�ð�) :  %s \n�߿䵵 : %d��°\n �׷� :  �޽�(3) \n���� : %s \n���� : %s\n",location_cursor,arr[location_cursor-1].date,arr[location_cursor-1].clock,arr[location_cursor-1].important_level,arr[location_cursor-1].title,arr[location_cursor-1].content); // ��� ���
					break;
					
				case 4:
					printf("%d��° ����\n�Ͻ�(��¥) : %s \n�Ͻ�(�ð�) :  %s \n�߿䵵 : %d��°\n �׷� :  ����(4) \n���� : %s \n���� : %s\n",location_cursor,arr[location_cursor-1].date,arr[location_cursor-1].clock,arr[location_cursor-1].important_level,arr[location_cursor-1].title,arr[location_cursor-1].content); // ��� ���
					break;
				}
				while(1){
					int input = keyboard_input();
					if(input == -2) break;
				}
				system("cls");
				printf("��ġ |    ��¥     |  �ð� | �߿䵵|  �׷�� |     ���� &  ���� \n");
				for(i=0;i<n;i++){
				if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
				switch(arr[i].group){
					case 0:
						printf("     | %s | %s | %d��° | ����(0) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;
					 
					case 1:
						printf("     | %s | %s | %d��° | ���(1) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break; 
					
					case 2:
						printf("     | %s | %s | %d���� | ���(2) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 3:
						printf("     | %s | %s | %d���� | �޽�(3) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 4:
						printf("     | %s | %s | %d��° | ����(4) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ���
					
					SetColor(white,black); 	 
				}		 
			}
			
			
		}
		else if(input == 2){
			
			char tmp[50];
			system("cls");
			if(n+1 >= num){ // ���� ������ �Ҵ�� ũ�⺸�� ū ��� 
			num *= 2; // ���� ���� ���� 2��� ���ϱ� 
			arr = (Plan *)realloc(arr,sizeof(char *) * num); // ũ�� ���Ҵ��ϱ� 
			group0 = (Plan *)realloc(group0,sizeof(char *) * num); // ũ�� ���Ҵ��ϱ� 
			group1 = (Plan *)realloc(group1,sizeof(char *) * num); // ũ�� ���Ҵ��ϱ� 
			group2 = (Plan *)realloc(group2,sizeof(char *) * num); // ũ�� ���Ҵ��ϱ� 
			group3 = (Plan *)realloc(group3,sizeof(char *) * num); // ũ�� ���Ҵ��ϱ� 
			group4 = (Plan *)realloc(group4,sizeof(char *) * num); // ũ�� ���Ҵ��ϱ� 
			}
			
			arr[n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
			arr[n].clock = (char *) malloc(sizeof(char) * 10);
			arr[n].title = (char *) malloc(sizeof(char) * 300);
			arr[n].content = (char *) malloc(sizeof(char) * 300);
			printf("������ �߰��մϴ�.\n");
			printf("��¥�� �Է��ϼ���. �Է� : ");
			scanf("%s",arr[n].date);
			printf("�ð��� �Է��ϼ���. �Է� : ");
			scanf("%s",arr[n].clock);
			printf("�߿䵵�� �Է��ϼ���. �Է� : "); 
			scanf("%d",&arr[n].important_level);
			printf("�׷���� �Է��ϼ���. �Է� : ");
			scanf("%s",tmp);
			if(!strcmp(tmp,"����")) arr[n].group=0; 
			if(!strcmp(tmp,"���")) arr[n].group=1; 
			if(!strcmp(tmp,"���")) arr[n].group=2; 
			if(!strcmp(tmp,"�޽�")) arr[n].group=3; 
			if(!strcmp(tmp,"����")) arr[n].group=4; 
			printf("������ ������ �Է��ϼ���. �Է� : "); 
			scanf("%s",arr[n].title);
			printf("������ ������ �Է��ϼ���. �Է� : "); 
			scanf("%s",arr[n].content);
			FILE * write1 = fopen("input.txt", "a"); // write1 ����  (���� �д� ��ġ �ʱ�ȭ�� ����) 
			fprintf(write1, "\n%s %s %d %d %s %s",arr[n].date,arr[n].clock,arr[n].important_level,arr[n].group,arr[n].title,arr[n].content);
			fclose(write1);
			printf("abc"); 
			char tmp_date[10],tmp_clock[5];
			strcpy(tmp_date,arr[n].date); // ���� ��¥, �ð��� ���� �Ͽ� �ӽ� �迭�� ���� 
			strcpy(tmp_clock,arr[n].clock); 
			arr[n].date[4] = '.';  // ��� �� ���� 
		arr[n].date[5] = tmp_date[4];
		arr[n].date[6] = tmp_date[5];
		arr[n].date[7] = '.';
		arr[n].date[8] = tmp_date[6];
		arr[n].date[9] = tmp_date[7];
		arr[n].date[10] = '.';
		arr[n].date[11] = 0;
		arr[n].clock[2]= ':';
		arr[n].clock[3] = tmp_clock[2];
		arr[n].clock[4] = tmp_clock[3];
		arr[n].clock[5] = 0;
		
		n++;
			system("cls");
			printf("��ġ |    ��¥     |  �ð� | �߿䵵|  �׷�� |     ���� &  ���� \n");
			 
				for(i=0;i<n;i++){
					if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
				switch(arr[i].group){
					case 0:
						printf("     | %s | %s | %d��° | ����(0) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;
					 
					case 1:
						printf("     | %s | %s | %d��° | ���(1) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break; 
					
					case 2:
						printf("     | %s | %s | %d���� | ���(2) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 3:
						printf("     | %s | %s | %d���� | �޽�(3) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 4:
						printf("     | %s | %s | %d��° | ����(4) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;	 
				}
				
				SetColor(white,black);
			}
		}
		else if (input == 3){
			
			system("cls");
			char tmp[300],tmp_date[10],tmp_clock[5];
			printf("���� ������ �����ϼ̽��ϴ�. ���� ���� �����մϴ�. (�����ϰ� ���� �����ôٸ� �������� �νʽÿ�!)\n");
			printf("�����Ͻ� ������ ��¥�� �Է��� �ֽʽÿ�. �Է� : ");
			tmp_date[1] = 120;
			gets(tmp_date);
			
			printf("�����Ͻ� ������ �ð��� �Է��� �ֽʽÿ�. �Է� : ");
			tmp_clock[1] = 120;
			gets(tmp_clock);
			
			printf("�����Ͻ� ������ �߿䵵�� �Է��� �ֽʽÿ�. �Է� : ");
			tmp[1] = 120;
			gets(tmp);
			if(tmp[1] != 120)  arr[location_cursor-1].important_level = atoi(tmp);
			
			printf("�׷���� �Է��ϼ���. �Է� : ");
			tmp[1] = 120;
			gets(tmp);
			if(tmp[1] != 120){
				if(!strcmp(tmp,"����")) arr[location_cursor-1].group=0; 
				if(!strcmp(tmp,"���")) arr[location_cursor-1].group=1; 
				if(!strcmp(tmp,"���")) arr[location_cursor-1].group=2; 
				if(!strcmp(tmp,"�޽�")) arr[location_cursor-1].group=3; 
				if(!strcmp(tmp,"����")) arr[location_cursor-1].group=4; 
			}
			
			printf("�����Ͻ� ������ ������ �Է��� �ֽʽÿ�. �Է� : ");
			tmp[1] = 120;
			gets(tmp);
			if(tmp[1] != 120){
				strcpy(arr[location_cursor-1].title,tmp);
			} 
			
			printf("�����Ͻ� ������ ������ �Է��� �ֽʽÿ�. �Է� : ");
			tmp[1] = 120;
			gets(tmp);
			if(tmp[1] != 120){
				strcpy(arr[location_cursor-1].content,tmp);
			} 
			
			if(tmp_date[1] != 120){
				arr[location_cursor-1].date[4] = '.';  // ��� �� ���� 
				arr[location_cursor-1].date[5] = tmp_date[4];
				arr[location_cursor-1].date[6] = tmp_date[5];
				arr[location_cursor-1].date[7] = '.';
				arr[location_cursor-1].date[8] = tmp_date[6];
				arr[location_cursor-1].date[9] = tmp_date[7];
				arr[location_cursor-1].date[10] = '.';
				arr[location_cursor-1].date[11] = 0;
			}
			
			if(tmp_clock[1] != 120){
				arr[location_cursor-1].clock[2]= ':';
				arr[location_cursor-1].clock[3] = tmp_clock[2];
				arr[location_cursor-1].clock[4] = tmp_clock[3];
				arr[location_cursor-1].clock[5] = 0;
			}
			
			FILE * write2 = fopen("input.txt", "w"); // write2 ����  (���� �д� ��ġ �ʱ�ȭ�� ����) 
			i = 0; // arr���� ���� .,:�� �� ���� �־ �ϳ���(��¥, �ð�) 
			fprintf(write2, "%c%c%c%c%c%c%c%c %c%c%c%c %d %d %s %s",arr[i].date[0],arr[i].date[1],arr[i].date[2],arr[i].date[3],arr[i].date[5],arr[i].date[6],arr[i].date[8],arr[i].date[9],arr[i].clock[0],arr[i].clock[1],arr[i].clock[3],arr[i].clock[4],arr[i].important_level,arr[i].group,arr[i].title,arr[i].content);
			for(i=1;i<n;i++) {
				fprintf(write2, "\n%c%c%c%c%c%c%c%c %c%c%c%c %d %d %s %s",arr[i].date[0],arr[i].date[1],arr[i].date[2],arr[i].date[3],arr[i].date[5],arr[i].date[6],arr[i].date[8],arr[i].date[9],arr[i].clock[0],arr[i].clock[1],arr[i].clock[3],arr[i].clock[4],arr[i].important_level,arr[i].group,arr[i].title,arr[i].content);
			}
			fclose(write2); // ���� �� ���� ����! 
		
		free(group1);
		free(group2);
		free(group3);
		free(group4);
		free(group0);
	
		Plan * group0 = (Plan *) malloc(sizeof(Plan) * num);  group0_n = 0; // �� �ݰ� ���Ӱ� �ٽ� ���� �ž�! 
		Plan * group1 = (Plan *) malloc(sizeof(Plan) * num);  group1_n = 0;
		Plan * group2 = (Plan *) malloc(sizeof(Plan) * num); group2_n = 0;
		Plan * group3 = (Plan *) malloc(sizeof(Plan) * num); group3_n = 0;
		Plan * group4 = (Plan *) malloc(sizeof(Plan) * num); group4_n = 0;
		for(i=0;i<n;i++){
	
			switch(arr[i].group){
				case 0:
					group0[i].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group0[i].clock = (char *) malloc(sizeof(char) * 10);
					group0[i].title = (char *) malloc(sizeof(char) * 300);
					group0[i].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group0[i].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group0[i].clock, arr[i].clock);
					strcpy(group0[i].title, arr[i].title);
					strcpy(group0[i].content, arr[i].content);
					group0[i].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group0[i].group = arr[i].group;
					group0_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;		
			
				case 1:
					group1[group1_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group1[group1_n].clock = (char *) malloc(sizeof(char) * 10);
					group1[group1_n].title = (char *) malloc(sizeof(char) * 300);
					group1[group1_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group1[group1_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group1[group1_n].clock, arr[i].clock);
					strcpy(group1[group1_n].title, arr[i].title);
					strcpy(group1[group1_n].content, arr[i].content);
					group1[group1_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group1[group1_n].group = arr[i].group;
					group1_n++; // �׷��� ���� ������ 1�� ���Ѵ�.
					break;
					
				case 2:
					group2[group2_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group2[group2_n].clock = (char *) malloc(sizeof(char) * 10);
					group2[group2_n].title = (char *) malloc(sizeof(char) * 300);
					group2[group2_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group2[group2_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group2[group2_n].clock, arr[i].clock);
					strcpy(group2[group2_n].title, arr[i].title);
					strcpy(group2[group2_n].content, arr[i].content);
					group2[group2_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ� 
					group2[group2_n].group = arr[i].group;
					group2_n++; // �׷��� ���� ������ 1�� ���Ѵ�.
					break;	
				
				case 3:
					group3[group3_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group3[group3_n].clock = (char *) malloc(sizeof(char) * 10);
					group3[group3_n].title = (char *) malloc(sizeof(char) * 300);
					group3[group3_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group3[group3_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group3[group3_n].clock, arr[i].clock);
					strcpy(group3[group3_n].title, arr[i].title);
					strcpy(group3[group3_n].content, arr[i].content);
					group3[group3_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group3[group3_n].group = arr[i].group;
					group3_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;	
				
				case 4:
					group4[group4_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group4[group4_n].clock = (char *) malloc(sizeof(char) * 10);
					group4[group4_n].title = (char *) malloc(sizeof(char) * 300);
					group4[group4_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group4[group4_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group4[group4_n].clock, arr[i].clock);
					strcpy(group4[group4_n].title, arr[i].title);
					strcpy(group4[group4_n].content, arr[i].content);
					group4[group4_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group4[group4_n].group = arr[i].group;
					group4_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;	
			}
		
	}
			system("cls");
			
			printf("��ġ |    ��¥     |  �ð� | �߿䵵|  �׷�� |     ���� &  ���� \n");
			for(i=0;i<n;i++){
				if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
				
				switch(arr[i].group){
					case 0:
						printf("     | %s | %s | %d��° | ����(0) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;
					 
					case 1:
						printf("     | %s | %s | %d��° | ���(1) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break; 
					
					case 2:
						printf("     | %s | %s | %d���� | ���(2) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 3:
						printf("     | %s | %s | %d���� | �޽�(3) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 4:
						printf("     | %s | %s | %d��° | ����(4) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;	 
				}
				SetColor(white,black);
			}
			 
		}
		
		if(input == -3){
			int now_delete = location_cursor-1;
			if( n == location_cursor ) location_cursor--;
			for(i=now_delete + 1;i<n;i++){
				strcpy(arr[i-1].date,arr[i].date);
				strcpy(arr[i-1].clock,arr[i].clock);
				arr[i-1].important_level = arr[i].important_level;
				arr[i-1].group = arr[i].group;
				strcpy(arr[i-1].title,arr[i].title);
				strcpy(arr[i-1].content,arr[i].content);
			}
			
				FILE * write2 = fopen("input.txt", "w"); // write2 ����  (���� �д� ��ġ �ʱ�ȭ�� ����) 
			i = 0; // arr���� ���� .,:�� �� ���� �־ �ϳ���(��¥, �ð�) 
			fprintf(write2, "%c%c%c%c%c%c%c%c %c%c%c%c %d %d %s %s",arr[i].date[0],arr[i].date[1],arr[i].date[2],arr[i].date[3],arr[i].date[5],arr[i].date[6],arr[i].date[8],arr[i].date[9],arr[i].clock[0],arr[i].clock[1],arr[i].clock[3],arr[i].clock[4],arr[i].important_level,arr[i].group,arr[i].title,arr[i].content);
			for(i=1;i<n;i++) {
				fprintf(write2, "\n%c%c%c%c%c%c%c%c %c%c%c%c %d %d %s %s",arr[i].date[0],arr[i].date[1],arr[i].date[2],arr[i].date[3],arr[i].date[5],arr[i].date[6],arr[i].date[8],arr[i].date[9],arr[i].clock[0],arr[i].clock[1],arr[i].clock[3],arr[i].clock[4],arr[i].important_level,arr[i].group,arr[i].title,arr[i].content);
			}
			fclose(write2); // ���� �� ���� ����! 
		
		free(group1);
		free(group2);
		free(group3);
		free(group4);
		free(group0);
	
		Plan * group0 = (Plan *) malloc(sizeof(Plan) * num);  group0_n = 0; // �� �ݰ� ���Ӱ� �ٽ� ���� �ž�! 
		Plan * group1 = (Plan *) malloc(sizeof(Plan) * num);  group1_n = 0;
		Plan * group2 = (Plan *) malloc(sizeof(Plan) * num); group2_n = 0;
		Plan * group3 = (Plan *) malloc(sizeof(Plan) * num); group3_n = 0;
		Plan * group4 = (Plan *) malloc(sizeof(Plan) * num); group4_n = 0;
		for(i=0;i<n;i++){
			if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
			switch(arr[i].group){
				case 0:
					group0[i].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group0[i].clock = (char *) malloc(sizeof(char) * 10);
					group0[i].title = (char *) malloc(sizeof(char) * 300);
					group0[i].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group0[i].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group0[i].clock, arr[i].clock);
					strcpy(group0[i].title, arr[i].title);
					strcpy(group0[i].content, arr[i].content);
					group0[i].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group0[i].group = arr[i].group;
					group0_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;		
			
				case 1:
					group1[group1_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group1[group1_n].clock = (char *) malloc(sizeof(char) * 10);
					group1[group1_n].title = (char *) malloc(sizeof(char) * 300);
					group1[group1_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group1[group1_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group1[group1_n].clock, arr[i].clock);
					strcpy(group1[group1_n].title, arr[i].title);
					strcpy(group1[group1_n].content, arr[i].content);
					group1[group1_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group1[group1_n].group = arr[i].group;
					group1_n++; // �׷��� ���� ������ 1�� ���Ѵ�.
					break;
					
				case 2:
					group2[group2_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group2[group2_n].clock = (char *) malloc(sizeof(char) * 10);
					group2[group2_n].title = (char *) malloc(sizeof(char) * 300);
					group2[group2_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group2[group2_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group2[group2_n].clock, arr[i].clock);
					strcpy(group2[group2_n].title, arr[i].title);
					strcpy(group2[group2_n].content, arr[i].content);
					group2[group2_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ� 
					group2[group2_n].group = arr[i].group;
					group2_n++; // �׷��� ���� ������ 1�� ���Ѵ�.
					break;	
				
				case 3:
					group3[group3_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group3[group3_n].clock = (char *) malloc(sizeof(char) * 10);
					group3[group3_n].title = (char *) malloc(sizeof(char) * 300);
					group3[group3_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group3[group3_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group3[group3_n].clock, arr[i].clock);
					strcpy(group3[group3_n].title, arr[i].title);
					strcpy(group3[group3_n].content, arr[i].content);
					group3[group3_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group3[group3_n].group = arr[i].group;
					group3_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;	
				
				case 4:
					group4[group4_n].date = (char *) malloc(sizeof(char) * 13); // ���� �迭�� �޸� �Ҵ� 
					group4[group4_n].clock = (char *) malloc(sizeof(char) * 10);
					group4[group4_n].title = (char *) malloc(sizeof(char) * 300);
					group4[group4_n].content = (char *) malloc(sizeof(char) * 300);
					strcpy(group4[group4_n].date, arr[i].date); // ��� ���ڿ��� �����Ѵ�
					strcpy(group4[group4_n].clock, arr[i].clock);
					strcpy(group4[group4_n].title, arr[i].title);
					strcpy(group4[group4_n].content, arr[i].content);
					group4[group4_n].important_level = arr[i].important_level; // ��� ���� �����Ѵ�
					group4[group4_n].group = arr[i].group;
					group4_n++; // �׷��� ���� ������ 1�� ���Ѵ�. 
					break;	
			}
			SetColor(white,black);
	}
			system("cls");
			n--;
			printf("��ġ |    ��¥     |  �ð� | �߿䵵|  �׷�� |     ���� &  ���� \n");
			for(i=0;i<n;i++){
				if( location_cursor-1 == i ) SetColor(red,blue + color_bright);
				switch(arr[i].group){
					case 0:
						printf("     | %s | %s | %d��° | ����(0) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;
					 
					case 1:
						printf("     | %s | %s | %d��° | ���(1) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break; 
					
					case 2:
						printf("     | %s | %s | %d���� | ���(2) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 3:
						printf("     | %s | %s | %d���� | �޽�(3) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 	
						break;
					
					case 4:
						printf("     | %s | %s | %d��° | ����(4) | %s | %s |\n",arr[i].date,arr[i].clock,arr[i].important_level,arr[i].title,arr[i].content); // ��� ��� 
						break;	 
				}
				SetColor(white,black);
			}
		}
		else if(input == -10){
			put_cursor(-10);
			printf("��� ���� Ű�� | '�����̽�' | '���� ȭ��ǥ Ű' | '�Ʒ��� ȭ��ǥ Ű' | 'e','i','d' Ű |�Դϴ�." );
			Sleep(1500);
			put_cursor(-10);
			printf("                                                                                                    ");
		}
		
	}
      for(i=0;i<n;i++){ //�޸� ������ �����Ѵ�. 
		free(arr[i].date);
		free(arr[i].clock);
		free(arr[i].content);
		free(arr[i].title);
	}
	
	free(arr); //�޸� ����
	free(group1);
	free(group2);
	free(group3);
	free(group4);
	free(group0);
	return 0;
}

int keyboard_input(){ // Ű���� ó�� �ޱ� 
	int key = getch(); // ȭ��ǥ�� 1����Ʈ �ޱ� - ����Ű�� �̰��� 224�� ����. 
    if(key == 224) // ȭ��ǥ�� 2����Ʈ Ȯ�� �ڵ��̴�.  
	{
    	key = getch(); // ȭ��ǥ�� �״��� 1 ����Ʈ �ޱ� - �������� ������ �����ȴ�. 

    	switch(key)
   		{
        	case 72: // ���� ȭ��ǥ Ű�� ������ �� 
            	return 1; // 1 ��ȯ 
            	break;
        	case 80: // �Ʒ��� ȭ��ǥ Ű�� ������ �� 
            	return -1; // -1 ��ȯ 
            	break;
        	default: // �� Ű ��� �ش���� ���� ��� 
        		return -10;  // -10 (�����ڰ� ���Ƿ� ���� �� �Լ��� '���� ��') ��ȯ 
            	break;
    	}
	}
	else if (key == 32) return 0; // �����̽� Ű�� ������ ��
	else if (key == 'i') return 2; 
	else if (key == 'q') return -2; 
	else if (key == 'e') return 3;
	else if (key == 'd') return -3;
	else return -10; // -10 (�����ڰ� ���Ƿ� ���� �� �Լ��� '���� ��') ��ȯ 
}

void put_cursor(int x){
	if(x == 1){ // �Է� 
		SetColor(red,blue + color_bright); 
		gotoxy(2,location_cursor); // ��ġ �̵� 
		printf("��");// ȭ��ǥ �Է� 
		SetColor(white,black);
	}
	else if(x == -1){ // ���� 
		SetColor(white,black);
		gotoxy(2,location_cursor); // ��ġ �̵� 
		printf("  "); // ȭ��ǥ ����
	}
	
	else if (x == -10){
		gotoxy(0,n+1);
	}
	

}

/* ���⿡ �ִ� ������ WINDOWS API�� �ִ� �������� windows �ü�������� ��� �����ϰ� �˴ϴ�. - ���� */
 
void SetColor(int text, int bgcolor) // ���� ���� ��� ���� �����Ѵ�. 
{
	int color= (bgcolor << 4) | text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y) // Ŀ���� ��ġ�� �̵���Ų��. 
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void CursorView(char show) //Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

/* -��- */ 
