// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 23:14
// Description:
//

#pragma once

#include <arpa/inet.h>
#include <string_view>
#include <string>

class NetAddress6 {
public:
  std::string_view Ip() {
    return ip_;
  }

  uint16_t Port() {
    return port_;
  }

  NetAddress6(std::string_view ip, uint16_t port);

private:
  std::string ip_;
  uint16_t port_;
  struct sockaddr_in6 address_;
};
