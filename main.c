#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>



//MergeSort funkcije za nizove
void insertion_sort(int arr[], int low, int high) {
 int i, j ,tmp;
 for (i = low; i <= high; i++) {
 j = i;
 while (j > low && arr[j - 1] > arr[j]) {
 tmp = arr[j];
 arr[j] = arr[j - 1];
 arr[j - 1] = tmp;
 j--;
 }
 }
 }


void merge(int a[], int low, int high, int k)
{



    int n=(high-low+1),i;
    int len_pod=n/k;
    int broj_zadnjih=n-len_pod*(k-1);
    int curPos[k];
    int mid = low+n/k-1;
    int * pomocni=malloc(n*sizeof(int));



    for (i=0;i<k;++i)
        curPos[i]=0;


if(k==2){


    int i = low, j = mid+1, l = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            pomocni[l++] = a[i++];
        else
            pomocni[l++] = a[j++];
    }
    while (i <= mid)
        pomocni[l++] = a[i++];

    while (j <= high)
        pomocni[l++] = a[j++];

    l--;
    while (l >= 0) {
        a[low + l] = pomocni[l];
        l--;
    }
    free(pomocni);

}


else {

    int p=0;

    while (p<n)
    {

       int minPos = -1;
       int minn = INT_MAX;

          for (i=0; i<k-1; ++i)
        {

            if (curPos[i]<len_pod)
            {

                if(a[low+len_pod*i+curPos[i]]<minn)
                {
                    minn=a[low+len_pod*i+curPos[i]];
                    minPos=i;
                }

            }


        }

                if (curPos[k-1]<broj_zadnjih)
            {

                if(a[low+len_pod*(k-1)+curPos[k-1]]<minn)
                {
                    minn=a[low+len_pod*(k-1)+curPos[k-1]];
                    minPos=k-1;
                }

            }



        curPos[minPos]++;
        pomocni[p++] = minn;

    }


for (i=0; i<n; ++i)
    a[low+i]=pomocni[i];
free(pomocni);

}

}





  void kwayMergesortRecursive (int a[], int low, int high, int k) {
        int i;


        if (high-low+1<k)
        {
           insertion_sort(a,low,high);
        }

            else{
            for (i = 0; i < k-1; i++) {

                kwayMergesortRecursive (a,
                                        low + i*((high-low+1)/k),
                                        low + (i+1)*((high-low+1)/k) - 1,
                                       k);
            }
            kwayMergesortRecursive(a,low + (k-1)*((high-low+1)/k),high,k);
            merge (a, low, high, k);

        }
    }




//MergeSort funkcije za liste

typedef struct node
{
    int data;

    struct node* next;

}node;

void Split(node* source, node* ptr[], int k, int n)
{
    int i,j;
    node* pom1;
    node* pom2;

    if (source==NULL || source->next==NULL)
    {
        *(ptr+0) = source;
        //for (i=1;i<k;++i)
       // *(ptr+i) = NULL;
    }

    else

 {


    ptr[0] = source;
    pom1=source;
    pom2=source;
    int granica= n/k;
   for (i=1; i<k; ++i)
    {


        j=1;

        while (j<granica){
            pom1=pom1->next;

            j++;
        }

        ptr[i]=pom1->next;
        pom2=pom1;
        pom1=pom1->next;
        pom2->next=NULL;

    }
/*
    for (i=0; i<k-1; ++i){
        j=1;
        pom1=ptr[i];
        while (j<granica){
            pom1=pom1->next;
            j++;

        }
        pom1->next=NULL;
    }

*/

 }

}


