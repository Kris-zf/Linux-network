// -*- coding: utf-8-unix; -*-
// Copyright (c) 2023
//
// Author: kroszhu@gmail.com
// Date: 2023/4/9 21:59
// Description:
//

#pragma once

class NetAddress {
public:
  void GetLocalHost() {}

  std::string_view Ip() {return "";}

  uint16_t Port() {
    return  0;
  }

private:
  bool is_ipv6_ = false;

};
