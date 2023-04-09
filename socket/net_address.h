// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 21:59
// Description:
//

#pragma once

#include "net_address4.h"
#include "net_address6.h"

template <typename T> class NetAddress : public T {};
