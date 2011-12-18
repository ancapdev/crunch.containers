// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_CONTAINERS_API_HPP
#define CRUNCH_CONTAINERS_API_HPP

#include "crunch/base/platform.hpp"

#if defined (CRUNCH_PLATFORM_WIN32) && defined (VPM_SHARED_LIB_BUILD)
#   if defined (crunch_containers_lib_EXPORTS)
#       define CRUNCH_CONTAINERS_API __declspec(dllexport)
#   else
#       define CRUNCH_CONTAINERS_API __declspec(dllimport)
#   endif
#else
#   define CRUNCH_CONTAINERS_API
#endif

#endif
