#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "Server.h"
#include <string>
#include <set>
#include <functional>
#include <ftw.h>
#include <thread>
#include <mutex>
#include <stack>

class WebServer {
private:
    Server* server;
    std::string WWWPath;
    std::set<std::string, std::greater<std::string>> Files;

    std::stack<WebClientHandlder> ClientHandlers;
    std::mutex StackMutex;

    std::queue<int> ClientQueue;
    std::mutex QueueMutex;

    std::string getPath();
    void AddClient(int sock);
    void AddHandler(int sock);

public:
   WebServer(const std::string& port); 

   bool isInFiles(const std::string& file);

   void Run();

   std::string GetWWWPath() { return WWWPath; }

   ~WebServer();
};

#endif
