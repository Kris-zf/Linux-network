// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 22:11
// Description:
//

#pragma once

#include <arpa/inet.h>
#include <string>
#include <string_view>

class NetAddress4 {
public:
  std::string_view Ip() { return ip_; }

  uint16_t Port() { return port_; }

  NetAddress4(std::string_view ip, uint16_t port);

  [[nodiscard]] struct sockaddr *ToSocketAddr() const {
    return const_cast<sockaddr *>(
        reinterpret_cast<const struct sockaddr *>(&address_));
  }

private:
  std::string ip_;
  uint16_t port_;
  struct sockaddr_in address_;
};
