// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 22:11
// Description:
//

#include "net_address4.h"

NetAddress4::NetAddress4(std::string_view ip, uint16_t port) : ip_(ip), port_(port) {
  if (inet_pton(AF_INET, ip.data(), &address_.sin_addr) <= 0 ) {
    // 出错返回-1，非有效表达式返回0，成功返回1
    std::exit(EXIT_FAILURE);
  }
  address_.sin_family = AF_INET;
  address_.sin_port = port;
}
