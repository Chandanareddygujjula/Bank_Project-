#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Structure to store account information
struct Account
{
    int accountnumber;
    char name[50];
    char fathername[50];
    char aadhar[20];
    float balance;
    char mobile[10];
    char pan[20];
};

//Array to store accounts
struct Account accounts[100];
int accountcount=0;

//Generate Account Number
int randomaccountnumber()
{
    srand(time(NULL));
    return rand() %90000000000 +1000000000;
}
//Function
void createaccount();
void transfermoney();
void moneydeposit();
void moneywithdrawl();
void accountclose();
void balanceenquiry();

int main()
{
    // Function to display the menu
    printf("--- Banking Management System ---");
    int choice;
    while(1)
    {
    printf("\nChoose your choice :\n\n1. Create Account \n2. Transfer Money \n3. Money Deposit \n4. Money Withdrawl \n5. Account Close \n6. Balance Enquiry \n7. Exit\n\nEnter your Choice :" );
    scanf("%d",&choice);
    switch(choice) 
        {
            case 1:
                createaccount();
                break;
          
            case 7:
                return 0;
            default:
      printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

 //Function to create an Account
void createaccount()
{
    if (accountcount < 100)
    {
        printf("Enter Account Holder's Full Name: ");
        scanf(" %s", &accounts[accountcount].name);
        printf("Enter Father's Name: ");
        scanf(" %s", &accounts[accountcount].fathername);
        printf("Enter Aadhar Number: ");
        scanf("%s", &accounts[accountcount].aadhar);
        printf("Enter PAN Number: ");
        scanf("%s", &accounts[accountcount].pan);
        printf("Enter Mobile Number: ");
        scanf("%s", &accounts[accountcount].mobile);
        accounts[accountcount].accountnumber = randomaccountnumber(); // Generates a unique number
        printf("Enter Initial Balance: ");
        scanf("%f", &accounts[accountcount].balance);
        printf("\nAccount Created Successfully!\n");
        printf("Your Account Number is: %d\n", accounts[accountcount].accountnumber);
        accountcount++;
    } 
    else 
    {
        printf("\n Account Limit Reached.\n");
    }
}