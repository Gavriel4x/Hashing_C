/*
    By: Gavriel Reynard
    Date: 27 march 2022

*/

// APLICATION CODE FOR HASHING MID SQUARE ALGORITHM

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

const int Max = 1000;

struct Node{
    char name[51];
    Node *next;
} *Head[Max], *Tail[Max];

Node *createNode(char *name){

    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}

const int SIZE = 3; // initialize based on the assumption that the table size is 1000

int get_digits(long int hashvalue){ // get the length of the digits

    int count = 0;
    
    while(hashvalue){
        hashvalue /= 10;
        count++;
    }return count;
}

int MidSquare(char *name){ // a string is hashed based on the algorithm function

    long int hashvalue = 0;
    int len = strlen(name);

    int key = 0;
    for(int i=0;i<len;i++){
        key += name[i];
    }hashvalue = key * key;

    int total_digits = get_digits(hashvalue);
    int last_index = (total_digits / 2);
    int first_index = (last_index + SIZE) - 1;

    int divide_by = last_index - 1;
    int diff = (first_index) - last_index;

    for(int i=0;i<divide_by;i++){
        hashvalue /= 10;
    }long int temp = hashvalue;

    int temp2 = pow(10,diff+1);
    int final = temp%temp2;
    printf("\nHash value is %d \n\n",final);

    return final;
}

void insert(char *name){ // insert a node to the hash tables

    Node *newNode = createNode(name);
    int index = MidSquare(name);

    if(!Head[index]){
        Head[index] = Tail[index] = newNode;
    }else{
        Tail[index]->next = newNode;
        Tail[index] = newNode;
    }
}

void print(){ // print all function

    for(int i=0;i<Max;i++){
        if(Head[i]){

            printf("Index ke-%d : ",i);

            for(Node *curr = Head[i]; curr ;curr = curr->next ){
                printf("%s -> ",curr->name);
            }printf("NULL");
            puts("");
        }
    }
}

int main(){

    puts("Please type how much times you would like to input");

    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){
        puts("Enter Name!!");
        char name[51];
        scanf("%[^\n]",&name);
        getchar();
        insert(name);
    }print();

    return 0;
}