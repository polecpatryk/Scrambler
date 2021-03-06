// Filename: engine.cpp
// Author:   Patryk Połeć

#include "engine.h"

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _nCmdShow)
{	
	C_Log         *objLog         = new C_Log(PATH_FILE_ERROR_LOG);
	C_Config      *objConfig      = new C_Config(PATH_FILE_CONFIG_INI);
	C_Converter   *objConverter   = new C_Converter;
	C_Scrambler   *objScrambler   = new C_Scrambler;
	C_Application *objApplication = new C_Application(objLog, objConfig, objConverter, objScrambler, &_hInstance, _lpCmdLine);

	while(GetMessage(&objApplication->message, NULL, 0, 0) && objApplication->stateLoop == RUN)
	{
		TranslateMessage(&objApplication->message);
		DispatchMessage(&objApplication->message);
	}
	
	delete objApplication;
	delete objScrambler;
	delete objConverter;
	delete objConfig;
	delete objLog;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////// Window Procedure
LRESULT CALLBACK WindowMainProcedure(HWND _handleWindow, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	if(_message == WM_CREATE)
	{
		LPCREATESTRUCT lpcStruct = (LPCREATESTRUCT)_lParam;
		SetWindowLongPtr(_handleWindow, GWL_USERDATA, (long)lpcStruct->lpCreateParams);
	}

	C_Application *objApplication = (C_Application*)GetWindowLongPtr(_handleWindow, GWL_USERDATA);

	if(objApplication) return objApplication->WindowProcedure(_handleWindow, _message, _wParam, _lParam);
	else               return DefWindowProc(_handleWindow, _message, _wParam, _lParam);
}

LRESULT CALLBACK DialogMainProcedure(HWND _handleWindow, UINT _message, WPARAM _wParam, LPARAM _lParam)
{
	if(_message == WM_CREATE)
	{
		LPCREATESTRUCT lpcStruct = (LPCREATESTRUCT)_lParam;
		SetWindowLongPtr(_handleWindow, GWL_USERDATA, (long)lpcStruct->lpCreateParams);
	}

	C_Application *objApplication = (C_Application*)GetWindowLongPtr(_handleWindow, GWL_USERDATA);

	if(objApplication) return objApplication->DialogProcedure(_handleWindow, _message, _wParam, _lParam);
	else               return DefWindowProc(_handleWindow, _message, _wParam, _lParam);
}