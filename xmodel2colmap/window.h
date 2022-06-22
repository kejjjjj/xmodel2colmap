#pragma once

#ifndef deez
#define deez
#include "h.h"

inline uint32_t WINDOW_WIDTH = 400;
inline uint32_t WINDOW_HEIGHT = 400;

inline uint32_t WINDOW_POS[2] = { 100, 100 };

inline float MODELSCALE;

namespace W
{
	// Data
	static LPDIRECT3D9              g_pD3D = NULL;
	static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
	static D3DPRESENT_PARAMETERS    g_d3dpp = {};

	// Forward declarations of helper functions
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void ResetDevice();
	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void window();
	void renderstuff(HWND hwnd);
	void MakeStyle();

	void GetWindowResolution(RECT rect, float* resolution);
	RECT GetWindowDimensions(HWND hwnd, RECT* rect);

	void render_log(HWND hwnd);
}

#endif