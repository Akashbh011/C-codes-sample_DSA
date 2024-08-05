//Restaurant Management System
//CSA- Group 5

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <ctype.h>
#define BUFFER_SIZE 1000
struct node
{
    char foodname[50];
    int quantity;
    float price;
    int data;
    struct node *prev;
    struct node *next;
};


struct node *headc=NULL,*newnode,*tailc=NULL;
struct node *heada=NULL,*taila=NULL;
struct node *head_s;
FILE *fp;//file pointer

void adminmenu()
{
    printf("\n\t\t\t\t\t\t\t1. View Total Sales for the day\n");
    printf("\t\t\t\t\t\t\t2. Add new items in the order menu\n");
    printf("\t\t\t\t\t\t\t3. Delete items from the order menu\n");
    printf("\t\t\t\t\t\t\t4. Update price of an item\n");
    printf("\t\t\t\t\t\t\t5. Display order menu\n");
    printf("\t\t\t\t\t\t\t6. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");

}


void customermenu()
{
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from order\n");
    printf("\t\t\t\t\t\t\t4. Delete ordered list\n");
    printf("\t\t\t\t\t\t\t5. Display final bill\n");
    printf("\t\t\t\t\t\t\t6. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
}

struct node *createadmin(struct node *head,int data, char foodname[], float price)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->price=price;
    newnode->quantity=0;
    strcpy(newnode->foodname,foodname);
    newnode->next=NULL;
    newnode->prev=NULL;

    struct node *temp=head;
    if(temp==NULL)
    {
        heada=taila=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=taila;
        taila=newnode;
    }
    return heada;
}


struct node *createcustomer(struct node *head,int data,int quantity)
{
    newnode=(struct node *)malloc(sizeof(struct node));

    struct node *temp1=heada;
    int flag=0;
    while(temp1!=NULL)
    {
        if(temp1->data==data)
        {
            flag=1;
            break;
        }
        temp1=temp1->next;
    }
    if(flag==1)
    {
        newnode->data=data;
        newnode->price=quantity*(temp1->price);
        newnode->quantity=quantity;
        strcpy(newnode->foodname,temp1->foodname);
        newnode->next=NULL;
        newnode->prev=NULL;

        struct node *temp=head;
        if(temp==NULL)
        {
            headc=tailc=newnode;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=tailc;
            tailc=newnode;

        }
    }
    else
    {
        printf("\n\t\t\t\t\t\t\tThis item is not present in the menu!\n");
    }
    return headc;
}


void displayList(struct node *head)
{

    struct node *temp1=head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL){
            if(temp1->quantity==0)
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n",temp1->data,temp1->foodname,temp1->price);
            }
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n",temp1->data,temp1->foodname,temp1->quantity,temp1->price);
            }
            temp1=temp1->next;
        }
        printf("\n");
    }
}


struct node *totalsales(int data, int quantity)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    int flag=0;
    struct node *temp1=heada;
    while(temp1->data!=data){
        temp1=temp1->next;
    }
    newnode->data=data;
    newnode->price=quantity*(temp1->price);
    newnode->quantity=quantity;
    strcpy(newnode->foodname,temp1->foodname);
    newnode->next=NULL;
    newnode->prev=NULL;

    struct node *temp=head_s;
    if(temp==NULL){
        head_s=newnode;
    }else{
        while(temp->next!=NULL){
            if(temp->data==data){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1)
        {
            temp->quantity+=newnode->quantity;
            temp->price=newnode->price;
        }
        else{
            temp->next=newnode;
        }
    }
    return head_s;
}


void calculatetotsales()
{
    struct node *temp = headc;
    while(temp!=NULL)
    {
        head_s = totalsales(temp->data, temp->quantity);
        temp=temp->next;
    }
}


