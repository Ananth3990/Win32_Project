#pragma once
#include <Windows.h>
TCHAR *Ram[6] = { TEXT("Select Company"),TEXT("Corsair"),TEXT("G.Skill"),TEXT("OCZ"),TEXT("Muskin"),0 };

TCHAR *RamSize[4] = { TEXT("4GB"),TEXT("8GB"),TEXT("16GB"),0 };
TCHAR *CorsairPrice[4] = { TEXT("100"),TEXT("101"),TEXT("102"),0};
TCHAR *GSkillPrice[4] = { TEXT("104"),TEXT("105"),TEXT("106"),0 };
TCHAR *OCZPrice[4] = { TEXT("108"),TEXT("109"),TEXT("110"),0 };
TCHAR *MuskinPrice[4] = { TEXT("112"),TEXT("113"),TEXT("114"),0 };

struct RamInfo *ri;

BOOL all_ok_for_ram = FALSE;