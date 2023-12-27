/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed   ************************/
/************************** File name: Terminal.h ************************/
/*************************************************************************/
/*************************************************************************/

/* file guard */
#ifndef _TERMINAL_H
#define _TERMINAL_H

/* includes */
#include <stdio.h>
#include <string.h>
#include "card.h"
#include "STD_TYPE.h"

/*structure data type to store terminal  information */
typedef struct  {
    f32 transAmount;
    f32 maxTransAmount;
    u8 transactionDate[6];
} Terminal_t;

/* Terminal errors*/
typedef enum TerminalError_t {
    Ok,
    WRONG_DATE,
    EXPIRED_CARD,
    INVALID_CARD,
    INVALID_AMOUNT,
    EXCEED_MAX_AMOUNT,
    INVALID_MAX_AMOUNT
} TerminalError_t;

/*func to get TransactionDate */
TerminalError_t getTransactionDate(Terminal_t* ptrCopyTermData);
/*func to check TransactionDate */
TerminalError_t isCardExpired(CARD_t* ptrCopyCardData,Terminal_t* ptrCopyTermData);
/*Set max Amount to one transaction*/
TerminalError_t setMaxAmount(Terminal_t* ptrCopyTermData);
/*func to get Transaction Amount */
TerminalError_t getTransactionAmount(Terminal_t* ptrCopyTermData);
/*func to check Amount is valid      */
TerminalError_t isBelowMaxAmount(Terminal_t* ptrCopyTermData);

#endif