//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "TimeChanger";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->ShowMainForm = false;          // нужно, чтобы запускать файл
                 ShowWindow(Application->Handle, SW_HIDE);   // невидимым
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
