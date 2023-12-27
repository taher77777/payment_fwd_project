/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed **************************/
/************************** File name: App.c    **************************/
/*************************************************************************/
/*************************************************************************/

#include "app.h"

CARD_t cardData;
Terminal_t termData;
transaction_t new_transaction;
TransStat_t recieve_err_holder;
int main() {

    u16 closeapp = -1;
    while (closeapp != 2) {
        printf("Do you want to make  transaction or view old transaction?"
            "\n 0)make new trans. \n 1)view old trans. \n 2)exit \n==>");
        scanf("%d", &closeapp);
        if (closeapp == 0)
        {
            appStart();
        }
        else if (closeapp == 1) {
           
            listSavedTransactionsTest();

        }
        else if(closeapp == 2)
        {
            printf("the program is closed \n ");

        }
        else
        {
            /* wrong inter */
            printf("wrong inter : Again \n ");
            closeapp = -1;
        }


    }

    return 0;
}

void appStart(void) {
    static u8 transaction_counter=0;
    /*CARD*/
    if (getCardHolderName(&cardData) != OK)
        return;
    if (getCardExpiryDate(&cardData) != OK)
        return;
    if (getCardPAN(&cardData) != OK)
        return;

    /*TERMINAL*/
    getTransactionDate(&termData);
    if (isCardExpired(&cardData, &termData) != Ok)
        return;
    if (setMaxAmount(&termData) != Ok)
        return;
    if (getTransactionAmount(&termData) != Ok)
        return;
    if (isBelowMaxAmount(&termData) != Ok)
        return;

    /*SERVER*/
    new_transaction.cardHolderData=cardData;
    new_transaction.terminalData=termData;
    new_transaction.transactionSequenceNumber=transaction_counter;
    recieve_err_holder = recieveTransactionData(&new_transaction);
    new_transaction.transState=recieve_err_holder;

    switch(recieve_err_holder)
    {
        case APPROVED:printf("APPROVED CARD \n");break;
        case DECLINED_INSUFFECIENT_FUND:printf("DECLINED_INSUFFECIENT_FUND \n ");break;
        case DECLINED_STOLEN_CARD:printf("DECLINED_STOLEN_CARD \n");break;
        case FRAUD_CARD:printf("FRAUD_CARD \n");break;
        case INTERNAL_SERVER_ERROR:printf("INTERNAL_SERVER_ERROR \n");break;

    }

    transaction_counter++;
    return ;
}
