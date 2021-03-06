﻿#pragma once
#include "kpeer.h"

// 客户端 连进来产生的 peer
struct CPeer : KPeer {
    // 自增编号, accept 时填充
    uint32_t clientId = 0xFFFFFFFFu;

    // 允许访问的 server peers 的 id 的白名单
    std::unordered_set<uint32_t> serverIds;

    // 继承构造函数
    using KPeer::KPeer;

    // 群发断开指令, 从容器移除变野,  DelayUnhold 自杀
    bool Close(int const& reason) override;

    // 延迟关闭( 设置 closed = true, 群发断开指令, 从容器移除变野, 靠超时自杀 )
    void DelayClose(double const& delaySeconds);

    // Close & DelayClose 的公共部分。群发断开指令 并从容器移除
    void PartialClose();

    // 收到正常包
    void ReceivePackage(char* const& buf, size_t const& len) override;

    // 收到内部指令
    void ReceiveCommand(char* const& buf, size_t const& len) override;
};
