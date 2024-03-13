/*
A simple bank management system :
features:
  - create bank account (asks for account number , name , opening balance, password])
  - delete bank account (requires to enter password )
  - search for account details using account number and name 
  - transfer amount from one account to other (requires sender account to enter password)
  - withdraw amount (requires to enter password)
  - deposit amount
*/ 

#include <stdio.h>
#include <string.h>

#define MAX_BANK_ACCOUNTS 100
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 10

typedef struct {
    char account_Holder_Name[NAME_LENGTH];
    char account_Password[PASSWORD_LENGTH];
    int accountNumber;
    double balance;
} bankAccount;

typedef struct{
    bankAccount accounts[MAX_BANK_ACCOUNTS];
    int num_Accounts;
} bank;


// Function To handle Customer tasks 

void customerTasks( int customer_account_number){
    int index_of_account;
    char entered_password[PASSWORD_LENGTH];
    if(searchForAccount(customer_account_number)){
        index_of_account = searchForAccount(customer_account_number);
        printf("Enter the password of your account : ");
        scanf("%s",entered_password);
        if(strcmp(entered_password, bank.accounts[index_of_account].account_Password)== 0){
            printf("Login Successful !! \n");
            customerPortal(bank.accounts[index_of_account]);
        }
        else{
            printf("Access denied");
        }
    }
    else{
        printf("Account with account number %d not found.\n", customer_account_number);
    }
}


// function to enter customer portal 

void customerPortal(bank customerAccount){
    int choice;
            do {
                printf("\nCustomer Options:\n");
                printf("1. View Balance\n");
                printf("2. Withdraw\n");
                printf("3. Transfer Balance\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Your account balance: %.2f\n", accounts[i].balance);
                        break;
                    case 2:
                        // Withdraw function 
                        
                        break;
                    case 3:
                        // Transfer balance function
                        break;
                    case 4:
                        printf("Exiting customer tasks.\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            } while (choice != 4);
}

// Function to handle admin tasks
void adminTasks() {
    int choice_for_tasks;
    int search_account_number, delete_account_number;

    printf("Welcome Admin\n");
    do {
        printf("\nWhat would You Like To Do:\n");
        printf("1. Create a Account\n");
        printf("2. Search for Account\n");
        printf("3. Delete Account\n");
        printf("4. See all Account\n");
        printf("5. Exit\n");
        scanf("%d", &choice_for_tasks);

        switch (choice_for_tasks) {
            case 1:
                if (createAccount()) {
                    printf("Account Creation Successful\n");
                } else {
                    printf("Failed to Create Account\n");
                }
                break;
            case 2:
                printf("Enter the account number: ");
                scanf("%d", &search_account_number);
                if (searchForAccount(search_account_number)) {
                    printf("Yes the account exists\n");
                } else {
                    printf("There is no account with such Details !!\n");
                }
                break;
            case 3:
                printf("Enter the Account Number of the account you want to delete: ");
                scanf("%d", &delete_account_number);
                if (deleteAccount(delete_account_number)) {
                    printf("Account deletion was successful\n");
                } else {
                    printf("Account Deletion Failed\n");
                }
                break;
            case 4:
                displayAllAccounts();
                break;
            case 5:
                printf("Sad to see you go, admin!\n");
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice_for_tasks != 5);
}


// main function 

int main() {
    int choice_to_login;
    char admin_password[] = "ni@sc@ha@l";
    char entered_password[PASSWORD_LENGTH];
    int customer_account_number;

    do {
        printf("Welcome to Nepal Rastra Bank\n");
        printf("\n1. Login as admin\n2. Login as Customer\n3. Deposit\n4. Exit\n");
        scanf("%d", &choice_to_login);

        switch (choice_to_login) {
            // If the user is a Admin
            case 1: {
                printf("Enter the admin password: ");
                scanf("%s", entered_password);
                if (strcmp(entered_password, admin_password) == 0) {
                    adminTasks();
                } else {
                    printf("Access denied !!\n");
                }
                break;
            }

            // If the user is a customer 
            case 2:{

                printf("Welcome to the Customer Portal\n");
                printf("Enter your account number: ");
                scanf("%d", &customer_account_number);
                customerTasks(customer_account_number);
                break;
            }


            //the user just wants to deposit money
            case 3:
                deposit();
                break;

                // the user wants to exist
            case 4:
                printf("Exiting program.\n");
                return 0;

                //Input input from User
            default:
                printf("Invalid input\n");
                break;
        }
    } while (1);

    return 0;
}