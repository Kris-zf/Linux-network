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

class IPv4 {
public:
  std::string_view Ip() { return ip_; }

  [[nodiscard]] uint16_t Port() const { return port_; }

  IPv4(std::string_view ip, uint16_t port);

  [[nodiscard]] const struct sockaddr* ToSocketAddr() const {
    return reinterpret_cast<const struct sockaddr*>(&address_);
  }

  struct sockaddr* ToSocketAddr() {
    return reinterpret_cast<struct sockaddr*>(&address_);
  }

private:
  std::string ip_;
  uint16_t port_;
  struct sockaddr_in address_;
};
