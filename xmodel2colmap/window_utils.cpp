#include "h.h"


void W::GetWindowResolution(RECT rect, float* resolution)
{
	resolution[0] = rect.right - rect.left;
	resolution[1] = rect.bottom - rect.top;
}
RECT W::GetWindowDimensions(HWND hwnd, RECT* rect)
{
	GetWindowRect(hwnd, &*rect);

	return *rect;
}