node* merge_list (node* ptr[], int k, int n)
{
node* pom1;
node* head;
int p=0, key, i;
int minn = INT_MAX;



if(k==2){

 for(i=0;i<k;++i){
    if(ptr[i]!=NULL)
    {
        if(ptr[i]->data<minn)
        {
            minn=ptr[i]->data;
            key=i;
        }
    }
}
pom1=ptr[key];
head=pom1;
ptr[key]=ptr[key]->next;
p++;


while(p<n)
{
minn=INT_MAX;

if(ptr[0]!=NULL)
        {
            if(ptr[0]->data<minn)
            {
                minn=ptr[0]->data;
                key=0;
            }
        }


else {
    if(ptr[1]!=NULL){
        while(ptr[1]!=NULL) { pom1->next=ptr[1];
                            pom1=ptr[1];
                            ptr[1]=ptr[1]->next;
                            }
                            break;

    }



}


        if(ptr[1]!=NULL)
        {
            if(ptr[1]->data<minn)
            {
                minn=ptr[1]->data;
                key=1;
            }
        }


   else {
    if(ptr[0]!=NULL){
        while(ptr[0]!=NULL) { pom1->next=ptr[0];
                            pom1=ptr[0];
                            ptr[0]=ptr[0]->next;
                            }
                            break;

    }



}



 pom1->next=ptr[key];
 pom1=ptr[key];
 ptr[key]=ptr[key]->next;
 p++;



}


}


else {


for(i=0;i<k;++i){
    if(ptr[i]!=NULL)
    {
        if(ptr[i]->data<minn)
        {
            minn=ptr[i]->data;
            key=i;
        }
    }
}
pom1=ptr[key];
head=pom1;
ptr[key]=ptr[key]->next;
p++;


while (p<n){
minn=INT_MAX;
for (i=0; i<k; ++i)
    {
        if(ptr[i]!=NULL)
        {
            if(ptr[i]->data<minn)
            {
                minn=ptr[i]->data;
                key=i;
            }
        }
    }

 pom1->next=ptr[key];
 pom1=ptr[key];
 ptr[key]=ptr[key]->next;
 p++;

}
}

return head;
}


static void push(node **head, int v)
{
    node *temp = malloc(sizeof(node));
    temp->data = v;
    temp->next = *head;
    *head = temp;
}




int pop(node ** head) {
    node * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    free(*head);
    *head = next_node;

    return 0;
}




void printList(node *node)

{

    while (node != NULL)

    {

        printf("%d ", node->data);

        node = node->next;

    }

}

int check_List(node *node, int n)
{
    int flag=1;
    int i=1;

    while (node!=NULL)
    {
        if(node->data!=i) {printf("Greska na %d mjestu za n = %d",i,n); flag=0; break;}
        node=node->next;
        i++;

    }

    return flag;

}


node* insertion_sort_inplace(node *head)

    {

        if(head == 0) return head;

        // assume head is sorted

     node *unsort = head->next;

       while(unsort != 0)

        {

           // take key as an element in the unsorted list.

            node *prev = 0;
            node *iter = head;
            node *key = unsort;

           // iterate within the sorted list and find the position

            while(iter != 0)

            {

                if(iter->data < key->data)

              {

                   prev = iter;

                   iter = iter->next;

                }

               else

                    break;

           }

            unsort = unsort->next;

           // if reached the end of sorted list, continue

           if(iter == key)

             continue;

            // note down the position to place

           node *place = iter;

            //move iter to end of the sorted list and connect with unsort

           while(iter->next != key) iter=iter->next;

            iter->next = unsort;

           // delete the key and place it in sorted list

          if(prev == 0) {
             head = key;

           } else {

              prev->next = key;

          }

          key->next = place;

       }

        return head;

    }





void MergeSort(struct node** headRef, int k, int n)

{

    node* head = *headRef;
    if ((head == NULL)|| head->next==NULL)

    {
        return;
    }

    else {

    if(n<k){
      *headRef=insertion_sort_inplace(head);

    }
    else{

    int i;
    node* ptr[k];
    Split(head, ptr, k,n);

   for (i=1; i<=(k-1); ++i)
    {
        MergeSort(&ptr[i-1],k,(n/k));
    }
        MergeSort(&ptr[k-1],k,(n-((k-1)*(n/k))));
    *headRef=merge_list(ptr,k,n);


    }
}
}



void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int check_Array (int arr[], int n)
{
    int i;
    int flag=1;
    for (i = 0; i < n; i++){
        if(arr[i]!=i+1)
        {
        printf("Greska na %d mjestu, za n = %d\n",i,n);flag=0; break;
        }

    }

    return flag;
}


void printArray (int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



void randomize ( int arr[], int n )
{
    int i,j;
    srand ( time(NULL) );


    for (i = n-1; i > 0; i--)
    {

        j = rand() % (i+1);

        swap(&arr[i], &arr[j]);
    }
}



void get_random_int(int * a,int low_bound, int up_bound, int size)
{
  int i;
  srand(time(NULL));
  for (i=0; i<size; ++i)
        a[i]= ((rand() % (up_bound-low_bound+1)) + low_bound);


}


 double dsecnd (void) {
    return (double)( clock( ) ) / CLOCKS_PER_SEC;
}


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}



int main()
{

FILE *f = fopen("output.txt", "w");

if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}








int i,k,j,n=10000;
double niz[19]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double liste[19]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double quick[1]={0};
double best_niz[19]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
double best_liste[19]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
double best_quick[1]={INT_MAX};


