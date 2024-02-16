#pragma once

template<typename T>
class Singleton
{
protected:
   Singleton() = default;
   virtual ~Singleton() = default;

   Singleton(const Singleton&) = delete;
   
public:
    Singleton& operator=(const Singleton&) = delete;

   static T& Instance()
   {
      static T instance;
      return instance;
   }
};