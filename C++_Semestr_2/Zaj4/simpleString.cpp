#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#include "simpleString.h"
size_t  SimpleString::instances_;
SimpleString::SimpleString(const char *text) {
    size_t n = strlen(text);
    this->data_ = new char[n];
    int i = 0;
    for (i = 0; i < n ; ++i) {
        data_[i] = text[i];
    }
    data_[i] = '\0';
    this->size_ = strlen(data_) ;
    this->capacity_ = strlen(data_);
    instances_++;
}
SimpleString::SimpleString(const SimpleString &string) {
    size_t n = strlen(string.data_);
    this->data_ = new char[n];
    int i = 0;
    for ( i = 0; i < n; ++i) {
        data_[i] = string.data_[i];
    }
    data_[i] = '\0';
    this->size_ = n;
    this->capacity_ = n;
    instances_++;
}

SimpleString::~SimpleString() {
    delete [] data_;
    instances_--;
}

size_t SimpleString::capacity() const {
    return capacity_;
}

size_t SimpleString::size() const {
    return size_;
}

const char *SimpleString::data() const {
    return data_;
}
const char *SimpleString::c_str() const {
    return data_;
}
size_t SimpleString::instances() {
    return instances_;
}

void SimpleString::assign(const char *new_text) {
    size_t n = strlen(new_text);
    delete [] data_;
    data_ = new char[n];
    int i;
    for ( i = 0; i < n; ++i) {
        data_[i] = new_text[i];
    }
    data_[i] = '\0';
    this->size_ = n;
    this->capacity_ = n;
}


bool SimpleString::equal_to(SimpleString text2) const{
    if (strcmp(data_, text2.data_) == 0) {return true;}
    else
        return false;
}

bool SimpleString::equal_to(SimpleString text2, bool yes_no) const {
    if(yes_no){
        if (strcmp(data_, text2.data_) == 0) {return true;}
        else
            return false;
    }
    else{
        if(strcasecmp(data_, text2.data_) == 0){return true;}
        else
            return false;
    }
}
void SimpleString::append(SimpleString text2) {
    size_t n = strlen(data_), n2 = strlen(text2.data_);
    char* temp1 = new char[n];
    strcpy(temp1, data_);
    delete [] data_;
    data_ = new char[n + n2+1];
    int i = 0;
    for (i = 0; i < n; ++i) {
        data_[i] = temp1[i];
    }
    int j = 0;
    for (j = i; j < n + n2; ++j) {
        data_[j] = text2.data_[j - i];
    }
    data_[j] = '\0';
    this->size_ = n+n2;
    this->capacity_ = n+n2;
}
    
