#pragma once


#include <vector>
#include <map>
#include <unordered_map>

#include "Cpp_Utils/JSON.hpp"


namespace Cpp_Utils
{


template<typename T, typename Callback>
void for_each(const std::vector<T> & vector, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::map<T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::unordered_map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::unordered_map<T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::unordered_map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::unordered_map<T, U> & map, const Callback & callback);

template<typename Callback>
void for_each(const JSON & json, const Callback & callback);

template<typename T, typename Predicate>
bool find(T & out, const std::vector<T> & vector, const Predicate & predicate);


} // namespace Cpp_Utils


#include "Cpp_Utils/Collection.ipp"
