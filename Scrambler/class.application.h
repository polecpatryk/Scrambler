// Filename: class.application.h
// Author:   Patryk Połeć

#pragma once

class C_Application
{
	// Constructor and destructor
	public:
		C_Application(C_Log *_objLog, C_Config *_objConfig, C_Converter *_objConverter, C_Scrambler *_objScrambler, HINSTANCE *_hInstance, LPSTR _lpCmdLine);
		~C_Application();

	// Window Procedure
	public:
		LRESULT CALLBACK WindowProcedure(HWND _handleWindow, UINT _message, WPARAM _wParam, LPARAM _lParam);
		LRESULT CALLBACK DialogProcedure(HWND _handleWindow, UINT _message, WPARAM _wParam, LPARAM _lParam);

	// Public methods
	public:
		int FileNew();
		int FileOpen();
		int FileSave();
		int FileSaveAs();

		int FileEncrypt();
		int FileDecrypt();

	   void CheckIsChangedText();

	// Private methods
	private:
	   bool SetFileName(HWND _handle, string &_fileName, LPCSTR _extension, LPCSTR _filter);
	   bool GetFileName(HWND _handle, string &_fileName, LPCSTR _filter = "");

	   void ClearWindow(HWND _handle);

		int GetNumberOfCharsFromWindow(HWND _handle);

	   void GetTextFromWindow(HWND _handle, string &_buffer);
	 string GetTextFromWindow(HWND _handle);
	    
	// Public fields
	public:
		MSG 
			message;

		int 
			stateLoop;

	// Private fields
	private:
		C_Log       *objLog;
		C_Config    *objConfig;
		C_Converter *objConverter;
		C_Scrambler *objScrambler;

		C_File *objFile;

		WNDCLASSEX 
			classWindow,
			classDialog;

		HINSTANCE 
			*instanceApplication;
		
		HMENU 
			handleMenu;

		HWND 
			handleWindow,
			handleTextBox,
			handleLabel1,
			handleLabel2,
			handleDialog,
			handleLabel3,
			handleEdit,
			handleButton1,
			handleButton2;

		HFONT
			handleFontVerdana;

		LPCSTR
			windowCaption;

		string
			currentFileName,
			
			savedTextBox;
		
		bool
			fileIsSave;

		int
			windowWidth,
			windowHeight;
};