// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 21:59
// Description:
//

#pragma once

#include "ip_v4.h"
#include "ip_v6.h"

namespace net {

template <typename T> class NetAddress : public T {};

using NetAddress4 = NetAddress<IPv4>;
using NetAddress6 = NetAddress<IPv6>;

void GetLocalHost(){}

}  // namespace net
