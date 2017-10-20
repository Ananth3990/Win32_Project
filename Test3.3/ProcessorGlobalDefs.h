#pragma once
#include<Windows.h>
//--------------
TCHAR *Processor[4] = { TEXT("Select Company"),TEXT("Intel"),TEXT("AMD"),0 };

TCHAR *Intel_Processor[4] = { TEXT("Core-i3"),TEXT("Core-i5"),TEXT("Core-i7"),0 };
TCHAR *AMD_Processor[4] = { TEXT("AMD FX"),TEXT("Athlon 64"),TEXT("AMD Ryzen 3"),0 };

TCHAR *AMD_ProcessorFXFamily[4] = { TEXT("Athlon64"),TEXT("Bulldozer"),TEXT("PileDriverCore"),0 };
TCHAR *AMD_ProcessorAthlon64Family[4] = { TEXT("SledgeHammer"),TEXT("ClawHammer"),TEXT("SanDiego"),0 };
TCHAR *AMD_ProcessorRyzen3Family[3] = { TEXT("AMD Ryzen 3 1200"),TEXT("AMD Ryzen 3 1300X"),0 };

TCHAR *Intel_Processor_Generation[5] = { TEXT("Haswell"),TEXT("Broadwell"),TEXT("KabyLake"),TEXT("Skylake"),0 };

TCHAR *AMD_ProcessorFXPrice[4] = { TEXT("10"),TEXT("20"),TEXT("30"),0 };
TCHAR  *AMD_ProcessorAthlon64Price[4] = { TEXT("40"),TEXT("50"),TEXT("60"),0 };
TCHAR *AMD_ProcessorRyzen3Price[3] = { TEXT("21"),TEXT("56"),0 };

TCHAR *i3Price[5] = { TEXT("1"),TEXT("2"),TEXT("3"),TEXT("11"),0 };
TCHAR *i5Price[5] = { TEXT("4"),TEXT("5"),TEXT("6"),TEXT("12"),0};
TCHAR *i7Price[5] = { TEXT("7"),TEXT("8"),TEXT("9"),TEXT("13"),0};

struct ProcessorInfo *pi;

BOOL all_ok_for_processor = FALSE;
//--------------
