/*
 *  Copyright (C) 2014-2020 Team Kodi (https://kodi.tv)
 *  Copyright (C) 2014 Stephen Denham
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include <kodi/addon-instance/PVR.h>
#include <string>
#include <vector>

#define REQUEST_RETRIES 4

typedef enum
{
  FILMON_TIMER_STATE_NEW = 0,
  FILMON_TIMER_STATE_SCHEDULED = 1,
  FILMON_TIMER_STATE_RECORDING = 2,
  FILMON_TIMER_STATE_COMPLETED = 3,
} FILMON_TIMER_STATE;

typedef struct
{
  int iDuration;
  int iGenreType;
  int iGenreSubType;
  std::string strChannelName;
  std::string strPlotOutline;
  std::string strPlot;
  std::string strRecordingId;
  std::string strStreamURL;
  std::string strTitle;
  std::string strIconPath;
  std::string strThumbnailPath;
  time_t recordingTime;
} FILMON_RECORDING;

typedef struct
{
  unsigned int iClientIndex;
  int iClientChannelUid;
  time_t startTime;
  time_t endTime;
  FILMON_TIMER_STATE state;
  std::string strTitle;
  std::string strSummary;
  bool bIsRepeating;
  time_t firstDay;
  int iWeekdays;
  unsigned int iEpgUid;
  int iGenreType;
  int iGenreSubType;
  int iMarginStart;
  int iMarginEnd;
} FILMON_TIMER;

typedef struct
{
  bool bRadio;
  int iGroupId;
  std::string strGroupName;
  std::vector<unsigned int> members;
} FILMON_CHANNEL_GROUP;

typedef struct
{
  unsigned int iBroadcastId;
  std::string strTitle;
  unsigned int iChannelId;
  time_t startTime;
  time_t endTime;
  std::string strPlotOutline;
  std::string strPlot;
  std::string strIconPath;
  int iGenreType;
  int iGenreSubType;
  time_t firstAired;
  int iParentalRating;
  int iStarRating;
  int iSeriesNumber;
  int iEpisodeNumber;
  int iEpisodePartNumber;
  std::string strEpisodeName;
} FILMON_EPG_ENTRY;

typedef struct
{
  bool bRadio;
  unsigned int iUniqueId;
  unsigned int iChannelNumber;
  unsigned int iEncryptionSystem;
  std::string strChannelName;
  std::string strIconPath;
  std::string strStreamURL;
  std::vector<FILMON_EPG_ENTRY> epg;
} FILMON_CHANNEL;

class PVRFilmonAPI
{
public:
  PVRFilmonAPI(kodi::addon::CInstancePVRClient& client) : m_client(client) { }

  bool filmonAPICreate(void);
  void filmonAPIDelete(void);
  bool filmonAPIkeepAlive(void);
  bool filmonAPIlogin(std::string username, std::string password);
  void filmonAPIgetUserStorage(uint64_t& iTotal, uint64_t& iUsed);
  bool filmonAPIdeleteTimer(unsigned int timerId, bool bForceDelete);
  bool filmonAPIaddTimer(int channelId, time_t startTime, time_t endTime);
  bool filmonAPIdeleteRecording(unsigned int recordingId);
  bool filmonAPIgetChannel(unsigned int channelId, FILMON_CHANNEL* channel, bool preferHd);
  std::vector<unsigned int> filmonAPIgetChannels(void);
  unsigned int filmonAPIgetChannelCount(void);
  std::vector<FILMON_CHANNEL_GROUP> filmonAPIgetChannelGroups();
  std::vector<FILMON_RECORDING> filmonAPIgetRecordings(void);
  std::vector<FILMON_TIMER> filmonAPIgetTimers(void);
  std::string filmonAPIConnection();

private:
  bool filmonRequest(std::string path, std::string params = "", unsigned int retries = REQUEST_RETRIES);
  void filmonAPIlogout(void);
  bool filmonAPIgetSessionKey(void);
  void filmonAPIgetswfPlayer();
  int filmonAPIgetGenre(std::string group);
  std::string filmonAPIgetRtmpStream(std::string url, std::string name);
  bool filmonAPIgetRecordingsTimers(bool completed = false);
  void clearResponse();
  std::string timeToHourMin(unsigned int t);
  void setTimerDefaults(FILMON_TIMER* t);

  std::string filmonUsername = "";
  std::string filmonpassword = "";
  std::string sessionKeyParam = "";
  std::string swfPlayer = "";

  long long storageUsed = 0;
  long long storageTotal = 0;

  std::vector<unsigned int> channelList;
  std::vector<FILMON_CHANNEL_GROUP> groups;
  std::vector<FILMON_RECORDING> recordings;
  std::vector<FILMON_TIMER> timers;

  bool connected = false;

  std::string response;

  kodi::addon::CInstancePVRClient& m_client;
};
