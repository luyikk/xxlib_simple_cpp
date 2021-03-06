﻿#pragma once
#include <ajson.hpp>
#include <iostream>

// 用类结构映射到 json 格式:

struct Config {
    uint32_t serverId = 0;						// 服务id, 各个服务之间不可重复. 可以和 gatewayId 重复
    uint32_t gatewayListenPort = 0;				// 监听端口 for gateway
    std::string lobbyIp;                        // 大厅服务所在 ip
    uint32_t lobbyPort = 0;                     // 大厅服务 port
};
AJSON(Config, serverId, gatewayListenPort, lobbyIp, lobbyPort);


// 适配 std::cout
inline std::ostream& operator<<(std::ostream& o, Config const& c) {
    ajson::save_to(o, c);
    return o;
}

// 全局单例, 便于访问
inline Config config;
