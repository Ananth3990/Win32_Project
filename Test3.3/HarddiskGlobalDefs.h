#pragma once
#include<Windows.h>

TCHAR *HardDisk[4] = { TEXT("Select Company"),TEXT("Western Digital"),TEXT("Seagate"),0 };
TCHAR *HardDiskSize[4] = { TEXT("500GB"),TEXT("1TB"),TEXT("2TB"),0 };
TCHAR* WesternDigitalPrice[4] = { TEXT("2345"),TEXT("6789"),TEXT("3256"),0 };
TCHAR* SeagatePrice[4] = { TEXT("4567"),TEXT("8970"),TEXT("9000"),0 };

struct HardDiskInfo *hi;

BOOL all_ok_for_harddisk=FALSE;
