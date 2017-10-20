#pragma once
#include<Windows.h>
TCHAR *GraphicCards[5] = { TEXT("Select Company"), TEXT("AMD"),TEXT("NVIDIA"),TEXT("Zotac"),0 };

TCHAR *GraphicCardsNvidia[5] = { TEXT("GeForce GTX 1050"), TEXT("GeForce GTX 1060"),TEXT("GeForce GTX 1080"),TEXT("GeForce GTX 1080 Ti"),0 };
TCHAR *GraphicCardsAMD[4] = { TEXT("AMD Radeon R7 240"),TEXT("AMD Radeon R9 280X"),TEXT("AMD Radeon Pro Duo"),0 };
TCHAR *GraphicCardsZotac[4] = { TEXT("Zotac NVIDIA GT 730"),TEXT("Zotac NVIDIA GT 1050 TI"),TEXT("Zotac NVIDIA GT 1050"),0 };

TCHAR *GraphicCardsNvidiaPrice[5] = { TEXT("8270"),TEXT("6789"),TEXT("2345"),TEXT("4567"),0 };
TCHAR *GraphicCardsAMDPrice[4] = { TEXT("5654"),TEXT("2478"),TEXT("9087"),0 };
TCHAR *GraphicCardsZotacPrice[4] = { TEXT("5689"),TEXT("5432"),TEXT("7654"),0 };

struct GraphicCardInfo *gi;

BOOL all_ok_with_graphiccard=FALSE;
