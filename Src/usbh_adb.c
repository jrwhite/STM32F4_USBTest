/*
 * usbh_adb.c
 *
 *  Created on: May 28, 2018
 *      Author: jarod
 */

#include "usbh_adb.h"

#define USBH_ADB_BUFFER_SIZE	1024

static USBH_StatusTypeDef USBH_ADB_InterfaceInit  (USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_ADB_InterfaceDeInit  (USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_ADB_Process(USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_ADB_SOFProcess(USBH_HandleTypeDef *phost);

static USBH_StatusTypeDef USBH_ADB_ClassRequest (USBH_HandleTypeDef *phost);

USBH_ClassTypeDef ADB_Class =
{
		"ADB",
		USBH_ADB_CLASS,
		USBH_ADB_InterfaceInit,
		USBH_ADB_InterfaceDeInit,
		USBH_ADB_ClassRequest,
		USBH_ADB_Process,
		USBH_ADB_SOFProcess,
		NULL,
};
