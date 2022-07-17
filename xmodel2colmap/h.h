#pragma once

#ifndef h_h_h
#define h_h_h

#pragma warning(disable: 26495)

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];


#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <direct.h>

namespace fs = std::filesystem;

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9core.h>

#include "window.h"
#include "filesystem.h"
#include "utils.h"
#include "log.h"

#include "x_init.h"

#include "x_preferences.h"
#endif