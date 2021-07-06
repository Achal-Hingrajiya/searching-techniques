#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10


struct data_item
{
    int data;
    int key;
};

struct data_item *hash_table[SIZE];


int hashCode(int);
struct data_item *search_item(int);
void insert_item(int,int);
struct data_item *delete_item(int, int);
void display();


int main()
{
    int choice,key,data;

    struct data_item *temp;
    temp=(struct data_item *) malloc(sizeof(struct data_item));

    while(1)
    {
        printf("\n\nName: Hingrajiya Achal\nEn no.: 19012021012\n");
        printf("Practical 9 : Hash Table Implementation\n");
        printf("\n1. Insert\t2. Delete\n3. Search\t4. Display\n5. Exit\nEnter Your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                printf("\nEnter key and data to be inserted in Hash Table :\t");
                scanf("%d",&key);
                scanf("%d",&data);

                insert_item(key,data);

                printf("\n(%d, %d) inserted successfully.",key,data
                       );

                break;

            case 2:

                printf("\nEnter key and data to be deleted from Hash Table :\t");
                scanf("%d",&key);
                scanf("%d",&data);

                delete_item(key,data);

                printf("\n(%d, %d) deleted successfully.",key,data);

                break;

            case 3:
                printf("\nEnter key of data to be searched from Hash Table :\t");
                scanf("%d",&key);

                temp = search_item(key);
                if(temp)
                    printf("\nData associated with key : %d is %d in the Hash Table.",temp->key,temp->data);
                else
                    printf("\nData associated with key : %d is unavailable in the Hash Table.",key);

                break;

            case 4:

                printf("\nDisplaying the Hash Table:\t");
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("\nPlease make appropriate choice.\n");


        }//switch

    }//while

}


int hashCode(int key)
{

    return key%SIZE;
}


struct data_item *search_item(int key)
{


    int i = hashCode(key);

    while(hash_table[i] != NULL)
    {
        if(hash_table[i]->key == key)
            return hash_table[i];
        ++i;
        i %= SIZE;
    }

    return NULL;
}



void insert_item(int key,int data)
{
    struct data_item *item;
    item=(struct data_item*) malloc(sizeof(struct data_item));
    item->data = data;
    item->key = key;

    int i = hashCode(key);

    while(hash_table[i] != NULL && hash_table[i]->key != -1)
    {
        ++i;
        i %= SIZE;
    }

    hash_table[i] = item;

}



struct data_item* delete_item(int key, int data)
{

    struct data_item *dummy;
    dummy=(struct data_item *) malloc(sizeof(struct data_item));
    dummy->data =-1;
    dummy->key =-1;


    int i = hashCode(key);
    while(hash_table[i] !=NULL)
    {
        if(hash_table[i]->key == key)
        {
            struct data_item* temp=hash_table[i];

            hash_table[i]=dummy;

            return temp;
        }

        ++i;

        i%=SIZE;

    }
    return NULL;

}

void display()
{

    for(int i=0; i<SIZE; i++)
    {
        if(hash_table[i]==NULL)
            printf("(-, -), ");

        else
            printf("(%d, %d), ",hash_table[i]->key,hash_table[i]->data);
    }

}