int polje[32]={-2000,3000,-4,-1,-4,-4,0,0,450,2,33,43,100,43,33,18,19,20,1,1,1,3,3,3,-182,32,15,21,46,78,30000000,-11000};
node *c=NULL;
int pompolje[32];

for(i=0;i<32;++i){

   pompolje[i]=polje[i];
    push(&c,polje[(32-1)-i]);
}

printf("Vizualni test korektnosti\n");
printf("----------------------------------------------------------------------\n");
printf("Sortiramo niz: ");
printArray(pompolje,32);
printf("----------------------------------------------------------------------\n\n");
printf("Mergesort za polja: ");
kwayMergesortRecursive(pompolje,0,31,5);

printArray(pompolje,32);

printf("\n\n");

MergeSort(&c, 5,32);
printf("Mergesort za liste: ");
printList(c);


printf("\n\n");
printf("----------------------------------------------------------------------\n");


int * ret = malloc(n* sizeof(int));
int * ret1= malloc(n* sizeof(int));
node* a;
for(i=0;i<n;++i)
    ret[i]=n-i;



randomize(ret,n);
int flag=1, flag1=1;

printf("Testovi korektnosti algoritama\n");
printf("------------------------------\n\n");
for (k=2; k<=sqrt(n);++k){
a=NULL;
for(i=0;i<n;++i){
ret1[i]=ret[i];
push(&a,ret[(n-1)-i]);
}

kwayMergesortRecursive(ret1,0,n-1,k);
MergeSort(&a, k,n);


if(!check_Array(ret1,n)){printf("Greska za k = %d\n",k); flag=0; printArray(ret1,n);break;}
if(!check_List(a,n)){printf("Greska za k = %d\n",k);flag1=0; printList(a);break;}
}
if(flag==1) printf("Polje je korektno sortirano za svaki k.\n");
if(flag1==1) printf("Lista je korektno sortirana za svaki k.\n");
printf("\n\n");



printf("Vremenski testovi, n = %d\n",n);
printf("Prosjecna vremena na 10 uzoraka duljine n\n");
printf("----------------------------------------------------------------------\n");
printf("     k            Mergesort (polja)                Mergesort (liste) \n");
printf("                   Average (best)                   Average (best)   \n");
printf("----------------------------------------------------------------------\n");
int l[12]={2,3,4,5,6,7,8,9,10,20,40,sqrt(n)};
double t1,t2;

for (j=0;j<10;++j){
for (k=0;k<12;++k){

a=NULL;
for(i=0;i<n;++i){
ret1[i]=ret[i];
push(&a,ret[(n-1)-i]);
}

t1=dsecnd();
kwayMergesortRecursive(ret1,0,n-1,l[k]);
t2=dsecnd();
niz[k]=niz[k]+(t2-t1);
if((t2-t1)<best_niz[k]) best_niz[k]=t2-t1;

t1=dsecnd();
MergeSort(&a, l[k],n);
t2=dsecnd();
liste[k]=liste[k]+(t2-t1);
if((t2-t1)<best_liste[k]) best_liste[k]=t2-t1;



}

for(i=0;i<n;++i){
ret1[i]=ret[i];
}

t1=dsecnd();
qsort(ret1, n, sizeof(int), cmpfunc);
t2=dsecnd();

quick[0]=quick[0]+(t2-t1);
if((t2-t1)<best_quick[0]) best_quick[0]=t2-t1;


randomize(ret,n);

while(1)
{
 if(pop(&a)==-1) {break;}
}

}

free(ret);
free(ret1);
free(a);

for (i=0;i<12;++i)
{
    niz[i]=niz[i]/10;
    printf("    %3d      %10fl (%fl)",l[i], niz[i],best_niz[i]);
    fprintf(f, "%fl", niz[i]);

    liste[i]=liste[i]/10;

    printf("           %10fl (%fl)", liste[i],best_liste[i]);
    fprintf(f, "          %fl\n",liste[i]);
    printf("\n");
    fprintf(f, "\n\n");
}
quick[0]=quick[0]/10;

fprintf(f, "  \n\n\n");
fprintf(f, "          %fl\n",quick[0]);

fprintf(f, "  \n\n\n");

for (i=0;i<12;++i)
{
fprintf(f, "%fl", best_niz[i]);

fprintf(f, "          %fl\n",best_liste[i]);

}

fprintf(f, "          %fl\n",best_quick[0]);
fprintf(f, "\n\n");

fclose(f);


printf("\n");
printf("Vrijeme quicksorta (qsort) je %fl (%fl)\n",quick[0],best_quick[0]);

printf("\n\n");








    return 0;
}


