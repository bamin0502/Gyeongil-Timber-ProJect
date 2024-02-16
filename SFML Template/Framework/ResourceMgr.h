#pragma once
#include "Singleton.h"
#include <unordered_map>

template<typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
    friend Singleton<ResourceMgr<T>>;
private:
   std::unordered_map<std::string, T*> resources;
   static T Empty;

public:
   ResourceMgr() = default; //To-Do 싱글톤 객체 보장을 위한 처리가 필요함.
   virtual ~ResourceMgr()
   {
      UnloadAll();
   }

   bool Load(const std::string& filePath)
   {
      if (resources.find(filePath) != resources.end())
         return false;

      T* res = new T();
      bool success = res->loadFromFile(filePath);
      if (success)
      {
         //셋 다 동일한 기능
         //resources[filePath] = res;
         resources.insert({ filePath, res});
         //resources.insert(std::unordered_map<std::string,T*>::make_pair(id,res));
      }
      return success;
   }

   bool UnLoad(const std::string& filePath)
   {
      auto it = resources.find(filePath);
      if (it == resources.end())
         return false;

      delete it->second;
      resources.erase(it);
      return true;
      
   }

   bool UnloadAll()
   {
      for (const auto& pair : resources)
      {
         delete pair.second;
      }
      resources.clear();
      
      return true;
   }

   T* Get(const std::string& filePath)
   {
      auto it = resources.find(filePath);
      if (it == resources.end())
         return nullptr;

      return it->second;
   }

   ResourceMgr(const ResourceMgr&) = delete;
   ResourceMgr(ResourceMgr&&) = delete;
   ResourceMgr& operator=(const ResourceMgr&) = delete;
   ResourceMgr& operator=(ResourceMgr&&) = delete;


};

template<typename T>
T ResourceMgr<T>::Empty;

#define TEXTURE_RES_MGR (ResourceMgr<sf::Texture>::Instance())
#define FONT_RES_MGR (ResourceMgr<sf::Font>::Instance())