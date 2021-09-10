#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char *ID;
	char *name;
	char *birthday;
	char *hometown;
	float DTBTL;
	int DRL;
}student;

int countLine(FILE* sourc); //dem dong
void getInfo(student *SV, int numOfStudent, int n); // nhap thong tin vao file
void delSpace(char str[]);  // xoa dau cach, viet hoa dau cau
void readInfo(FILE* sourc, student *SV, int n);  // doc thong tin len mang
void printSta(); // print thanh thong tin
void printInfo(student *SV, int i);  // print thong tin
void sortByDTBTL(student *SV, int n); // sap xep theo DTBTK
void sortByDRL(student *SV, int n);  // sap xep theo DRL
void sortByID(student *SV, int n);  // sap xep theo MSSV
void sortByName(student *SV, int n);
void swapInfo(student *SV, int i, int j);  // Ham doi cho 2 sinh vien
void updateFile(FILE* sourc, student *SV, int n);  // cap nhat thong tin len file
void removeInfo(student *SV, int i, int n); // xoa thong tin SV
void nameSepara(student *SV, int n, char name[]);

int main(){
	int conti = 1, choose, numOfStudent, n, max, i, j;
	char find[15];
	FILE *sourc = NULL;
	
	student *SV;
	numOfStudent = countLine(sourc);
	SV = (student*)malloc(sizeof(student) * numOfStudent);

	readInfo(sourc, SV, numOfStudent);

	while(conti != 0){
		printf("\n\n\
					STUDENT INFORMATION:\n\n\
					1. Print all infomation \n\n\
					2. Search by...\n\n\
					3. Sort by...\n\n\
					4. ADD more Student Information\n\n\
					5. REMOVE an Student information\n\n\n\n\
					0. EXIT\n\n");
		printf("\n\
					Choose an option: ");
		scanf("%d", &choose);
		
		switch(choose){		
		case 1: //printf all
			system("cls");
			printf("1. Print All Information: \n\n");
			sortByID(SV, numOfStudent);
			printSta();
			for(i = 0; i < numOfStudent; i++){
				printInfo(SV, i);
			}
			
			//Highest DTBTL
			printf("\nThe highest DTBTL: \n");
			for( i = 0, max = 0; i < numOfStudent; i++){
				if(SV[i]. DTBTL > max){
					max = SV[i]. DTBTL;
				}
			}
			for( i = 0; i < numOfStudent; i++){
				if(SV[i]. DTBTL == max)
					printInfo(SV, i);
			}
			//Highest DRL
			printf("\nThe highest DRL: \n");
			for( i = 0, max = 0; i < numOfStudent; i++){
				if(SV[i]. DRL > max){
					max = SV[i]. DRL;
				}
			}
			for( i = 0; i < numOfStudent; i++){
				if(SV[i]. DRL == max)
					printInfo(SV, i);
			}
			
			break;
			
		case 2://Search by....
			system("cls");
			printf("\n\n\
					1. Search in other\n\n\
					2. Search by Student ID\n\n");
			printf("\n\
					Choose an option: ");
			scanf("%d", &choose);
		
			switch(choose){
				case 1:	//Search in other
					system("cls");
					
					printf("\n\nWhat number student you want to find: ");
					scanf("%d", &j);
					i = j - 1;
					system("cls");
					printf("1. Search in other\n\n");
					printf("Student %d:\n", j);
					printSta();
					printInfo(SV, i);
					break;
					
				case 2:	//search by ID
					system("cls");
				
					printf("\nWhat student ID you want to find: ");
					fflush(stdin);
					gets(find);
					system("cls");
					printf("2. Search by ID:\n\n");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						if(stricmp(find, SV[i].ID) == 0 ){
							printInfo(SV, i);
						}	
					}
					break;
			}
			break;
		
		case 3:// Sort by...
			system("cls");
			printf("\n\n\
					1. Sort by DTBTL\n\n\
					2. Sort by DRL\n\n\
					3. Sort by Student ID\n\n\
					4. Sort by Name\n\n");
			printf("\n\
					Choose an option: ");
			scanf("%d", &choose);
			
			switch(choose){
				case 1:
					system("cls");
				
					sortByDTBTL(SV, numOfStudent);
					printf("1. Sort by DTBTL\n\n");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
				
					break;
				
				case 2:
					system("cls");
				
					sortByDRL(SV, numOfStudent);
					printf("2. Sort by DRL\n\n");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
					break;
				case 3:
					system("cls");
				
					sortByID(SV, numOfStudent);
					printf("3. Sort by Student ID\n\n");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
					break;
				case 4:
					system("cls");
					printf("4. Sort by Name\n\n");
					sortByName(SV, numOfStudent);
					sortByName(SV, numOfStudent);
					
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
					break;
			}
			break;
		case 4:  //add info
			
			system("cls");
			printf("Enter the number of Student you want to add: ");
			scanf("%d", &n);
			
			SV = realloc(SV, sizeof(student) * (numOfStudent+n));
			
			getInfo(SV, numOfStudent, n);
			
			numOfStudent = numOfStudent + n;
			
			continue;
			
		case 5:	//delete information
			system("cls");
			printf("\n\n\
					1. REMOVE in other\n\n\
					2. REMOVE by Student ID\n\n");
			printf("\n\
					Choose an option: ");
			scanf("%d", &choose);
		
			switch(choose){
				case 1:	//remove in other
					system("cls");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
					
					printf("\n\nWhat number student you want to REMOVE: ");
					scanf("%d", &i);
					i--;
					removeInfo(SV, i, numOfStudent);
					numOfStudent --;
					
					printf("\n\nREMOVE complete !! \n\n\n");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
					
					break;
					
				case 2:	//remove by ID
					system("cls");
					
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
				
					printf("\nWhat student ID you want to REMOVE: ");
					fflush(stdin);
					gets(find);

					for(i = 0; i < numOfStudent; i++){
						if(stricmp(find, SV[i].ID) == 0 ){
							removeInfo(SV, i , numOfStudent);
							numOfStudent --;
						}	
					}
					
					printf("\n\nREMOVE complete !! \n\n\n");
					printSta();
					for(i = 0; i < numOfStudent; i++){
						printInfo(SV, i);
					}
					break;
			}
			break;
			case 0:
				conti = 0;
				printf("\n\n\n\
						SEE YOU AGAIN !!!");
		}
		if (conti != 0){
			printf("\n\n\nPRESS ANYKEY to CONTINUE...");
			getch();
			system("cls");
		}
	}
	updateFile(sourc, SV,numOfStudent);
	free(SV);
	
	return 0;
}
	
	// nhap thong tin vao mang
