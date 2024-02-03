#include<stdio.h>
#include<math.h>

int n;
int mainStackTop = -1;

struct stack{
    char name;
    char payee[15];
    double cost[15];
    int top;
} person[10];



struct MainStack{
    double cost;
    double payee;
} mainStack[20];

void pushMain(double cost, char name)
{
    mainStackTop++;
    mainStack[mainStackTop].cost = cost;
    mainStack[mainStackTop].payee = name; 
}



// void pushcost(double price, char Name, int destination)
// {
//     person[destination].payee[]
// }

int main()
{
    char title[25];
    char tperson1;
    char tperson2;
    double tcost;
    char cont;
    
    int nameFlag = 0;

    printf("Enter the title of the trip: ");
    scanf("%s",title);

    printf("Enter the number of people: ");
    scanf("%d",&n);

    printf("Enter %d names in the form of one characetr each for a person (maybe initals): ",n);
    for(int i = 0; i < n; i++) {
        scanf(" %c",&tperson1);

        person[i].name = tperson1;
        person[i].top = -1;
    }

    
    int j = 0;

    name_mismatch:
    printf("Enter the person who bore the expense: ");
    scanf(" %c", &tperson2);

    for(int i = 0; i < n; i++) {
        if(tperson2 == person[i].name) {
            nameFlag = 1;
        }
    }
    if(nameFlag == 0) {
        printf("The person you have entered doesnt exist, please try again\n");
        goto name_mismatch;
    }
    nameFlag = 0;

    printf("Enter the cost %c bore: ",tperson2);
    scanf("%lf", &tcost);

    pushMain(tcost,tperson2);

    
    printf("Do you want to Enter more data? Y or N? ");
    ask_data:
    scanf(" %c",&cont);
    
    if(cont == 'Y' || cont == 'y') {
        goto name_mismatch;
    } else if(cont != 'N' || cont != 'n') {
        printf("Invalid output, Enter Y or N: ");
        goto ask_data;
    }    

    
    
    printf("%s",title);


    return 0;
}