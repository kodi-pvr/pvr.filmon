/*
 *  Copyright (C) 2011-2020 Team Kodi (https://kodi.tv)
 *  Copyright (C) 2011 Pulse-Eight (http://www.pulse-eight.com/)
 *  Copyright (C) 2014 Stephen Denham
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "FilmonAPI.h"
#include "client.h"
#include "kodi/libXBMC_pvr.h"

#include <mutex>
#include <vector>

#define FILMON_CACHE_TIME 10800 // 3 hours

typedef FILMON_EPG_ENTRY PVRFilmonEpgEntry;
typedef FILMON_CHANNEL PVRFilmonChannel;
typedef FILMON_RECORDING PVRFilmonRecording;
typedef FILMON_TIMER PVRFilmonTimer;
typedef FILMON_CHANNEL_GROUP PVRFilmonChannelGroup;

class PVRFilmonData
{
public:
  PVRFilmonData(void);
  virtual ~PVRFilmonData(void);

  virtual bool Load(std::string user, std::string pwd);

  virtual const char* GetBackendName(void);
  virtual const char* GetBackendVersion(void);
  virtual const char* GetConnection(void);
  virtual void GetDriveSpace(long long* iTotal, long long* iUsed);

  virtual int GetChannelsAmount(void);
  virtual PVR_ERROR GetChannels(ADDON_HANDLE handle, bool bRadio);

  virtual int GetChannelGroupsAmount(void);
  virtual PVR_ERROR GetChannelGroups(ADDON_HANDLE handle, bool bRadio);
  virtual PVR_ERROR GetChannelGroupMembers(ADDON_HANDLE handle, const PVR_CHANNEL_GROUP& group);

  virtual PVR_ERROR GetEPGForChannel(ADDON_HANDLE handle,
                                     int iChannelUid,
                                     time_t iStart,
                                     time_t iEnd);

  virtual int GetRecordingsAmount(void);
  virtual PVR_ERROR GetRecordings(ADDON_HANDLE handle);
  virtual PVR_ERROR DeleteRecording(const PVR_RECORDING& recording);

  virtual int GetTimersAmount(void);
  virtual PVR_ERROR GetTimers(ADDON_HANDLE handle);
  virtual PVR_ERROR AddTimer(const PVR_TIMER& timer);
  virtual PVR_ERROR DeleteTimer(const PVR_TIMER& timer, bool bForceDelete);
  virtual PVR_ERROR UpdateTimer(const PVR_TIMER& timer);

  virtual PVR_ERROR GetChannelStreamProperties(const PVR_CHANNEL* channel,
                                               PVR_NAMED_VALUE* properties,
                                               unsigned int* iPropertiesCount);
  virtual PVR_ERROR GetRecordingStreamProperties(const PVR_RECORDING* recording,
                                                 PVR_NAMED_VALUE* properties,
                                                 unsigned int* iPropertiesCount);

private:
  int UpdateChannel(unsigned int channelId);
  std::mutex m_mutex;
  std::vector<PVRFilmonChannelGroup> m_groups;
  std::vector<PVRFilmonChannel> m_channels;
  std::vector<PVRFilmonRecording> m_recordings;
  std::vector<PVRFilmonTimer> m_timers;
  time_t lastTimeGroups;
  time_t lastTimeChannels;
  std::string username;
  std::string password;
  bool onLoad;
};