void getInfo(student *SV, int m, int n){
	
	int i, count;
	char temp[200];
	
	for(i = m, count = 1; i < m + n;count ++, i++){

		printf("STUDENT No.%d: ", count);
		fflush(stdin);
		
		printf("\nStudent ID: ");
		gets(temp);
		delSpace(temp);
		SV[i].ID = strdup(temp);
		
		printf("\nFull name: ");
		gets(temp);
		delSpace(temp);
		SV[i].name = strdup(temp);
		
		printf("\nBirthday: ");
		gets(temp);
		delSpace(temp);
		SV[i].birthday = strdup(temp);
		
		printf("\nHome Town: ");
		gets(temp);
		delSpace(temp);
		SV[i].hometown = strdup(temp); 
		
		printf("\nDTBTL: ");
		scanf("%f",&SV[i].DTBTL);
		
		printf("\nDRL: ");
		scanf("%d",&SV[i].DRL);
		
		
		
		
		
		
		
		
		
		system("cls");
	}
	
}

	//dem so dong tren file
int countLine(FILE* sourc){
	char testC;
	int lineOfFile = 0;
	sourc = fopen("Student info.txt", "r");

	do{
		testC = fgetc(sourc);
		if(testC == '\n')
			lineOfFile ++;
	}while(testC != EOF);
	
	fclose(sourc);
	return lineOfFile;
}
	
	//chuan hoa ho ten
void delSpace(char str[]){
	
	//xoa dau cach
	while(str[0] == ' ')
		strcpy(&str[0], &str[1]);
		
	while(str[strlen(str)-1] == ' ')
		strcpy(&str[strlen(str)-1],&str[strlen(str)]);
	
	int i;
	for( i = 0; i < strlen(str); i++){
		if(str[i] == ' ' && str[i+1] == ' '){
			strcpy(&str[i], &str[i + 1]);
			i --;
		}
	}

	// viet hoa dau ten
	strlwr(str);
	str[0] = toupper(str[0]);
	for(i = 1; i < strlen(str); i++){
		if(str[i] == ' ')
			str[i+1] = toupper(str[i+1]);
	}
	
}

	//doc thong tin va dua vao struct SV
