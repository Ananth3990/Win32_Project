#pragma once
#include<Windows.h>
TCHAR *Mouse[5] = { TEXT("Select Company"),TEXT("Logitech"),TEXT("Asus"),TEXT("Corsair"),0};
TCHAR *CorsairMouse[3] = { TEXT("Wired"),TEXT("Wireless"),0 };
TCHAR *LogitechMouse[3] = { TEXT("Wired"),TEXT("Wireless"),0 };
TCHAR *AsusMouse[3] = { TEXT("Wired"),TEXT("Wireless"),0 };
TCHAR *CorsairMousePrice[3] = { TEXT("3000"),TEXT("4000"),0 };
TCHAR *LogitechMousePrice[3] = { TEXT("1000"),TEXT("2000"),0 };
TCHAR *AsusMousePrice[3] = { TEXT("5000"),TEXT("6000"),0 };


struct MouseInfo *moi;

BOOL all_ok_with_mouse = FALSE;
