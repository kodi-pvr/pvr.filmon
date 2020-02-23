[![Build Status](https://travis-ci.org/kodi-pvr/pvr.filmon.svg?branch=Leia)](https://travis-ci.org/kodi-pvr/pvr.filmon/branches)
[![Build Status](https://dev.azure.com/teamkodi/kodi-pvr/_apis/build/status/kodi-pvr.pvr.filmon?branchName=Leia)](https://dev.azure.com/teamkodi/kodi-pvr/_build/latest?definitionId=60&branchName=Leia)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/5120/badge.svg)](https://scan.coverity.com/projects/5120)

# Filmon PVR
Filmon PVR client addon for [Kodi] (https://kodi.tv)

## Build instructions

### Linux

1. `git clone --branch Leia https://github.com/xbmc/xbmc.git`
2. `git clone https://github.com/kodi-pvr/pvr.filmon.git`
3. `cd pvr.filmon && mkdir build && cd build`
4. `cmake -DADDONS_TO_BUILD=pvr.filmon -DADDON_SRC_PREFIX=../.. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../../xbmc/addons -DPACKAGE_ZIP=1 ../../xbmc/cmake/addons`
5. `make`

##### Useful links

* [Kodi's PVR user support] (https://forum.kodi.tv/forumdisplay.php?fid=167)
* [Kodi's PVR development support] (https://forum.kodi.tv/forumdisplay.php?fid=136)
