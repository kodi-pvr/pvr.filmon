# - Try to find libtag
# Once done this will define
#
# TAGLIB_FOUND - system has libtag
# TAGLIB_INCLUDE_DIRS - the libtag include directory
# TAGLIB_LIBRARIES - The libtag libraries

find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
  pkg_check_modules (CRYPTOPP libcrypto++)
endif()

if(NOT CRYPTOPP_FOUND)
  find_path(CRYPTOPP_INCLUDE_DIRS cryptopp/cryptlib.h)
  find_library(CRYPTOPP_LIBRARIES cryptopp)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Crypto++ CRYPTOPP_INCLUDE_DIRS CRYPTOPP_LIBRARIES)

mark_as_advanced(CRYPTOPP_INCLUDE_DIRS CRYPTOPP_LIBRARIES)
