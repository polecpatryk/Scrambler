// Filename: engine.h
// Author:   Patryk Połeć

#pragma once

using namespace std;

// Include libraries
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>

// Include definitions
#include "definitions.h"

// Include class
#include "class.file.h"
#include "class.converter.h"
#include "class.scrambler.h"
#include "class.application.h"

LRESULT CALLBACK WindowMainProcedure(HWND _handleWindow, UINT _message, WPARAM _wParam, LPARAM _lParam);
LRESULT CALLBACK DialogMainProcedure(HWND _handleWindow, UINT _message, WPARAM _wParam, LPARAM _lParam);