struct node *delete(int data,struct node *head,struct node *tail){
    if(head==NULL){
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }else{
        struct node *temp;
        if(data==head->data){
            temp=head;
            head=head->next;
            if(head!=NULL){
                head->prev=NULL;
            }
            free(temp);
        }else if(data==tail->data){
            temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            free(temp);
        }else{
            temp=head;
            while(temp->data!=data){
                temp=temp->next;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
    return head;
}

void deleteFromFile(int serial_no){
    FILE *fp1, *fp2;
    char line[100];
    char name[50];
    float price;
    int num;

    // Open the file in read mode
    fp1 = fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt", "r");

    // Open a temporary file in write mode
    fp2 = fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\temp.txt", "w");
    while (fgets(line, sizeof(line), fp1)) {
        // Get the serial number, food name and price from the line
        sscanf(line, "%d %s %f", &num, name, &price);

        // If the serial number matches, update the price and write back to the file
        if (serial_no == num) {
            continue;
        } else {
            fprintf(fp2, "%s", line);
        }
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    // Delete the original file
    remove("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt");

    // Rename the temporary file to the original file name
    rename("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\temp.txt", "C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt");

}


int deleteAdmin(){
   /* // printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    // int num;
    // scanf("%d",&num);

    // struct node *temp=heada;
    // while(temp!=NULL){
    //     if(temp->data==num){
    //         heada=delete(num,heada,taila);
    //         return 1;
    //     }
    //     temp=temp->next;
    // }*/

    FILE *fp1, *fp2;
    int serial_no, found = 0;
    char line[100];
    char name[50];
    float price;
    int num;
    // Open the file in read mode
    fp1 = fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt", "r");


    printf("Enter the serial number of the food item to delete: ");
    scanf("%d", &serial_no);
    while (fgets(line, sizeof(line), fp1)) {
        // Get the serial number, food name and price from the line
        sscanf(line, "%d %s %f", &num, name, &price);

        // If the serial number matches, update the price and write back to the file
        if (serial_no == num) {

            found = 1;
            fclose(fp1);
            deleteFromFile(num);
        } else {
            found = 0;
        }
    }
    fclose(fp1);



    if (found) {
        return 1;
    } else {
        return 0;
    }
}


int deletecustomer()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    struct node* temp=headc;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            headc = delete(num, headc, tailc);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}


void displaybill(){
   // fopen("D:\\DSCourseProject\\bill.txt", "a");
    displayList(headc);
    struct node *temp = headc;
    float total_price=0;
    while(temp!=NULL){
        total_price += temp->price;
        temp=temp->next;
    }

     printf("\t\t\t\t\t\t\tTotal price: %0.02f\n",total_price);
    fprintf(fp,"The total price is: %.2f \n",total_price);
}

struct node *deleteList(struct node *head){
    if(head==NULL){
        return NULL;
    }
    else{
        struct  node *temp=head;
        while(temp->next!=0){
            temp=temp->next;
            free(temp->prev);
        }
        free(temp);
        head=NULL;
    }//file empty
    return head;
}

void updatePrice(){
    FILE *fp1, *fp2;
    int serial_no, found = 0;
    char line[100];
    char name[50];
    float price;
    int num;
    float newp;
    // Open the file in read mode
    fp1 = fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt", "r");

    // Open a temporary file in write mode
    fp2 = fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\temp.txt", "w");
    printf("Enter the serial number of the food item to update: ");
    scanf("%d", &serial_no);
    printf("Enter the new price: ");
    scanf("%f", &newp);
    while (fgets(line, sizeof(line), fp1)) {
        // Get the serial number, food name and price from the line
        sscanf(line, "%d %s %f", &num, name, &price);

        // If the serial number matches, update the price and write back to the file
        if (serial_no == num) {
            fprintf(fp2, "%d %s %0.2f\n", serial_no, name, newp);
            found = 1;
        } else {
            fprintf(fp2, "%s", line);
        }
    }

    // Close both files
    fclose(fp1);
    fclose(fp2);

    // Delete the original file
    remove("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt");

    // Rename the temporary file to the original file name
    rename("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\temp.txt", "C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt");

    if (found) {
        printf("Record updated successfully.\n");
    } else {
        printf("Record not found.\n");
    }
    /*struct node *temp;
    temp=heada;
    while(temp->data!=num && temp!=NULL){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("\t\t\t\t\t\t\tThis item is not present in the menu");
        return 0;
    }*/
    /*printf("\n\t\t\t\t\tEnter the new price of the item: ");
    int p;
    scanf("%d",&p);*/
    //temp->price = p;



}

int arrayEqual(char name1[],char name2[]){
    int len1=0;
    int len2=0;

    while(name1[len1]!='\0'){
        len1+=1;
    }
    while(name2[len2]!='\0'){
        len2+=1;
    }

    if(len1!=len2){
        return 0;
    }
    else{
        for(int i=0;i<len1;i++){
            if(name1[i]!=name2[i]){
                return 0;
            }
        }
    }
    return 1;
}


void feedback(){
    //fp=fopen("D:\\DSCourseProject\\list.txt","a");
    float rating;
    printf("Thank you!, please rate our overall service in range of (0-5): ");
    scanf("%f",&rating);
    fprintf(fp,"The rating for the service was: %f \n",rating);
}


char* trim(char* str) {
    int i, j;
    char* trimmed = (char*) malloc(strlen(str) + 1);

    // Remove leading spaces
    for (i = 0; str[i] == ' '; i++);
    strcpy(trimmed, str + i);

    // Remove trailing spaces
    for (j = strlen(trimmed) - 1; j >= 0 && trimmed[j] == ' '; j--);
    trimmed[j + 1] = '\0';

    return trimmed;
}

void normalize_string(char* str, char* result) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            result[j] = tolower(str[i]);
            j++;
        }
    }
    result[j] = '\0';

