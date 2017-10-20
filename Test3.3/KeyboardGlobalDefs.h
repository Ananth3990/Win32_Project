#pragma once
#include<Windows.h>
TCHAR *Keyboard[5] = { TEXT("Select Company"),TEXT("Yamaha"),TEXT("KORG"),TEXT("Roland"),0 };

TCHAR *YamahaKeyboard[3] = { TEXT("Wired"),TEXT("Wireless"),0 };
TCHAR *YamahaKeyboardPrice[3] = { TEXT("560"),TEXT("900"),0 };
TCHAR *KorgKeyboard[3] = { TEXT("Wired"),TEXT("Wireless"),0 };
TCHAR *KorgKeyboardPrice[3] = { TEXT("780"),TEXT("670"),0 };
TCHAR *RolandKeyboard[3] = { TEXT("Wired"),TEXT("Wireless"),0 };
TCHAR *RolandKeyboardPrice[3] = { TEXT("546"),TEXT("200"),0 };

struct KeyboardInfo *ki;

BOOL all_ok_with_keyboard = FALSE;

