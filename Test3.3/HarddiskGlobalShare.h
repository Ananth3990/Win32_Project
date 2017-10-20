#pragma once
#include<Windows.h>

extern BOOL HardDiskDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

extern TCHAR *HardDisk[7];
extern TCHAR *HardDiskSize[4];
extern TCHAR* WesternDigitalPrice[4];
extern TCHAR* SeagatePrice[4];

extern struct HardDiskInfo *hi;

extern BOOL all_ok_for_harddisk;


