//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
TimeToCheckTmp = new TStringList;
TimeToCheckTmp->LoadFromFile("Time_ch.txt");
TimeToCheck = (TimeToCheckTmp->Strings[0]).SubString(1,5);
delete TimeToCheckTmp;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerTimer(TObject *Sender)
{
        // получить системное врем€
TDateTime RealTime = Time();
AnsiString RealTimeStr = (TimeToStr(RealTime)).SubString(1,5);
        // если это 10.00 - выполнить *.bat-фйл с его коррекцией
if(TimeToCheck==RealTimeStr) {
        int Rez = WinExec("Timech~1.pif",SW_RESTORE);
        if(Rez<31) ShowMessage("—бой в программе коррекции времени");
        }
}
//---------------------------------------------------------------------------

