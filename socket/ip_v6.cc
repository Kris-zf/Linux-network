// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 23:14
// Description:
//

#include "ip_v6.h"

IPv6::IPv6(std::string_view ip, uint16_t port)
    : ip_(ip), port_(port) {
  if (inet_pton(AF_INET6, ip.data(), &address_.sin6_addr) <= 0) {
    std::exit(EXIT_FAILURE);
  }
  address_.sin6_family = AF_INET6;
  address_.sin6_port = port;
}
