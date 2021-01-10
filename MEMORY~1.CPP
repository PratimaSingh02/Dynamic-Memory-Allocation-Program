#include<stdio.h>
#include<conio.h>
#define max 50
 //modified
//******Important***
//dont change position of if brackets because multiple conditions are checked simultaneously by each brace end and start.:)
//extrapos not required
int i2=0,x=0,choice,i,big,f,n,j,k,l,a=1,flag2=0,flag3=0,n1,arr1[max],ptotal,parr[max],arr2[max],n2,leftout[max],leftoutsize=0,flag[max],extrapos=0,index[max];
void display(){
int m=1;
clrscr();
/*for(f=1;f<=n1;f++){
printf("\t%d",flag[f]);
} */
if(choice==1)
printf("\n\n\t\t\t*****First Fit*****\n");
else
printf("\n\n\t\t\t*****Worst Fit*****\n");
for(f=1;f<=n1;f++){
if(flag[f]!=0){
printf("\n\t\t ------------------------------------------------------");
printf("\n\t\t|  (%d). %dKB memory block has P%d(%dKB) process.       |",m,arr1[f],flag[f],parr[flag[f]]);
printf("\n\t\t ------------------------------------------------------");
}//if
else{
printf("\n\t\t ------------------------------------------------------");
printf("\n\t\t|  (%d). %dKB memory block is FREE.                     |",m,arr1[f]);
printf("\n\t\t ------------------------------------------------------");
}//else
m++;
}//for
if(leftoutsize>0){
for(m=1;m<=leftoutsize;m++){
printf("\n\n\t-->Process %d(%dKB) didn't get memory space(leftout).",leftout[m],parr[leftout[m]]);
}//while
}
/*if(extrapos>0){
while(extrapos<ptotal){
printf("\nProcess %d(%dKB) didn't get memory space(cuz extra).",extrapos,parr[extrapos]);
extrapos++;
}//while
}//if*/
}//function
void init(){
printf("\nEnter total number of memory blocks= ");
scanf("%d",&n1);
n2=n1;
if(n1>=1){
printf("\n\tEnter each blocks' memory size in integer:-  ");
}//if
for(f=1;f<=n1;f++){
printf("\nEnter memory block %d size= ",f);
scanf("%d",&arr1[f]);
if(arr1[f]<=0){
printf("\nEnter value bigger than 0.");
f--;
continue;
}//inner if
arr2[f]=arr1[f];
}//for
printf("\nEnter total number of processes= ");
scanf("%d",&ptotal);
if(ptotal>=1){
printf("\n\tEnter each process' memory size required:-");
}//if
for(f=1;f<=ptotal;f++){
printf("\nEnter process %d memory size= ",f);
scanf("%d",&parr[f]);
if(parr[f]<=0){
printf("\nEnter value bigger than 0.");
f--;
}
}//for
for(f=1;f<=n1;f++){
flag[f]=0;
}//for
a=1;//also point to leftout[]s first index
leftoutsize=0;//initialize its size to 0 at the start
}//function
void main(){
do{
clrscr();
printf("\nSelect an algorithm:\n1.First fit\n2.Worst fit\n\n\tEnter your choice= ");
scanf("%d",&choice);
switch(choice){
case 1:
init();
/*if(ptotal>n1){
printf("\n\textrapos initialized to=%d ",extrapos);
extrapos=(ptotal-n1)+1;
} */
//printf("\n\t\tValue of n=%d",n);
for(f=1;f<=ptotal;f++){
//printf("\narr2/n2 array %d time:\n",f);
/*for(k=1;k<=n2;k++){
printf("\t%d",arr2[k]);
} *///displays array arr2 after each iteration of outer for loop
for(j=1;j<=n2;j++){
if(arr2[j]>=parr[f]){
for(l=1;l<=n1;l++){
if(arr2[j]==arr1[l]){
//printf("\nProcessP%d is in mb%d and flag position=%d flag value= %d",f,l,l,f);
flag[l]=f;//flag is a flag of mb1
break;
}//if
}//innerest inner for
//index[a]=l;//value of index of mb1
//a++;
k=j;
while(k<n2){
arr2[k]=arr2[k+1];
k++;
}//while
n2--;//array shortened
break;//memory allocated for this process
}//if
}//inner for
for(k=1;k<=n1;k++){ //dont use ptotalbecuaseptotal size may be less and arr1 size may be more and the process may be alloacted to the last mb in arr1
if(f==flag[k]){
flag3=1;//means memory allocated
break;
}//outer for if
}//another inner for
if(flag3!=1){
leftout[a]=f;//lefout process index  _______________________________________
a++;
leftoutsize++;
}
flag3=0;
//printf("\t%d time: n2= %d",f,n2);
}//outer for
printf("\npress 1 to display= ");
scanf("%d",&flag2);
if(flag2==1)
display();
break;//case 1 break

case 2:
//******Important***
//dont change position of if brackets because multiple conditions are checked simultaneously by each brace end and start.:)
init();
//big=-1;//initilaize big to a new value otherwise if(parr[f]<=big) will consider previous wrong fit big value
for(f=1;f<=ptotal;f++){
if(n2>0){
big=arr2[0];
for(i=1;i<=n2;i++){
if(big<arr2[i]){
big=arr2[i];
i2=i;
}
}//biggest
//**********Important*******
//no need of big=-1 because the whole allocation(entry of process in flag[]) is done only when element is left in arr2 i.e. n2>0
if(parr[f]<=big){
for(l=1;l<=n1;l++){
if(big==arr1[l]){
flag[l]=f;
break;
}
}//flag

while(i2<n2){
arr2[i2]=arr2[i2+1];
i2++;
}//while
n2--;
}//if process is allocated(if of parr[f]<=big)
}//if to check n2!=0
for(k=1;k<=n1;k++){
if(f==flag[k]){
flag3=1;
break;
}
}//leftout
if(flag3!=1){
leftout[a]=f;
a++;
leftoutsize++;
}//if process didnt get allocated
flag3=0;
}//outer for
printf("\npress 1 to display= ");
scanf("%d",&flag2);
if(flag2==1)
display();
break;//case2 break

default:
printf("\nYou've entered a wrong choice.");
break;
}//switch
printf("\n\nPress 1 to go to menu or press any other key to exit= ");
scanf("%d",&x);
}while(x==1);

getch();
}
