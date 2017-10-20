#include<windows.h>
#include <CommCtrl.h>
#include<string.h>
#include "resource.h"
#include "ProcessorGlobalDefs.h"
#include "RamGlobalDefs.h"
#include "MotherboardGlobalDefs.h"
#include "HarddiskGlobalDefs.h"
#include "GraphicCardGlobalDefs.h"
#include "CDandDVDGlobalDefs.h"
#include "MonitorGlobalDefs.h"
#include"CabinetGlobalDefs.h"
#include "KeyboardGlobalDefs.h"
#include "MouseGlobalDefs.h"

#pragma comment(lib,"User32.lib")
#pragma comment (lib,"gdi32.lib")

HINSTANCE ghInstance = NULL;
HWND ghwnd;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

WNDCLASSEX ac;
MSG msg;
TCHAR szClassName[] = TEXT("Parent Window");

void InitializeProcessor(HWND hDlg);
void InitializeRam(HWND hDlg);
void InitializeMotherboard(HWND hDlg);
void InitializeHardDisk(HWND hDlg);
void InitializeGraphicCard(HWND hDlg);
void InitializeCDandDVD(HWND hDlg);
void InitializeMonitor(HWND hDlg);
void InitializeCabinet(HWND hDlg);
void InitializeKeyboard(HWND hDlg);
void InitializeMouse(HWND hDlg);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	void uninitialize(void);
	LRESULT CALLBACK AcCallBack(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

	MSG msg;

	HWND hwnd;

	ghInstance = hInstance;

	ac.cbSize = sizeof(WNDCLASSEX);
	ac.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	ac.cbClsExtra = 0;
	ac.cbWndExtra = 0;
	ac.hInstance = hInstance;
	ac.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	ac.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	ac.hCursor = LoadCursor(NULL, IDC_ARROW);
	ac.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	ac.lpfnWndProc = AcCallBack;
	ac.lpszClassName = szClassName;
	ac.lpszMenuName = NULL;


	RegisterClassEx(&ac);

	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szClassName,
		TEXT("Shree Ganesha"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (hwnd == NULL)
	{
		MessageBox(NULL, TEXT("Parent Window creation failed"), TEXT("Error"), MB_OK);
		exit(0);
	}

	ghwnd = hwnd;

	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	uninitialize();
	return ((int)msg.wParam);
}

void uninitialize(void)
{
	dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
	SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
	SetWindowPlacement(ghwnd, &wpPrev);
	SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
	ShowCursor(TRUE);
	DestroyWindow(ghwnd);
}

LRESULT CALLBACK AcCallBack(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	void uninitialize(void);
	BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

	HINSTANCE hInst;
	
	switch (iMsg)
	{
	case WM_CREATE:
		pi = (struct ProcessorInfo*)malloc(sizeof(struct ProcessorInfo));
		ri = (struct RamInfo*)malloc(sizeof(struct RamInfo));
		mi = (struct MotherBoardInfo*)malloc(sizeof(struct MotherBoardInfo));
		hi = (struct HardDiskInfo*)malloc(sizeof(struct HardDiskInfo));
		gi = (struct GraphicCardInfo*)malloc(sizeof(struct GraphicCardInfo));
		cd = (struct CDandDVDInfo*)malloc(sizeof(struct CDandDVDInfo));
		moni = (struct MonitorInfo*)malloc(sizeof(struct MonitorInfo));
		cbi = (struct CabinetInfo*)malloc(sizeof(struct CabinetInfo));
		ki = (struct KeyboardInfo*)malloc(sizeof(struct KeyboardInfo));
		moi = (struct MouseInfo*)malloc(sizeof(struct MouseInfo));
		break;
		
	case WM_PAINT:
		break;

	case WM_CLOSE:
		uninitialize();
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

		case VK_SPACE:
			hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);

			//Further task will be a call to dialog box
			DialogBox(hInst, TEXT("DataEntry"), ghwnd, MyDlgProc);

			break;

		default:
			break;
		}
		break;

	case WM_DESTROY:
		free(pi);
		pi = NULL;
		free(ri);
		ri = NULL;
		free(mi);
		mi = NULL;
		free(hi);
		hi = NULL;
		free(gi);
		gi = NULL;
		free(cd);
		cd = NULL;
		free(moni);
		moni = NULL;
		free(cbi);
		cbi = NULL;
		free(ki);
		ki = NULL;
		free(moi);
		moi = NULL;
		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL  ProcessorDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL RamDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL MotherboardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL HardDiskDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL GraphicCardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL CDAndDVDDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL MonitorDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL CabinetDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL KeyboardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL MouseDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

	TCHAR str[256];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		InitializeHardDisk(hDlg);
		InitializeMotherboard(hDlg);
		InitializeRam(hDlg);
		InitializeProcessor(hDlg);
		InitializeGraphicCard(hDlg);
		InitializeCDandDVD(hDlg);
		InitializeMonitor(hDlg);
		InitializeCabinet(hDlg);
		InitializeKeyboard(hDlg);
		InitializeMouse(hDlg);
		return TRUE;
		break;

	case WM_COMMAND:
		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE:
			switch (LOWORD(wParam))
			{
			case  LB_Processor:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor1:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor2:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor3:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram1:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram2:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard1:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard2:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk1:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk2:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard1:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard2:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD1:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD2:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor1:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor2:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet1:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet2:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard1:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard2:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse1:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse2:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;
			}
		break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Processor:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor1:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor2:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor3:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram1:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram2:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard1:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard2:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk1:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk2:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard1:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard2:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD1:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD2:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor1:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor2:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet1:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet2:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard1:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard2:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse1:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse2:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;
			}
			break;

		default:
			break;
		}

		switch (LOWORD(wParam))
		{
		case IDOK:
			MessageBox(ghwnd,TEXT("in IDOK"),TEXT("Message"),MB_OK);


			if ((wcscmp(mi->Company, TEXT("Select Company")) != 0) && (wcscmp(mi->Price, TEXT("-")) != 0))
			{
				all_ok_for_motherboard = TRUE;
			}
			else
			{
				all_ok_for_motherboard = FALSE;
			}

			if ((wcscmp(pi->Company, TEXT("Select Company")) != 0) && (wcscmp(pi->Price, TEXT("-")) != 0) && (wcscmp(pi->Generation, TEXT("-")) != 0) )
			{
				all_ok_for_processor = TRUE;
			}
			else
			{
				all_ok_for_processor = FALSE;
			}

			if ((wcscmp(ri->Company, TEXT("Select Company")) != 0) && (wcscmp(ri->Price, TEXT("-")) != 0))
			{
				all_ok_for_ram = TRUE;
			}
			else
			{
				all_ok_for_ram = FALSE;
			}

			if ((wcscmp(hi->Company, TEXT("Select Company")) != 0) && (wcscmp(hi->Price, TEXT("-")) != 0))
			{
				all_ok_for_harddisk = TRUE;
			}
			else
			{
				all_ok_for_harddisk = FALSE;
			}

			if ((wcscmp(gi->Company, TEXT("Select Company")) != 0) && (wcscmp(gi->Price, TEXT("-")) != 0))
			{
				all_ok_with_graphiccard = TRUE;
			}
			else
			{
				all_ok_with_graphiccard = FALSE;
			}

			if ((wcscmp(cd->Company, TEXT("Select Company")) != 0) && (wcscmp(cd->Price, TEXT("-")) != 0))
			{
				all_ok_with_cdanddvd = TRUE;
			}
			else
			{
				all_ok_with_cdanddvd = FALSE;
			}

			if ((wcscmp(moni->Company, TEXT("Select Company")) != 0) && (wcscmp(moni->Price, TEXT("-")) != 0))
			{
				all_ok_with_monitor = TRUE;
			}
			else
			{
				all_ok_with_monitor = FALSE;
			}

			if ((wcscmp(cbi->Company, TEXT("Select Company")) != 0) && (wcscmp(cbi->Price, TEXT("-")) != 0))
			{
				all_ok_with_cabinet = TRUE;
			}
			else
			{
				all_ok_with_cabinet = FALSE;
			}

			if ((wcscmp(ki->Company, TEXT("Select Company")) != 0) && (wcscmp(ki->Price, TEXT("-")) != 0))
			{
				all_ok_with_keyboard = TRUE;
			}
			else
			{
				all_ok_with_keyboard = FALSE;
			}

			if ((wcscmp(moi->Company, TEXT("Select Company")) != 0) && (wcscmp(moi->Price, TEXT("-")) != 0))
			{
				all_ok_with_mouse = TRUE;
			}
			else
			{
				all_ok_with_mouse = FALSE;
			}

			if (all_ok_for_processor == TRUE)
			{
				MessageBox(ghwnd, TEXT("Processor Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for Processor is %s"), pi->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("CPU for Processor is %s"), pi->CPU);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Generation for Processor is %s"), pi->Generation);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Processor is %s"), pi->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_for_ram == TRUE)
			{
				MessageBox(ghwnd, TEXT("Ram Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for Ram is %s"), ri->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Size for Ram is %s"), ri->Size);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Ram is %s"), ri->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_with_monitor == TRUE)
			{
				MessageBox(ghwnd, TEXT("Monitor Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for Monitor is %s"), moni->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for Monitor is %s"), moni->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Monitor is %s"), moni->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_for_motherboard == TRUE)
			{
				MessageBox(ghwnd, TEXT("Motherboard Details"), TEXT("Message"), MB_OK);

				wsprintf(str,TEXT("Company for Motherboard is %s"),mi->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for Motherboard is %s"), mi->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Motherboard is %s"), mi->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_for_harddisk == TRUE)
			{
				MessageBox(ghwnd, TEXT("HardDisk Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for HardDisk is %s"), hi->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Size for Harddisk is %s"), hi->Size);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Harddisk is %s"), hi->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_with_graphiccard==TRUE)
			{
				MessageBox(ghwnd, TEXT("Graphic Card Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for GraphicsCard is %s"), gi->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for GraphicsCard is %s"), gi->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for GraphicsCard is %s"), gi->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_with_cdanddvd == TRUE)
			{
				MessageBox(ghwnd, TEXT("CD and DVD Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for CD and DVD is %s"), cd->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for CD and DVD is %s"), cd->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for CD and DVD is %s"), cd->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_with_cabinet == TRUE)
			{
				MessageBox(ghwnd, TEXT("Cabinet Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for Cabinet is %s"), cbi->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for Cabinet is %s"), cbi->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Cabinet is %s"), cbi->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_with_keyboard == TRUE)
			{
				MessageBox(ghwnd, TEXT("Keyboard Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for Keyboard is %s"), ki->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for Keyboard is %s"), ki->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Keyboard is %s"), ki->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			if (all_ok_with_mouse == TRUE)
			{
				MessageBox(ghwnd, TEXT("Mouse Details"), TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Company for Mouse is %s"), moi->Company);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Product for Mouse is %s"), moi->Product);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);

				wsprintf(str, TEXT("Price for Mouse is %s"), moi->Price);
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
			}

			break;

		case IDCANCEL:
			EndDialog(hDlg, 0);
			DestroyWindow(ghwnd);
			break;

		default:
			break;
		}
		break;
	}
	return FALSE;
}

