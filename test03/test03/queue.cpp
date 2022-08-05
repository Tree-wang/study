#pragma once
#include <queue>

template<class T>
class concurrentQueue
{
public:
    concurrentQueue() {}

    void push(const T& x)
    {
        MutexLockGuard lock(_mutex);
        _qu.push(x);
    }

    void pop(T& x)
    {
        MutexLockGuard lock(_mutex);
        x = _qu.front();
        _qu.pop();
    }

    void clear()
    {
        MutexLockGuard lock(_mutex);
        while (!_qu.empty())
            _qu.pop();
    }

    bool empty()
    {
        MutexLockGuard lock(_mutex);
        return _qu.empty();
    }

    size_t size()
    {
        MutexLockGuard lock(_mutex);
        return _qu.size();
    }

private:
    std::queue<T> _qu;
    MutexLock _mutex;
};