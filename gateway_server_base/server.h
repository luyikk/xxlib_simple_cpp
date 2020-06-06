﻿#pragma once
#include "xx_epoll.h"
#include <unordered_map>
namespace EP = xx::Epoll;

// 预声明
struct Listener;
using Listener_r = EP::Ref<Listener>;
struct Peer;
using Peer_r = EP::Ref<Peer>;

// 服务本体
struct Server : EP::Context {
    // 在构造函数中根据 config 进一步初始化各种拨号器
    Server(size_t const &wheelLen = 1 << 12);

    // 析构当前类中的一些成员
    ~Server() override;

    // 帧逻辑：遍历 dialerPeers 检查 Peer 状态并自动拨号
    int FrameUpdate() override;

    // 等待 client 接入的监听器
    Listener_r listener;

    // server peers
    std::unordered_map<uint32_t, Peer_r> ps;
};