static void InitializeProcessor(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_Processor1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Processor2), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Processor3), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Processor));
	SendDlgItemMessage(hDlg, LB_Processor, CB_RESETCONTENT, 0, 0);
	for (int i = 0; (*(Processor + i)) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg, LB_Processor), CB_ADDSTRING, 0, (LPARAM)(*(Processor + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_Processor), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_Processor), SW_SHOW);
}

static void InitializeRam(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_Ram1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Ram2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Ram));
	SendDlgItemMessage(hDlg, LB_Ram, CB_RESETCONTENT, 0, 0);
	for (int i = 0; (*(Ram + i)) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg, LB_Ram), CB_ADDSTRING, 0, (LPARAM)(*(Ram + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_Ram), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_Ram), SW_SHOW);
}

static void InitializeMotherboard(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_MotherBoard1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_MotherBoard2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_MotherBoard));
	SendDlgItemMessage(hDlg, LB_MotherBoard, CB_RESETCONTENT, 0, 0);
	for (int i = 0; (*(MotherBoards + i)) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg, LB_MotherBoard), CB_ADDSTRING, 0, (LPARAM)(*(MotherBoards + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_MotherBoard), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_MotherBoard), SW_SHOW);
}

static void InitializeHardDisk(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_HardDisk1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_HardDisk2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_HardDisk));
	proc = GetDlgItem(hDlg, LB_HardDisk);
	if (proc != NULL)
	{
		for (int i = 0; (*(HardDisk + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(HardDisk + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_HardDisk), SW_SHOW);
}

static void InitializeGraphicCard(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_GraphicCard1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_GraphicCard2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_GraphicCard));
	proc = GetDlgItem(hDlg, LB_GraphicCard);
	if (proc != NULL)
	{
		for (int i = 0; (*(GraphicCards + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(GraphicCards + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_GraphicCard), SW_SHOW);
}

static void InitializeCDandDVD(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_CDAndDVD));
	proc = GetDlgItem(hDlg, LB_CDAndDVD);
	if (proc != NULL)
	{
		for (int i = 0; (*(CDAndDVD + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(CDAndDVD + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD), SW_SHOW);
}

static void InitializeMonitor(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Monitor1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Monitor2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Monitor));
	proc = GetDlgItem(hDlg, LB_Monitor);
	if (proc != NULL)
	{
		for (int i = 0; (*(Monitor + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Monitor + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Monitor), SW_SHOW);
}

static void InitializeCabinet(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Cabinet1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Cabinet2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Cabinet));
	proc = GetDlgItem(hDlg, LB_Cabinet);
	if (proc != NULL)
	{
		for (int i = 0; (*(Cabinet + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Cabinet + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Cabinet), SW_SHOW);
}

static void InitializeKeyboard(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Keyboard1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Keyboard2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Keyboard));
	proc = GetDlgItem(hDlg, LB_Keyboard);
	if (proc != NULL)
	{
		for (int i = 0; (*(Keyboard + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Keyboard + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Keyboard), SW_SHOW);
}

static void InitializeMouse(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Mouse1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Mouse2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Mouse));
	proc = GetDlgItem(hDlg, LB_Mouse);
	if (proc != NULL)
	{
		for (int i = 0; (*(Mouse + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Mouse + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Mouse), SW_SHOW);
}


