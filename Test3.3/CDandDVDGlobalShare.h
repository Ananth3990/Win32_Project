#pragma once
#include<Windows.h>

extern BOOL CDAndDVDDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

extern TCHAR *CDAndDVD[5];

extern TCHAR *AMWCDAndDVD[5];
extern TCHAR *AstradCDAndDVD[5];
extern TCHAR *AcroxCDAndDVD[5];
extern TCHAR *AMWCDAndDVDPrice[5];
extern TCHAR *AstradCDAndDVDPrice[5];
extern TCHAR *AcroxCDAndDVDPrice[5];

extern struct CDandDVDInfo *cd;

extern BOOL all_ok_with_cdanddvd;

