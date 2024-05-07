#include <gtest/gtest.h>
#include <QtCore>

#include "Repository.h"

TEST(Repository, insert) {
    Lumen::Repository<int> repo;
    int* ptr = new int(0);
    repo.insert(ptr);

    EXPECT_TRUE(repo.contains(ptr));
}

TEST(Repository, insertWithArgs) {
    Lumen::Repository<int> repo;
    int* ptr = repo.insert(0);

    EXPECT_TRUE(repo.contains(ptr));
}

TEST(Repository, getAll) {
    Lumen::Repository<int> repo;

    int* ptr = repo.insert(0);
    int* ptr2 = repo.insert(0);

    EXPECT_TRUE(repo.getAll().contains(ptr));
    EXPECT_TRUE(repo.getAll().contains(ptr2));
}

TEST(Repository, remove) {
    Lumen::Repository<int> repo;
    int* ptr = repo.insert(0);

    repo.remove(ptr);

    EXPECT_FALSE(repo.contains(ptr));
}
