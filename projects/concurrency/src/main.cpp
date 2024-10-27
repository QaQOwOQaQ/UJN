#include <myheader.h>

using namespace std;


std::condition_variable cv;
bool done;
std::mutex m;
bool wait_loop()
{
    auto const timeout = std::chrono::steady_clock::now()
        + std::chrono::milliseconds(500);
    std::unique_lock<std::mutex> lk(m);
    while(!done)
    {
        if(cv.wait_until(lk, timeout) == std::cv_status::timeout)
            break;
    }
    return done;
}

bool flag;
std::mutex m;
void wait_for_flag()
{
    std::unique_lock<std::mutex> lk(m);
    while (!flag)
    {
        lk.unlock();                                                 // 1 解锁互斥量
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 2 休眠 100ms
        lk.lock();                                                   // 3 再锁互斥量 
    }
}