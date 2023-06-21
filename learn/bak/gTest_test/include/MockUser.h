//
// Created by yaojie on 2023/6/21.
//

#ifndef TEST2_MOCKUSER_H
#define TEST2_MOCKUSER_H

#include "User.h"
#include <gmock/gmock.h>

class MockUser : public User {
public:
    MOCK_METHOD(int, getAge, (), (override));
};

#endif //TEST2_MOCKUSER_H
