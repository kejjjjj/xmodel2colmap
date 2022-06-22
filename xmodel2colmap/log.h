#pragma once
#ifndef thislog
#define thislog
#include "h.h"
class _Log
{
public:
    ImGuiTextBuffer     Buf;
    ImGuiTextFilter     Filter;
    ImVector<int>       LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
    bool                AutoScroll;  // Keep scrolling if already at the bottom.

    _Log();
    void    Clear();
    void    AddLog(const char* fmt, ...) IM_FMTARGS(2);
    void    Draw(const char* title, bool* p_open, HWND hwnd);
};
inline _Log _log;
#endif