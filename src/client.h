/*
 *  Copyright (C) 2011-2020 Team Kodi (https://kodi.tv)
 *  Copyright (C) 2011 Pulse-Eight (http://www.pulse-eight.com/)
 *  Copyright (C) 2014 Stephen Denham
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "kodi/libXBMC_addon.h"
#include "kodi/libXBMC_pvr.h"

extern bool m_bCreated;
extern std::string g_strUserPath;
extern std::string g_strClientPath;
extern ADDON::CHelper_libXBMC_addon* XBMC;
extern CHelper_libXBMC_pvr* PVR;
extern bool g_boolPreferHd;
