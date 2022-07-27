// -*- coding: utf-8-unix; -*-
// Copyright (c) 2022 .
//     All rights reserved.
//
// Author: kroszhu@gmail.com
// Date: 2022/7/11 1:06 AM
// Description:
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>

int main() {
  // 创建套接字
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  // 请求指定ip和端口
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // htons是将整型变量从主机字节顺序转变成网络字节顺序
  addr.sin_port = htons(8888);
  int ret = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  if (ret != 0) {
    std::cerr << ret << std::endl;
  }

  char resp[50];
  read(sock, resp, sizeof(resp) - 1);

  std::cout << std::string(resp) << std::endl;
  return 0;
}
