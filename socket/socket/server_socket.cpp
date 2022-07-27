// -*- coding: utf-8-unix; -*-
// Copyright (c) 2022 .
//     All rights reserved.
//
// Author: kroszhu@gmail.com
// Date: 2022/7/10 11:58 PM
// Description:
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <memory>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

int main() {
  // 1. 创建套接字
  // int socket(int domain, int type, int protocol);
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    std::cerr << server_socket << std::endl;
  }

  // 2.套接字绑定IP端口
  struct sockaddr_in server_addr;
  // 每个字节用0填充
  memset(&server_addr, 0, sizeof(server_addr));
  // 设置IP类型，IP，端口
  server_addr.sin_family = AF_INET;  // IP v4
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // IP 地址
  server_addr.sin_port = htons(8888);  // 端口
  // 绑定
  // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
  bind(server_socket, (sockaddr*) &server_addr, sizeof(server_addr));

  // 3. 监听
  // int listen(int sockfd, int backlog); backlog表示最大连接数量
  // socket()函数创建的socket默认是一个主动类型的，listen函数将socket变为被动类型的，等待客户的连接请求。
  listen(server_socket, 30);

  // 4.接收客户端请求
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_addr_len);

  // 5. 回复客户端
  int count = 0;
  char resp[] = "hello";
  write(client_socket, resp, sizeof(resp));

  // 6. 关闭套接字
  close(server_socket);
  close(client_socket);

  return 0;
}
