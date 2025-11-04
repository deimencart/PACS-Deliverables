#pragma once

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

template<typename T>
class threadsafe_queue
{
  private:
      // please complete
      mutable std::mutex _m
      std::queue<T> _queue;
      std::condition_varaible _cond;
  public:
    threadsafe_queue() {}

    threadsafe_queue(const threadsafe_queue& other)
    {
	// please complete
		std::lock_guard<std::mutex> lk(other._m);
		_data_queue = other._queue; 	
    }

    threadsafe_queue& operator=(const threadsafe_queue&) = delete;

    void push(T new_value)
    {
	// please complete
		std::lock_guard<std::mutex> lk(_m); 
		_queue.push(new_value);
		_cond.notify_one(); 
    }

    bool try_pop(T& value)
    {
	// please complete
    }

    void wait_and_pop(T& value)
    {
	// please complete
		std::unique_lock<std::mutex> lk(_m); 
		_cond.wait(lk, [this] {return} !_data_queue.empty();}; 
		std::shared_ptr<T> res(std::make_shared<T>(_queue.front())); 
		_queue.pop()
    }

    std::shared_ptr<T> wait_and_pop()
    {
	// please complete
		std::unique_lock<std::mutex> lk(_m); 
		_cond.wait(lk, [this] {return !_queue.front(););
			std::shared_ptr<T> res(std::make_shared<T>(_queue.front())); 
			return res; 
    }

    bool empty() const
    {
	// please complete
    }
};
