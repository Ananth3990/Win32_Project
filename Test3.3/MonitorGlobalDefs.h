#pragma once
#include<Windows.h>
TCHAR *Monitor[5] = { TEXT("Select Company"),TEXT("Sony"),TEXT("Dell"),TEXT("HP"),0 };

TCHAR *SonyMonitor[4] = { TEXT("Sony Bravia"),TEXT("Sony XAV"),TEXT("Sony XLM"),0 };
TCHAR *SonyMonitorprice[4] = { TEXT("3456"),TEXT("5678"),TEXT("1589"),0 };
TCHAR *DellMonitor[4] = { TEXT("Dell MSD14"),TEXT("Dell 12216HV"),TEXT("Dell SE2216H"),0 };
TCHAR *DellMonitorprice[4] = { TEXT("345"),TEXT("567"),TEXT("159"),0 };
TCHAR *HPMonitor[4] = { TEXT("HP Bravia"),TEXT("HP XAV"),TEXT("HP XLM"),0 };
TCHAR *HPMonitorprice[4] = { TEXT("34"),TEXT("56"),TEXT("89"),0 };

struct MonitorInfo *moni;

BOOL all_ok_with_monitor = FALSE;
