#include <stdio.h>
#include <string.h>

struct Customer
{
    char name[30];
    char vehicleNo[20];
    int vehicle;
    int service;
    int payment;
    int charge;
    float amountPaid;
};

union Payment
{
    float cash;
    char upi[30];
    char card[20];
};

int main()
{
    struct Customer c[50];
    union Payment p[50];

    char username[20], password[20];
    int attempt = 0, login = 0;
    int n = 0, i, j, choice, pos;
    float totalIncome, totalCharge, balance;
    int billNo;

    printf("================================\n");
    printf("       GARAGE MANAGEMENT\n");
    printf("             LOGIN\n");
    printf("================================\n");

    while(attempt < 3)
    {
        printf("\nEnter Username: ");
        scanf("%s", username);

        printf("Enter Password: ");
        scanf("%s", password);

        if(strcmp(username, "prakruthi") == 0 &&
           strcmp(password, "1234") == 0)
        {
            printf("\nLogin Successful!\n");
            login = 1;
            break;
        }
        else
        {
            attempt++;
            printf("Wrong Username or Password!\n");
            printf("Attempts remaining: %d\n", 3 - attempt);
        }
    }

    if(login == 0)
    {
        printf("\nAccess Denied!\n");
        return 0;
    }

    do
    {
        printf("\n================================\n");
        printf("    GARAGE MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Add Customer\n");
        printf("2. View All Customers\n");
        printf("3. Delete Customer\n");
        printf("4. Exit\n");
    
        printf("5. Generate Bill\n");
        printf("6. Garage Income Report\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(n == 50)
                {
                    printf("Customer limit reached!\n");
                    break;
                }

                i = n;

                printf("\nEnter Customer Name: ");
                scanf("%s", c[i].name);

                printf("Enter Vehicle Number: ");
                scanf("%s", c[i].vehicleNo);

                do
                {
                    printf("\nSelect Vehicle\n");
                    printf("1. Bike\n");
                    printf("2. Car\n");
                    printf("3. Auto\n");
                    printf("Enter choice: ");
                    scanf("%d", &c[i].vehicle);

                    if(c[i].vehicle < 1 || c[i].vehicle > 3)
                        printf("Invalid choice!\n");

                } while(c[i].vehicle < 1 || c[i].vehicle > 3);

                do
                {
                    printf("\nSelect Service\n");
                    printf("1. Oil Change - Rs.500\n");
                    printf("2. Brake Service - Rs.1000\n");
                    printf("3. Engine Service - Rs.3000\n");
                    printf("4. General Service - Rs.1500\n");
                    printf("Enter choice: ");
                    scanf("%d", &c[i].service);

                    if(c[i].service < 1 || c[i].service > 4)
                        printf("Invalid choice!\n");

                } while(c[i].service < 1 || c[i].service > 4);

                switch(c[i].service)
                {
                    case 1: c[i].charge = 500; break;
                    case 2: c[i].charge = 1000; break;
                    case 3: c[i].charge = 3000; break;
                    case 4: c[i].charge = 1500; break;
                }

                do
                {
                    printf("\nPayment Method\n");
                    printf("1. Cash\n");
                    printf("2. UPI\n");
                    printf("3. Card\n");
                    printf("Enter choice: ");
                    scanf("%d", &c[i].payment);

                    if(c[i].payment < 1 || c[i].payment > 3)
                        printf("Invalid choice!\n");

                } while(c[i].payment < 1 || c[i].payment > 3);

                switch(c[i].payment)
                {
                    case 1:
                        printf("Enter Cash Amount: ");
                        scanf("%f", &p[i].cash);
                        c[i].amountPaid = p[i].cash;
                        break;

                    case 2:
                        printf("Enter UPI ID: ");
                        scanf("%s", p[i].upi);
                        printf("Enter Amount Paid: ");
                        scanf("%f", &c[i].amountPaid);
                        break;

                    case 3:
                        printf("Enter Card Number: ");
                        scanf("%s", p[i].card);
                        printf("Enter Amount Paid: ");
                        scanf("%f", &c[i].amountPaid);
                        break;
                }

                n++;
                printf("\nCustomer Added Successfully!\n");
                break;

            case 2:
                if(n == 0)
                {
                    printf("\nNo Customers Available!\n");
                    break;
                }

                printf("\n========== CUSTOMER LIST ==========\n");

                for(i = 0; i < n; i++)
                {
                    printf("\nCustomer Number: %d\n", i + 1);
                    printf("Name: %s\n", c[i].name);
                    printf("Vehicle Number: %s\n", c[i].vehicleNo);

                    switch(c[i].vehicle)
                    {
                        case 1: printf("Vehicle: Bike\n"); break;
                        case 2: printf("Vehicle: Car\n"); break;
                        case 3: printf("Vehicle: Auto\n"); break;
                    }

                    switch(c[i].service)
                    {
                        case 1: printf("Service: Oil Change\n"); break;
                        case 2: printf("Service: Brake Service\n"); break;
                        case 3: printf("Service: Engine Service\n"); break;
                        case 4: printf("Service: General Service\n"); break;
                    }

                    printf("Service Charge: Rs.%d\n", c[i].charge);

                    switch(c[i].payment)
                    {
                        case 1:
                            printf("Payment: Cash\n");
                            break;
                        case 2:
                            printf("Payment: UPI\n");
                            printf("UPI ID: %s\n", p[i].upi);
                            break;
                        case 3:
                            printf("Payment: Card\n");
                            printf("Card Number: %s\n", p[i].card);
                            break;
                    }

                    printf("Amount Paid: Rs.%.2f\n", c[i].amountPaid);

                    if(c[i].amountPaid >= c[i].charge)
                        printf("Change: Rs.%.2f\n",
                               c[i].amountPaid - c[i].charge);
                    else
                        printf("Balance Due: Rs.%.2f\n",
                               c[i].charge - c[i].amountPaid);

                    printf("-----------------------------------\n");
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("\nNo Customers to Delete!\n");
                    break;
                }

                printf("\nEnter Customer Number to Delete (1-%d): ", n);
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid Customer Number!\n");
                    break;
                }

                pos--;

                for(j = pos; j < n - 1; j++)
                {
                    c[j] = c[j + 1];
                    p[j] = p[j + 1];
                }

                n--;
                printf("\nCustomer Deleted Successfully!\n");
                break;

            case 4:
                printf("\nThank You for Using Garage Management System!\n");
                break;

            case 5:
                if(n == 0)
                {
                    printf("\nNo Customers Available!\n");
                    break;
                }

                printf("\nEnter Customer Number for Bill (1-%d): ", n);
                scanf("%d", &billNo);

                if(billNo < 1 || billNo > n)
                {
                    printf("Invalid Customer Number!\n");
                    break;
                }

                i = billNo - 1;

                printf("\n================================\n");
                printf("          GARAGE BILL\n");
                printf("================================\n");
                printf("Customer Number: %d\n", billNo);
                printf("Customer Name: %s\n", c[i].name);
                printf("Vehicle Number: %s\n", c[i].vehicleNo);

                switch(c[i].vehicle)
                {
                    case 1: printf("Vehicle: Bike\n"); break;
                    case 2: printf("Vehicle: Car\n"); break;
                    case 3: printf("Vehicle: Auto\n"); break;
                }

                switch(c[i].service)
                {
                    case 1: printf("Service: Oil Change\n"); break;
                    case 2: printf("Service: Brake Service\n"); break;
                    case 3: printf("Service: Engine Service\n"); break;
                    case 4: printf("Service: General Service\n"); break;
                }

                printf("--------------------------------\n");
                printf("Service Charge: Rs.%d\n", c[i].charge);
                printf("Amount Paid: Rs.%.2f\n", c[i].amountPaid);

                if(c[i].amountPaid >= c[i].charge)
                {
                    printf("Balance Due: Rs.0.00\n");
                    printf("Change: Rs.%.2f\n",
                           c[i].amountPaid - c[i].charge);
                }
                else
                {
                    printf("Balance Due: Rs.%.2f\n",
                           c[i].charge - c[i].amountPaid);
                }

                switch(c[i].payment)
                {
                    case 1: printf("Payment Method: Cash\n"); break;
                    case 2: printf("Payment Method: UPI\n"); break;
                    case 3: printf("Payment Method: Card\n"); break;
                }

                printf("================================\n");
                printf("       Thank You!\n");
                printf("================================\n");
                break;

            case 6:
                totalIncome = 0;
                totalCharge = 0;
                balance = 0;

                for(i = 0; i < n; i++)
                {
                    totalCharge = totalCharge + c[i].charge;

                    if(c[i].amountPaid < c[i].charge)
                    {
                        totalIncome = totalIncome + c[i].amountPaid;
                        balance = balance + c[i].charge - c[i].amountPaid;
                    }
                    else
                    {
                        totalIncome = totalIncome + c[i].charge;
                    }
                }

                printf("\n================================\n");
                printf("       GARAGE INCOME REPORT\n");
                printf("================================\n");
                printf("Total Customers: %d\n", n);
                printf("Total Service Charges: Rs.%.2f\n", totalCharge);
                printf("Total Income: Rs.%.2f\n", totalIncome);
                printf("Total Balance Due: Rs.%.2f\n", balance);
                printf("================================\n");
                break;

            default:
                printf("\nInvalid Menu Choice!\n");
        }

    } while(choice != 4);

    return 0;
}
