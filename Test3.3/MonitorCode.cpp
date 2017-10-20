#include <Windows.h>
#include "resource.h"
#include "MonitorGlobalShare.h"

extern HWND ghwnd;

static void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str)
{
	HWND proc;
	SendDlgItemMessage(hDlg, comboId, CB_RESETCONTENT, 0, 0);

	SetFocus(GetDlgItem(hDlg, comboId));
	proc = GetDlgItem(hDlg, comboId);
	if (proc != NULL)
	{
		for (int i = 0; *(str + i) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(str + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, comboId), SW_SHOWNORMAL);
}

static void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str)
{
	HWND proc;

	SendDlgItemMessage(hDlg, comboId, CB_RESETCONTENT, 0, 0);

	SetFocus(GetDlgItem(hDlg, comboId));
	proc = GetDlgItem(hDlg, comboId);
	if (proc != NULL)
	{
		SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)*str);
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, comboId), SW_SHOWNORMAL);
	SendDlgItemMessage(hDlg, IDOK, BM_CLICK, (WPARAM)0, (LPARAM)0);
}


BOOL MonitorDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int ItemIndex;
	TCHAR ListItem[256];
	int index;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			break;

		case IDCANCEL:
			break;
		}

		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE:
			switch (LOWORD(wParam))
			{
			case  LB_Monitor:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				MessageBox(NULL, TEXT("LB_Monitor"), TEXT("Message"), MB_OK);

				ShowWindow(GetDlgItem(hDlg, LB_Monitor2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_Monitor1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Monitor2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Sony")) == 0)
					{
						MessageBox(NULL, TEXT("Sony"), TEXT("Message"), MB_OK);
						AddStringsinSpecifiedComboBox(hDlg, LB_Monitor1, SonyMonitor);
					}
					else if (wcscmp(ListItem, TEXT("Dell")) == 0)
					{
						MessageBox(NULL, TEXT("Dell"), TEXT("Message"), MB_OK);
						AddStringsinSpecifiedComboBox(hDlg, LB_Monitor1, DellMonitor);
					}
					else if (wcscmp(ListItem, TEXT("HP")) == 0)
					{
						MessageBox(NULL, TEXT("HP"), TEXT("Message"), MB_OK);
						AddStringsinSpecifiedComboBox(hDlg, LB_Monitor1, HPMonitor);
					}
				}
				break;

			case LB_Monitor1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				MessageBox(NULL, TEXT("LB_Monitor1"), TEXT("Message"), MB_OK);

				if (wcscmp(ListItem, TEXT("Sony Bravia")) == 0)
				{
					MessageBox(NULL, TEXT("Sony Bravia"), TEXT("Message"), MB_OK);
					AddStringinSpecifiedComboBox(hDlg, LB_Monitor2, (SonyMonitorprice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Sony XAV")) == 0)
				{
					MessageBox(NULL, TEXT("Sony XAV"), TEXT("Message"), MB_OK);
					AddStringinSpecifiedComboBox(hDlg, LB_Monitor2, (SonyMonitorprice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Sony XLM")) == 0)
				{
					MessageBox(NULL, TEXT("Sony XLM"), TEXT("Message"), MB_OK);
					AddStringinSpecifiedComboBox(hDlg, LB_Monitor2, (SonyMonitorprice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Dell MSD14")) == 0)
				{
					MessageBox(NULL, TEXT("Dell MSD14"), TEXT("Message"), MB_OK);
					AddStringinSpecifiedComboBox(hDlg, LB_Monitor2, (DellMonitorprice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Dell 12216HV")) == 0)
				{
					MessageBox(NULL, TEXT("Dell 12216HV"), TEXT("Message"), MB_OK);
					AddStringinSpecifiedComboBox(hDlg, LB_Monitor2, (DellMonitorprice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Dell SE2216H")) == 0)
				{
					MessageBox(NULL, TEXT("Dell 12216HV"), TEXT("Message"), MB_OK);
					AddStringinSpecifiedComboBox(hDlg, LB_Monitor2, (DellMonitorprice + 2));
				}
					break;

			case LB_Monitor2:
				break;
				}
				break;

			case CBN_KILLFOCUS:
				switch (LOWORD(wParam))
				{
				case  LB_Monitor:
					index = SendMessage(GetDlgItem(hDlg, LB_Monitor), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
					(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)moni->Company); //string in above got index is got here
					wcscpy_s(moni->Price, TEXT("-"));
					break;

				case LB_Monitor1:
					index = SendMessage(GetDlgItem(hDlg, LB_Monitor1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
					(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)moni->Product); //string in above got index is got here
					break;

				case LB_Monitor2:
					index = SendMessage(GetDlgItem(hDlg, LB_Monitor2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
					(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)moni->Price); //string in above got index is got here	
					break;
				}
				break;
			}
			return TRUE;
			break;
		}
		return FALSE;
}