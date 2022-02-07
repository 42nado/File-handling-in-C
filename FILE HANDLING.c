#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#define MAX 10


int last;
void update();
void upload();
void download();
void makempty();
void insert();
void del(int x);
void display();
int isfull();
int isempty();
int locate();
int menu();

char name[MAX][31];
int q1[MAX], q2[MAX];
float average[MAX];
int i, d, p, x;
int sum=0;

int main(){
makempty();
download();
   while(1){
        switch(menu()){
        case 1 : system("cls");insert();break;
        case 2 : system("cls");display();printf("\nDelete Data\n");printf("Input the number to be deleted: ");scanf("%d",&d);del(d);break;
        case 3 : system("cls");display();printf("\nUpdate Data\n");printf("Input the number to be updated: ");scanf("%d",&d);update(d);break;
        case 4 : system("cls");display();getch();break;
        case 5 : upload();exit(0);
        default: printf("1-5 ONLY!");getch();

        }
    }
}
void makempty(){
last=0;
}
void insert(){
    printf("\nInsert Data\n");
    if (isfull()){
        printf("There is no space left!");
        getch();
    }
        else {
        printf("Name: ");
        scanf(" %[^\n]",name[last]);
        printf("Quiz #1: ");
        scanf("%d",&q1[last]);
        printf("Quiz #2: ");
        scanf("%d",&q2[last]);
        last++;
    }
}
void del(int x){

    if (isempty()){
        printf("Empty space!");
        getch();
    }
    else {
    p=locate(x);
    if (p<0){
        printf("Not found.");
        getch();
    }
    else{
      for(i=p;i<last;i++){
                strcpy(name[i],name[i+1]);
                q1[i]=q1[i+1];
                q2[i]=q2[i+1];
        }
        last--;
    }
}
}
void display(){
    printf("NAME OF STUDENT\t\tQuiz1\tQuiz2\tAverage   ");
    printf("Remarks\n");
    for(i=0;i<last;i++){
            sum=q1[i]+q2[i];
            average[i] = sum/2.0;

        printf("%d.)\t%s\t\t%d\t%d\t%6.2f\t ",i+1,name[i],q1[i],q2[i],average[i]);
        if (average[i]>=75.0){
            printf(" PASSED");
        }else{
            printf(" FAILED");
        }
        printf("\n");
    }
}
int isfull(){
   return(last==MAX);
}
int isempty(){
    return(last==0);
}
int locate(int x){
    for(i=0;i<=last;i++){
        if(x==i+1){
            return(i);
        }
    }
    return(-1);
}
int menu(){
    int op;
    system("cls");
    printf("*****Menu*****\n**************\n");
    printf("1.) Insert\n");
    printf("2.) Delete\n");
    printf("3.) Update\n");
    printf("4.) Display\n");
    printf("5.) Exit\n");
    printf("Select(1-5): ");
    scanf("%d",&op);
    return op;
}
void update(int x)
{
    if(isempty()){
        printf("Empty space");
        getch();
    }
    else{
        p=locate(x);
        if(p<0){
            printf("Not found");
            getch();
        }
        else{
        for(i=p;i<=last;i++){
          printf("Name: ");
            scanf(" %[^\n]",name[i]);
          printf("Quiz 1: ");
          scanf("%d",&q1[i]);
          printf("Quiz 2: ");
          scanf("%d",&q2[i]);
          break;
            }
        }
    }

}
void upload(){
    FILE *fp;
    fp=fopen("bsit1cd.dbf","w+");
    for(i=0;i<last;i++){
        fprintf(fp,"%s\n%d\n%d\n",name[i],q1[i],q2[i]);
    }
    fclose(fp);
}
void download(){
    FILE *fp;
    fp=fopen("bsit1cd.dbf","r+");
    while(!feof(fp)){
        fscanf(fp," %[^\n]\n%d\n%d\n", name[last],&q1[last],&q2[last]);
        last++;
    }
    fclose(fp);
}