    // Remove newline character from the result string
    if (j > 0 && result[j-1] == '\n') {
        result[j-1] = '\0';
    }
}




void admin(){
    //fopen("D:\\DSCourseProject\\list.txt", "a");
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t    ADMIN SECTION\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1){
        adminmenu();

        int opt;
        scanf("%d",&opt);


        if(opt==6){
            break;
        }


        switch(opt){
            case 1:
                displayList(head_s);

                break;
            case 2:
                fp= fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt","a+");
                printf("\n\t\t\t\t\t\t\tEnter serial no. of the food item: ");
                int num,flag = 0;
                char name[50];
                float price;
                scanf("%d",&num);
                getchar();
                printf("\n\t\t\t\t\t\t\tEnter name of the food item: ");
                fgets(name,50,stdin);
                name[strcspn(name,"\n")]=0;
                char file_line[200];
                int file_serial_no;
                char file_product_name[100];
                float file_product_price;
                int flg=0;


                /*while (fgets(file_line, 200, fp)) {
                    // Split line into fields
                    sscanf(file_line, "%d %[^\n]%*c %f", &file_serial_no, file_product_name, &file_product_price);

                    // Compare input serial no and product name with file serial no and product name
                    if (num==file_serial_no || strcmp(name, file_product_name) == 0) {
                        printf("\n\t\t\t\t\t\t\tError: Serial no or product name already exists in the file.\n");
                        flg=1;
                        break;
                    }
                }*/
                rewind(fp);

                while (fgets(file_line, 200, fp)) {
                    // Split line into fields
                    //sscanf(file_line, "%d %[^\n]%*c %f", &file_serial_no, file_product_name, &file_product_price);
                    sscanf(file_line, "%d %s %f", &file_serial_no, file_product_name, &file_product_price);
                    // Trim leading and trailing spaces from the input and file product names
                    /char input_product_name_trimmed = trim(name);
                    char* file_product_name_trimmed = trim(file_product_name); */

                    char normalized_input_name[100], normalized_file_name[100];
                    normalize_string(name, normalized_input_name);
                    normalize_string(file_product_name, normalized_file_name);

                    // Compare input serial no and trimmed input product name with file serial no and trimmed file product name
                    /*if (num==file_serial_no || strcmp(input_product_name_trimmed, file_product_name_trimmed) == 0) {
                        printf("\n\t\t\t\t\t\t\tError: Serial no or product name already exists in the file.\n");
                        flg=1;
                        break;
                    }*/

                    if (num == file_serial_no || strcasecmp(normalized_input_name, normalized_file_name) == 0) {
                        printf("\n\t\t\t\t\t\t\tError: Serial no or product name already exists in the file.\n");
                        flg = 1;
                        break;
                    }





                    // Free memory allocated for trimmed product names
                   /* free(input_product_name_trimmed);
                    free(file_product_name_trimmed); */
                }


                if(flg!=1)
                {
                    printf("\n\t\t\t\t\t\t\tEnter price: ");
                    scanf("%f",&price);
                    heada = createadmin(heada,num,name,price);
                    struct node *temp1=heada;
                    while(temp1->data!=num)
                    {
                        temp1=temp1->next;
                    }
                    fprintf(fp,"%d %s %.2f\n",temp1->data,temp1->foodname,temp1->price);
                    printf("\n\t\t\t\t\t\t\tNew food item added to the list!!\n\n");
                    //fclose(fp);

                }
                fclose(fp);



                break;

            case 3:
            if(deleteAdmin()){
                printf("\n\t\t\t\t\t\t### Updated list of food items menu ###\n");
                //displayList(heada);


                fp=fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt","r");
                char buffer[BUFFER_SIZE];
                int totalRead = 0;
                if(fp == NULL)
                {
                    /* Unable to open file hence exit */
                    printf("Unable to open file.\n");
                    printf("Please check whether file exists and you have read privilege.\n");
                    exit(EXIT_FAILURE);
                }
                printf("File opened successfully. Reading file contents line by line. \n\n");


                /* Repeat this until read line is not NULL */
                while(fgets(buffer, BUFFER_SIZE, fp) != NULL)
                {
                    /* Total character read count */
                    totalRead = strlen(buffer);


                    /*
                     * Trim new line character from last if exists.
                     */
                    buffer[totalRead - 1] = buffer[totalRead - 1] == '\n'
                                            ? '\0'
                                            : buffer[totalRead - 1];


                    /* Print line read on cosole*/
                    printf("%s\n", buffer);

                }


                /* Done with this file, close file to release resource */
                fclose(fp);

            }
            else{
                printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!\n\n");
            }
            break;

            case 4:
                updatePrice();
                break;

            case 5:

            printf("\n\t\t\t\t\t\t\t   ### Order menu ###\n");
            //FILE *ptr;
                //displayList(heada);
                fp=fopen("C:\\Users\\Ajinkya\\OneDrive\\Documents\\Data Structure\\CP\\menu.txt","r");
                char buffer[BUFFER_SIZE];
                int totalRead = 0;
                if(fp == NULL)
                {
                    /* Unable to open file hence exit */
                    printf("Unable to open file.\n");
                    printf("Please check whether file exists and you have read privilege.\n");
                    exit(EXIT_FAILURE);
                }
                printf("File opened successfully. Reading file contents line by line. \n\n");


                /* Repeat this until read line is not NULL */
                while(fgets(buffer, BUFFER_SIZE, fp) != NULL)
                {
                    /* Total character read count */
                    totalRead = strlen(buffer);


                    /*
                     * Trim new line character from last if exists.
                     */
                    buffer[totalRead - 1] = buffer[totalRead - 1] == '\n'
                                            ? '\0'
                                            : buffer[totalRead - 1];


                    /* Print line read on cosole*/
                    printf("%s\n", buffer);

                }


                /* Done with this file, close file to release resource */
                fclose(fp);


                break;

            default:
            printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
            break;


        }
    }
}