void readInfo(FILE *sourc, student *SV, int n){
	int i, tmp;
	float ftmp;
	char temp[200];
	
	sourc = fopen("Student info.txt","r");

	for ( i = 0; i < n; i++){
		fgets(temp, 11, sourc);
		delSpace(temp);
		SV[i].ID = strdup(temp);
		
		fgets(temp, 31, sourc);
		delSpace(temp);
		SV[i].name = strdup(temp);
		
		fgets(temp, 16, sourc);
		delSpace(temp);
		SV[i].birthday = strdup(temp);
		
		fgets(temp, 21, sourc);
		delSpace(temp);
		SV[i].hometown = strdup(temp);
		
		fscanf(sourc,"%8f", &ftmp);
		SV[i].DTBTL = ftmp;
		
		fscanf(sourc,"%5d", &tmp);
		SV[i].DRL = tmp;
		fseek(sourc, 2, SEEK_CUR);
		
	}
	fclose(sourc);
}

void printSta(){
	printf("%-5s %-10s %-30s %-20s %-20s %7s %7s \n","STT","Student ID","Full Name", "Birthday","Home Town", "DTBTL", "DRL");
}

void printInfo(student *SV, int i){
	printf("%-5d %-10s %-30s %-20s %-20s %7.1f %7.1d \n",i+1 , SV[i]. ID, SV[i]. name, SV[i]. birthday, SV[i]. hometown, SV[i]. DTBTL, SV[i]. DRL);
}

void nameSepara(student *SV,int n, char name[]){
	int i ;
	int len = strlen(SV[n]. name);
	for( i = len - 1; i > 0; i--){
		if(SV[n].name[i] == ' '){
			strcpy(name, &SV[n].name[i+1]);
			break;
		}
	}
}

void sortByName(student *SV, int n){
	int i, j;
	char namei[50], namej[50];
	for ( i = 0 ; i < n-1; i++ ){
		nameSepara(SV, i, namei);
		for(j = i+1; j < n; j++){
			nameSepara(SV, j, namej);
			if(strcmp(namei, namej) > 0){
				swapInfo(SV, i , j);
			}
		}	
	}
}

void sortByDTBTL(student *SV, int n){
	int i, j;
	for ( i = 0 ; i < n - 1; i++ ){
		for(j = i+1; j < n; j++){
			if(SV[j]. DTBTL > SV[i]. DTBTL){
				swapInfo(SV, i , j);
			}
		}	
	}
}

void sortByDRL(student *SV, int n){
	int i, j;
	for ( i = 0 ; i < n - 1; i++ ){
		for(j = i+1; j < n; j++){
			if(SV[j]. DRL > SV[i]. DRL){
				swapInfo(SV, i , j);
			}
		}	
	}
}

void sortByID(student *SV, int n){
	int i, j;
	for ( i = 0 ; i < n - 1; i++ ){
		for(j = i+1; j < n; j++){
			if(strcmp(SV[j]. ID, SV[i]. ID) < 0){
				swapInfo(SV, i , j);
			}
		}	
	}
}

void swapInfo(student *SV, int i, int j){
	student temp[1];
	temp[0] = SV[i];
	SV[i] = SV[j];
	SV[j] = temp[0];
}

void removeInfo(student *SV, int i, int n){
	int j;
	for (j = i+1; i < n - 1; j++, i++){
		swapInfo(SV, i , j);
	}
}

void updateFile(FILE* sourc, student *SV, int n){
	int i;
	sourc = fopen("Student info.txt", "w+");
	for(i = 0; i < n; i++){
		
		fprintf(sourc,"%10s", SV[i]. ID);
		
		fprintf(sourc,"%30s", SV[i]. name);
		
		fprintf(sourc,"%15s", SV[i]. birthday);
		
		fprintf(sourc,"%20s", SV[i]. hometown);
		
		fprintf(sourc,"%8.2f", SV[i]. DTBTL);
		
		fprintf(sourc,"%5d", SV[i]. DRL);
		
		fputs("\n", sourc);
	}
	
	fclose (sourc);
}

