// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 23:14
// Description:
//

#pragma once

#include <arpa/inet.h>
#include <string>
#include <string_view>

class IPv6 {
public:
  std::string_view Ip() { return ip_; }

  uint16_t Port() const { return port_; }

  IPv6(std::string_view ip, uint16_t port);

  const struct sockaddr* ToSocketAddr() const {
    return reinterpret_cast<const struct sockaddr*>(&address_);
  }

  struct sockaddr* ToSocketAddr() {
    return reinterpret_cast<struct sockaddr*>(&address_);
  }

private:
  std::string ip_;
  uint16_t port_;
  struct sockaddr_in6 address_;
};
