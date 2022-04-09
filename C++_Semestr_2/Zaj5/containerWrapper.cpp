#include <iostream>
#include <algorithm> // std::sort, std::find, std::copy
#include <iterator> // std::distance, std::advance, std::back_inserter
#include <limits>   // std::numeric_limits<size_t>::max()
#include <numeric>  // std::accumulate()

using namespace std;

#include "containerWrapper.h"
#pragma region Vector
VectorWrapper::VectorWrapper(const value_type *arr, long long size) {
    for (int i = 0; i < size; ++i) {
        this->impl_.push_back(arr[i]);
    }
}

void VectorWrapper::push_back(const value_type &el) {
    this->impl_.push_back(el);
}

void VectorWrapper::push_front(const value_type &el) {
    this->impl_.insert(this->impl_.begin(), el);
}

void VectorWrapper::insert(const value_type &el, size_t position) {
    auto it = impl_.begin() + position;
    this->impl_.insert(it, el);
}

IContainerWrapper::value_type& VectorWrapper::at(size_t position) {
    return this->impl_.at(position);
}
void VectorWrapper::sort() {
    std::sort(this->impl_.begin(), this->impl_.end());
}
void VectorWrapper::erase(size_t position) {
    auto it = impl_.begin() + position;
    this->impl_.erase(it);
}

IContainerWrapper::value_type VectorWrapper::count() const {
    return std::accumulate(this->impl_.begin(), this->impl_.end(), IContainerWrapper::value_type{});
}

size_t VectorWrapper::find(const value_type &val) const {
    if (*std::find(this->impl_.begin(), this->impl_.end(), val) == *this->impl_.end())
        return std::numeric_limits<size_t>::max();
    else
        return *std::find(this->impl_.begin(), this->impl_.end(), val);
}
IContainerWrapper::value_type VectorWrapper::pop_front() {
    auto a = *this->impl_.begin();
    this->impl_.erase(this->impl_.begin());
    return a;
}
#pragma endregion Vector
#pragma region VectorPre
VectorPreallocatedWrapper::VectorPreallocatedWrapper(const value_type *arr, long long size) {
    this->impl_.reserve(this->preallocationSize);
    for (int i = 0; i < size; ++i) {
        this->impl_.push_back(arr[i]);
    }
}

void VectorPreallocatedWrapper::push_back(const value_type &el) {
    this->impl_.push_back(el);
}

void VectorPreallocatedWrapper::push_front(const value_type &el) {
    this->impl_.insert(this->impl_.begin(), el);
}

void VectorPreallocatedWrapper::insert(const value_type &el, size_t position) {
    auto it = impl_.begin() + position;
    this->impl_.insert(it, el);
}

IContainerWrapper::value_type& VectorPreallocatedWrapper::at(size_t position) {
    return this->impl_.at(position);
}

void VectorPreallocatedWrapper::sort() {
    std::sort(impl_.begin(), impl_.end());
}

void VectorPreallocatedWrapper::erase(size_t position) {
    auto it = impl_.begin() + position;
    this->impl_.erase(it);
}

IContainerWrapper::value_type VectorPreallocatedWrapper::count() const {
    return std::accumulate(this->impl_.begin(), this->impl_.end(), IContainerWrapper::value_type{});
}

size_t VectorPreallocatedWrapper::find(const value_type &val) const {
    if (*std::find(this->impl_.begin(), this->impl_.end(), val) == *this->impl_.end())
        return std::numeric_limits<size_t>::max();
    else
        return *std::find(this->impl_.begin(), this->impl_.end(), val);
}

IContainerWrapper::value_type VectorPreallocatedWrapper::pop_front() {
    auto a = *this->impl_.begin();
    this->impl_.erase(this->impl_.begin());
    return a;
}
#pragma endregion VectorW
#pragma region List
ListWrapper::ListWrapper(const value_type *arr, long long size) {
    for (int i = 0; i < size; ++i) {
        this->impl_.push_back(arr[i]);
    }
}
void ListWrapper::push_back(const value_type &el) {
    this->impl_.push_back(el);
}
void ListWrapper::push_front(const value_type &el) {
    this->impl_.push_front(el);
}
void ListWrapper::insert(const value_type &el, size_t position) {
    auto it = impl_.begin();
    advance(it, position);
    this->impl_.insert(it, el);
}

void ListWrapper::sort() {
    this->impl_.sort();
}

IContainerWrapper::value_type& ListWrapper::at(size_t position) {
    auto it = this->impl_.begin();
    advance(it, position);
    return *it;
}

void ListWrapper::erase(size_t position) {
    auto it = impl_.begin();
    advance(it, position);
    this->impl_.erase(it);
}

IContainerWrapper::value_type ListWrapper::count() const {
    return std::accumulate(this->impl_.begin(), this->impl_.end(), IContainerWrapper::value_type{});
}

size_t ListWrapper::find(const value_type &val) const {
    if (*std::find(this->impl_.begin(), this->impl_.end(), val) == *this->impl_.end())
        return std::numeric_limits<size_t>::max();
    else
        return *std::find(this->impl_.begin(), this->impl_.end(), val);
}

IContainerWrapper::value_type ListWrapper::pop_front() {
    auto a = *this->impl_.begin();
    this->impl_.pop_front();
    return a;
}
#pragma endregion List
#pragma region Deque
DequeWrapper::DequeWrapper(const value_type *arr, long long size) {
    for (int i = 0; i < size; ++i) {
        this->impl_.push_back(arr[i]);
    }
}

void DequeWrapper::push_back(const value_type &el) {
    this->impl_.push_back(el);
}
void DequeWrapper::push_front(const value_type &el) {
    this->impl_.push_front(el);
}

void DequeWrapper::insert(const value_type &el, size_t position) {
    auto it = impl_.begin();
    advance(it, position);
    this->impl_.insert(it, el);
}

IContainerWrapper::value_type& DequeWrapper::at(size_t position) {
    return this->impl_.at(position);
}

void DequeWrapper::sort() {
    std::sort(this->impl_.begin(), this->impl_.end());
}

void DequeWrapper::erase(size_t position) {
    auto it = impl_.begin() + position;
    this->impl_.erase(it);
}

IContainerWrapper::value_type DequeWrapper::count() const {
    return std::accumulate(this->impl_.begin(), this->impl_.end(), IContainerWrapper::value_type{});
}

size_t DequeWrapper::find(const value_type &val) const {

    if (*std::find(this->impl_.begin(), this->impl_.end(), val) == *this->impl_.end())
        return std::numeric_limits<size_t>::max();
    else
        return *std::find(this->impl_.begin(), this->impl_.end(), val);
}
IContainerWrapper::value_type DequeWrapper::pop_front() {
    auto a = *this->impl_.begin();
    this->impl_.pop_front();
    return a;
}

#pragma endregion Deque
IContainerWrapper::~IContainerWrapper() = default;


