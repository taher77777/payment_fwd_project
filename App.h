/*************************************************************************/
/*************************************************************************/
/************************** Name: Taher Mohamed **************************/
/************************** File name: App.h    **************************/
/*************************************************************************/
/*************************************************************************/

/* file guard */
#ifndef _APP_H
#define _APP_H

/* includes */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "STD_TYPE.h"
#include "Card.h"
#include "Terminal.h"
#include "Server.h"

extern transaction_t transData[255];
extern accountsDB_t accountRefrence[255];

void appStart(void);

#endif

