/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed   ************************/
/************************** File name: server.c   ************************/
/*************************************************************************/
/*************************************************************************/
/*includes*/
#include "server.h"
#include "card.h"
#include "terminal.h"

/*Local data base*/
/*data base*/
accountsDB_t accountRefrence[255] = {
    {1620.0F, RUNNING, "5170770054625604"},
    {127000.0F, BLOCKED, "5170770054628566"},
    {191000.0F, RUNNING, "5170770054628061"},
    {1210000.0F, BLOCKED, "5170770054625323"},
    {1490000.0F, RUNNING, "5170770054625745"},
    {1780000.0F, RUNNING, "5170770054621355"},
    {163000.0F, BLOCKED, "5170770054623138"},
    {9000.0F, RUNNING, "5170770054626560"},
    {9000.0F, BLOCKED, "5170770054627436"},
    {1220000.0F, RUNNING, "5170770054625638"},
    {150000.0F, BLOCKED, "5170770054620720"},
    {1790000.0F, RUNNING, "5170770054625778"} };

    /*data base to transactions*/
    transaction_t transData[255] = { {0} };
    /*running acount index*/
    u8 globalindex=-1;
    /*last seg number*/
    u8 lastsegnum=-1;

TransStat_t recieveTransactionData(transaction_t* ptrtransData)
{   

    if((isValidAccount(&(ptrtransData->cardHolderData)))==ACCOUNT_NOT_FOUND)
    {
        return DECLINED_STOLEN_CARD ;
    }

    else if ((isBlockedAccount())==BLOCKED_ACCOUNT)
    {
        return FRAUD_CARD;
    }

   else if ((isAmountAvailable(&(ptrtransData->terminalData)))==LOW_BALANCE)
    {
        return DECLINED_INSUFFECIENT_FUND;
    }

    else if ((saveTransaction(ptrtransData))!=SERVER_OK)
    {
        return INTERNAL_SERVER_ERROR;
    }
    return APPROVED;
}


/*is valid account */
serverError_t isValidAccount(CARD_t* ptrcardHolderData)
{
       u8 u8index = -1;
       u8 u8local_counter=0;
       //u8 pan[20];
       //strcpy(pan, ptrcardHolderData->CARD_PAN_Number);
    for ( u8local_counter = 0; u8local_counter < 255; u8local_counter++) {
        if (0==strcmp(ptrcardHolderData->CARD_PAN_Number, accountRefrence[u8local_counter].primaryAccountNumber)) 
        {
            u8index = u8local_counter;
            break;

        }
    }

    if (u8index < 0) 
    {

        //printf("ACCOUNT_NOT_FOUND\n");
        return ACCOUNT_NOT_FOUND;
    }
    else 
    {

       // printf("SERVER_OK : valid account\n");
        globalindex=u8index;
        return SERVER_OK;
    }

}


/*is account blocked*/
serverError_t isBlockedAccount(void)
{
    if (accountRefrence[globalindex].state == BLOCKED) {
        printf("BLOCKED_ACCOUNT\n");
        return BLOCKED_ACCOUNT;
    }
    else {
        printf("SERVER_OK : Running account\n");
        return SERVER_OK;
    }

}
/*check the amount is available*/
serverError_t isAmountAvailable(Terminal_t* ptrterminalData)
{
    if (ptrterminalData->transAmount > accountRefrence[globalindex].balance) {
        printf("LOW_BALANCE\n");
        return LOW_BALANCE;
    }
    else {
        printf("SERVER_OK : amount valid\n");
        return SERVER_OK;
    }
}


/*when any transaction accured will stored*/
serverError_t saveTransaction(transaction_t* ptrtransData)
{
    static u8 count=0;
    /* either trans limit reached OR cant save */
    if (count == 255) {
        puts("INTERNAL_SERVER_ERROR\n"); 
        /* func failed*/
        return SAVING_FAILED;
    }


    transData[count].cardHolderData = ptrtransData->cardHolderData;
    transData[count].terminalData = ptrtransData->terminalData;
    transData[count].transState=ptrtransData->transState;
    transData[count].transactionSequenceNumber=(ptrtransData->transactionSequenceNumber)+1;


    if (count + 1 == 255)
        puts("WARNING! you can't make more transactions after this \n "
            "i.e.(max transaction limit reached)\n");

    puts("transaction saved\n");
    lastsegnum=transData[count].transactionSequenceNumber;
    return SERVER_OK;
}



void listSavedTransactionsTest()
{       
    u8 count =0;
    if(lastsegnum>-1)
    {
        for(count=0;count<=lastsegnum;count++)
        {
        printf("\n***********************\n ");
        printf(" CARD Holder name : %s\n", transData[count].cardHolderData.CARD_Holder_Name);
        printf(" CARD PAN num : %s \n", transData[count].cardHolderData.CARD_PAN_Number);
        printf(" Card expiry date : %s\n", transData[count].cardHolderData.CARD_Expiry_Date);
        printf(" transaction date : %s\n", transData[count].terminalData.transactionDate);
        printf(" transaction amount : %0.2f \n", transData[count].terminalData.transAmount);
        printf(" Max amount : %0.2f\n",transData[count].terminalData.maxTransAmount);
        printf(" transaction state : %s \n",transData[count].transState);
        printf("\n***********************\n");
        }
    }
    else if (lastsegnum==-1)
    {
        printf("not found transaction\n");
    }


}