void customer(){
    int flag=0,j=1;
    char ch;
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t    CUSTOMER SECTION\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1){
        customermenu();

        int opt;
        scanf("%d",&opt);

        if(opt==6){
            break;
        }
        int choice=1;
        switch(opt){
            case 1:
                 choice = 1;

                while(choice == 1){
                    //displayList(heada);
                    fp=fopen("D:\\DSCourseProject\\menu.txt","r");
                    int num1;
                    char name1[50];
                    float price1;

                    // Open the file in read mode


                    // Read and print each record in the file
                    while (fscanf(fp, "%d %[^\n] %f", &num1, name1, &price1) ==3) {
                        printf("%d %s %0.2f\n", num1, name1, price1);
                    }

                    // Close the file
                    fclose(fp);
                    printf("\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ");
                    int n;
                    scanf("%d",&n);
                    printf("\t\t\t\t\t\tEnter quantity: ");
                    int quantity;
                    scanf("%d",&quantity);
                    headc = createcustomer(headc,n,quantity);
                    printf("\t\t\t\t\t\tEnter 1 to add more items: ");
                    scanf("%d",&choice);
                }
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t  ### List of ordered items ###\n");
                displayList(headc);
                break;
            case 3:
                if(deletecustomer())
                {
                    printf("\n\t\t\t\t\t\t### Updated list of your ordered food items ###\n");
                    displayList(headc);
                }
                else
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!!\n");
                break;
            case 4:
                headc = deleteList(headc);
                break;
            case 5:
                calculatetotsales();
                printf("\n\t\t\t\t\t\t\t  ### Final Bill ###\n");
                displaybill();
                headc = deleteList(headc);
                feedback();
                printf("\n\t\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t\t");
                fflush(stdin);
                ch=fgetc(stdin);
                flag=1;
                break;

            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
        if(flag==1)
            break;
    }
}



void mainMenu()
{
    printf("\n                                 **************************\n");
    printf("                                                     RESTAURANT MANAGEMENT SYSTEM BY G5\n");
    printf("                                 **************************\n\n\n");
    printf("\t\t\t\t\t\t\t1. ADMIN SECTION--> \n");
    printf("\t\t\t\t\t\t\t2. CUSTOMER SECTION--> \n");
    printf("\t\t\t\t\t\t\t3. Exit--> \n\n");
    printf("\t\t\t\t\t\t\tPlease Enter Your Choice --->");
}


int main()
{
    heada=createadmin(heada,1,"Tomato Soup",90);
    heada=createadmin(heada,2,"Mango Juice",60);
    while(1)
    {
        mainMenu();
        int choice;
        scanf("%d",&choice);

        if(choice==3)
        {
            printf("\n\n\t\t\t\t\t\t\t**Thank you!!**\n");
            break;
        }

        switch(choice)
        {
            case 1:
                admin();
                break;
            case 2:
                customer();
                break;
            case 3:
                break;
            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
    }


    return 0;
}
