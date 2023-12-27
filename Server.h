/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed   ************************/
/************************** File name:  server.h  ************************/
/*************************************************************************/
/*************************************************************************/

/* file guard */
#ifndef _SERVER_H
#define _SERVER_H

/*includes*/
#include <stdio.h>
#include <stdint.h>
#include "Card.h"
#include "Terminal.h"
#include "STD_TYPE.h"

/*server responcses to the trans */
typedef enum transState_t {
    APPROVED,//ok
    DECLINED_INSUFFECIENT_FUND,//There is not enough money
    DECLINED_STOLEN_CARD,//card is stolen
    FRAUD_CARD,//fake card
    INTERNAL_SERVER_ERROR //server crashed
} TransStat_t;

/*account status*/
typedef enum AccountState_t { RUNNING, BLOCKED } AccountState_t;

/*server error type*/
typedef enum serverError_t {
    SERVER_OK,
    SAVING_FAILED,
    TRANSACTION_NOT_FOUND,
    ACCOUNT_NOT_FOUND,
    LOW_BALANCE,
    BLOCKED_ACCOUNT
} serverError_t;

/*all information about transaction*/
typedef struct {

	CARD_t cardHolderData;
	Terminal_t terminalData;
    TransStat_t transState;
    u32 transactionSequenceNumber;
}transaction_t ;

/*Data base to server*/
typedef struct  {
    f32 balance;
    AccountState_t state;
    u8 primaryAccountNumber[20];
} accountsDB_t;

TransStat_t recieveTransactionData(transaction_t* ptrtransData);
serverError_t isValidAccount(CARD_t* ptrcardHolderData);

serverError_t isBlockedAccount( void);

serverError_t isAmountAvailable(Terminal_t* ptrterminalData);
serverError_t saveTransaction(transaction_t* ptrtransData);
void listSavedTransactionsTest(void);
#endif 


